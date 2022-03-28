""" Flask built Website that provides users with random facts"""
import atexit
import re
from functools import wraps

from apscheduler.schedulers.background import BackgroundScheduler
from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from werkzeug.security import check_password_hash, generate_password_hash

from flask_session import Session
from mails import lookup, send_daily_email, send_email

# Configure application
app = Flask(
    __name__,
    static_folder="static",
    template_folder="templates",
)

# initialise scheduler
scheduler = BackgroundScheduler()
# Add job to scheduler and set to start at 8am
scheduler.add_job(
    func=send_daily_email, trigger="interval", days=1, start_date="2022-03-26 08:00:00"
)
scheduler.start()

# Shut down the scheduler when exiting the app
atexit.register(lambda: scheduler.shutdown())

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///private/random_facts.db")


def login_required(f):
    """
    Decorator for functions that can only be accessed when user is logged in
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show information about the subscription"""
    status = db.execute("SELECT subscribed FROM users WHERE id = ?", session["user_id"])
    return render_template("index.html", status=int(status[0]["subscribed"]))


# Log out of site
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# Log into site
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return """apology("must provide username", 403)"""

        # Ensure password was submitted
        elif not request.form.get("password"):
            return """apology("must provide password", 403)"""

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return """apology("invalid username and/or password", 403)"""

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Get username and email from input
        name = request.form.get("username").rstrip()
        email = request.form.get("email").rstrip()

        # Get Password and confirmation of password from site
        password1 = request.form.get("password")
        password2 = request.form.get("confirmation")

        # Encrypt the password
        password = generate_password_hash(
            password1, method="pbkdf2:sha256", salt_length=8
        )
        # Check email adress using regex pattern is valid if not return error
        pattern = (
            r"([A-Za-z0-9]+[.-_])*[A-Za-z0-9]+@[A-Za-z0-9-^@]+(\.[A-Z|a-z^@]{2,})+"
        )
        if not re.match(pattern, email):
            return """apology(email not valid)"""

        # Check both passwords are the same and not empty
        if not name or not password2 or not password1 == password2:
            return """apology("Form not entered correctly")"""

        # Is name in database
        name_check = db.execute(
            "SELECT username FROM users where UPPER(username) = ?", name.upper()
        )
        email_check = db.execute(
            "SELECT email FROM users where UPPER(email) = ?", email.upper()
        )
        # Check email isnt in database
        if email_check:
            return """apology(email already used)"""
        # Insert new user if name doesnt already exist
        if not name_check:
            db.execute(
                """INSERT INTO users (date, username, email, hash, subscribed) VALUES (datetime(), ? , ? , ? , ?)""",
                name,
                email,
                password,
                0,
            )
        else:
            return """apology("Username already exists")"""
        try:
            send_email(email, "You have successfully registered")
        except:
            raise ValueError("Error")

        return render_template("login.html")

    return render_template("register.html")


@app.route("/interests", methods=["GET", "POST"])
@login_required
def interests():
    """Show information about the interests"""
    if request.method == "POST":
        # Get list of checked boxes
        not_interested = request.form.getlist("selected")
        # Loop through list and remove from database
        for interest in not_interested:
            db.execute(
                "DELETE from interests WHERE user_id = ? AND interest = ?",
                session["user_id"],
                interest,
            )
        # Get new list and pass to render_template
        interests = db.execute(
            "SELECT interest FROM interests WHERE user_id = ?", session["user_id"]
        )
        return render_template("interests.html", interests=interests)
    else:
        interests = db.execute(
            "SELECT interest FROM interests WHERE user_id = ?", session["user_id"]
        )
        return render_template("interests.html", interests=interests)


@app.route("/tryitout", methods=["GET", "POST"])
@login_required
def tryitout():
    """Try it out page if method is post show the fact"""
    if request.method == "POST":
        random_fact = lookup()
        while len(random_fact) < 15:
            random_fact = lookup()
        return render_template("tryitout.html", random_fact=random_fact)

    return render_template("tryitout.html")


@app.route("/settings", methods=["GET", "POST"])
@login_required
def settings():
    """Change settings such as subscription"""
    return render_template("settings.html")


@app.route("/changepassword", methods=["GET", "POST"])
@login_required
def changepassword():
    """Change password and udate db"""
    if request.method == "POST":
        old_password = request.form.get("old_password")
        password1 = request.form.get("password1")
        password2 = request.form.get("password")
        # Get hashed pw from db
        old_pass_hash = db.execute(
            "SELECT hash FROM users where id = ?", session["user_id"]
        )
        # Check old password is correct
        if not check_password_hash(old_pass_hash[0]["hash"], old_password):
            return render_template(
                "/changepassword.html", message="Incorrect Password!"
            )
        if password1 != password2:
            return render_template(
                "/changepassword.html", message="Passwords do not match!"
            )
        db.execute(
            "UPDATE users SET hash = ? WHERE id = ?",
            generate_password_hash(password1),
            session["user_id"],
        )
        return render_template("/changepassword.html", message="Password Changed!")
    return render_template("/changepassword.html")


@app.route("/subscribe", methods=["GET", "POST"])
@login_required
def subscribe():
    """Change subscription variable in data base allowing users to unsubscribe"""
    subscribed = db.execute(
        "SELECT subscribed FROM users where id = ?", session["user_id"]
    )
    if request.method == "POST":
        db.execute(
            "UPDATE users SET subscribed = ? WHERE id = ?",
            (int(subscribed[0]["subscribed"]) + 1) % 2,
            session["user_id"],
        )
    subscribed = db.execute(
        "SELECT subscribed FROM users where id = ?", session["user_id"]
    )
    status = "subscribed"
    change = "unsubscribe"
    message = "For now at least..."
    if subscribed[0]["subscribed"] == 0:
        status = "not subscribed"
        change = "subscribe"
        message = "Yes, please. More than anything!"

    return render_template(
        "/subscribe.html", status=status, change=change, message=message
    )


@app.route("/change-email", methods=["GET", "POST"])
@login_required
def changeemail():
    """Change email by verifying old email and updating database with new"""
    if request.method == "POST":
        email = request.form.get("new-email")
        password = request.form.get("password")
        # Get hashed pw from db
        pass_hash = db.execute(
            "SELECT hash FROM users where id = ?", session["user_id"]
        )
        # Check old password is correct
        if not check_password_hash(pass_hash[0]["hash"], password):
            return render_template("/change-email.html", message="Incorrect Password!")
        email_check = db.execute("SELECT email FROM users")
        # Check see if email is in database
        for i in email_check:
            if i["email"] == email:
                return render_template(
                    "/change-email.html", message="Email used on another account"
                )

        # Update email in database
        db.execute(
            "UPDATE users SET email = ? WHERE id = ?",
            email,
            session["user_id"],
        )
        return render_template("/change-email.html", message="E-mail Changed!")
    return render_template("/change-email.html")


if __name__ == "__main__":
    app.run(debug=True)

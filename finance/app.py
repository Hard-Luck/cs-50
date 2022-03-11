import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


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
    """Show portfolio of stocks"""
    holdings = db.execute("SELECT stock, quantity FROM stocks where person_id = ?", session["user_id"])
    prices = {}
    total = 0
    # Loop through holdings for tickers and price calculations
    for j in holdings:
        prices[j["stock"]] = float(lookup(j["stock"])["price"])
        total += float(lookup(j["stock"])["price"]) * j["quantity"]
    return render_template("index.html", holdings=holdings, prices=prices, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    """Buy shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get("quote"))
        if stock:
            price = float(stock["price"])
            quantity = float(request.form.get("quantity"))
            cost = price * quantity
            print(balance)
            #check balance
            if not cost < float(balance[0]["cash"]):
                return apology("Not enough funds")
            new_balance = float(balance[0]["cash"]) - cost
            stock_check = db.execute("SELECT stock FROM stocks WHERE stock = ? AND person_id =?", stock["symbol"].upper(), session["user_id"])
            db.execute("UPDATE users SET cash = ? where id = ?", new_balance, session["user_id"])
            #check if user already owns some of this stock, if not insert new row
            if not stock_check:
                db.execute("INSERT INTO stocks (stock, person_id, quantity) VALUES(?, ?, ?)",stock["symbol"].upper(), session["user_id"], int(quantity))
                return render_template("buy.html", cash=new_balance)
            # Query how many stock already owned
            current = db.execute("SELECT quantity FROM stocks WHERE stock = ? AND person_id =?", stock["symbol"].upper(), session["user_id"])
            db.execute("UPDATE stocks set quantity = ? WHERE person_id = ?", int(quantity) + current[0]["quantity"], session["user_id"])
            return render_template("buy.html", cash=new_balance)
        else:
            return apology("Stock does not exist")
    else:
        return render_template("buy.html", cash=balance[0]["cash"])


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stock = lookup(request.form.get("quote"))
        if stock:
            return render_template("quoted.html", stock=stock)
        else:
            return apology("Stock does not exist")
    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        """Register user"""
        name = request.form.get("name").rstrip()
        password1 = request.form.get("password1")
        password2 = request.form.get("password2")
        password = generate_password_hash(password1, method='pbkdf2:sha256', salt_length=8)
        if not name or not password2 or not (password1 == password2):
            return apology("Form not entered correctly")
        #is name in database
        name_check = db.execute("SELECT username FROM users where UPPER(username) = ?",name.upper())
        print(name_check)
        if not name_check:
            db.execute("INSERT INTO users (username, hash) VALUES (?,?)", name, password)
        else:
            return apology("Username already exists")
        return render_template("login.html")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    balance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    stocks = db.execute("SELECT stock FROM stocks where person_id = ?",  session["user_id"])

    if request.method == "POST":
        to_sell = request.form.get("sell")
        quantity = float(request.form.get("quantity"))
        quantity_owned = db.execute("SELECT quantity FROM stocks WHERE stock = ? AND person_id =?", to_sell, session["user_id"])
        owned = quantity_owned[0]["quantity"]
        print(quantity_owned)
        print(owned)
        print(quantity)
        # Ensure quantity is positive and less tthan or equal to stock owned
        if not to_sell or ((quantity <= owned) and quantity < 0):
            return apology("Sale Error")
        new_owned = owned - quantity
        price = float(stock["price"])
        sale_price = price * quantity
        print(balance)
        # Update cash balance and stock balance
        new_balance = float(balance[0]["cash"]) + sale_price
        db.execute("UPDATE users SET cash = ? where id = ?", new_balance, session["user_id"])
        db.execute("UPDATE stocks SET quantity = ? where person_id = ?", new_owned, session["user_id"])
        # If user sells all stock, delete from db
        db.execute("DELETE from stocks WHERE quantity = 0")

    return render_template("sell.html", cash=balance[0]["cash"], stocks=stocks)

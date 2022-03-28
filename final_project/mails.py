"""module to automatically send email"""
import smtplib

import requests
from cs50 import SQL

from credentials import get_login, get_password

PASSWORD = get_password()
LOGIN = get_login()


def send_email(send_to: str, message: str) -> None:
    """send mail"""
    with smtplib.SMTP("smtp.gmail.com", 587) as smtp:
        smtp.starttls()
        smtp.login(LOGIN, PASSWORD)
        smtp.sendmail(LOGIN, send_to, message)


# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///private/random_facts.db")


def send_daily_email() -> None:
    """Send daily email to all addresses that are subscribed"""

    # Get list of emails
    emails = db.execute("SELECT email FROM users WHERE subscribed = ?", 1)
    # Get daily fact
    daily_fact = lookup()
    mailing_list = []

    # Convert to format
    for address in emails:
        for details in address.values():
            mailing_list.append(details)

    for address in mailing_list:
        try:
            send_email(address, daily_fact)
        except (UnicodeEncodeError, KeyError, ValueError):
            print(f"Unable to send to {address}")


def lookup(number: int = 1):
    """Look up random cat fact"""

    # Contact API
    try:
        url = f"https://cat-fact.herokuapp.com/facts/random?animal_type=cat&amount={number}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None

    # Parse response
    try:
        quote = response.json()
        return quote["text"]
    except (KeyError, TypeError, ValueError):
        return None


if __name__ == "__main__":
    print(LOGIN)
    send_daily_email()

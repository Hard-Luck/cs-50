import cs50
import re

#regex check for length of string
pattern = r"^[0-9]{13}$|^[0-9]{15}$|^[0-9]{16}$"

#Enter credit card number
number = get_string("Enter credit card number")

def main():
    #check the length and return invalid if not correct length
    if not re.match(pattern, number):
        print("INVALID")
        break



def l
import cs50
import re
from math import ceil



def main():
    #Enter credit card number
    number = cs50.get_string("Enter credit card number: ")
    #check the length and return invalid if not correct length
    if not check_length(number) == 0:
        return
    sum_check(number)


#Function to check the length is 13, 15 or 16
def check_length(number):
    #regex check for length of string
    pattern = r"^[0-9]{13}$|^[0-9]{15}$|^[0-9]{16}$"
    if not re.match(pattern, number):
        print("INVALID")
        return 1
    return 0

# Sum check function to check card number is valid
def sum_check(number):
    sum = 0



    print(sum)


"""#checking the leading digits
def check_type(number):"""


main()
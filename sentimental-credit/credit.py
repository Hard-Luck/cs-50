import cs50
import re
from math import ceil



def main():
    #Enter credit card number
    number = cs50.get_string("Enter credit card number: ")
    #check the length and return invalid if not correct length
    if check_length(number):
        print("INVALID")
        return
    # Check sumcheck = 0
    if sum_check(number):
        print("INVALID")
        return
    print(check_type(number))



#Function to check the length is 13, 15 or 16
def check_length(number):
    #regex check for length of string
    pattern = r"^[0-9]{13}$|^[0-9]{15}$|^[0-9]{16}$"
    if re.match(pattern, number):
       return 0
    return 1

# Sum check function to check card number is valid
def sum_check(number):
    length = len(number)
    hlen = length // 2
    sum = 0
    # For card numbers of even length
    if length % 2 == 0:
        for i in range(hlen):
            sum += (2*(int(number[2 * i])) % 10)
            sum += int(number[2 * i + 1])
            if int(number[2 * i]) > 4:
                sum += 1
    # For card numbers of even length
    else:
        sum += int(number[0])
        for j in range(0, hlen):
            sum += (2*(int(number[2 * j + 1])) % 10)
            sum += int(number[2 * j])
            if int(number[2 * j + 1]) > 4:
                sum += 1
    return sum % 10


# Get the first 2 digits as an int
def check_type(number):
    pre = int(number[0:2])
    length = len(number)
    if (number[0] == "4" and (length == 13 or length == 16)):
        return "VISA"
    elif (pre == 34 or pre == 37) and length == 15:
        return "AMEX"
    elif (50 < pre <= 55) and length == 16:
        return "MASTERCARD"
    # If no passes thus far then card must be invalid
    else:
        return "INVALID"


main()
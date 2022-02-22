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
    length = len(number)
    hlen = length // 2
    sum = 0
    # For card numbers of even length
    if length % 2 == 0:
        for i in range(hlen):
            sum += 2*(int(number[2 * i]))
            sum += int(number[2 * i + 1])
            if int(number[2 * i]) > 4:
                sum += 1
    # For card numbers of even length
    else:
        sum += int(number[0])
        for j in range(1, hlen):
            sum += 2*(int(number[2 * j - 1]))
            sum += int(number[2 * j])
            if int(number[2 * j]) > 4:
                sum += 1

    print(sum)


"""#checking the leading digits
def check_type(number):"""


main()
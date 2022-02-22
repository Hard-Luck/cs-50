import cs50
import re



def main():
    #Enter credit card number
    number = cs50.get_string("Enter credit card number: ")
    #check the length and return invalid if not correct length
    if not check_length(number) == 0:
        return



#Function to check the length is 13, 15 or 16
def check_length(number):
    #regex check for length of string
    pattern = r"^[0-9]{13}$|^[0-9]{15}$|^[0-9]{16}$"
    if not re.match(pattern, number):
        print("INVALID")
        return 1
    return 0

def sum_check():
    

main()
import cs50
import re

pattern = r"/^[0-9]{13}$/"

if re.match(pattern,"1111111111111"):
    print("all good")
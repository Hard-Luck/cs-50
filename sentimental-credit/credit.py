import cs50
import re

pattern = r"/^[0-9]{7}$/"

if re.match(pattern,"0000000"):
    print("all good")
else:
    print("baD")
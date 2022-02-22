import cs50
import re

pattern = r"/[0-9]{7}/"

if re.match(pattern,"1111111"):
    print("all good")
else:
    print("baD")
import cs50
import re

pattern = r"[0-9]{13}|[0-9]{15}|[0-9]{16}"

if re.match(pattern,"111111111111111111111"):
    print("all good")
else:
    print("baD")
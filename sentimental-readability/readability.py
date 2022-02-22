import cs50
import string

text = cs50.get_string("Enter Text: ")

words = len(text.split())

nopunc = text.translate(str.maketrans("","",string.punctuation))
print(nopunc.strip())
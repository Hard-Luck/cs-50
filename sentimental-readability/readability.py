import cs50
import string

text = cs50.get_string("Enter Text: ")
nopunc = text.translate(str.maketrans("","",string.punctuation))

words = len(text.split())
letters = len(nopunc)
sentences = 0



import cs50
import string

text = cs50.get_string("Enter Text: ")

# Take all punctuation out of the text 
nopunc = text.translate(str.maketrans("","",string.punctuation))

# Split the text at every space, count the size of the list
words = len(text.split())
letters = len(nopunc)
sentences = 0

sentences += text.count(".")
sentences += text.count("!")
sentences += text.count("?")

print(sentences)
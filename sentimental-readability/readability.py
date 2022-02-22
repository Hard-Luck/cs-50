import cs50
import string

text = cs50.get_string("Enter Text: ")

# Take all punctuation out of the text and then remove all whitespace to count
nopunc = text.translate(str.maketrans("", "", string.punctuation))
nopunc = nopunc.replace(" ", "")

# Split the text at every space, count the size of the list
words = len(text.split())
letters = len(nopunc)
sentences = 0

# Increment based on sentence identifiers
sentences += text.count(".")
sentences += text.count("!")
sentences += text.count("?")

# Calculate the level using the formula
level = 5.88 * letters/words - 29.6 * sentences/words - 15.8

# Print result based on grade (level)
if level < 1:
    print("Before Grade 1")
elif level > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(level)}")

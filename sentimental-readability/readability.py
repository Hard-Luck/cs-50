import cs50
import string

text = cs50.get_string("Enter Text: ")

# Take all punctuation out of the text and then remove all whitespace to count
nopunc = text.translate(str.maketrans("","",string.punctuation))
nopunc.replace(" ", "")

# Split the text at every space, count the size of the list
words = len(text.split())
letters = len(nopunc)
sentences = 0

sentences += text.count(".")
sentences += text.count("!")
sentences += text.count("?")

# Calculate the level using the formula
level = 0.0588 * letters/words - 0.296 * sentences/words *100 - 15.8

# Print result based on grade (level)
if level < 1:
    print("Grade 1")
if level > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(level)}")

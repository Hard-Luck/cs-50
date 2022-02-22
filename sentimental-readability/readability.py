import cs50
import string

text = cs50.get_string("Enter Text: ")

# Take all punctuation out of the text and then remove all whitespace to count
nopunc = text.translate(str.maketrans("","",string.punctuation))
nopunc.replace(" ", "")

# Split the text at every space, count the size of the list
words = len(text.split())
print(words)
letters = len(nopunc)
print(letters)
sentences = 0

sentences += text.count(".")
sentences += text.count("!")
sentences += text.count("?")
print(sentences)
# Calculate the level using the formula
level = 5.88 * letters/words - 29.6 * sentences/words - 15.8

# Print result based on grade (level)
if level < 1:
    print("Grade 1")
if level > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(level)}")

import cs50

text = cs50.get_string("Enter Text: ")

words = len(text.split())
print(words)
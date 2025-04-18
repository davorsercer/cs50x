from cs50 import get_string

# Prompt the user for some text
text = get_string("Text: ")

# Count the number of letters, words, and sentences in the text
letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1
    if i.isspace():
        words += 1
    if i == '.' or i == '!' or i == '?':
        sentences += 1
print(letters, words, sentences)

# Compute the Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
L = letters / words * 100
S = sentences / words * 100
C_L_index = (0.0588 * L) - (0.296 * S) - 15.8

if C_L_index >= 16:
    print("Grade 16+")

elif C_L_index <= 1:
    print("Before Grade 1")

else:
    print(f"Grade {round(C_L_index)}")

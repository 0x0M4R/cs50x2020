from cs50 import get_string

# get string from user
text = get_string("Text:")

# count number of letters words and sentences.
letters = 0
words = 1
sentences = 0
for i in range(len(text)):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1
    if text[i] == ' ':
        words += 1
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences += 1

# calculate amount of letters per 100 words and amount of sentences per 100 words
L = letters / words * 100
S = sentences / words * 100

# run values through Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8

# print grade level
if index < 2:
    print("Before Grade 1")
elif index > 17:
    print("Grade 16+")
else:
    print("Grade {:.0f}".format(index))
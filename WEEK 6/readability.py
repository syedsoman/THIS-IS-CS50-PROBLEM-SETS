# compute grade level of a text

import re

text = input("Text: ")

letters = 0
for c in text:
    if c.isalpha():
        letters += 1

words = len(text.split())
sentences = len(re.findall(r"[.!?]", text))

L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

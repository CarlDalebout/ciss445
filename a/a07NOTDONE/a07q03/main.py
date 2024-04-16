# Name: Carl Dalebout
# File: main.py

import re

p = re.compile("((1)*(00)*(1)*)*\Z")
s = input("give me a string with 1's and 0's: ")
print(p.match(s))
String

Strings are created with single or double quotes:

'''Python
message = "what do you like?"
response = 'spam
'''

To quote a quote, we need to “escape” it, by preceding it with \. Alternatively, we can use the other type of quotation marks:

'''Python
'doesn\'t'  # use \' to escape the single quote...

"doesn't"  # ...or use double quotes instead

'"Yes," they said.'

"\"Yes,\" they said."

'"Isn\'t," they said.'
'''

In the Python shell, the string definition and output string can look different. The print() function produces a more readable output, by omitting the enclosing quotes and by printing escaped and special characters:

'''Python
s = 'First line.\nSecond line.'  # \n means newline

s  # without print(), special characters are included in the string
'First line.\nSecond line.'

print(s)  # with print(), special characters are interpreted, so \n produces new line
First line.
Second line.
'''

If you don’t want characters prefaced by \ to be interpreted as special characters, you can use raw strings by adding an r before the first quote:

'''Python
print('C:\some\name')  # here \n means newline!

# Output
C:\some
ame
'''

'''Python
print(r'C:\some\name')  # note the r before the quote

# Output
C:\some\name
'''

There is one subtle aspect to raw strings: a raw string may not end in an odd number of \ characters



String literals can span multiple lines. One way is using triple-quotes: """...""" or '''...'''. End of lines are automatically included in the string, but it’s possible to prevent this by adding a \ at the end of the line. In the following example, the initial newline is not included:

'''Python
print("""\

Usage: thingy [OPTIONS]

     -h                        Display this usage message

     -H hostname               Hostname to connect to

""")

# Output
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
'''


strings have many related functions and methods:

'''Python

# continued from above

print(len(response)) # length of string
print(response.upper()) # Make uppercase. See also str.lower()
print(message.capitalize()) # Capitalize. See also str.title()
print(message + response) # concatenation with +
print(5 * response) # multiplication is multiple concatenation

# Output:
4
'SPAM'
'What do you like?'
'what do you like?spam'
'spamspamspamspamspam'
'''

Two or more string literals next to each other are automatically concatenated.

'''Python
print('Py' 'thon')

# Output
'Python'
'''

'''Python
This feature is particularly useful when you want to break long strings:

text = ('Put several strings within parentheses '
        'to have them joined together.')

print(text)

# Output
'Put several strings within parentheses to have them joined together.'
'''

This only works with two literals though, not with variables or expressions:

prefix = 'Py'

prefix 'thon'  # can't concatenate a variable and a string literal
  File "<stdin>", line 1
    prefix 'thon'
           ^^^^^^
SyntaxError: invalid syntax

('un' * 3) 'ium'
  File "<stdin>", line 1
    ('un' * 3) 'ium'
               ^^^^^
SyntaxError: invalid syntax



Single line comments are initiated by a hash (#). 

Comments may be their own line, or inline, following a statement.

    # An assignment statement

    x = 5 # x is assigned the value 5

Python does not have any syntax for multiline comments, such as
the /* ... */ syntax used in C and C++, though multiline strings
are often used as a replacement for multiline comments. 

You can also use the hash symbol (#) at the beginning of each line to create a multiline comment.

# This is a multiline comment
# using the hash symbol on each line.
# Python will ignore each line individually.

Triple-quoted strings are the most common way to create multiline comments.

'''
This is a multiline comment.
It can span multiple lines.
Python will ignore this entire block.
'''

Python style guides recommend...

Using triple-quoted strings (docstrings) to document functions, classes, and modules.

Using the hash symbol (#) on each line if you are temporarily commenting out code during development.
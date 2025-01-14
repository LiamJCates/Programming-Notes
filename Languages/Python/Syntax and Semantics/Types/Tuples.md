Tuples

Tuples are immutable ordered sequences. Once defined, they cannot be altered:

'''Python
t = (1, 2, 3)

t[1] = 4

# Output
---------------------------------------------------------
TypeError Traceback (most recent call last)
<ipython-input-23-141c76cb54a2> in <module>()
----> 1 t[1] = 4
TypeError: 'tuple' object does not support item assignment
'''

'''Python
t = (1, 2, 3)

t.append(4)
---------------------------------------------------------
AttributeError Traceback (most recent call last)
<ipython-input-24-e8bd1632f9dd> in <module>()
----> 1 t.append(4)

AttributeError: 'tuple' object has no attribute 'append'
'''

Tuples are defined with parentheses rather than square brackets:

'''Python
t = (1, 2, 3)

# Output
print(t)
(1, 2, 3)
'''

They can also be defined without any brackets at all:

'''Python
t = 1, 2, 3

# Output
print(t)
(1, 2, 3)
'''

Unlike lists, single element tuples require a comma:

thistuple = ("apple",)
print(type(thistuple))

#NOT a tuple
thistuple = ("apple")
print(type(thistuple)) 



Tuples are often used in a Python program; a particularly common
case is in functions that have multiple return values. For example,
the as_integer_ratio()


x = 0.125
print(x.as_integer_ratio())

# Output: 
(1, 8)


indexing and slicing works for tuples
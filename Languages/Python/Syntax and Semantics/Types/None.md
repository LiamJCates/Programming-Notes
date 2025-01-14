None Type

Python includes a special type, the NoneType, which has only a single possible value, None:

print(type(None))

# Output
NoneType

You'll see None used in many places, but perhaps most commonly it
is used as the default return value of a function. For example, the
print() function in Python 3 does not return anything, but we can
still catch its value:
In [25]: return_value = print('abc')
abc
In [26]: print(return_value)
None
Likewise, any function in Python with no return value is, in reality,
returning None.
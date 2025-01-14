Boolean Type

The Boolean type, returned by comparison operators, has two possible values: True and
False:


'''Python
result = (4 < 5)
print(result)
print(type(result))

# Output
true
bool
'''

Boolean values are case-sensitive, unlike some other languages, True and False must be capitalized!

Booleans can also be constructed using the bool() object constructor: values of any other type can be converted to Boolean via predictable rules. 

For example, any numeric type is False if equal to zero, and True otherwise:

bool(2014)
True

bool(0)
False

bool(3.1415)
True

The Boolean conversion of None is always False:

bool(None)
False

For strings, bool(s) is False for empty strings and True otherwise:
bool("")
False

bool("abc")
True

For sequences, which we'll see in the next section, the Boolean representation is False for empty sequences and True for any other sequences:

bool([1, 2, 3])
True

bool([])
False
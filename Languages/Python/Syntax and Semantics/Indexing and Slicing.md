Python provides access to elements in compound types through indexing for single elements, and slicing for multiple elements. 

Python uses zero-based indexing

L = [2, 3, 5, 7, 11]
print(L[0])
print(L[1])

# Output
2
3

Elements at the end of the list can be accessed with negative numbers, starting from -1:

print(L[-1])
print(L[-2])


Out: 
11
7

slicing accesses multiple values in sublists. It uses a colon to indicate the start point (inclusive) and end point (non-inclusive) of the subarray.

In [12]: L[0:3]
Out [12]: [2, 3, 5]

If we leave out the first index, 0 is assumed

In [13]: L[:3]
Out [13]: [2, 3, 5]

we leave out the last index, it defaults to the length of the list

In [14]: L[-3:]
Out [14]: [5, 7, 11]

This makes sure that s[:i] + s[i:] is always equal to s

Attempting to use an index that is too large will result in an error:

word[42]  # the word only has 6 characters
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
IndexError: string index out of range

However, out of range slice indexes are handled gracefully when used for slicing:

word[4:42]
'on'

word[42:]
''


A third integer represents step size

In [15]: L[::2] # equivalent to L[0:len(L):2]
Out [15]: [2, 5, 11]

a negative step will reverse the array:

In [16]: L[::-1]
Out [16]: [11, 7, 5, 3, 2]

Both indexing and slicing can be used to set elements as well as access them. 

In [17]: L[0] = 100
print(L)
[100, 3, 5, 7, 11]
In [18]: L[1:3] = [55, 56]
print(L)
[100, 55, 56, 7, 11]



Strings are sequences, which means they follow all 

Python has cannot be changed — they are immutable. Therefore, assigning to an indexed position in the string results in an error:
>>>

word[0] = 'J'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'str' object does not support item assignment

word[2:] = 'py'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'str' object does not support item assignment

If you need a different string, you should create a new one:
>>>

'J' + word[1:]
'Jython'

word[:2] + 'py'
'Pypy'
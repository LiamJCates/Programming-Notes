Lists

Lists ordered, mutable sequence. 

They can be defined with comma-separated values between square brackets

Some List properties and methods

In [1]: L = [2, 3, 5, 7]
In [2]: # Length of a list
len(L)
Out [2]: 4
In [3]: # Append a value to the end
L.append(11)
L
Out [3]: [2, 3, 5, 7, 11]
In [4]: # Addition concatenates lists
L + [13, 17, 19]
Out [4]: [2, 3, 5, 7, 11, 13, 17, 19]
In [5]: # sort() method sorts in-place
L = [2, 5, 1, 6, 3, 4]
L.sort()
L
Out [5]: [1, 2, 3, 4, 5, 6]


One of the powerful features of Python's compound objects is
that they can contain objects of any type, or even a mix of types. 



L = [1, 'two', 3.14, [0, 3, 5]]

This flexibility is a consequence of Python's dynamic type system.

 lists can even contain
other lists as elements. Such type flexibility is an essential piece of
what makes Python code relatively quick and easy to write.




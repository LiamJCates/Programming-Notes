Types

The principal built-in types are numerics, sequences, mappings, classes, instances and exceptions.

| Type | Example | Description |
| ---- | ---- | ----------- |
| int | 1 | Integers (i.e., whole numbers) |
| float | 1.0 | Floating-point numbers (i.e., real numbers) |
| complex | 1 + 2j | Complex numbers (i.e., numbers with a real and imaginary part) |
| bool | True | Boolean: True/False values |
| str | x = 'abc' | String: characters or text |
| NoneType | None |  Special object indicating nulls |


Compound Types

Python also has several built-in compound types, which act as containers for other types. 

| Type Name | Example | Description |
| --------- | ------- | ----------- |
| list | [1, 2, 3] | Ordered collection |
| tuple | (1, 2, 3) | Immutable ordered collection |
| dict | {'a':1, 'b':2, 'c':3} | Unordered (key,value) mapping |
| set | {1, 2, 3} | Unordered collection of unique values |



More Specialized Data Structures
Python contains several other data structures that you might find
useful; these can generally be found in the built-in collections
module. The collections module is fully documented in Python’s
online documentation, and you can read more about the various
objects available there.
In particular, I’ve found the following very useful on occasion:
collections.namedtuple
Like a tuple, but each value has a name
collections.defaultdict
Like a dictionary, but unspecified keys have a user-specified
default value
collections.OrderedDict
Like a dictionary, but the order of keys is maintained


Once you’ve seen the standard built-in collection types, the use of
these extended functionalities is very intuitive, and I’d suggest read‐
ing about their use:

https://docs.python.org/3/library/collections.html


Control Flow

Conditional Statements: if, elif, and else

x = -15
if x == 0:
print(x, "is zero")
elif x > 0:
print(x, "is positive")
elif x < 0:
print(x, "is negative")
else:
print(x, "is unlike anything I've ever seen...")
-15 is negative


Note especially the use of colons (:) and whitespace to denote sepa‐
rate blocks of code.
Python adopts the if and else often used in other languages; its
more unique keyword is elif, a contraction of “else if”. In these
conditional clauses, elif and else blocks are optional; additionally,
you can optionally include as few or as many elif statements as you
would like.

for loops

for N in [2, 3, 5, 7]:
print(N, end=' ') # print all on same line
2 3 5 7

the object to the right of the in can be any Python iterator.

the range object, which generates a sequence of numbers:
In [3]: for i in range(10):
print(i, end=' ')
0 1 2 3 4 5 6 7 8 9

range starts at zero by default, and that by convention
the top of the range is not included in the output. Range objects can
also have more complicated values:
In [4]: # range from 5 to 10
list(range(5, 10))
Out [4]: [5, 6, 7, 8, 9]
In [5]: # range from 0 to 10 by 2
list(range(0, 10, 2))
Out [5]: [0, 2, 4, 6, 8]

Note that the behavior of range() is one of the differences between
Python 2 and Python 3: in Python 2, range() produces a list, while
in Python 3, range() produces an iterable object.

while loops

i = 0
while i < 10:
    print(i, end=' ')
    i += 1

0 1 2 3 4 5 6 7 8 9




The break statement breaks out of the loop entirely

a, b = 0, 1
amax = 100
L = []
while True:
(a, b) = (b, a + b)
if a > amax:
break
L.append(a)
print(L)
[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]


The continue statement skips the remainder of the current
loop, and goes to the next iteration

for n in range(20):
# check if n is even
if n % 2 == 0:
continue
print(n, end=' ')
1 3 5 7 9 11 13 15 17 19


One rarely used pattern available in Python is the else statement as
part of a for or while loop. 
The
loop-else is perhaps one of the more confusingly named statements
in Python; I prefer to think of it as a nobreak statement: that is, the else block is executed only if the loop ends naturally, without
encountering a break statement.

L = []
nmax = 30
for n in range(2, nmax):
for factor in L:
if n % factor == 0:
break
else: # no break
L.append(n)
print(L)
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]


Functions

factor-out useful pieces into reusable functions. Here we’ll
cover two ways of creating functions: the def statement, useful for
any type of function, and the lambda statement, useful for creating
short anonymous functions.

print('abc')
abc
Here print is the function name, and 'abc' is the function’s argu‐
ment.


In addition to arguments, there are keyword arguments that are
specified by name. One available keyword argument for the print()
Defining and Using Functions
|
41
function (in Python 3) is sep, which tells what character or charac‐
ters should be used to separate multiple items:
In [2]: print(1, 2, 3)
1 2 3
In [3]: print(1, 2, 3, sep='--')
1--2--3
When non-keyword arguments are used together with keyword
arguments, the keyword arguments must come at the end.

In
Python, functions are defined with the def statement. 

 def fibonacci(N):
L = []
a, b = 0, 1
while len(L) < N:
a, b = b, a + b
L.append(a)
return L

Now we have a function named fibonacci which takes a single
argument N, does something with this argument, and returns a
value; in this case, a list of the first N Fibonacci numbers:
In [5]: fibonacci(10)
Out [5]: [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]

If you’re familiar with strongly typed languages like C, you’ll imme‐
diately notice that there is no type information associated with the
function inputs or outputs. Python functions can return any Python
object, simple or compound, which means constructs that may be
difficult in other languages are straightforward in Python.
For example, multiple return values are simply put in a tuple, which
is indicated by commas:


def real_imag_conj(val):
return val.real, val.imag, val.conjugate()
r, i, c = real_imag_conj(3 + 4j)
print(r, i, c)

3.0 4.0 (3-4j)

Often when defining a function, there are certain values that we
want the function to use most of the time, but we’d also like to give
the user some flexibility. In this case, we can use default values for
arguments.

def fibonacci(N, a=0, b=1):
L = []
while len(L) < N:
a, b = b, a + b
L.append(a)
return L

With a single argument, the result of the function call is identical to
before:
In [8]: fibonacci(10)
Out [8]: [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
But now we can use the function to explore new things, such as the
effect of new starting values:
In [9]: fibonacci(10, 0, 2)
Out [9]: [2, 2, 4, 6, 10, 16, 26, 42, 68, 110]
The values can also be specified by name if desired, in which case
the order of the named values does not matter:
In [10]: fibonacci(10, b=3, a=1)
Out [10]: [3, 4, 7, 11, 18, 29, 47, 76, 123, 199]


Sometimes you might wish to write a function in which you don’t
initially know how many arguments the user will pass. In this case,
you can use the special form *args and **kwargs to catch all argu‐
ments that are passed

def catch_all(*args, **kwargs):
print("args =", args)
print("kwargs = ", kwargs)

catch_all(1, 2, 3, a=4, b=5)
args = (1, 2, 3)
kwargs = {'a': 4, 'b': 5}
In [13]: catch_all('a', keyword=2)
args = ('a',)
kwargs = {'keyword': 2}

Here it is not the names args and kwargs that are important, but the
* characters preceding them. args and kwargs are just the variable
names often used by convention, short for “arguments” and “key‐
word arguments”. The operative difference is the asterisk characters:
a single * before a variable means “expand this as a sequence”, while
a double ** before a variable means “expand this as a dictionary”. In
fact, this syntax can be used not only with the function definition,
but with the function call as well!
In [14]: inputs = (1, 2, 3)
keywords = {'pi': 3.14}
catch_all(*inputs, **keywords)
args = (1, 2, 3)
kwargs = {'pi': 3.14}


another way of
defining short, one-off functions with the lambda statement. 

add = lambda x, y: x + y
add(1, 2)
Out [15]: 3

This lambda function is roughly equivalent to
In [16]: def add(x, y):
return x + y

So why would you ever want to use such a thing? Primarily, it comes
down to the fact that everything is an object in Python, even func‐
tions themselves! That means that functions can be passed as argu‐
ments to functions.

data = [{'first':'Guido', 'last':'Van Rossum', 'YOB':1956},
{'first':'Grace', 'last':'Hopper', 'YOB':1906},
{'first':'Alan', 'last':'Turing', 'YOB':1912}]
Now suppose we want to sort this data. Python has a sorted func‐
tion that does this:
In [18]: sorted([2,4,3,5,1,6])
Out [18]: [1, 2, 3, 4, 5, 6]
But dictionaries are not orderable: we need a way to tell the function
how to sort our data. We can do this by specifying the key function,
a function which given an item returns the sorting key for that item:
In [19]: # sort alphabetically by first name
sorted(data, key=lambda item: item['first'])
Out [19]:
[{'YOB': 1912, 'first': 'Alan', 'last': 'Turing'},
{'YOB': 1906, 'first': 'Grace', 'last': 'Hopper'},
{'YOB': 1956, 'first': 'Guido', 'last': 'Van Rossum'}]
In [20]: # sort by year of birth
sorted(data, key=lambda item: item['YOB'])
Out [20]:
[{'YOB': 1906, 'first': 'Grace', 'last': 'Hopper'},
{'YOB': 1912, 'first': 'Alan', 'last': 'Turing'},
{'YOB': 1956, 'first': 'Guido', 'last': 'Van Rossum'}]
While these key functions could certainly be created by the normal,
def syntax, the lambda syntax is convenient for such short one-off
functions like these.




Iterators
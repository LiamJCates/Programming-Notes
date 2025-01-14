Syntax

This is an example of a Python statement:

'''Python
x = 1
'''

It initializes a variable named x and assigns it the value 1.

The end of this statement is the end of the line.

This is in contrast to languages like C and C++, where every statement must end with a semicolon (;).

If a variable is undefined (assigned no value), trying to use it will give you an error:

n  # try to access an undefined variable
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'n' is not defined


A statement may continue to the next line using a backslash (\):

'''Python
x = 1 + 2 + 3 + 4 +\
5 + 6 + 7 + 8
'''

We may also use parentheses ():

'''Python
x = (1 + 2 + 3 + 4 +
5 + 6 + 7 + 8)
'''

Python style guides recommend the second version.



Semicolon Can Optionally Terminate a Statement

To put multiple statements on a single line. 

'''Python
x = 1; y = 2
'''

The semicolon (;) may be used optionally in Python to put two statements on a single line.

Functionally, this is entirely equivalent to writing:

'''Python
x = 1
y = 2
'''

Multiple statements on a single line is generally discouraged by Python style guides.




Whitespace

In Python's syntax whitespace is meaningful.

A block of code is a set of statements to be treated as a unit. 

In Python, code blocks are denoted by indentation:

'''Python
for i in range(100):
    # indentation indicates code block
    total += i
'''

Indented code blocks are always preceded by a colon (:) on the previous line.

The use of indentation helps to enforce the uniform, readable style
that many find appealing in Python code. 

For example, the following two snippets will produce different results:

'''Python
if x < 4:
    y = x * 2 
    print(x)
'''
'''Python
if x < 4:
    y = x * 2
print(x)
'''

In the first, print(x) is in the indented block, and will be executed only if x is less than 4. 

In the second, print(x) is outside the block, and will be executed regardless of the value of x.

Python's use of meaningful whitespace often is surprising to programmers who are accustomed to other languages. 

Some find it can lead to much more consistent and readable code than languages that do not enforce indentation of code blocks. 

The amount of whitespace used for indenting code blocks is up to the user, as long as it is consistent throughout the script. By convention, most style guides recommend to indent code blocks by four spaces.

Whitespace within lines of code does not matter. For example, these expressions are equivalent:

'''Python
x=1+2
x = 1 + 2
x   =   1   +   2
'''

Most Python style guides recommend using a single
space around binary operators, and no space around unary operators. An example of exponentiation by a negative number:

'''Python
x = 10 ** -2
'''




Parentheses are used to group statements or mathematical operations:

'''Python
x = 9 / ( 2 + 1 )
'''

indicate that a function is being called. In the next snippet, the print() function is used to display the value of one or more expressions.

A function call is indicated by a pair of opening and closing parentheses, with the arguments to the function contained within:

'''Python
print('first value:', 1)
'''

Some functions can be called with no arguments at all, in which case
the opening and closing parentheses still must be used to indicate a
function evaluation. An example of this is the sort method of lists:

'''Python
L = [4,2,3,1]
L.sort()
print(L)

# Output:
[1, 2, 3, 4]
'''

The () after sort indicates that the function should be executed,
and is required even if no arguments are necessary.

A Note on the print() Function

The print() function is one piece that has changed between
Python 2.x and Python 3.x. In Python 2, print behaved as a state‐
ment—that is, you could write:

'''Python
# Python 2 only!
print "first value:", 1

# Output:
first value: 1
'''

For various reasons, the language maintainers decided that in
Python 3 print() should become a function, as we have seen previously.

This is one of the many backward-incompatible constructs between
Python 2 and 3. The presence of the print statement rather than the print() function is often one of the first signs that you're looking at Python 2 code.


We've mentioned Python “style guides,” which can help teams to
write code in a consistent style. The most widely used style guide in
Python is known as PEP8:
https://www.python.org/dev/peps/pep-0008/ 







Semantics

variables and objects are the primary way to store, reference, and operate on data.


Python Variables Are Pointers

variables are best thought of not as containers but as pointers.

Assigning variables in Python is as easy as putting a variable name
to the left of the equals sign (=):

'''Python
# assign 4 to the variable x
x = 4
'''
 
We are essentially defining a pointer named x that points to some location contaiyning the value 4.

because Python variables just point to various objects, there is no
need to “declare” the variable, or even require the variable to always
point to information of the same type! This is the sense in which
people say Python is dynamically typed: variable names can point to
objects of any type.

this dynamic typing is one of the pieces that makes Python so quick
to write and easy to read.

There is a consequence of this “variable as pointer” approach. If we have two variable names pointing to the same mutable object, then changing one will change the other as well:

'''Python
x = [1, 2, 3]
y = x
print(y)

x.append(4)
print(y)

# Output:
[1, 2, 3]
[1, 2, 3, 4]
'''

Though we have only modified x, we see the results of our actions when printing y.

If we assign a different value to x, this will not affect the value of y — assignment is simply a change of what object the variable points to:

'''Python
# continued from code above...

x = 'something else'
print(y)

Output:
[1, 2, 3, 4]
'''

You might wonder whether this pointer idea makes arithmetic operations in Python difficult to track, but Python is set up so that this is not an issue. 

Numbers, strings, and other simple types are immutable: you can't change their value — you can only change what value the variables point to:

'''Python
x = 10
y = x
x += 5

print("x =", x)
print("y =", y)

# Output:
x = 15
y = 10
'''
When we call x += 5, we are not modifying the value of the 5 object
pointed to by x, but rather we are changing the object to which x points. For this reason, the value of y is not affected by the operation.


Everything Is an Object
Python is an object-oriented programming language, and in Python
everything is an object.

'''Python
x = 4
print(type(x))

x = 'hello'
print(type(x))

x = 3.14159
print(type(x))

# Output:
int
str
float
'''

Python has types; however, the types are linked not to the variable
names but to the objects themselves.

Objects have state (called attributes) and associated behaviors (called methods).

These attributes and methods are accessed via the dot (.) syntax.

For example, lists have an append method:

'''Python
In [10]: L = [1, 2, 3]
L.append(100)
print(L)

# Output
[1, 2, 3, 100]
'''

In Python even simple types have attached attributes and methods.

For example, numerical types have a real and imag attribute that return
the real and imaginary part of the value, if viewed as a complex
number:

'''Python
x = 4.5
print(x.real, "+", x.imag, 'i')

Output:
4.5 + 0.0 i
'''

Methods use function call syntax. For example, floating-point numbers have a method called is_integer that checks whether the value is an integer

x = 4.5
print(x.is_integer())
x = 4.0
print(x.is_integer())

Output:
False
True

When we say that everything in Python is an object, we really mean
that everything is an object—even the attributes and methods of
objects are themselves objects with their own type information:

print(type(x.is_integer))
builtin_function_or_method




Iterators

Iterators are perhaps most easily understood in the concrete case of
iterating through a list.

for value in [2, 4, 6, 8, 10]:
# do some operation
print(value + 1, end=' ')
3 5 7 9 11

The familiar for x in y syntax allows us to repeat some operation
for each value in the list.

When
you write something like for val in L, the Python interpreter
checks whether it has an iterator interface, which you can check
yourself with the built-in iter function:

iter([2, 4, 6, 8, 10])

Output: 
<list_iterator at 0x104722400>


 The iter object is a container that gives you access to
the next object for as long as it’s valid, which can be seen with the
built-in function next:

I = iter([2, 4, 6, 8, 10])
print(next(I))
print(next(I))
print(next(I))

# Output:
2 4 6


Perhaps the most common example of this indirect iteration is the
range() function in Python 3 (named xrange() in Python 2), which
returns not a list, but a special range() object:
In [8]: range(10)
Out [8]: range(0, 10)
range, like a list, exposes an iterator:
In [9]: iter(range(10))
Out [9]: <range_iterator at 0x1045a1810>
So Python knows to treat it as if it’s a list:
In [10]: for i in range(10):
print(i, end=' ')
0 1 2 3 4 5 6 7 8 9


The benefit of the iterator indirection is that the full list is never
explicitly created! We can see this by doing a range calculation that
would overwhelm our system memory if we actually instantiated it
(note that in Python 2, range creates a list, so running the following
will not lead to good things!):
In [11]: N = 10 ** 12
for i in range(N):
if i >= 10: break
print(i, end=', ')
0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
If range were to actually create that list of one trillion values, it
would occupy tens of terabytes of machine memory: a waste, given
the fact that we’re ignoring all but the first 10 values!
In fact, there’s no reason that iterators ever have to end at all!
Python’s itertools library contains a count function that acts as an
infinite range:


from itertools import count
for i in count():
    if i >= 10:
        break
    print(i, end=', ')

0, 1, 2, 3, 4, 5, 6, 7, 8, 9,


enumerate


You might be tempted to do things this way:

In [13]: L = [2, 4, 6, 8, 10]
for i in range(len(L)):
print(i, L[i])
0 2
1 4
2 6
3 8
4 10

Python provides a cleaner syntax using the enumerate iterator:

In [14]: for i, val in enumerate(L):
print(i, val)
0 2
1 4
2 6
3 8
4 10

This is the more “Pythonic” way to enumerate the indices and values in a list.



zip

To iterate over multiple lists simultaneously, the zip iterator zips together iterables:

L = [2, 4, 6, 8, 10]
R = [3, 6, 9, 12, 15]

for lval, rval in zip(L, R):
    print(lval, rval)

# Output
2 3
4 6
6 9
8 12
10 15

Any number of iterables can be zipped together, and if they are different lengths, the shortest will determine the length of the zip.




map and filter

The map iterator takes a function and applies it to the values in an
iterator:

# find the first 10 square numbers
square = lambda x: x ** 2

for val in map(square, range(10)):
    print(val, end=' ')

# Output:
0 1 4 9 16 25 36 49 64 81

The filter iterator looks similar, except it only passes through values for which the filter function evaluates to True:

# find values up to 10 for which x % 2 is zero

is_even = lambda x: x % 2 == 0

for val in filter(is_even, range(10)):
    print(val, end=' ')

# Output:
0 2 4 6 8

The map and filter functions, along with the reduce function (which lives in Python’s functools module) are fundamental components of the functional programming style, which, while not a dominant programming style in the Python world, has its outspoken proponents (see, for example, the pytoolz library).

*args syntax works not just with
sequences, but with any iterator:

print(*range(10))
0 1 2 3 4 5 6 7 8 9

So, for example, we can get tricky and compress the map example from before into the following:

In [19]: print(*map(lambda x: x ** 2, range(10)))
0 1 4 9 16 25 36 49 64 81


the opposite of zip() is… zip()!
zip() can zip together any number of iterators or sequences

x = [1, 2, 3]
y = [4, 5, 6]
zipped = zip(x, y)
list(zipped)

x2, y2 = zip(*zip(x, y))
print(x == list(x2) and y == list(y2))

Output:
[(1, 4), (2, 5), (3, 6)]
True




Specialized Iterators: itertools

The itertools module contains a whole host of useful iterators, below are a few


itertools.permutations function, which iterates over all permutations of a sequence:

from itertools import permutations

p = permutations(range(3))
print(*p)

(0, 1, 2) (0, 2, 1) (1, 0, 2) (1, 2, 0) (2, 0, 1) (2, 1, 0)

Similarly, the itertools.combinations function iterates over all
unique combinations of N values within a list:

from itertools import combinations

c = combinations(range(4), 2)
print(*c)

(0, 1) (0, 2) (0, 3) (1, 2) (1, 3) (2, 3)

Somewhat related is the product iterator, which iterates over all sets
of pairs between two or more iterables:

from itertools import product

p = product('ab', range(3))
print(*p)


('a', 0) ('a', 1) ('a', 2) ('b', 0) ('b', 1) ('b', 2)



List Comprehensions

List comprehensions are simply a way to compress a list-building
for loop into a single short, readable line. 

L = []
for n in range(12):
L.append(n ** 2)
L

Output:
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121]


The list comprehension equivalent of this is the following:

x = [n ** 2 for n in range(12)]
print(x)

Output:
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121]

This basic syntax, then, is [expr for var in iterable], where
expr is any valid expression, var is a variable name, and iterable is
any iterable Python object.

Nested loops may be achieved

x = [(i, j) for i in range(2) for j in range(3)]
print(x)

Output:
[(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)]

You can further control the iteration by adding a conditional to the
end of the expression.

x = [val for val in range(20) if val % 3 > 0]
print(x)

Output: 
[1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19]


we can achieve a ternary conditional thusly:

x = [val if val % 2 else -val 
for val in range(20) if val % 3]
print(x)

Output: [1, -2, -4, 5, 7, -8, -10, 11, 13, -14, -16, 17, 19]

Note the line break within the list comprehension before the for
expression: this is valid in Python, and is often a nice way to break-
up long list comprehensions for greater readability. 


Once you understand the dynamics of list comprehensions, it’s
straightforward to move on to other types of comprehensions. The
syntax is largely the same; the only difference is the type of bracket
you use.

curly braces you can create a set with a set comprehension:

x = {a % 3 for a in range(1000)}
print(x)

Output:
{0, 1, 2}

With a slight tweak, you can add a colon (:) to create a dict compre‐
hension:
In [11]: {n:n**2 for n in range(6)}
Out [11]: {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
Finally, if you use parentheses rather than square brackets, you get
what’s called a generator expression:
In [12]: (n**2 for n in range(12))
Out [12]: <generator object <genexpr> at 0x1027a5a50>
A generator expression is essentially a list comprehension in which
elements are generated as needed rather than all at once


Generators


Generator Expressions

(n ** 2 for n in range(12))
Out [2]: <generator object <genexpr> at 0x104a60518>
Notice that printing the generator expression does not print the
contents; one way to print the contents of a generator expression is
to pass it to the list constructor:
In [3]: G = (n ** 2 for n in range(12))
list(G)
Out [3]: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121]
A list is a collection of values, while a generator is a recipe for producing
values
When you create a list, you are actually building a collection of val‐
ues, and there is some memory cost associated with that. When you
create a generator, you are not building a collection of values, but a
recipe for producing those values. Both expose the same iterator
interface, as we can see here:
In [4]: L = [n ** 2 for n in range(12)]
for val in L:
print(val, end=' ')
0 1 4 9 16 25 36 49 64 81 100 121
In [5]: G = (n ** 2 for n in range(12))
for val in G:
print(val, end=' ')
0 1 4 9 16 25 36 49 64 81 100 121
The difference is that a generator expression does not actually com‐
pute the values until they are needed. This not only leads to memory
efficiency, but to computational efficiency as well! This also means
that while the size of a list is limited by available memory, the size of
a generator expression is unlimited!

An example of an infinite generator expression can be created using
the count iterator defined in itertools:
In [6]: from itertools import count
count()
Out [6]: count(0)

In [7]: for i in count():
print(i, end=' ')
if i >= 10: break
0 1 2 3 4 5 6 7 8 9 10
The count iterator will go on happily counting forever until you tell
it to stop; this makes it convenient to create generators that will also
go on forever:
In [8]:
factors = [2, 3, 5, 7]
G = (i for i in count() if all(i % n > 0 for n in factors))
for val in G:
print(val, end=' ')
if val > 40: break
1 11 13 17 19 23 29 31 37 41
You might see what we’re getting at here: if we were to expand the
list of factors appropriately, what we would have the beginnings of is
a prime number generator, using the Sieve of Eratosthenes algo‐
rithm.

A list can be iterated multiple times; a generator expression is single use:

In [9]: L = [n ** 2 for n in range(12)]
for val in L:
print(val, end=' ')
print()
for val in L:
print(val, end=' ')
0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121


A generator expression, on the other hand, is used up after one iteration:
In [10]: G = (n ** 2 for n in range(12))
list(G)
Out [10]: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121]
In [11]: list(G)
Out [11]: []

This can be very useful because it means iteration can be stopped
and started:
In [12]: G = (n**2 for n in range(12))
for n in G:
print(n, end=' ')
if n > 30: break
print("\ndoing something in between")
for n in G:
print(n, end=' ')
0 1 4 9 16 25 36
doing something in between
49 64 81 100 121

the generator keeps track of which values have already been generated


Beware, this function will return an empty list due to how generator comprehension works. Python does not have tuple comprehension

def mul_by_n(lst, n):
    print("Inputs: ", lst, n) # Check our inputs
    result = (x * n for x in lst)
    print("Result: ", list(result)) # Check our result
    return list(result)



Generator Functions: Using yield

we can make more complicated generators
using generator functions, which make use of the yield statement.

G1 = (n ** 2 for n in range(12))

def gen():
    for n in range(12):
        yield n ** 2

G2 = gen()

print(*G1)
print(*G2)

0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121

A generator function is a function that, rather than using return to
return a value once, uses yield to yield a (potentially infinite)
sequence of values. Just as in generator expressions, the state of the
generator is preserved between partial iterations, but if we want a
fresh copy of the generator we can simply call the function again.

 example of a generator function: a func‐
tion to generate an unbounded series of prime numbers. A classic
algorithm for this is the Sieve of Eratosthenes


def gen_primes(N):
    """Generate primes up to N"""
    primes = set()
    for n in range(2, N):
        if all(n % p > 0 for p in primes):
            primes.add(n)
            yield n

print(*gen_primes(70))

2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67








Modules and Packages

Loading Modules: the import Statement
For loading built-in and third-party modules, Python provides the
import statement. 

Explicit module import
Explicit import of a module preserves the module’s content in a
namespace. The namespace is then used to refer to its contents with
dot notation.

import math

print(math.cos(math.pi))

Output:
-1.0


Explicit module import by alias

For longer module names, it’s not convenient to use the full module
name each time you access some element.

import numpy as np

print(np.cos(np.pi))

Output: 
-1.0


Explicit import of module contents

to import a few particular items from the module

from math import cos, pi

print(cos(pi))

Output: 
-1.0

Implicit import of module contents

to import the entirety of the module contents into the local namespace.

from math import *

print(sin(pi) ** 2 + cos(pi) ** 2)

Output: 
1.0

Caution should be used with this method, as it can create namespace conflicts




import numpy as np

arr = np.array([ [1, 2, 3], 
                 [4, 5, 6]])

# Sum of all elements
print(np.sum(arr))  # Output: 21

# Sum along columns
print(np.sum(arr, axis=0))  # Output: [5, 7, 9]

# Sum along rows
print(np.sum(arr, axis=1))  # Output: [6, 15]
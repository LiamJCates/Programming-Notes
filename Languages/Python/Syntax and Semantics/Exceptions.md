Errors and Exceptions
No matter your skill as a programmer, you will eventually make a
coding mistake. Such mistakes come in three basic flavors:
Syntax errors
Errors where the code is not valid Python (generally easy to fix)
Runtime errors
Errors where syntactically valid code fails to execute, perhaps
due to invalid user input (sometimes easy to fix)
Semantic errors
Errors in logic: code executes without a problem, but the result
is not what you expect (often very difficult to identify and fix)

Python handles runtime errors via its exception
handling framework.


Runtime Errors
If you’ve done any coding in Python, you’ve likely come across run‐
time errors. They can happen in a lot of ways.
For example, if you try to reference an undefined variable:
In [1]: print(Q)
---------------------------------------------------------
NameError Traceback (most recent call last)
<ipython-input-3-e796bdcf24ff> in <module>()
----> 1 print(Q)
NameError: name 'Q' is not defined
Or if you try an operation that’s not defined:
In [2]: 1 + 'abc'
---------------------------------------------------------
TypeError Traceback (most recent call last)
<ipython-input-4-aab9e8ede4f7> in <module>()
----> 1 1 + 'abc'
TypeError: unsupported operand type(s) for +: 'int' and 'str'
Or you might be trying to compute a mathematically ill-defined
result:
In [3]: 2 / 0
---------------------------------------------------------
ZeroDivisionError Traceback (most recent call last)
<ipython-input-5-ae0c5d243292> in <module>()
----> 1 2 / 0
ZeroDivisionError: division by zero

Or maybe you’re trying to access a sequence element that doesn’t
exist:
In [4]: L = [1, 2, 3]
L[1000]
---------------------------------------------------------
IndexError Traceback (most recent call last)
<ipython-input-6-06b6eb1b8957> in <module>()
1 L = [1, 2, 3]
----> 2 L[1000]
IndexError: list index out of range

Note that in each case, Python is kind enough to not simply indicate that an error happened, but to spit out a meaningful exception that includes information about what exactly went wrong, along with the exact line of code where the error happened.


Catching Exceptions: try and except
The main tool Python gives you for handling runtime exceptions is
the try…except clause. Its basic structure is this:
try:
    print("this gets executed first")
except:
    print("this gets executed only if there is an error")

# Output:
this gets executed first

Note that the second block here did not get executed: this is because
the first block did not return an error.


Let’s put a problematic statement in the try block and see what happens:

try:
    print("let's try something:")
    x = 1 / 0 # ZeroDivisionError
except:
    print("something bad happened!")

# Output
let's try something:
something bad happened!

Here we see that when the error was raised in the try statement (in this case, a ZeroDivisionError), the error was caught, and the except statement was executed.

it's nearly always a better idea to catch exceptions explicitly:


def safe_divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        return 1E100

print(safe_divide(1, 0))
print(safe_divide(1, '2'))

# Output
1e+100

---------------------------------------------------------
TypeError Traceback (most recent call last)
<ipython-input-15-2331af6a0acf> in <module>()
----> 1 safe_divide(1, '2')

<ipython-input-13-10b5f0163af8> in safe_divide(a, b)
1 def safe_divide(a, b):
2 try:
----> 3 return a / b
4 except ZeroDivisionError:
5 return 1E100
TypeError: unsupported operand type(s) for /: 'int' and 'str'


Raising Exceptions: raise


The way you raise your own exceptions is with the raise statement.

raise RuntimeError("my error message")
---------------------------------------------------------
RuntimeError Traceback (most recent call last)
<ipython-input-16-c6a4c1ed2f34> in <module>()
----> 1 raise RuntimeError("my error message")
RuntimeError: my error message

def fibonacci(N):
if N < 0:
raise ValueError("N must be non-negative")
L = []
a, b = 0, 1
while len(L) < N:
a, b = b, a + b
L.append(a)
return L
In [17]: fibonacci(10)
Out [17]: [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
In [18]: fibonacci(-10)
---------------------------------------------------------
RuntimeError Traceback (most recent call last)
<ipython-input-20-3d291499cfa7> in <module>()
----> 1 fibonacci(-10)
<ipython-input-18-01d0cf168d63> in fibonacci(N)
1 def fibonacci(N):
2 if N < 0:
----> 3 raise ValueError("N must be non-negative")
4 L = []
5 a, b = 0, 1
ValueError: N must be non-negative


Now the user knows exactly why the input is invalid, and could even
use a try…except block to handle it!
In [19]: N = -10
try:
print("trying this...")
print(fibonacci(N))
except ValueError:
print("Bad value: need to do something else")
trying this...
Bad value: need to do something else


Accessing the error message

Sometimes in a try…except statement, you would like to be able to
work with the error message itself. This can be done with the as
keyword:
In [20]: try:
x = 1 / 0
except ZeroDivisionError as err:
print("Error class is: ", type(err))
print("Error message is:", err)
Error class is: <class 'ZeroDivisionError'>
Error message is: division by zero
With this pattern, you can further customize the exception handling
of your function.


Defining custom exceptions


it is possible to define custom
exceptions through class inheritance. For instance, if you want a spe‐
cial kind of ValueError, you can do this:
In [21]: class MySpecialError(ValueError):
pass
raise MySpecialError("here's the message")
---------------------------------------------------------
MySpecialError Traceback (most recent call last)
<ipython-input-23-92c36e04a9d0> in <module>()
2 pass
3
----> 4 raise MySpecialError("here's the message")
MySpecialError: here's the message

try…except…else…finally

 you can use the else and finally
keywords to further tune your code’s handling of exceptions

 try:
print("try something here")
except:
print("this happens only if it fails")
else:
print("this happens only if it succeeds")
finally:
print("this happens no matter what")
try something here
this happens only if it succeeds
this happens no matter what
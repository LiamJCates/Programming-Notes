Creating Your Own Exception Classes
Whenever you create your own classes or write programs, exceptions are likely to
occur. As you have seen, C++ provides numerous exception classes to deal with
these situations. However, it does not provide all of the exception classes you will ever need. Therefore, C++ enables programmers to create their own exception classes.

You can define your own exceptions whenever you’d like; usually, these
user-defined exceptions inherit from std::exception. All the classes from stdlib
use exceptions that derive from std::exception. This makes it easy to catch
all exceptions, whether from your code or from the stdlib, with a single
catch block.

C++ uses the same mechanism to process the exceptions that you define as it uses
for built-in exceptions. However, you must throw your own exceptions using the
throw statement.
In C++, any class can be considered an exception class. Therefore, an exception class
is simply a class. It need not be inherited from the class exception. What makes a
class an exception is how you use it.
The exception class that you define can be very simple in the sense that it does not
contain any members. For example, the following code can be considered an exception class:
class dummyExceptionClass
{
};



// User-defined exception class.
#include <iostream>
#include <string>
using namespace std;
class divisionByZero
{
public:
  divisionByZero()
  {
    message = "Division by zero";
  }
  divisionByZero(string str)
  {
    message = str;
  }
  string what()
  {
    return message;
  }
private:
    string message;
};

The definition of the class divisionByZero contains two constructors: the default
constructor and the constructor with parameters. The default constructor stores the
string "Division by zero" in an object. The constructor with parameters allows
users to create their own error messages. The function what is used to return the
string stored in the object.
In the definition of the class divisionByZero, the constructors can also be
written as:
divisionByZero() : message("Division by zero"){}
divisionByZero(string str) : message(str){}

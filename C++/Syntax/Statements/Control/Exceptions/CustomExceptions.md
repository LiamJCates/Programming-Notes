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
















To throw an exception that includes more than one variable with or without the same type  create your own exception class that can contain more than one piece of information. It should preferably derive from std::exception. If you make this a strategy, you can always catch your exceptions with a single catch(std::exception&) (useful if you only want to free some resource, and then rethrow the exception - you don't have to have a gazilion catch handlers for each and every exception type you throw).

Example:

class MyException : public std::exception {
   int x;
   const char* y;

public:
   MyException(const char* msg, int x_, const char* y_)
      : std::exception(msg)
      , x(x_)
      , y(y_) {
   }

   int GetX() const { return x; }
   const char* GetY() const { return y; }
};

...

try {
   throw MyException("Shit just hit the fan...", 1234, "Informational string");
} catch(MyException& ex) {
   LogAndShowMessage(ex.what());
   DoSomething(ex.GetX(), ex.GetY());
}

Exceptions provide a way to transfer control from one part of a program to another. C++ exception handling is built upon three keywords: try, catch, and throw.

    throw − A program throws an exception when a problem shows up. This is done using a throw keyword.

    catch − A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.

    try − A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

Assuming a block will raise an exception, a method catches an exception using a combination of the try and catch keywords. A try/catch block is placed around the code that might generate an exception. Code within a try/catch block is referred to as protected code, and the syntax for using try/catch as follows −

try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}


Throwing Exceptions

Exceptions can be thrown anywhere within a code block using throw statement. The operand of the throw statement determines a type for the exception and can be any expression and the type of the result of the expression determines the type of exception thrown.

Following is an example of throwing an exception when dividing by zero condition occurs −

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

Catching Exceptions

The catch block following the try block catches any exception. You can specify what type of exception you want to catch and this is determined by the exception declaration that appears in parentheses following the keyword catch.

try {
   // protected code
} catch( ExceptionName e ) {
  // code to handle ExceptionName exception
}

Above code will catch an exception of ExceptionName type. If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception declaration as follows −

try {
   // protected code
} catch(...) {
  // code to handle any exception
}





Let us now note the following about try/catch blocks.
? If no exception is thrown in a that try block are ignored and program execution resumes after the last try block, all catch blocks associated with
catch block.
? If an exception is thrown in a that try block are ignored. The program searches the try block, the remaining statements in catch blocks in
the order they appear after the try block and looks for an appropriate
exception handler. If the type of thrown exception matches the parameter
type in one of the catch blocks, the code of that catch block executes, and
the remaining catch blocks after this catch block are ignored.
? The last catch block that has an ellipsis (three dots) is designed to catch
any type of exception.





C++ Standard Exceptions

C++ provides a list of standard exceptions defined in <exception> which we can use in our programs.

C11 provides support to handle exceptions via a hierarchy of classes. The class
exception is the base of the classes designed to handle exceptions. Among others,
this class contains the function what. The function what returns a string containing an appropriate message. All derived classes of the class exception override the
function what to issue their own error messages.

Two classes are immediately derived from the class exception: logic_error and
runtime_error. Both of these classes are defined in the header file stdexcept.
To deal with logical errors in a program, such as a string subscript out of range or
an invalid argument to a function call, several classes are derived from the class
logic_error. For example, the class invalid_argument is designed to deal with
illegal arguments used in a function call. The class out_of_range deals with the
string subscript out of range error. If a length greater than the maximum allowed for
a string object is used, the class length_error deals with this error. For example,
recall that every string object has a maximum length (see Chapter 7). If a length larger
than the maximum length allowed for a string is used, then the length_error exception is generated. If the operator new cannot allocate memory space, this operator
throws a bad_alloc exception.
The class runtime_error is designed to deal with errors that can be detected only
during program execution. For example, to deal with arithmetic overflow and underflow exceptions, the classes overflow_error and underflow_error are derived
from the class runtime_error.




Creating Your Own Exception Classes
Whenever you create your own classes or write programs, exceptions are likely to
occur. As you have seen, C11 provides numerous exception classes to deal with
these situations. However, it does not provide all of the exception classes you will ever
need. Therefore, C11 enables programmers to create their own exception classes to
handle both the exceptions not covered by C11’s exception classes and their own
exceptions. This section describes how to create your own exception classes.
C11 uses the same mechanism to process the exceptions that you define as it uses
for built-in exceptions. However, you must throw your own exceptions using the
throw statement.
In C11, any class can be considered an exception class. Therefore, an exception class
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


A tour of C++ 48/255

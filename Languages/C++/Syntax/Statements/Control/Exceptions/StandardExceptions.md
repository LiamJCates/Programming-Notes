Standard Exceptions
C++ enables you to throw exceptions of any type, although in general it is recommended to throw types that are derived from std::exception.

C++ provides a list of standard exceptions defined in <exception> and support to handle exceptions via a hierarchy of classes.

The rules for exception handling are based on class inheritance. When
an exception is thrown, a catch block handles the exception if the thrown
exception’s type matches the catch handler’s exception type or if the
thrown exception’s type inherits from the catch handler’s exception type.

There is a hierarchy of existing exception types available for use in the
stdlib.

This hierarchy has many types for exceptions that occur often and their use is recommended.

<stdexcept>: Defines a set of standard exceptions that both the library and programs can use to report common errors.

<exception>: Defines the base class (i.e., std::exception) for all exceptions thrown by the elements of the standard library, along with several types and utilities to assist handling exceptions.

<exception> only defines the class std::exception, while <stdexcept> defines several classes that inherit from std::exception (e.g., std::logic_error, std::out_of_range). That is why <stdexcept> includes <exception>.

They are in separate headers because if you want to define your own exception class inheriting std::exception (and not use the classes from <stdexcept>), you can avoid unnecessary definitions.




### Standard Exception Classes
The stdlib provides you with the standard exception classes in the <stdexcept>
header. These should be your first port of call when you’re programming
exceptions. The superclass for all the standard exception classes is the
class std::exception. The class exception is the base of the classes designed to handle exceptions.

All the subclasses in <stdexcept> can be partitioned into three groups:
  logic errors
  runtime errors
  language support errors

While language support errors are not generally relevant to you as a programmer, you’ll definitely encounter logic errors and runtime errors.

Two classes are immediately derived from the class exception: logic_error and
runtime_error.


Logic Errors
Logic errors derive from the logic_error class. Generally, you could avoid these
exceptions through more careful programming. A primary example is when
a logical precondition of a class isn’t satisfied, such as when a class invariant cannot be established.

a class invariant is something that the programmer defines, neither the compiler nor the runtime environment can enforce it without help.
You can use a class constructor to check for various conditions, and if you
cannot establish a class invariant, you can throw an exception. If the failure
is the result of, say, passing an incorrect parameter to the constructor, a
logic_error is an appropriate exception to throw.

To deal with logical errors in a program, such as a string subscript out of range or an invalid argument to a function call, several classes are derived from the class logic_error. For example, the class invalid_argument is designed to deal with illegal arguments used in a function call. The class out_of_range deals with the
string subscript out of range error. If a length greater than the maximum allowed for
a string object is used, the class length_error deals with this error. For example,
recall that every string object has a maximum length (see Chapter 7). If a length larger
than the maximum length allowed for a string is used, then the length_error exception is generated. If the operator new cannot allocate memory space, this operator
throws a bad_alloc exception.


The logic_error has several subclasses that you should be aware of:
•	 The domain_error reports errors related to valid input range, especially
for math functions. The square root, for example, only supports nonnegative numbers (in the real case). If a negative argument is passed, a
square root function could throw a domain_error.
•	 The invalid_argument exception reports generally unexpected arguments.
•	 The length_error exception reports that some action would violate a
maximum size constraint.
•	 The out_of_range exception reports that some value isn’t in an expected
range. The canonical example is bounds-checked indexing into a data
structure.




Runtime Errors
Runtime errors derive from the runtime_error class. These exceptions help
you report error conditions that are outside the program’s scope.

The class runtime_error is designed to deal with errors that can be detected only
during program execution. For example, to deal with arithmetic overflow and underflow exceptions, the classes overflow_error and underflow_error are derived
from the class runtime_error.

runtime_error has some subclasses that you might find useful:
•	 The system_error reports that the operating system encountered some
error. You can get a lot of mileage out of this kind of exception. Inside
of the <system_error> header, there’s a large number of error codes and
error conditions. When a system_error is constructed, information about
the error is packed in so you can determine the nature of the error.
The .code() method returns an enum class of type std::errc that has
a large number of values, such as bad_file_descriptor, timed_out, and
permission_denied.
•	 The overflow_error and underflow_error report arithmetic overflow and
underflow, respectively.
Other errors inherit directly from exception. A common one is the
bad_alloc exception, which reports that new failed to allocate the required
memory for dynamic storage.
Language Support Errors
You won’t use language support errors directly. They exist to indicate that
some core language feature failed at runtime.


Example



All exceptions thrown by components of the C++ Standard library throw exceptions derived from this exception class. These are:

exception	description
bad_alloc	thrown by new on allocation failure
bad_cast	thrown by dynamic_cast when it fails in a dynamic cast
bad_exception	thrown by certain dynamic exception specifiers
bad_typeid	thrown by typeid
bad_function_call	thrown by empty function objects
bad_weak_ptr	thrown by shared_ptr when passed a bad weak_ptr

Also deriving from exception, header <exception> defines two generic exception types that can be inherited by custom exceptions to report errors:

exception	description
logic_error	error related to the internal logic of the program
runtime_error	error detected during runtime

A typical example where standard exceptions need to be checked for is on memory allocation:

  // bad_alloc standard exception
  #include <iostream>
  #include <exception>
  using namespace std;

  int main () {
    try
    {
      int* myarray= new int[1000];
    }
    catch (exception& e)
    {
      cout << "Standard exception: " << e.what() << endl;
    }
    return 0;
  }

The exception that may be caught by the exception handler in this example is a bad_alloc. Because bad_alloc is derived from the standard base class exception, it can be caught (capturing by reference, captures all related classes).











#### what
The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions. It is called std::exception and is defined in the <exception> header.

Among others, this class contains the function what. The function what returns a string containing an appropriate message. All derived classes of the class exception override the function what to issue their own error messages.


This class has a virtual member function called what that returns a null-terminated character sequence (of type char *) and that can be overwritten in derived classes to contain some sort of description of the exception.

  // using standard exceptions
  #include <iostream>
  #include <exception>
  using namespace std;

  class myexception: public exception
  {
    virtual const char* what() const throw()
    {
      return "My exception happened";
    }
  } myex;

  int main () {
    try
    {
      throw myex;
    }
    catch (exception& e)
    {
      cout << e.what() << '\n';
    }
    return 0;
  }


Output
  My exception happened

We have placed a handler that catches exception objects by reference (notice the ampersand & after the type), therefore this catches also classes derived from exception, like our myex object of type myexception.

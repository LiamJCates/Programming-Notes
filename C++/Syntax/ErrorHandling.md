Exceptions provide a way to transfer control from one part of a program to another.

Exceptions are types that communicate an error condition.

When an error
condition occurs, you throw an exception. After you throw an exception, it’s
in flight. When an exception is in flight, the program stops normal execution and searches for an exception handler that can manage the in-flight
exception. Objects that fall out of scope during this process are destroyed.
In situations where there’s no good way to handle an error locally, such
as in a constructor, you generally use exceptions. Exceptions play a crucial
role in managing object life cycles in such circumstances.
The other option for communicating error conditions is to return an
error code as part of a function’s prototype. These two approaches are
complementary. In situations where an error occurs that can be dealt with
locally or that is expected to occur during the normal course of a program’s
execution, you generally return an error code.


C++ exception handling is built upon three keywords: try, catch, and throw.

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

Once an exception occurs in a try{} block, no further statements execute.

Throwing Exceptions
To throw an exception, use the throw keyword followed by a throwable object.
Most objects are throwable. But it’s good practice to use one of the
exceptions available in stdlib, such as std::runtime_error in the <stdexcept>
header. The runtime_error constructor accepts a null-terminated const char*
describing the nature of the error condition. You can retrieve this message
via the what method, which takes no parameters.

Exceptions can be thrown anywhere within a code block using throw statement. The operand of the throw statement determines a type for the exception and can be any expression and the type of the result of the expression determines the type of exception thrown.

Following is an example of throwing an exception when dividing by zero condition occurs −

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}




Catching Exceptions
The catch block following the try block catches a specified exception.

You use try-catch blocks to establish exception handlers for a block of code.
Within the try block, you place code that might throw an exception. Within
the catch block, you specify a handler for each exception type you can handle.

You can specify what type of exception you want to catch and this is determined by the exception declaration that appears in parentheses following the keyword catch.

try {
   // protected code
} catch( ExceptionName e ) {
  // code to handle ExceptionName exception
}

Above code will catch an exception of ExceptionName type. If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception declaration.

The following special handler catches any exception regardless of its type:

try {
   // protected code
} catch(...) {
  // code to handle any exception
}

Special handlers are typically used as a safety mechanism to log the
program’s catastrophic failure to catch an exception of a specific type.
You can handle different types of exceptions originating from the same
try block by chaining together catch statements, as demonstrated here:
try {
// Code that might throw an exception
--snip--
} catch (const std::logic_error& ex) {
// Log exception and terminate the program; there is a programming error!
--snip--
} catch (const std::runtime_error& ex) {
// Do our best to recover gracefully
--snip--
} catch (const std::exception& ex) {
// This will handle any exception that derives from std:exception
// that is not a logic_error or a runtime_error.
--snip--
} catch (...) {
// Panic; an unforeseen exception type was thrown
--snip--
}

It’s common to see such code in a program’s entry point.


Rethrowing An Exception
In a catch block, you can use the throw keyword to resume searching for an
appropriate exception handler. This is called rethrowing an exception. There
are some unusual but important cases where you might want to further inspect
an exception before deciding to handle it, as shown:
try {
// Some code that might throw a system_error
--snip--
} catch(const std::system_error& ex) {
if(ex.code()!= std::errc::permission_denied){
// Not a permission denied error
throw;
}
// Recover from a permission denied
--snip--
}

In this example, some code that might throw a system_error is wrapped
in a try-catch block. All system_errors are handled, but unless it’s an EACCES
(permission denied) error, you rethrow the exception. There are some performance penalties to this approach, and the resulting code is often needlessly convoluted.

Rather than rethrowing, you can define a new exception type and create
a separate catch handler for the EACCES error, as demonstrated:

try {
// Throw a PermissionDenied instead
--snip--
} catch(const PermissionDenied& ex) {
// Recover from an EACCES error (Permission Denied
--snip--
}

If a std::system_error is thrown, the PermissionDenied handler won’t
catch it. (Of course, you could still keep the std::system_error handler to catch such exceptions if you wish.)







Handling Exceptions
If no exception is thrown in a that try block are ignored and program execution resumes after the last try block, all catch blocks associated with catch block.

If an exception is thrown in a that try block are ignored. The program searches the try block, the remaining statements in catch blocks in the order they appear after the try block and looks for an appropriate
exception handler. If the type of thrown exception matches the parameter
type in one of the catch blocks, the code of that catch block executes, and
the remaining catch blocks after this catch block are ignored.
? The last catch block that has an ellipsis (three dots) is designed to catch
any type of exception.


The rules for exception handling are based on class inheritance. When
an exception is thrown, a catch block handles the exception if the thrown
exception’s type matches the catch handler’s exception type or if the
thrown exception’s type inherits from the catch handler’s exception type.




C++ Standard Exceptions

C++ provides a list of standard exceptions defined in <exception> which we can use in our programs.

C++ provides support to handle exceptions via a hierarchy of classes. The class
exception is the base of the classes designed to handle exceptions. Among others,
this class contains the function what. The function what returns a string containing an appropriate message. All derived classes of the class exception override the
function what to issue their own error messages.

stdlib Exception Classes
You can arrange classes into parent-child relationships using inheritance.
Inheritance has a big impact on how the code handles exceptions. There is
a nice, simple hierarchy of existing exception types available for use in the
stdlib. You should try to use these types for simple programs.

Standard Exception Classes
The stdlib provides you with the standard exception classes in the <stdexcept>
header. These should be your first port of call when you’re programming
exceptions. The superclass for all the standard exception classes is the
class std::exception. All the subclasses in std::exception can be partitioned
into three groups: logic errors, runtime errors, and language support
errors. While language support errors are not generally relevant to you as
a programmer, you’ll definitely encounter logic errors and runtime errors.

Two classes are immediately derived from the class exception: logic_error and
runtime_error. Both of these classes are defined in the header file stdexcept.


Logic Errors
Logic errors derive from the logic_error class. Generally, you could avoid these
exceptions through more careful programming. A primary example is when
a logical precondition of a class isn’t satisfied, such as when a class invariant
cannot be established.

ince a class invariant is something that the programmer defines, neither the compiler nor the runtime environment can enforce it without help.
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












The noexcept Keyword
The keyword noexcept is another exception-related term you should know.
You can, and should, mark any function that cannot possibly throw an
exception noexcept, as in the following:
bool is_odd(int x) noexcept {
return 1 == (x % 2);
}
Functions marked noexcept make a rigid contract. When you’re using
a function marked noexcept, you can rest assured that the function cannot throw an exception. In exchange, you must be extremely careful when
you mark your own function noexcept, since the compiler won’t check for
you. If your code throws an exception inside a function marked noexcept,The Object Life Cycle 105
it’s bad juju. The C++ runtime will call the function std::terminate, a function that by default will exit the program via abort. Your program cannot
recover:
void hari_kari() noexcept {
throw std::runtime_error{ "Goodbye, cruel world." };
}
Marking a function noexcept enables some code optimizations that rely
on the function’s not being able to throw an exception.

Check out Item 16 of Effective Modern C++ by Scott Meyers for a thorough discussion of noexcept. The gist is that some move constructors and move assignment operators might throw an exception, for example, if they need to allocate memory and the
system is out. Unless a move constructor or move assignment operator specifies otherwise, the compiler must assume that a move could cause an exception. This disables
certain optimizations.





Call Stacks and Exceptions

Call Stacks and Exception Handling
The runtime seeks the closest exception handler to a thrown exception.
If there is a matching exception handler in the current stack frame, it will
handle the exception. If no matching handler is found, the runtime will
unwind the call stack until it finds a suitable handler. Any objects whose
lifetimes end are destroyed in the usual way.

Throwing in Destructors
If you throw an exception in a destructor, you are juggling with chainsaws. Such an exception absolutely must be caught within the destructor.

Suppose an exception is thrown, and during stack unwinding, another exception is thrown by a destructor during normal cleanup. Now you have two exceptions in flight. How should the C++ runtime handle such a situation?

The runtime will call terminate.

Consider throwing an exception from a destructor:

#include <cstdio>
#include <stdexcept>
struct CyberdyneSeries800
{
  CyberdyneSeries800()
  {
    printf( "I'm a friend of Sarah Connor." );
  }
  ~CyberdyneSeries800()
  {
    throw std::runtime_error{ "I'll be back." };
  }
};

int main() {
  try
  {
    CyberdyneSeries800 t800;
    throw std::runtime_error{ "Come with me if you want to live." };
  }
  catch(const std::exception& e)
  {
    printf("Caught exception: %s\n", e.what());
  }
}


First, you declare the CyberdyneSeries800 class, which has a simple constructor that prints a message and a thoroughly belligerent destructor
that throws an uncaught exception.

Within main, you set up a try block where you initialize a CyberdyneSeries800 called t800 and throw a runtime_error. Under better circumstances, the catch block would handle this exception, print its message, and exit gracefully. Because t800 is an automatic variable within the try block, it destructs during the normal process of finding a handler for the exception you’ve thrown.

And because t800 throws an exception in its destructor, your program invokes
std::terminate and ends abruptly.

As a general rule, treat destructors as if they were noexcept.



Exceptions and Performance
In your programs, you must handle errors; errors are unavoidable. When you
use exceptions correctly and no errors occur, your code is faster than manually error-checked code. If an error does occur, exception handling can sometimes be slower, but you make huge gains in robustness and maintainability
over the alternative. Kurt Guntheroth, the author of Optimized C++, puts it
well: “use of exception handling leads to programs that are faster when they
execute normally, and better behaved when they fail.” When a C++ program
executes normally (without exceptions being thrown), there is no runtime
overhead associated with checking exceptions. It’s only when an exception is
thrown that you pay overhead.
Hopefully, you’re convinced of the central role exceptions play in idiomatic C++ programs. Sometimes, unfortunately, you won’t be able to use
exceptions. One example is embedded development where real-time guarantees are required. Tools simply don’t (yet) exist in this setting. With luck,
this will change soon, but for now, you’re stuck without exceptions in most
embedded contexts. Another example is with some legacy code. Exceptions
are elegant because of how they fit in with RAII objects. When destructors are responsible for cleaning up resources, stack unwinding is a direct
and effective way to guarantee against resource leakages. In legacy code,
you might find manual resource management and error handling instead
of RAII objects. This makes using exceptions very dangerous, because stack
unwinding is safe only with RAII objects. Without them, you could easily
leak resources.




## Alternatives to Exceptions
In situations where exceptions are not available, all is not lost. Although
you’ll need to keep track of errors manually, there are some helpful C++
features that you can employ to take the sting out a bit. First, you can manually enforce class invariants by exposing some method that communicates
whether the class invariants could be established, as shown here:
struct HumptyDumpty {
HumptyDumpty();
bool is_together_again();
--snip--
};
In idiomatic C++, you would just throw an exception in the constructor,
but here you must remember to check and treat the situation as an error
condition in your calling code:
bool send_kings_horses_and_men() {
HumptyDumpty hd{};
if (hd.is_together_again()) return false;
// Class invariants of hd are now guaranteed.
// Humpty Dumpty had a great fall.
--snip--
return true;
}


### Structured Binding Declaration
The second, complementary coping strategy is to return multiple values using structured binding declaration, a language feature that allows you to
return multiple values from a function call. You can use this feature to return
success flags alongside the usual return value, as demonstrated in Listing 4-22.
struct Result { u
HumptyDumpty hd;
bool success;
};
Result make_humpty() { v
HumptyDumpty hd{};
bool is_valid;
// Check that hd is valid and set is_valid appropriately
return { hd, is_valid };
}
bool send_kings_horses_and_men() {
auto [hd, success] = make_humpty(); w
if(!success) return false;
// Class invariants established
--snip--
return true;
}



A tour of C++ 48/255

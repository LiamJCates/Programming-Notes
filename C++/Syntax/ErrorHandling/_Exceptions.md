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
If no exception is thrown, program execution resumes after the last try block, all catch blocks associated with catch block.

If an exception is thrown, the program searches the try block, then the remaining statements in catch blocks in the order they appear after the try block to look for an appropriate exception handler.

If the type of thrown exception matches the parameter type in one of the catch blocks, the code of that catch block executes, and the remaining catch blocks after this catch block are ignored.

A catch block that has an ellipsis (three dots) is designed to catch
any type of exception.


The rules for exception handling are based on class inheritance. When
an exception is thrown, a catch block handles the exception if the thrown
exception’s type matches the catch handler’s exception type or if the
thrown exception’s type inherits from the catch handler’s exception type.

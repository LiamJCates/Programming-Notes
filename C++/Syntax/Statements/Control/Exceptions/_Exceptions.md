Exception handling provides a way of transferring control and information from some point in the execution of a program to a handler associated with a point previously passed by the execution (in other words, exception handling transfers control up the call stack)

An exception can be thrown by a throw-expression, dynamic_cast, typeid, new-expression, allocation function, and any of the standard library functions that are specified to throw exceptions to signal certain error conditions (e.g. std::vector::at, std::string::substr, etc).

In order for an exception to be caught, the throw-expression has to be inside a try-block or inside a function called from a try-block, and there has to be a catch clause that matches the type of the exception object.

When declaring a function, exception specifications and noexcept specifiers may be provided to limit the types of the exceptions a function may throw.




### What is an Exception
Exceptions are types that communicate an error condition.

When an error condition occurs, you throw an exception. After you throw an exception, it’s in flight. When an exception is in flight, the program stops normal execution and searches for an exception handler that can manage the in-flight exception. Objects that fall out of scope during this process are destroyed. In situations where there’s no good way to handle an error locally, such as in a constructor, you generally use exceptions. Exceptions play a crucial role in managing object life cycles in such circumstances. The other option for communicating error conditions is to return an error code as part of a function’s prototype. These two approaches are complementary. In situations where an error occurs that can be dealt with locally or that is expected to occur during the normal course of a program’s execution, you generally return an error code.



### Syntax
C++ exception handling is built upon three keywords which specify try, catch, and throw expressions:

    throw − A program throws an exception when a problem shows up. This is done using a throw keyword.

    catch − A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.

    try − A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.



First, use a try block to enclose one or more statements that might throw an exception.

A throw expression signals that an exceptional condition—often, an error—has occurred in a try block. You can use an object of any type as the operand of a throw expression. Typically, this object is used to communicate information about the error. In most cases, we recommend that you use the std::exception class or one of the derived classes that are defined in the standard library. If one of those is not appropriate, we recommend that you derive your own exception class from std::exception.

To handle exceptions that may be thrown, implement one or more catch blocks immediately following a try block. Each catch block specifies the type of exception it can handle.


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




### Throwing Exceptions
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



### Catching Exceptions
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



### Rethrowing An Exception
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




### Handling Exceptions
If no exception is thrown, program execution resumes after the last try block, all catch blocks associated with catch block.

If an exception is thrown, the program searches the try block, then the remaining statements in catch blocks in the order they appear after the try block to look for an appropriate exception handler.

If the type of thrown exception matches the parameter type in one of the catch blocks, the code of that catch block executes, and the remaining catch blocks after this catch block are ignored.

A catch block that has an ellipsis (three dots) is designed to catch
any type of exception.


The rules for exception handling are based on class inheritance. When
an exception is thrown, a catch block handles the exception if the thrown
exception’s type matches the catch handler’s exception type or if the
thrown exception’s type inherits from the catch handler’s exception type.



Unhandled C++ exceptions

If a matching handler (or ellipsis catch handler) cannot be found for the current exception, the predefined terminate run-time function is called. (You can also explicitly call terminate in any of your handlers.) The default action of terminate is to call abort. If you want terminate to call some other function in your program before exiting the application, call the set_terminate function with the name of the function to be called as its single argument. You can call set_terminate at any point in your program. The terminate routine always calls the last function given as an argument to set_terminate.




Remarks
The code after the try clause is the guarded section of code. The throw expression throws—that is, raises—an exception. The code block after the catch clause is the exception handler. This is the handler that catches the exception that's thrown if the types in the throw and catch expressions are compatible. For a list of rules that govern type-matching in catch blocks, see How Catch Blocks are Evaluated. If the catch statement specifies an ellipsis (...) instead of a type, the catch block handles every type of exception. When you compile with the /EHa option, these can include C structured exceptions and system-generated or application-generated asynchronous exceptions such as memory protection, divide-by-zero, and floating-point violations. Because catch blocks are processed in program order to find a matching type, an ellipsis handler must be the last handler for the associated try block. Use catch(...) with caution; do not allow a program to continue unless the catch block knows how to handle the specific exception that is caught. Typically, a catch(...) block is used to log errors and perform special cleanup before program execution is stopped.

A throw expression that has no operand re-throws the exception currently being handled. We recommend this form when re-throwing the exception, because this preserves the original exception’s polymorphic type information. Such an expression should only be used in a catch handler or in a function that's called from a catch handler. The re-thrown exception object is the original exception object, not a copy.






How Catch Blocks are Evaluated (C++)
https://docs.microsoft.com/en-us/cpp/cpp/how-catch-blocks-are-evaluated-cpp?view=msvc-160

C++ enables you to throw exceptions of any type, although in general it is recommended to throw types that are derived from std::exception. A C++ exception can be caught by a catch handler that specifies the same type as the thrown exception, or by a handler that can catch any type of exception.

If the type of thrown exception is a class, which also has a base class (or classes), it can be caught by handlers that accept base classes of the exception's type, as well as references to bases of the exception's type. Note that when an exception is caught by a reference, it is bound to the actual thrown exception object; otherwise, it is a copy (much the same as an argument to a function).

When an exception is thrown, it may be caught by the following types of catch handlers:

    A handler that can accept any type (using the ellipsis syntax).

    A handler that accepts the same type as the exception object; because it is a copy, const and volatile modifiers are ignored.

    A handler that accepts a reference to the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of the same type as the exception object.

    A handler that accepts a base class of the same type as the exception object; since it is a copy, const and volatile modifiers are ignored. The catch handler for a base class must not precede the catch handler for the derived class.

    A handler that accepts a reference to a base class of the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of a base class of the same type as the exception object.

    A handler that accepts a pointer to which a thrown pointer object can be converted via standard pointer conversion rules.

The order in which catch handlers appear is significant, because handlers for a given try block are examined in order of their appearance. For example, it is an error to place the handler for a base class before the handler for a derived class. After a matching catch handler is found, subsequent handlers are not examined. As a result, an ellipsis catch handler must be the last handler for its try block.





Modern C++ best practices for exceptions and error handling
https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160

In modern C++, in most scenarios, the preferred way to report and handle both logic errors and runtime errors is to use exceptions. It's especially true when the stack might contain several function calls between the function that detects the error, and the function that has the context to handle the error. Exceptions provide a formal, well-defined way for code that detects errors to pass the information up the call stack.
Use exceptions for exceptional code

Program errors are often divided into two categories: Logic errors that are caused by programming mistakes, for example, an "index out of range" error. And, runtime errors that are beyond the control of programmer, for example, a "network service unavailable" error. In C-style programming and in COM, error reporting is managed either by returning a value that represents an error code or a status code for a particular function, or by setting a global variable that the caller may optionally retrieve after every function call to see whether errors were reported. For example, COM programming uses the HRESULT return value to communicate errors to the caller. And the Win32 API has the GetLastError function to retrieve the last error that was reported by the call stack. In both of these cases, it's up to the caller to recognize the code and respond to it appropriately. If the caller doesn't explicitly handle the error code, the program might crash without warning. Or, it might continue to execute using bad data and produce incorrect results.

Exceptions are preferred in modern C++ for the following reasons:

    An exception forces calling code to recognize an error condition and handle it. Unhandled exceptions stop program execution.

    An exception jumps to the point in the call stack that can handle the error. Intermediate functions can let the exception propagate. They don't have to coordinate with other layers.

    The exception stack-unwinding mechanism destroys all objects in scope after an exception is thrown, according to well-defined rules.

    An exception enables a clean separation between the code that detects the error and the code that handles the error.

The following simplified example shows the necessary syntax for throwing and catching exceptions in C++.
C++

#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
    //...
}

int main()
{
    try
    {
        MyFunc(256); //cause an exception to throw
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}

Exceptions in C++ resemble ones in languages such as C# and Java. In the try block, if an exception is thrown it will be caught by the first associated catch block whose type matches that of the exception. In other words, execution jumps from the throw statement to the catch statement. If no usable catch block is found, std::terminate is invoked and the program exits. In C++, any type may be thrown; however, we recommend that you throw a type that derives directly or indirectly from std::exception. In the previous example, the exception type, invalid_argument, is defined in the standard library in the <stdexcept> header file. C++ doesn't provide or require a finally block to make sure all resources are released if an exception is thrown. The resource acquisition is initialization (RAII) idiom, which uses smart pointers, provides the required functionality for resource cleanup. For more information, see How to: Design for exception safety. For information about the C++ stack-unwinding mechanism, see Exceptions and stack unwinding.
Basic guidelines

Robust error handling is challenging in any programming language. Although exceptions provide several features that support good error handling, they can't do all the work for you. To realize the benefits of the exception mechanism, keep exceptions in mind as you design your code.

    Use asserts to check for errors that should never occur. Use exceptions to check for errors that might occur, for example, errors in input validation on parameters of public functions. For more information, see the Exceptions versus assertions section.

    Use exceptions when the code that handles the error is separated from the code that detects the error by one or more intervening function calls. Consider whether to use error codes instead in performance-critical loops, when code that handles the error is tightly coupled to the code that detects it.

    For every function that might throw or propagate an exception, provide one of the three exception guarantees: the strong guarantee, the basic guarantee, or the nothrow (noexcept) guarantee. For more information, see How to: Design for exception safety.

    Throw exceptions by value, catch them by reference. Don’t catch what you can't handle.

    Don't use exception specifications, which are deprecated in C++11. For more information, see the Exception specifications and noexcept section.

    Use standard library exception types when they apply. Derive custom exception types from the exception Class hierarchy.

    Don't allow exceptions to escape from destructors or memory-deallocation functions.

Exceptions and performance

The exception mechanism has a minimal performance cost if no exception is thrown. If an exception is thrown, the cost of the stack traversal and unwinding is roughly comparable to the cost of a function call. Additional data structures are required to track the call stack after a try block is entered, and additional instructions are required to unwind the stack if an exception is thrown. However, in most scenarios, the cost in performance and memory footprint isn't significant. The adverse effect of exceptions on performance is likely to be significant only on memory-constrained systems. Or, in performance-critical loops, where an error is likely to occur regularly and there's tight coupling between the code to handle it and the code that reports it. In any case, it's impossible to know the actual cost of exceptions without profiling and measuring. Even in those rare cases when the cost is significant, you can weigh it against the increased correctness, easier maintainability, and other advantages that are provided by a well-designed exception policy.
Exceptions versus assertions

Exceptions and asserts are two distinct mechanisms for detecting run-time errors in a program. Use assert statements to test for conditions during development that should never be true if all your code is correct. There's no point in handling such an error by using an exception, because the error indicates that something in the code has to be fixed. It doesn't represent a condition that the program has to recover from at run time. An assert stops execution at the statement so that you can inspect the program state in the debugger. An exception continues execution from the first appropriate catch handler. Use exceptions to check error conditions that might occur at run time even if your code is correct, for example, "file not found" or "out of memory." Exceptions can handle these conditions, even if the recovery just outputs a message to a log and ends the program. Always check arguments to public functions by using exceptions. Even if your function is error-free, you might not have complete control over arguments that a user might pass to it.
C++ exceptions versus Windows SEH exceptions

Both C and C++ programs can use the structured exception handling (SEH) mechanism in the Windows operating system. The concepts in SEH resemble the ones in C++ exceptions, except that SEH uses the __try, __except, and __finally constructs instead of try and catch. In the Microsoft C++ compiler (MSVC), C++ exceptions are implemented for SEH. However, when you write C++ code, use the C++ exception syntax.

For more information about SEH, see Structured Exception Handling (C/C++).
Exception specifications and noexcept

Exception specifications were introduced in C++ as a way to specify the exceptions that a function might throw. However, exception specifications proved problematic in practice, and are deprecated in the C++11 draft standard. We recommend that you don't use throw exception specifications except for throw(), which indicates that the function allows no exceptions to escape. If you must use exception specifications of the deprecated form throw( type-name ), MSVC support is limited. For more information, see Exception Specifications (throw). The noexcept specifier is introduced in C++11 as the preferred alternative to throw().

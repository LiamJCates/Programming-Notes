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

    When declaring a function, exception specifications and noexcept specifiers may be provided to limit the types of the exceptions a function may throw.

    Don't use exception specifications, which are deprecated in C++11. For more information, see the Exception specifications and noexcept section.

    Use standard library exception types when they apply. Derive custom exception types from the exception Class hierarchy.

    Don't allow exceptions to escape from destructors or memory-deallocation functions.








Special handlers are typically used as a safety mechanism to log the program’s catastrophic failure to catch an exception of a specific type. You can handle different types of exceptions originating from the same try block by chaining together catch statements, as demonstrated here:

  try
  {
    // Code that might throw various exceptions
  }
  catch (const std::logic_error& ex)
  {
    // Log exception and terminate the program; there is a programming error!
  }
  catch (const std::runtime_error& ex)
  {
    // Do our best to recover gracefully
  }
  catch (const std::exception& ex)
  {
    // This will handle any exception that derives from std:exception
    // that is not a logic_error or a runtime_error.
    --snip--
  }
  catch (...)
  {
    // Panic; an unforeseen exception type was thrown
  }

It’s common to see such code in a program’s entry point.











There are some unusual but important cases where you might want to further inspect an exception before deciding to handle it, as shown:

  try
  {
    // Some code that might throw a system_error
    --snip--
  }
  catch(const std::system_error& ex)
  {
    if(ex.code()!= std::errc::permission_denied){
    // Not a permission denied error
    throw;
  }
  // Recover from a permission denied
  --snip--
  }

In this example, some code that might throw a system_error is wrapped in a try-catch block. All system_errors are handled, but unless it’s an EACCES (permission denied) error, you rethrow the exception. There are some performance penalties to this approach, and the resulting code is often needlessly convoluted.

Rather than rethrowing, you can define a new exception type and create
a separate catch handler for the EACCES error, as demonstrated:

  try
  {
    // Throw a PermissionDenied instead
    --snip--
  }
  catch(const PermissionDenied& ex)
  {
    // Recover from an EACCES error (Permission Denied
    --snip--
  }

If a std::system_error is thrown, the PermissionDenied handler won’t
catch it. (Of course, you could still keep the std::system_error handler to catch such exceptions if you wish.)

















Exceptions and performance

The exception mechanism has a minimal performance cost if no exception is thrown. If an exception is thrown, the cost of the stack traversal and unwinding is roughly comparable to the cost of a function call. Additional data structures are required to track the call stack after a try block is entered, and additional instructions are required to unwind the stack if an exception is thrown. However, in most scenarios, the cost in performance and memory footprint isn't significant. The adverse effect of exceptions on performance is likely to be significant only on memory-constrained systems. Or, in performance-critical loops, where an error is likely to occur regularly and there's tight coupling between the code to handle it and the code that reports it. In any case, it's impossible to know the actual cost of exceptions without profiling and measuring. Even in those rare cases when the cost is significant, you can weigh it against the increased correctness, easier maintainability, and other advantages that are provided by a well-designed exception policy.
Exceptions versus assertions

Exceptions and asserts are two distinct mechanisms for detecting run-time errors in a program. Use assert statements to test for conditions during development that should never be true if all your code is correct. There's no point in handling such an error by using an exception, because the error indicates that something in the code has to be fixed. It doesn't represent a condition that the program has to recover from at run time. An assert stops execution at the statement so that you can inspect the program state in the debugger. An exception continues execution from the first appropriate catch handler. Use exceptions to check error conditions that might occur at run time even if your code is correct, for example, "file not found" or "out of memory." Exceptions can handle these conditions, even if the recovery just outputs a message to a log and ends the program. Always check arguments to public functions by using exceptions. Even if your function is error-free, you might not have complete control over arguments that a user might pass to it.
C++ exceptions versus Windows SEH exceptions

Both C and C++ programs can use the structured exception handling (SEH) mechanism in the Windows operating system. The concepts in SEH resemble the ones in C++ exceptions, except that SEH uses the __try, __except, and __finally constructs instead of try and catch. In the Microsoft C++ compiler (MSVC), C++ exceptions are implemented for SEH. However, when you write C++ code, use the C++ exception syntax.

For more information about SEH, see Structured Exception Handling (C/C++).
Exception specifications and noexcept

Exception specifications were introduced in C++ as a way to specify the exceptions that a function might throw. However, exception specifications proved problematic in practice, and are deprecated in the C++11 draft standard. We recommend that you don't use throw exception specifications except for throw(), which indicates that the function allows no exceptions to escape. If you must use exception specifications of the deprecated form throw( type-name ), MSVC support is limited. For more information, see Exception Specifications (throw). The noexcept specifier is introduced in C++11 as the preferred alternative to throw().











Exception dangers and downsides
By Alex on October 26th, 2008 | last modified by Alex on December 21st, 2020

As with almost everything that has benefits, there are some potential downsides to exceptions as well. This article is not meant to be comprehensive, but just to point out some of the major issues that should be considered when using exceptions (or deciding whether to use them).

Cleaning up resources

One of the biggest problems that new programmers run into when using exceptions is the issue of cleaning up resources when an exception occurs. Consider the following example:

1
2
3
4
5
6
7
8
9
10

try
{
    openFile(filename);
    writeFile(filename, data);
    closeFile(filename);
}
catch (const FileException &exception)
{
    std::cerr << "Failed to write to file: " << exception.what() << '\n';
}

What happens if WriteFile() fails and throws a FileException? At this point, we’ve already opened the file, and now control flow jumps to the FileException handler, which prints an error and exits. Note that the file was never closed! This example should be rewritten as follows:

1
2
3
4
5
6
7
8
9
10
11
12
13

try
{
    openFile(filename);
    writeFile(filename, data);
    closeFile(filename);
}
catch (const FileException &exception)
{
    // Make sure file is closed
    closeFile(filename);
    // Then write error
    std::cerr << "Failed to write to file: " << exception.what() << '\n';
}

This kind of error often crops up in another form when dealing with dynamically allocated memory:

1
2
3
4
5
6
7
8
9
10

try
{
    auto *john { new Person{ "John", 18, PERSON_MALE } };
    processPerson(john);
    delete john;
}
catch (const PersonException &exception)
{
    std::cerr << "Failed to process person: " << exception.what() << '\n';
}

If processPerson() throws an exception, control flow jumps to the catch handler. As a result, john is never deallocated! This example is a little more tricky than the previous one -- because john is local to the try block, it goes out of scope when the try block exits. That means the exception handler can not access john at all (its been destroyed already), so there’s no way for it to deallocate the memory.

However, there are two relatively easy ways to fix this. First, declare john outside of the try block so it does not go out of scope when the try block exits:

1
2
3
4
5
6
7
8
9
10
11
12

Person *john{ nullptr };
try
{
    john = new Person("John", 18, PERSON_MALE);
    processPerson(john);
    delete john;
}
catch (const PersonException &exception)
{
    delete john;
    std::cerr << "Failed to process person: " << exception.what() << '\n';
}

Because john is declared outside the try block, it is accessible both within the try block and the catch handlers. This means the catch handler can do cleanup properly.

The second way is to use a local variable of a class that knows how to cleanup itself when it goes out of scope (often called a “smart pointer”). The standard library provides a class called std::unique_ptr that can be used for this purpose. std::unique_ptr is a template class that holds a pointer, and deallocates it when it goes out of scope.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

#include <memory> // for std::unique_ptr

try
{
    auto *john { new Person("John", 18, PERSON_MALE) };
    std::unique_ptr<Person> upJohn { john }; // upJohn now owns john

    ProcessPerson(john);

    // when upJohn goes out of scope, it will delete john
}
catch (const PersonException &exception)
{
    std::cerr << "Failed to process person: " << exception.what() << '\n';
}

We’ll talk more about smart pointers in the next chapter.

Exceptions and destructors

Unlike constructors, where throwing exceptions can be a useful way to indicate that object creation did not succeed, exceptions should never be thrown in destructors.

The problem occurs when an exception is thrown from a destructor during the stack unwinding process. If that happens, the compiler is put in a situation where it doesn’t know whether to continue the stack unwinding process or handle the new exception. The end result is that your program will be terminated immediately.

Consequently, the best course of action is just to abstain from using exceptions in destructors altogether. Write a message to a log file instead.

Performance concerns

Exceptions do come with a small performance price to pay. They increase the size of your executable, and they may also cause it to run slower due to the additional checking that has to be performed. However, the main performance penalty for exceptions happens when an exception is actually thrown. In this case, the stack must be unwound and an appropriate exception handler found, which is a relatively expensive operation.

As a note, some modern computer architectures support an exception model called zero-cost exceptions. Zero-cost exceptions, if supported, have no additional runtime cost in the non-error case (which is the case we most care about performance). However, they incur an even larger penalty in the case where an exception is found.

So when should I use exceptions?

Exception handling is best used when all of the following are true:

    The error being handled is likely to occur only infrequently.
    The error is serious and execution could not continue otherwise.
    The error cannot be handled at the place where it occurs.
    There isn’t a good alternative way to return an error code back to the caller.

As an example, let’s consider the case where you’ve written a function that expects the user to pass in the name of a file on disk. Your function will open this file, read some data, close the file, and pass back some result to the caller. Now, let’s say the user passes in the name of a file that doesn’t exist, or a null string. Is this a good candidate for an exception?

In this case, the first two bullets above are trivially met -- this isn’t something that’s going to happen often, and your function can’t calculate a result when it doesn’t have any data to work with. The function can’t handle the error either -- it’s not the job of the function to re-prompt the user for a new filename, and that might not even be appropriate, depending on how your program is designed. The fourth bullet is the key -- is there a good alternative way to return an error code back to the caller? It depends on the details of your program. If so (e.g. you can return a null pointer, or a status code to indicate failure), that’s probably the better choice. If not, then an exception would be reasonable.

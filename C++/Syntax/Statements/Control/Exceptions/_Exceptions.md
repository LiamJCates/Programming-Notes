# Exception handling

The handling of an exception breaks the normal flow of execution by either executing a pre-registered exception handler or terminating the program.

Exceptions are types that communicate an error condition; anomalous or exceptional conditions that require special processing.

Handlers are special functions that resolve exceptional conditions experienced during program execution.

Exception handling is the process of responding to exceptional circumstances (like runtime errors) in programs by transferring control and information from some point in the execution of a program to a point previously passed by the execution where a handler function has been specified to resolve the circumstance.

General Steps
  An error condition occurs
  A corresponding exception is thrown
  The program stops normal execution
  The runtime seeks the closest exception handler to catch a thrown exception.
  Appropriate handler is found or the program terminates.


To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion of code in a try-block. When an exceptional circumstance arises within that block, an exception is thrown that transfers the control to the exception handler. If no exception is thrown, the code continues normally and all handlers are ignored.



### Syntax
C++ exception handling is built upon three keywords which specify try, catch, and throw expressions:

  throw − The throw keyword throws an exception when a problem occurs.
  try − The try keyword identifies a code block where exceptions might occur
  catch − The catch keyword indicates an exception handler.



#### Throw
In C++, a throw statement is used to signal that an exception or error case has occurred (think of throwing a penalty flag). Signaling that an exception has occurred is also commonly called raising an exception.

To use a throw statement, simply use the throw keyword, followed by an expression of any data type you wish to use to signal that an error has occurred.

  throw expression;

A throw expression accepts one parameter which is passed as an argument to the exception handler.

For more information specific to throwing exceptions, see:
[C++\Syntax\Statements\Control\Exceptions\Throw.md]



#### Try
In C++, we use the try keyword to define a block of statements that is under inspection (called a try block). The try block acts as an observer, looking for any exceptions that are thrown by any of the statements within the try block:

  try
  {
    // Statements that may throw exceptions you want to handle go here
  }



#### Catch
The catch keyword is used to define a block of code (called a catch block) that handles exceptions of a given data type. To handle exceptions that may be thrown, implement one or more catch blocks immediately following the closing brace of a try block. Each catch block specifies the type of exception it can handle. The syntax for catch is similar to a regular function with one parameter:

  catch( ExceptionName e1 )
  {
     // catch block
  }

Here’s an example of a catch block that will catch integer exceptions:

  catch (int x)
  {
    // Handle an exception of type int here
    std::cerr << "We caught an int exception with value" << x << '\n';
  }

For more information specific to catching exceptions, see:
[C++\Syntax\Statements\Control\Exceptions\Catch.md]



#### Handling Exceptions
Throw, try and catch work together to handle exceptions. A try block is placed around the code that might throw an exception and a catch block immediately follows it. Code within a try/catch block is referred to as protected or guarded code.

The syntax for using try/catch as follows:

  #include <iostream>

  int main () {
    try
    {
      throw 20;
    }
    catch (int e)
    {
      std::cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
  }

A try block must have at least one catch block immediately following it, but may have multiple catch blocks listed in sequence. Multiple handlers (i.e., catch expressions) can be chained:

  try {
     // protected code
     throw expression;
  }
  catch( ExceptionName e1 )
  {
     // catch block
  }
  catch( ExceptionName e2 )
  {
     // catch block
  }
  catch( ExceptionName eN )
  {
     // catch block
  }

When try block detects any exceptions that are thrown by statements within the try block it routes them to the first appropriate catch block for handling.



### Control Flow
Once an exception is thrown, no further statements in the try block execute and the exception is "in flight".

While an exception is in flight, the program searches the statements in catch blocks in the order they appear after the try block to look for an appropriate exception handler. The search will travel up the call stack in search of an appropriately parameterized handler, known as call stack "unwinding".

For more information about unwinding the call stack see:
[C++\Syntax\Statements\Control\Exceptions\Unwinding.md]

An exception in flight is routed to the first catch block for which the type of thrown exception matches the parameter type specified by the catch block. The exception in flight is then considered "caught".

The code of that catch block executes and any remaining catch blocks after this catch block are ignored. The exception is then considered "handled".

After an exception has been handled, program execution resumes after the try-catch block, not after the throw statement.

If no catch block of a correctly parameterized type is found the program will terminate.

A terminate handler function is a function automatically called when the exception handling process has to be abandoned for some reason. This happens when no catch handler can be found for a thrown exception.

If a matching handler cannot be found for the current exception, the predefined terminate run-time function is called.

For more information regarding program termination, see:
[C++\Syntax\Statements\Control\Halt\_Halt.md]



### Exceptions and Performance

In your programs, you must handle errors; errors are unavoidable.

When you use exceptions correctly and no errors occur, your code is faster than manually error-checked code.

If an error does occur, exception handling can sometimes be slower, but you make huge gains in robustness and maintainability over the alternative.

Kurt Guntheroth, the author of Optimized C++, puts it well:

  “use of exception handling leads to programs that are faster when they execute normally, and better behaved when they fail.”

When a C++ program executes normally (without exceptions being thrown), there is no runtime overhead associated with checking exceptions. It’s only when an exception is thrown that you pay overhead.

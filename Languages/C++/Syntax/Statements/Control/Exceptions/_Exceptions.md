# Exception handling

The handling of an exception breaks the normal flow of execution by either executing a pre-registered exception handler or terminating the program.

Exceptions are types that communicate an error condition; error conditions are anomalous or exceptional conditions that require special processing.

Handlers are special functions that resolve exceptional conditions experienced during program execution.

Exception handling is the process of responding to exceptional circumstances (like runtime errors) in programs by transferring control and information from some point in the execution of a program to a point previously passed by the execution where a handler function has been specified to resolve the circumstance.

General Steps Throws
  An error condition occurs
  A corresponding exception is thrown
  The program stops normal execution
  The runtime seeks the closest exception handler to catch a thrown exception.
  Appropriate handler is found or the program terminates.


To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion of code in a try-block.

When an exceptional circumstance arises within that block, an exception is thrown that transfers the control to the exception handler. If no exception is thrown, the code continues normally and all handlers are ignored.



### Syntax
C++ exception handling is built upon three keywords which specify particular kinds of expressions, try, catch, and throw:

  throw − The throw keyword throws an exception of a given type.
  try − The try keyword identifies a code block the is under inspection, and indicates where exceptions occur
  catch − The catch keyword defines an exception handler, which catches a particular type of thrown exception.



#### Throw
In C++, a throw statement is used to signal that an exception or error case has occurred (think of throwing a penalty flag). Signaling that an exception has occurred is also commonly called "raising" an exception.

To use a throw statement, the throw keyword is followed by an expression that resolves to any data type you wish to use to signal that an error has occurred.

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
The catch keyword is used to define a block of code (called a catch block) that handles exceptions of a given data type. To handle exceptions that may be thrown, implement one or more catch blocks immediately following the closing brace of a try block. The syntax for catch is similar to a regular function with one parameter. Each catch block specifies the type of exception it can handle like a function would specify a parameter, and the statements that resolve the exception:

  catch( ExceptionType e1 )
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
Throw, try and catch work together to handle exceptions. In the most basic configuration, a try block is placed around code that might throw an exception and a catch block immediately follows it:

The syntax for using try/catch as follows:

```cpp
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
```

A try block must have at least one catch block immediately following it, but may have multiple catch blocks listed in sequence. Multiple handlers (i.e., catch expressions) can be chained:

  try {
     // protected code
     throw expression;
  }
  catch( ExceptionType e1 )
  {
     // catch block
  }
  catch( ExceptionType e2 )
  {
     // catch block
  }
  catch( ExceptionType eN )
  {
     // catch block
  }

When try block detects any exceptions that are thrown by statements within the try block it routes them to the first appropriate catch block for handling.



### Control Flow
The path of execution experienced during the handling of a exceptions activates a control flow that is a brief diversion from that of the intended control flow.

There is some vocabulary that assists us in speaking about the actions that occur during exception handling.

There are many things in programs that might cause an exception to occur. It is our job as programmers to identify a code section where an error might occur and surround that code section in a try block. Code within a try block is referred to as protected or "guarded" code.

From within a section of gaurded code, the job of the programmer then becomes one of analyzing values to determine when a anomalous value occurs so that the control flow can guide the execution of a program to a throw statement.

As mentioned above, a throw statement is followed by a corresponding expression of a type we determine to be related to the error. Once the throw statement is executed, the throw statement is said to have "thrown" an exception of the type that matched its corresponding expression type.

Once an exception is thrown, no further statements in the try block execute and the exception is said to be "in flight".

While an exception is in flight, the program begins seraching for an appropriate catch block. An appropriate catch block is one that has been  parameterized with a type that matches the type of the thrown exception.

The catch blocks are searched in the order they appear after the try block to look for an appropriate parameterized exception handler.

If no appropriate catch block is found immediately after the try block the exception was thrown from, the search will travel up the call stack in search of an appropriately parameterized handler, known as call stack "unwinding".

For more information about the process of unwinding the call stack see:
[C++\Syntax\Statements\Control\Exceptions\Unwinding.md]

An exception in flight is routed to the first catch block for which the type of thrown exception matches the parameter type specified by the catch block. Once it has been routed to such a catch block, the exception in flight is then considered "caught".

Once the catch block that catches a given exception executes, all other catch blocks related to the try block are ignored. Once the catch block has executed the exception is then considered "handled".

After an exception has been handled, program execution resumes after the try-catch block, not after the throw statement.

If no catch block of a correctly parameterized type is found the program will "terminate".

During program terminiatino, a terminate handler function is acis a function automatically called when the exception handling process has to be abandoned for some reason. This happens when no catch handler can be found for a thrown exception.

If a matching handler cannot be found for the current exception, the predefined terminate run-time function is called.

For more information regarding program termination, see:
[C++\Syntax\Statements\Control\Halt\_Halt.md]



### Exceptions and Performance

In your programs, you must handle errors, in a program of sufficient complexity, errors are unavoidable.

When you use exceptions correctly and no errors occur, your code is faster than manually error-checked code.

If an error does occur, exception handling can sometimes be slower, but you make huge gains in robustness and maintainability over the alternative.

Kurt Guntheroth, the author of Optimized C++, puts it well:

  “use of exception handling leads to programs that are faster when they execute normally, and better behaved when they fail.”

When a C++ program executes normally (without exceptions being thrown), there is no runtime overhead associated with checking exceptions. It’s only when an exception is thrown that you pay overhead.

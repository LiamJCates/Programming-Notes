Exception handling
Exceptions are types that communicate an error condition. Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called handlers.

Exception handling is thus the process of responding to the occurrence of exceptions – anomalous or exceptional conditions requiring special processing - during the execution of a program. In general, an exception breaks the normal flow of execution and executes a pre-registered exception handler.

Exception handling provides a way of transferring control and information from some point in the execution of a program to a handler associated with a point previously passed by the execution, known as transferring control up the call stack.

To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion of code in a try-block. When an exceptional circumstance arises within that block, an exception is thrown that transfers the control to the exception handler. If no exception is thrown, the code continues normally and all handlers are ignored.


General Steps
  An error condition occurs
  A corresponding exception is thrown
  The program stops normal execution
  The runtime seeks the closest exception handler to catch a thrown exception.
  Appropriate handler is found or the program terminates.



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


#### Try
In C++, we use the try keyword to define a block of statements (called a try block). The try block acts as an observer, looking for any exceptions that are thrown by any of the statements within the try block:

  try
  {
    // Statements that may throw exceptions you want to handle go here
  }



#### Catch
The catch keyword is used to define a block of code (called a catch block) that handles exceptions for a single data type. To handle exceptions that may be thrown, implement one or more catch blocks immediately following the closing brace of a try block. Each catch block specifies the type of exception it can handle. The syntax for catch is similar to a regular function with one parameter:

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



#### try/catch block
Try blocks and catch blocks work together, a try block is placed around the code that might generate an exception and a catch block immediately follows it. Code within a try/catch block is referred to as protected or guarded code. The syntax for using try/catch as follows:

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



### Handling Exceptions
Once an exception is thrown, no further statements in the try block execute and the exception is "in flight".

While an exception is in flight, the program searches the statements in catch blocks in the order they appear after the try block to look for an appropriate exception handler.

An exception in flight is "caught" and routed to the first catch block parameterized for handling it. The routing will travel up the call stack called "unwinding" the call stack in search of an appropriately parameterized handler.

For more information about unwinding the call stack see:
[C++\Syntax\Statements\Control\Exceptions\Unwinding.md]

If the type of thrown exception matches the parameter type in one of the catch blocks, the code of that catch block executes, and the remaining catch blocks after this catch block are ignored. The exception is then considered "handled". After an exception has been handled, program execution resumes after the try-catch block, not after the throw statement.

If no catch block of a correctly parameterized type is found the program will terminate.

For more information about program termination via unhandled exception see:
[C++\Syntax\Statements\Control\Exceptions\Unhandled.md]



### Throwing Exceptions
To throw an exception, use the throw keyword followed by a throwable object.

Typically, this value will be an error code, a description of the problem, or a custom exception class:

  throw -1; // literal integer value
  throw ENUM_INVALID_INDEX; // enum value
  throw "Can't take square root of negative number"; // literal C-style (const char*) string
  throw dX; // previously defined double variable
  throw MyException("Fatal Error"); // MyException class object

Each of these statements acts as a signal that some kind of problem that needs to be handled has occurred. Typically, this object is used to communicate information about the error.

Most objects are throwable. But it’s good practice to use one of the
exceptions available in stdlib. In most cases, it is recommended that you use the std::exception class or one of the derived classes that are defined in the standard library. If one of those is not appropriate, it is recommended that you derive your own exception class from std::exception.

For more information about deriving exceptions see:
[C++\Syntax\Statements\Control\Exceptions\CustomExceptions.md]

Exceptions can be thrown anywhere within a code block using throw statement. The operand of the throw statement determines a type for the exception and can be any expression and the type of the result of the expression determines the type of exception thrown.

The following throws an exception for a divide by zero condition:

  double division(int a, int b)
  {
     if( b == 0 ) {
        throw "Division by zero condition!";
     }
     return (a/b);
  }

An exception can be thrown by a throw-expression, dynamic_cast, typeid, new-expression, allocation function, and any of the standard library functions that are specified to throw exceptions to signal certain error conditions (e.g. std::vector::at, std::string::substr, etc).



### Catching Exceptions
In order for an exception to be "caught" by an exception handler, the throw-expression has to be inside the scope of a try-block.

A catch block following a try block catches a specified exception type.

The types of exception a given catch block handles is determined by the exception declaration that appears in parentheses following the keyword catch.

A distinct catch block must be used to specify a handler for each exception type you choose to handle.

If the type of thrown exception is a class, which also has a base class (or classes), it can be caught by handlers that accept base classes of the exception's type, as well as references to bases of the exception's type.

  try
  {
     // protected code
  }
  catch( ExceptionName e )
  {
    // code to handle ExceptionName exception
  }

For more information about the selection of a catch block see:
[C++\Syntax\Statements\Control\Exceptions\CatchSelection.md]



#### Catch Parameters
A catch clause has exactly one parameter

Catch parameters work just like function parameters, with the parameter being available within the subsequent catch block. Exceptions of fundamental types can be caught by value, but exceptions of non-fundamental types should be caught by const reference to avoid making an unnecessary copy.

Note that when an exception is caught by a reference, it is bound to the actual thrown exception object; otherwise, it is a copy (much the same as an argument to a function).

Just like with functions, if the parameter is not going to be used in the catch block, the variable name can be omitted:

  catch (double) //no variable name as it's unused in the catch block below
  {
    // Handle exception of type double here
    std::cerr << "We caught an exception of type double" << '\n';
  }

To throw an exception that includes more than one variable with or without the same type you might throw like this:

 throw std::make_pair(3, std::string("hello"));

and catch like this:

  catch(std::pair<int, std::string>& exc)
  {
    // Handle exception of type here
  }



#### ... Handler

If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception declaration.

The following special handler catches any exception regardless of its type:

  try
  {
     // protected code
  }
  catch(...)
  {
    // code to handle any exception
  }

Because catch blocks are processed in sequential program order to find a matching type, an ellipsis handler must be the last handler for the associated try block. This can be used as a default handler that catches all exceptions not caught by other handlers:

  try {
    // code here
  }
  catch (int param) { cout << "int exception"; }
  catch (char param) { cout << "char exception"; }
  catch (...) { cout << "default exception"; }

In this case, the last handler would catch any exception thrown of a type that is neither int nor char.

Use catch(...) with caution; do not allow a program to continue unless the catch block knows how to handle the specific exception that is caught. Typically, a catch(...) block is used to log errors and perform special cleanup before program execution is stopped.



#### Rethrowing An Exception
In a catch block, you can use the throw keyword to resume searching for an appropriate exception handler. This is called rethrowing an exception.

A throw expression that has no operand re-throws the exception currently being handled:

  throw;

This form is recommend when re-throwing the exception, because this preserves the original exception’s polymorphic type information. Such an expression should only be used in a catch handler or in a function that's called from a catch handler. The re-thrown exception object is the original exception object, not a copy.



#### nested try-catch

It is also possible to nest try-catch blocks within more external try blocks. In these cases, we have the possibility that an internal catch block forwards the exception to its external level. This is done with the expression throw; with no arguments. For example:

  try {
    try {
        // code here
    }
    catch (int n) {
        throw;
    }
  }
  catch (...) {
    cout << "Exception occurred";
  }




### Exception specification
Older code may contain dynamic exception specifications. They are now deprecated in C++, but still supported. A dynamic exception specification follows the declaration of a function, appending a throw specifier to it:

  double myfunction (char param) throw (int);

This declares a function called myfunction, which takes one argument of type char and returns a value of type double. If this function throws an exception of some type other than int, the function calls std::unexpected instead of looking for a handler or calling std::terminate.

If this throw specifier is left empty with no type, this means that std::unexpected is called for any exception. Functions with no throw specifier (regular functions) never call std::unexpected, but follow the normal path of looking for their exception handler.

int myfunction (int param) throw(); // all exceptions call unexpected
int myfunction (int param);         // normal exception handling

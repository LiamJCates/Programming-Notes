
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

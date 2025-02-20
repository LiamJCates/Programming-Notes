### Catching Exceptions
In order for an exception to be "caught" by a given exception handler, a throw-expression of a type that matches the parameter of the exception handler sepcified by a catch block has to be executed inside the scope of a try-block for which the catch block is associated.

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

If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must specify an ellipsis, ..., as the parameter of the exception handling declaration.

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



### Catch Selection

When an exception is thrown, it may be caught by the following types of catch handlers:

    A handler that can accept any type (using the ellipsis syntax, ...).

    A handler that accepts the same type as the exception object; because it is a copy, const and volatile modifiers are ignored.

    A handler that accepts a reference to the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of the same type as the exception object.

    A handler that accepts a base class of the same type as the exception object; since it is a copy, const and volatile modifiers are ignored. The catch handler for a base class must not precede the catch handler for the derived class.

    A handler that accepts a reference to a base class of the same type as the exception object.

    A handler that accepts a reference to a const or volatile form of a base class of the same type as the exception object.

    A handler that accepts a pointer to which a thrown pointer object can be converted via standard pointer conversion rules.

The order in which catch handlers appear is significant, because handlers for a given try block are examined in order of their appearance. For example, it is an error to place the handler for a base class before the handler for a derived class. After a matching catch handler is found, subsequent handlers are not examined. As a result, an ellipsis catch handler must be the last handler for its try block.

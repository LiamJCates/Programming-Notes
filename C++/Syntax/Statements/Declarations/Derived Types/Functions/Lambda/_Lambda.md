## Lambda Functions

A lambda expression (also called a lambda or closure) allows us to define an unnamed or anonymous function objects within another function.

Lambdas don’t provide any additional functionality to declaring function types the old-fashioned way. But they’re extremely convenient when you need to initialize a function object in only a single context. The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as close to where it is used as possible (providing additional context).

lambda syntax:

  [ captures ] ( parameters ) modifiers -> returnType
  {
      //body statements
  }

There are five components to a lambda expression:
•	 captures: The member variables of the function object
•	 parameters: The arguments required to invoke the function object
•	 body: The function object’s code
•	 modifiers: Elements like constexpr, mutable, noexcept, and [[noreturn]]
•	 return type: The type returned by the function object

The capture clause and parameters can both be empty if they are not needed.

The return type is optional, and if omitted, auto will be assumed (thus using type inference to determine the return type). While type inference for function return types is avoided, in this context, it’s fine to use (because lambdas are typically trivial functions).

Also note that lambdas have no name, so we don’t need to provide one.

Only the captures and the body are required; everything else is optional.

This means a trivial lambda definition looks like this:

  int main()
  {
    []{}; // defines a lambda with no captures, no parameters, and no return type
  }


Lambda Topics:
  Parameters
  Captures
  Returns
  As Variables
  Analogues
  Types
  Generic

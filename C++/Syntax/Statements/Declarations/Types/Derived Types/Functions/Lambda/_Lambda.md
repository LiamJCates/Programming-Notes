## Lambda Functions
Lambda expressions were introduced in C++11 and help in the usage of STL algorithms to sort or process data.

An example of usage is a sort function. Typically, a sort function requires you to supply a binary predicate. This is a function that compares two arguments and returns true if one is less than the other, else false, thereby helping in deciding the order of elements in a sort operation.

Such predicates are typically implemented as operators in a class, leading to a tedious bit of coding.

One problem with calling algorithms is that sometimes the predicate or transformation function must be declared far from the place where it is called. With a properly descriptive name, this problem can be reduced, but often the function is trivial, and your program would be much easier to read if you could put its functionality directly in the call to the standard algorithm. A feature introduced in C++ 11 and expanded in subsequent standards permits exactly that.

Lambda expressions can compact definitions like those mentioned above.

A lambda expression (also called a lambda or closure) allows us to define an unnamed or anonymous function objects within another function.

lambdas allow us to define a function as an expression. You can pass this function to an algorithm, save it in a variable, or call it immediately.

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

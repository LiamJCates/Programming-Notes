### Default
In C++, functions can have optional parameters, for which given arguments are not required in a call. Default arguments are used in such a way that, for example, a function with two parameters may be called with only one or none.

Default argument declaration uses the "=" operator to define a default value for a parameter. Default arguments are assigned a value when declared in the function signature:

  double Area(double radius, double pi = 3.14);

The function Area() can then be invoked without a second parameter:

  Area(radius);

In this case, the second parameter defaults to the value of 3.14. However, when required, the same function can be invoked using two arguments:

  Area(radius, 3.14159); // more precise pi

You can have multiple parameters with default values; however, these should all be at the tail end of the parameter list.

Default arguments can only be declared once

Once declared, a default argument can not be redeclared. That means for a function with a forward declaration and a function definition, the default argument can be declared in either the forward declaration or the function definition, but not both.

  void printValues(int x, int y=10);

  void printValues(int x, int y=10) // error: redefinition of default argument
  {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
  }

Best practice is to declare the default argument in the forward declaration and not in the function definition, as the forward declaration is more likely to be seen by other files (particularly if it’s in a header file).



### Default arguments and function overloading

Functions with default arguments may be overloaded. For example, the following is allowed:

  void print(std::string string);
  void print(char ch=' ');

If the user were to call print(), it would resolve to print(' '), which would print a space.

However, it is important to note that optional parameters do NOT count towards the parameters that make the function unique. Consequently, the following is not allowed:

  void printValues(int x);
  void printValues(int x, int y=20);

If the caller were to call printValues(10), the compiler would not be able to disambiguate whether the user wanted printValues(int) or printValues(int, 20) with the default value.

As the compiler cannot resolve an ambiguous function overload a compiler error results.

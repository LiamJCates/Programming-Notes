## Passing by Reference

In certain cases it is useful to program a function such that its parameters are not created and destroyed within the function call, using references that are valid before the function call and remain so after the function has exited.

To access an external variable from within a function, arguments can be passed by reference, instead of by value.

When a variable is passed by reference, what is passed is no longer a copy. The variable identified by the function parameter becomes associated with the argument passed to the function, and any modification on their corresponding local variables within the function are reflected in the variables passed as arguments in the call. The parameter name become an alias of the argument passed on the function call.

In C++, references are indicated with an ampersand (&) following the parameter type:

	typename& parameter-name

A form of the function Area() that computes and returns the area as a parameter by reference looks like this:

  // output parameter result by reference
  void Area(double radius, double& result)
  {
  	result = Pi * radius * radius;
  }

Don’t miss the ampersand (&) next to the second parameter result. This sign indicates to the compiler that the second argument should NOT be copied to the function; instead, it is a reference to the variable being passed. The return type has been changed to void as the function no longer supplies the area computed as a return value, rather as an output parameter by reference.

A function can return only one value using the return statement. So, if your function needs to perform operations that affect many values required at the caller, passing arguments by reference is one way to get a function to supply those many modifications back to the calling module.



### const

Functions with reference parameters are generally perceived as functions that modify the arguments passed. If we want to pass by reference for performance reasons but don’t need to modify the argument, we pass-by-const-reference, declaring the reference parameter with the const type qualifier.

A const reference is a reference that does not allow the variable being referenced to be changed through the reference. Consequently, if we use a const reference as a parameter, we guarantee to the caller that the function will not change the argument!

Therefore, const references provide functionality similar to passing arguments by value, but with an increased efficiency for parameters of large types. That is why they are extremely popular in C++ for arguments of compound types. For most fundamental types, there is no noticeable difference in efficiency, and in some cases, const references may even be less efficient!

NOTE
You can’t pass a const argument to a non-const reference parameter.
Non-const references cannot bind to r-values. A function with a non-const reference parameter cannot be called with literal or temporary argument value.
Non-const references can only reference non-const l-values (e.g. non-const variables), so a reference parameter cannot accept an argument that is a const l-value.
Using const parameters ensures you can pass both non-const and const arguments to the function as const references can accept any type of argument, including non-const l-values, const l-values, and r-values.



### Pros and cons of pass by reference

Advantages of passing by reference:

    References allow a function to change the value of the argument, which is sometimes useful. Otherwise, const references can be used to guarantee the function won’t change the argument.
    Because a copy of the argument is not made, pass by reference is fast, even when used with large structs or classes.
    References can be used to return multiple values from a function (via out parameters).
    References must be initialized, so there’s no worry about null values.

Disadvantages of passing by reference:

    Because a non-const reference cannot be initialized with a const l-value or an r-value (e.g. a literal or an expression), arguments to non-const reference parameters must be normal variables.
    It can be hard to tell whether an argument passed by non-const reference is meant to be input, output, or both. Judicious use of const and a naming suffix for out variables can help.
    It’s impossible to tell from the function call whether the argument may change. An argument passed by value and passed by reference looks the same. We can only tell whether an argument is passed by value or reference by looking at the function declaration. This can lead to situations where the programmer does not realize a function will change the value of the argument.

When to use pass by reference:

    When passing structs or classes (use const if read-only).
    When you need the function to modify an argument.
    When you need access to the type information of a fixed array.

When not to use pass by reference:

    When passing fundamental types that don’t need to be modified (use pass by value).

For definition of terminology and general information about parameters, see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine\Parameters.md]

In general, C++ uses two types of formal parameters:
  Value parameter: A formal parameter that receives a copy of the content of the corresponding actual parameter.
  Reference parameter: A formal parameter that receives the location (memory address) of the corresponding actual parameter.

When a function is called, all of the parameters of the function are created and initialized as variables.

By default, C++ copies argument values into the matching parameter (‘‘pass-by-value’’).
To refer to an object in the caller’s environment, a C++ call must copy a reference into the parameter (‘‘pass-by-reference’’).

You can program a function such that its parameters are not created and destroyed within the function call using references that are valid even after the function has exited so as to allow you to manipulate more data or parameters in a function call.

As a general rule of thumb:

When we care about performance, we usually pass small values by-value and larger ones by-reference. Here ‘‘small’’ means ‘‘something that’s really cheap to copy.’’ Exactly what ‘‘small’’ means depends on machine architecture, but ‘‘the size of two or three pointers or less’’ is a good rule of thumb.

The semantics of argument passing are identical to the semantics of initialization, argument types are checked and implicit argument type conversion takes place when necessary. The value of such compile-time checking and type conversion should not be underestimated.


### Argument Order
Take care not to make function calls where argument order matters.

The C++ specification does not define the order function calls evaluate arguments, whether arguments are matched with parameters in left to right order or right to left order.

When the arguments are function calls, then this can be problematic:

  someFunction(a(), b()); // a() or b() may be called first

If the architecture evaluates left to right, a() will be called before b(). If the architecture evaluates right to left, b() will be called before a(). This may or may not be of consequence, depending on what a() and b() do.

If it is important that one argument evaluate first, you should explicitly define the order of execution, like so:

  int avar{ a() }; // a() will always be called first
  int bvar{ b() }; // b() will always be called second

  someFunction(avar, bvar);

In the above call, it doesn't matter whether avar or bvar are copied first because they are just values


### Default
In C++, functions can also have optional parameters, for which no arguments are required in the call, in such a way that, for example, a function with two parameters may be called with only one. For this, the function shall include a default value for its last parameter, which is used by the function when called with fewer arguments.

default arguments can be assigned a value when declared:

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

Default arguments and function overloading

Functions with default arguments may be overloaded. For example, the following is allowed:

  void print(std::string string);
  void print(char ch=' ');

If the user were to call print(), it would resolve to print(' '), which would print a space.

However, it is important to note that optional parameters do NOT count towards the parameters that make the function unique. Consequently, the following is not allowed:

  void printValues(int x);
  void printValues(int x, int y=20);

If the caller were to call printValues(10), the compiler would not be able to disambiguate whether the user wanted printValues(int) or printValues(int, 20) with the default value.




## Passing Arguments by Reference
In certain cases, though, it may be useful to access an external variable from within a function. To do that, arguments can be passed by reference, instead of by value.

To gain access to its arguments, the function declares its parameters as references. In C++, references are indicated with an ampersand (&) following the parameter type.

When a variable is passed by reference, what is passed is no longer a copy, but the variable itself, the variable identified by the function parameter, becomes somehow associated with the argument passed to the function, and any modification on their corresponding local variables within the function are reflected in the variables passed as arguments in the call. The parameter names become aliases of the arguments passed on the function call.

when you declare a parameter that takes an argument by reference. A form of the function Area() that computes and returns the area as a parameter by reference looks like this:

  // output parameter result by reference
  void Area(double radius, double& result)
  {
  result = Pi * radius * radius;
  }

Don’t miss the ampersand (&) next to the second parameter result. This sign indicates to the compiler that the second argument should NOT be copied to the function; instead, it is a reference to the variable being passed. The return type has been changed to void as the function no longer supplies the area computed as a return value, rather as an output parameter by reference.

A function can return only one value using the return statement. So, if your function needs to perform operations that
affect many values required at the caller, passing arguments
by reference is one way to get a function to supply those many
modifications back to the calling module.


Returning multiple values via out parameters

Parameters that are only used for returning values back to the caller are called out parameters.

This method, while functional, has a few minor downsides. First, the caller must pass in arguments to hold the updated outputs even if it doesn’t intend to use them. More importantly, the syntax is a bit unnatural, with both the input and output parameters being put together in the function call. It’s not obvious from the caller’s end that sin and cos are out parameters and will be changed. This is probably the most dangerous part of this method (as it can lead to mistakes being made). Some programmers and companies feel this is a big enough problem to advise avoiding output parameters altogether, or using pass by address for out parameters instead (which has a clearer syntax indicating whether a parameter is modifiable or not).

Personally, we recommend avoiding out parameters altogether if possible. If you do use them, naming out parameters (and output arguments) with an “out” suffix (or prefix) can help make it clear that the value might be modified.

Pointers are an effective way to pass memory space that contains relevant data for functions to work on. The memory space shared can also return the result of an operation. When using a pointer with functions, it becomes important to ensure that the called function is only allowed to modify parameters that you want to let it modify, but not others. For example, a function that calculates the area of a circle given radius sent as a pointer should not be allowed to modify the radius. This is where you use the keyword
const to control what a function is allowed to modify


### const
Calling a function with parameters taken by value causes copies of the values to be made. This is a relatively inexpensive operation for fundamental types such as int, but if the parameter is of a large compound type, it may result in certain overhead.

Arguments by reference do not require a copy. The function operates directly on aliases.

functions with reference parameters are generally perceived as functions that modify the arguments passed, because that is why reference parameters are actually for.

The solution is for the function to guarantee that its reference parameters are not going to be modified by this function. This can be done by qualifying the parameters as constant. By qualifying them as const, the function is forbidden to modify the values.

A function can then access values as references (aliases of the arguments), without having to make actual copies.

If we want to pass by reference for performance reasons but don’t need to modify the argument, we pass-by-const-reference

Therefore, const references provide functionality similar to passing arguments by value, but with an increased efficiency for parameters of large types. That is why they are extremely popular in C++ for arguments of compound types. Note though, that for most fundamental types, there is no noticeable difference in efficiency, and in some cases, const references may even be less efficient!

This is by far the most common case in ordinary good code: it is fast and not error-prone. It is not uncommon for a function argument to have a default value; that is, a value that is considered preferred or just the most common. We can specify such a default by a default function argument.

Using const is useful for several reasons:

    It enlists the compilers help in ensuring values that shouldn’t be changed aren’t changed (the compiler will throw an error if you try, like in the above example).
    It tells the programmer that the function won’t change the value of the argument. This can help with debugging.
    You can’t pass a const argument to a non-const reference parameter. Using const parameters ensures you can pass both non-const and const arguments to the function.
    Const references can accept any type of argument, including non-const l-values, const l-values, and r-values.





## Passing Arguments by Address

There is one more way to pass variables to functions, and that is by address. Passing an argument by address involves passing the address of the argument variable rather than the argument variable itself. Because the argument is an address, the function parameter must be a pointer. The function can then dereference the pointer to access or change the value being pointed to.

Remember that fixed arrays decay into pointers when passed to a function, so we have to pass the length as a separate parameter.

It is always a good idea to ensure parameters passed by address are not null pointers before dereferencing them. Dereferencing a null pointer will typically cause the program to crash.

When you pass a pointer to a function, the pointer’s value (the address it points to) is copied from the argument to the function’s parameter. In other words, it’s passed by value! If you change the function parameter’s value, you are only changing a copy. Consequently, the original pointer argument will not be changed.

Note that even though the address itself is passed by value, you can still dereference that address to change the argument’s value. This is a common point of confusion, so let’s clarify:

    When passing an argument by address, the function parameter variable receives a copy of the address from the argument. At this point, the function parameter and the argument both point to the same value.
    If the function parameter is then dereferenced to change the value being pointed to, that will impact the value the argument is pointing to, since both the function parameter and argument are pointing to the same value!
    If the function parameter is assigned a different address, that will not impact the argument, since the function parameter is a copy, and changing the copy won’t impact the original. After changing the function parameter’s address, the function parameter and argument will point to different values, so dereferencing the parameter and changing the value will no longer affect the value pointed to by the argument.

The next logical question is, “What if we want to change the address an argument points to from within the function?”. Turns out, this is surprisingly easy. You can simply pass the address by reference. The syntax for doing a reference to a pointer is a little strange (and easy to get backwards). However, if you do get it backwards, the compiler will give you an error:

  type *& variableName


### Pros and cons of pass by value

Advantages of passing by value:

    Arguments passed by value can be variables (e.g. x), literals (e.g. 6), expressions (e.g. x+1), structs & classes, and enumerators. In other words, just about anything.
    Arguments are never changed by the function being called, which prevents side effects.

Disadvantages of passing by value:

    Copying structs and classes can incur a significant performance penalty, especially if the function is called many times.

When to use pass by value:

    When passing fundamental data type and enumerators, and the function does not need to change the argument.

When not to use pass by value:

    When passing structs or classes (including std::array, std::vector, and std::string).

In most cases, pass by value is the best way to accept parameters of fundamental types when the function does not need to change the argument. Pass by value is flexible and safe, and in the case of fundamental types, efficient.



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



### Pros and cons of pass by address

Advantages of passing by address:

    Pass by address allows a function to change the value of the argument, which is sometimes useful. Otherwise, const can be used to guarantee the function won’t change the argument. (However, if you want to do this with a non-pointer, you should use pass by reference instead).
    Because a copy of the argument is not made, it is fast, even when used with large structs or classes.
    We can return multiple values from a function via out parameters.

Disadvantages of passing by address:

    Because literals (excepting C-style string literals) and expressions do not have addresses, pointer arguments must be normal variables.
    All values must be checked to see whether they are null. Trying to dereference a null value will result in a crash. It is easy to forget to do this.
    Because dereferencing a pointer is slower than accessing a value directly, accessing arguments passed by address is slower than accessing arguments passed by value.

When to use pass by address:

    When passing built-in arrays (if you’re okay with the fact that they’ll decay into a pointer).
    When passing a pointer and nullptr is a valid argument logically.

When not to use pass by address:

    When passing a pointer and nullptr is not a valid argument logically (use pass by reference).
    When passing structs or classes (use pass by reference).
    When passing fundamental types (use pass by value).

As you can see, pass by address and pass by reference have almost identical advantages and disadvantages. Because pass by reference is generally safer than pass by address, pass by reference should be preferred in most cases.

Rule

Prefer pass by reference to pass by address whenever applicable.

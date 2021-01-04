In general, C++ uses two types of formal parameters:
  Value parameter: A formal parameter that receives a copy of the content of the corresponding actual parameter.
  Reference parameter: A formal parameter that receives the location (memory address) of the corresponding actual parameter.

By default, C++ copies values (‘‘pass-by-value’’). To refer to an object in the caller’s environment, a C++ call must use a reference (‘‘pass-by-reference’’).

You can program a function such that its parameters are not created and destroyed within the function call using references that are valid even after the function has exited so as to allow you to manipulate more data or parameters in a function call.

When we care about performance, we usually pass small values by-value and larger ones by-reference. Here ‘‘small’’ means ‘‘something that’s really cheap to copy.’’ Exactly what ‘‘small’’ means depends on machine architecture, but ‘‘the size of two or three pointers or less’’ is a good rule of thumb.

The semantics of argument passing are identical to the semantics of initialization, argument types are checked and implicit argument type conversion takes place when necessary. The value of such compile-time checking and type conversion should not be underestimated.



### Default
In C++, functions can also have optional parameters, for which no arguments are required in the call, in such a way that, for example, a function with two parameters may be called with only one. For this, the function shall include a default value for its last parameter, which is used by the function when called with fewer arguments.

default arguments can be assigned a value when declared:

  double Area(double radius, double pi = 3.14);

The function Area() can then be invoked without a second parameter:

  Area(radius);

In this case, the second parameter defaults to the value of 3.14. However, when required, the same function can be invoked using two arguments:

  Area(radius, 3.14159); // more precise pi


You can have multiple parameters with default values; however, these should all be at the tail end of the parameter list.



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

Pointers are an effective way to pass memory space that contains relevant data for functions to work on. The memory space shared can also return the result of an operation. When using a pointer with functions, it becomes important to ensure that the called function is only allowed to modify parameters that you want to let it modify, but not others. For example, a function that calculates the area of a circle given radius sent as a pointer should not be allowed to modify the radius. This is where you use the keyword
const to control what a function is allowed to modify


### const
Calling a function with parameters taken by value causes copies of the values to be made. This is a relatively inexpensive operation for fundamental types such as int, but if the parameter is of a large compound type, it may result on certain overhead.

Arguments by reference do not require a copy. The function operates directly on aliases.

functions with reference parameters are generally perceived as functions that modify the arguments passed, because that is why reference parameters are actually for.

The solution is for the function to guarantee that its reference parameters are not going to be modified by this function. This can be done by qualifying the parameters as constant. By qualifying them as const, the function is forbidden to modify the values.

A function can then access values as references (aliases of the arguments), without having to make actual copies.

If we want to pass by reference for performance reasons but don’t need to modify the argument, we pass-by-const-reference

Therefore, const references provide functionality similar to passing arguments by value, but with an increased efficiency for parameters of large types. That is why they are extremely popular in C++ for arguments of compound types. Note though, that for most fundamental types, there is no noticeable difference in efficiency, and in some cases, const references may even be less efficient!

This is by far the most common case in ordinary good code: it is fast and not error-prone. It is not uncommon for a function argument to have a default value; that is, a value that is considered preferred or just the most common. We can specify such a default by a default function argument.

For definition of terminology and general information about parameters, see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine\Parameters.md]

When a function is called, all of the parameters of the function are created and initialized as variables. The semantics of argument passing are identical to the semantics of initialization, argument types are checked and implicit argument type conversion takes place when necessary.


In C++, an argument may be unnamed in the argument list of the function definition. Since it is unnamed, you cannot use it in the function body, of course. Unnamed arguments are allowed to give the programmer a way to “reserve space in the argument list.” Whoever uses the function must still call the function with the proper arguments. However, the person creating the function can then use the argument in the future without forcing modification of code that calls the function. This option of ignoring an argument in the list is also possible if you leave the name in, but you will get an annoying warning message about the value being unused every time you compile the function. The warning is eliminated if you remove the name.


In general, C++ uses two types of formal parameters:
  Value parameter: A formal parameter that receives a copy of the content of the corresponding actual parameter.
  Reference parameter: A formal parameter that receives the location (memory address) of the corresponding actual parameter.


By default, C++ copies argument values into parameters (‘‘pass-by-value’’).

To refer to an object in the caller’s environment, a C++ function call must use a reference parameter (‘‘pass-by-reference’’).

As a general rule of thumb:

When we care about performance, we usually pass small values by-value and larger ones by-reference. Here ‘‘small’’ means ‘‘something that’s really cheap to copy.’’ Exactly what ‘‘small’’ means depends on machine architecture, but ‘‘the size of two or three pointers or less’’ is a good rule of thumb.

Terms that pertain to parameter passing methods include:
  Pass By Value
  Pass By Address
  Pass By Reference
  Pass By Constant Reference
  Pass By Rvalue Reference (since C++11)



### const

The const prefix can be used to alter both of these passing methods listed above.  By qualifying parameters as const, the function is forbidden to modify the values. This is useful for several reasons:

    It enlists the compilers help in ensuring values that shouldn’t be changed aren’t changed (the compiler will throw an error if you try).
    It tells the programmer that the function won’t change the value of the argument. This can help with debugging.
    You can’t pass a const argument to a non-const reference parameter. Using const parameters ensures you can pass both non-const and const arguments to the function.
    Const references can accept any type of argument, including non-const l-values, const l-values, and r-values.

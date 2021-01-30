Functions accept input specified by their parameters, and perform a transformation that produces some result.

When you write a user-defined function, you get to determine whether your function will return a value back to the caller or not. To return a value back to the caller, two things are needed.

Return Type
A function indicates the value type it returns to the caller using a type name defined directly before the function’s name in the function signature. The default return type is int if no return type is defined and a return type of void is used to indicate that no value is returned.

Return Statement
A value returning function requires a return statement, within the function body, to indicate the value returned to the caller, the return value.



Returning values from a function to its caller by value, address, or reference works almost exactly the same way as passing arguments to a function does. All of the same upsides and downsides for each method are present. The primary difference between the two is simply that the direction of data flow is reversed. However, there is one more added bit of complexity -- because local variables in a function go out of scope and are destroyed when the function returns, we need to consider the effect of this on each return type.


### Return by value

Return by value is the simplest and safest return type to use. When a value is returned by value, a copy of that value is returned to the caller.

When the return statement is executed, the return value is copied from the function back to the caller. Return by value is the default method for returning an output value; for copying small objects it’s ideal.

Return by value is the most appropriate when returning variables that were declared inside the function, or for returning function arguments that were passed by value. However, like pass by value, return by value is slow for structs and large classes.

When to use return by value:
    When returning variables that were declared inside the function
    When returning function arguments that were passed by value

When not to use return by value:
    When returning a built-in array or pointer (use return by address)
    When returning a large struct or class (use return by reference)



#### Return by address

Returning by address involves returning the address of a variable to the caller. Similar to pass by address, return by address can only return the address of a variable, not a literal or an expression (which don’t have addresses). Because return by address just copies an address from the function to the caller, return by address is fast.

However, return by address has one additional downside that return by value doesn’t -- if you try to return the address of a variable local to the function, your program will exhibit undefined behavior.

We return ‘‘by reference’’ only when we want to grant a caller access to something that is not local to the function.

Return by address is often used to return dynamically allocated memory to the caller. This works because dynamically allocated memory does not go out of scope at the end of the block in which it is declared, so that memory will still exist when the address is returned back to the caller. Keeping track of manual allocations can be difficult. Separating the allocation and deletion into different functions makes it even harder to understand who’s responsible for deleting the resource or if the resource needs to be deleted at all. Smart pointers (covered later) and types that clean up after themselves should be used instead of manual allocations.

When to use return by address:

    When returning dynamically allocated memory and you can’t use a type that handles allocations for you
    When returning function arguments that were passed by address

When not to use return by address:

    When returning variables that were declared inside the function or parameters that were passed by value (use return by value)
    When returning a large struct or class that was passed by reference (use return by reference)



### Return by reference

Similar to return by address, values returned by reference must be variables. When a variable is returned by reference, a reference to the variable is passed back to the caller. The caller can then use this reference to continue modifying the variable. Return by reference is also fast, which can be useful when returning structs and classes.

However, just like return by address, you should not return local variables by reference. You should not return a reference to a literal or an expression that resolves to a temporary value, as those will go out of scope at the end of the function and you’ll end up returning a dangling reference. Return by reference is typically used to return arguments passed by reference to the function back to the caller.

When to use return by reference:
    When returning a reference parameter
    When returning a member of an object that was passed into the function by reference or address
    When returning a large struct or class that will not be destroyed at the end of the function (e.g. one that was passed in by reference)

When not to use return by reference:
    When returning variables that were declared inside the function or parameters that were passed by value (use return by value)
    When returning a built-in array or pointer value (use return by address)



### Mixing return references and values

Although a function may return a value or a reference, the caller may or may not assign the result to a variable or reference accordingly. Let’s look at what happens when we mix value and reference types.

  int returnByValue()
  {
      return 5;
  }

  int& returnByReference()
  {
    // static ensures x isn't destroyed when the function ends
    static int x{ 5 };
    return x;
  }

  int main()
  {
      // case A -- ok, treated as return by value
      int val{ returnByReference() };

      // case B -- compile error since the value is an r-value, and an r-value can't bind to a non-const reference
      int& ref{ returnByValue() };

      // case C -- ok, the lifetime of the return value is extended to the lifetime of cref
      const int& cref{ returnByValue() };

      return 0;
  }

In case A, we’re assigning a reference return value to a non-reference variable. Because val isn’t a reference, the return value is copied into val, as if returnByReference() had returned by value.

In case B, we’re trying to initialize reference ref with the copy of the return value returned by returnByValue(). However, because the value being returned doesn’t have an address (it’s an r-value), this will cause a compile error.

In case C, we’re trying to initialize const reference cref with the copy of the return value returned by returnByValue(). Because const references can bind to r-values, there’s no problem here. Normally, r-values expire at the end of the expression in which they are created -- however, when bound to a const reference, the lifetime of the r-value (in this case, the return value of the function) is extended to match the lifetime of the reference (in this case, cref)

For more information regarding value types, see:
[C++\Semantics\Values.md]



## Automatic Return Type Deduction

Starting with C++14, instead of specifying the return type, you would use auto as the return type declaration and let the compiler deduce the return type for you on the basis of return values you program.

For more information regarding the use of return type deduction, see:
[C++\Syntax\Statements\Declarations\Variables\TypeDeduction\_TypeDeduction.md]

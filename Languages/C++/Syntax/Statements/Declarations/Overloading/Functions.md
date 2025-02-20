## Function Overloading

C++ allows multiple definitions for the same function name in the same scope. The definition of the function must differ from each other by the types and/or the number of arguments in the argument list. While the return type can change, you cannot overload function declarations that differ only by return type.

Overloaded functions can be quite useful in applications where a function with a particular name that produces a certain type of output might need to be invoked with different sets of parameters.

Overload Resolution
Overload resolution is the process that the compiler executes when matching
a function invocation with its proper implementation.

Recall from Chapter 4 that function overloads allow you to specify functions with the same name but different types and possibly different arguments. The compiler selects among these function overloads by comparing the argument types within the function invocation with the types within each overload declaration. The compiler will choose the best among the possible options, and if it cannot select a best option, it will generate a compiler error.

Roughly, the matching process proceeds as follows:
1. The compiler will look for an exact type match.
2. The compiler will try using integral and floating-point promotions to get a suitable overload (for example, int to long or float to double).
3. The compiler will try to match using standard conversions like integral type to floating-point or casting a pointer-to-child into a pointer-to-parent.
4. The compiler will look for a user-defined conversion.
5. The compiler will look for a variadic function.



## Conflicts
If two functions are defined with the same name, but with different argument types, the compiler will choose the most appropriate function to invoke for each call

If two alternative functions could be called, but neither is better than the other, the call is deemed ambiguous and the compiler gives an error. For example:

void print(int, double);
void print(double, int);

void user2() {
  print(0,0); // error: ambiguous
}

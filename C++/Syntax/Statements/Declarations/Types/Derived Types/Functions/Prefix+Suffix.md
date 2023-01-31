## Prefix Specifiers
You can provide a number of optional specifiers (or modifiers) to functions.

Specifiers alter a function’s behavior in some way.

prefix specifiers: appear at the beginning of the function’s declaration or definition, before the return type in the function.
suffix specifiers: appear after the argument list.

The syntax is as follows:

```cpp
[prefix] return_type function_name( parameter_list ) [suffix];

[prefix] return_type function_name( parameter_list ) [suffix]
{
  //statements
}
```

where
  [prefix] indicates the location of prefix specifiers
  [suffix] indicates the location of suffix specifiers

There isn’t a definite reason for why certain specifiers appear as
prefixes or as suffixes. Relative to other languages, C++ has a long history, the location of the various specifiers evolved incrementally along with it. Modern programmers must ensure that their usage follows the syntax defined by the C++ language specification.


## Prefix Specifiers

### static
indicates that a function that isn’t a member of a class has internal linkage, meaning the function won’t be used outside of this translation unit. Unfortunately, this keyword does double duty: if it modifies a method (that is, a function inside a class), it indicates that the function isn’t associated with an instantiation of the class but rather with the class itself.

### virtual
indicates that a method can be overridden by a child class. The override modifier indicates to the compiler that a child class intends to override a parent’s virtual function.

### constexpr
indicates that the function should be evaluated at compile time if possible.

### [[noreturn]]
indicates that this function won’t return. This attribute helps the compiler to optimize your code.


### inline
An inline prefix guides the compiler when optimizing code.

On most platforms, a function call compiles into a series of instructions,
such as the following:
1. Place arguments into registers and on the call stack.
2. Push a return address onto the call stack.
3. Jump to the called function.
4. After the function completes, jump to the return address.
5. Clean up the call stack.

These steps typically execute very quickly, and the payoff in reduced binary size can be substantial if you use a function in many places.

Inlining a function means copying and pasting the contents of the function directly into the execution path, eliminating the need for the five steps outlined. This means that as the processor executes your code, it will immediately execute your function’s code rather than executing the (modest) ceremony required for function invocation. If you prefer this marginal increase in speed over the commensurate cost in increased binary size, you can use the inline keyword to indicate this to the compiler. The inline keyword hints to the compiler’s optimizer to put a function directly inline rather than perform a function call.

Adding inline to a function doesn’t change its behavior; it’s purely an expression of preference to the compiler. You must ensure that if you define a function inline, you do so in all translation units. Also note that modern compilers will typically inline functions where it makes sense—especially if a function isn’t used outside of a single translation unit.


If your function is a very simple one like the following:

```cpp
  int Max(int x, int y) {
     return (x > y)? x : y;
  }
```

The overhead of performing an actual function call on this might be quite high for the amount of time spent actually executing Max.

This is why C++ compilers enable the programmer to declare such functions as inline. Keyword inline is the programmers’ request that these functions be expanded inline where called.

Compilers typically see this keyword as a request to place the contents of the function directly where the function has been invoked which increases the execution speed of the code.

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

```cpp
#include <iostream>

using namespace std;

inline int Max(int x, int y) {
   return (x > y)? x : y;
}

// Main function for the program
int main() {
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;

   return 0;
}
```

Calling a function generally causes a certain overhead (stacking arguments, jumps, etc...), and thus for very short functions, it may be more efficient to simply insert the code of the function where it is called, instead of performing the process of formally calling a function.

Preceding a function declaration with the inline specifier informs the compiler that inline expansion is preferred over the usual function call mechanism for a specific function. This does not change at all the behavior of a function, but is merely used to suggest the compiler that the code generated by the function body shall be inserted at each point the function is called, instead of being invoked with a regular function call.

For example, the concatenate function above may be declared inline as:

```cpp
  inline string concatenate (const string& a, const string& b)
  {
    return a+b;
  }
```

This informs the compiler that when concatenate is called, the program prefers the function to be expanded inline, instead of performing a regular call. inline is only specified in the function declaration, not when it is called.

Note that most compilers already optimize code to generate inline functions when they see an opportunity to improve efficiency, even if not explicitly marked with the inline specifier. Therefore, this specifier merely indicates the compiler that inline is preferred for this function, although the compiler is free to not inline it, and optimize otherwise. In C++, optimization is a task delegated to the compiler, which is free to generate any code for as long as the resulting behavior is the one specified by the code.


## Suffix specifiers

### noexcept
indicates that the function will never throw an exception. It enables certain optimizations.

### const
indicates that the method won’t modify an instance of its class, allowing const references types to invoke the method.


### final and override
The final modifier indicates that a method cannot be overridden by a child
class. It’s effectively the opposite of virtual.

You can also apply the final keyword to an entire class, disallowing that
class from becoming a parent entirely

N O T E
Neither final nor override is technically a language keyword; they are identifiers. Unlike keywords, identifiers gain special meaning only when used in a specific context. This means you can use final and override as symbol names elsewhere in your program, thereby leading to the insanity of constructions like virtual void final() override. Try not to do this.


Whenever you’re using interface inheritance, you should mark implementing classes final because the modifier can encourage the compiler to perform an optimization called devirtualization. When virtual calls are devirtualized, the compiler eliminates the runtime overhead associated with a virtual call.

### volatile
A volatile object’s value can change at any time, so the compiler must treat all accesses to volatile objects as visible side effects for optimization purposes. The volatile keyword indicates that a method can be invoked on volatile objects. This is analogous to how const methods can be applied to const objects. Together, these two keywords define a method’s const/volatile qualification (or sometimes cv qualification).

Just like you cannot invoke a non-const method on a const object, you cannot invoke a non-volatile method on a volatile object.

Consider what would happen if you could perform such an operation: a non-volatile method is a candidate for all kinds of compiler optimizations: many kinds of memory accesses can be optimized away without changing the observable side effects of your program.

How should the compiler treat a contradiction arising from you using a
volatile object—which requires that all its memory accesses are treated as
observable side effects — to invoke a non-volatile method?

The compiler’s answer is that it calls this contradiction an error.

## Prefix Modifiers

### static
indicates that a function that isn’t a member of a class has internal linkage, meaning the function won’t be used outside of this translation unit. Unfortunately, this keyword does double duty: if it modifies a method (that is, a function inside a class), it indicates that the function isn’t associated with an instantiation of the class but rather with the class itself.

### virtual
indicates that a method can be overridden by a child class. The override modifier indicates to the compiler that a child class intends to override a parent’s virtual function.

### constexpr
indicates that the function should be evaluated at compile time if possible.

### [[noreturn]]
indicates that this function won’t return. Recall that this attribute helps the compiler to optimize your code.


### inline
guides the compiler when optimizing code.
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



## Suffix Modifiers

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

Just like you cannot invoke a non-const
method on a const object, you cannot invoke a non-volatile method on a
volatile object. Consider what would happen if you could perform such an
operation: a non-volatile method is a candidate for all kinds of compiler
optimizations for the reasons outlined in Chapter 7: many kinds of memory
accesses can be optimized away without changing the observable side effects
of your program.
How should the compiler treat a contradiction arising from you using a
volatile object—which requires that all its memory accesses are treated as
observable side effects—to invoke a non-volatile method? The compiler’s
answer is that it calls this contradiction an error.

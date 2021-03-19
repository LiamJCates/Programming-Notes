Bindings and Scopes
Each binding has a scope, which is the part of the program in which the binding is visible. For bindings defined outside of any function or block, the
scope is the whole program—you can refer to such bindings wherever you
want. These are called global.
But bindings created for function parameters or declared inside a
function can be referenced only in that function, so they are known as local
bindings. Every time the function is called, new instances of these bindings
are created. This provides some isolation between functions—each function call acts in its own little world (its local environment) and can often
be understood without knowing a lot about what’s going on in the global
environment.
Bindings declared with let and const are in fact local to the block that
they are declared in, so if you create one of those inside of a loop, the code
before and after the loop cannot “see” it. In pre-2015 JavaScript, only functions created new scopes, so old-style bindings, created with the var keyword,
are visible throughout the whole function that they appear in—or throughout the global scope, if they are not in a function.

Each scope can “look out” into the scope around it, so x is visible inside the block in the example. The exception is when multiple bindings have the same name—in that case, code can see only the innermost one.

JavaScript distinguishes not just global and local bindings. Blocks and functions can be created inside other blocks and functions, producing multiple degrees of locality.

The set of bindings visible inside a block is determined by the place of that block in the program text. Each local scope can also see all the local scopes that contain it, and all scopes can see the global scope. This approach to binding visibility is called lexical scoping.

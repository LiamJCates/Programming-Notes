The term static is one of the most confusing terms in the C++ language, in large part because static has different meanings in different contexts.


#### Local
A static local variable is created at the start of the program, and destroyed at the end of the program (just like a global variable). As a result, the static variable will retain its value even after it goes out of scope!

Static variables offer some of the benefit of global variables (they don’t get destroyed until the end of the program) while limiting their visibility to block scope. This makes them safe for use even if you change their values regularly.

Avoid static local variables unless the variable never needs to be reset. static local variables decrease reusability and make functions harder to reason about.

Static local variables should only be used if in your entire program and in the foreseeable future of your program, the variable is unique and it wouldn’t make sense to reset the variable.

#### Global
The static modifier may also be applied to global variables. When this is done, it causes that variable's scope to be restricted to the file in which it is declared.



#### Class Member
When static is used on a class data member, it causes only one copy of that member to be shared by all objects of its class.

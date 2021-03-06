## Fundamental Data Types
Fundamental Data types are the most basic types of object.


Fundamental types (also called built-in types) are specified by the C++ language standard and are built into the compiler. Fundamental types aren't defined in any header file.

A data type is called fundamental if variables of that type can store only one value at a time.





Each Fundamental Data type corresponds directly to hardware facilities and has a fixed size that determines the range of values that can be stored in it.

The size of a type is implementation-defined (i.e., it can vary among different machines) and can be obtained by the sizeof operator; for example, sizeof(char) equals 1 and sizeof(int) is often 4.


Some refer to Fundamental Data types as primitive or built-in types because they’re part of the core language and almost always available to you.

For more information on primitive types see:
[C++\Syntax\Statements\Declarations\PrimitiveTypes\_Primitives.md]

These types will work on any platform, but their features, such as size and memory layout, depend on implementation.

Fundamental Data types strike a balance. On one hand, they try to map a direct relationship from C++ construct to computer hardware; on the other hand, they simplify writing cross-platform code by allowing a programmer to write code once that works on many platforms.



Types built out of other types using C++’s abstraction mechanisms are called user-defined types. They are referred to as classes and enumerations. User defined types can be built out of both built-in types and other user-defined types.

The type qualifiers provide additional information about the variables they precede.

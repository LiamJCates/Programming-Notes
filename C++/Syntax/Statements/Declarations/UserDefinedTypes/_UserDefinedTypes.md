The data types that are defined by the user are called abstract datatypes or user-defined derived data type.

These types include:

  Enumeration
  Class
  Structure
  Union
  Type aliases



Class
The building block of C++ that leads to Object-Oriented programming is a Class. A class is like a blueprint for an object, which holds its own data and function members. Class members can be accessed and used by creating an object which is an instance of that class.

Enumerations
The simplest of the user-defined types. The values that an enumeration can take are restricted to a set of possible values. Enumerations are excellent for modeling categorical concepts.

Structures
A structure creates a data type that can be used to group items of possibly different types into a single type.

Unions
A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one member at a time. Unions can be dangerous as they are easy to misuse.

Type aliases
C++ allows you to define explicitly data type names by via the using and typedef keywords. These do not actually create a new data class, rather they define a name for an existing type. This can increase the portability(the ability of a program to be used across different types of machines; i.e., mini, mainframe, micro, etc; without much changes into the code) of a program as only the type alias statements would have to be changed.

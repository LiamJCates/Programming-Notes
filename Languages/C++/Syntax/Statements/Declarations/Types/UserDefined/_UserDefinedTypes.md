The data types that are defined by the user are called abstract, user-defined, or derived datatypes.

C++ augments the built-in types and operations with
a sophisticated set of abstraction mechanisms out of which programmers can build such high-level

User-defined types are often preferred over built-in types because they are easier to use, less error-prone, and typically as efficient for what they do as direct use of built-in types, or even faster.

These types include:

  Enumeration
  Structure
  Type aliases
  Union
  Class


Enumerations
The simplest of the user-defined types. The values that an enumeration can take are restricted to a set of possible values. Enumerations are excellent for modeling categorical concepts.

Structures
A structure creates a data type that can be used to group items of possibly different types into a single type.

Type aliases
C++ allows you to define new data type names. These do not actually create a new data type, rather they define a name for an existing type.

Unions
A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one member at a time.

Class
The building block of C++ that leads to Object-Oriented programming is a Class. A class is like a blueprint for an object, which holds its own data and function members. Class members can be accessed and used by creating an object which is an instance of that class.

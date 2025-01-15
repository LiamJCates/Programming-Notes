The concept of type is of particular importance in C++. 

All entities, objects, references, functions including function template specializations, and expressions have a property called type.

A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
• A type defines a set of possible values and a set of operations (for an object).
• An object is some memory that holds a value of some type.
• A value is a set of bits interpreted according to a type.
• A variable is a named object

type both restricts the operations that are permitted for programming entities and provides semantic meaning to the otherwise generic sequences of bits. 


C++ is both a strongly typed language and a statically typed language; every object has a type and that type never changes. When you declare a variable in your code, you must either specify its type explicitly, or use the auto keyword to instruct the compiler to deduce the type from the initializer. When you declare a function in your code, you must specify the type of its return value and of each argument. Use the return value type void if no value is returned by the function. The exception is when you're using function templates, which allow for arguments of arbitrary types.



Every variable, function argument, and function return value must have a type in order to be compiled. Also, all expressions (including literal values) are implicitly given a type by the compiler before they're evaluated. 

The type of a given value specifies:
the amount of memory that's allocated
the kinds of values that may be stored 
how the compiler interprets the bit patterns in those values
the operations you can perform on them 

When the type of a variable, here named "v", is of any particular type, here named "T", we often say that “v has type T” or, interchangeably, that “v is a T.”


There are many conceptualizations of type classifications, and various texts will use different terms that mean the same or similar things, we will try to cover the most popular ones here:

fundamental
primitive / basic
built-in

scalar
compound / composite

abstract
derived
user-defined
variable vs. object
POD


C++ defines two formal classifications of types: 
fundamental and compound

a flowchart can be found
https://upload.cppreference.com/mwiki/images/9/96/cpp_types.svg


Fundamental
https://en.cppreference.com/w/cpp/language/types


Primitive
"primitive" or "basic" types tends to be used by other languages to refer to simple types that are similar to C++'s fundamental types. Readers my find informal descriptions use these terms interchangeably within the context of C++

Built-in
We call the types that can be built from the fundamental types, the const and volitile modifiers (cv-qualified), and the declarator operators built-in types.


Fundamental:

void

    Object:

        Scalar:

        null pointer

            Arithmetic:

            integer
            floating point

Compound:

function
reference

    Object:

    array
    class
    union

        Scalar:

        enum
        pointer
        member_pointer


Scalar type: A type that holds a single value of a defined range. Scalars include arithmetic types (integral or floating-point values), enumeration type members, pointer types, pointer-to-member types, and std::nullptr_t. Fundamental types are typically scalar types.


Compound type: A type that isn't a scalar type. Compound types include array types, function types, class (or struct) types, union types, enumerations, references, and pointers to non-static class members.


Variable: The symbolic name of a quantity of data. The name can be used to access the data it refers to throughout the scope of the code where it's defined. In C++, variable is often used to refer to instances of scalar data types, whereas instances of other types are typically called objects.

Object: For simplicity and consistency, this article uses the term object to refer to any instance of a class or structure. When it's used in the general sense, it includes all types, even scalar variables.

POD type (plain old data): This informal category of data types in C++ refers to types that are scalar (see the Fundamental types section) or are POD classes. A POD class has no static data members that aren't also PODs, and has no user-defined constructors, user-defined destructors, or user-defined assignment operators. Also, a POD class has no virtual functions, no base class, and no private or protected non-static data members. POD types are often used for external data interchange, for example with a module written in the C language (which has POD types only).
Types are one of the most fundamental concepts in programming.

The concept of type is important in C++. 

Objects, references, functions including function template specializations, and expressions have a property called type.

A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
• A type defines a set of possible values and a set of operations (for an object).
• An object is some memory that holds a value of some type.
• A value is a set of bits interpreted according to a type.
• A variable is a named object

type both restricts the operations that are permitted for programming entities and provides semantic meaning to the otherwise generic sequences of bits. 

Every variable, function argument, and function return value must have a type in order to be compiled. Also, all expressions (including literal values) are implicitly given a type by the compiler before they're evaluated. 

The type of a given value specifies:
the amount of memory that's allocated
the kinds of values that may be stored 
how the compiler interprets the bit patterns in those values
the operations you can perform on them 

When the type of a variable, here named "v", is of any particular type, here named "T", we often say that “v has type T” or, interchangeably, that “v is a T.”


There are many conceptualizations of type classifications, and various texts will use different terms that mean the same or similar things, we will try to cover the most popular ones here:

fundamental
primative / basic
built-in

scalar
compound / composite

abstract
derived
user-defined
object
POD


C++ defines two formal classifications of types: 
fundamental and compound

a flowchart can be found
https://upload.cppreference.com/mwiki/images/9/96/cpp_types.svg


Fundamental
https://en.cppreference.com/w/cpp/language/types


Primative
"primitive" or "basic" types tends to be used by other languages to refer to simple types that are similar to C++'c "undamental types. Readers my find informal descriptions use these terms interchangeably within the context of C++

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

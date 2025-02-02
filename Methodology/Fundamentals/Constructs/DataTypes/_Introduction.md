# Data Type

https://en.wikipedia.org/wiki/Data_type

## Overview
In computer science and computer programming, a data type is an attribute of any data unit, a singular, structured piece of information.

A data unit may be formed from a composition of other data units which themselves may be compositional in nature. 

The data type (or simply type) of a data unit is generally specified by a set of possible values, a set of allowed operations on these values, and it's physical or hardware representation.



### Real World Example
We begin our data typing journey with a "real-world" example of data with which many are familiar.

The mathematical integers are one of the most common types of data for which many individuals have developed some level of rigorous theoretical understanding. We are taught from a young age of their general format, valid values, operations we can perform with those values, and the logical behavior that produces the results of those operations.


Properties of mathematical integers:

Values:
The set of integer values consists of zero (0), the positive natural numbers (1, 2, 3, ...), and their additive inverses (the negative integers, i.e., −1, −2, −3, ...).

Operations:
The set of integers is "closed" under certain arithmetic operations, like addition and multiplication. A set is closed under an operation if performance of that operation on members of the set always produces a member of that set. If we add or multiply two integer values together the result will always be another integer value.
(An operation like division involves all real numbers (result values may require decimal digits))

Representation:
We represent integer values in written format as base-10 numerals, using Arabic numbers (0,1,2, … 8, 9) arranged as numeric digits, where each numeral is a sequence of digits which may be of arbitrary (any) length, and any digit composing a numeral can only have one of 10 values.



Different languages may use different data types or similar types with different semantics. For example, in the Python programming language, int represents an arbitrary-precision integer which has the traditional numeric operations such as addition, subtraction, and multiplication. However, in the Java programming language, the type int represents the set of 32-bit integers ranging in value from −2,147,483,648 to 2,147,483,647, with arithmetic operations that wrap on overflow. In Rust this 32-bit integer type is denoted i32 and panics on overflow in debug mode





Most programming languages also allow the programmer to define additional data types, usually by combining multiple elements of other types and defining the valid operations of the new data type. For example, a programmer might create a new data type named "complex number" that would include real and imaginary parts, or a color data type represented by three bytes denoting the amounts each of red, green, and blue, and a string representing the color's name.



### Type Systems 

Data types are used within type systems, which offer various ways of defining, implementing, and using them. In a type system, a data type represents a constraint placed upon the interpretation of data, describing representation, interpretation and structure of values or objects stored in computer memory. The type system uses data type information to check correctness of computer programs that access or manipulate the data.

A type system is a logical system comprising a set of rules that assigns a property called a type (for example, integer, floating point, string) to every term (a word, phrase, or other set of symbols). Usually the terms are various language constructs of a computer program, such as variables, expressions, functions, or modules. A type system dictates the operations that can be performed on a term. For variables, the type system determines the allowed values of that term. 

https://en.wikipedia.org/wiki/Type_system


Type checking is the process of verifying and enforcing the constraints of types,
which can occur at either compile-time or run-time. Compile time checking, also
called static type checking, is carried out by the compiler when a program is com-
piled. Run time checking, also called dynamic type checking, is carried out by the
program as it is running. A programming language is said to be strongly typed
if the type system ensures that conversions between types must be either valid or
result in an error. A weakly typed language on the other hand makes no such guarantees and generally allows automatic conversions between types which may have
no useful purpose



Key Differences:

    When type checking occurs:
        Static: During compilation 
        Dynamic: At runtime 

Benefits of Static Type Checking: 

    Early error detection 
    Improved code reliability 
    Easier debugging 
    Better code maintainability 

Benefits of Dynamic Type Checking: 

    Greater flexibility and rapid prototyping 
    Less code to write (less type annotations needed) 
    Easier to learn for beginners 

Examples of Languages:

    Static Typing: Java, C++, C#, TypeScript
    Dynamic Typing: Python, JavaScript, PHP
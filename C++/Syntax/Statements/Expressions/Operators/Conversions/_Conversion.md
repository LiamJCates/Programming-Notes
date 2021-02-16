Type Conversions

Type conversion operations are used to convert a value of one type to a corresponding value of another type.

Type conversion is classified by the type being converted as either:
	Standard
	User-Defined

Standard Conversions
Standard conversions are those that affect fundamental data types, and allow the conversions between numerical types (short to int, int to float, double to int...), to or from bool, and some pointer conversions.

User-Defined Type Conversions
Conversion of user-defined types must be defined by their classes. These functions tell the compiler how your user-defined types behave during implicit and explicit type conversion.



Depending on the situation, type conversions can be
	Explicit
	Implicit

Explicit Conversion
The word “explicit” means ‘open’ or ‘clear’. In explicit C++ type casting, the data type in which the value is to be converted is clearly specified in the program. It is done by cast operator. The cast operator is a unary operator. It converts the value of an expression into a value of the type specified.

Implicit Conversion
The word “implicit” means ‘understood’ or ‘embedded’. In implicit C++ type casting, the data type in which the value is to be converted is not specified by the source code as in explicit conversion. It is automatically done by the C++ compiler.



Explicit conversion cast operators
	C-Style
	Functional
	Named







Narrowing conversion

Some of these conversions may imply a loss of precision, which the compiler can signal with a warning. This warning can be avoided with an explicit conversion.


Widening conversion

Widening conversion are also called promotions




Explicit type conversion

Explicit type conversions are also called casts.

C++ is a strong-typed language. Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion, known in C++ as type-casting.

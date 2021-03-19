## Type Conversions

Type conversion operations are used to convert a value of one type to a corresponding value of another type.


### Type

Type conversion is classified by the type being converted as either:
	Standard
	User-Defined

#### Standard Conversions
Standard conversions are those that affect fundamental data types, allowing conversions between numerical types (short to int, int to float, double to int...), to or from bool, and some pointer conversions.

#### User-Defined Type Conversions
Conversion of user-defined types must be defined by their classes. These functions tell the compiler how your user-defined types behave during implicit and explicit type conversion.



### Cause

The cause of a given type conversion can be:
	Explicit
	Implicit

#### Explicit Conversion
The word “explicit” means ‘open’ or ‘clear’. In explicit C++ type casting, the data type in which the value is to be converted is clearly specified by the source code.

Explicit conversions are called casts and are done by cast operators. The cast operator is a unary operator. These operators convert a value or expression into a value of the type specified.

Explicit conversion cast operators:
	C-Style
	Functional
	Named



#### Implicit Conversion
The word “implicit” means ‘understood’ or ‘embedded’. In implicit C++ type casting, the data type in which the value is to be converted is not specified by the source code as in explicit conversion. It is automatically done by the C++ compiler.



### Effect

A given type conversion may change the number of bits used to represent a value, these types of conversions are known as:
	Narrowing
	Widening


#### Narrowing conversion

Some of these conversions may imply a loss of precision, which the compiler can signal with a warning. This warning can be avoided with an explicit conversion.

A narrowing cast introduces the possibility of overflow.

Narrowing casts must be explicitly cast, and overflow exceptions must be handled unless the code is marked as not being checked for overflow

The compiler performs narrowing conversions implicitly, but it warns you about potential data loss. Take these warnings very seriously. If you are certain that no data loss will occur because the values in the larger variable will always fit in the smaller variable, then add an explicit cast so that the compiler will no longer issue a warning. If you are not sure that the conversion is safe, add to your code some kind of runtime check to handle possible data loss so that it does not cause your program to produce incorrect results.

Any conversion from a floating point type to an integral type is a narrowing conversion because the fractional portion of the floating point value is discarded and lost.



#### Widening conversion

A "widening" cast is a cast from one type to another, where the "destination" type has a larger range or precision than the "source" (e.g. int to long, float to double).

Widening conversion are also called promotions

Widening casts between built-in primitives are implicit, meaning you do not have to specify the new type with the cast operator, unless you want the type to be treated as the wider type during a calculation.

Because widening conversions are always safe, the compiler performs them silently and does not issue warnings.

By default, types are cast to the widest actual type used on the variable's side of a binary expression or assignment, not counting any types on the other side).

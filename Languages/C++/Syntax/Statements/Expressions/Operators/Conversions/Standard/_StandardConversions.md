The C++ language defines conversions between its fundamental types. It also defines conversions for pointer, reference, and pointer-to-member derived types. These conversions are called standard conversions.

Standard conversions:
  Integral conversions and promotions
  Arithmetic conversions
  Pointer conversions
  Reference conversions
  Pointer-to-member conversions

Note



The result of a conversion is an l-value only if it produces a reference type. For example, a user-defined conversion declared as operator int&() returns a reference and is an l-value. However, a conversion declared as operator int() returns an object and isn't an l-value.

Integral promotions

Objects of an integral type can be converted to another wider integral type, that is, a type that can represent a larger set of values. This widening type of conversion is called integral promotion. With integral promotion, you can use the following types in an expression wherever another integral type can be used:

    Objects, literals, and constants of type char and short int
    Enumeration types
    int bit fields
    Enumerators

C++ promotions are "value-preserving," as the value after the promotion is guaranteed to be the same as the value before the promotion. In value-preserving promotions, objects of shorter integral types (such as bit fields or objects of type char) are promoted to type int if int can represent the full range of the original type. If int can't represent the full range of values, then the object is promoted to type unsigned int. Although this strategy is the same as the one used by Standard C, value-preserving conversions don't preserve the "signedness" of the object.

Value-preserving promotions and promotions that preserve signedness normally produce the same results. However, they can produce different results if the promoted object appears as:

An operand of /, %, /=, %=, <, <=, >, or >=
  These operators rely on sign for determining the result. Value-preserving and sign-preserving promotions produce different results when applied to these operands.

The left operand of >> or >>=
  These operators treat signed and unsigned quantities differently in a shift operation. For signed quantities, a right shift operation propagates the sign bit into the vacated bit positions, while the vacated bit positions are zero-filled in unsigned quantities.

Overloaded
  An argument to an overloaded function, or the operand of an overloaded operator, that depends on the signedness of the operand type for argument matching. For more information about defining overloaded operators, see Overloaded operators.

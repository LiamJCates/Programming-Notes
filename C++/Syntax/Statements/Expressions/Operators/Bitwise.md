## Unary Bitwise Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Bitwise NOT | ~a | Yes |

The one's complement operator (~), sometimes called the bitwise complement operator, yields a bitwise one's complement of its operand. That is, every bit that is 1 in the operand is 0 in the result. Conversely, every bit that is 0 in the operand is 1 in the result. The operand to the one's complement operator must be an integral type.

Integral promotion is performed on integral operands. The type the operand is promoted to is the resultant type:
[C++\Semantics\Types&Values\Conversions\StandardConversions.md]



## Binary Bitwise Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Bitwise AND | a & b | Yes |
| Bitwise OR | a \| b | Yes |
| Bitwise XOR | a ^ b | Yes |

These operands perform bitwise evaluation between corresponding operand bits.

Both operands to the bitwise operator must have integral types. The usual arithmetic conversions are applied to the operands:
[C++\Semantics\Types&Values\Conversions\StandardConversions.md]



## Bitwise Shift Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Bitwise left shift | a << b | Yes |
| Bitwise right shift | a >> b | Yes |


The bitwise shift operators are the right-shift operator (>>), which moves the bits of shift-expression to the right, and the left-shift operator (<<), which moves the bits of shift-expression to the left.

The left-shift operator causes the bits in shift-expression to be shifted to the left by the number of positions specified by additive-expression. The bit positions that have been vacated by the shift operation are zero-filled. A left shift is a logical shift (the bits that are shifted off the end are discarded, including the sign bit).

The right-shift operator causes the bit pattern in shift-expression to be shifted to the right by the number of positions specified by additive-expression. For unsigned numbers, the bit positions that have been vacated by the shift operation are zero-filled. For signed numbers, the sign bit is used to fill the vacated bit positions. In other words, if the number is positive, 0 is used, and if the number is negative, 1 is used.

The result of a right-shift of a signed negative number is implementation-dependent. Although the Microsoft C++ compiler uses the sign bit to fill vacated bit positions, there is no guarantee that other implementations also do so.

The result of a shift operation is undefined if additive-expression is negative or if additive-expression is greater than or equal to the number of bits in the (promoted) shift-expression. No shift operation is performed if additive-expression is 0.

The expressions on both sides of a shift operator must be integral types.

The result type is the same as the type of the promoted shift-expression:
[C++\Semantics\Types&Values\Conversions\StandardConversions.md]

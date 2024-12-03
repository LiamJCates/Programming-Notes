## Unary Logical Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| NOT | !a | Yes |

The logical negation operator, !, reverses the meaning of its operand. The operand must be of arithmetic or pointer type (or an expression that evaluates to arithmetic or pointer type). The operand is implicitly converted to type bool. The result is true if the converted operand is false; the result is false if the converted operand is true. The result is of type bool.

For an expression e, the unary expression !e is equivalent to the expression (e == 0), except where overloaded operators are involved.



## Binary Logical Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| AND | a && b | Yes |
| OR | a \|\| b | Yes |

The logical AND operator (&&) returns the boolean value true if both operands are true and returns false otherwise.
The logical OR operator (||) returns the boolean value true if either or both operands is true and returns false otherwise.

The operands are implicitly converted to type bool before evaluation, and the result is of type bool. Logical AND has left-to-right associativity.

The operands don't need to have the same type, but they must have boolean, integral, or pointer type. The operands are commonly relational or equality expressions.

The first operand is completely evaluated and all side effects are completed before evaluation of the logical expression continues.

The second AND operand is evaluated only if the first operand evaluates to true (nonzero).
The second OR operand is evaluated only if the first operand evaluates to false.
This is known as short-circuit evaluation.

This evaluation eliminates needless evaluation of the second operand.

You can use short-circuit AND evaluation to prevent null-pointer dereferencing
char *pch = 0;
// ...
(pch) && (*pch = 'a');

## Unary Plus and Negation
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Unary Plus | +a | Yes |
| Unary Minus | -a | Yes |

The result of the unary plus operator (+) is the value of its operand.
The unary negation operator (-) produces the negative of its operand.

Their operand must be of an arithmetic type.

Integral promotion is performed on integral operands. The resultant type is the type to which the operand is promoted. Thus, the expression +ch, where ch is of type char, results in type int; the value is unmodified.

Unary negation of unsigned quantities is performed by subtracting the value of the operand from 2^n, where n is the number of bits in an object of the given unsigned type.



## Unary Increment and Decrement
The unary operators (++ and --) are called "prefix" and "postfix" increment or decrement operators when the increment or decrement operators appear before or after the operand, respectively.

| Name | Syntax | Overloadable |
|------|--------|--------------|
| Prefix Increment | ++a | Yes |
| Postfix Increment | a++ | Yes |
| Prefix Decrement | --a | Yes |
| Postfix Decrement | a-- | Yes |

The operands to prefix increment and prefix decrement operators must have integral, floating, or pointer type and must be a modifiable l-value expression (an expression without the const attribute). The result is an l-value.

When the operator appears before its operand, the operand is incremented or decremented and its new value is the result of the expression.

a postfix increment or decrement expression evaluates to the value of the expression prior to application of the respective operator. The increment or decrement operation occurs after the operand is evaluated. This issue arises only when the postfix increment or decrement operation occurs in the context of a larger expression.

When a postfix operator is applied to a function argument, the value of the argument is not guaranteed to be incremented or decremented before it is passed to the function.

An operand of integral or floating type is incremented or decremented by the integer value 1. The type of the result is the same as the operand type. An operand of pointer type is incremented or decremented by the size of the object it addresses. An incremented pointer points to the next object; a decremented pointer points to the previous object.

The operands to postfix increment and postfix decrement operators must be modifiable (not const) l-values of arithmetic or pointer type. The type of the result is the same as that of the postfix-expression, but it is no longer an l-value.

Because increment and decrement operators have side effects, using expressions with increment or decrement operators in a preprocessor macro can have undesirable results. Consider this example:

  #define max(a,b) ((a)<(b))?(b):(a)

  int main()
  {
     int i = 0, j = 0, k;
     k = max( ++i, j );
  }

The macro expands to:

  k = ((++i)<(j))?(j):(++i);

If i > j or less than j by 1, it will be incremented twice.




## Binary Arithmetic Additive Operators
The additive operators take operands of arithmetic or pointer types and have left-to-right associativity.

| Name | Syntax | Overloadable |
|------|--------|--------------|
| Addition | a + b | Yes |
| Subtraction | a - b | Yes  |

If one or both of the operands are pointers, they must be pointers to objects, not to functions. If both operands are pointers, the results are not meaningful unless both are pointers to objects in the same array.

Additive operators take operands of arithmetic, integral, and scalar types. These are defined in the following table.


The legal operand combinations:
arithmetic + arithmetic
scalar + integral
integral + scalar
arithmetic - arithmetic
scalar - scalar

Pointer Arithmetic
If one of the operands in an addition operation is a pointer to an array of objects, the other must be of integral type. The result is a pointer that is of the same type as the original pointer and that points to another array element.

If both operands are pointers, the result of subtraction is the difference (in array elements) between the operands. The subtraction expression yields a signed integral result of type ptrdiff_t (defined in the standard include file <stddef.h>).

One of the operands can be of integral type, as long as it is the second operand. The result of the subtraction is of the same type as the original pointer. The value of the subtraction is a pointer to the (n - i)th array element, where n is the element pointed to by the original pointer and i is the integral value of the second operand.


## Binary Arithmetic Multiplicative Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Multiplication | a * b Yes |
| Division | a / b Yes |
| Modulo | a % b | Yes |

The multiplicative operators take operands of arithmetic types and have left-to-right associativity.

The modulus operator (%) has a stricter requirement in that its operands must be of integral type. (To get the remainder of a floating-point division, use the run-time function, fmod.)

Division by 0 in either a division or a modulus expression is undefined and causes a run-time error. Therefore, the following expressions generate undefined, erroneous results

If both operands to a multiplication, division, or modulus expression have the same sign, the result is positive. Otherwise, the result is negative. The result of a modulus operation's sign is implementation-defined. In Microsoft C++, the result of a modulus expression is always the same as the sign of the first operand.

Since the conversions performed by the multiplicative operators do not provide for overflow or underflow conditions, information may be lost if the result of a multiplicative operation cannot be represented in the type of the operands after conversion.

The relationship between the multiplicative operators is given by the identity:

  (e1 / e2) * e2 + e1 % e2 == e1.

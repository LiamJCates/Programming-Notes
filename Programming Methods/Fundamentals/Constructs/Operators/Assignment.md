## Assignment
The assignment operator is a binary operator that assigns a value to a variable.

variable = expression;

In an assignment statement, the value of the expression should match the data type of the variable.

	int x = 5;

The expression on the right side is evaluated, and its value is assigned to the variable (and thus to a memory location) on the left side.
A variable is said to be initialized the first time a value is placed in the variable

This expression, called assignment chaining, is valid in many languages:

	x = y = z = 5;

It assigns 5 to the all three variables: x, y and z; always from right-to-left.

Along with the standard assignment operator, many languages provide compound assignment operators. These operators combine assignment with another binary operation. The operation is performed first, between the variable being assigned to on the left side of the operator and the variable being assigned on the right then the assignment operation occurs.

For exampled, the addition assignment operator (+=) adds the value of the right operand to a variable on the left, then assigns the result to the variable.

An assignment operator performs a given operation between operands and then assigns the result to the first operand.
## Compound Assignment

| expression	| equivalent to... |
|-------------|------------------|
| y += x;	| y = y + x; |
| x -= 5;	| x = x - 5; |
| x /= y;	| x = x / y; |
| x *= y; | x = x * y; |
| x %= y; | x = x % y; |
| x >>= y; | x = x >> y; |
| x <<= y; | x = x << y; |
| x &= y; | x = x & y; |
| x ^= y; | x = x ^ y; |
| x \|= y; | x = x \| y; |

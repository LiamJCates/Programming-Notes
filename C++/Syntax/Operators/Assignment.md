## Assignment
The assignment operator is a binary operator that assigns a value to a variable.

variable = expression;

In an assignment statement, the value of the expression should match the data type of the variable.

int x = 5;

The expression on the right side is evaluated, and its value is assigned to the variable (and thus to a memory location) on the left side.
A variable is said to be initialized the first time a value is placed in the variable

The following expression is also valid in C++:

x = y = z = 5;

It assigns 5 to the all three variables: x, y and z; always from right-to-left.


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

An assignment operator performs a given operation between operands and then assigns the result to the first operand.

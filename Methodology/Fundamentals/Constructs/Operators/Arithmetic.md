## Unary Arithmetic Operators
The unary plus + and unary minus - operators take a single arithmetic operand.
Both operators promote their operands to int. So, if the operand is of type bool, char, or short int, the result of the expression is an int.
Unary plus doesn’t do much besides promotion
unary minus flips the sign of the operand.


## Increment and Decrement

| expression	| equivalent to... |
|-------------|------------------|
| ++x | x = x + 1 |
| --x | x = x - 1 |
| x++ | x = x + 1 |
| x-- | x = x - 1 |

A peculiarity of this operator is that it can be used both as a prefix and as a suffix. In the case that the increase operator is used as a prefix (++x) of the value, the expression evaluates to the final value of x, once it is already increased. On the other hand, in case that it is used as a suffix (x++), the value is also increased, but the expression evaluates to the value that x had before being increased.

You often hear of cases where prefix increment or decrement
operators are preferred on grounds of better performance. That
is, ++startValue is preferred over startValue++.
This is true at least theoretically because with the postfix
operators, the compiler needs to store the initial value
temporarily in the event of it needing to be assigned. The effect
on performance in these cases is negligible with respect to
integers, but in the case of certain classes there might be a
point in this argument. Smart compilers may optimize away the
differences.

## Binary Arithmetic operators
The five arithmetical operations supported by C++ are:

| operator	| description |
|-----------|-------------|
| + | addition |
| - | subtraction |
| * | multiplication |
| / | division |
| % | modulo |

Built-in arithmetic operators perform mathematical computations.
These operators take two operands and perform the indicated
mathematical operation. Like their unary counterparts, these binary
operators cause integer promotion on their operands. For example, adding
two char operands will result in an int.

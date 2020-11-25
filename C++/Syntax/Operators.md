Unary operator: An operator that has only one operand.
Binary operator: An operator that has two operands.

When more than one arithmetic operator is used in an expression, C++ uses the operator precedence rules to evaluate the expression.

When operators have the same level of precedence, the operations are performed in a certain order.

These rules are listed later

To avoid confusion, you can use parentheses to group arithmetic
expressions.

## Assignment
The assignment operator assigns a value to a variable.

variable = expression;

In an assignment statement, the value of the expression should match the data type of the variable.

int x = 5;

The expression on the right side is evaluated, and its value is assigned to the variable (and thus to a memory location) on the left side.
A variable is said to be initialized the first time a value is placed in the variable

The following expression is also valid in C++:

x = y = z = 5;

It assigns 5 to the all three variables: x, y and z; always from right-to-left.




## Arithmetic operators
The five arithmetical operations supported by C++ are:

| operator	| description |
|-----------|-------------|
| + | addition |
| - | subtraction |
| * | multiplication |
| / | division |
| % | modulo |



## Bitwise operators
Bitwise operators modify variables considering the bit patterns that represent the values they store.

| operator | asm equivalent | description |
|----------|----------------|-------------|
| & | AND | Bitwise AND |
| \| | OR | Bitwise inclusive OR |
| ^ | XOR | Bitwise exclusive OR |
| ~ | NOT | Unary complement (bit inversion) |
| << | SHL | Shift bits left |
| >> | SHR | Shift bits right |




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

## Relational and comparison operators

| operator | description |
|----------|-------------|
| == | Equal to |
| != | Not equal to |
| < | Less than |
| > | Greater than |
| <= | Less than or equal to |
| >= | Greater than or equal to |



## Logical operators

| operator | description |
|----------|-------------|
| && | AND |
| \|\| | OR |
| ! | NOT |

Note that evaluation of an expression to true in C++ essentially
means that the expression does not evaluate to false, false
being zero. So, an expression that evaluates to any non-zero
number—negative or positive—is essentially considered to be
evaluating to true when used in a conditional statement.

Short circuit evaluation is the mechanism by which the second argument of a logical express is executed or evaluated only if the first argument does not suffice to determine the value of the expression.

This occurs when the first argument of an && expression is false or the first argument of an || expression is true.

in case you want to evaluate all expressions anyway you can use the & and | operators.



## Conditional ternary operator
The conditional operator evaluates an expression, returning one value if that expression evaluates to true, and a different one if the expression evaluates as false. Its syntax is:

condition ? result1 : result2




## Comma operator
The comma operator (,) is used to separate two or more expressions that are included where only one expression is expected. When the set of expressions has to be evaluated for a value, only the right-most expression is considered.

For example, the following code:
a = (b=3, b+2);

would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3.




## Explicit type casting operator
Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++. The simplest one, which has been inherited from the C language, is to precede the expression to be converted by the new type enclosed between parentheses (()):

int i;
float f = 3.14;
i = (int) f;


The previous code converts the floating-point number 3.14 to an integer value (3); the remainder is lost. Here, the typecasting operator was (int). Another way to do the same thing in C++ is to use the functional notation preceding the expression to be converted by the type and enclosing the expression between parentheses:

i = int (f);

Both ways of casting types are valid in C++.






## sizeof
The unary operator sizeof accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object:

x = sizeof (char);

Here, x is assigned the value 1, because char is a type with a size of one byte.

The sizeof operator always returns a size_t.

The value returned by sizeof is a compile-time constant, so it is always determined before program execution.




From greatest to smallest priority, C++ operators are evaluated in the following order:
| Level | Precedence group | Operator | Description | Grouping |
|-------|------------------|----------|-------------|----------|
| 1 | Scope | :: | scope qualifier | Left-to-right |
| 2 |	Postfix (unary) | ++ -- | postfix increment / decrement | Left-to-right |
|  |  | () | functional forms |  |
|  |  | [] | subscript |  |
|  |  | . -> | member access |  |
| 3 |	Prefix (unary) |	++ -- | prefix increment / decrement | Right-to-left |
|  |  | ~ ! |	bitwise NOT / logical NOT |  |
|  |  | + - | unary prefix |  |
|  |  | & * | reference / dereference |  |
|  |  | new delete | allocation / deallocation |  |
|  |  | sizeof | parameter pack |  |
|  |  | (type) | C-style type-casting |  |
| 4 | Pointer-to-member | .* ->* | access pointer | Left-to-right |
| 5 | Arithmetic: scaling | * / % | multiply, divide, modulo | Left-to-right |
| 6 | Arithmetic: addition | + - | addition, subtraction | Left-to-right |
| 7 | Bitwise shift | << >> | shift left, shift right | Left-to-right |
| 8 | Relational | < > <= >= | comparison operators | Left-to-right |
| 9 | Equality | == != | equality / inequality | Left-to-right |
| 10 | And | & | bitwise AND | Left-to-right |
| 11 | Exclusive or | ^	| bitwise XOR | Left-to-right |
| 12 | Inclusive or | \| | bitwise OR | Left-to-right |
| 13 | Conjunction | && | logical AND | Left-to-right |
| 14 | Disjunction | \|\|	| logical OR | Left-to-right |
| 15 | Assignment-level expressions | = *= /= %= += -= | assignment / compound assignment | Right-to-left |
|  |  | >>= <<= &= ^= \|= | | |
| | | ?: | conditional operator | |
| 16 | Sequencing | , | comma separator | Left-to-right |

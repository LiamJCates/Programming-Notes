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

## Unary Arithmetic Operators
The unary plus + and unary minus - operators take a single arithmetic operand.
Both operators promote their operands to int. So, if the operand is of type bool, char, or short int, the result of the expression is an int.
Unary plus doesn’t do much besides promotion
unary minus flips the sign of the operand.

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

bitwise logical operators work on integral types and perform a
Boolean operation at the bit level and returns an integral type matching
its operands.


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

Comparison operators compare the given operands and evaluate to a
bool

## Logical operators

| operator | description |
|----------|-------------|
| && | AND |
| \|\| | OR |
| ! | NOT |


logical operators take bool-convertible operands and return an object of
type bool.


Note that evaluation of an expression to true in C++ essentially
means that the expression does not evaluate to false, false
being zero. So, an expression that evaluates to any non-zero
number—negative or positive—is essentially considered to be
evaluating to true when used in a conditional statement.

Short circuit evaluation is the mechanism by which the second argument of a logical express is executed or evaluated only if the first argument does not suffice to determine the value of the expression.

This occurs when the first argument of an && expression is false or the first argument of an || expression is true.

in case you want to evaluate all expressions anyway you can use the & and | operators.



## Member Access Operators
member access operators are used to interact with pointers, arrays, and many of the classes.
The six such operators include subscript [], indirection *, address-of &, member-of-object ., and member-of-pointer ->.

There are also pointer-to-member-of-object .* and pointer-to-member-of-pointer ->* operators, but these are uncommon.



## Conditional ternary operator
The conditional operator evaluates an expression, returning one value if that expression evaluates to true, and a different one if the expression evaluates as false. Its syntax is:

condition ? result1 : result2




## Comma operator
The comma operator (,) is used to separate two or more expressions that are included where only one expression is expected.  The comma operator allows several expressions separated by commas to be evaluated within a larger expression. The expressions evaluate from left to right, and the rightmost expression is the return value

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




## Operator Precedence and Associativity
When more than one operator appears in an expression, operator precedence
and operator associativity decide how the expression parses. Operators with
higher precedence are bound tighter to their arguments than operators
with lower precedence. If two operators have the same precedence, their
associativity breaks the tie to decide how arguments bind. Associativity is
either left to right or right to left.

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









Evaluation Order
Evaluation order determines the execution sequence of operators in an
expression. A common misconception is that precedence and evaluation
order are equivalent: they are not. Precedence is a compile time concept that
drives how operators bind to operands. Evaluation order is a runtime concept that drives the scheduling of operator execution.
In general, C++ has no clearly specified execution order for operands. Although
operators bind to operands in the well-defined way explained in the preceding sections, those operands evaluate in an undefined order. The compiler can order operand evaluation however it likes.
You might be tempted to think that the parentheses in the following
expression drive evaluation order for the functions stop, drop, and roll, or
that some left-to-right associativity has some runtime effect:
(stop() + drop()) + roll()
They do not. The roll function might execute before, after, or between
evaluations of stop and drop. If you require operations to execute in a specific
order, simply place them into separate statements in the desired sequence,
as shown here:
auto result = stop();
result = result + drop();
result = result + roll();
If you aren’t careful, you can even get undefined behavior. Consider the
following expression:
b = ++a + a;
Because the ordering of the expressions ++a and a is not specified, and
because the value of ++a + a depends on which expression evaluates first,
the value of b cannot be well defined.
In some special situations, execution order is specified by the language.
The most commonly encountered scenarios are as follows:
•	 The built-in logical AND operator a && b and built-in logical OR operator a || b guarantee that a executes before b.
•	 The ternary operator a ? b : c guarantees that a executes before
b and c.
•	 The comma operator a, b guarantees that a executes before b.
•	 The constructor arguments in a new expression evaluate before the call
to the allocator function.
You might be wondering why C++ doesn’t enforce execution order,
say from left to right, to avoid confusion. The answer is simply that by not
arbitrarily constraining execution order, the language is allowing compiler
writers to find clever optimization opportunities.

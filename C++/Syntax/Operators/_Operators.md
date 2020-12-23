Operators, such as the addition (+) and address-of (&) operators, do work
on arguments called operands, such as numerical values or objects to produce some value.

For more information about Operators see:
[Programming Methods\Fundamentals\Constructs\Operators]


## Operator Precedence and Associativity
When more than one operator appears in an expression, operator precedence
and operator associativity decide how the expression parses.

Operators with higher precedence are bound tighter to their arguments than operators with lower precedence. If two operators have the same precedence, their
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









## Evaluation Order
When operators have the same level of precedence, the operations are performed in a certain order.


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

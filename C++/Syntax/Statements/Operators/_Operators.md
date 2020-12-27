Operators, such as the addition (+) and address-of (&) operators, do work
on arguments called operands, such as numerical values or objects to produce some value.

For General information about Operators see:
[Programming Methods\Fundamentals\Constructs\Operators]

For information about C++ Operator Overloading see:
[C++\Syntax\Overloading\_Overloading.md]

C++ Operators

Arithmetic Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Basic assignment | a = b | Yes |
| Addition | a + b | Yes |
| Subtraction | a - b | Yes  |
| Unary Plus | +a | Yes |
| Unary Minus | -a | Yes |
| Multiplication | a * b Yes |
| Division | a / b Yes |
| Modulo | a % b | Yes |
| Prefix Increment  ++a | Yes |
| Postfix Increment  a++ | Yes |
| Prefix Decrement  --a | Yes |
| Postfix Decrement  a-- | Yes |

Relational Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Equal to | a == b | Yes |
| Not Equal To | a != b | Yes |
| Greater Than | a > b | Yes |
| Less Than | a < b | Yes |
| Greater Than or Equal | a >= b | Yes |
| Less Than or Equal | a <= b | Yes |

Logical Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| NOT | !a | Yes |
| AND | a && b | Yes |
| OR | a \|\| b | Yes |

Bitwise Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Bitwise NOT | ~a | Yes |
| Bitwise AND | a & b | Yes |
| Bitwise OR | a \| b | Yes |
| Bitwise XOR | a ^ b | Yes |
| Bitwise left shift | a << b | Yes |
| Bitwise right shift | a >> b | Yes |

Compound Assignment Operators
| Name | Syntax | Meaning | Overloadable |
|------|--------|---------|--------------|
| Addition Assignment | a += b | a = a + b | Yes |
| Subtraction Assignment | a +-= b | a = a - b | Yes |
| Multiplication Assignment | a *= b | a = a * b | Yes |
| Division Assignment | a /= b | a = a / b | Yes |
| Modulo Assignment | a %= b | a = a % b | Yes |
| Bitwise AND Assignment | a &= b | a = a & b | Yes |
| Bitwise OR Assignment | a \|= b | a = a \| b | Yes |
| Bitwise XOR Assignment | a ^= b | a = a ^ b | Yes |
| Bitwise left shift Assignment | a <<= b | a = a << b | Yes |
| Bitwise right shift Assignment | a >>= b | a = a >> b | Yes |

Member and Pointer Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Subscript | a[b] | Yes |
| Indirection | *a | Yes |
| Address-of | &a Yes |
| Structure Dereference | a->b | Yes |
| Structure Reference | a.b | Yes |
| Member selected by pointer-to-member b of object pointed to by a | a->*b | Yes |
| Member of object a selected by pointer-to-member b | a.*b | Yes |


Other Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Function Call | a(Args) | Yes |
| Comma | a, b | Yes |
| Ternary Conditional | a ? b : c | No |
| Scope Resolution | a::b | No |
| User Defined Literal | "a"_b | Yes |
| sizeof VariableType | sizeof(a) | Yes |
| sizeof Type | sizeof(type) | Yes |
| sizeof parameter pack | sizeof...(Args) No |
| alignof | alignof(type) | No |
| type identification | typeid(type) |
| type identification of Varible | typeid(a) |
| C-Style Conversion | (type)a | Yes |
| Conversion | type(a) | No |
| static_cast | static_cast<type>(a) | Yes |
| dynamic_cast | dynamic_cast<type>(a) | No |
| const_cast | const_cast<type>(a) | No |
| reinterpret_cast | reinterpret_cast<type>(a) | No |  |
| Allocate storage | new type | Yes |
| Allocate array storage new type[n] | Yes |
| Deallocate storage | delete a | Yes |
| Deallocate array storage | delete[] a Yes |
| Exception check | noexcept(a) | No |



## Operator Aliases
C++ defines keywords to act as aliases for a number of operators:

|Keyword | Operator |
|-------|----------|
| and | && |
| and_eq | &= |
| bitand | & |
| bitor | \| |
| compl | ~ |
| not | ! |
| not_eq | != |
| or | \|\| |
| or_eq \| |= |
| xor | ^ |
| xor_eq | ^= |




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

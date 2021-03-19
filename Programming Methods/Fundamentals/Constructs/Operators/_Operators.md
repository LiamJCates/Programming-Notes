In mathematics, an operation is a mathematical calculation involving zero or more input values (called operands) that produces a new value (called an output value). The specific operation to be performed is denoted by a construct (typically a symbol or pair of symbols) called an operator.

In computer programming, operators are constructs defined within programming languages which behave generally like functions, but which differ syntactically or semantically.


Operation Types
  Binary:
    Assignment
    Arithmetic
    Relational
    Logical
    Bitwise

  Unary:
    Arithmetic
    Bitwise

  Ternary
    Conditional



Operands
In computing, an operand is the part of a computer instruction which specifies what data is to be manipulated or operated on, while at the same time representing the data itself.

For example, a computer instruction describes an operation such as add or multiply, while the operand(s) specify which element, e, to operate as well as the value of e.


Operator Position
The position of the operator with respect to its operands may be prefix, infix or postfix.
  infix: Infix notation is the notation commonly used in arithmetical and logical formulae and statements. It is characterized by the placement of operators between operands

  prefix: also known as Polish notation (PN), normal Polish notation (NPN), Warsaw notation, Polish prefix notation or simply prefix notation, is a mathematical notation in which operators precede their operands

  postfix: also known as  Reverse Polish notation (RPN), Polish postfix notation or simply postfix notation, is a mathematical notation in which operators follow their operands.



Arity
The syntax of an expression involving an operator depends on its arity (number of operands), precedence, and (if applicable), associativity.

Unary operator: An operator that has only one operand.
Binary operator: An operator that has two operands.
Ternary operator: An operator that has three operands.

Most programming languages support a standard variety of binary operators and a few unary operators, with some supporting more operands, such as the ? : operator, which is ternary.

Binary
A binary operator requires two operands, one before the operator and one after the operator:

operand1 operator operand2

For example, 3+4 or x*y.

Unary
A unary operator requires a single operand, either before or after the operator:

operator operand

or

operand operator

For example, x++ or ++x.



Operand Coercion
Some languages also allow for the operands of an operator to be implicitly converted, or coerced, to suitable data types for the operation to occur. For example, in Perl coercion rules lead into 12 + "3.14" producing the result of 15.14. The text "3.14" is converted to the number 3.14 before addition can take place. Further, 12 is an integer and 3.14 is either a floating or fixed-point number (a number that has a decimal place in it) so the integer is then converted to a floating point or fixed-point number respectively.


Evaluating Operators
When more than one operator appears in an expression, operator precedence
and operator associativity decide how the expression parses.

Operators with higher precedence are bound tighter to their arguments than operators with lower precedence. If two operators have the same precedence, their
associativity breaks the tie to decide how arguments bind. Associativity is
either left to right or right to left

To avoid confusion, you can use parentheses to group arithmetic expressions.

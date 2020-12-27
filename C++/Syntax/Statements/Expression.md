Expressions are computations that produce results and side effects. Generally, expressions contain operands and operators that do work on them.

C++ distinguishes between expressions and statements. Very casually, we could say that every expression becomes a statement if semicolon terminated.

Expression statements comprise most of the statements in a program. You can turn any expression into a statement, which you should do whenever you need to evaluate an expression but want to discard the result. Of course, this is only useful if evaluating that expression causes a side effect


Expressions
  variable names
  constant names
  literal values
  other expressions combined by an operator
  assignment



Input and output operations such as:

std::cout ≪ "x is " ≪ x ≪ "\n"

are also expressions.

A function call with expressions as arguments is an expression, e.g., abs(x) or abs(x * y + z). Therefore, function calls can be nested: pow(abs(x), y). Note that nesting would not be possible if function calls were statements.

Since assignment is an expression, it can be used as an argument of a function: abs(x= y). Or I/O operations such as those above, e.g.:

print(std::cout ≪ "x is " ≪ x ≪ "\n", "I am such a nerd!");

Needless to say this is not particularly readable and it would cause more confusion than doing something useful.

An expression surrounded by parentheses is an expression as well, e.g., (x + y). As this grouping by parentheses precedes all operators, we can change the order of evaluation to suit our needs: x * (y + z) computes the addition first.

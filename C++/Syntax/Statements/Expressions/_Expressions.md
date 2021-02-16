An expression is a sequence of operators and their operands, that specifies a computation.

When an expression is executed, each of the terms in the expression is evaluated until a single value remains (this process is called evaluation).

Wherever you can use a single value in C++, you can use an expression instead, and the compiler will evaluate the expression and resolve to a single value. That single value is called the result of the expression.

Expressions do not end in a semicolon, and cannot be compiled by themselves and are always evaluated as part of statements.

Some common expression evaluations include:
  literals evaluate to their own values.
  Variables evaluate to the value of the variable.
  Function calls evaluate whatever value the function returns.
  Operators let us combine multiple values together to produce a new value.



Expressions are formed from atomic pieces called Primary Expressions and various Operators.

Expression evaluation may produce a result (e.g., evaluation of 2+2 produces the result 4) and may generate side-effects (e.g. evaluation of std::printf("%d",4) prints the character '4' on the standard output).

C++ distinguishes between expressions and statements. Very casually, we could say that every expression becomes a statement if semicolon terminated.

Expression statements comprise most of the statements in a program. You can turn any expression into a statement, which you should do whenever you need to evaluate an expression but want to discard the result. Of course, this is only useful if evaluating that expression causes a side effect

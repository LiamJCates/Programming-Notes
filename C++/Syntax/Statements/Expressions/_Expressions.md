An expression is a sequence of operators and their operands, that specifies a computation.

Expressions are formed from atomic pieces called Primary Expressions and various Operators.

Expression evaluation may produce a result (e.g., evaluation of 2+2 produces the result 4) and may generate side-effects (e.g. evaluation of std::printf("%d",4) prints the character '4' on the standard output).

General
  value categories (lvalue, rvalue, glvalue, prvalue, xvalue) classify expressions by their values
  order of evaluation of arguments and subexpressions specify the order in which intermediate results are obtained


C++ distinguishes between expressions and statements. Very casually, we could say that every expression becomes a statement if semicolon terminated.

Expression statements comprise most of the statements in a program. You can turn any expression into a statement, which you should do whenever you need to evaluate an expression but want to discard the result. Of course, this is only useful if evaluating that expression causes a side effect

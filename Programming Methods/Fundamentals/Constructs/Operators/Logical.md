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

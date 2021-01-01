## Comma operator
The comma operator (,) is used to separate two expressions that are included where only one expression is expected.

The comma operator has left-to-right associativity. Two expressions separated by a comma are evaluated left to right and the rightmost expression is the value of the expression. The left operand is always evaluated, and all side effects are completed before the right operand is evaluated.

The comma operator allows several expressions separated by commas to be evaluated within a larger expression.

For example, the following code:
  a = (b=3, b+2);

would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3.

If you want to use comma-as-operator within a single function argument, variable assignment, or other comma-separated list, you need to use parentheses:

  int a = 1, b = 2, weirdVariable = (++a, b), d = 4;


Commas can be used as separators in some contexts, such as function argument lists. Do not confuse the use of the comma as a separator with its use as an operator; the two uses are completely different.

Consider the expression e1, e2. The type and value of the expression are the type and value of e2; the result of evaluating e1 is discarded. The result is an l-value if the right operand is an l-value.

Where the comma is normally used as a separator (for example in actual arguments to functions or aggregate initializers), the comma operator and its operands must be enclosed in parentheses.

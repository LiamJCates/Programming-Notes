## Comma operator
The comma operator (,) is used to separate two or more expressions that are included where only one expression is expected. The comma operator allows several expressions separated by commas to be evaluated within a larger expression. The expressions evaluate from left to right, and the rightmost expression is the return value

For example, the following code:
  a = (b=3, b+2);

would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3.

If you want to use comma-as-operator within a single function argument, variable assignment, or other comma-separated list, you need to use parentheses:

  int a = 1, b = 2, weirdVariable = (++a, b), d = 4;

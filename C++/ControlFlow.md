Conditional Statements

if (boolean-expression) statement;

An if statement contains a Boolean expression and one or more nested
statements. Depending on whether the Boolean evaluates to true or false,
the program decides which nested statement to execute.

The statement could be a single statement followed by a semicolon or a block statement.

if (boolean-expression-1) statement-1
else if (boolean-expression-2) statement-2
else statement-3

if a Boolean expression evaluates to true the associated statement is executed, if neither do the optional else statement is executed.

You can include any number of else if clauses or omit them entirely.




Functions

Functions are blocks of code that accept input and return output to their callers.
input objects called are called parameters or arguments output objects


return-type function_name(par-type1 par_name1, ..., par-typeN par_nameN) {
  //statements
  return return-value;
}

To call (or invoke) a function, you use the name of the desired function, parentheses, and a comma-separated list of the required parameters.

The compiler reads files from top to bottom, so the function’s declaration must appear before its point of first use.

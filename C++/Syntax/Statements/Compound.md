To permit more complex statements, C++ provides a structure called a compound statement, also called a block or block statement.

A compound statement is a group of zero or more statements that is treated by the compiler as if it were a single statement. Blocks can be used anywhere a single statement is allowed.

In C++, such statements are a sequence of statements delimited by curly braces {...}. No semicolon is needed at the end of a block.

Compound statement syntax:

  {
    statement_1
    statement_2
    ...
    statement_n
  }

Compound statements do more than simply group multiple statements into a single statement. You can also group definitions within the block. Any variable that you define in a block is visible only within the confines of the block. The region where you can use a variable is known as the variable’s scope. 

If Statements

An if statement consists of a boolean expression followed by one statement or multiple statements delimited by braces.
```c
if(boolean_expression) {
   /* statement(s) will execute if the boolean expression is true */
}
```
If the Boolean expression evaluates to true, then the block of code inside the 'if' statement will be executed. If the Boolean expression evaluates to false, then the first set of code after the end of the 'if' statement (after the closing curly brace) will be executed.

C programming language assumes any non-zero and non-null values as true and if it is either zero or null, then it is assumed as false value.


if...else statement
An if statement can be followed by an optional else statement, which executes when the Boolean expression is false.
```c
if(boolean_expression) {
   /* statement(s) will execute if the boolean expression is true */
} else {
   /* statement(s) will execute if the boolean expression is false */
}
```
an else is associated with the closest "else-less" if in the same code block/ scope

To ensure an else is associated with the proper if use braces

When a multi-way decision has no default action, the final else may be used for
error checking of impossible values.


If...else if...else Statement

An if statement can be followed by an optional else if...else statement, which is very useful to test various conditions using single if...else if statement.

When using if...else if..else statements, there are few points to keep in mind −

    An if can have zero or one else's and it must come after any else if's.

    An if can have zero to many else if's and they must come before the else.

    Once an else if succeeds, none of the remaining else if's or else's will be tested.

Syntax

The syntax of an if...else if...else statement in C programming language is −
```c
if(boolean_expression 1) {
   /* Executes when the boolean expression 1 is true */
} else if( boolean_expression 2) {
   /* Executes when the boolean expression 2 is true */
} else if( boolean_expression 3) {
   /* Executes when the boolean expression 3 is true */
} else {
   /* executes when the none of the above condition is true */
}
```

nested if statements
You can use one if or else if statement inside another if or else if statement(s).

The syntax for a nested if statement is as follows −
```c
if( boolean_expression 1) {

   /* Executes when the boolean expression 1 is true */
   if(boolean_expression 2) {
      /* Executes when the boolean expression 2 is true */
   }
}
```

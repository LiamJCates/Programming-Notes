




If Statements

if statement
An if statement consists of a boolean expression followed by one or more statements.

if(boolean_expression) {
   /* statement(s) will execute if the boolean expression is true */
}

If the Boolean expression evaluates to true, then the block of code inside the 'if' statement will be executed. If the Boolean expression evaluates to false, then the first set of code after the end of the 'if' statement (after the closing curly brace) will be executed.

C programming language assumes any non-zero and non-null values as true and if it is either zero or null, then it is assumed as false value.


if...else statement
An if statement can be followed by an optional else statement, which executes when the Boolean expression is false.

if(boolean_expression) {
   /* statement(s) will execute if the boolean expression is true */
} else {
   /* statement(s) will execute if the boolean expression is false */
}


If...else if...else Statement

An if statement can be followed by an optional else if...else statement, which is very useful to test various conditions using single if...else if statement.

When using if...else if..else statements, there are few points to keep in mind −

    An if can have zero or one else's and it must come after any else if's.

    An if can have zero to many else if's and they must come before the else.

    Once an else if succeeds, none of the remaining else if's or else's will be tested.

Syntax

The syntax of an if...else if...else statement in C programming language is −

if(boolean_expression 1) {
   /* Executes when the boolean expression 1 is true */
} else if( boolean_expression 2) {
   /* Executes when the boolean expression 2 is true */
} else if( boolean_expression 3) {
   /* Executes when the boolean expression 3 is true */
} else {
   /* executes when the none of the above condition is true */
}


nested if statements
You can use one if or else if statement inside another if or else if statement(s).

The syntax for a nested if statement is as follows −

if( boolean_expression 1) {

   /* Executes when the boolean expression 1 is true */
   if(boolean_expression 2) {
      /* Executes when the boolean expression 2 is true */
   }
}

















Switch Statements

switch statement
A switch statement allows a variable to be tested for equality against a list of values.

switch(expression) {
  case constant-expression  :
    statement(s);
    break; /* optional */

  case constant-expression  :
    statement(s);
    break; /* optional */

  /* you can have any number of case statements */
  default : /* Optional */
  statement(s);
}

The following rules apply to a switch statement −

The expression used in a switch statement must have an integral or enumerated type, or be of a class type in which the class has a single conversion function to an integral or enumerated type.

You can have any number of case statements within a switch. Each case is followed by the value to be compared to and a colon.

The constant-expression for a case must be the same data type as the variable in the switch, and it must be a constant or a literal.

When the variable being switched on is equal to a case, the statements following that case will execute until a break statement is reached.

When a break statement is reached, the switch terminates, and the flow of control jumps to the next line following the switch statement.

Not every case needs to contain a break. If no break appears, the flow of control will fall through to subsequent cases until a break is reached.

A switch statement can have an optional default case, which must appear at the end of the switch. The default case can be used for performing a task when none of the cases is true. No break is needed in the default case.


nested switch statements
You can use one switch statement inside another switch statement(s).

char c1 = 'A';
char c2 = 'B';

switch(c1) {

  case 'A':
    printf("This A is part of outer switch" );

    switch(c2) {
      case 'A':
        printf("This A is part of inner switch" );
        break;
      case 'B': /* case code */
    }

    break;
  case 'B':
    /* case code */
    break;
  default:
    /* case code */
}





The ? : Operator

We have covered conditional ternary operator ? : in the previous chapter which can be used to replace if...else statements. It has the following general form −

Exp1 ? Exp2 : Exp3;

Where Exp1, Exp2, and Exp3 are expressions. Notice the use and placement of the colon.

The value of a ? expression is determined like this −

    Exp1 is evaluated. If it is true, then Exp2 is evaluated and becomes the value of the entire ? expression.

    If Exp1 is false, then Exp3 is evaluated and its value becomes the value of the expression.










Loops

You may encounter situations, when a block of code needs to be executed several number of times. In general, statements are executed sequentially: The first statement in a function is executed first, followed by the second, and so on.

Programming languages provide various control structures that allow for more complicated execution paths.

A loop statement allows us to execute a statement or group of statements multiple times. The executed statement may be a single statement or a block of statements.

loops iterate while some condition is true.
The condition may be any expression, and true is any nonzero value.


while loop
Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.

while(condition) {
   statement(s);
}





for loop
Executes a sequence of statements multiple times and abbreviates the code that manages the loop variable.


for(initialization; test condition; increment){
  //loop statements
}

Here is the flow of control in a 'for' loop −

    The init step is executed first, and only once. This step allows you to declare and initialize any loop control variables. You are not required to put a statement here, as long as a semicolon appears.

    Next, the condition is evaluated. If it is true, the body of the loop is executed. If it is false, the body of the loop does not execute and the flow of control jumps to the next statement just after the 'for' loop.

    After the body of the 'for' loop executes, the flow of control jumps back up to the increment statement. This statement allows you to update any loop control variables. This statement can be left blank, as long as a semicolon appears after the condition.

    The condition is now evaluated again. If it is true, the loop executes and the process repeats itself (body of loop, then increment step, and then again condition). After the condition becomes false, the 'for' loop terminates.




do...while loop
It is more like a while statement, except that it tests the condition at the end of the loop body.

do {
   statement(s);
} while( condition );

Notice that the conditional expression appears at the end of the loop, so the statement(s) in the loop executes once before the condition is tested.

If the condition is true, the flow of control jumps back up to do, and the statement(s) in the loop executes again. This process repeats until the given condition becomes false.




nested loops
You can use one or more loops inside any other while, for, or do..while loop.


The syntax for a nested for loop statement in C is as follows −

for ( init; condition; increment ) {

   for ( init; condition; increment ) {
      statement(s);
   }
   statement(s);
}

The syntax for a nested while loop statement in C programming language is as follows −

while(condition) {

   while(condition) {
      statement(s);
   }
   statement(s);
}

The syntax for a nested do...while loop statement in C programming language is as follows −

do {
   statement(s);

   do {
      statement(s);
   }while( condition );

}while( condition );

A final note on loop nesting is that you can put any type of loop inside any other type of loop. For example, a 'for' loop can be inside a 'while' loop or vice versa.







the grammatical rules of C require that a for and while
statement have a body. The isolated semicolon, called a null statement, can satisfy that requirement. It can be put on a separate line to make it visible.




Loop Control Statements

Loop control statements change execution from its normal sequence. When execution leaves a scope, all automatic objects that were created in that scope are destroyed.

C supports the following control statements.

break statement
Terminates the loop or switch statement and transfers execution to the statement immediately following the loop or switch.


continue statement
Causes the loop to skip the remainder of its body and immediately retest its condition prior to reiterating.


goto statement
Transfers control to the labeled statement.






The Infinite Loop

A loop becomes an infinite loop if a condition never becomes false. The for loop is traditionally used for this purpose. Since none of the three expressions that form the 'for' loop are required, you can make an endless loop by leaving the conditional expression empty.

#include <stdio.h>

int main () {

   for( ; ; ) {
      printf("This loop will run forever.\n");
   }

   return 0;
}

When the conditional expression is absent, it is assumed to be true. You may have an initialization and increment expression, but C programmers more commonly use the for(;;) construct to signify an infinite loop.

NOTE − You can terminate an infinite loop by pressing Ctrl + C keys.

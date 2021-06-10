Loops

You may encounter situations, when a block of code needs to be executed several number of times. In general, statements are executed sequentially: The first statement in a function is executed first, followed by the second, and so on.

Programming languages provide various control structures that allow for more complicated execution paths.

A loop statement allows us to execute a statement or group of statements multiple times. The executed statement may be a single statement or a block of statements.

loops iterate while some condition is true.
The condition may be any expression, and true is any nonzero value.


#### while loop
Repeats a statement or group of statements while a given condition is true. It tests the condition before executing the loop body.
```c
while(condition) {
   statement(s);
}
```




### for loop
Executes a sequence of statements multiple times and abbreviates the code that manages the loop variable.

```c
for(initialization; test condition; increment){
  //loop statements
}
```

Here is the flow of control in a 'for' loop −

    The init step is executed first, and only once. This step allows you to declare and initialize any loop control variables. You are not required to put a statement here, as long as a semicolon appears.

    Next, the condition is evaluated. If it is true, the body of the loop is executed. If it is false, the body of the loop does not execute and the flow of control jumps to the next statement just after the 'for' loop.

    After the body of the 'for' loop executes, the flow of control jumps back up to the increment statement. This statement allows you to update any loop control variables. This statement can be left blank, as long as a semicolon appears after the condition.

    The condition is now evaluated again. If it is true, the loop executes and the process repeats itself (body of loop, then increment step, and then again condition). After the condition becomes false, the 'for' loop terminates.




#### do...while loop
It is more like a while statement, except that it tests the condition at the end of the loop body.
```c
do {
   statement(s);
} while( condition );
```
Notice that the conditional expression appears at the end of the loop, so the statement(s) in the loop executes once before the condition is tested.

If the condition is true, the flow of control jumps back up to do, and the statement(s) in the loop executes again. This process repeats until the given condition becomes false.




#### nested loops
You can use one or more loops inside any other while, for, or do..while loop.


The syntax for a nested for loop statement in C is as follows −
```c
for ( init; condition; increment ) {

   for ( init; condition; increment ) {
      statement(s);
   }
   statement(s);
}
```
The syntax for a nested while loop statement in C programming language is as follows −
```c
while(condition) {

   while(condition) {
      statement(s);
   }
   statement(s);
}
```
The syntax for a nested do...while loop statement in C programming language is as follows −
```c
do {
   statement(s);

   do {
      statement(s);
   }while( condition );

}while( condition );
```
A final note on loop nesting is that you can put any type of loop inside any other type of loop. For example, a 'for' loop can be inside a 'while' loop or vice versa.

#### null statement
the grammatical rules of C require that a for and while statement have a body. The isolated semicolon, called a null statement, can satisfy that requirement. It can be put on a separate line to make it visible.


#### Loop Control Statements

Loop control statements change execution from its normal sequence. When execution leaves a scope, all automatic objects that were created in that scope are destroyed.

C supports the following control statements.

break statement
Terminates the innermost enclosing loop or switch statement and transfers execution to the statement immediately following that loop or switch.
```c
break;
```
continue statement
Causes the loop to skip the remainder of its body and immediately retest its condition prior to reiterating.
```c
continue;
```

goto statement
Transfers control to the labeled statement.

The syntax for a goto statement in C is as follows −
```c
goto label;
...
label: statement;
```
Here label can be any plain text except C keyword and it can be set anywhere in the C program above or below to goto statement.

Formally, the goto is never necessary, and in practice it is almost always easy to write code without it

The most common use of goto is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once. The break statement cannot be used directly since it only exits from the innermost loop.

A label has the same form as a variable name, and is followed by a colon. It can be attached to any statement in the same function as the goto. The scope of a label is the entire function.

Code involving a goto can always be written without one, though perhaps at the price of some repeated tests or an extra variable






#### The Infinite Loop

A loop becomes an infinite loop if a condition never becomes false. The for loop is traditionally used for this purpose. Since none of the three expressions that form the 'for' loop are required, you can make an endless loop by leaving the conditional expression empty.

```c
#include <stdio.h>

int main () {

   for( ; ; ) {
      printf("This loop will run forever.\n");
   }

   return 0;
}
```

When the conditional expression is absent, it is assumed to be true. You may have an initialization and increment expression, but C programmers more commonly use the for(;;) construct to signify an infinite loop.

NOTE − You can terminate an infinite loop by pressing Ctrl + C keys.

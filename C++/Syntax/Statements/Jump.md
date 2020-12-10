## Jump Statements
Jump statements, including the break, continue, and goto statements, transfer
control flow. Unlike selection statements, jump statements are not conditional. You should avoid using them because they can almost always
be replaced with higher-level control structures.

### break
The break statement terminates execution of the enclosing iteration or
switch statement. Once break completes, execution transfers to the statement
immediately following the for, range-based for, while, do-while, or switch
statement.

The break statement is typically used for two purposes:
  To exit early from a loop.
  To skip the remainder of the switch structure.
After the break statement executes, the program continues to execute with the first statement after the structure. The use of a break statement in a loop can eliminate the use of certain (flag) variables.

The break statement is an effective way to avoid extra variables to control a loop
and produce an elegant code. However, break statements must be used very sparingly
within a loop. An excessive use of these statements in a loop will produce spaghetti-code
(loops with many exit conditions) that can be very hard to understand and manage. You
should be extra careful in using break statements and ensure that the use of the break
statements makes the code more readable and not less readable. If you’re not sure, don’t
use break statements.

### continue
The continue statement skips the remainder of an enclosing iteration statement and continues with the next iteration.

The continue statement is used in while, for, and do...while structures.

In a while and do...while structure, the expression (that is, the loop-continue test) is evaluated immediately after the continue statement. In a for structure, the update statement is executed after the continue statement, and then the loop condition (that is, the loop-continue test) executes.


### goto
The goto statement is an unconditional jump. The target of a goto statement
is a label.

Labels
Labels are identifiers you can add to any statement. Labels give statements
a name, and they have no direct impact on the program. To assign a label,
prepend a statement with the desired name of the label followed by a
semicolon.

goto instructs execution to continue from a particular, labeled,
point in code. You can use it to go backward and re-execute certain statements.

Syntax:
SomeFunction()
{
  Start: //Label
  CodeThatRepeats;
  goto Start;
}

In modern C++, there is no good role for goto statements. Don’t use them.

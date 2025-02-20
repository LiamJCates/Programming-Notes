### break
Causes the enclosing for, range-for, while or do-while loop or switch statement to terminate.

Used when it is otherwise awkward to terminate the loop using the condition expression and conditional statements.

Syntax
attr(optional) break ; 		

After this statement the control is transferred to the statement immediately following the enclosing loop or switch. As with any block exit, all automatic storage objects declared in enclosing compound statement or in the condition of a loop/switch are destroyed, in reverse order of construction, before the execution of the first line following the enclosing loop.

Notes
A break statement cannot be used to break out of multiple nested loops. The goto statement may be used for this purpose.


The break statement is an effective way to avoid extra variables to control a loop and produce an elegant code. However, break statements must be used very sparingly within a loop. An excessive use of these statements in a loop will produce spaghetti-code (loops with many exit conditions) that can be very hard to understand and manage. You should be extra careful in using break statements and ensure that the use of the break statements makes the code more readable and not less readable. If you’re not sure, don’t use break statements.

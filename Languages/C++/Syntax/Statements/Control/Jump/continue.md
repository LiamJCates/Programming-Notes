### continue
Causes the remaining portion of the enclosing for, range-for, while or do-while loop body to be skipped.

Used when it is otherwise awkward to ignore the remaining portion of the loop using conditional statements.

Syntax
attr(optional) continue ; 		

Explanation
The continue statement causes a jump, as if by goto to the end of the loop body (it may only appear within the loop body of for, range-for, while, and do-while loops).

In a while and do...while structure, the expression (that is, the loop-continue test) is evaluated immediately after the continue statement. In a for structure, the update statement is executed after the continue statement, and then the loop condition (that is, the loop-continue test) executes.

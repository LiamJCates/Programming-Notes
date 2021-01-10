### do while
Executes a statement repeatedly, until the value of expression becomes false. The test takes place after each iteration.

Syntax

attr(optional) do statement while ( expression ) ; 		

where
attr(C++11): is any number of attributes

expression: is any expression which is contextually convertible to bool. This expression is evaluated after each iteration, and if it yields false, the loop is exited.

statement: is any statement, typically a compound statement, which is the body of the loop
Explanation

statement is always executed at least once, even if expression always yields false. If it should not execute in this case, a while or for loop may be used.

If the execution of the loop needs to be terminated at some point, a break statement can be used as terminating statement.

If the execution of the loop needs to be continued at the end of the loop body, a continue statement can be used as shortcut. 

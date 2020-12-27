## Jump Statements

Jump statements transfer control flow. Unlike selection statements, jump statements are not conditional. You should avoid using them because they can almost always be replaced with higher-level control structures.

(1) attr(optional) break ;
(2) attr(optional) continue ;
(3) attr(optional) return expression(optional) ;
(4) attr(optional) return braced-init-list ; (since C++11)
(5) attr(optional) goto identifier ;

1) break statement;
2) continue statement;
3) return statement with an optional expression;
4) return statement using list initialization;
5) goto statement.

Note: for all jump statements, transfer out of a loop, out of a block, or back past an initialized variable with automatic storage duration involves the destruction of objects with automatic storage duration that are in scope at the point transferred from but not at the point transferred to. If multiple objects were initialized, the order of destruction is the opposite of the order of initialization.




### break
Causes the enclosing for, range-for, while or do-while loop or switch statement to terminate.

Used when it is otherwise awkward to terminate the loop using the condition expression and conditional statements.

Syntax
attr(optional) break ; 		

After this statement the control is transferred to the statement immediately following the enclosing loop or switch. As with any block exit, all automatic storage objects declared in enclosing compound statement or in the condition of a loop/switch are destroyed, in reverse order of construction, before the execution of the first line following the enclosing loop.

Notes
A break statement cannot be used to break out of multiple nested loops. The goto statement may be used for this purpose.


The break statement is an effective way to avoid extra variables to control a loop and produce an elegant code. However, break statements must be used very sparingly within a loop. An excessive use of these statements in a loop will produce spaghetti-code (loops with many exit conditions) that can be very hard to understand and manage. You should be extra careful in using break statements and ensure that the use of the break statements makes the code more readable and not less readable. If you’re not sure, don’t use break statements.



### continue
Causes the remaining portion of the enclosing for, range-for, while or do-while loop body to be skipped.

Used when it is otherwise awkward to ignore the remaining portion of the loop using conditional statements.

Syntax
attr(optional) continue ; 		

Explanation
The continue statement causes a jump, as if by goto to the end of the loop body (it may only appear within the loop body of for, range-for, while, and do-while loops).

In a while and do...while structure, the expression (that is, the loop-continue test) is evaluated immediately after the continue statement. In a for structure, the update statement is executed after the continue statement, and then the loop condition (that is, the loop-continue test) executes.




### return
Terminates the current function and returns the specified value (if any) to its caller.

Syntax
(1) attr(optional) return expression(optional) ;
(2) attr(optional) return braced-init-list ; 	(2) 	(since C++11)
(3) attr(optional) co_return expression(optional) ; 	(3) 	(since C++20)
(4) attr(optional) co_return braced-init-list ; 	(4) 	(since C++20)

attr(C++11) - optional sequence of any number of attributes
expression - expression, convertible to the function return type
braced-init-list - brace-enclosed list of initializers and other braced-init-lists

Explanation
1) Evaluates the expression, terminates the current function and returns the result of the expression to the caller, after implicit conversion to the function return type. The expression is optional in functions whose return type is void, and disallowed in constructors and in destructors.

2) Uses copy-list-initialization to construct the return value of the function.

3,4) In a coroutine, the keyword co_return must be used instead of return for the final suspension point (see coroutines for details).
Notes

If control reaches the end of a function with the return type void, end of a constructor, end of a destructor, or the end of a function-try-block for a function with the return type void without encountering a return statement, return; is executed.

If control reaches the end of the main function, return 0; is executed.

Flowing off the end of a value-returning function (except main) without a return statement is undefined behavior.

In a function returning void, the return statement with expression can be used, if the expression type is void.

(since C++14)
The copy-initialization of the result of the function call is sequenced-before the destruction of all temporaries at the end of expression, which, in turn, is sequenced-before the destruction of local variables of the block enclosing the return statement.
	






### Labels

Any statement can be labeled, by providing a label followed by a colon before the statement itself.
attr(optional) identifier : statement 	(1) 	
attr(optional) case constexpr : statement 	(2) 	
attr(optional) default : statement 	(3) 	
1) target for goto;
2) case label in a switch statement;
3) default label in a switch statement.

An attribute sequence attr may appear just before the label (in which case it applies to the label), or just before any statement itself, in which case it applies to the entire statement.

A label (and only a label) with an identifier declared inside a function is in scope everywhere in that function, in all nested blocks, before and after its own declaration.

A statement may carry multiple labels.
Two labels in a function must not have the same identifier.

Labels are not found by unqualified lookup: a label can have the same name as any other entity in the program.



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

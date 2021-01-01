### Labels
Labels are identifiers you can add to any statement. Labels give statements
a name, and they have no direct impact on the program. To assign a label,
prepend a statement with the desired name of the label followed by a
semicolon.

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
Transfers control unconditionally.

Used when it is otherwise impossible to transfer control to the desired location using other statements.

Syntax
attr(optional) goto label ; 		


Explanation
The goto statement transfers control to the location specified by label. The goto statement must be in the same function as the label it is referring, it may appear before or after the label.

If transfer of control exits the scope of any automatic variables (e.g. by jumping backwards to a point before the declarations of such variables or by jumping forward out of a compound statement where the variables are scoped), the destructors are called for all variables whose scope was exited, in the order opposite to the order of their construction.

The goto statement cannot transfer control into a try-block or into a catch-clause, but can transfer control out of a try-block or a catch-clause (the rules above regarding automatic variables in scope are followed)

If transfer of control enters the scope of any automatic variables (e.g. by jumping forward over a declaration statement), the program is ill-formed (cannot be compiled), unless all variables whose scope is entered have
1) scalar types declared without initializers
2) class types with trivial default constructors and trivial destructors declared without initializers
3) cv-qualified versions of one of the above
4) arrays of one of the above

(Note: the same rules apply to all forms of transfer of control)

In modern C++, there is no good role for goto statements. Don’t use them.


Syntax:
SomeFunction()
{
  Start: //Label
  CodeThatRepeats;
  goto Start;
}

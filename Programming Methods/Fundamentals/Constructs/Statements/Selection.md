## Selection Statements
Selection statements express conditional control flow. The two general of
selection statements are the if statement and the switch statement. Selection statements provide conditional branching dependent on the value of an expression called a conditional. After a selection statement is executed, sequential execution is resumed.


### If
if boolean-expression
  statement

An if statement contains the if keyword, a boolean expression, and a statement. The statement associated with the if could be a single statement or a block statement. The if keyword, boolean expression, and associated statement are known as an "if clause".

The if statement provides conditional branching dependent on whether the if clauses boolean expression evaluates to true or false. Executing the associated statement when the boolean expression is true and skipping the associated statement when the boolean expression is false.

Additionally, the if statement may be followed by an optional else clause.
An else clause is composed of the else keyword and an associated statement, either a single statement or a block statement. The statement of an else clause is executed only when the boolean expression of the associated if clause is false.

if boolean-expression
  statement
else
  statement

If we want to have more complex logic, we can have nested if statements. Nesting an if statement means we can specify a new if statement within a block statement that follows either the if or else clause.

if boolean-expression
  {
    if boolean-expression
      statement
    else
      statement
  }
else
  statement

Pairing an else with an if: In a nested if statement, an else is associated with the most recent incomplete if — that is, the most recent if that has not been paired with an else.

Additionally, the if statement may be followed by an optional else if clause. An else if clause is composed of the else if keyword, a boolean expression, and a statement. The statement associated with the else if could be a single statement or a block statement.

You can include any number of else if clauses or omit them entirely.

if (boolean-expression-1)
  statement-1
else if (boolean-expression-2)
  statement-2
else
  statement-3

The evaluation of an if clause proceeds from top to bottom, evaluating the boolean expression associated with each if or else if clause. When the first boolean expression evaluates to true the associated statement is executed and no other clauses are considered. If none of the boolean expressions associated with any of the clauses evaluate to true then the statement associated with the optional else clause is executed or no statements are executed when there is no else specified.




### Switch
One alternative, when we have one option out of many that can be true, is the switch statement. It also works with conditions even if they are not as apparent as they are in an if statement.

Like an if statement, switch statements provide conditional branching.

A switch statement only compares values for equality

What a switch statement looks like depends on what language we use. What we will see here is a structure that is rather common, but when applying it, you will need to look up the correct syntax for your language.

The switch keyword denotes a switch statement.

The switch statement transfers control to one of several case clauses depending on the value of an associated conditional expression. The case keyword denotes a case clause, whereas the default keyword denotes the default clause. When a switch statement executes, control transfers to the case associated with the value if the conditional expression or to an optional default case if no case matches the value of the conditional expression.

Once control is transferred to a case clause, execution will continue until the end of the switch statement or a break keyword.

You’ll almost always find a break at the end of each switch condition.


switch(condition){
  case (case-value):
    {//case statements }
    break;
  case (case-value):
    {//case statements }
    break;
  default:
    {//case statements }
}

Each case clause contains the case keyword, an associated case-value, and an associated statement that can either be a single statement or a block statement. After each statement following a case, you must specify a break statement with the break keyword or the following case will be executed. If condition matches none of the cases and a default case is specified, the default case executes.

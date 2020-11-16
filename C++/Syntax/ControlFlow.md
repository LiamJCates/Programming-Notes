Conditional Statements

## If
if (boolean-expression) statement;

An if statement contains a Boolean expression and one or more nested
statements. Depending on whether the Boolean evaluates to true or false,
the program decides which nested statement to execute.

The statement could be a single statement followed by a semicolon or a block statement.

if (boolean-expression-1) statement-1
else if (boolean-expression-2) statement-2
else statement-3

if a Boolean expression evaluates to true the associated statement is executed, if neither do the optional else statement is executed.

You can include any number of else if clauses or omit them entirely.



## Switch
The switch statement transfers control to one of several statements depending on the value of a condition, which evaluates to either an integer or enumeration type.

The switch keyword denotes a switch statement.
Like an if statement, switch statements provide conditional branching. When a switch statement executes, control transfers to the case fitting the condition or to a default condition if no case matches the condition expression. The case
keyword denotes a case, whereas the default keyword denotes the default
condition.
Somewhat confusingly, execution will continue until the end of the
switch statement or the break keyword. You’ll almost always find a break at
the end of each condition.


switch(condition){
  case (case-value):
    {//case statements }
    break;
  case (case-value):
    {//case statements }
    break;
  default:  
}

All switch statements begin with the switch keyword followed by the condition in parentheses. Each case begins with the case keyword followed by the case’s enumeration or integral value. If condition is equal to a given case-value, the code in the associated block will execute. After each statement following a case, you place a break keyword or the following case will be executed. If condition matches none of the cases and a default case is specified, the default case executes.

The braces enclosing each case are optional but highly recommended. Without them,
you’ll sometimes get surprising behavior.




# Loops

## for
A for loop lets you repeat (or iterate) the execution of a statement a until a specified condition is false.

Initializer: First portion, sets counter variables.
Iteration condition: condition evaluated before each iteration.
Iteration statement: happens after each loop cycle.
Loop statement: a statement that repeats until the iteration condition is false, can be a single statement followed by a semi-colon or a block statement.

for(initializer, iteration condition, iteration statement)
  loop statement;

#include <cstddef>
#include <cstdio>
int main() {
  unsigned long maximum = 0; u44 Chapter 2
  unsigned long values[] = { 10, 50, 20, 40, 0 }; v
  for(size_t i=0; i < 5; i++) { w
    if (values[i] > maximumx) maximum = values[i]; y
  }
  printf("The maximum value is %lu", maximum); z
}

If you’ve programmed C or C++ before, you might be wondering why Listing 2-10
employs size_t instead of an int for the type of i. Consider that values could theoretically take up the maximum storage allowed. Although size_t is guaranteed to be
able to index any value within it, int is not. In practice, it makes little difference,
but technically size_t is correct.

The Range-Based for Loop
For certain objects which are collections of other objects, like arrays, for understands how to iterate over the range of values within an object. Each loop iteration references one element from the collection

element-type: value type which the loop will iterate over, must match the types within the iterable
element-name: identifier used to reference an element of the collection during the iteration
iterable-name: identifier of the iteration collection of which we would like to access the members of.

for(element-type element-name : iterable-name)
  loop statement;

#include <cstdio>
int main() {
  unsigned long maximum = 0;
  unsigned long values[] = { 10, 50, 20, 40, 0 };
  for(unsigned long value : values) {
    if (value > maximum) maximum = valuw;
  }
  printf("The maximum value is %lu.", maximum);
}






## goto

goto instructs execution to continue from a particular, labeled,
point in code. You can use it to go backward and re-execute certain statements.
The syntax for the goto statement is
SomeFunction()
{
Start: // Called a label
CodeThatRepeats;
goto Start;
}

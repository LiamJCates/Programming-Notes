## Iteration Statements
Iteration statements execute an associated statement repeatedly.

The three basic iteration statements are the while loop, the do-while loop, the for loop, and the range-based for loop

Loops typically execute their associated statement while a certain expression evaluates to true.

### Loop Control Variable
Typically, the expression checks whether a variable, called the loop control variable (LCV), satisfies certain conditions.

The LCV must be properly initialized before the loop is encountered, and it should eventually make the expression evaluate to false. We do this by updating or assigning a new value to the LCV in the body of the loop.

Counter-Controlled Loop
Suppose you know exactly how many times certain statements need to be executed. In such cases, the loop assumes the form of a counter-controlled loop. That is, the LCV serves as a “counter.” Suppose that a set of statements needs to be executed N times. You can set up a counter (initialized to 0 before the loop) to track how many times a statement executes. Before executing the body of the loop statements, the counter is compared with N. If counter < N, the body of the loop executes. The body of the loop continues to execute until the value of counter >= N. Thus, inside the body of the loop, the value of counter increments by 1 after it reads a new item.



Sentinel Controlled Loop
You do not always know how many pieces of data (or entries) need to be read, but you may know that the last entry is a special value, called a sentinel, that will tell the loop to stop. In this case, you must read the first item before the loop so the test expression will have a valid value to test. If this item does not equal the sentinel, the body of the loop executes. The loop continues to execute as long as the program has not read the sentinel. Such a loop is called a sentinel-controlled loop.

For example, if we want to count the number of characters in a string before the occurrence of a given value we can use that value as a sentinel value and iterate through the string until we hit that sentinel value.



Flag-Controlled Loops
A flag-controlled loop uses a flag variable to control the loop. A flag variable is a boolean variable that indicates whether a condition is true or false.

The condition is typically false before the loop body
In which case you set a flag variable initialized to false before executing the body of the loop statements.

The loop tests the flag variable to begin execution and continues to execute until the flag variable changes value

in the body of the loop, once a certain condition is met the flag variable is updated and the loop terminates after it finishes the current iteration.




### Loop Types
A loop where the loop condition is evaluated before executing the body of the loop is called pretest loops.

In a loop where the loop condition is evaluated after executing the body of the loop are called posttest loops.

pretest loops have entry conditions and it is possible these loops may never activate.

posttest loops have exit conditions and therefore always executes the statement at least once.

#### for
The for statement is specified by the for keyword and a number

The typical components of a for loop are as follows:
  Initializer: First portion, sets counter variables.
  Iteration condition: boolean-expression evaluated before each iteration.
  Iteration statement: happens after each loop cycle.
  Loop statement: also called the loop body, is a statement that repeats until the iteration condition is false, can be a single statement or a block statement.

for(initializer, iteration condition, iteration statement)
  loop statement;

The for loop executes as follows:
1. The initializer executes.
2. The iteration condition is evaluated. If the loop condition evaluates to true:
  i. Execute the for loop statement.
  ii. Execute the iteration statement.
3. Repeat Step 2 until the loop condition evaluates to false.

The initializer statement usually initializes a variable (called the for loop control, or for index, variable).

Any of the for loop components can be optionally excluded and the loop is still valid. If the loop condition is omitted it defaults to true and another construct must be used to halt loop iteration.

the for loop is a pretest loop, the body may never execute.

## while
while (boolean-expression)
  statement;

A while loop is specified by the while keyword, a boolean expression and a statement which can be either a simple or compound statement called the loop body.

The boolean expression is evaluated, when true the loop body executes, when false control flow resumes after the while statement. The

## do while
do
  statement
while (boolean-expression);

A do while loop is specified by the do keyword, a statement which can be either a simple or compound statement, the while keyword, and a boolean expression.


The statement executes first, and then the expression is evaluated. If the expression evaluates to true, the statement executes again. As long as the expression in a do. . .while statement is true, the statement executes. To avoid an infinite loop, you must, once again, make sure that the loop body contains a statement that ultimately makes the expression false and assures that it exits properly.

The do while loop is a post test loop and always executes once

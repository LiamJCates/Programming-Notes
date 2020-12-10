## Iteration Statements
Iteration statements execute a statement repeatedly. The four kinds of iteration statements are the while loop, the do-while loop, the for loop, and the range-based for loop

Loops typically execute while a certain expression evaluates to true.

Typically, the expression checks whether a
variable, called the loop control variable (LCV), satisfies certain conditions.

The LCV must be properly initialized before the loop is encountered, and it should eventually make the expression evaluate to false. We do this by updating or assigning a new value to the LCV in the body of the loop.

Counter-Controlled Loop
Suppose you know exactly how many times certain statements need to be executed. For example, suppose you know exactly how many pieces of data (or entries) need to be read. In such cases, the loop assumes the form of a counter-controlled loop. That is, the LCV serves as a “counter.” Suppose that a set of statements needs to be executed N times. You can set up a counter (initialized to 0 before the loop) to track how many items have been read. Before executing the body of the loop statements, the counter is compared with N. If counter < N, the body of the loop executes. The body of the loop continues to execute until the value of counter >= N. Thus, inside the body of the loop, the value of counter increments by 1 after it reads a new item.

Sentinel Controlled Loop
You do not always know how many pieces of data (or entries) need to be read, but you may know that the last entry is a special value, called a sentinel, that will tell the loop to stop. In this case, you must read the first item before the loop so the test expression will have a valid value to test. If this item does not equal the sentinel, the body of the loop executes. The loop continues to execute as long as the program has not read the sentinel. Such a loop is called a sentinel-controlled loop.
The end-of-file (EOF) value is often a good sentinel value.

Flag-Controlled Loops
A flag-controlled loop uses a flag variable to control the loop. A flag variable is a bool variable that indicates whether a condition is true or false.
It is generally named for the true state of that condition: for example, isFound, isTallEnough, and isFull.

The condition is typically false before the loop body
In which case you set a flag variable initialized to false before executing the body of the loop statements.

The loop tests the flag variable to begin execution and continues to execute until the flag variable changes value

in the body of the loop, once a certain condition is met the flag variable is updated and the loop terminates after it finishes the current iteration.

### Loop Types
In a loop where the loop condition is evaluated before executing the body of the loop are called pretest loops.

In a loop where the loop condition is evaluated after executing the body of the loop are called posttest loops.

pretest loops have entry conditions so these loops may never
activate.

posttest loops have exit conditions and therefore
always executes the statement at least once.

## for
A for loop lets you repeat (or iterate) the execution of a statement a until a specified condition is false.

Initializer: First portion, sets counter variables.
Iteration condition: condition evaluated before each iteration.
Iteration statement: happens after each loop cycle.
Loop statement: a statement that repeats until the iteration condition is false, can be a single statement followed by a semi-colon or a block statement.

for(initializer, iteration condition, iteration statement)
  loop statement;

The for loop executes as follows:
1. The initializer executes.
2. The iteration condition is evaluated. If the loop condition evaluates to true:
  i. Execute the for loop statement.
  ii. Execute the iteration statement.
3. Repeat Step 2 until the loop condition evaluates to false.

The initializer statement usually initializes a variable (called the for loop control, or for indexed, variable)

#include <cstddef>
#include <cstdio>
int main() {
  unsigned long maximum = 0;
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

## while
while (expression)
  statement;

In C++, while is a reserved word. Of course, the statement can be either a simple
or compound statement. The expression acts as a decision maker and is usually a
logical expression. The statement is called the body of the loop.

## do while
do
  statement
while (expression);


Of course, statement can be either a simple or compound statement. If it is a compound statement, enclose it between braces.

In C++, do is a reserved word.
The statement executes first, and then the expression is evaluated. If the expression
evaluates to true, the statement executes again. As long as the expression in a
do. . .while statement is true, the statement executes. To avoid an infinite loop, you
must, once again, make sure that the loop body contains a statement that ultimately
makes the expression false and assures that it exits properly.

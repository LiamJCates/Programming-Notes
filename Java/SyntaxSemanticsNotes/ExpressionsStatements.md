Expressions, Statements, and Blocks

Expressions are the core components of statements
Statements may be grouped into blocks
Blocks generally designate logical components of a program


Expressions

Expressions are composed of variables, operators, literals, and method calls
Expressions evaluate to a single value of a given type

Spacing and Parentheses
An expression in Java may have tabs and spaces in it to make it more readable.
Redundant or additional parentheses will not cause error or slow expression execution
You are encouraged to use parentheses to make order of evaluation clear

Type Conversion in Expressions
Within an expression, it is possible to mix two or more values of differing types as long as:
they are implicitly compatible (widening conversion)
    they are explicitly type cast to compatible types

Implicit conversion of numeric types follow type promotion rules:

char, byte, short < int < long < float < double

It is important to understand that type promotions apply only to the values operated upon when an expression is evaluated. For example, if the value of a byte variable is promoted to int inside an expression, outside the expression, the variable is still a byte. Type promotion only affects the evaluation of an expression.

char, byte, and short values are always promoted to int. If one operand is a long, the whole expression is promoted to long. If one operand is a float operand, the entire expression is promoted to float. If any of the operands is double, the result is double.

Somewhat counterintuitively, no cast is needed when assigning byte*byte to an int, because bytes are promoted to int when the expression is evaluated. However, when you try to assign byte * byte to a byte, you do need a cast—back to byte! Keep this in mind if you get unexpected type-incompatibility error messages on expressions that would otherwise seem perfectly OK.
This same situation happens with char's and shorts.




Statements

Any task you want to accomplish in a Java program can be broken down into a series of statements.

A statement forms a complete unit of execution, built from expressions terminated by a semi-colon
Each statement must end in a semicolon;
In Java, the semicolon is a separator. It is often used to terminate a statement.
In essence, the semicolon indicates the end of one logical entity

Statements define computation by creating and manipulating variables, assigning data-type values to them, and controlling the flow of execution of such operations.

Java supports three statements types:
Declaration statements        A statement that creates a variable identifier and memory space
Expression statements        A statement that produces a value
Control Flow statements     A statement that determines program execution order




Blocks
Statements in Java are grouped using an opening brace ( { ) and a closing brace ( } ).
A group of statements placed between these characters is called a block (or block statement).
All opening braces in Java must be closed with a corresponding closing brace.
A block is a group of zero or more statements that can be used anywhere a single statement is allowed.

Q: Does the use of a code block introduce any run-time inefficiencies?

A: No. Code blocks do not add any overhead whatsoever.
The { and } exist only in your program’s source code. Java does not execute the { or }.
Comments

single-line comment syntax:         //Comment text

Comments are ignored by javac, they are not compiled into bytecode.
Comments are added to our code to make it more readable for other programmers.

multiline comments syntax:        /* Comment
Text
*/

The third type of comment is known as a documentation comment.
Any comment that starts with /** and ends with */ is considered a documentation comment.

A documentation comment
just before a class header gives a brief description of the class.
just before each method header gives a brief description of the method.
White Space
In Java, the term white space refers to one or more consecutive space characters, tab characters, or line breaks.

In Java, you don’t have to do anything special to continue a statement onto a second line.

x = (y + 5) / z;

is identical to this statement:
x =
(y + 5) / z;

Java does not recognize the end of the line as a terminator.
For this reason, it does not matter where on a line you put a statement.
Be advised, that you can’t put white space in the middle of a keyword or identifier.

The compiler ignores white space, so it doesn’t affect the bytecode that’s created for your program.
As a result, using extra white space in your program doesn’t affect your program’s performance in any way, but it does make the program’s source code easier to read.

Using white space liberally in your programs is a good idea.
To make your program more readable to other programmers (and yourself), follow the conventions of
» Line breaks    Place each statement on a separate line.
» Tabs:        Line up elements that belong together.











Control Flow Statements

There are three categories of program control statements:
selection/decision statements    which include the if and the switch;
iteration/looping statements    which include the for, while, and do-while loops;
jump/branching statements    which include break, continue, and return.

By default, program statements are executed from top to bottom, in the order that they appear
We alter this flow using control flow statements.






Jump / Branching Statements
A branching statement is a statement that instructs the program to branch to another line of code. Branching statements are commonly used in loops and other control flow statements.
break;        //causes the program to stop execution and exit a code block
continue;    //cause the program to skip the remained of a loop iteration


Decision/Selection Statements
Java provides selection statements: statements that let you choose actions with alternative courses.
Selection statements use conditions that are Boolean expressions.

if statement
The if statement is used for conditional execution of the associated code block.
The else if and else branches are optional.

if (condition){
} else if (condition){
} else{
}



Switch Statement
The switch statement is similar to an if statement except that a switch statement requires each case to be based on a single value.
A switch statement's expression is evaluated once
The expression's value is compared with the values designated by each case
Once there is a match this comparison stops, the associated block of code is executed.
When a certain case is satisfied, everything starting from the next line is executed
The default code block is run if no case match is found.

A break statement instructs the program to break out of the switch statement.
If no break appears, flow of control will fall through and execute subsequent cases until a break is reached.
The break and default keywords are optional

For versions of Java prior to JDK 7, the expression controlling the switch must resolve to type byte, short, int, char, or an enumeration. Beginning with JDK 7, expression can also be of type String.
However, switching on strings can be less efficient than switching on integers. Therefore, it is best to switch on strings only in cases in which the controlling data is already in string form.

Each value specified in the case statements must be a unique constant expression (such as a literal value). Duplicate case values are not allowed. The type of each value must be compatible with the type of expression.

switch(expression) {
  case value1:
    break;
  case value2:
    break;
  default:
}


Q: Under what conditions should I use an if-else-if ladder rather than a switch when coding a multiway branch?
A: In general, use an if-else-if ladder when the conditions controlling the selection process do not rely upon a single value.
Iteration / Looping Statements
The four commonly used looping statements in Java are the for statement, the enhanced for statement, the while statement and the do-while statement.

Loop Design Strategy:
The key to designing a loop is to identify the code that needs to be repeated and write a condition for terminating the loop.

Sentinel Value
Another common technique for controlling a loop is to designate a special value when reading and processing a set of values. This special input value, known as a sentinel value, signifies the end of the input. A loop that uses a sentinel value to control its execution is called a sentinel-controlled loop.

Pretest/Posttest
The while loop and for loop are called pretest loops because the continuation condition is checked before the loop body is executed.
The do-while loop is called a posttest loop because the condition is checked after the loop body is executed.

expressively equivalent
The three forms of loop statements—while, do-while, and for—are expressively equivalent; that is, you can write a loop in any of these three forms.

Minimizing Numeric Errors
Using floating-point numbers in the loop continuation condition may cause numeric errors. Numeric errors involving floating-point numbers are inevitable, because floating-point numbers are represented by approximation in computer memory by nature.


For Statement
The for statement executes a code block zero or more times until the test condition is false

Syntax:

for (initialization statement; test condition; iteration expression) { //Loop body }

It is possible for any or all of the initialization, condition, or iteration portions of the for loop to be blank.
You can have any number of initialization and iteration statements
in practice, more than two or three make the for loop unwieldy.

The test condition controlling the loop can be any valid Boolean expression.

You can create an infinite loop by leaving the conditional expression empty.
This syntax shows the way many Java programmers create an infinite loop:

for(;;){ //Statements }

The body of a loop can be zero or more statements
A single statement is not enclosed in brackets
    A body with zero statements is the syntactically valid null statement

Syntax:
for (initialization statement; test condition; iteration expression) statement;

Syntax:
for (initialization statement; test condition; iteration expression) { }

Body-less loops are often useful.
For example, the following program uses one to sum the numbers 1 through 5:
sum = 0
for(i = 1; i <=5; sum += i) { }


Enhanced For Statement
An enhanced for statement is very useful if you want to get information from an array without making any changes to it.

Syntax:
for (variable declaration : name of array) { //Do Some Task }

For example, you the following code may be used to display the elements of the array.

for (int item : myNumbers) System.out.println(item);

Any type that implements the Iterator interface can be iterated over by the enhanced for statement

While Statement
The while statement repeatedly executes instructions inside the loop while a certain condition remains valid.

Syntax:
while (conditional)
{
//Do Some Task
}


Do-while Statement
The do-while statement is similar to the while statement with one main difference - the code within the curly braces of a do-while statement is executed at least once, even if the condition is false, as the condition is checked at the end of the code block rather than the start.
Note that for a do-while statement, a semi-colon (;) is required after the test condition.

Syntax:
do {
    //Do Some Task
} while (condition);

Q: Given the flexibility inherent in all of Java’s loops, what criteria should I use when selecting a loop? That is, how do I choose the right loop for a specific job?
A: Use a for loop when performing a known number of iterations based on the value of a loop control variable. Use the do-while when you need a loop that will always perform at least one iteration.
The while is best used when the loop will repeat until some condition becomes false.




Advanced Jump Statements

Advanced Break
The break statement can be employed by itself to provide a “civilized” form of the goto statement. Java does not have a goto statement, because it provides an unstructured way to alter the flow of program execution. Programs that make extensive use of the goto are usually hard to understand and hard to maintain. There are, however, a few places where the goto is a useful and legitimate device. For example, the goto can be helpful when exiting from a deeply nested set of loops. This can be placed in any block, and specifies precisely where execution will resume:

break label;

label is the name of a label that identifies a block of code. When this form of break executes, control is transferred out of the named block of code. The labeled block of code must enclose the break statement, but it does not need to be the immediately enclosing block. This means that you can use a labeled break statement to exit from a set of nested blocks. But you cannot use break to transfer control to a block of code that does not enclose the break statement. To name a block, put a label at the start of it. The block being labeled can be a stand-alone block, or a statement that has a block as its target. A label is any valid Java identifier followed by a colon. Once you have labeled a block, you can then use this label as the target of a break statement. Doing so causes execution to resume at the end of the labeled block.

first:
for( int i = 0; i < 10; i++) {
  second:
  for(int j = 0; j < 5; j ++ ) {
    break xxx;
  }
}

third:
for( int a = 0; a < 10; a++) {

}
You could replace xxx with first or second (to break the outer or inner loop), since both loops are being executed, when you hit the break statement, but replacing xxx with third won't compile.

Q: You say that the goto is unstructured and that the break with a label offers a better alternative. But really, doesn’t breaking to a label, which might be many lines of code and levels of nesting removed from the break, also destructure code? A: The short answer is yes! However, in those cases in which a jarring change in program flow is required, breaking to a label still retains some structure. A goto has none!

Advanced Continue
It is possible to force an early iteration of a loop, bypassing the loop’s normal control structure. This is accomplished using continue. In while and do-while loops, a continue statement will cause control to go directly to the conditional expression and then continue the looping process. In the case of the for, the iteration expression of the loop is evaluated, then the conditional expression is executed, and then the loop continues. As with the break statement, continue may specify a label to describe which enclosing loop to continue.

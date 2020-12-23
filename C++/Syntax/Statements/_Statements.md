Each C++ program is comprised of a sequence of statements, which are programming constructs that specify program execution.

All statements in C++ end with a semicolon (;)

The next statement can start immediately after the semicolon, but for convenience and readability you often program successive statements on successive lines.

If you need to spread a statement over two lines by inserting a backslash (\) at the end:
cout << "Hello \
World" << endl; // split to two lines is OK






#### Expression Statements
An expression statement is an expression followed by a semicolon (;).

Expressions are computations that produce results and side effects. Generally,
expressions contain operands and operators that do work on them

Operators, such as the addition (+) and address-of (&) operators, do work
on arguments called operands, such as numerical values or objects.

Expression statements comprise most of the statements in a program.
You can turn any expression into a statement, which you should do
whenever you need to evaluate an expression but want to discard the
result. Of course, this is only useful if evaluating that expression causes
a side effect



#### Declaration Statements
Declaration statements (or just declarations) introduce identifiers, such as
functions, templates, and namespaces, into your programs.



#### Functions
A function declaration, also called the function’s signature or prototype, specifies a function’s inputs and outputs. The declaration doesn’t need to include parameter names, only their types.

Functions that aren’t member functions are called non-member functions,
or sometimes free functions, and they’re always declared outside of main()
at namespace scope. A function definition includes the function declaration
as well as the function’s body. A function’s declaration defines a function’s
interface, whereas a function’s definition defines its implementation.

function declarations are optional. So why do they exist?
The answer is that you can use declared functions throughout your
code as long as they’re eventually defined somewhere. Your compiler tool
chain can figure it out.

#### Namespace
A namespace statement declares the name of a namespace and causes the source code that follows the declaration to be compiled within that namespace.


#### Control Structures
Control structures provide alternatives to sequential program execution and are used to alter the sequential flow of execution.

The most common control structures are selection, iteration, and jump statements:
  Selection statements cause the program to execute particular statements depending on some condition(s).
  Iteration statements cause the program to repeat particular statements based on some condition(s).
  Jump statements cause the program to transfer execution unconditionally



#### Compound Statements
To permit more complex statements, C++ provides a structure called a compound statement or a block of statements.

Compound statements, also called blocks, are a sequence of statements enclosed
or grouped together within braces {...}.

Blocks are useful in control structures

Compound statement syntax:
{
statement_1
statement_2
...
statement_n
}

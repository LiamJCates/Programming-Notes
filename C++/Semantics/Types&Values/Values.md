Program values are supplied by name (variables, constants) and expressions

Variables are tools that help the programmer temporarily store data for
a finite amount of time.

Constants are tools that help the programmer define artifacts that are not allowed to change or make changes.

Expressions are any valid unit of code, a combination of one or more constants, variables, functions, and operators, that the programming language interprets to resolve to a value.


the main objective of a C++ program is to perform calculations and
manipulate data. Recall that data must be loaded into the main memory before it can be manipulated.

Storing data in the computer’s memory is a two-step process:
1. Instruct the computer to allocate memory.
2. Include statements in the program to put data into the allocated memory.


## Variables
Variable: A memory location whose content may change during program execution

The values of variables are stored somewhere in an unspecified location in the computer memory as zeros and ones. Our program does not need to know the exact location where a variable is stored; it can simply refer to it by its name. What the program needs to be aware of is the kind of data stored in the variable. It's not the same to store a simple integer as it is to store a letter or a large floating-point number; even though they are all represented using zeros and ones, they are not interpreted in the same way, and in many cases, they don't occupy the same amount of memory.

A Variable Has Three Aspects
Type: The type of information that the variable can hold
Name: The name you use in your application to refer to the variable
Value: The actual thing that the storage bin holds


The variable type attribute tells the compiler the nature of data the variable can store, and the compiler reserves the necessary memory space. The name chosen by the programmer is a friendly replacement for the address in the memory where the variable’s value is stored.



Yet, declaring a variable when it is first needed is often better as it makes the code readable—one notices the type of the variable when the declaration is close to its point of first use.

While some user defined types might have a default initialization, built in types do not. Unless the initial value is assigned, you cannot be sure of the contents of that variable's memory location. Therefore, initialization is optional, but it’s often a good programming practice

In C++, you must declare all identifiers before you can use them. If you refer to an
identifier without declaring it, the compiler will generate an error message (syntax error),
indicating that the identifier is not declared. Therefore, to use either a named constant
or a variable, you must first declare it.




## Expressions
Expressions
There are three types of arithmetic expressions in C++:

Integral expressions: all operands in the expression are integers. An integral expression yields an integral result.

Floating-point (decimal) expressions—all operands in the expression
are floating points (decimal numbers). A floating-point expression
yields a floating-point result.

Mixed expressions the expression contains both integers and decimal numbers.


From these rules, it follows that when evaluating a mixed expression, you concentrate on one operator at a time, using the rules of precedence.

If the operator to be evaluated has one integer operand and one floating-point operand, before evaluating this operator, convert the integer operand to a floating-point number with the decimal part of 0.


A common expression is assignment

The assignment operator replaces the value contained by the operand to the left (l-value) by that on the right (r-value).

There are two kinds of expressions in C++ −

    lvalue − Expressions that refer to a memory location is called "lvalue" expression. An lvalue may appear as either the left-hand or right-hand side of an assignment.

    rvalue − The term rvalue refers to a data value that is stored at some address in memory. An rvalue is an expression that cannot have a value assigned to it which means an rvalue may appear on the right- but not left-hand side of an assignment.

Variables are lvalues and so may appear on the left-hand side of an assignment. Numeric literals are rvalues and so may not be assigned and can not appear on the left-hand side.

So, all l-values can be r-values, but not all r-values can be l-values.

Following is a valid statement −

int g = 20;

But the following is not a valid statement and would generate compile-time error −

10 = 20;

Outputting or accessing the value of a variable in an expression does not destroy or modify the contents of the variable.







## Logical Expression
Logical expression: An expression that evaluates to true or false is called a logical expression.

A simple program executes statements in the order they appear, from the top to the bottom of the program, sequentially.

The specific sequence of statements that the CPU executes is called the program’s execution path (or path).

Straight-line programs take the same path (execute the same statements in the same order) every time they are run.

Control structures provide alternatives to sequential program execution and are used to alter the sequential flow of execution.

A program is usually not limited to a linear sequence of instructions. During its process it may select difference paths, repeat code, or . For that purpose, C++ provides control structures that serve to specify what has to be done by our program, when and under which circumstances.

With the introduction of control structures we are going to have to introduce a new concept: the compound-statement or block. A block is a group of statements which are separated by semicolons (;) like all C++ statements, but grouped together in a block enclosed in braces: { }:

{ statement1; statement2; statement3; }

Most of the control structures that we will see in this section require a generic statement as part of its syntax. A statement can be either a simple statement (a simple instruction ending with a semicolon) or a compound statement (several instructions grouped in a block), like the one just described. In the case that we want the statement to be a simple statement, we do not need to enclose it in braces ({}). But in the case that we want the statement to be a compound statement it must be enclosed between braces ({}), forming a block.

### Compound Statements

To permit more complex statements, C++ provides a structure called a compound statement, also called a block or block statement.

A compound statement is a group of zero or more statements that is treated by the compiler as if it were a single statement. Blocks can be used anywhere a single statement is allowed.

In C++, such statements are a sequence of statements delimited by curly braces {...}. No semicolon is needed at the end of a block.

Compound statement syntax:

  {
    statement_1
    statement_2
    ...
    statement_n
  }

Compound statements do more than simply group multiple statements into a single statement. You can also group definitions within the block. Any variable that you define in a block is visible only within the confines of the block. The region where you can use a variable is known as the variable’s scope. 


### Control Structures
  Selection
    if
    switch

  Iteration
    while
    do while
    for
    ranged for (for each)

  Jump
    break
    continue
    return
    goto

  Halt
    abort
    assert
    exit
    terminate

  Exception Handling


Selection statements cause the program to execute particular statements depending on some condition(s) and include if and switch

When a control flow statement causes point of execution to change to a non-sequential statement, this is called branching.

Iteration statements cause the program to repeat particular statements based on some condition(s) and include for, while, and do while loops.

Jump statements cause the program to transfer execution unconditionally and include break, continue, return, and goto label statements.

Halts are flow control statements that terminate the program. In C++, halts are implemented as functions (rather than keywords).


Exception handling provides a way of transferring control and information from some point in the execution of a program to a handler associated with a point previously passed by the execution (in other words, exception handling transfers control up the call stack)


For those statements that use conditions
C++ is permissive about what it allows as a condition. Any numerical type can be a condition, and the compiler treats nonzero values as true and zero as false. In other words, it supplies an implicit != 0 to test the numeric value.

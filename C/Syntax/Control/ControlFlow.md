The control-flow statements of a language specify  the order in which computations are performed

A simple program executes statements in the order they appear, from the top to the bottom of the program, sequentially.

The specific sequence of statements that the CPU executes is called the program’s execution path (or path, for short).

Straight-line programs take the same path (execute the same statements in the same order) every time they are run.

Control structures provide alternatives to sequential program execution and are used to alter the sequential flow of execution.

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
    assert
    abort
    exit


When a control flow statement causes point of execution to change to a non-sequential statement, this is called branching.

Selection statements cause the program to execute particular statements depending on some condition(s) and include if and switch

Iteration statements cause the program to repeat particular statements based on some condition(s) and include for, while, and do while loops.

Jump statements cause the program to transfer execution unconditionally and include break, continue, return, and goto label statements.

Halts are flow control statements that terminate the program. In C++, halts are implemented as functions (rather than keywords).


Exception handling provides a way of transferring control and information from some point in the execution of a program to a handler associated with a point previously passed by the execution (in other words, exception handling transfers control up the call stack)


For those statements that use conditions
C++ is permissive about what it allows as a condition. Any numerical type can be a condition, and the compiler treats nonzero values as true and zero as false. In other words, it supplies an implicit != 0 to test the numeric value.


### Comma
1) Comma as an operator:
The comma operator (represented by the token, ) is a binary operator that evaluates its first operand and discards the result, it then evaluates the second operand and returns this value (and type). A pair of expressions separated by a comma is evaluated left to right. The comma operator has the lowest precedence of any C operator, and acts as a sequence point.

2) Comma as a separator:
Comma acts as a separator when used with function calls and definitions, function like macros, variable declarations, enum declarations, and similar constructs.


### Code Block
Braces { and }  are used to group declarations and statements together
Groups of statements are defined as compound statements called a block

Variables can be declared inside any code block

When grouped, statements and declarations are still syntactically equivalent to a single statement

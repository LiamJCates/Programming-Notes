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

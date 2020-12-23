Programming Constructs
In computer science, the syntax of a computer language is the set of rules that defines the combinations of symbols that are considered to be correctly structured statements or expressions in that language.

A syntactically correct symbol sequence is known as a language construct.

Formally, a language construct is a syntactically allowable part of a program that may be formed from one or more lexical tokens in accordance with the rules of a programming language. The term "language construct" is often used as a synonym for control structure.

More generally, Programs are designed using common building blocks. These building blocks, known as programming constructs (or programming concepts), form the basis for all programs.

Basic Constructs
  Comments

  Declarations:
    Variable
    Constant
    Subroutines
    Classes

  Operators
    Assignment
    Arithmetic
    Relational
    Logical
    Bitwise
    Miscellaneous

  Expressions
    Integral
    Floating
    Relational
    Logical
    Bitwise
    Constant
    Pointer

  Control Structures
    Sequence
    Selection
    Iteration
    Subroutine
    Exceptions
    Breaking Control Flow:
      Continue
      Labels
      Goto




Control Structures
There are three basic control structures to consider:
  Sequence is the order in which instructions occur and are processed
  Selection determines which path a program takes when it is running
  Iteration is the repeated execution of a section of code when a program is running

All programs use one or more of these constructs. The longer and more complex the program, the more these constructs will be used repeatedly.







Sequence
Sequence is the order in which programming statements are executed. Programming statements usually run serially, one after another in the order which instructions occur, unless one of the other programming constructs is used. The sequence of a program is extremely important as once these are translated, carrying out instructions in the wrong order leads to a program performing incorrectly.

In many programming languages, the sequence of code that we write is made up of what are called statements. A statement expresses some action to be carried out and is made up of several internal components. These are called expressions.



Selection
Selection is a programming construct where by a section of code is run only if a condition is met. In programming, there are occasions when a decision needs to be made. Selection is the process of making a decision. The result of the decision determines which path the program will take next.



Iteration

There are times when a program needs to repeat certain steps until told otherwise, or until a condition has been met. This process is known as iteration.

Iteration is often referred to as looping, since the program ‘loops’ back to an earlier line of code. Iteration is also known as repetition.

Iteration allows programmers to simplify a program and make it more efficient . Instead of writing out the same lines of code again and again, a programmer can write a section of code once, and ask the program to execute the same line repeatedly until no longer needed.

When programmers use iteration, a program is simplified, less error-prone and more flexible. This is because:
  there are fewer lines of code, which means there are fewer opportunities for typing errors to creep in
  to increase or decrease the number of iterations, only the loop's end value needs to be changed

There are two types of iteration:
  definite iteration (also known as count-controlled iteration)
  indefinite iteration (also known as condition-controlled iteration)


Definite Iteration
When a program needs to iterate a set number of times, this is known as definite iteration and most often makes use of a FOR loop. A loop of this type uses an extra variable called a loop counter that keeps track of the number of times the loop has been run and ceases iteration when the counter


Indefinite Iteration
Indefinite iteration repeatedly executes a section of code until a condition is met - or no longer met.

There are two types of indefinite iteration:
    WHILE loops - uses the statements WHILE and ENDWHILE
    REPEAT UNTIL loops - uses the statements REPEAT and UNTIL

With a WHILE loop, the code within the iteration may never be executed.
With a REPEAT UNTIL loop, the code is always executed at least once.





Label
A label is an explicit name or number assigned to a fixed position within the source code, and which may be referenced by control flow statements appearing elsewhere in the source code. A label marks a position within source code and has no other effect.

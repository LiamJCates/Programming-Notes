Structured programming is a programming paradigm aimed at improving the clarity, quality, and development time of a computer program by making extensive use of the structured control flow constructs of selection (if/then/else) and repetition (while and for), block structures, and subroutines.


Structured programming is a branch of a family of paradigms called imperative
programming. Languages that use the concepts of imperative programming use
statements to change the program's state.

A language that supports structured programming is a language that modifies the state of the program using statements and has functions, loops, and if statements as tools to accomplish this.

We will sometimes also hear the terms procedural and modular languages. There is no need to go into the details of what the difference is between these as this is mostly academic. We can safely consider all these the same thing.


Structured programming is most frequently used with deviations that allow for clearer programs in some particular cases, such as when exception handling has to be performed.




Elements
Control structures

Following the structured program theorem, all programs are seen as composed of control structures:
  "Sequence": ordered statements or subroutines executed in sequence.

  "Selection": one or a number of statements is executed depending on the state of the program. This is usually expressed with keywords such as if..then..else..endif.

  "Iteration": a statement or block is executed until the program reaches a certain state, or operations have been applied to every element of a collection. This is usually expressed with keywords such as while, repeat, for or do..until. Often it is recommended that each loop should only have one entry point (and in the original structural programming, also only one exit point, and a few languages enforce this).

  "Recursion": a statement is executed by repeatedly calling itself until termination conditions are met. While similar in practice to iterative loops, recursive loops may be more computationally efficient, and are implemented differently as a cascading stack.


Subroutines; callable units such as procedures, functions, methods, or subprograms are used to allow a sequence to be referred to by a single statement.

Blocks are used to enable groups of statements to be treated as if they were one statement. Block-structured languages have a syntax for enclosing structures in some formal way.



Structured programming languages
It is possible to do structured programming in any programming language, though it is preferable to use something like a procedural programming language. Some of the languages initially used for structured programming include: ALGOL, Pascal, PL/I and Ada, but most new procedural programming languages since that time have included features to encourage structured programming, and sometimes deliberately left out features – notably GOTO – in an effort to make unstructured programming more difficult. Structured programming (sometimes known as modular programming[citation needed]) enforces a logical structure on the program being written to make it more efficient and easier to understand and modify.






Common deviations
While goto has now largely been replaced by the structured constructs of selection (if/then/else) and repetition (while and for), few languages are purely structured. The most common deviation, found in many languages, is the use of a return statement for early exit from a subroutine. This results in multiple exit points, instead of the single exit point required by structured programming.


Early exit
The most common deviation from structured programming is early exit from a function or loop. At the level of functions, this is a return statement. At the level of loops, this is a break statement (terminate the loop) or continue statement (terminate the current iteration, proceed with next iteration). In structured programming, these can be replicated by adding additional branches or tests, but for returns from nested code this can add significant complexity.

The most common problem in early exit is that cleanup or final statements are not executed – for example, allocated memory is not deallocated, or open files are not closed, causing memory leaks or resource leaks. These must be done at each return site, which is brittle and can easily result in bugs. For instance, in later development, a return statement could be overlooked by a developer, and an action that should be performed at the end of a subroutine might not be performed in all cases. Languages without a return statement do not have this problem.

Exception handling
Some argue that any exceptions thrown from a function violate the single-exit paradigm, and proposes that all inter-procedural exceptions should be forbidden.

exception handling differs from structured programming constructs like while loops because the transfer of control "is set up at a different point in the program than that where the actual transfer takes place. At the point where the transfer actually occurs, there may be no syntactic indication that control will in fact be transferred."[16] Computer science professor Arvind Kumar Bansal also notes that in languages which implement exception handling, even control structures like for, which have the single-exit property in absence of exceptions, no longer have it in presence of exceptions, because an exception can prematurely cause an early exit in any part of the control structure; for instance if init() throws an exception in for (init(); check(); increm()), then the usual exit point after check() is not reached.

Multiple entry
More rarely, subprograms allow multiple entry. This is most commonly only re-entry into a coroutine (or generator/semicoroutine), where a subprogram yields control (and possibly a value), but can then be resumed where it left off. There are a number of common uses of such programming, notably for streams (particularly input/output), state machines, and concurrency. From a code execution point of view, yielding from a coroutine is closer to structured programming than returning from a subroutine, as the subprogram has not actually terminated, and will continue when called again – it is not an early exit. However, coroutines mean that multiple subprograms have execution state – rather than a single call stack of subroutines – and thus introduce a different form of complexity.

It is very rare for subprograms to allow entry to an arbitrary position in the subprogram, as in this case the program state (such as variable values) is uninitialized or ambiguous, and this is very similar to a goto.

Dynamically typed languages

A language is dynamically typed if the type is associated with run-time values, and not named variables/fields/etc.

As with type-inferred languages, dynamically typed languages do not require the programmer to write explicit type annotations on expressions. Among other things, this may permit a single variable to refer to values of different types at different points in the program execution. However, type errors cannot be automatically detected until a piece of code is actually executed, potentially making debuggingmore difficult. Lisp, Smalltalk, Perl, Python, JavaScript, and Ruby are all examples of dynamically typed languages.

Dynamic typing, also called latent typing, determines the type-safety of operations at run time; in other words, types are associated with run-time values rather than textual expressions.

This means that you as a programmer can write a little quicker because you do not have to specify types every time (unless using a statically-typed language with type inference).

Examples: Perl, Ruby, Python, PHP, JavaScript

Most scripting languages have this feature as there is no compiler to do static type-checking anyway, but you may find yourself searching for a bug that is due to the interpreter misinterpreting the type of a variable. Luckily, scripts tend to be small so bugs have not so many places to hide.

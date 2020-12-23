Semantics
The term semantics refers to the meaning of languages, as opposed to their form (syntax).

Static semantics
The static semantics defines restrictions on the structure of valid texts that are hard or impossible to express in standard syntactic formalisms. For compiled languages, static semantics essentially include those semantic rules that can be checked at compile time.
Examples include checking that every identifier is declared before it is used (in languages that require such declarations) or that the labels on the arms of a case statement are distinct.[46] Many important restrictions of this type, like checking that identifiers are used in the appropriate context (e.g. not adding an integer to a function name), or that subroutine calls have the appropriate number and type of arguments, can be enforced by defining them as rules in a logic called a type system.

Static semantics:
Constraints: A function must have a well-typed body, assuming the names bound in its argument pattern have the inferred types (and any references to enclosing names have the proper types, etc.).
Result type: The type of the function is argType -> returnType, where argType and returnType are inferred from the argument pattern and body.


Dynamic semantics
Once data has been specified, the machine must be instructed to perform operations on the data.
For example, the semantics may define the strategy by which expressions are evaluated to values, or the manner in which control structures conditionally execute statements.
The dynamic semantics (also known as execution semantics) of a language defines how and when the various constructs of a language should produce a program behavior.

Dynamic semantics: A function definition constructs a closure that contains two parts:
The code of the compiled function.
An environment pointer that "captures" variables in the surrounding environment.

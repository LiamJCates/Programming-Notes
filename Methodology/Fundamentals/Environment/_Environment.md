












Formal Representation

The Execution Environment or environment is a representation of a programs state as it executes.

The representation is written:

  ρ = {x1 7→ n1, . . . xk 7→ nk }, associates variable xi with value ni.

Where p is

Environment is finite map, aka partial function
x ∈ dom ρ x is defined in environment ρ
ρ(x) the value of x in environment ρ
ρ{x 7→ v} extends/modifies environment ρ to map x to v

Expression evaluation
Expressions are evaluated in an environment to produce values.
An environment consists of formal, global, and function environments.
Heart of the interpreter
structural recursion on Exps
environment provides meanings of names


Operational semantics
Specify executions of programs on an abstract machine
Typical uses
Very concise and precise language definition
Direct guide to implementor
Prove things like “environments can be kept on a stack”

You’ve seen expressions: ASTs
All values are integers.
State <e, ξ, φ, ρ> is
e Expression being evaluated
ξ Values of global variables
φ Definitions of functions
ρ Values of formal parameters
You’ve seen expressions: ASTs
All values are integers.

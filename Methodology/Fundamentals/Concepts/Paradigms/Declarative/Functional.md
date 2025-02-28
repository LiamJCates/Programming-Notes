Functional programming is a paradigm that has gained popularity. It is not new; we can trace its roots back to Lambda calculus, which was introduced in the 1930s. In the 1950s, the programming language Lisp was developed and implemented this paradigm.


As we will see, this paradigm has a very different approach to how programs are structured and implemented. You will need to rethink the way you look at programming and code structure to be able to understand the strength of this paradigm. We will begin by looking at a definition of functional programming. The definition will, itself, be hard to understand, so we will also need to look at some parts of it to understand what this is all about.

One definition is as follows:

"Functional programming is a way of structuring a computer program that treats computation as the evaluation of mathematical functions and avoids changing the state of the program and the use of mutable data.












In computer science, functional programming is a programming paradigm where programs are constructed by applying and composing functions. It is a declarative programming paradigm in which function definitions are trees of expressions that each return a value, rather than a sequence of imperative statements which change the state of the program.

In functional programming, functions are treated as first-class citizens, meaning that they can be bound to names (including local identifiers), passed as arguments, and returned from other functions, just as any other data type can. This allows programs to be written in a declarative and composable style, where small functions are combined in a modular manner.

Functional programming is sometimes treated as synonymous with purely functional programming, a subset of functional programming which treats all functions as deterministic mathematical functions, or pure functions. When a pure function is called with some given arguments, it will always return the same result, and cannot be affected by any mutable state or other side effects. This is in contrast with impure procedures, common in imperative programming, which can have side effects (such as modifying the program's state or taking input from a user). Proponents of purely functional programming claim that by restricting side effects, programs can have fewer bugs, be easier to debug and test, and be more suited to formal verification.












The principles of modularity and code reuse in practical functional languages are fundamentally the same as in procedural languages, since they both stem from structured programming.

So for example:
Procedures correspond to functions. Both allow the reuse of the same code in various parts of the programs, and at various points of its execution.
By the same token, procedure calls correspond to function application.
Functions and their invocations are modularly separated from each other in the same manner, by the use of function arguments, return values and variable scopes.

The main difference between the styles is that functional programming languages remove or at least deemphasize the imperative elements of procedural programming. The feature set of functional languages is therefore designed to support writing programs as much as possible in terms of pure functions:
Whereas procedural languages model execution of the program as a sequence of imperative commands that may implicitly alter shared state, functional programming languages model execution as the evaluation of complex expressions that only depend on each other in terms of arguments and return values. For this reason, functional programs can have a free order of code execution, and the languages may offer little control over the order in which various parts of the program are executed. (For example, the arguments to a procedure invocation in Scheme are executed in an arbitrary order.)
Functional programming languages support (and heavily use) first-class functions, anonymous functions and closures, although these concepts are being included in newer procedural languages.
Functional programming languages tend to rely on tail call optimization and higher-order functions instead of imperative looping constructs.
Many functional languages, however, are in fact impurely functional and offer imperative/procedural constructs that allow the programmer to write programs in procedural style, or in a combination of both styles. It is common for input/output code in functional languages to be written in a procedural style.
There do exist a few esoteric functional languages (like Unlambda) that eschew structured programming precepts for the sake of being difficult to program in (and therefore challenging). These languages are the exception to the common ground between procedural and functional languages.


















Good abstractions let us compute effectively by simplifying complexity.
Conventional ‘high level’ languages do not provide significant abstraction from machine language.
Notations must map straightforwardly to machine code, minor errors cause critical faults.

ML supports functional programming,
Functional programming: programs consist of functions operating on simple data structures.
Programming tasks can be approached mathematically, without preoccupation with the computer’s internal workings.

ML also provides mutable variables and arrays.
Mutable objects can be updated using an assignment command;
using them, any piece of conventional code can be expressed easily.

For structuring large systems, ML modules allow program parts to  be specified and coded separately.

Most importantly of all, ML protects programmers from their own errors.
Before a program may run, the compiler checks that all module interfaces agree and that data are used consistently.
For example, an integer may not be used as a store address.

At execution, further checking ensures safety: even faulty ML programs behave as ML programs.
It might run forever and it might return with an error message. But it cannot crash.

ML supports a level of abstraction that is oriented to the requirements of the programmer, not those of the hardware. The ML system can preserve this abstraction, even if the program is faulty. Few other languages offer such assurances.
Functional Programming
Languages like Fortran, Pascal and C are called procedural: programming unit is the procedure.

A refinement centres on objects that pair their own operations, object-oriented languages like C++.

Both approaches are imperative, they rely on commands that act upon the machine state.

procedural languages are oriented around commands,
functional languages are oriented around expressions.







1.1 Expressions versus commands
Fortran was the first high-level programming language, it gave programmers the arithmetic expression.
No longer did they have to code sequences of additions, loads and stores on registers:

We consider the advantages of expressions, note expressions in Fortran can have side effects, side effects can change the state.

We shall focus on pure expressions, which merely compute a value.
Expressions have a recursive structure.

The expression

f(E1 + E2) - g(E3)

is built of expressions E1, E2 and E3, and may itself be part of one.

The value of an expression is given recursively in terms of its subexpression values.

The subexpressions can be evaluated in any order, or even in parallel.

Expressions can be transformed using mathematical laws.

For instance, replacing E1 + E2 by E2 + E1 does not affect the value of the expression above, thanks to the commutative law of addition.

This ability to substitute equals for equals is called referential transparency.

In particular, an expression may safely be replaced by its value.
Commands share most of these advantages.
In modern languages, commands are built out of other commands.
The meaning of a command that follows can be given in terms of the meanings of its parts:
while B1 do (if B2 then C1 else C2)
Commands even enjoy referential transparency: laws can be proved and applied as substitutions.
(if B then C1 else C2); C ≡ if B then (C1; C ) else (C2; C )

However, the meaning of an expression is simply the result of evaluating it, this is why subexpressions can be evaluated independently of each other.

The meaning of an expression can be extremely simple, like the number 3.
The meaning of a command is a state transformation or something equally complicated.
To understand a command, you have to understand its full effect on the machine’s state.

In a purely functional language there is no state. Expressions satisfy the usual mathematical laws, up to the limitations of the machine (for example, real arithmetic is approximate). Purely functional programs can also be written in Standard ML. However, ML is not pure because of its assignments and input/output commands. The ML programmer whose style is ‘almost’ functional had better not be lulled into a false sense of referential transparency






1.3 Storage management
To avoid copying large objects, we can reference them indirectly.
We allocate storage space for our data, and return its address as a reference.

When we are finished with the data, we deallocate (release) storage.
If we prematurely reallocate storage, simultaneous use causes elusive errors.
If we never deallocate storage, we leak and may exhaust memory space.

Yet many basic data structures, such as the linked list, require references.
Functional languages like SML, and some others, use garbage collection to manage references.

Garbage collection runtime system service that manages storage through periodic scans mark accessible objects and reclaims the others.

Garbage collection can be slow and may require additional space, but it pays dividends.

Languages with garbage collection typically use references heavily in their internal representation of data. A function that ‘returns’ an employee record actually abstracts underlying data, returning a reference, the programmer is productive, freed of storage management, with greater expressive power.







1.4 Elements of a functional language
Functional programs effect values, not system state, by evaluating expressions, not commands.
Lists and trees.
Lists are collections of the form    [a, b, c, d, e, . . .].
Lists support sequential access, left to right.

A more flexible way of organizing data is as a tree:
         d
       /   \
      b     f
     / \   / \
    a   c e   g

Lists and trees are represented using references, so the runtime system uses a garbage collector.

Functions.
Expressions consist mainly of function applications.
Functions may take any type of arguments and return any type of result.
‘any type’ includes functions themselves, which can be treated like other data;
making this work also requires a garbage collector.
Recursion.
Functional variables obtain their values from outside by function call or by declaration.
They cannot be updated, but recursive calls can produce a changing series of argument values.
Pattern-matching.
Most functional languages allow a function to analyse its argument using pattern-matching.

A function to count the elements of a list looks like this in ML:
fun length [] = 0
| length (x::xs) = 1 + length xs;
We instantly see that the length of the empty list ([]) is zero, and that the length of a list consisting of the element x prefixed to the list xs is the length of xs plus one.

Expressing such functions without using patterns is terribly cumbersome, ML compilers do so internally.
Polymorphic type checking.
Programmers, being human, often err. Fortunately, the compiler can detect them before the program runs, provided the language enforces a type discipline.

Types classify data, to ensure sensible use. Some programmers find type checking to restrictive.
In Pascal, a function to compute the length of a list must specify the type of the list’s elements.

Our ML length function works for all lists because ML’s type system is polymorphic.
The price of this freedom is hours spent hunting errors that might have been caught automatically.
Higher-order functions
Functions themselves are computational values. Even Fortran lets a function be passed as an argument to another function, but few procedural languages let function values play a full role as data structures.
A higher-order function (or functional) is a function that operates on other functions.
The functional map, when applied to a function f , returns another function; that function takes
[x1, ..., xn] to [f(x1), ..., f(xn)]

Another higher-order function, function f and value e, returns
f(x1, f(x2, ... f(xe)...))
If e = 0 and f = + then we get the sum of x1, . . . , xn, computed by
x1 + (x2 +  ... + (xn + 0)...)

If e = 1 and f = × then we get their product, computed by
x1 × (x2 ×  ... × (xn × 1)...)

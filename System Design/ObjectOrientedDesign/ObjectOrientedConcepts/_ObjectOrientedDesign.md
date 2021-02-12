For an overview of the Object Oriented programming paradigm see:
[Programming Methods\Paradigms\Imperative\Object-Oriented.md]

All programming languages provide abstractions. It can be argued that the complexity of the problems you’re able to solve is directly related to the kind and quality of abstraction. By “kind” I mean, “What is it that you are abstracting?” Assembly language is a small abstraction of the underlying machine. Many so-called “imperative” languages that followed (such as Fortran, BASIC, and C) were abstractions of assembly language. These languages are big improvements over assembly language, but their primary abstraction still requires you to think in terms of the structure of the computer rather than the structure of the problem you are trying to solve.

The programmer must establish the association between the machine model (in the “solution space,” which is the place where you’re modeling that problem, such as a computer) and the model of the problem that is actually being solved (in the “problem space,” which is the place where the problem exists).

The effort required to perform this mapping, and the fact that it is extrinsic to the programming language, produces programs that are difficult to write and expensive to maintain, and as a side effect created the entire “programming methods” industry.

The alternative to modeling the machine is to model the problem you’re trying to solve.

Early languages such as LISP and APL chose particular views of the world (“All problems are ultimately lists” or “All problems are algorithmic”). PROLOG casts all problems into chains of decisions. Languages have been created for constraint-based programming and for programming exclusively by manipulating graphical symbols. (The latter proved to be too restrictive.) Each of these approaches is a good solution to the particular class of problem they’re designed to solve, but when you step outside of that domain they become awkward.

The object-oriented approach goes a step farther by providing tools for the programmer to represent elements in the problem space. This representation is general enough that the programmer is not constrained to any particular type of problem. We refer to the elements in the problem space and their representations in the solution space as “objects”.

The idea is that the program is allowed to adapt itself to the lingo of the problem by adding new types of objects, so when you read the code describing the solution, you’re reading words that also express the problem. This is a more flexible and powerful language abstraction than what we’ve had before.

Thus, OOP allows you to describe the problem in terms of the problem, rather than in terms of the computer where the solution will run.

There’s still a connection back to the computer, though. Each object looks quite a bit like a little computer; it has a state, and it has operations that you can ask it to perform. However, this doesn’t seem like such a bad analogy to objects in the real world; they all have characteristics and behaviors.

Object-oriented design is the discipline of defining the objects and their interactions to solve a problem.

Exactly how object-oriented programming is implemented differs from language to language. Languages that support object-orientation will also sometimes have slightly different rules for how object-orientation is used. As always, we will need to learn how the language we are using has defined the object-oriented principles.

There are languages that are object-based, which means that they have objects. This, however, is only part of the picture when it comes to an object-oriented language, and languages that stop at packaging functions inside data structures are object-based, not object-oriented.


Topics
  Abstraction
    Encapsulation
    Information Hiding
    Inheritance
    Polymorphism
    Modularity
    Generics
    Relationships

  Classes
    Message Passing
    Specialized Objects
    Class Design
    Design Process

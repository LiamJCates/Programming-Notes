Type System

Typed versus untyped languages
A language is typed if the specification of every operation defines types of data to which the operation is applicable.

A type system defines how a programming language classifies values into types, how it can manipulate those types and how they interact. The goal of a type system is to verify and usually enforce a level of correctness by detecting certain incorrect operations.

The hardware of a general purpose computer is unable to discriminate between for example a memory address and an instruction code, or between a character, an integer, or a floating-point number, because it makes no intrinsic distinction between any of the possible values that a sequence of bits might mean.

With a type system, assigning a data type, termed typing, gives meaning to a sequence of bits such as a value in memory or some object such as a variable.

Associating a sequence of bits with a type conveys that meaning to the programmable hardware to form a symbolic system composed of that hardware and some program.

The type system associates a type with each computed value and, by examining the flow of these values, attempts to ensure or prove that no type errors can occur. A programming language's type system determines what constitutes a type error, but in general the aim is to prevent operations expecting a certain kind of value from being used with values for which that operation does not make sense (logic errors). Type systems are often specified as part of programming languages and built into interpreters and compilers.

The main purpose of a type system is to reduce possibilities for bugs in computer programs. A type system does this by defining interfaces, specified by expected types, between different parts of a computer program. The type system is used to check that the parts have been connected in a way remain consistent.


Checking
This checking can happen statically (at compile time), dynamically (at run time), or as a combination of both.

An invalid operation may be detected when the program is either
  compiled ("static" type checking), resulting in a compilation error
  run ("dynamic" type checking), resulting in a run-time exception

Many languages allow a function called an exception handler to handle run-time exceptions

Any decidable type system involves a trade-off: while it rejects many incorrect programs, it can also prohibit some correct, albeit unusual programs.

In order to bypass this downside, a number of languages have type loopholes, usually unchecked casts that may be used by the programmer to explicitly allow a normally disallowed operation between different types.

In most typed languages, the type system is used only to type check programs, but a number of languages, usually functional ones, infer types, relieving the programmer from the need to write type annotations.

The compiler performs type checking during the first pass. Type
checking tests for the proper use of arguments in functions and
prevents many kinds of programming errors. Since type checking
occurs during compilation instead of when the program is running,
it is called static type checking.
Some object-oriented languages (notably Java) perform some type
checking at runtime (dynamic type checking). If combined with static
type checking, dynamic type checking is more powerful than static
type checking alone. However, it also adds overhead to program
execution.
C++ uses static type checking because the language cannot assume
any particular runtime support for bad operations. Static type
checking notifies the programmer about misuses of types during
compilation, and thus maximizes execution speed. As you learn
C++, you will see that most of the language design decisions favor
the same kind of high-speed, production-oriented programming
the C language is famous for.
You can disable static type checking in C++. You can also do your
own dynamic type checking – you just need to write the code.

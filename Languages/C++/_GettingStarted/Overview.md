C++ is a programming language developed by Bjarne Stroustrup originating in 1979 at Bell Labs.

Initially, C++ was designed to be an object-oriented successor to C, most C code is valid in C++.
However, in the strict mathematical sense, C isn't a subset of C++. There are programs that are valid C but not valid C++ and even a few ways of writing code that has a different meaning in C and C++.

Examples:
http://david.tribble.com/text/cdiffs.htm


### Why Learn C++

Learning C++ is valuable because it provides a strong foundation in programming concepts, is widely used in performance-critical applications due to its high speed and efficiency, offers low-level hardware control, and thus opens doors to a variety of career paths in software development, particularly in areas like game development, system programming, and embedded systems

C++ programming gives you a clear understanding about Object Oriented Programming. You will understand low level implementation of polymorphism when you will implement virtual tables and virtual table pointers, or dynamic type identification.

C++ is very popular

C++ is a widely used programming languages in application and system programming. So you can choose your area of interest of software development.

C++ really teaches you the difference between compiler, linker and loader, different data types, storage classes, variable types their scopes etc.



### C and C++’s philosophy

The underlying design philosophy of C and C++ can be summed up as “trust the programmer” -- which is powerful and dangerous.

C++ is designed to allow the programmer a high degree of freedom to do what they want. However, this also means the language often won’t stop you from doing things that don’t make sense, because it will assume you’re doing so with reason. There are quite a few pitfalls for new programmers, knowing what you shouldn’t do in C/C++ is almost as important as knowing what you should do.

### C++ Characteristics

C++ is a mid-level, statically typed, compiled, general-purpose, case-sensitive, free-form programming language that supports procedural, object-oriented, and generic programming.


middle-level
C++ is regarded as a middle-level language, as it comprises a combination of both high-level and low-level language features.

statically typed
The type of every C++ entity (object, value, expression, etc...) must be known to the compiler at its point of use. The type of an object determines the set of operations applicable to it.

compiled
A C++ program's source code must be processed by the compiler tool chain into an executable program.

general-purpose
C++ is a programming language dedicated to a general-purpose, designed to be used for writing software in a wide variety of application domains.

case-sensitive
case sensitivity defines whether uppercase and lowercase letters are treated as distinct (case-sensitive) or equivalent (case-insensitive).

free-form
A free-form language is a programming language in which the positioning of characters on the page in program text is unimportant and whitespace characters are used only to delimit tokens, and have no other significance.

procedural
derived from structured programming, based on the concept of the procedure call. Procedures or subroutines, simply contain a series of computational steps to be carried out. Any given procedure (within scope) might be called at any point during a program's execution.

object-oriented
Initially C++ was designed to be an object-oriented successor to C that implements concepts such as inheritance, abstraction, polymorphism, and encapsulation.

generic
Generic programming is a style of computer programming in which algorithms are written in terms of types to-be-specified-later that are then instantiated when needed for specific types provided as parameters.








### C++ Standards

While there is no single organization that controls all of C++, individual vendors and communities implement the International Organization for Standardization (ISO) standard which determines the syntax and semantics of the C++ language

C++ was standardized in 1998 by the ISO committee (this means the ISO committee ratified a document describing the C++ language, to help ensure all compilers adhered to the same set of standards).

A minor update was released in 2003 (called C++03).

Four major updates to the C++ language (C++11, C++14, C++17, and C++20 ratified in 2011, 2014, 2017, and 2020 accordingly) have been made since then, each adding additional functionality. C++11 in particular added a huge number of new capabilities, and at this point is widely considered the new baseline.

Upgrades by the ISO committee are expected every three or so years.

Each new formal release is called a language standard (or language specification). Standards are named after the year they are released. For example, there is no C++15, because there was no new standard in 2015.

It is suggested that projects always used the most recent implementation of the standard.



The ISO C++ standard defines two kinds of entities:
  • Core language features, such as built-in types (e.g., char and int) and loops (e.g., for-statements and while-statements)
  • Standard-library components, such as containers (e.g., vector and map) and I/O operations (e.g., << and getline())

The standard-library components are perfectly ordinary C++ code provided by every C++ implementation. That is, the C++ standard library can be implemented in C++ itself and is (with very minor uses of machine code for things such as thread context switching). This implies that C++ is sufficiently expressive and efficient for the most demanding systems programming tasks.






The following list shows some application types:

✦ GTK+ Project: This is a graphical application that includes, well, a window.
You know the kind: It usually has a menu across the top and something
inside it that you can either click or type into. It relies on the Gimp Toolkit (GTK), which provides an incredibly flexible interface that runs on a number of platforms including Linux, Mac, and Windows systems.

✦ Console Application: This is an application that is represented within a Console window instead of a graphical window. Console refers to a window with a command prompt. (You may know it as a terminal window when working
with operating systems such as the Mac or Linux.)

✦ Static library: A static library is a set of C++ code that you use later in another project.

✦ Dynamic Link Library: A Dynamic Link Library (DLL) is kind of like a
static library except it is separated from the main application and gets
its own file with a .DLL extension.

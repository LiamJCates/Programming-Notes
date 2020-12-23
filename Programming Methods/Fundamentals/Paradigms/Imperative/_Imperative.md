Imperative
In computer science, imperative programming is a programming paradigm that uses statements that change a program's state.

The imperative paradigm has two main features:
  they use constructs that explicitly control that order in which operations occur
  they allow side effects, in which state can be modified at one point in time, within one unit of code, and then later read at a different point in time inside a different unit of code. The communication between the units of code is not explicit.

The term is often used in contrast to declarative programming, which focuses on what the program should accomplish without specifying how the program should achieve the result.


## The Imperative Mood
In natural language, or ordinary language, any language that has evolved naturally in humans, there is an imperative mood. The imperative mood is something that forms a command, such as Move!, Don't be late!, or Work hard!.

In much the same way that the imperative mood in natural languages expresses commands, an imperative program consists of commands for the computer to perform. Imperative programming focuses on describing how a program operates.


## Program State
A program is said to have a state if it remembers previous events that have occurred. A program stores data in variables. At any given point, during the program's execution, we can look at the data that is currently in all the variables we have defined. The combined value in all these variables is what makes up the state of the program. If we change one variable, the state of the program will also change. When we are talking about imperative programming, we mean that as soon as a statement changes the content of a variable, it has changed the program state. This is what forms the memory of preceding events. When an event – a statement, in our case – occurs and it changes a variable, it will affect the behavior of the program.











Imperative programming
Procedural programming languages are also imperative languages, because they make explicit references to the state of the execution environment. This could be anything from variables (which may correspond to processor registers) to something like the position of the "turtle" in the Logo programming language.
Often, the terms "procedural programming" and "imperative programming" are used synonymously. However, procedural programming relies heavily on blocks and scope, whereas imperative programming as a whole may or may not have such features. As such, procedural languages generally use reserved words that act on blocks, such as if, while, and for, to implement control flow, whereas non-structured imperative languages use goto statements and branch tables for the same purpose.

Object-oriented programming
The focus of procedural programming is to break down a programming task into a collection of variables, data structures, and subroutines, whereas in object-oriented programming it is to break down a programming task into objects that expose behavior (methods) and data (members or attributes) using interfaces. The most important distinction is that while procedural programming uses procedures to operate on data structures, object-oriented programming bundles the two together, so an "object", which is an instance of a class, operates on its "own" data structure.[2]
Nomenclature varies between the two, although they have similar semantics:
| Procedural | Object-oriented |
|------------|-----------------|
| procedure | method |
| record | object |
| module | class |
| procedure call | message |








Comparing imperative and structured programming
Programs written in assembly language use a concept known as GOTOs. It is a technique that's used to control the flow in a program. To use them, we insert labels into the code, and we can then instruct the program to jump to one such label and resume its execution there.


Today, it is, under most circumstances, considered a bad practice to use GOTOs as the code will be hard to read, understand, and maintain. There is hardly ever any need to perform a GOTO as languages such as BASIC and C support constructs that can let us achieve the same result and maintain good code quality. Using this style of programming was what first defined imperative programming. As programming languages developed and we got other tools, such as loops, if statements, and functions, there was a need to distinguish these more modern languages from the older style. Even though these programming languages use the same ideas as assembly language, these statements will change the state of the program. This is because they no longer rely on jumps or GOTOs to accomplish this. This was when we got the definition structured programming. A language that supports structured programming is a language that modifies the state of the program using statements and has functions, loops, and if statements as tools to accomplish this.

We will sometimes also hear the terms procedural and modular languages. There is no need to go into the details of what the difference is between these as this is mostly academic. We can safely consider all these the same thing.

Imperative and procedural programming
Procedural programming is a type of imperative programming in which the program is built from one or more procedures (also termed subroutines or functions). The terms are often used as synonyms, but the use of procedures has a dramatic effect on how imperative programs appear and how they are constructed. Heavily procedural programming, in which state changes are localized to procedures or restricted to explicit arguments and returns from procedures, is a form of structured programming.


structured programming and modular programming in general have been promoted as techniques to improve the maintainability and overall quality of imperative programs. The concepts behind object-oriented programming attempt to extend this approach.

Procedural programming could be considered a step toward declarative programming. A programmer can often tell, simply by looking at the names, arguments, and return types of procedures (and related comments), what a particular procedure is supposed to do, without necessarily looking at the details of how it achieves its result. At the same time, a complete program is still imperative since it fixes the statements to be executed and their order of execution to a large extent.




Rationale and foundations of imperative programming

The hardware implementation of almost all computers is imperative.[note 1] Nearly all computer hardware is designed to execute machine code, which is native to the computer and is written in the imperative style. From this low-level perspective, the program state is defined by the contents of memory, and the statements are instructions in the native machine language of the computer. Higher-level imperative languages use variables and more complex statements, but still follow the same paradigm. Recipes and process checklists, while not computer programs, are also familiar concepts that are similar in style to imperative programming; each step is an instruction, and the physical world holds the state. Since the basic ideas of imperative programming are both conceptually familiar and directly embodied in the hardware, most computer languages are in the imperative style.

Assignment statements, in imperative paradigm, perform an operation on information located in memory and store the results in memory for later use. High-level imperative languages, in addition, permit the evaluation of complex expressions, which may consist of a combination of arithmetic operations and function evaluations, and the assignment of the resulting value to memory. Looping statements (as in while loops, do while loops, and for loops) allow a sequence of statements to be executed multiple times. Loops can either execute the statements they contain a predefined number of times, or they can execute them repeatedly until some condition changes. Conditional branching statements allow a sequence of statements to be executed only if some condition is met. Otherwise, the statements are skipped and the execution sequence continues from the statement following them. Unconditional branching statements allow an execution sequence to be transferred to another part of a program. These include the jump (called goto in many languages), switch, and the subprogram, subroutine, or procedure call (which usually returns to the next statement after the call).

Early in the development of high-level programming languages, the introduction of the block enabled the construction of programs in which a group of statements and declarations could be treated as if they were one statement. This, alongside the introduction of subroutines, enabled complex structures to be expressed by hierarchical decomposition into simpler procedural structures.

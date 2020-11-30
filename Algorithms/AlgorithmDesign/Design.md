Conceptual Design
The purpose of any application is to get some data as
input, process or operate on it, and then provide suitable data as output.

Most generally, an algorithm is a set of rules that precisely defines a sequence of operations to achieve a result.

Long before the computer age, and indeed, throughout all of recorded history, individuals have found it practical to establish procedures for the completion of tasks. The more efficient in terms of time, effort and resources spent to achieve the result or to document, convey, or learn the underlying techniques, the more favorable a methodology is found to be.

This, essentially, is what algorithm design seeks to achieve.

When designers attempt to develop an algorithm to complete some task, they break down that task, outline the steps required to resolve it, then record the series of basic operations to accomplish those steps.

Typical steps in the development of algorithms:
Problem definition
Development of a model
Specification of the algorithm
Designing an algorithm
Checking the correctness of the algorithm https://en.wikipedia.org/wiki/Correctness_(computer_science)
Analysis of the algorithm
Implementation of the algorithm
Program testing
Documentation



The procedures described by an algorithm are generally created independent of the method of expression. For any algorithm said to solve some problem, we can implement its operations in any full featured programming language. The procedure captured by the algorithm's specification is said to be independent from any programming languages. The technique used to provide a language independent description of an algorithm is called Pseudocode.


The planning of computer program development, textbooks, and scientific publications related to computation often use pseudocode for the description of algorithms.

Pseudocode gives a high-level description of an algorithm using the structural conventions of a normal programming language, but is intended for human reading rather than machine reading. Typically omitting those details essential for machine understanding of the algorithm, such as variable declarations, system-specific code and subroutines, pseudocode employs natural language descriptions and general mathematical notation where convenient.



The use of pseudocode allows programmers to understand processes it expresses via an efficient and environment-independent description of the key principles of an algorithm without having to share a common programming language.

While no one standard for pseudocode syntax exists, in textbooks, there is usually an accompanying introduction explaining the particular conventions in use.

An example standard:    pseudocode-standard.pdf
General Guidelines:    pseudocode.pdf


A programmer who needs to implement a specific algorithm, especially an unfamiliar one, will often start with a high level description followed by a (Quasi-)formal description that may easily be translated into programming language.

Example https://en.wikipedia.org/wiki/Algorithm#Algorithm_example





Now that we understand the development steps and a method of expression, how do we know that our design is  a good one?

In the traditional study of algorithms, there are two main criteria for judging the merits of algorithms.
Efficiency: cost in resources, like memory space and execution time, to execute the algorithm.
Correctness: does the algorithm give a solution to the problem in a finite number of steps.


The term "analysis of algorithms" was coined by the computer scientist Donald Knuth. Algorithm analysis provides theoretical estimates for the resources needed by any algorithm which solves a given computational problem. These estimates provide an insight into reasonable directions of search for efficient algorithms. Efficiency is a topic of great interest in computer science: A program can take seconds, hours, or even years to finish executing, depending on which algorithm it implements.

We will talk more about efficiency here (link to analysis)


What if we were to remove the restrictions of efficiency and suppose computers had infinite memory space and instantaneous execution speed, would we still need to study algorithms?
Yes, to ensure correctness


A correct algorithm will solve the problem it is stated to address. An algorithm is said to be correct if its execution halts with correct output, for every unique input configuration that satisfies the algorithm's requirements, called a problem instance. An incorrect algorithm might never halt, or may halt with an incorrect answer, as such, proving correctness is a necessary step in algorithm design.

As we explore the methods of algorithm design, careful attention is given to demonstrating algorithms that are correct and efficient.


There exist many methods of algorithm design
Algorithm Design Paradigms

An algorithm paradigm or algorithm design paradigm is a generic model or framework which underlies the design of a class of algorithms. An algorithmic paradigm is an abstraction higher than the notion of an algorithm, just as an algorithm is an abstraction higher than a computer program.

Design paradigms are a collection of methods used to develop a mathematically proven process for solving a problem which may then be expressed as an algorithm.
https://en.wikipedia.org/wiki/Algorithm#Expressing_algorithms

General techniques

There are many broadly recognized algorithmic techniques that offer a proven method or process for designing and constructing algorithms.

Brute force
Brute force is a simple, exhaustive technique that evaluates every possible outcome to find a solution.

Divide and conquer
The divide and conquer technique decomposes complex problems into smaller sub-problems. Each sub-problem is then solved and these partial solutions are recombined to determine the overall solution. This technique is often used for searching and sorting.

Dynamic
Dynamic programming is a systematic technique in which a complex problem is decomposed into smaller, overlapping subproblems for solution. Dynamic programming stores the results of the overlapping subproblems so that they are not required to be completed more than once.

Evolutionary
An evolutionary approach develops candidate solutions and then, in a manner similar to biological evolution, performs a series of random alterations or combinations of these solutions and evaluates the new results against a fitness function. The most fit or promising results are selected for additional exploration, to achieve an overall optimal solution.

Graph traversal
Graph traversal is a technique for finding solutions to problems that can be represented as graphs. This approach is broad, and includes depth-first search, breadth-first search, tree traversal, and many specific variations that may include local optimizations and excluding search spaces that can be determined to be non-optimum or not possible. These techniques may be used to solve a variety of problems including shortest path and constraint satisfaction problems.

Greedy
A greedy approach begins by evaluating one possible outcome from the set of possible outcomes, and then searches locally for an improvement on that outcome. When a local improvement is found, it will repeat the process and again search locally for additional improvements near this local optimum. A greedy technique is generally simple to implement, and these series of decisions can be used to find local optimums depending on where the search began. However, greedy techniques may not identify the global optimum across the entire set of possible outcomes.



Recursion
Recursion is a general technique for designing an algorithm that calls itself with a progressively simpler part of the task down to one or more base cases with defined results.






Additional Methods
Backtracking https://en.wikipedia.org/wiki/Backtracking
Branch and bound https://en.wikipedia.org/wiki/Branch_and_bound
Prune and search https://en.wikipedia.org/wiki/Prune_and_search

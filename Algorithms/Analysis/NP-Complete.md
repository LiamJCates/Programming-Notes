Complexity Theory

The goal of complexity theory is to understand the nature of efficient computation.
analysis of algorithms enables us to classify algorithms according to the amount of resources they will consume.
A nice YouTube video on P = NP:
https://www.youtube.com/watch?v=YX40hbAHx3s

Computational complexity.
Computational complexity is the art and science of determining resource requirements for different problems. Computational complexity deals with assertions about any conceivable algorithm for a problem. Making such statements is significantly more challenging than understanding the running time of one particular algorithm for the problem since we must reason about all possible algorithms (even those not yet discovered).

As digital computers were developed in the 1940s and 1950s, the Turing machine served as the theoretical model of computation.

In the 1960s Hartmanis and Stearns proposed measuring the time and memory needed by a computer as a function of the input size.

They defined complexity classes in terms of Turing machines and proved that some problems have "an inherent complexity that cannot be circumvented by clever programming."

They also proved a formal version, time hierarchy theorem, of the intuitive idea that if given more time or space, Turing machines can solve more problems. For example, there are problems that can be solved with n2 time but not n time.

In other words, no matter how hard a problem is (time and space requirements), there are always harder problems.


Polynomial-time.
We refer to any algorithm whose running time is bounded by a polynomial in the input size (e.g., N log N or N^2) as a polynomial-time algorithm.

For example, a brute force algorithm for the TSP might take N! steps. Even if each electron in the universe (1079) had the power of today's fastest supercomputer (1012 instructions per second), and each worked for the life of the universe (1017 seconds) on solving the problem, it would barely make a dent in solving a problem with N = 1,000 since 1000! >> 101000 >> 1079 * 1012 * 1017. Exponential growth dwarfs technological change.

As programmers gained more experience with computation, it became evident that polynomial-time algorithms were useful and exponential-time algorithms were not.

 We say that a problem is intractable if there is no polynomial-time algorithm for the problem.
The idea of classifying problems according to polynomial and exponential time profoundly changed the way people thought about computational problems.

NP.
Informally we define a search problem as a computational problem where we are looking for a solution among a (potentially huge) number of possibilities, but such that when we find a solution, we can easily check that it solves our problem. Given an instance I of a search problem (some input data specifying the problem), our goal is to find a solution S (an entity that meets some pre-specified criterion) or report that no such solution exists. To be a search problem, we require that it be easy to check that S is indeed a solution. By easy, we mean polynomial-time in the size of the input I. The complexity class NP is the set of all search problems.


NP- Complete

two characteristics common to algorithmic problems...
many candidate solutions, practical applications

Why are NP-complete problems interesting?
Nobody knows whether efficient algorithms exist for NP-complete problems.
nobody has proven that an efficient algorithm for NP-complete problems cannot exist.

The set of NP-complete problem algorithms has the remarkable property that if an efficient algorithm exists for one of them, efficient algorithms exist for all of them.

Several NP-complete problems are similar, to problems with existing efficient algorithms
This shows that  a small change to the problem statement can cause a big change to the efficiency of the best known algorithm.
Example: shortest-path and traveling-salesman problems

You should know NP-complete problem definitions and situations because some of them arise surprisingly often in real applications.

If you are called upon to produce an efficient algorithm for an NP-complete problem, you are
likely to spend a lot of time in a fruitless search.

However NP-complete problems, under certain assumptions, has approximate algorithms that give
a result not too far above the smallest possible.
If you can show that the problem is NP-complete, you can instead
spend your time developing an efficient estimate algorithm

“traveling-salesman problem,”
Each day, delivery trucks make their drop, then return to the depot.
Select an order of stops with the lowest overall distance traveled by each truck.

“traveling-salesman problem,” is NP-complete meaning it's solution has no known efficient algorithm.

How are the shortest-path and traveling-salesman problems similar?
The correct solution to both selects an order of stops with the lowest overall distance traveled.

How are the shortest-path and traveling-salesman problems different?
Shortest path has a discrete start and end point, TSM requires they be the same.
Shortest path is polynomially solvable but travelling -salesman is NP-Complete
Almost all the algorithms we have studied thus far have been polynomial-time algorithms: on inputs of size n, their worst-case running time is O(n^k) for some constant k.

Not all problems can be solved in polynomial time.
For example, there are problems, such as Turing’s famous “Halting Problem,” that cannot be solved by any computer, no matter how much time we allow.

There are also problems that can be solved, but not in time O(n^k) for any constant k.

Generally, we think of problems that are solvable by polynomial-time algorithms as being tractable, or easy, and problems that require superpolynomial time as being intractable, or hard.

The subject of this chapter, however, is an interesting class of problems, called the “NP-complete” problems, whose status is unknown.

No polynomial-time algorithm has yet been discovered for an NP-complete problem, nor has anyone yet been able to prove that no polynomial-time algorithm can exist for any one of them.

This so-called P ≠ NP question has been one of the deepest, most perplexing open research problems in theoretical computer science since it was first posed in 1971.

Most theoretical computer scientists believe that the NP-complete problems are intractable, since given the wide range of NP-complete problems that have been studied to date—without anyone having discovered a polynomial time solution to any of them—it would be truly astounding if all of them could be solved in polynomial time.

It is fascinating that some of these problems have very simple definition and some are very similar to problems that are known to have polynomial-time algorithms, yet they are harder to solve.




Several NP-complete problems are particularly tantalizing because they seem on the surface to be similar to problems that we know how to solve in polynomial time. In each of the following pairs of problems, one is solvable in polynomial time and the other is NP-complete, but the difference between problems appears to be slight:

Shortest vs. longest simple paths:
Even with negative edge weights, we can find shortest paths from a single source in a directed graph G =(V, E) in O(VE) time. Finding a longest simple path between two vertices is difficult, however. Merely determining whether a graph contains a simple path with at least a given number of edges is NP-complete.

Euler tour vs. hamiltonian cycle:

In a strongly connected directed graph a Euler tour is a cycle that visits
each edge of a graph once (it can visit vertices more than once though); determining whether a graph has a Euler tour is a polynomial-time problem.

An Euler tour of a connected, directed graph G = (V, E) is a cycle that traverses each edge of G exactly once, although it is allowed to visit each vertex more than once.
We can determine whether a graph has an Euler tour in only O(E) time
We can find the edges of the Euler tour in O(E) time.

A hamiltonian cycle of a directed graph G = (V, E) is a simple cycle that contains every vertex.
Determining whether a directed graph has a hamiltonian cycle is NP-complete.
The problem of determining whether a graph has a Hamiltonian cycle, called the Hamiltonian
Cycle Problem, is an NP-complete problem.



2—CNF satisfiability vs. 3-CNF satisfiability:
A boolean formula contains variables whose values are 0 or 1;
boolean connectives are
 & ∧ (AND), ∨ + ∥ (OR), and ¬ ~ ! (NOT) are...

A boolean formula is satisfiable if there exists some assignment Of the values 0 and 1 to its variables that causes it to evaluate to 1.

Informally, a boolean formula is in k-conjunctive normal form, or k-CNF, if it is the AND Of clauses Of ORS Of exactly k variables or their negations.

For example, the boolean formula (x1 ∨ ¬x2) ∧ (¬x1 ∨ x3) ∧ (¬x2 ∨ ¬x3) is in 2-CNE (It has
the satisfying assignment x1 = 1, x2 = 0, x3 = 1

Although we can determine in polynomial time whether a 2-CNF formula is satisfiable, determining whether a 3-CNF formula is satisfiable is NP-complete.



NP-completeness and the classes P and NP

Three classes of algorithmic problems: P, NP, and NPC,

The class P consists of those problems that are solvable in polynomial time.

More specifically, class P problems can be solved in time O(n^k) for some constant k, where n is the size of the input to the problem.

The class NP consists of those problems that are “verifiable” in polynomial time.

What do we mean by a problem being verifiable? If we were somehow given a “certificate” of a solution, then we could verify that the certificate is correct in time polynomial in the size of the input to the problem.

A problem is verifiable if there is a verifying algorithm for that problem that runs in polynomial time.

A verifying algorithm takes two "arguments": the regular input to the problem and an assumed/proposed solution (called "certificate" or "witness"); it then verifies the correctness of the proposed solution.

For example, in the hamiltonian cycle problem, given a directed graph G = (V, E), a certificate would be a sequence <v1, v2, v3… v|V|> of |V| vertices.

We could easily check in polynomial time that (vi, vi+1) ∈ E for i = 1, 2, 3… |V| - 1 and that (v|v| , v1) ∈ E as well.

As another example, for 3-CNF satisfiability, a certificate would be an assignment of values to variables. We could check in polynomial time that this assignment satisfies the boolean formula.

Any problem in P is also in NP, since if a problem is in P then we can solve it in polynomial time without even being supplied a certificate.
if a problem can be solved in polynomial time then it can be verified in polynomial time as well (we can solve the problem and compare the solution to the proposed solution, spending polynomial time altogether).

The open question is whether or not P is a proper subset of NP.

The name NP comes from the expression "non-deterministically polynomial"

"non-deterministically polynomial" means that if we allow non-determinism in the procedure (at certain points during its execution, the procedure may have to make a choice out of possible options on how to continue), then assuming the algorithm would make the correct "lucky
guess" on each of the choice-points, it would solve the problem in a polynomial
time. This is another way of looking at problems contained in NP.

Class NPC: This is the class of NP-complete problems.

These are problems that are from NP but for whom there has not been found a polynomial-time algorithm yet. So, these problems are verifiable in polynomial time, but we don't know if they
are solvable in polynomial time or not. We say that these problems are at least as
"hard" as any problem in NP.

For a given problem, establishing that it is NP-complete is very valuable since it gives an indication that the problem likely is intractable and thus we may want to concentrate out time and energy on developing an approximation algorithm (to produce a "good enough" solution), or solving a tractable special case instead of spending time on finding a fast algorithm to solve the general problem exactly.

It is worth noting also that if the size of the input is small, a superpolynomial (e.g. exponential) algorithm can be perfectly acceptable.

 Informally, a problem is in the class NPC—and we refer to it as being NPcomplete—if it is in NP and is as “hard” as any problem in NP.

In the meantime, we will state without proof that if any NP-complete problem can be solved in polynomial time, then every problem in NP has a polynomial time algorithm.

Most theoretical computer scientists believe that the NP-complete problems are intractable, since given the wide range of NP-complete problems that have been studied to date—without anyone having discovered a polynomial time solution to any of them—it would be truly astounding if all of them could be solved in polynomial time.

Yet, given the effort devoted thus far to proving that NP-complete problems are intractable—without a conclusive outcome—we cannot rule out the possibility that the NP-complete problems are in fact solvable in polynomial time. To become a good algorithm designer, you must understand the rudiments of the theory of NP-completeness.

If you can establish a problem as NP-complete, you provide good evidence for its intractability.

As an engineer, you would then do better to spend your time developing an approximation algorithm (see Chapter 35) or solving a tractable special case, rather than searching for a fast algorithm that solves the problem exactly.

Moreover, many natural and interesting problems that on the surface seem no harder than sorting, graph searching, or network flow are in fact NP-complete. Therefore, you should become familiar with this remarkable class of problems.







Overview of showing problems to be NP-complete

The techniques we use to show that a particular problem is NP-complete differ fundamentally from the techniques used throughout most of this book to design and analyze algorithms. When we demonstrate that a problem is NP-complete, we are making a statement about how hard it is (or at least how hard we think it is), rather than about how easy it is. We are not trying to prove the existence of an efficient algorithm, but instead that no efficient algorithm is likely to exist.

We rely on three key concepts in showing a problem to be NP-complete:


Decision problems vs. optimization problems

Decision Problems: problems that have a yes/no answer (or, more formally, “1” or “0”) for every instance of a problem.

Here are some examples of decision problems:
Given a natural number n, determine if it is a perfect square.
Given a graph G and some u, v vertices, determine if there is a path from vertex u to vertex v.
Given x and y strings, determine if they have a common substring.

Many problems of interest are optimization problems in which each solution has a value and the goal is to obtain a solution with the best value.

Although optimization problems are not decision problems, there is a convenient relationship between them which allows us to cast an optimization problem as a related decision problem;

We cast a given optimization problem as a related decision problem by imposing a bound on the value to be optimized.

Optimization problem 1: Given a G graph and u, v vertices in it, find the shortest distance (length of the shortest path) from vertex u to vertex v.

Related Decision problem 1: Given a G graph, u, v vertices in it, and an integer k,
determine whether (length of the shortest path) from u vertex to v vertex is at most k

Optimization problem 2: Given x and y strings, find the longest common substring.

Related decision problem 2: Given x, y strings and an integer k, determine whether x
and y's longest common substring has at most k length.

Many problems of interest are optimization problems, in which each feasible (i.e., “legal”) solution has an associated value, and we wish to find a feasible solution with the best value.

NP-completeness applies directly to decision problems and not to optimization problems, however, we can take advantage of the convenient relationship between optimization problems and decision problems.

The relationship between an optimization problem and its related decision problem works in our favor when we try to show that the optimization problem is “hard.” That is because the decision problem is in a sense “easier,” or at least “no harder.”

Stated in a way that has more relevance to NP-completeness, if we can provide evidence that a decision problem is hard, we also provide evidence that its related optimization problem is hard.
Thus, even though it restricts attention to decision problems, the theory of NP-completeness often has implications for optimization problems as well.



Reductions

The above notion of showing that one problem is no harder or no easier than another applies even when both problems are decision problems. We take advantage of this idea in almost every NP-completeness proof, as follows.

Let us consider a decision problem A, which we would like to solve in polynomial time.

Now suppose that we already know how to solve a different decision problem B in polynomial time.
Finally, suppose that we have a procedure that transforms any instance 𝞪 of A into some instance 𝞫 of B with the following characteristics:
The transformation takes polynomial time.
The answers are the same. That is, the answer for 𝞪 is “yes” if and only if the answer for 𝞫 is also “yes.”

[Reduction.png]

Figure 34.1 How to use a polynomial-time reduction algorithm to solve a decision problem A in polynomial time, given a polynomial-time decision algorithm for another problem B.
In polynomial time, we transform an instance 𝞪 of A into an instance 𝞫 of B,
we solve B in polynomial time, and we use the answer for 𝞪 as the answer for 𝞫.

We call such a procedure a polynomial-time reduction algorithm and, as Figure 34.1 shows, it provides us a way to solve problem A in polynomial time:
1. Given an instance alpha of problem A, use a polynomial-time reduction algorithm to transform it to an instance 𝞫 of problem B.
2. Run the polynomial-time decision algorithm for B on the instance 𝞫.
3. Use the answer for 𝞫 as the answer for 𝞪.

As long as each of these steps takes polynomial time, all three together do also, and so we have a way to decide on 𝞪 in polynomial time.

By “reducing” solving problem A to solving problem B, we use the “easiness” of B to prove the “easiness” of A.

Recalling that NP-completeness is about showing how hard a problem is rather than how easy it is, we use polynomial-time reductions in the opposite way to show that a problem is NP-complete.

We could use polynomial-time reductions to show that no polynomial-time algorithm can exist for a particular problem B. Suppose we have a decision problem A for which we already know that no polynomial-time algorithm can exist. (Let us not concern ourselves for now with how to find such a problem A.) Suppose further that we have a polynomial-time reduction transforming instances of A to instances of B. Now we can use a simple proof by contradiction to show that no polynomial time algorithm can exist for B.

Suppose that B has a polynomial-time algorithm. Then, using the method shown in Figure 34.1, we would have a way to solve problem A in polynomial time, which contradicts our assumption that there is no polynomial-time algorithm for A.

For NP-completeness, we cannot assume that there is absolutely no polynomial time algorithm for problem A. The proof methodology is similar, however, in that we prove that problem B is NP-complete on the assumption that problem A is also NP-complete.

A first NP-complete problem

Because the technique of reduction relies on having a problem already known to be NP-complete in order to prove a different problem NP-complete, we need a “first” NP-complete problem.
The circuit-satisfiability problem, in which we are given a boolean combinational circuit composed of AND, OR, and NOT gates, and we wish to know whether there exists some set of boolean inputs to this circuit that causes its output to be 1.

Loop Invariant
In proofs of correctness of iterative algorithms the most challenging parts usually involve loops.

In computer science, a loop invariant is a is a formal statement of a property/condition that stays true throughout loop iteration

The loop invariant characterizes the loops purpose and pretext for implementation.


A loop invariant is a program loop property that is true before during and after each iteration.

Knowing its invariant(s) is essential to understand the effect of a loop
Loop invariants help us to understand why an algorithm is correct

Methodologically the loop invariant is an abstract specification of the loop
Iterative algorithms often use loop invariants to provide logical argumentation that a loop does as intended by design.

We state these properties of the processed input A[1... N-1]  formally as a loop invariant
A Loop invariant often is included in pseudocode as a comment following the loop header

Each loop's invariants must show these three things:
Initialization, Maintenance, termination

Loop Invariant Initialization:    true before each iteration of the loop
Loop Invariant Maintenance:       remains true through the iteration of the loop
Loop Invariant Termination:       true upon termination of the loop,


Termination deals with final state and is therefore the invariant property that helps to prove the correctness of the algorithm
Both the loop invariants and the loop termination condition can be guaranteed on exit from the loop

A loop invariant is a logical assertion, sometimes checked within the code, through an assertion call
When the Initialization and Maintenance properties hold the loop invariant is true prior to every iteration of the loop




Proving partial correctness of loops with invariants is very similar to proving correctness of recursive programs via induction

A given loop invariants are often the same as a given recursive inductive hypotheses





Showing that the invariant holds before the first iteration corresponds to an inductive base case

showing that the invariant holds from iteration to iteration corresponds to the inductive step.

the terminal invariant stops “induction” when a loop terminates


A common problem in computer programming is loops which don't terminate or terminate without achieving their goal behavior
Loop Invariant Termination property is perhaps the most important as we use it to show loop correctness

A loop invariant is a formal statement about the relationship between loop functionality and the variables in your program


Loop invariants and mathematical induction differ as...
The termination property, unlike the inductive step, is finite


Proofs of correctness for recursive algorithms usually use induction

Portions of an inductive proof:
basis proof, inductive hypotheses, inductive step

Inductive Basis Case: proves that a correct value is returned when number of elements in input is 1.

Inductive Hypothesis: Assume that the algorithm returns the correct answer when the number of elements in A is n, where n is some number > 0.

Inductive Step: Prove that the algorithm will return the correct answer when the number of elements is n+1

Running time relationship is defined by the time function

The time function is a relation of algorithm running time by input size

The time function is denoted T(N)


When analyzing algorithms, we are interested in differences in the relative growth rate of time functions

The growth rate is how fast an algorithms runtime increases with input size


To find time functions worst case resolve dominant term and drop constants

The running time on a particular input is the number of primitive operations or “steps” executed

Execution of the ith line takes takes time ci, where ci is a constant  







Even for inputs of a given size, an algorithm’s running time may depend on which input of that size is given.




The running time of the algorithm is the sum of running times for each statement executed

Algorithm cost ignores actual cost of each statement using constants ci to represent the constant costs

Runtime of consecutive statements are added




Branches
If/else runtime is calculated using the running time of the longer branch + runtime of the test

A shorter branches execution time might be
May be chosen in analysis if it is the typically executed branch




Loops
Loop runtime is the sum of runtime of the contained statements
including comparisons multiplied by the max number of iterations is

The runtime of a group of nested loops is at most
The runtime of its statements multiplied by the product of their max sizes is

When for or while loops exits normally, due to the loop header conditional   the conditional test is executed one time more than the loop body




Functions
Running time of methods called must be analyzed first then factored into the time function
Subroutine calls themselves take constant time though  the subroutine called may take more


The rate of growth, or order of growth has us consider only the leading term of a runtime formula
as lower-order terms are relatively insignificant for large n.




Recurrence relation
When an algorithm contains self reference, its runtime is expressed by a recurrence equation
A recurrence is an equation or inequality that describes a function in terms of its value on smaller inputs
A recurrence relation is coupled with a boundary condition
Recurrence boundary condition specifies the base case for the smallest argument-values
A recurrence equation, rather than a precise step count, provides tight asymptotic equivalent/estimate using big-oh or big𝜽 notation

Recurrences equations go hand in hand with the divide-and-conquer paradigm, because
they give us a natural way to characterize the running times of divide-and-conquer algorithms

In addition to smaller instances of the same problem, we have to solve subproblems that are not quite the same as the original problem.

We consider solving subproblems which differ from the original as part of the combine step.


The recursive equation is the sum of the
The constant time work plus the time for the next recursive call made

A recursive linear search would,
Would create just one subproblem of one element fewer than the original search problem

A recursive linear search yields the recurrence:
T(n) = T(n-1) + 𝜽(1)




three methods for solving recurrences
Substitution, Recursion Tree, and Master methods





For convenience, we shall generally omit statements of the boundary conditions of recurrences and assume that T(n) is constant for small n.

Since the running time of an algorithm on a constant-sized input is a constant, recurrences generally have T(n) =  θ(1) for sufficiently small n.

The recurrences we get in algorithm analysis typically have T(a) = 𝜽(1) type boundary conditions where a is the smallest or sufficiently small, base case of N

The reason recurrence equations ignore boundary conditions is that although changing the value of T(1) changes the exact solution to the recurrence, the solution typically doesn’t change by more than a constant factor, and so the order of growth is unchanged.

A recurrence for the running time of a divide-and-conquer algorithm:
  let T(n) be the running time on a problem of size n.
  The base case takes constant time 𝜽(1)
  Subproblems are 1/b original size.
  T(n/b) to solve one subproblem of size n/b, aT(n/b) to solve a of them.
  D(n) time to divide into subproblems
  C(n) time to combine their solutions, we get the recurrence


T(n) =  θ(1)                        if n ≤ c
        aT(n/b) + D(n) + C(n)       otherwise


Subproblems are not necessarily constrained to being a constant fraction of the original problem size.

A recursive algorithm might divide subproblems into unequal sizes, perhaps a 2/3-to-1/3 split. If divide and combine steps take linear time, give the recurrence:

T(n) = T(2n/3) + T(n/3) + θ(n)









Master Method
The master method provides bounds for recurrences of the form:
T(n) = aT(n/b) + f(n)
where a ≥ 1, b > 1 and f(n) is a given function

This recurrence characterizes a divide-and-conquer algorithm that creates subproblems, each 1/b the size, and divide and combine steps together take f(n) time.




Occasionally, we shall see recurrences that are not equalities but rather
inequalities

T(n) ≤ 2T(n/2) + Θ(n)
states only an upper bound on T(n) and requires O-notation


T(n) ≥ 2T(n/2) + Θ(n)
states only a lower bound on T(n) and requires Ω-notation

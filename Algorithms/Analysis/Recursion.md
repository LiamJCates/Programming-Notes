Recursion.
A recursive method is a method that calls itself either directly or indirectly. There are three important rules of thumb in developing recursive programs:
The recursion has a base case.
Recursive calls must address subproblems that are smaller so as to converge to the base case.
Recursive calls should not address subproblems that overlap.

Recursion / Master Theorem

Recursion happens when a method calls itself

Recursive code has the possible danger of a Stack Overflow
correctly written recursive methods test for a condition that terminates the recursion when the method reaches the base case

Recursion is an essential tool for implementing algorithms that take advantage of the technique known as divide and conquer, where a complex problem is repeatedly divided into similar (but smaller) problems until a simple case (the base case) is reached.


Recurrence

When an algorithm contains self reference, its runtime is expressed by a recurrence equation

A recurrence is an equation or inequality that describes a function in terms of its value on smaller inputs

A recurrence relation is coupled with a boundary condition
Recurrence boundary condition specifies the base case for the smallest argument-values

A recurrence equation, rather than a precise step count, provides...
Provides tight asymptotic equivalent/estimate using big-oh or big𝜽 notation...

three methods for solving recurrences...
Substitution, Recursion Tree, and Master methods are...

In the substitution method, we guess a bound and then use mathematical induction
to prove our guess correct.


Recurrences equations go hand in hand with the divide-and-conquer paradigm, because they give us a natural way to characterize the running times

In addition to smaller instances of the same problem, we have to solve subproblems that are not quite the same as the original problem.

We consider solving subproblems which differ from the original as part of the combine step.

Since the running time of an algorithm on a constant-sized input is a constant, recurrences generally have T(n) =
θ(1) for sufficiently small n.

Consequently, for convenience, we shall generally omit statements of the boundary conditions of recurrences and assume that T (n) is constant for small n.

The reason recurrence equations ignore boundary conditions is that although changing the value of T(1) changes the exact solution to the recurrence, the solution typically doesn’t change by more than a constant factor, and so the order of growth is unchanged.

The recurrences we get in algorithm analysis typically have T(a) = 𝜽(1) type boundary conditions where a is the smallest or sufficiently small, base case of N

The default boundary condition is considered to be T(1) = 𝜽(1)

A recurrence for the running time of a divide-and-conquer algorithm falls out from three steps:
let T(n) be the running time on a problem of size n. 
The base case takes constant time 𝜽(1)
subproblems are 1/b original size.
T(n/b) to solve one subproblem of size n/b,
aT(n/b) to solve a of them.

To aT(n/b) we add D(n) time to divide into subproblems and C(n) time to combine their solutions

T(n) =  {𝜽(1)                    if n <= c
        {aT(n/b) + D(n) + C(n)   otherwise

A recursive algorithm might divide subproblems into unequal sizes, perhaps a 2/3-to-1/3 split.
If divide and combine steps take linear time, give the recurrence :
T(n) = T(2n/3) + T(n/3) +  𝜽(n)

The master method provides bounds for recurrences of the form:

T(n) = aT(n/b) + f(n)

The master method:

T(n) = aT(n/b) + f(n)
where a >= 1, b > 1 and f(n) is a given function

A recurrence of the form T(n) = aT(n/b) + f(n) characterizes a divide-and-conquer algorithm that creates
a subproblems, each 1/b the size, and divide and combine steps together take f(n) time.

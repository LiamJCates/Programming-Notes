## Asymptotic Analysis

We use asymptotic notation to describe the running times of algorithms

An algorithm's asymptotic efficiency is determined by order of growth
For sufficient input sizes only a runtime's order of growth is relevant

An asymptotically more efficient algorithm is better for large inputs.
large inputs are most relevant as small inputs typically do not have a significant impact on runtime




When analyzing the resource requirements of a given algorithm represented by some function f(n), the worst and best case scenarios work to establish another function g(n). g(n) approximates either an upper or lower bound for f(n) at n of sufficient size.

g(n) is what is known as an asymptotic curve for f(n).

The word Asymptotic means approaching a value or curve arbitrarily closely without surpassing it.

It is a technique of representing limiting behavior. The methodology has applications across science.
And it is often used to analyze the performance of an algorithm for input data sets.

A simple example is a function ƒ (n) = n^2+3n,
the lower order term, 3n^1, becomes insignificant in size when compared to the size of the higher order term, n^2, as the input size, n, grows larger.

To represent this mathematically we write "lim n → ∞ ƒ(n) = n^2"

This symbology indicates that, as the size of the input x, trends toward infinity, or becomes infinitely large, the growth of ƒ (n) closely resembles, or is "asymptotically equivalent" to its highest term n^2.





Definition:  
g(n) is in O( f(n) ) if there exist constants c and n0 such that  g(n) ≤ c*f(n) for all n ≥ n0

To show g(n) is in O( f(n) ), pick 
  c large enough to “cover the constant factors”
  n0 large enough to “cover the lower-order terms”


By our previous example
ƒ(n) = n^2+3n  

we can see that for g(n) = c * n0^2 even for small values of c = 3 and n0  = 2 g(n) = 3 * 2^2 = 12 > 10 = 2^2 + 3*2 = ƒ (n)

For this reason, we call algorithm analysis asymptotic analysis.

We express such statements less formally, and more efficiently, as ƒ (n) = O(n^2), known as Big-O notation.



### Measuring Algorithm Efficiency Using Big-O Notation

Succinctly, Big-O notation expresses algorithmic resource usage in terms of how quickly it grows relative to the input, as the input gets arbitrarily large.

The Big-O notation obtains a function for measuring algorithm time complexity based on the input size.
This function counts operations performed by an algorithm while ignoring multiplicative constants and non-dominating terms.

To use a well known example:
The linear search algorithm takes a search key and an indexed collection of elements. It compares the key with the elements in the collection sequentially until the key is found or the collection is exhausted. If the key is not in the collection, the algorithm performs n comparisons, one for each element in the size n collection. If the key is in the collection, and the index at which the element matching the key is found, follows a normal distribution, so each index is equally likely, the algorithm requires n/2 comparisons on average.

In either case, The algorithm’s execution time is proportional to the size of the collection. If you double the size of the collection, you will expect the number of comparisons to double as well.

The algorithm's resource usage, in this case time spent to perform comparisons, grows at a linear rate. The growth rate has an order of magnitude of n.

Computer scientists then use Big O notation to represent the “order of magnitude.” Using this notation, the complexity of the linear search algorithm is O(n), pronounced as “order of n.” We call an algorithm with a time complexity of O(n), a linear algorithm, and it exhibits a linear growth rate.

The linear search algorithm requires n comparisons in the worst case and n/2 comparisons in the average case if you are nearly always looking for something known to be in the list. Using the Big O notation, both the cases require O(n) time. The multiplicative constant (1/2) that effects the rate of growth in the average case is omitted. Algorithm analysis is focused on growth rate. The multiplicative constants have no impact on growth rates. Therefore, O(n) = O(n/2) = O(100n).


### Asymptotic Notations

Following are the commonly used asymptotic notations to calculate the running time complexity of an algorithm.


Ο Notation: Describes the upper bound of the running time, an algorithm that linearly traverses an array can be described as O(n), but it can also be described as O(n^2) or O(2^n), the algorithm is as fast as, or faster than all of these; therefore they are upper bounds on the runtime. A less than or equal to relationship.

Ω Notation: Describes the lower bound of the running time, an algorithm that linearly traverses an array can be described as Ω(n), but it can also be described as Ω(log n) or Ω(1), the algorithm is as slow as or slower than all of these; therefore they are lower bounds on the runtime. A greater than or equal to relationship.

θ Notation: Describes both the lower and upper bound of the running time. A linear traversal is both O(n) and Ω(n), therefore it is θ(n). A tight bound on the runtime.


##### Summary

In industry/interviews, Big O notation is used as Big θ, it would be seen as incorrect to describe a linear traversal as O(n^2) or O(2^n), thought it is technically correct.

In academia:
Use big-𝜽() notation if the algorithms worst case is not significantly different form the best case use

Use big-O() notation if the algorithms worst case is significantly different from the best case

Use big-O() notation when unsure of which growth classification use










One of the fundamental measures of algorithmic efficiency is time efficiency

The running time on a particular input is the number of primitive operations or “steps” executed by an algorithm, given some input.

The growth rate of a given algorithm is how fast it's runtime increases in relation to input size

NOTE:
Even for inputs of a given size, an algorithm’s running time may depend on which input of that size is given.
This can be ignored for now


### Time Functions

When analyzing algorithms, we are interested in differences in the relative growth rate

The running time of the algorithm is the sum of running times for each statement executed

Algorithm cost ignores actual cost of each statement using constants ci to represent the constant costs

Runtime of consecutive statements are added




Running time relationship is defined by the time function, denoted T(N)

The time function is a relation of algorithm running time by input size

To find time functions we resolve the dominant term and drop constants



Branches
If/else runtime is calculated using the running time of the longer branch + runtime of the test

A shorter branches execution time might be chosen in analysis if it is the typically executed branch




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

Asymptotic Analysis
An algorithms asymptotic efficiency is determined by order of growth
For sufficient input sizes only a runtime's order of growth is relevant

An asymptotically more efficient algorithm is best for all but very small inputs

We use asymptotic notation primarily to describe the running times of algorithms


When analyzing the resource requirements of a given algorithm represented by some function f(n), the worst and best case scenarios work to establish another function g(n). g(n) approximates either an upper or lower bound for f(n) at n of sufficient size.

g(n) is what is known as an asymptotic curve for f(n).

The word Asymptotic means approaching a value or curve arbitrarily closely without surpassing it.

It is a technique of representing limiting behavior. The methodology has applications across science.
And it is often used to analyze the performance of an algorithm for input data sets.

A simple example is a function ƒ (n) = n^2+3n,
the lower order term, 3n^1, becomes insignificant in size when compared to the size of the higher order term, n^2, when n is very large.

To represent this mathematically we write "lim n→∞ ƒ (n) = n^2"

This symbology indicates that, as the size of the input x, trends toward infinity, or becomes infinitely large, the growth of ƒ (n) closely resembles, or is "asymptotically equivalent" to its highest term n^2.

Definition:  
g(n) is in O( f(n) ) if there exist constants c and n0 such that  g(n) ≤ c*f(n) for all n ≥ n0

To show g(n) is in O( f(n) ), pick a c large enough to “cover the constant factors” and n0 large enough to “cover the lower-order terms”

By our previous example ƒ (n) = n^2+3n  we can see that for g(n) = c*n0^2 even for small values of c = 2 and n0  = 3 g(n) = 3 * 2^2 = 12 > 10 = 2^2 + 3*2 = ƒ (n)

For this reason, we call algorithm analysis asymptotic analysis.

We express such statements less formally, and more efficiently, as ƒ (n) = O(n^2), known as Big-O notation.



Measuring Algorithm Efficiency Using Big-O Notation
Succinctly, Big-O notation expresses algorithmic resource usage in terms of how quickly it grows relative to the input, as the input gets arbitrarily large.

The Big-O notation obtains a function for measuring algorithm time complexity based on the input size.
This function counts operations performed by an algorithm while ignoring multiplicative constants and non-dominating terms.

To use a well known example:
The linear search algorithm takes a search key and an indexed collection of elements. It compares the key with the elements in the collection sequentially until the key is found or the collection is exhausted. If the key is not in the collection, the algorithm performs n comparisons, one for each element in the size n collection. If the key is in the collection, and the index at which the element matching the key is found, follows a normal distribution, so each index is equally likely, the algorithm requires n/2 comparisons on average.

In either case, The algorithm’s execution time is proportional to the size of the collection. If you double the size of the collection, you will expect the number of comparisons to double as well.

The algorithm's resource usage, in this case time spent to perform comparisons, grows at a linear rate. The growth rate has an order of magnitude of n.

Computer scientists then use Big O notation to represent the “order of magnitude.” Using this notation, the complexity of the linear search algorithm is O(n), pronounced as “order of n.” We call an algorithm with a time complexity of O(n) linear algorithm, and it exhibits a linear growth rate.

The linear search algorithm requires n comparisons in the worst case and n/2 comparisons in the average case if you are nearly always looking for something known to be in the list. Using the Big O notation, both the cases require O(n) time. The multiplicative constant (1/2) that effects the rate of growth in the average case is omitted. Algorithm analysis is focused on growth rate. The multiplicative constants have no impact on growth rates. Therefore, O(n) = O(n/2) = O(100n).

Asymptotic Notations
Following are the commonly used asymptotic notations to calculate the running time complexity of an algorithm.
Ο Notation
Ω Notation
θ Notation


Use big-𝜽() notation if the algorithms worst case is not significantly different form the best case use

Use big-O() notation if the algorithms worst case is significantly different from the best case use

Use big-O() notation when unsure of which growth classification use


Example
```
public static int exampleFunction( int n ) {
  int partialSum;
  partialSum = 0;

  for( int i = 1; i <= n; i++ )
    partialSum += i * i * i;

  return partialSum;
}
```
| Line | Purpose | Cost |
|------|---------|------|
| 2 | Declaration | 0 |
| 3 | Assignment | 1 |
| 5 | one initialization, N + 1 tests, and N increments | 2N + 2 |
| 6 | two multiplications, an addition and assignment N times | 4N |
| 8 | Return | 1 |                            1

We ignore method call and returning costs, for a total of:  6N + 4

If we had to perform all this work every time we needed to analyze a program, the task would quickly become infeasible. Fortunately, since we are giving the answer in terms of Big-Oh, there are lots of shortcuts that can be taken without affecting the final answer.

Lines 2,3 and 6 are insignificant compared with the for loop, so these constant time costs are disregarded.
Lines 4 and 5 are O(1) statements (per execution), so precise units do not matter.

Thus, we say that the Big-O notation of T(N) = 6N + 4 is O(N).




General Rules

Rule 0    Inner to Outer
Analyze algorithms from the inside out, meaning the deepest or most inner scope first. This includes structures such as loops or function calls are analysed first before the larger contexts they appear in.

Rule 1    Loops
The running time of a loop is at most the running time of the statements inside the loop (including tests, and iteration handling) multiplied by the number of iterations.

Rule 2    Nested loops.
Using Rule 0, we analyze these inside out. The total running time of a statement inside a group of nested loops is the running time of the statement multiplied by the product of the sizes of all the loops.

As an example, the following program fragment is O(N2):
for( i = 0; i < n; i++ )
for( j = 0; j < n; j++ )
k++;

Rule 3    Consecutive Statements
These are additive which means that the highest order of the series is considered

As an example, the following program fragment, which has O(N) work followed by O(N2) work, is also O(N2):
for( i = 0; i < n; i++ )
a[ i ] = 0;
for( i = 0; i < n; i++ )
for( j = 0; j < n; j++ )
a[ i ] += a[ j ] + i + j;

Rule 4    If / Else Branches
For the fragment
if( condition )
T()1
else
T()2

The running time of an If / Else statement is never more than the running time of the test condition plus the larger of the running times of T()1 and T()2. Clearly, this can be an overestimate in some cases, but it is never an underestimate.

Rule 5 - method calls
method calls must be analyzed before other statements in the same scope.
recursive methods have several options.
If the recursion is really just a thinly veiled loop, the analysis is usually trivial.
For instance, the following method is really just a simple loop and is O(N):
public static long factorial( int n ) {
if( n <= 1 )
return 1;
else
return n * factorial( n - 1 );
}

When recursion is properly used, the analysis will involve a recurrence relation, consider:

public static long fib( int n ) {
1    if( n <= 1 )
2        return 1;
else
3        return fib( n -1)+ fib( n - 2 );
}


Let T(N) be the running time for the method call fib(n).
For N = 0 or N = 1
The running time is some constant value, which is the time to do the test at line 1 and return at line 2. We can say that T(0) = T(1) = 1 because these operations are of the order c*n^0 and the constant c can be ignored.
For N > 2,
The time to execute the method is the constant work done by the test at line 1 plus the work at line 3. Line 3 consists of an addition, two subtractions and two method calls. Since the method calls are not simple operations, they must be analyzed by themselves. The first method call is fib(n - 1) and hence, by the definition of T, requires T(N − 1) units of time. A similar argument shows that the second method call requires T(N − 2) units of time.
for n > 1:
T(n) = T(n-1) + T(n-2) + 4 (1 comparison, 2 subtractions, 1 addition)

Let’s say c = 4 and try to first establish a lower bound by approximating that T(n-1) ~ T(n-2) , though T(n-1) ≥ T(n-2), hence lower bound
T(n) = T(n-1) + T(n-2) + c
    = 2T(n-2) + c    //from the approximation T(n-1) ~ T(n-2)
    = 2*(2T(n-4) + c) + c
    = 4T(n-4) + 3c
    = 8T(n-6) + 7c
    = 2^k * T(n - 2k) + (2^k - 1)*cLet's find the value of k for which: n - 2k = 0
k = n/2T(n) = 2^(n/2) * T(0) + (2^(n/2) - 1)*c
    = 2^(n/2) * (1 + c) - ci.e. T(n) ~ 2^(n/2)

now for the upper bound, we can approximate T(n-2) ~ T(n-1) as T(n-2) ≤ T(n-1)
T(n) = T(n-1) + T(n-2) + c
    = 2T(n-1) + c    //from the approximation T(n-1) ~ T(n-2)
    = 2*(2T(n-2) + c) + c
    = 4T(n-2) + 3c
    = 8T(n-3) + 7c
    = 2^k * T(n - k) + (2^k - 1)*cLet's find the value of k for which: n - k = 0
k = nT(n) = 2^n * T(0) + (2^n - 1)*c
    = 2^n * (1 + c) - ci.e. T(n) ~ 2^n
Hence the time taken by recursive Fibonacci is O(2^n) or exponential.




Only a few function classes tend to occur in the course of basic algorithm analysis, listed in order of increasing dominance:

• Constant functions, f(n) = 1
If a function always performs in the same amount of time, regardless of input, it runs in O(1) time. This is not to say that a function that takes constant time will always take the same amount of time, but that the number of steps it performs (and hence the time it takes) will never grow beyond a constant maximum.
Such functions might measure the cost of adding two numbers, printing out “The Star Spangled Banner,” or the growth realized by functions such as f(n) = min(n, 100). In the big picture, there is no dependence on the parameter n.

• Logarithmic functions, f(n) = log n –
Logarithmic time-complexity shows up in algorithms such as binary search. Such functions grow quite slowly as n gets big, but faster than the constant function. Functions that take logarithmic time are usually not much slower than those that take constant time. A binary search takes time O(log n), as do most functions that eliminate half of the input at each stage of processing.

• Linear functions, f(n) = n
If a function will always take time in direct proportion to the size of its input then it is said to take time O(n)
Such functions measure the cost of looking at each item once (or twice, or ten times) in an n-element array, say to identify the biggest item, the smallest item, or compute the average value.

• Superlinear functions, f(n) = n lg n –
This important class of functions arises in such algorithms as Quicksort and Mergesort. They grow just a little faster than linear, just enough to be a different dominance class.

• Quadratic functions, f(n) = n^2 –
Functions that take quadratic time generally contain two nested loops over the input
Such functions measure the cost of looking at most or all pairs of items in an n-element universe. This arises in algorithms such as insertion sort and selection sort.

• Cubic functions, f(n) = n^3 – Such functions enumerate through all triples of
items in an n-element universe. These also arise in certain dynamic programming algorithms

• Exponential functions, f(n) = c^n for a given constant c > 1 – Functions like 2^n arise when enumerating all subsets of n items. As we have seen, exponential algorithms become useless fast, but not as fast as. . .

• Factorial functions, f(n) = n! – Functions like n! arise when generating all
permutations or orderings of n items.

For a more complete view see: https://en.wikipedia.org/wiki/Time_complexity#Table_of_common_time_complexities



Properties of Big O

Definition 2.1.
T(N) = O(f(N)) if there are positive constants c and n0 such that T(N) ≤ cf(N) when N ≥ n0.

Definition 2.2.
T(N) = Ω(g(N)) if there are positive constants c and n0 such that T(N) ≥ cg(N) when N ≥ n0.

Definition 2.3.
T(N) = Θ(h(N)) if and only if T(N) = O(h(N)) and T(N) = Ω(h(N)).

The idea of these definitions is to establish a relative order among functions. Given two functions, there are usually points where one function is smaller than the other function, so it does not make sense to claim, for instance, f(N) < g(N). Thus, we compare their relative rates of growth.

When we say that T(N) = O(f(N)), we are guaranteeing that the function T(N) grows at a rate no faster than f(N); thus f(N) is an upper bound on T(N).

Since this implies that f(N) = Ω (T(N)), we may also say that T(N) is a lower bound on f(N).

Use big-𝜽()    If algorithms worst case is not significantly different from the best case
Use big-O()     If algorithms worst case is significantly different from the best case

Use big-O() notation when unsure of which growth classification


The important things to know are
Rule 1.
If T1(N) = O(f(N)) and T2(N) = O(g(N)), then
(a) T1(N) + T2(N) = O(f(N) + g(N))
(intuitively and less formally it is O(max(f(N), g(N))) ),
(b) T1(N) ∗ T2(N) = O(f(N) ∗ g(N)).

Rule 2.
If T(N) is a polynomial of degree k, then T(N) = O(Nk).

Rule 3.
logk N = O(N) for any constant k. This tells us that logarithms grow very slowly

we can always determine the relative growth rates of two functions f(N) and g(N) by computing
lim(N→∞) f(N)/g(N), using L’Hôpital’s rule if necessary.

L’Hôpital’s rule states that if limN→∞ f(N) = ∞ and limN→∞ g(N) = ∞, then limN→∞ f(N)/g(N) = limN→∞ f  (N)/g (N), where f `(N) and g`(N) are the derivatives of f(N) and g(N), respectively
The limit can have four possible values:
The limit is 0: This means that f(N) = o(g(N)).
The limit is c = 0: This means that f(N) = (g(N)).
The limit is ∞: This means that g(N) = o(f(N)).
The limit does not exist: There is no relation (this will not happen in our context).







Big Oh Notation, Ο
The notation Ο(n) is the formal way to express the upper bound of an algorithm's running time. It measures the worst case time complexity or the longest amount of time an algorithm can possibly take to complete.

For example, for a function f(n)
Ο(f(n)) = { g(n) : there exists c > 0 and n0 such that f(n) ≤ c.g(n) for all n > n0. }

This notation gives the tight upper bound of the given function.
Generally, it is represented as f(n) = O(g(n)).
That means, at larger values of n, the upper bound of f(n) is g(n).

O-notation implies that f(n)
|f| is bounded by g up to constant factor asymptotically


O–notation defined as O(g(n)) = f(n):
there exist positive constants c and n0 such that 0 ≤ f(n) ≤ cg(n) for all n ≥ n0}.

g(n) is an asymptotic tight upper bound for f(n). Our objective is to give the smallest rate of growth g(n) which is greater than or equal to the given algorithms’ rate of growth f(n).

Generally we discard lower values of n. That means the rate of growth at lower values of n is not important. In the figure, n0 is the point from which we need to consider the rate of growth for a given algorithm. Below n0, the rate of growth could be different. n0 is called threshold for the given function.

To represent an asymptotic upper bound, we use O-notation to represent

Big O limit Definition

lim n → ∞ f(n) / g(n) = 0

through O-notation we represent g(n) as the upper bound of f(n) through

f(n) = O(g(n)) formal definition
∀k > 0, ∃n0 ∀n > n0 | f(n) | ≤ k * g(n)

For all values of k greater than zero
there exists some value initial value n where
for all values of n greater than the initial value of n
the value of a function f(n) is less than or equal to a constant k * g(n)

O(f(n)) is the set of functions with smaller or the same order of growth as f(n). For example; O(n2) includes O(1), O(n), O(nlogn), etc.





Big-O Examples


Examples of determining Big O

Example 1:
for (int i = 1; i <= n; i++) {
     k = k + 5;
}
It is a constant time, c, for executing    k = k + 5;

Since the loop is executed n times, the time complexity for the loop is
T(n) = (a constant c) * n = O(n)

Example 2:
for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 k = k + i + j;
 }
}
It is a constant time, c, for executing    k = k + i + j;
The outer loop executes n times. For each iteration in the outer loop, the inner loop is executed n times. Thus, the time complexity for the loop is
T(n) = (a constant c) * n * n = O(n2)

An algorithm with the O(n2) time complexity is called a quadratic algorithm and it exhibits
a quadratic growth rate. The quadratic algorithm grows quickly as the problem size
increases. If you double the input size, the time for the algorithm is quadrupled. Algorithms with a nested loop are often quadratic.

Example 3:
Consider the following loop:
for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= i; j++) {
     k = k + i + j;
 }
}
The outer loop executes n times. For i = 1, 2, c , the inner loop is executed one time, two times, and n times. Thus, the time complexity for the loop is
T(n) = c + 2c + 3c + 4c + …  + nc
= cn(n + 1)/2
= (c/2) n2 + (c/2)n
= O(n2)

Example 4:
for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= 20; j++) {
 k = k + i + j;
 }
}
The inner loop executes 20 times and the outer loop n times. Time complexity:    T(n) = 20 * c * n = O(n)

Example 5:
for (int j = 1; j <= 10; j++) {
     k = k + 4;
}
for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= 20; j++) {
k = k + i + j;
 }
}

The first loop executes 10 times and the second loop 20 * n times. Thus, the time complexity for the loop is T(n) = 10 * c + 20 * c * n = O(n)

Example 6:
if (list.contains(e)) {
     System.out.println(e);
}
else
 for (Object t: list) {
System.out.println(t);
 }
Suppose the list contains n elements. The execution time for list.contains(e) is O(n). The loop in the else clause takes O(n) time. Hence, the time complexity for the entire statement is
T(n) = if test time + worst@case time (if clause, else clause) = O(n) + O(n) = O(n)
result = 1;
for (int i = 1; i <= n; i++)
result *= a;

The algorithm takes O(n) time. Without loss of generality, assume that n = 2k.
You can improve the algorithm using the following scheme:
result = a;
for (int i = 1; i <= k; i++)
result *= result;


The algorithm takes O(log n) time. An algorithm with the O(logn) time complexity is called a logarithmic algorithm and it exhibits a logarithmic growth rate. The base of the log is 2, but the base does not affect a logarithmic growth rate, so it can be omitted. In algorithm analysis, the base is usually 2.
Omega Notation, Ω
The notation Ω(n) is the formal way to express the lower bound of an algorithm's running time. It measures the best case time complexity or the best amount of time an algorithm can possibly take to complete.

For example, for a function f(n)
Ω(f(n)) ≥ { g(n) : there exists c > 0 and n0 such that g(n) ≤ c.f(n) for all n > n0. }


this notation gives the tighter lower bound of the given algorithm and we represent it as f(n) = Ω(g(n)). That means, at larger values of n, the tighter lower bound of f(n) is g(n).

The Ω notation can be defined as Ω(g(n)) = {f(n):
there exist positive constants c and n0 such that 0 ≤ cg(n) ≤ f(n) for all n ≥ n0}.

g(n) is an asymptotic tight lower bound for f(n).
Our objective is to give the largest rate of growth g(n) which is less than or equal to the given algorithm’s rate of growth f(n).

Ω-notation implies that f(n)
f is bounded below by g asymptotically

Big Ω limit Definition
(notation)

through Ω-notation we
We represent g(n) as the lower bound of f(n) through

f(n) = Ω(g(n)) formal definition
(notation)

To represent an asymptotic lower bound, we use
We use Ω-notation to represent

Big Ω in terms of Big O
f(n) = Ω(g(n)) AND g(n) = O(f(n))






Theta Notation, θ
The notation θ(n) is the formal way to express both the lower bound and the upper bound of an algorithm's running time. It is represented as follows −

θ(f(n)) = { g(n) if and only if g(n) =  Ο(f(n)) and g(n) = Ω(f(n)) for all n > n0. }
This notation decides whether the upper and lower bounds of a given function (algorithm) are the same.

The average running time of an algorithm is always between the lower bound and the upper bound.

If the upper bound (O) and lower bound (Ω) give the same result, then the Θ notation will
also have the same rate of growth.

As an example, let us assume that f(n) = 10n + n is the expression. Then, its tight upper bound g(n) is O(n). The rate of growth in the best case is g(n) = O(n).

In this case, the rates of growth in the best case and worst case are the same. As a result, the
average case will also be the same. For a given function (algorithm), if the rates of growth
(bounds) for O and Ω are not the same, then the rate of growth for the Θ case may not be the same.
In this case, we need to consider all possible time complexities and take the average of those (for
example, for a quick sort average case, refer to the Sorting chapter).

Now consider the definition of Θ notation.

It is defined as Θ(g(n)) = {f(n):
there exist positive constants c1, c2 and n0 such that 0 ≤ c1g(n) ≤ f(n) ≤ c2g(n) for all n ≥ n0}.

g(n) is an asymptotic tight bound for f(n).
Θ(g(n)) is the set of functions with the same order of growth as g(n).

In this case, the rates of growth in the best case and worst case are the same. As a result, the
average case will also be the same. For a given function (algorithm), if the rates of growth
(bounds) for O and Ω are not the same, then the rate of growth for the Θ case may not be the same.

Θ(g(n)) = {f(n)
Big Θ -notation
f(n) = Θ(g(n))

Big Θ -notation implies
(notation)

Big Θ limit Definition
(notation)

f(n) = Θ(g(n)) if and only if
f(n) = O(g(n)) and f(n) = Ω(g(n)).

For sufficiently large n, Θ-notation means
f() grows at the same rate as g() does

Function f(n) ⊆ Θ(g(n)) if there exist positive constants c1 and c2 such that
f(n) can be “sandwiched” between c1 ⋅ g(n) and c2 ⋅ g(n), for sufficiently large n

f(n) = Θ(g(n)) formal definition


(notation)

f(n) = Θ(g(n)) implies f(n) = O(g(n)), since
Θ notation is a stronger notion than O-notation so

Written set-theoretically, we have Θg(n)
⊆ O(g(n))/Ω(g(n))

Big Θ means f(n) = O(g(n)) and g(n) =
O(f(n))


small o-notation
(notation)

f(n) = small o(g(n)) if and only if
f(n) = O(g(n)) and  f(n) ≠ Θ(g(n)) (notation)

small o-notation implies
(notation)

small o-notation formal definition
(notation)

small o-notation limit
(notation)

small o-notation implies that
f grows much slower than g for sufficiently large n when using




ω-notation
f(n) = ω(g(n)) if and only if f(n) = Ω(g(n)) and  f(n) ≠ Θ(g(n))

ω-notation implies f(n) dominates g(n) asymptotically

ω-notation formal definition


ω-notation limit


ω-notation implies that f grows faster than g for sufficiently large n
Big O notation logically means f(n) ≤ g(n)

Asymptotically f(n) is no worse than g(n) if f(n) grows no faster than g(n)

Big Θ(g(n)) notation, logically means f(n) ≈ g(n)

Asymptotically, f(n) is equivalent to g(n) if f(n) grows the same as g(n)

Big Ω(g(n)) notation logically means f(n) ≥ g(n)

f(n) is asymptotically no better than g(n) if f(n) grows at least as fast as g(n)












The running time of insertion sort is not Ω(n^2), since there exists an input for which insertion sort runs in Θ(n) time (e.g., when the input is already sorted).

We can say insertion sort's worst-case is Ω(n^2), since
There exists an input that causes insertion sort to take a maximumΩ(n^2) time so

if f(n) = O(g(n)) and p(n) = O(h(n)) then f(n) + p(n) =
f(n) + p(n) = max(O(g(n)), O(h(n))) if

if f(n) = O(g(n)) and p(n) = O(h(n)) then f(n) ⋅ p(n) =
f(n) ⋅ p(n) = O( g(n) ⋅ h(n) ) if


If f(n) is a polynomial function of degree k then f(n) = Θ(n^k)

To determine the relative growth rates of two functions f and g:    lim(n → ∞) f(n) / g(n)

Transitivity of f(n) = Θ(g(n)) and g(n) = Θ(h(n)) implies f(n) = Θ(h(n));

Transitivity of f(n) = O(g(n)) and g(n) = O(h(n)) implies f(n) = O(h(n));

Transitivity of f(n) = Ω(g(n)) and g(n) = Ω(h(n)) implies f(n) = Ω(h(n));

Transitivity of f(n) = o(g(n)) and g(n) = o(h(n)) implies f(n) = o(h(n));

Transitivity of f(n) = ω(g(n)) and g(n) = ω(h(n)) implies f(n) = ω(h(n)):

Reflexivity of f(n) means
f(n) = Θ(f(n))
f(n) = O(f(n))
f(n) = Ω(f(n))

Symmetry f(n) = Θ(g(n)) if and only if g(n) = Θ(f(n))

Transpose symmetry f(n) = O(g(n)) if and only if g(n) = Ω(f(n))
Transpose symmetry f(n) = o(g(n)) if and only if g(n) = ω(f(n))

Properties hold for asymptotic notations allow us to draw an analogy between the comparison of two functions f and g

The comparison of two real numbers a and b; f(n) = O(g(n)) is like a ≤  b
The comparison of two real numbers a and b; f(n) = Ω(g(n)) is like a ≥  b
The comparison of two real numbers a and b; f(n) = Θ(g(n)) is like a = b
The comparison of two real numbers a and b; f(n) = o(g(n)) is like a < b
The comparison of two real numbers a and b; f(n) = ω(g(n)) is like a > b

We say f(n) is asymptotically smaller than g(n) if f(n) = o(g(n))
We say f(n) is asymptotically larger than g(n) if f(n) = ω(g(n)).

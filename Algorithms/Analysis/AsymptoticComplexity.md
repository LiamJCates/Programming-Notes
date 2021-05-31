## Asymptotic Analysis

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

To represent this mathematically we write "lim n → ∞ ƒ(n) = n^2"

This symbology indicates that, as the size of the input x, trends toward infinity, or becomes infinitely large, the growth of ƒ (n) closely resembles, or is "asymptotically equivalent" to its highest term n^2.

Definition:  
g(n) is in O( f(n) ) if there exist constants c and n0 such that  g(n) ≤ c*f(n) for all n ≥ n0

To show g(n) is in O( f(n) ), pick a c large enough to “cover the constant factors” and n0 large enough to “cover the lower-order terms”

By our previous example
ƒ(n) = n^2+3n  

we can see that for g(n) = c * n0^2 even for small values of c = 2 and n0  = 3 g(n) = 3 * 2^2 = 12 > 10 = 2^2 + 3*2 = ƒ (n)

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

Computer scientists then use Big O notation to represent the “order of magnitude.” Using this notation, the complexity of the linear search algorithm is O(n), pronounced as “order of n.” We call an algorithm with a time complexity of O(n) linear algorithm, and it exhibits a linear growth rate.

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

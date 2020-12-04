## Introduction to Algorithm Analysis

What is Algorithm Analysis?
A method to estimate the resources required by an algorithm

Why use Algorithm Analysis?
It allows us to measure and compare efficiency between algorithm implementations.

What does efficiency measure?
An implementation that uses less resources, for example run time or storage space, during execution, is said to be more efficient.

Why measure algorithm efficiency?
The most common reason for measuring the efficiency of an algorithm is so that it can be optimized. Without a measure of efficiency we cannot determine whether a change made to an implementation, or choice between different implementations, is actually an optimization or a pessimization.

How do we measure algorithm efficiency?
Algorithm efficiency can be analyzed at two different stages:
Before or after implementation

Analysis before implementation is known as A Priori, Theoretical, or Algorithm Analysis
Efficiency is measured by counting the basic mathematical steps or computational operations performed by the algorithm. The count of operations grows relative to the problem's input size, known as a rate of growth, which is contrasted between implementations.

Analysis after implementation is known as A Posterior, Empirical, or Profile Analysis
The algorithm is implemented using a programming language. This is then executed on a target platform. During this method of analysis, empirical data, like running time and space required, is collected by the system to be contrasted between implementations.

How does Algorithm Analysis measure efficiency?
By providing a rate of growth that is relative to input size. An algorithm is said to be efficient when increase of resource usage remains small, or grows slowly, compared to a growth in its input size.

What is input size?
Input size informally means the number of instances in the input, or number of things processed during the algorithm's execution.
For example, during sorting, the input size references the number of items to be sorted.




## Profile Analysis

What is Profile Analysis?
The most intuitive approach might be to implement an algorithm and execute it with test input, recording empirical data such as the resulting runtime and memory space usage, a process called  "profiling". These statistics comprise the implementation's "profile", which may then be compared to the profile of another implementation.


Why should we do theoretical comparison when we can use empirical profiling data?

This approach has problems:
1.  To compare the algorithms, you must implement them both.
      This is both cost and time prohibitive

2.  The results might depend on what kind of computer you use.
      An algorithm might seem efficient on a specialized machine, yet be inefficient in general.

3.  The results might depend on the size of the input data.
      A less efficient algorithm might run more quickly if the input size is not sufficiently large

4.  Execution time depends on specific input.
      Consider, for example, linear search and binary search. If an element to be searched happens to be the first in the list, linear search will find the element quicker than binary search.

5.  Many tasks run concurrently on a computer.
      The execution time of a particular program depends on the system load.


How do we address the problems of Profile Analysis?
We can perform analysis in spite of these problems using Algorithm Analysis as it is a theoretical approach developed to analyze algorithms independent of a computational platform and specific input.

Algorithm Analysis evaluates the effect of a change in input size, no matter the specific input or platform used. Using the measure provided by Algorithm Analysis  we may predict how fast an algorithm’s resource usage increases as a problem instance's input size increases, called a rate of growth, which is applicable to all platforms and input.





## Platform Independence

How is Algorithm Analysis platform independent?
Ultimately, Algorithm Analysis allows for the comparison of algorithms without implementing them.

In order to analyze algorithms in a formal framework, we need a model of computation.

Before we can analyze an algorithm, we must model the implementation technology, including the resources and their costs

A computational model, real or imaginary, is a device that is used to perform instructions of the algorithm
An algorithms execution specifics is determined by the computational model used
Most typically we use the Uniform Cost Model.

Uniform Cost Model characteristics:
○ Sequential execution:
    only one operation is performed at any given instant
○ Constant time instructions:
    basic operations require one time unit
    (arithmetic, logical, control flow, data handling and memory operations)
○ Infinite RAM memory:
    No input size prohibits analysis, and memory access time is constant
    (unlimited memory cells with equal access cost)

Uniform Cost Model weaknesses:
○ Non-multithreaded:
    Many modern algorithms are multithreaded, allowing for parallel, rather than serial, execution.
○ Operations are not constant time:
    Not all operations require the same amount of time, by our model, a read operation requires the amount of time as arithmetic addition, though one may be orders of magnitude faster.
○ RAM is not infinite:
    By assuming infinite RAM memory, we ignore the fact that the cost of a memory access can increase when larger and slower storage media is accessed due to larger memory requirements.

While weaknesses exist, the Uniform Cost Model provides a simple, effective, and widely accepted method for performing Algorithm Analysis. There are other models, but they are not the focus of this document.





## Input Independence

How is Algorithm Analysis independent of specific input?
To understand this we must first understand complexity.

Algorithm Analysis measures efficiency by gauging resource usage and calls this measure of efficiency complexity. We suppose f() is a function representing an algorithm and n is the size of input data.
The complexity f(n), most commonly given as a growth function in terms of the running time or memory space required, relative to n.

Now consider that it is impossible to count the resource usage of an algorithm for all possible inputs.
However, the complexity function f(n) is monotonically non-decreasing. That means, if the input size increases, the resource usage also increases or remains constant.

However, for different inputs of the same size, the complexity of an algorithm may vary dramatically. Therefore, several complexity functions are commonly used.





## Complexity Functions

The goal of complexity analysis is to provide bounds for the execution costs of an algorithm's implementation.

These bounds are most commonly achieved by examining Worst, Average, and Best case complexity

Worst case
Defines the algorithm's upper bound, or maximum complexity using input of size n, for which the algorithm takes the most resources.

Best case
○ Defines the algorithm's lower bound, or minimum complexity using input of size n, for which the algorithm takes the least resources.

Average case
○ Provides a general prediction about the resource requirement of the algorithm over all inputs of size n (this makes sense, as the number of possible inputs of a given size is finite).

Usefulness By Case
Average-case analysis attempts to reflect typical behavior, but is difficult to perform because, for many problems, it is hard to determine the relative probabilities and distributions of various input instances.  Best/worst-case analyses are not representative of typical behavior. However, worst-case analysis is very useful for providing assurance that the algorithm will never be slower than the worst case. Generally, the quantity required is the worst-case, unless otherwise specified. Worst-case analysis is easier to perform, and achieves actionable results due to the guarantee it provides.





## Complexity Types

Time Factor:
    measures the number of basic operations required by the algorithm.

Space Factor:
    measured the maximum memory space required by the algorithm.

With the low cost of storage, the most important resource to analyze is generally the running time, or time complexity.

Generally, when "complexity" is used without being further specified, this is the worst-case time complexity that is considered.





## Time Complexity

Time complexity of an algorithm is defined as the numerical function T(), called the time function, which represents the amount of time required by the algorithm to run to completion. Time requirements for a given problem instance is thus represented by T(n), where n is the size of the input data, and is measured by the number of basic operations, provided each step consumes constant time.

While several factors, such as compiler, computer, and programming language used, affect the running time of a program, input size is the primary, if not the only, variable considered during algorithm analysis.

The total running time is determined by two factors:
• The cost of executing each statement
• The number of times each statement is executed

The former is a property of the system, and the latter is a property of the algorithm.

In an ideal scenario, if we know both for each instruction type in the program, we can multiply the execution cost with the frequency with which they are executed and determine the running time by summing to reach the total execution cost on a given machine.

However, as algorithms themselves are machine independent, our pre-implementation analysis of them should reflect this. This measurement will be covered extensively in the remainder of this document.

We define three functions, used by an algorithm on input of size N
Tavg (N)        average-case running time
Tworst (N)    worst-case running time
Tbest (N)        best case running time

Tbest (N) ≤ Tavg (N) ≤ Tworst (N)





## Space Complexity

The space required by an algorithm is equal to the sum of two components
The constant space required to store certain data and variables, that are independent of the size of the problem. For example, local variables and constants used, program size, etc.
The variable space required by variables, whose size depends on the size of the problem. For example, dynamic memory allocation, recursion stack space, etc.

Space complexity S() of any algorithm P can then be expressed S(P) = C + S(I), where C is the fixed part and S(I) is the variable part of the algorithm, which depends on instance characteristic I.

Following is a simple example, an algorithm that sums to variables and adds a constant, 10;

procedure getC( A, B )
  C ← A + B + 10
  return C
end procedure

Here we have three variables A, B, and C as well as one constant, 10.
Hence S(P) = 1 + 3.

A complete summation of required space then depends on the size required by the data types of given variables and constants, and should be multiplied with each occurrence accordingly.

We define three functions, used by an algorithm on input of size N
Savg (P)      average-case running time
Sworst (P)    worst-case running time
Sbest (P)     best case running time

Sbest (P) ≤ Savg (P) ≤ Sworst (P)

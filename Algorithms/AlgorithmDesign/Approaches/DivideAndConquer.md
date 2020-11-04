Divide and Conquer
The divide and conquer technique decomposes complex problems into smaller sub-problems. Each sub-problem is then solved and these partial solutions are recombined to determine the overall solution. This technique is often used for searching and sorting.


Recursive algorithms in general typically follow a divide-and-conquer approach

Divide and Conquer approach uses a recursive structure to solve a given problem by self reference, dividing the problem into smaller subproblems that are instances of the original problem until they are so small that they can be solved in a straightforward manner.

Recursive Case: when the problem instances are large and must be solved by recursively splitting.
Base Case: When the problem becomes small enough, we halt recursion and say that the recursion “bottoms out” and a simple solution can be found.

The divide-and-conquer approach involves two steps at each level of recursion which progress until a base case is reached.

Divide: the problem is divided into two or more sub-problems that are smaller instances of the same problem; typically these sub-problems are disjoint.

Conquer: the sub-problems are conquered by solving them recursively, and their solutions are combined into the solution of the original problem

When we keep on dividing the subproblems into even smaller sub-problems, we may eventually reach a stage where no more division is possible. Those "atomic" smallest possible sub-problem (fractions) are solved. The solution of all sub-problems is finally merged in order to obtain the solution of an original problem.



The divide-and-conquer paradigm involves three recursive steps Divide Conquer Merge

Divide/Break
This step involves breaking the problem into smaller sub-problems. Sub-problems should represent a part of the original problem. This step generally takes a recursive approach to divide the problem until no sub-problem is further divisible. At this stage, sub-problems become atomic in nature but still represent some part of the actual problem.

Conquer/Solve
This step receives a lot of smaller sub-problems to be solved. Generally, at this level, the problems are considered 'solved' on their own.

Merge/Combine
When the smaller sub-problems are solved, this stage recursively combines them until they formulate a solution of the original problem. This algorithmic approach works recursively and conquer & merge steps works so close that they appear as one.

Examples
The following computer algorithms are based on divide-and-conquer programming approach −
Merge Sort
Quick Sort
Binary Search
Strassen's Matrix Multiplication
Closest pair (points)
There are various ways available to solve any computer problem, but the mentioned are a good example of divide and conquer approach.



Merge Sort

Divide        n-element sequence into two subsequences of n/2 elements each.
Conquer     Sort the two subsequences recursively using merge sort.
Combine    Merge the two sorted subsequences to produce the sorted answer

Our MERGE procedure takes time 𝜽(n), where n = r - p + 1 is the total number of elements being merged

if we call MERGE-SORT on n elements when n is odd, we end up with subproblems of size
In practice, we neglect certain technical details when we state and solve recurrences including omission of floors, ceilings, and boundary conditions.

The recurrence describing the worst-case running time of MERGE-SORT is really


The worst-case running time T(n) of the MERGE-SORT procedure by the recurrence


Solution to

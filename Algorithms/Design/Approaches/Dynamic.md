Dynamic Programming

Dynamic programming: A systematic technique in which a complex problem is decomposed into smaller, overlapping subproblems for solution. 


Dynamic programming stores the results of the overlapping subproblems so that they are not required to be completed more than once.

Dynamic programming approach is similar to divide and conquer in breaking down the problem into smaller and yet smaller possible sub-problems. But unlike, divide and conquer, these sub-problems are not solved independently. Rather, results of these smaller sub-problems are remembered and used for similar or overlapping sub-problems.

Dynamic algorithms use Memoization to remember the output of already solved sub-problems.
Before solving the in-hand sub-problem, dynamic algorithm will try to examine the results of the previously solved sub-problems. 
Thus solutions of sub-problems are combined in order to achieve the best solution. 

Dynamic programming is an approach to optimization as, typically, referring to a previous solution output is cheaper than recomputing in terms of CPU cycles.
The problem should be able to be divided into smaller overlapping sub-problem.
An optimum solution can be achieved by using an optimum solution of smaller sub-problems.


Comparison
In contrast to greedy algorithms, where local optimization is addressed, dynamic algorithms are motivated for an overall optimization of the problem.
In contrast to divide and conquer algorithms, where solutions are combined to achieve an overall solution, dynamic algorithms use the output of a smaller sub-problem and then try to optimize a bigger sub-problem.

Example
The following computer problems can be solved using dynamic programming approach −
Fibonacci number series
Knapsack problem
Tower of Hanoi
All pair shortest path by Floyd-Warshall
Shortest path by Dijkstra
Project scheduling

Dynamic programming can be used in both top-down and bottom-up manner. 


Dynamic programming (DP) solves intricate problems by breaking them down into simpler components. DP can be applied to problems exhibiting two properties: overlapping subproblems and optimal substructure.

Overlapping Subproblems
a recursive algorithm solving the problem should solve the same subproblems over and over, rather than generating new subproblems.

Optimal Substructure
means that any optimal solution can be constructed efficiently from the optimal solutions of its subproblems.

In other words, suppose that each subproblem has its own cost function: the optimal substructure implies that the minima of each of these cost functions can be found as the minima of the global cost function restricted to the same subsets. DP pursues to solve each subproblem only once, as a result reducing the number of computations.

After the solution to a given subproblem has been computed, it is stored in a table or "memoized". Next time the same solution is required, it is simply looked up. 

DP solves problems in either two methods:

a) Top-down approach:
This is a consequence of the recursive mathematical definition associated to many DP problems.

b) Bottom-up approach:
This requires a reformulation of the recursive mathematical definition where subproblems are solved first and their solutions used to build-on and achieve solutions for bigger subproblems

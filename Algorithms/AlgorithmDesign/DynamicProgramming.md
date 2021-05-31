Dynamic programming (DP) solves intricate problems by breaking them down into simpler components. DP can be applied to problems exhibiting two properties: overlapping subproblems and optimal substructure.

Overlapping Subproblems
means that any recursive algorithm solving the problem should solve the same subproblems over and over, rather than generating new subproblems.

Optimal Substructure
means that any optimal solution can be constructed efficiently from the optimal solutions of its subproblems.

In other words, suppose that each subproblem has its own cost function: the optimal substructure implies that the minima of each of these cost functions can be found as the minima of the global cost function restricted to the same subsets. DP pursues to solve each subproblem only once, as a result reducing the number of computations.

After the solution to a given subproblem has been computed, it is stored in a table or "memoized". Next time the same solution is required, it is simply looked up. 

DP solves problems in either two methods:

a) Top-down approach:
This is a consequence of the recursive mathematical definition associated to many DP problems.

b) Bottom-up approach:
This requires a reformulation of the recursive mathematical definition where subproblems are solved first and their solutions used to build-on and achieve solutions for bigger subproblems

A recursive function is a function that calls itself, directly or indirectly. A recursive method consists of two parts: Termination Condition and Body (which include recursive expansion).
1. Termination Condition: A recursive method always contains one or more terminating condition. A condition in which recursive method is processing a simple case and will not call itself.

2. Body (including recursive expansion): The main logic of the recursive method contained in the body of the method. It also contains the recursion expansion statement that in turn calls the method itself.

Three important properties of recursive algorithm are:
1) A recursive algorithm must have a termination condition.

2) A recursive algorithm must change its state, and move towards the termination condition.

3) A recursive algorithm must call itself.

Note: The speed of a recursive program is slower because of stack overheads. If the same task can be done using an iterative solution (loops), then we should prefer an iterative solution (loops) in place of recursion to avoid stack overhead.

Note: Without termination condition, the recursive method may run forever and will finally consume all the stack memory

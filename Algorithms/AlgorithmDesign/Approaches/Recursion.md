Recursion is a general technique for designing an algorithm that calls itself with a progressively simpler part of the task down to one or more base cases with defined results.

Often, a recursive approach can appear simpler, and perhaps more elegant, although this comes at a price. Particular algorithms that perform a high number of recursive calls can throw a StackOverflowException, and may even be slower in performance over their iterative counterparts due to the extra setup in stack allocation for calling a method.

Tail recursive calls can sometime be optimized into iterative approaches. Tail recursion is when the recursive step is the final step of the method: The compiler can replace the stack variables for the current method with those for the next method call, rather than creating a new stack frame. The JVM itself cannot handle this directly, but some compilers can do this for Java and other JVMsupported languages.

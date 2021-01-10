Exceptions and Performance

In your programs, you must handle errors; errors are unavoidable.

When you use exceptions correctly and no errors occur, your code is faster than manually error-checked code.

If an error does occur, exception handling can sometimes be slower, but you make huge gains in robustness and maintainability over the alternative.

Kurt Guntheroth, the author of Optimized C++, puts it well:

  “use of exception handling leads to programs that are faster when they execute normally, and better behaved when they fail.”

When a C++ program executes normally (without exceptions being thrown), there is no runtime overhead associated with checking exceptions. It’s only when an exception is thrown that you pay overhead.

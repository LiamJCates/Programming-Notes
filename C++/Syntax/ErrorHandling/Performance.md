Exceptions and Performance
In your programs, you must handle errors; errors are unavoidable. When you
use exceptions correctly and no errors occur, your code is faster than manually error-checked code. If an error does occur, exception handling can sometimes be slower, but you make huge gains in robustness and maintainability
over the alternative. Kurt Guntheroth, the author of Optimized C++, puts it
well: “use of exception handling leads to programs that are faster when they
execute normally, and better behaved when they fail.” When a C++ program
executes normally (without exceptions being thrown), there is no runtime
overhead associated with checking exceptions. It’s only when an exception is
thrown that you pay overhead.
Hopefully, you’re convinced of the central role exceptions play in idiomatic C++ programs. Sometimes, unfortunately, you won’t be able to use
exceptions. One example is embedded development where real-time guarantees are required. Tools simply don’t (yet) exist in this setting. With luck,
this will change soon, but for now, you’re stuck without exceptions in most
embedded contexts. Another example is with some legacy code. Exceptions
are elegant because of how they fit in with RAII objects. When destructors are responsible for cleaning up resources, stack unwinding is a direct
and effective way to guarantee against resource leakages. In legacy code,
you might find manual resource management and error handling instead
of RAII objects. This makes using exceptions very dangerous, because stack
unwinding is safe only with RAII objects. Without them, you could easily
leak resources.

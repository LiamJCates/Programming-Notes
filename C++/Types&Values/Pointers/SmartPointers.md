Smart Pointers
Dynamic objects have the most flexible lifetimes. With great flexibility
comes great responsibility, so you must make sure each dynamic object
gets destructed exactly once. This might not look daunting with small programs, but looks can be deceiving. Just consider how exceptions factor
If you want to do a few small things right, do them yourself. If you
want to do great things and make a big impact, learn to delegate.
—John C. Maxwell342 Chapter 11
into dynamic memory management. Each time an error or an exception
could occur, you need to keep track of which allocations you’ve made
successfully and be sure to release them in the correct order.
Fortunately, you can use RAII to handle such tedium. By acquiring
dynamic storage in the constructor of the RAII object and releasing dynamic
storage in the destructor, it’s relatively difficult to leak (or double free)
dynamic memory. This enables you to manage dynamic object lifetimes
using move and copy semantics.
You could write these RAII objects yourself, but you can also use some
excellent prewritten implementations called smart pointers. Smart pointers are
class templates that behave like pointers and implement RAII for dynamic
objects.
This section delves into five available options included in stdlib and
Boost: scoped, unique, shared, weak, and intrusive pointers. Their ownership models differentiate these five smart pointer categories.

C++ Crash Course pg 342

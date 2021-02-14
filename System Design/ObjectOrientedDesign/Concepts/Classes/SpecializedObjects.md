An important concept for objects is the design pattern. A design pattern provides a reusable template to address a common problem. The following object descriptions are examples of some of the most common design patterns for objects.

Function object: an object with a single method (in C++, this method would be the function operator, "operator()") that acts much like a function (like a C/C++ pointer to a function).

Immutable object: an object set up with a fixed state at creation time and which does not change afterward.

First-class object: an object that can be used without restriction.

Container object: an object that can contain other objects.

Factory object: an object whose purpose is to create other objects.

Metaobject: an object from which other objects can be created (compare with a class, which is not necessarily an object).
Prototype object: a specialized metaobject from which other objects can be created by copying

God object: an object that knows or does too much (it is an example of an anti-pattern).

Singleton object: an object that is the only instance of its class during the lifetime of the program.

Filter object: an object that receives a stream of data as its input and transforms it into the object's output. Often the input and output streams are streams of characters, but these also may be streams of arbitrary objects. These are generally used in wrappers since they conceal the existing implementation with the abstraction required at the developer side.

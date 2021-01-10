In C++, a virtual function or virtual method is an inheritable and overridable function or method for which dynamic dispatch is facilitated. This concept is an important part of the (runtime) polymorphism portion of object-oriented programming (OOP).

In short, a virtual function defines a target function to be executed, but the target might not be known at compile time.

Unlike a non-virtual function, when a virtual function is overridden the most-derived version is used at all levels of the class hierarchy, rather than just the level at which it was created. Therefore if one method of the base class calls a virtual method, the version defined in the derived class will be used instead of the version defined in the base class.

This is in contrast to non-virtual functions, which can still be overridden in a derived class, but the "new" version will only be used by the derived class and below, but will not change the functionality of the base class at all.

A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class if the derived class is not abstract.

When a pure virtual method exists, the class is "abstract" and can not be instantiated on its own. Instead, a derived class that implements the pure-virtual method(s) must be used. A pure-virtual isn't defined in the base-class at all, so a derived class must define it, or that derived class is also abstract, and can not be instantiated. Only a class that has no abstract methods can be instantiated.

A virtual provides a way to override the functionality of the base class, and a pure-virtual requires it.

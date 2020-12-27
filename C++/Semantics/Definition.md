A common misconception is that definition equals declaration plus initialization.

The concepts of declaration, definition, and initialization are described below.


### Declaration

Declaration, generally, refers to the introduction of a new name in the program. For example, you can declare a new function by describing it's "signature":

void xyz();

or declare an incomplete type:

class klass;
struct ztruct;

and last but not least, to declare an object:

int x;

It is described, in the C++ standard, at §3.1/1 as:

    A declaration (Clause 7) may introduce one or more names into a translation unit or redeclare names introduced by previous declarations.



### Definition

A definition is a definition of a previously declared name (or it can be both definition and declaration). For example:

int x;
void xyz() {...}
class klass {...};
struct ztruct {...};
enum { x, y, z };

Specifically the C++ standard defines it as:

  A declaration is a definition unless it declares a function without specifying the function’s body (8.4), it contains the extern specifier (7.1.1) or a linkage-specification25 (7.5) and neither an initializer nor a function-body, it declares a static data member in a class definition (9.2, 9.4), it is a class name declaration (9.1), it is an opaque-enum-declaration (7.2), it is a template-parameter (14.1), it is a parameter-declaration (8.3.5) in a function declarator that is not the declarator of a function-definition, or it is a typedef declaration (7.1.3), an alias-declaration (7.1.3), a using-declaration (7.3.3), a static_assert-declaration (Clause 7), an attribute-declaration (Clause 7), an empty-declaration (Clause 7), or a using-directive (7.3.4).



### Initialization

Initialization refers to the "assignment" of a value, at construction time. For a generic object of type T, it's often in the form:

T x = i;

but in C++ it can be:

T x(i);

or even:

T x {i};

with C++11.



### Conclusion

    So does it mean definition equals declaration plus initialization?

It depends. On what you are talking about. If you are talking about an object, for example:

int x;

This is a definition without initialization. The following, instead, is a definition with initialization:

int x = 0;

In certain context, it doesn't make sense to talk about "initialization", "definition" and "declaration". If you are talking about a function, for example, initialization does not mean much.

So, the answer is no: definition does not automatically mean declaration plus initialization.

A common misconception is that definition equals declaration plus initialization.

The concepts of declaration, definition, and initialization are described below.


Declarations vs. definitions

In C++, you’ll often hear the words “declaration” and “definition” used, often interchangeably, though they are not.

A definition actually implements (for functions or types) or instantiates (for variables) the identifier. Here are some examples of definitions:

int add(int x, int y) // implements function add()
{
    int z{ x + y }; // instantiates variable z

    return z;
}

A definition is needed to satisfy the linker. If you use an identifier without providing a definition, the linker will error.

The one definition rule (or ODR for short) is a well-known rule in C++. The ODR has three parts:

    Within a given file, a function, object, type, or template can only have one definition.
    Within a given program, an object or normal function can only have one definition. This distinction is made because programs can have more than one file (we’ll cover this in the next lesson).
    Types, templates, inline functions, and variables are allowed to have identical definitions in different files. We haven’t covered what most of these things are yet, so don’t worry about this for now -- we’ll bring it back up when it’s relevant.

Violating part 1 of the ODR will cause the compiler to issue a redefinition error. Violating ODR part 2 will likely cause the linker to issue a redefinition error. Violating ODR part 3 will cause undefined behavior.


A declaration is a statement that tells the compiler about the existence of an identifier and its type information. Here are some examples of declarations:
	
int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
int x; // tells the compiler about an integer variable named x

A declaration is all that is needed to satisfy the compiler. This is why we can use a forward declaration to tell the compiler about an identifier that isn’t actually defined until later.

In C++, all definitions also serve as declarations. This is why int x appears in our examples for both definitions and declarations. Since int x is a definition, it’s a declaration too. In most cases, a definition serves our purposes, as it satisfies both the compiler and linker. We only need to provide an explicit declaration when we want to use an identifier before it has been defined.

While it is true that all definitions are declarations, the converse is not true: all declarations are not definitions. An example of this is the function prototype -- it satisfies the compiler, but not the linker. These declarations that aren’t definitions are called pure declarations. Other types of pure declarations include forward declarations for variables and type declarations (you will encounter these in future lessons, no need to worry about them now).

The ODR doesn’t apply to pure declarations (it’s the one definition rule, not the one declaration rule), so you can have as many pure declarations for an identifier as you desire (although having more than one is redundant).

Author's note

In common language, the term “declaration” is typically used to mean “a pure declaration”, and “definition” is used to mean “a definition that also serves as a declaration”. Thus, we’d typically call int x; a definition, even though it is both a definition and a declaration.



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


Declarations vs. definitions
It’s important to understand the difference between declarations and
definitions because these terms will be used precisely throughout
the book. Essentially all C and C++ programs require declarations.
Before you can write your first program, you need to understand
the proper way to write a declaration.
A declaration introduces a name – an identifier – to the compiler. It
tells the compiler “This function or this variable exists somewhere,
and here is what it should look like.” A definition, on the other
hand, says: “Make this variable here” or “Make this function here.”
It allocates storage for the name. This meaning works whether
you’re talking about a variable or a function; in either case, at the
point of definition the compiler allocates storage. For a variable, the
compiler determines how big that variable is and causes space to be
generated in memory to hold the data for that variable. For a
function, the compiler generates code, which ends up occupying
storage in memory.
You can declare a variable or a function in many different places,
but there must be only one definition in C and C++ (this is
sometimes called the ODR: one-definition rule). When the linker is
uniting all the object modules, it will usually complain if it finds
more than one definition for the same function or variable.
A definition can also be a declaration. If the compiler hasn’t seen
the name x before and you define int x;, the compiler sees the name
as a declaration and allocates storage for it all at once.

a declaration is a language construct that specifies properties of an identifier: it declares what a word (identifier) "means". Declarations are most commonly used for functions, variables, constants, and classes


Beyond the name (the identifier itself) and the kind of entity (function, variable, etc.), declarations typically specify the data type (for variables and constants), or the type signature (for functions); types may also include dimensions, such as for arrays.

A declaration is used to announce the existence of the entity to the compiler; this is important in those strongly typed languages that require functions, variables, and constants, and their types to be specified with a declaration before use, and is used in forward declaration.

The term "declaration" is frequently contrasted with the term "definition", but meaning and usage varies significantly between languages

Declarations:
  Variable
  Constant
  Functions
  Classes




Declaration vs Definition
One basic dichotomy is whether or not a declaration contains a definition: for example, whether a declaration of a constant or variable specifies it's value or only its type; and similarly whether a declaration of a function specifies the body (implementation) of the function, or only its type signature.

In informal usage, a "declaration" refers only to a pure declaration (types only, no value or body), while a "definition" refers to a declaration that includes a value or body.







https://en.wikipedia.org/wiki/Forward_declaration


a forward declaration is a declaration of an identifier (denoting an entity such as a type, a variable, a constant, or a function) for which the programmer has not yet given a complete definition.

Statically typed languages

A statically typed language's expressions have their types determined prior to when the program is executed, typically at compile-time.

The main advantage here is that all kinds of checking can be done by the compiler, and therefore a lot of trivial bugs are caught at a very early stage.

Statically typed languages can be either manifestly typed or type-inferred.
  manifestly typed: the programmer must explicitly write types at certain textual positions (for example, at variable declarations).

  type-inferred: the compiler infers the types of expressions and declarations based on context.


Most mainstream statically typed languages, such as C++, C# and Java, are manifestly typed. Complete type inference has traditionally been associated with less mainstream languages, such as Haskell and ML.

However, many manifestly typed languages support partial type inference; for example, C++, Java and C# all infer types in certain limited cases. Additionally, some programming languages allow for some types to be automatically converted to other types; for example, an int can be used where the program expects a float.


Compatibility: equivalence and subtyping
A type checker for a statically typed language must verify that the type of any expression is consistent with the type expected by the context in which that expression appears.

For example, in an assignment statement of the form x :=e, the inferred type of the expression e must be consistent with the declared or inferred type of the variable x. This notion of consistency, called compatibility, is specific to each programming language.

If the type of e and the type of x are the same, and assignment is allowed for that type, then this is a valid expression. Thus, in the simplest type systems, the question of whether two types are compatible reduces to that of whether they are equal (or equivalent).

Different languages, however, have different criteria for when two type expressions are understood to denote the same type.

These different equational theories of types vary widely, two extreme cases being structural type systems, in which any two types that describe values with the same structure are equivalent, and nominative type systems, in which no two syntactically distinct type expressions denote the same type (i.e., types must have the same "name" in order to be equal).

In languages with subtyping, the compatibility relation is more complex. In particular, if A is a subtype of B, then a value of type A can be used in a context where one of type B is expected, even if the reverse is not true. Like equivalence, the subtype relation is defined differently for each programming language, with many variations possible. The presence of parametric or ad hoc polymorphism in a language may also have implications for type compatibility.

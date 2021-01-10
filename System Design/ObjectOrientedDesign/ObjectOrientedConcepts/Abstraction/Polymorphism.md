Generally, polymorphism refers to the ability of acquiring many forms.

Polymorphism is one of the most powerful aspects of object-oriented programming.



Polymorphism is the capability to provide multiple implementations of an action and to select the correct implementation based on the surrounding context.

Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

The idea is that you can expand and enhance your application by simply adding new classes derived from a common base class. Then you have to make very few (if any) modifications to the rest of your application.

Considering the is-a relationship, polymorphism can be thought of as using a subclass when a superclass has been asked for. The behavior of the subclass will remain, but the user of the polymorphic type is none the wiser.

Polymorphic code is code you write once and can reuse with different types. Ultimately, this flexibility yields loosely coupled and highly reusable code. It eliminates tedious copying and pasting, making your code more maintainable and readable.





In programming languages and type theory, polymorphism is the provision of a single interface to entities of different types or the use of a single symbol to represent multiple different types.

The most commonly recognized major classes of polymorphism are:

    Ad hoc polymorphism: defines a common interface for an arbitrary set of individually specified types.
    Parametric polymorphism: when one or more types are not specified by name but by abstract symbols that can represent any type.
    Subtyping (inclusion) polymorphism: when a name denotes instances of many different classes related by some common superclass
    Coercion polymorphism: Implicit type conversion has also been defined as a form of polymorphism, referred to as "".



ad hoc polymorphism
the term ad hoc polymorphism to refer to polymorphic functions that can be applied to arguments of different types, but that behave differently depending on the type of the argument to which they are applied (also known as function overloading or operator overloading).[5] The term "ad hoc" in this context is not intended to be pejorative; it refers simply to the fact that this type of polymorphism is not a fundamental feature of the type system.



Parametric polymorphism
Parametric polymorphism allows a function or a data type to be written generically, so that it can handle values uniformly without depending on their type.[7] Parametric polymorphism is a way to make a language more expressive while still maintaining full static type-safety.

The concept of parametric polymorphism applies to both data types and functions. A function that can evaluate to or be applied to values of different types is known as a polymorphic function. A data type that can appear to be of a generalized type (e.g. a list with elements of arbitrary type) is designated polymorphic data type like the generalized type from which such specializations are made.

Parametric polymorphism is also available in several object-oriented languages. For instance, templates in C++, or generics in Java:


Subtype Polymorphism
Some languages employ the idea of subtyping (also called subtype polymorphism or inclusion polymorphism) to restrict the range of types that can be used in a particular case of polymorphism. In these languages, subtyping allows a function to be written to take an object of a certain type T, but also work correctly, if passed an object that belongs to a type S that is a subtype of T (according to the Liskov substitution principle). This type relation is sometimes written S <: T. Conversely, T is said to be a supertype of S—written T :> S. Subtype polymorphism is usually resolved dynamically (see below).

if Number, Rational, and Integer are types such that Number :> Rational and Number :> Integer, a function written to take a Number will work equally well when passed an Integer or Rational as when passed a Number. The actual type of the object can be hidden from clients into a black box, and accessed via object identity. In fact, if the Number type is abstract, it may not even be possible to get your hands on an object whose most-derived type is Number (see abstract data type, abstract class).

Object-oriented programming languages offer subtype polymorphism using subclassing (also known as inheritance). With subtyping, calling code can be agnostic as to which class in the supported hierarchy it is operating on - the parent class or one of its descendants. Meanwhile, the same operation name among objects in an inheritance hierarchy may behave differently.

In typical implementations, each class contains what is called a virtual table—a table of functions that implement the polymorphic part of the class interface—and each object contains a pointer to the "vtable" of its class, which is then consulted whenever a polymorphic method is called. This mechanism is an example of:

  late binding, because virtual function calls are not bound until the time of invocation;
  single dispatch (i.e. single-argument polymorphism), because virtual function calls are bound simply by looking through the vtable provided by the first argument (the this object), so the runtime types of the other arguments are completely irrelevant.

The interaction between parametric polymorphism and subtyping leads to the concepts of variance and bounded quantification.




Coercion Polymorphism
When the type of a source expression is compatible with the type of its target entity. In this rule, compatible with means that the type of the source expression either conforms to or converts to that of the target. Conformance of types is defined by the rules for polymorphism above.




Implementation Aspects
Polymorphism can be distinguished by when the implementation is selected: statically (at compile time) or dynamically (at run time, typically via a virtual function). This is known respectively as static dispatch and dynamic dispatch, and the corresponding forms of polymorphism are accordingly called static polymorphism and dynamic polymorphism.

Static polymorphism executes faster, because there is no dynamic dispatch overhead, but requires additional compiler support. Further, static polymorphism allows greater static analysis by compilers (notably for optimization), source code analysis tools, and human readers (programmers). Dynamic polymorphism is more flexible but slower—for example, dynamic polymorphism allows duck typing, and a dynamically linked library may operate on objects without knowing their full type.

Static polymorphism typically occurs in ad hoc polymorphism and parametric polymorphism, whereas dynamic polymorphism is usual for subtype polymorphism.

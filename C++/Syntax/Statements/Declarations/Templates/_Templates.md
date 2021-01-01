## Templates

C++ templates achieve compile-time polymorphism


### Idea
A template is a class or function with template parameters.

These parameters, called type parameters, can stand in for any type, including fundamental and user-defined types.

The big idea is single source code template substitutes a type parameter for a given type throughout the template statements. This type parameter functions much like a function parameter in that a supplied type values is substituted everywhere the type parameter is specified throughout the statements.

When the templated code is invoke with a type value the compiler generates new template instance, an implementation of the statements that use the source code as a template and the type specified as template instantiation.

Template instantiation is the process of creating a class or a function from a template. Somewhat confusingly, you can also refer to “a template instantiation” as the result of the template instantiation process. Template instantiations are also called concrete classes and concrete types.

The template feature allows us to write a single code segment for:
  a set of related functions, called a function template or parameterized operations.
  a set of related classes, called a class template or parameterized type.



### Use of Templates
Templates are the C++ foundation of generic programming, which involves writing code in a way that is independent of any particular type. Thus, a template can be thought of as blueprint or formula for creating a generic class or a function.

Templates have many more uses than simply parameterizing a type. In particular, they are extensively used for parameterization of both types and algorithms in the standard library.

The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept.

There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.

Templates are a compile-time mechanism, so their use incurs no run-time overhead compared to hand-crafted code.










What programming techniques are effective when you use templates?

Templates offer:
• The ability to pass types (as well as values and templates) as arguments without loss of information. This implies excellent opportunities for inlining, of which current implementations take great advantage.

• Opportunities to weave together information from different contexts at instantiation time. This implies optimization opportunities.

• The ability to pass constant values as arguments. This implies the ability to do compile-time computation.

In other words, templates provide a powerful mechanism for compile-time computation and type manipulation that can lead to very compact and efficient code. Remember that types (classes) can contain both code (§6.3.2) and values (§6.2.2).

The first and most common use of templates is to support generic programming, that is, programming focused on the design, implementation, and use of general algorithms. Here, ‘‘general’’
means that an algorithm can be designed to accept a wide variety of types as long as they meet the
algorithm’s requirements on its arguments. Together with concepts, the template is C++’s main
support for generic programming. Templates provide (compile-time) parametric polymorphism.






### Declaring Templates
In C++, template is a reserved word.

You declare templates with a template prefix.

A template prefix consists of the keyword template followed by angle brackets < > which contain a comma delimited list of one or more template parameter declarations.

A template parameters declaration uses either the typename or class keywords followed by a type identifier.

Similar to variables being parameters to functions, types (that is, data types) are parameters to templates. The type identifier is referred to as a formal parameter to the template.

Syntax:
template <class T>
//declaration

OR

template <typename T>
//declaration

This template takes a template parameter T to be used in the declaration:
  T is the name of a data type, built-in or user-defined
  declaration is either a function declaration or a class declaration.

NOTE
The coexistence of the typename and class keywords is unfortunate and confusing. They mean the same thing, in older code we often see template<class T> as the prefix so both are supported for historical reasons.






### Polymorphism at Runtime vs. Compile Time
When you want polymorphism, you should use templates. But sometimes
you can’t use templates because you won’t know the types used with your
code until runtime. Remember that template instantiation only occurs
when you pair a template’s parameters with types. At this point, the compiler can instantiate a custom class for you. In some situations, you might
not be able to perform such pairings until your program is executing (or,
at least, performing such pairing at compile time would be tedious).
In such cases, you can use runtime polymorphism. Whereas the template
is the mechanism for achieving compile-time polymorphism, the runtime
mechanism is the interface.

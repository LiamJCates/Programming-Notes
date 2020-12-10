Advanced Template Topics

For everyday polymorphic programming, templates are your go-to tool. It
turns out that templates are also used in a wide range of advanced settings,
especially in implementing libraries, high-performance programs, and
embedded system firmware. This section outlines some of the major terrain
features of this vast space.

Template Specialization
To understand advanced template usage, you must first understand template specialization. Templates can actually take more than just concept
and typename parameters (type parameters). They can also accept fundamental types, like char (value parameters), as well as other templates. Given
the tremendous flexibility of template parameters, you can make a lot of
compile-time decisions about their features. You could have different versions of templates depending on the characteristics of these parameters.
For example, if a type parameter is Ordered instead of Regular, you might be
able to make a generic program more efficient. Programming this way is
called template specialization. Refer to the ISO standard [temp.spec] for more
information about template specialization.

Name Binding
Another critical component of how templates get instantiated is name
binding. Name binding helps determine the rules for when the compiler
matches a named element within a template to a concrete implementation.
The named element could, for example, be part of the template definition, a local name, a global name, or from some named namespace. If you
want to write heavily templated code, you need to understand how this
binding occurs. If you’re in such a situation, refer to Chapter 9, “Names
in Templates,” in C++ Templates: The Complete Guide by David Vandevoorde
et al. and to [temp.res].

Type Function
A type function takes types as arguments and returns a type. The type traits
with which you build up concepts are closely related to type functions.
You can combine type functions with compile time control structures to
do general computation, such as programming control flow, at compile
time. Generally, programming using these techniques is called template
metaprogramming.

Template Metaprogramming
Template metaprogramming has a deserved reputation for resulting in
code that is exceedingly clever and absolutely inscrutable to all but the
mightiest of wizards. Fortunately, once concepts are part of the C++ standard, template metaprogramming should become more approachable to
us mere mortals. Until then, tread carefully. For those interested in further detail on this topic, refer to Modern C++ Design: Generic Programming
and Design Patterns Applied by Andrei Alexandrescu and C++ Templates: The
Complete Guide by David Vandevoorde et al.


Template Source Code Organization
Each time a template is instantiated, the compiler must be able to generate all the code necessary to use the template. This means all the information about how to instantiate a custom class or function must be available
within the same translation unit as the template instantiation. By far, the
most popular way to achieve this is to implement templates entirely within
header files.
There are some modest inconveniences associated with this approach.
Compile times can increase, because templates with the same parameters
might get instantiated multiple times. It also decreases your ability to hide
implementation details. Fortunately, the benefits of generic programming
far outweigh these inconveniences. (Major compilers will probably minimize the problems of compile times and code duplication anyway.)
There are even a few advantages to having header-only templates:
•	 It’s very easy for others to use your code: it’s a matter of applying
 #include to some headers (rather than compiling the library, ensuring the resulting object files are visible to the linker, and so on).
•	 It’s trivially easy for compilers to inline header-only templates, which
can lead to faster code at runtime.
•	 Compilers can generally do a better job of optimizing code when all of
the source is available.

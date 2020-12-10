## Variadic Templates
Sometimes, templates must take in an unknown number of arguments. The
compiler knows these arguments at template instantiation, but you want to
avoid having to write many different templates each for different numbers
of arguments. This is the raison d’être of variadic templates. Variadic templates take a variable number of arguments.
You denote variadic templates using a final template parameter that
has a special syntax, namely typename... arguments. The ellipsis indicates
that arguments is a parameter pack type, meaning you can declare parameter
packs within your template. A parameter pack is a template argument that
accepts zero or more function arguments. These definitions can seem a
bit abstruse, so consider the following sample variadic template that builds
upon SimpleUniquePointer.

template <typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
  return SimpleUniquePointer<T>{ new T{ arguments... } };
}

You define the parameter pack type Arguments, which declares make_simple_unique as a variadic template. This function passes arguments to
the constructor of template parameter T.

The upshot is you can now create SimpleUniquePointers very easily, even
when the pointed-to object has a non-default constructor.

NOTE
There is a slightly more efficient implementation of Listing 6-34. If arguments is an rvalue, you can move it directly into the constructor of T. The stdlib contains a function called std::forward in the <utility> header that will detect whether arguments is an lvalue or rvalue and perform a copy or move, respectively. See Item 23 in Effective Modern C++ by Scott Meyers.

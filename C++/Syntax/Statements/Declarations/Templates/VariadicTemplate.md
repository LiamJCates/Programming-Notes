## Variadic Templates
Sometimes, templates must take in an unknown number of arguments. The compiler knows these arguments at template instantiation, but you want to avoid having to write many different templates each for different numbers of arguments. This is the raison d’être of variadic templates. Variadic templates take a variable number of arguments.

You denote variadic templates using a final template parameter that has a special syntax, namely typename... arguments. The ellipsis indicates that arguments is a parameter pack type, meaning you can declare parameter packs within your template. A parameter pack is a template argument that accepts zero or more function arguments. These definitions can seem a bit abstruse, so consider the following sample variadic template that builds upon SimpleUniquePointer.

template <typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
  return SimpleUniquePointer<T>{ new T{ arguments... } };
}

You define the parameter pack type Arguments, which declares make_simple_unique as a variadic template. This function passes arguments to the constructor of template parameter T.

The upshot is you can now create SimpleUniquePointers very easily, even when the pointed-to object has a non-default constructor.

NOTE
There is a slightly more efficient implementation of Listing 6-34. If arguments is an rvalue, you can move it directly into the constructor of T. The stdlib contains a function called std::forward in the <utility> header that will detect whether arguments is an lvalue or rvalue and perform a copy or move, respectively. See Item 23 in Effective Modern C++ by Scott Meyers.




## Variadic Templates
The variadic template enables you to create function templates that accept variadic, same-typed arguments. They enable you to employ the considerable power of the template engine. To declare a variadic template, you add a special template parameter called a template parameter pack.

Syntax:
  template <typename.. Args>
  return-type func-name(Args... args) {
    // Use parameter pack semantics
    // within function body
  }


The template parameter pack is part of the template parameter list. When you use Args within the function template, it’s called a function parameter pack. Some special operators are available for use with parameter packs:
•	 You can use sizeof...(args) to obtain the parameter pack’s size.
•	 You can invoke a function with the special syntax other_function(args...).  This expands the parameter pack args and allows you to perform further processing on the arguments contained in the parameter pack.


### Programming with Parameter Packs
Unfortunately, it’s not possible to index into a parameter pack directly. You must invoke the function template from within itself — a process called compile-time recursion—to recursively iterate over the elements in a parameter pack.

  template <typename T, typename...Args>
  void my_func(T u, Args...args) {
    // Use x, then recurse:
    my_func(args...);
  }

Unlike other usage listings, the ellipses contained in this listing are literal.
The key is to add a regular template parameter before the parameter pack. Each time you invoke my_func, x absorbs the first argument. The remainder packs into args. To invoke, you use the args... construct to expand the parameter pack.

The recursion needs a stopping criteria, so you add a function template
specialization without the parameter:

  template <typename T>
  void my_func(T x) {
  // Use x, but DON'T recurse
  }

  Revisiting the sum Function:

  #include <cstdio>

  template <typename T>
  constexpru T sum(T x) {
    return x;
  }

  template <typename T, typename... Args>
  constexpr T sum(T x, Args... args) {
    return x + sum(args...);
  }

  int main() {
    printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12));
  }

The first function is the overload that handles the stopping condition; if the function has only a single argument, you simply return the argument x, because the sum of a single element is just the element. The variadic template follows the recursion pattern. It peels a single argument x off the parameter pack args and then returns x plus the result of the recursive call to sum with the expanded parameter pack. Because all of this generic programming can be computed at compile time, you mark these functions constexpr. This compile-time
computation is a major advantage, which has identical output but computes the result at runtime.



## Fold Expressions
When you just want to apply a single binary operator over a range of values, you can use a fold expression instead of recursion.

A fold expression computes the result of using a binary operator over all the arguments of a parameter pack. Fold expressions are distinct from but related to variadic templates.

Syntax:
(... binary-operator parameter-pack)

For example, you could employ the following fold expression to sum over all elements in a parameter pack called pack:
(... + args)


  #include <cstdio>
  template <typename... T>
  constexpr auto sum(T... args) {
    return (... + args);
  }

  int main() {
    printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12)); v
  }

You simplify the sum function by using a fold expression instead of the
recursion approach. The end result is identical.

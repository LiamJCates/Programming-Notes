## Variadic Functions
Variadic functions take a variable number of arguments. Typically, you specify
the exact number of arguments a function takes by enumerating all of its
parameters explicitly. With a variadic function, you can take any number
of arguments. The variadic function printf is a canonical example: you
provide a format specifier and an arbitrary number of parameters. Because
printf is a variadic function, it accepts any number of parameters.

You declare variadic functions by placing ... as the final parameter
in the function’s argument list. When a variadic function is invoked, the
compiler matches arguments against declared arguments. Any leftovers
pack into the variadic arguments represented by the ... argument.
You cannot extract elements from the variadic arguments directly.
Instead, you access individual arguments using the utility functions in the
<cstdarg> header.

Utility Functions in the <cstdarg> Header
| Function | Description |
| va_list | Used to declare a local variable representing the variadic arguments |
| va_start | Enables access to the variadic arguments |
| va_end | Used to end iteration over the variadic arguments |
| va_arg | Used to iterate over each element in the variadic arguments |
| va_copy | Makes a copy of the variadic arguments |

The utility functions’ usage is a little convoluted and best presented in
a cohesive example. Consider this variadic sum function:

#include <cstdio>
#include <cstdint>
#include <cstdarg>

int sum(size_t n, ...) {
  va_list args;
  va_start(args, n);
  int result{};
  while (n--) {
    auto next_element = va_arg(args, int);
    result += next_element;
  }
  va_end(args);
  return result;
}

int main() {
  printf("The answer is %d.", sum(6, 2, 4, 6, 8, 10, 12));
}

The answer is 42.

You declare sum as a variadic function. All variadic functions must
declare a va_list. You’ve named it args. A va_list requires initialization
with va_start, which takes two arguments. The first argument is a va_list,
and the second is the size of the variadic arguments. You iterate over each
element in the variadic arguments using the va_args function. The first
argument is the va_list argument, and the second is the argument type.
Once you’ve completed iterating, you call va_list with the va_list structure.
You invoke sum with seven arguments: the first is the number of variadic
arguments (six) followed by six numbers (2, 4, 6, 8, 10, 12).
Variadic functions are a holdover from C. Generally, variadic functions
are unsafe and a common source of security vulnerabilities.

There are at least two major problems with variadic functions:
•	 Variadic arguments are not type-safe. (Notice that the second argument of va_args is a type.)
•	 The number of elements in the variadic arguments must be tracked separately.

The compiler cannot help you with either of these issues.
Fortunately, variadic templates provide a safer and more performant way to implement variadic functions.



## Variadic Templates
The variadic template enables you to create function templates that accept variadic, same-typed arguments. They enable you to employ the considerable power of the template engine. To declare a variadic template, you add a special template parameter called a template parameter pack.

Syntax:
template <typename.. Args>
return-type func-name(Args... args) {
  // Use parameter pack semantics
  // within function body
}


The template parameter pack is part of the template parameter list. When you use Args within the function template, it’s called a function parameter pack. Some special operators are available for use with parameter
packs:
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

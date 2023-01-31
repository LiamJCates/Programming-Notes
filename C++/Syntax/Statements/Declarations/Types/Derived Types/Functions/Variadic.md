## Variadic Functions
Variadic functions take a variable number of arguments.

Typically, you specify the exact number of arguments a function takes by enumerating all of its parameters explicitly. With a variadic function, you can take any number of arguments.

The variadic function printf is a canonical example: you provide a format specifier and an arbitrary number of parameters. Because printf is a variadic function, it accepts any number of parameters.

You declare variadic functions by placing ... as the final parameter in the function’s argument list. When a variadic function is invoked, the compiler matches arguments against declared arguments. Any leftovers pack into the variadic arguments represented by the ... argument.

You cannot extract elements from the variadic arguments directly.

Instead, you access individual arguments using the utility functions in the

  <cstdarg> header.

Utility Functions in the <cstdarg> Header

| Function | Description |
|----------|-------------|
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

Output
  The answer is 42.

You declare sum as a variadic function. All variadic functions must declare a va_list. Named args above. A va_list requires initialization with va_start, which takes two arguments. The first argument is a va_list, and the second is the size of the variadic arguments. You iterate over each element in the variadic arguments using the va_args function. The first argument is the va_list argument, and the second is the argument type.

Once you’ve completed iterating, you call va_list with the va_list structure. You invoke sum with seven arguments: the first is the number of variadic arguments (six) followed by six numbers (2, 4, 6, 8, 10, 12).

Variadic functions are a holdover from C. Generally, variadic functions are unsafe and a common source of security vulnerabilities.

There are at least two major problems with variadic functions:

  Variadic arguments are not type-safe. (Notice that the second argument of va_args is a type.)
  The number of elements in the variadic arguments must be tracked separately.

The compiler cannot help you with either of these issues.

Fortunately, variadic templates provide a safer and more performant way to implement variadic functions.

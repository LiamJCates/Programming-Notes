### Lambda Variables

While it can be tempting to define compact definitions via a lambda in the same line that it is used, this can often times make code harder to read, an example follows.

For example, in the following snippet, we’re using std::all_of to check if all elements of an array are even:
```cpp
  // Bad: We have to read the lambda to understand what's happening.
  return std::all_of(array.begin(), array.end(),
    [](int i){ return ((i % 2) == 0);}
  );
```

Much like we can initialize a variable with a literal value (or a function pointer) for use later, we can also initialize a lambda variable with a lambda definition. A named lambda along with a good function name can make code easier to read.

We can improve the readability of this as follows:

Although a lambda is an unnamed function, you can give it a name by assigning the lambda to a variable. This is a case where you probably want to declare the variable using the auto keyword, so you don’t have to think about the type of the lambda that is the variable’s initial value.

```cpp
// Good: Instead, we can store the lambda in a named variable and pass it to the function.
  auto isEven{
    [](int i) { return ((i % 2) == 0); }
  };

  return std::all_of(array.begin(), array.end(), isEven);
```

Note how well the last line reads: “return whether all of the elements in the array are even”

Once you assign a lambda to a variable, you can call that variable as though it were an ordinary function, an example of calling the isEven function above:

  bool is_it_even = isEven(2);

The advantage of naming a lambda is that you can call it more than once in the same function. In this way, you get the benefit of self-documenting code with a well-chosen name and the benefit of a local definition.

If you don’t want to use auto, the standard library can help.

In the <functional> header is the type std::function, which you use by placing a function’s return type and parameter types in angle brackets. For example, the following defines a variable, times_two, and initializes it with a lambda that takes one argument of type int and returns int:

std::function<int(int)> times_two{ [](int i) { return i * 2; } };

The actual type of a lambda is more complicated, but the compiler knows how to convert that type to the matching std::function<> type.

Using auto is preferred because calling a std::function incurs a small cost that an auto lambda does not.

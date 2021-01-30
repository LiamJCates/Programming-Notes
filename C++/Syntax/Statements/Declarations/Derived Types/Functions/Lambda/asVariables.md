### Lambda Variables
Lambda expressions were introduced in C++11 and help in the usage of STL algorithms to sort or process data.

An example of usage is a sort function. Typically, a sort function requires you to supply a binary predicate. This is a function that compares two arguments and returns true if one is less than the other, else false, thereby helping in deciding the order of elements in a sort operation.

Such predicates are typically implemented as operators in a class, leading to a tedious bit of coding. Lambda expressions can compact predicate definitions

While it can be tempting to define such compact predicate definition via a lambda in the same line that it is used, this can often times make code harder to read, an example follows.

Much like we can initialize a variable with a literal value (or a function pointer) for use later, we can also initialize a lambda variable with a lambda definition. A named lambda along with a good function name can make code easier to read.

For example, in the following snippet, we’re using std::all_of to check if all elements of an array are even:

  // Bad: We have to read the lambda to understand what's happening.
  return std::all_of(array.begin(), array.end(), [](int i){ return ((i % 2) == 0); });

We can improve the readability of this as follows:

  // Good: Instead, we can store the lambda in a named variable and pass it to the function.
  auto isEven{
    [](int i)
    {
      return ((i % 2) == 0);
    }
  };

  return std::all_of(array.begin(), array.end(), isEven);

Note how well the last line reads: “return whether all of the elements in the array are even”

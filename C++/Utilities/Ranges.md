Several programs that you’ve read and written have a common theme: copying a sequence of data, such as
a vector or string, and applying some kind of transformation to each element (converting to lowercase,
doubling the values in an array, and so on). The standard algorithm, transform, is ideal for applying an
arbitrarily complex transformation to the elements of a range.

We can solve this problem using  transform and range adaptors.

```cpp
/** Listing 22-1. Calling transform to Apply a Function to Each Element of a Range */
#include <iostream>
#include <iterator>
#include <ranges>

int times_two(int i)
{
  return i * 2;
}

int plus_three(int i)
{
  return i + 3;
}

int main()
{
   auto data{ std::ranges::istream_view<int>(std::cin)
              | std::ranges::views::transform(times_two)
              | std::ranges::views::transform(plus_three)
   };
   for (auto element : data)
      std::cout << element << '\n';
}
```

istream_view reads values from an input source, such as the standard input. In this case, the values it reads are integers. It produces a sequence of values known as a range.

In addition to being used in a ranged for loop, a range can also feed a pipeline, as indicated by the pipe (|) operator. A range can also take a pipeline as input.

In this example, transform is a range adaptor. It calls a user-supplied function for each item in the range. A pipeline starts with a range and contains as many subsequent range adaptors or views as you wish. A range adaptor adapts a range algorithm for use in a pipeline, and the standard library supplies several in the std::ranges::views namespace, which you are free to shorten by using simply std::views.

The transform function has several flavors. This one takes two arguments: the data to transform and the name of a function.

Most algorithms are declared in the <algorithm> header with help from the <ranges> header.

You will often need both.

Even though the data variable seems to hold the entire range, range adaptors process their data one element at a time instead of storing any data.

So the first part of the program sets up the data pipeline.
The second part, the for loop, evaluates the pipeline. That’s when the input is read, one integer at a time, transformed, and then printed by the loop body.

The final argument to transform is the name of a function that you must have declared or defined earlier in the source file. In this example, the functions each take one int parameter and return an int.

The general rule for a transform function is that its parameter type must match the input type, which is the type of the elements in the input range. The return value is of the same or compatible type.

The transform algorithm calls this function once for each element in the range and returns the new value.



The purpose of the C++ standard library is not to provide a zillion functions that cover all possible programming scenarios but, rather, to provide the tools you need to build your own functions with which you can solve your problems. Thus, you would search the standard library in vain for a single algorithm that copies, transforms, and filters. Instead, you can combine two standard functions: one that transforms and one that filters.

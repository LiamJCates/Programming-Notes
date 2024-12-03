Several programs that you’ve read and written have a common theme: copying a sequence of data, such as a vector or string, and applying some kind of transformation to each element (converting to lowercase, doubling the values in an array, and so on). The standard algorithm, transform, is ideal for applying an arbitrarily complex transformation to the elements of a sequence.


/* Calling transform to Apply a Function to Each Element of an Array */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

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
   std::vector<int> data{std::istream_iterator<int>(std::cin),
                         std::istream_iterator<int>()};

   std::transform(data.begin(), data.end(), data.begin(), times_two);
   std::transform(data.begin(), data.end(), data.begin(), plus_three);

   std::copy(data.begin(), data.end(),
             std::ostream_iterator<int>(std::cout, "\n"));
}


The transform function takes four arguments: the first two specify the input range (as start and one-past-the-end iterators), the third argument is a write iterator, and the final argument is the name of a function. Like other iterator-based algorithms, transform is declared in the <algorithm> header. Regarding the third argument, as usual, it is your responsibility to ensure the output sequence has enough room to accommodate the transformed data. In this case, the transformed data overwrite the original data, so the start of the output range is the same as the start of the input range. The fourth argument is just the name of a function that you must have declared or defined earlier in the source file. In this example, the function takes one int parameter and returns an int. The general rule for a transform function is that its parameter type must match the input type, which is the type of the element to which the read iterators refer. The return value must match the output type, which is the type to which the result iterator refers. The transform algorithm calls this function once for each element in the input range. It copies to the output range the value returned by the function.

Notice that this version of the program makes an extra pass over the range in order to apply two
transformations. The ranged version of the program could perform both transformations in one pass.
In order to make a single pass, you need a single function, so you could write one function that multiplies by
two and then adds three.

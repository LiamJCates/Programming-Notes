std::array automates the allocation and deallocation of memory.

std::array is a templatized class that takes two parameters – the type of the elements and the size of the array.

std::array<int, 10> arr;  // int array size 10

std::array provides operator[], which is same as the C-style array, and avoids the cost of checking whether the index is less than the size of the array.

arr[0] = 1;               // Sets the first element as 1

std::array<int, 4> arr2 = {1, 2, 3, 4};

std::cout << "Elements in second array: ";

for(int i = 0; i < arr.size(); i++)
std::cout << arr2[i] << " ";

at(index) function throws an exception if the argument is not valid.

we can always catch the error using exception handling, as demonstrated in the following example.
try
{
  std::cout << arr.at(4); // No error
  std::cout << arr.at(5); // Throws exception std::out_of_range
}
catch (const std::out_of_range& ex)
{
  std::cerr << ex.what();
}


passing std::array to another function is similar to passing any built-in data type. We can pass it by value or reference, with or without const. Additionally, the syntax doesn't involve any pointer-related operations or referencing and de-referencing operations. Hence, the readability is much better compared to C-style arrays, even for multidimensional arrays.

The following example demonstrates how to pass an array by value:
void print(std::array<int, 5> arr)
{
  for(auto ele: arr)
    std::cout << ele << ", ";
}

std::array<int, 5> arr = {1, 2, 3, 4, 5};
print(arr);

This example would produce the following output:
1, 2, 3, 4, 5

We can't pass an array of any other size for this function, because the size of the array is a part of the data type of the function parameter. So, for example, if we pass std::array<int, 10>, the compiler will return an error saying that it can't match the function parameter, nor can it convert from one to the other.

However, if we want to have a generic function that can work with std::array of any size, we can make the size of the array templatized for that function, and it will generate code for all the required sizes of the array. So, the signature will look like the following:

template <size_t N>
void print(const std::array<int, N>& arr)

Apart from readability, while passing std::array, it copies all the elements into a new array by default. Hence, an automatic deep copy is performed. If we don't want that feature, we can always use other types, such as reference and const reference. Thus, it provides greater flexibility for programmers.

In practice, for most operations, std::array provides similar performance as a C-style array, since it is just a thin wrapper to reduce the effort of programmers and make the code safer.

std::array provides two different functions to access array elements –
operator[] and at().

operator[], is similar to C-style arrays, and doesn't perform any check on the index. However, the at() function provides a check on the index, and throws an exception if the index is out of range. Due to this, it is a bit slower in practice.



### Comparison
Another useful functionality provided by std::array is the relational operator for deep
comparison and the copy-assignment operator for deep copy. All size operators (<, >, <=, >=, ==, !=) are defined for std::array to compare two arrays, provided the same
operators are also provided for the underlying type of std::array.
C-style arrays also support all the relational operators, but these operators don't
actually compare the elements inside the array; in fact, they just compare the pointers.
Therefore, just the address of the elements is compared as integers instead of a deep
comparison of the arrays. This is also known as a shallow comparison, and it is not of
much practical use. Similarly, assignment also doesn't create a copy of the assigned
data. Instead, it just makes a new pointer that points to the same data.
Note
Relational operators work for std::array of the same size only. This is because
the size of the array is a part of the data type itself, and it doesn't allow values of
two different data types to be compared.



### Iteration

std::array iterator interface for printing all the elements in an array:

std::array<int, 5> arr = {1, 2, 3, 4, 5};
for(auto element: arr)
{
  std::cout << element << ' ';
}

This example would show the following output:
1 2 3 4 5


The reason we can iterate over std::array using a range-based loop is due to iterators.

Hence, a range-based for loop starts at begin() and ends at end(), advancing step by step using the increment operator (++).


The array.begin() function returns an iterator that points to the first element,
The array.end() function returns an iterator just after the last element.
The array.data() function returns a pointer to the actual buffer stored inside the object. Allows pointer arithmetic and similar operations. Helpful when dealing with old/legacy code that only accepts a raw pointer as a function parameter.

So, a range-based loop can be written as follows:
for(auto it = arr.begin(); it != arr.end(); it++)
{
  auto element = (*it);
  std::cout << element << ' ';
}

There are some other forms of iterators, such as const_iterator and reverse_iterator, which are also quite useful. const_iterator is a const version of the normal iterator. If
the array is declared to be a const, its functions that are related to iterators, such as begin() and end(), return const_iterator.

reverse_iterator allows us to traverse the array in the reverse direction. So, its functions, such as the increment operator (++) and advance, are inverses of such
operations for normal iterators.

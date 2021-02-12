An understanding of the mechanics of dynamic allocation are required to understand the following content.

For information regarding dynamic memory allocation, see:
[C++\Syntax\Statements\Declarations\Derived Types\PointersAndReferences\DynamicMemory.md]



### Dynamically allocating arrays

In addition to dynamically allocating single values, we can also dynamically allocate arrays of variables.

To allocate an array dynamically, we use the array form of new and delete, new[] and delete[].

When using new[], we specify the number of elements to allocate memory for:

  type_name* ptr_name = new type_name[number_or_elements];

Thus, if you need to allocate integers, you use the following syntax:

int* pointToAnInt = new int;      // get a pointer to an integer
int* pointToNums = new int[10];   // pointer to a block of 10 integers

Note that new indicates a request for memory. There is no guarantee that a call for allocation always succeeds because this depends on the state of the system and the availability of memory resources.



### Dynamically deleting arrays

When deleting a dynamically allocated array, we have to use the array version of delete, which is delete[].

This tells the CPU that it needs to clean up multiple variables instead of a single variable. One of the most common mistakes that new programmers make when dealing with dynamic memory allocation is to use delete instead of delete[] when deleting a dynamically allocated array. Using the scalar version of delete on an array will result in undefined behavior, such as data corruption, memory leaks, crashes, or other problems.

One often asked question of array delete[] is, “How does array delete know how much memory to delete?” The answer is that array new[] keeps track of how much memory was allocated to a variable, so that array delete[] can delete the proper amount. Unfortunately, this size/length isn’t accessible to the programmer.

Every allocation using new needs to be eventually released using an equal and opposite de-allocation via delete, note the usage of delete[] when you allocate a block using new[]:

  Type* Pointer = new Type[numElements]; // allocate a block
  delete[] Pointer; // release block allocated above

Failure to de-allocate larger blocks of memory result in more server memory leaks. These rapidly reduce the amount of system memory available for applications to consume and has higher potential to make the execution of your application slower.

  #include <iostream>
  using namespace std;

  int main()
  {
    try
    {
      int* pointsToManyNums = new int [0x1fffffff]; //Large request
      // Use the allocated memory
      delete[] pointsToManyNums;
    }
    catch (bad_alloc)
    {
      cout << "Memory allocation failed. Ending program" << endl;
    }
    return 0;
  }

It is up to you — the programmer — to ensure that all allocated memory is also released by your application.

Unlike a fixed array, where the size must be fixed at compile time, dynamically allocating an array allows us to choose array length at runtime:

  #include <iostream>
  #include <cstddef> // std::size_t

  int main()
  {
      std::cout << "Enter a positive integer: ";
      std::size_t length{};
      std::cin >> length;

      int *array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!

      std::cout << "I just allocated an array of integers of length " << length << '\n';

      array[0] = 5; // set element 0 to value 5

      delete[] array; // use array delete to deallocate array

      // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway

      return 0;
  }

Because we are allocating an array, C++ knows that it should use the array version of new instead of the scalar version of new. Essentially, the new[] operator is called, even though the [] isn’t placed next to the new keyword.

The length of dynamically allocated arrays has to be a type that’s convertible to std::size_t. We could use int, but that would cause a compiler warning when the compiler is configured with a high warning level. We have the choice between using std::size_t as the type of length, or declaring length as an int and then casting it when we create the array like so:

  int length{};
  std::cin >> length;
  int *array{ new int[static_cast<std::size_t>(length)]{} };

Note that because this memory is allocated from a different place than the memory used for fixed arrays, the size of the array can be quite large. You can run the program above and allocate an array of length 1,000,000 (or probably even 100,000,000) without issue. Try it! Because of this, programs that need to allocate a lot of memory in C++ typically do so dynamically.



### Dynamic arrays are almost identical to fixed arrays

A fixed array holds the memory address of the first array element. You also learned that a fixed array can decay into a pointer that points to the first element of the array. In this decayed form, the length of the fixed array is not available (and therefore neither is the size of the array via sizeof()), but otherwise there is little difference.

A dynamic array starts its life as a pointer that points to the first element of the array. Consequently, it has the same limitations in that it doesn’t know its length or size. A dynamic array functions identically to a decayed fixed array, with the exception that the programmer is responsible for deallocating the dynamic array via the delete[] keyword.

Initializing dynamically allocated arrays

If you want to initialize a dynamically allocated array to 0, the syntax is quite simple:

  int *array{ new int[length]{} };

Prior to C++11, there was no easy way to initialize a dynamic array to a non-zero value (initializer lists only worked for fixed arrays). This means you had to loop through the array and assign element values explicitly.

  int *array = new int[5];
  array[0] = 9;
  array[1] = 7;
  array[2] = 5;
  array[3] = 3;
  array[4] = 1;

Super annoying!

However, starting with C++11, it’s now possible to initialize dynamic arrays using initializer lists!

  int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array before C++11
  int *array{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11
  // To prevent writing the type twice, long type names, we can use auto.
  auto *array{ new int[5]{ 9, 7, 5, 3, 1 } };

Note that this syntax has no operator= between the array length and the initializer list.

For consistency, fixed arrays can also be initialized using uniform initialization:

1
2

int fixedArray[]{ 9, 7, 5, 3, 1 }; // initialize a fixed array in C++11
char fixedArray[]{ "Hello, world!" }; // initialize a fixed array in C++11

Explicitly stating the size of the array is optional. Doing so can help catching errors early, because the compiler will warn you when the specified length is less than the actual length.

As of the time of writing, the GCC still has a bug where initializing a dynamically allocated array of chars using a C-style string literal causes a compiler error:

1

char *array = new char[14] { "Hello, world!" }; // doesn't work in GCC, though it should

If you have a need to do this on GCC, dynamically allocate a std::string instead (or allocate your char array and then copy the string in).

Resizing arrays

Dynamically allocating an array allows you to set the array length at the time of allocation. However, C++ does not provide a built-in way to resize an array that has already been allocated. It is possible to work around this limitation by dynamically allocating a new array, copying the elements over, and deleting the old array. However, this is error prone, especially when the element type is a class (which have special rules governing how they are created).

Consequently, we recommend avoiding doing this yourself.

Fortunately, if you need this capability, C++ provides a resizable array as part of the standard library called std::vector. We’ll introduce std::vector shortly.

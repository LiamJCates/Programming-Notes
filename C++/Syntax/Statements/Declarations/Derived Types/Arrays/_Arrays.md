## Array

The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.

Arrays enable you to store data elements of identical type in the memory, in a sequential and ordered fashion, meaning that each element has a position in the array called it's index, and these positions are sequential in memory.

Declaration Syntax:

  dataType arrayName[intExp];

in which intExp specifies the number of components in the array and can be any constant expression that evaluates to a positive integer.

Consider the following statement:

  int list[10];

This statement declares an array, list, of 10 components:

  list[0], list[1], . . ., list[9].

In other words, we have declared 10 variables.

Such arrays are called static arrays because the number of elements they contain as well as the memory the array consumes is fixed at the time of compilation by intExp. Static arrays cannot take more data than what the programmer has specified. It also does not consume any less memory if left half-used or unused.

You can define the length of an array as a constant:

  const int ARRAY_LENGTH = 5;
  int myNumbers [ARRAY_LENGTH];

This is particularly useful when you need to access and use the length of the array at multiple places. If the length needed to change, instead of having to change the length in multiple places, you just correct the initialization value at the const int declaration.



## Initialization

Syntax:
  ElementType ArrayName [constant_number] = {optional initial values};

You can initialize array contents on a per-element basis:

  int myNumbers [5] = {34, 56, -21, 5002, 365}

To declare five distinct and unique integer variables and use them to store by declaring an array of five integers each initialized to zero:

  int myNumbers [5] = {};

Or partially initialize elements:

  int myNumbers [5] = {34, 56};

During partial initialization, the remaining elements may be default initialized depending on the type of the array.

You can opt to leave out the number of elements in an array if you initialize it with all necessary values:

  int myNumbers [] = {2016, 2052, -525}; // array of 3 elements

Good practice dictates a value should be assigned to each array elements before it is used.



## Array Access

Elements in an array can be accessed using the subscript operator and a zero-based index.

In other words, the index of the first array element is 0 and the last element is (Length of Array – 1). 0 and length-1 are known as the bounds of the array as they bound the valid index values.

The general form (syntax) used for accessing an array component is:

  arrayName[indexExp]

in which indexExp, called the index, is any expression whose value is a nonnegative integer.

The index value specifies the position of the component in the array to which we desire access.

When asked to access element at index N, the compiler uses the memory address of the first element (positioned at index zero) as the starting point and then skips N elements by adding the offset computed as N * sizeof(element) to reach the address containing the (N+1)th element.

The C++ compiler does not check if the index is within the actual defined bounds of the array. You can try fetching the element at index 1001 in an array of only 10 elements, putting the security and stability of your program at risk. The onus of ensuring that the array is not accessed beyond its bounds lies solely on the programmer. Accessing an array beyond its bounds results in unpredictable behavior. The program tries to access the component specified by the index, whatever memory location is indicated is accessed. This situation can result in altering or accessing the data of a memory location that you never intended to modify or access, or it may be an attempt to access protected memory that causes the program to crash. Accessing arrays beyond their bounds should be avoided at all costs.



### Array Memory Format

The base address of an array is the address (that is, the memory location) of the first array component.

The base address of the array myList is the address of the component myList[0].

Suppose that the base address of the array myList is 1000. Then, the address of the component myList[0] is 1000. Typically, the memory allocated for an int variable is four bytes.

main memory is an ordered sequence of cells, and each cell has a unique address. Typically, each cell is one byte. Therefore, to store a value into myList[0], starting at the address 1000, the next four bytes are allocated for myList[0]. It follows that the starting address of myList[1] is 1004, the starting address of myList[2] is 1008, and so on

Suppose myList is the name of an array. There is also a memory space associated with the identifier myList, and the base address of the array is stored in that memory space.

You might be wondering why the base address of an array is so important. The reason is that when you declare an array, the only things about the array that the computer remembers are the name of the array, its base address, the data type of each component, and (possibly) the number of components. Using the base address of the array, the index of an array component, and the size of each component in bytes, the computer calculates the address of a particular component.



## Library
The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great feature, but by restricting its copy and the fact that they easily decay into pointers, they probably suffer from an excess of optimization.

To overcome some of these issues, C++ provides an alternative array type as a standard container:
[C++\Utilities\STL\Containers\Sequence\array.md]



## Dynamic
To program an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. So called dynamic arrays optimize memory consumption and scale depending on the demand for resources and memory at execution-time.

C++ provides dynamic arrays in the form of std::vector:
[C++\Utilities\STL\Containers\Sequence\vector.md]

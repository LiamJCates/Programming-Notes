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
ElementType ArrayName [constant_number of elements] = {optional initial values};

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



## sizeof an array
Use the sizeof operator to obtain the total size in bytes of an array.

In general, the amount of memory reserved by the compiler for an array:
Bytes consumed by an array = sizeof(element-type) * Number of Elements

You can use a simple trick to determine the number of elements in an array: divide the size of the array by the size of a single constituent element:

short array[] = { 104, 105, 32, 98, 105, 108, 108, 0 };
size_t n_elements = sizeof(array) / sizeof(short);

On most systems, sizeof(array) will evaluate to 16 bytes and sizeof(short) will evaluate to 2 bytes. Regardless of the size of a short, n_elements will always initialize to 8 because the factor will cancel. This evaluation happens at compile time, so there is no runtime cost in evaluating the length of an array in this way.

The sizeof(x)/sizeof(y) construction is a bit of a hack, but it’s widely used in older code.



## Restrictions on Arrays
Consider the following statements:
  int myList[5] = {0, 4, 8, 12, 16};
  int yourList[5];

Note that these arrays are of the same type and have the same number of components. Suppose that you want to copy the elements of myList into the corresponding elements of yourList.

The following statement is illegal:

  yourList = myList; //illegal

In fact, this statement will generate a syntax error.

C++ does not allow aggregate operations on an array. An aggregate operation on an array is any operation that manipulates the entire array as a single unit.

To copy one array into another array, you must copy it component-wise—that is, one component at a time. For example, the following statements copy myList into yourList.

  yourList[0] = myList[0];
  yourList[1] = myList[1];
  yourList[2] = myList[2];
  yourList[3] = myList[3];
  yourList[4] = myList[4];

This can be accomplished more efficiently using a loop, such as the following:

  for (int index = 0; index < 5; index++)
    yourList[index] = myList[index];

Next, suppose that you want to read data into the array yourList. The following statement is illegal and, in fact, would generate a syntax error:

  cin >> yourList; //illegal

To read data into yourList, you must read one component at a time, using a loop such as the following:

  for (int index = 0; index < 5; index++)
    cin >> yourList[index];

Similarly, determining whether two arrays have the same elements and printing the contents of an array must be done component-wise. Note that the following statements are legal in the sense that they do not generate a syntax error; however, they do not give the desired results as they deal with the array's base address.

  cout << yourList;
  if (myList <= yourList)


The base address of an array is the address (that is, the memory location) of the first array component.

The base address of the array myList is the address of the component myList[0].

Suppose that the base address of the array myList is 1000. Then, the address of the component myList[0] is 1000. Typically, the memory allocated for an int variable is four bytes.

main memory is an ordered sequence of cells, and each cell has a unique address. Typically, each cell is one byte. Therefore, to store a value into myList[0], starting at the address 1000, the next four bytes are allocated for myList[0]. It follows that the starting address of myList[1] is 1004, the starting address of myList[2] is 1008, and so on

Suppose myList is the name of an array. There is also a memory space associated with the identifier myList, and the base address of the array is stored in that memory space. Consider the following statement:

  cout << myList << endl; //Line 2

Earlier, we said that this statement will not give the desired result. That is, this statement will not output the values of the components of myList. In fact, the statement outputs the value stored in myList, which is the base address of the array. This is why the statement will not generate a syntax error.

Suppose that you also have the following statement:

  int yourList[5];

Then, in the statement:

  if (myList <= yourList) //Line 3

the expression myList <= yourList evaluates to true if the base address of the array myList is less than the base address of the array yourList; and evaluates to false otherwise. It does not determine whether the elements of myList are less than or equal to the corresponding elements of yourList.

You might be wondering why the base address of an array is so important. The reason is that when you declare an array, the only things about the array that the computer remembers are the name of the array, its base address, the data type of each component, and (possibly) the number of components. Using the base address of the array, the index of an array component, and the size of each component in bytes, the computer calculates the address of a particular component.



### As Parameters

By reference only: In C++, arrays are passed by reference only.

Because arrays are passed by reference only, you do not use the symbol & when declaring an array as a formal parameter.
When declaring a one-dimensional array as a formal parameter, the size of the array is usually omitted. If you specify the size of a one-dimensional array when it is declared as a formal parameter, the size is ignored by the compiler.

Consider the following function:

  void funcArrayAsParam(int listOne[], double listTwo[])
  {
    ...
  }

To write a function to process such arrays, in addition to declaring an array as a formal parameter, we declare another formal parameter specifying the number of elements in the array, as in the following function:

  void initialize(int list[], int listSize)
  {
    for (int count = 0; count < listSize; count++)
      list[count] = 0;
  }

The first parameter of the function initialize is an int array of any size. When the function initialize is called, the size of the actual array is passed as the second parameter of the function initialize.

If C++ allowed arrays to be passed by value, the computer would have to allocate memory for the components of the formal parameter and copy the contents of the actual array into the corresponding formal parameter when the function is called. If the array size was large, this process would waste memory as well as the computer time needed for copying the data. That is why in C++ arrays are always passed by reference.

functions also return the address of an array rather than copy each member back to the caller


As C++ implicitly converts parameters using the array syntax ([]) to the pointer syntax (*). That means the following two function declarations are identical:

  void printSize(int array[]);
  void printSize(int *array);

Some programmers prefer using the [] syntax because it makes it clear that the function is expecting an array, not just a pointer to a value. However, in most cases, because the pointer doesn’t know how large the array is, you’ll need to pass in the array size as a separate parameter anyway (strings being an exception because they’re null terminated).

We lightly recommend using the pointer syntax, because it makes it clear that the parameter is being treated as a pointer, not a fixed array, and that certain operations, such as sizeof(), will operate as if the parameter is a pointer.

Recommendation: Favor the pointer syntax (*) over the array syntax ([]) for array function parameters.


## Library
The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great feature, but by restricting its copy and easily decay into pointers, they probably suffer from an excess of optimization. To overcome some of these issues with language built-in arrays, C++ provides an alternative array type as a standard container:
[C++\Utilities\STL\Containers\Sequence\array.md]


## Dynamic
To program an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. So called dynamic arrays optimize memory consumption and scale depending on the demand for resources and memory at execution-time. C++ provides you with convenient and easy-to-use dynamic arrays in the form of std::vector:
[C++\Utilities\STL\Containers\Sequence\vector.md]

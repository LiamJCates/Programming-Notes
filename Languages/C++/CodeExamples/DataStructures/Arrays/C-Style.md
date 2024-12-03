Static Array
Since this array was introduced in C, it is also known as a C-style array.

Here is how these arrays are declared:
• A static array is declared as
    int arr[size];.
• A dynamic array in C is declared as
    int* arr = (int*)malloc(size * sizeof(int));.
• A dynamic array is declared in C++ as
    int* arr = new int[size];




Limitations of C-style Arrays
Though C-style arrays do the job, they are not commonly used.

There are a number of limitations that indicate the necessity of better solutions. Some of the major limitations among those are as follows:

• Memory allocation and deallocation have to be handled manually. A failure to deallocate can cause a memory leak, which is when a memory address becomes inaccessible.

• The operator[] function does not check whether the argument is larger than the size of an array. This may lead to segmentation faults or memory corruption if used incorrectly.

• The syntax for nested arrays gets very complicated and leads to unreadable code.

• Deep copying is not available as a default function. It has to be implemented manually.

To avoid these issues, C++ provides a very thin wrapper over a C-style array called std::array

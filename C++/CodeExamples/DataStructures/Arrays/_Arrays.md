Array
Arrays are the most basic data structures used to store information. An array is a data structure used to store multiple data elements of the same data type. All the data is stored sequentially. The value stored at any index can be accessed in constant time.

The two main types of arrays are static and dynamic.

Basic arrays are static, and can store a fixed number of elements, whereas a collection stores object dynamically so there is no size restrictions it grows and shrinks automatically.

A static array has a lifetime only inside its declaration block, but a dynamic array provides better flexibility since the programmer can determine when it should be allocated and when it should be deallocated.

A static array is aggregated, which means that it is allocated on the stack, and hence
gets deallocated when the flow goes out of the function. On the other hand, a dynamic
array is allocated on a heap and stays there until the memory is freed manually.

We can choose either of them depending on the requirement. Both have the same performance for different operations.

Since all the array elements are present next to each other, when one of the elements is accessed, a few elements next to it are also brought into the cache. Hence, if you want to access those elements, it is a very fast operation as the data is already present in the cache. This property is also known as cache locality. Although it doesn't affect the asymptotic time complexity of any operations, while traversing an array, it can give an impressive advantage for contiguous data in practice. Since traversing requires going through all the elements sequentially, after fetching the first element, the next few elements can be retrieved directly from the cache. Hence, the array is said to have good cache locality.



Array ADT Operations
Below is the API of array:
1. Adds an element at kth position
    Value can be stored in array at Kth position in O(1) constant time. We just need to store value at arr[k].
2. Reading the value stored at kth position.
    Accessing value stored a some location in array is also O(1) constant time.
    We just need to read value stored at arr[k].

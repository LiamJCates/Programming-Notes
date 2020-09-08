ArrayList

An ArrayList uses a dynamic array as the underlying storage for the implementation of a list.

The array supports many of the qualities of a list, allowing us to linearly store, an ordered non-unique collection. However, standard arrays are not dynamic in size, so the ArrayList implementation must provide this functionality

Resizing arrays
When using an array to represent some collection type, array resizing is an approach to accommodating arbitrary growth and shrinkage in a data structure that is an attractive alternative to linked lists.

The idea is to modify the array based collection implementation to dynamically adjust the length of the array so that it is sufficiently large to hold all elements in the collection, but not so large as to waste an excessive amount of memory.

Achieving these goals turns out to be remarkably easy using a [dynamically sized array](https://github.com/LiamJCates/Programming-Notes/blob/master/Data%20Structures/Array/Array.md#dynamic-array)

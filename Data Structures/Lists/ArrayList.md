ArrayList

An ArrayList uses a dynamic array as the underlying storage for the implementation of a list.

The array supports many of the qualities of a list, allowing us to linearly store, an ordered non-unique collection. However, standard arrays are not dynamic in size, so the ArrayList implementation must provide this functionality

Resizing arrays
When using an array to represent some collection type, array resizing is an approach to accommodating arbitrary growth and shrinkage in a data structure that is an attractive alternative to linked lists.

The idea is to modify the array based collection implementation to dynamically adjust the length of the array so that it is sufficiently large to hold all elements in the collection, but not so large as to waste an excessive amount of memory.

Achieving these goals turns out to be remarkably easy

Add/Insert
When performing any add/insert we
First determine whether the collection's underlying array is too small by checking whether the collection size is equal to the array's length.

If not, we simply insert the new element by incrementing the collections size and placing the element to be inserted at that index

If so, we double the length of the array by
  creating a new array of twice the length,
  copying over each element to the new array,
  setting the list instance variable to reference the new array.

Remove/Delete
When performing any remove/delete, we
First determine whether the collection's underlying array is too large by checking whether the collection size is less than one-fourth the array length.

If so, we halve its length by
  creating a new array of a quarter the length,
  copying over each element to the new array,
  setting the list instance variable to reference the new array.

We then perform the removal.

In this way, after the array is halved, it will be about half full and can accommodate a substantial number of operations before having to change the length again.

A hash table is a data structure that maps keys to values for highly efficient lookup


Quick lookups are often really important. This is a common reason, to use arrays (O(1)-time lookups) over linked lists (O(n)-time lookups), for example.

In fact, many implementations of hash tables are use arrays as an underlying data structure. Hash tables are also known as associative arrays.

We can think of an array as a table with two columns:
	indexes:	sequential numbers starting at 0, {0, 1, 2, ...}
	elements:	values of a given type

In a standard array we don't get to pick the index values.

Suppose there is an array of size N and all elements to be stored in the array are represented by some key value, these key values are unique and also are in the range 0 to N-1. We can then store all the elements in the array based on the key where array index and keys are same.

In this case, we can access a given element in a constant time without the need for a linear search of O(n) comparisons. When we intend to search the array for a given element of key value x. We can access the desired value by using the key value as an index.

	int element = array[x];

This is called direct addressing:  
We store the key at the same address as the value of the key.
For a given key value, we must have an array large enough to have a corresponding address. For a collection of keys that have large differences between their key values much of the array is empty.

In the above example the key is required to be an integer from 0 to N-1 such that we can use the key to access the element at a given index.

What if we wanted to use any value as a key and still get quick lookups?
This is a process known as hashing.

In hashing, the address of the key is determined by using a mathematical function known as a hash function. The hash function will operate on a key of a given type to produce an integer between 0 and N-1 which is determined to be the address of the key in an N sized array.

The output of the hash function can be adjusted to produce integer values within some range. This is in contrast to the method of direct addressing, discussed above, which may result in a wide distribution of the keys throughout the memory, and hence lead to more wastage of space when compared with hashing.

By applying a hash function to the key value, a hash table provides constant time lookup similar to an array. The difference is, instead of accessing elements via sequential integers, the elements of an associative array are accessed using arbitrary data types such as strings, dates, or even user defined classes, processed via some hash function, to produce the array index where data is to be stored.

This data structure, which is implemented with an array and indexes values using a hashing function is known as an associative array, a hash map, a hash table, and sometimes simply a hash.

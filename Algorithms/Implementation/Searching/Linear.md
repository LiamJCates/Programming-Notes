## Sequential / Linear Search
When objects are not sorted in any particular order. To seek whether a given query object is inside the array or not, we simply browse the array sequentially until we find the object, or we report that it has not been found inside the array.

The execution time of a linear search is O(n), where n is the number of elements in the array. The algorithm is called a linear search because its complexity can be expressed as a linear function, which is that the number of comparisons to find the target item increases linearly with the size of the data.

The best case of a linear search is when the data element to be searched for is equal to the first element of the array. Obviously, the worst case will happen when the data element to be searched for is equal to the last element in the array.

Complexity of sequential search
Best      O(1)    Front of the list, first comparison
Average   O(n)    average number of comparisons n/2
Worst     O(n)    No match, scan entire array

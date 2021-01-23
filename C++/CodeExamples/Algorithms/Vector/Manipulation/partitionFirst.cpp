/*
Partition Array
Problem

Given an unsorted array A of length L, partition the array around the first
item, A[0].



Example:
given A:[4,3,7,1,5,2,6], we partition around its first item A[0] = 4.

The resulting array A’ will be partitioned such that all items with values less than the pivot value, in this case 4, will be put on its left and all other items greater than or equal to the pivot value, will be put on its right.

Solution A’:[3,1,2,4,5,7,6]

To partition the array A[start ... end] around the pivot value, in this case the first item in the array, pivot = A[start], our method of choice will be a inplace swapping of array elements that uses a loop to iterate through array members.

We will use two indices, i and j to identify elements to be swapped at each interation.

	i = start + 1;		i is the left-most index past the pivot
	j = end;					j is right-most index of the pivot subarray.

These indecies mark the boundaries of an unpartitioned area of the array. During loop iteration, these boundaries will be advanced through incrementing i and decrementing j
i will be incremented until it either passes j or an element that in not less than the pivot is found.
j will be decremented until an element that is less than the pivot is found

maintaining the invarient that elements of indexes lower than i are less than the pivot and elements of indexes higher than j are greater than or equal to the pivot.


Each loop iteration
	while i is less than j and the value A[i] is smaller than the pivot value.
		increment i
	while the value A[pivot] is less than A[j]
		decrement j
	if i is greater than j the boundary indecies have crossed each other
		break out of the loop
	else we have
		swap A[i] and A[j]


The last swap will place the pivot value at its final desired position.
	swap the pivot value, A[0] and A[j].

*/


/*
Performs a swap of array members

Takes
	pointer to the array holding elements to be swapped
	two integers indicating the indexes to swap.

Returns
	nothing, the swap happens in place.
*/
void Swap(int* values, const size_t i, const size_t j) {
	int tmp = values[i];
	values[i] = values[j];
	values[j] = tmp;
}

/*
Performs an array partition in place

Takes
	a pointer to the array to be partitioned,
	the index at which to start the partition
	the index at which to end the partition.

Returns
	nothing as it partitions the array in place.
*/
void Partition(int* values, const int start, const int end) {
// ASSERT(values != nullptr && s < e);
	const auto pivot = start;
	const auto target = values[pivot];
	int i = start + 1;
	int j = end;

	while (i < j)
	{
		while (i < j && values[i] < target)
			++i;
		while (target < values[j])
			--j;

		if (i > j) break;

		Swap(values, i, j);
	}
	Swap(values, j, pivot);
}







/*
Variation 1: now partition the array around the last item, A[L - 1].

*/


void Partition(int* values, const int start, const int end) {
// ASSERT(values != nullptr && s < e);
	const auto pivot = end;
	const auto target = values[pivot];
	int i = start;
	int j = end - 1;

	while (i < j)
	{
		while (i < j && values[i] < target)
			++i;
		while (target < values[j])
			--j;

		if (i > j) break;

		Swap(values, i, j);
	}
	
	Swap(values, j, pivot);
}

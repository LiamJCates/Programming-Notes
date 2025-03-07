MergeSort
Merge sort is a sorting method which follows the divide and conquer
approach. The divide and conquer approach is a very good approach in
which divide means partitioning the array having n elements into two subarrays of n/2 elements each. However, if there are no elements present
in the list/array or if an array contains only one element, then it is already
sorted. However, if an array has more elements, then it is divided into two
sub-arrays containing equal elements in them. Conquer is the process of
sorting the two sub-arrays recursively using merge sort. Finally, the two
sub-arrays are merged into one single sorted array.

Conceptually, a merge sort works as follows:
Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.


Merge Sort Technique
1. If the array has zero or one element in it, then there is no need to sort
that array as it is already sorted.
2. Otherwise, if there are more elements in the array, then divide the array
into two sub-arrays containing equal elements.
3. Each sub-array is now sorted recursively using merge sort.
4. Finally, the two sub-arrays are merged into a single sorted array

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)




Complexity of Merge Sort
The running time of the merge sort algorithm is O(n log n). This runtime remains the same in the average as well as in the worst case of the
merge sort algorithm. Although it has an optimal time complexity, sometimes this runtime can be O(n).

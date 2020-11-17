Different Searching Algorithms
· Linear Search – Unsorted Input
· Linear Search – Sorted Input
· Binary Search (Sorted Input)
· String Search: Tries, Suffix Trees, Ternary Search.
· Hashing and Symbol Tables










How sorting is useful in Selection Algorithm?
Selection problems can be converted to sorting problems. Once the array is
sorted, it is easy to find the minimum/maximum (or desired element) from the
sorted array. The method ‘Sorting and then Selecting’ is inefficient for selecting
a single element, but it is efficient when many selections need to be made from
the array. It is because only one initial expensive sort is needed, followed by
many cheap selection operations.
For example, if we want to get the maximum element from an array. After
sorting the array, we can simply return the last element from the array. What if
we want to get second maximum. Now, we do not have to sort the array again
and we can return the second last element from the sorted array. Similarly, we
can return the kth maximum element by just one scan of the sorted list.
So with the above discussion, sorting is used to improve the performance. In
general this method requires O(nlogn) (for sorting) time. With the initial sorting,
we can answer any query in one scan, O(n).

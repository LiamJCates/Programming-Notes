Insertion Sort

Specification:
Problem Solved: Sort collection members
Input: A sequence of N element {e1, e2, ..., en}
Output: An ordered permutation of the input such that e'1 ≤ e'2 ≤ ... ≤ e'n


Sorts one element at a time, comparing already-sorted elements to each subsequent element and inserting the new element into the correct location, similar to the way you sort a hand of playing cards.

To limit the wastage of memory or, we can say,
to save memory, most implementations of an insertion sort work by moving
the current element past the already sorted elements and repeatedly swapping or interchanging it with the preceding element until it is placed in its
correct position.


procedure insertionSort( list : collection of items )
   int holePosition
   int valueToInsert

   for i = 1 to list.length inclusive do:

      /* select value to be inserted */
      valueToInsert = list[i]
      holePosition = i

      /*locate hole position for the element to be inserted */

      while holePosition > 0 and list[holePosition-1] > valueToInsert do:
         list[holePosition] = list[holePosition-1]
         --holePosition
      end while

      /* insert the number at hole position */
      list[holePosition] = valueToInsert

   end for

end procedure



Insertion Sort Loop Invariant:
For each iteration of insertion sort, elements A[1... i-1] are  the elements originally in positions 1 through i-1, but now in sorted order.

For randomly ordered arrays of length N with distinct keys, insertion sort uses ~N^2/4 compares and ~N^2/4 exchanges on the average.
The worst case, a collection of reverse sort order, is ~ N^2/2 compares and ~ N^2/2 exchanges
The best case, a presorted collection, is N-1 compares and 0 exchanges.

Time Complexity Θ(n2)
Space Complexity Θ(1)

Unlike selection sort, the best-case running time for insertion sort is O(n), which occurs when the list is already sorted. This means insertion sort is an efficient way to add new elements to a presorted list. The average and worst cases are both O(n2), however, so it’s not the best algorithm to use for large amounts of randomly ordered data. Insertion sort is a stable, in-place sorting algorithm especially suitable for sorting small data sets and is often used as a building block for other, more complicated sorting algorithms.

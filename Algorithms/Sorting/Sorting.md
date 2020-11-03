Sorting

Sorting refers to the act of modifying the data in a structure to impose some order between the elements.
A sorting algorithm specifies the way to arrange data elements in a particular order.

The importance of sorting lies in most common uses of sorted sequences:
making lookup or search efficient;
making merging of sequences efficient.
enable processing of data in a defined order.

Most common orders are numerical or lexicographical (alphabetical) order.

Sorting algorithms are useful for two reasons.
To order data for presentation to the user in a more readable format
Examples: Phone directory, Dictionary

To simplify and optimize other algorithms


In theoretical computer science, we furthermore analyze lower bounds, which are time complexity bounds that can not be beaten by any algorithm. It is known that sorting requires of the order of n log n time (comparison operations) whatever the method/algorithm. denoted as follows: Ω(n log n).


Choosing the right sorting algorithm can have a huge impact on application performance.
If you are wondering which sorting algorithm is the best, there is no clear answer.
Each algorithm has advantages in certain contexts.
Even the lowly bubble sort can be optimal in some cases; for example, a nearly sorted list will be sorted quickly by a bubble sort with minimal memory overhead.
What’s right for one application isn’t necessarily right for a different application.

Here are some criteria to consider when selecting a sorting algorithm:

➤ How much data is to be sorted?
For large data sets, the worst-case bounds matter.
For Small data sets, algorithm simplicity matters.
Select an algorithm that performs acceptably on the largest data sets your code may encounter.

➤ Does the data fit in memory?
Most sorting algorithms are efficient only when the data they operate on resides in memory.
If the data set is too large for memory, you may need to split it into smaller chunks for sorting and then combine those sorted chunks to create the final sorted data set.

➤ Is the data already mostly sorted?
Adding new data to a sorted list can be done efficiently with certain algorithms, but those same algorithms have poor performance on randomly ordered data.

➤ How much additional memory does the algorithm require?
An in-place sorting algorithm sorts the data without using any additional memory, such as by swapping elements in an array. When memory is at a premium, an in-place algorithm may be a better choice than one with otherwise superior efficiency.

➤ Is relative order preserved?
A stable sorting algorithm preserves the relative order of data elements that are otherwise identical for sorting purposes. (In other words, if elements A and B have identical key values and A precedes B in the original data set, A will still precede B after a stable sorting.)
Stability is generally a desirable feature, but in many cases it may be worth sacrificing stability for improved performance.
Important Terms
Item:    
Key:    Complex types are sorted by one attribute, such a component or property is called a sort key.

Shuffling: The opposite of sorting, rearranging a sequence of items in a random or meaningless order

The best case of any sorting algorithm, occurs if the array is already sorted

Increasing Order        A value sequence is in increasing order, if elementi+1 > elementi
cannot contain duplicates

Decreasing Order        A value sequence is in decreasing order, if elementi+1 < elementi
cannot contain duplicates

Non-Increasing Order        A value sequence is in non-increasing order, if elementi+1 ≤ elementi
can contain duplicates

Non-Decreasing Order        A value sequence is in non-decreasing order, if elementi+1 ≥ elementi
can contain duplicates


In-place Sorting
Sorting algorithms that do not require any extra space, sorting is said to happen in-place, or for example, within the array itself. This is called in-place sorting.
Bubble sort is an example of in-place sorting.

However, in some sorting algorithms, the program requires space which is more than or equal to the elements being sorted. Sorting which uses equal or more space is called not-in-place sorting.
Merge-sort is an example of not-in-place sorting.


Stable Sorting
Stability of a sorting algorithm matters when we wish to maintain the sequence of original elements

If a sorting algorithm, after sorting the contents, does not change the sequence in which equal keys appear, it is called stable sorting.


If a sorting algorithm changes the sequence in which equal keys appear, it is called unstable sorting.



Adaptive Sorting Algorithm
A sorting algorithm is said to be adaptive if it takes advantage of already 'sorted' elements
That is, while sorting, if the source list has some element already sorted, adaptive algorithms will take this into account and will try not to re-order them.

A non-adaptive algorithm is one which does not take into account the elements which are already sorted. They try to force every single element to be re-ordered to confirm their sortedness.


Common Sorting algorithms
Bubble/Shell sort : Exchange two adjacent elements if they are out of order. Repeat until array is sorted.
Insertion sort : Scan successive elements for an out-of-order item, then insert the item in the proper place.
Selection sort : Find the smallest (or biggest) element in the array, and put it in the proper place. Swap it with the value in the first position. Repeat until array is sorted.
Quick sort : Partition the array into two segments. In the first segment, all elements are less than or equal to the pivot value. In the second segment, all elements are greater than or equal to the pivot value. Finally, sort the two segments recursively.
Merge sort : Divide the list of elements in two parts, sort the two parts individually and then merge it.
Bucket sort
Radix sort



Observations
Select
Iterates over a collection selecting the nth lowest item and swapping it with the item at the nth spot
Bubble
Adjacent pairs are compared and swapped if they are in the wrong order. Can be efficient for very small and nearly sorted lists. Easy to implement. Almost never used.
Insert
Iterates over a list, removing elements and inserting them into their sorted location in another list. Faster than quick sort for very small arrays.
Merge
Repeatedly divides the list into sub-lists until each list contains just one item, then repeatedly merges the lists to produce a single (sorted) list. Fast. Very commonly used.
Quick
Repeatedly divides the list into two sub-lists based on a pivot value until all lists contain a single value (or no values). Sorted sub-lists are concatenated around their pivot values to eventually form the complete, sorted list. Fast. Very commonly used.
Heap
Creates a heap data structure from the list, then repeatedly extracts the largest value into an array until all values are removed from the heap. The heap speeds searches while constructing the sorted array
Bucket


Radix









Quicksort
Mergesort
Timsort
Heapsort
Bubble Sort
Insertion Sort
Selection Sort
Tree Sort
Shell Sort
Bucket Sort
Radix Sort
Counting Sort
Cubesort



Primitive Operations

Given an unsorted array of elements, consider the task of sorting all its elements to get a sorted array in, say, increasing order.

Formally, the only two primitive operations considered for sorting arrays are:
– comparisons
– element swapping (exchanges)

For example, these basic operations are implemented as follows for integers:

static boolean GreaterThan(int a, int b) {return (a>b);}

static void swap (int[] array, int i, int j) {
    int tmp=array[i];
    array[i]=array[j];
    array[j]=tmp;
}



Bubble Sort

procedure bubbleSort( list : collection of items )

   n = list.length;

   do:
      /* initial swapped state is false*/
      swapped = false

      for i = 0 to n do:

         /* compare adjacent elements, if this pair is out of order */   
         if list[j] > list[j+1] then
            /* then swap them and change swapped state */
            swap( list[j], list[j+1] )        
            swapped = true
         end if

      end for
   /*optimized by observing that the n-th pass finds the n-th largest element
   and puts it into its final place. So, the inner loop can avoid looking at the
   last n − 1 items when running for the n-th time*/      
   n = n - 1

   /*if no number was swapped that means
   array is sorted now, end the loop.*/
   while(swapped)

end procedure return list



Further Optimization
More generally, it can happen that more than one element is placed in their final position on a single pass. In particular, after every pass, all elements after the last swap are sorted, and do not need to be checked again. This allows to skip over many elements, resulting in about a worst case 50% improvement in comparison count (though no improvement in swap counts), and adds very little complexity because the new code subsumes the "swapped" variable

procedure bubbleSort( list : collection of items )

   n = list.length;

   do:
      newn = 0

      for i = 1 to n do:
          if list[ i-1 ] > list[i] then
            swap( list[i-1], list[ i ] )        
            newn = i
         end if
      end for

   n = newn
   while( n ≤ 1)

end procedure return list




Bubble sort is asymptotically equivalent in running time to insertion sort in the worst case, but the two algorithms differ greatly in the number of swaps necessary. Experimental results such as those of Astrachan have also shown that insertion sort performs considerably better even on random lists. For these reasons many modern algorithm textbooks avoid using the bubble sort algorithm in favor of insertion sort.

Bubble sort also interacts poorly with modern CPU hardware. It produces at least twice as many writes as insertion sort, twice as many cache misses, and asymptotically more branch mispredictions. Experiments by Astrachan sorting strings in Java show bubble sort to be roughly one-fifth as fast as an insertion sort and 70% as fast as a selection sort.


Properties

Worst Case Complexity:        O(n2) array is reverse ordered
Average Case Complexity:    O(n2)
Best Case Complexity:         O(n)  array is ordered
Auxiliary Space:         O(1)
Sorting In Place:         Yes
Stable:                 Yes
Selection Sort

The selection sort is composed of three general operations that proceed as follows:
SELECTION:    seek the smallest array key
SWAP:        swap smallest key with first array element
ITERATE:     repeat with remaining sub-array:
At iteration i, use sub-array [ i , ..., n-1 ]
At iteration i+1, use sub-array [ i+1 , ..., n-1 ]

To program the selection sort, we use two nested loops:
Inner loop    SELECTs and SWAPs the smallest element of the current array,
Outer loop    Iterates on the remaining unsorted subarray

procedure selectionSort( list : collection of items )
int min, n = list.length

for i = 0 to n-1 do:        /* find the min element in the unsorted list[i .. n-1] */

    min = i;             /* assume the min is the first element */

    for j = i+1 to n do:        /* compare elements after i to find smallest */
        if (list[j] < list[min])        /* if this element is less, then */
            min = j;            /* found new minimum; remember its index */
        end if
    end for

    if min != i then        /* if a new min has been found, then */
        swap list[min] and list[i]    /* swap them */
    end if

end for
end procedure return list



Properties:
    Not stable    due to swapping
    In-place    
O(n2)        quadratic complexity

Complexity

Selection sort uses ~(n^2)/2 compares and n-1 exchanges to sort an array of length n.

Advantages:
Selection sort requires at most n – 1 exchanges. In situations in which moving data elements is more expensive than comparing them, selection sort may perform better than other polynomial time sort algorithms.
Insertion Sort
Sorts one element at a time, comparing already-sorted elements to each subsequent element and inserting the new element into the correct location, similar to the way you sort a hand of playing cards.

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
Quick Sort

divide and conquer is used as each problem instance is composed of similar subproblems with no overlap

Quicksort is a divide and conquer algorithm. It first divides the input array into two smaller sub-arrays: the low elements and the high elements. It then recursively sorts the sub-arrays. The steps for in-place Quicksort are:
Pick an element, called a pivot, from the array.
Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
The base case of the recursion is arrays of size zero or one, which are in order by definition, so they never need to be sorted.



Quick Sort Pseudocode

procedure quickSort(A, left, right)        //given an Array A, and the left and right index

   if right-left > 0                    // ensure we are not dealing with the basecase
      partition = partitionFunc(A, left, right)    // partition array A and acquire pivot index
      quickSort(A, left, partition)            // quicksort left partition recursively
      quickSort(A, partition+1, right)        // quicksort right partition recursively
   end if        

end procedure

Quick Sort Pivot Pseudocode

function partitionFunc(A, left, right)        // Given an array A and left/right sides of the array

    pivot = A[ ⌊ (right + left) / 2 ) ⌋ ]        
    // Select the pivot as the middle element, rounded down
    low = left - 1
    // get a pointer to the lowest index on the left, adjusting for the do while loop
    high = right + 1
    // get a pointer to the highest index on the right, adjusting for the while loop

    while True do
        do:
            low++
        while A[low] < pivot        
        //increment the low pointer until an element greater than or equal to the pivot is found

        do:
             high--    
        while A[high] > pivot
        // decrement the high pointer until an element less than or equal to the pivot is found

        if low ≥ high then
            return high
        // If the indices have met or passed then return the final index as the pivot

        else
            swap A[low] with A[high]
        //else swap the inverted elements so that they are on the correct side of the future pivot
    end while
end function

Complexity analysis of QuickSort
– The worst-case running time is quadratic: O(N^2),
– The expected running time is O(NlogN),
– The best case is linear O(n). (all elements identical)
MergeSort

Conceptually, a merge sort works as follows:
Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

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

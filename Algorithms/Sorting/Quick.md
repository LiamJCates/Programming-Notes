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

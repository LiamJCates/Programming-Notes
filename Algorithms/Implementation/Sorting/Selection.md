Selection Sort
Selection sort works by finding the smallest unsorted element in the array and swapping it with the element in the next position to be filled.

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

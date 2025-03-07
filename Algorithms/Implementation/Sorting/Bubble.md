Bubble Sort
Bubble sort, also known as exchange sort, is a very simple sorting method. It works by repeatedly moving the largest element to the highest position
of the array. In bubble sort, we are comparing two elements at a time, and
swapping is done if they are wrongly placed. If the element at a lower index
or position is greater than the element at a higher index, then in that case
both the elements are interchanged so that the smaller element is placed
before the bigger one. This process is repeated until the list becomes sorted.
Bubble sort gets its name from the way that the smaller elements “bubble” to
the top of the array. This sorting technique only uses comparisons to operate
on the elements. Hence, we can also call it a comparison sort.


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

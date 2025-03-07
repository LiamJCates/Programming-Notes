Merge Sort

Merge Sort

Divide        n-element sequence into two subsequences of n/2 elements each.
Conquer     Sort the two subsequences recursively using merge sort.
Combine    Merge the two sorted subsequences to produce the sorted answer

Our MERGE procedure takes time 𝜽(n), where n = r - p + 1 is the total number of elements being merged

if we call MERGE-SORT on n elements when n is odd, we end up with subproblems of size
⌊n/2⌋ and ⌈n/2⌉

In practice, we neglect certain technical details when we state and solve recurrences including omission of floors, ceilings, and boundary conditions.

The recurrence describing the worst-case running time of MERGE-SORT is really

T(n) = 𝜽(1)                       for n = 1
       T(⌊n/2⌋) + T(⌈n/2⌉) + 𝜽(n)   for n > 1

The worst-case running time T(n) of the MERGE-SORT procedure by the recurrence
T(n) = 𝜽(1)                       for n = 1
       2T(n/2) + 𝜽(n)             for n > 1

Solution to: T(n) = 𝜽(n log n)

You've been given an array that is sorted and then rotated.

Now how best can one search in this sorted + rotated array?

One can unrotate the array and then do a binary search. But that is no better than doing a linear search in the input array, as both are worst-case O(N).

[https://leetcode.com/problems/search-in-rotated-sorted-array/]

In a traditional binary search:
[Algorithms\Searching\Binary.md]

This can be done in O(logN) using a slightly modified binary search.

The interesting property of a sorted + rotated array is that when you divide it into two halves, results in three cases where at least one of the two halves will always be sorted.

Suppose we are given
a search value, E
a linear collection that is sorted in ascending order and rotated, array

let
  array[l..h] be a search interval
    where
    n is the array length
    l is the lowest index, l = 0
    h is the highest index, h = n - 1
    m is the middle index, m = l + (h - l) / 2
  p be an unknown rotation pivot for which the following element is lesser

Depending on the location of pivot, we can divide problem instances into three cases

Case 1:
The pivot is in the right half and the left half is sorted

  Suppose array = [4,5,6,7,8,9,1,2,3]
                   ^       ^ ^     ^
                   l       m p     h
  n = 9,
  l = 0, such that array[l] = 4
  h = n-1, such that array[h] = 3
  m = l + (h - l) / 2, such that array[m] = 8
  p = 5, such that array[p] = 9


Case 2:
The pivot is in the left half and the right half is sorted

  Suppose array = [7,8,9,1,2,3,4,5,6]
                   ^   ^   ^       ^
                   l   p   m       h
  n = 9,
  l = 0, such that array[l] = 7
  h = n-1, such that array[h] = 6
  m = l + (h - l) / 2, such that array[m] = 2
  p = 2, such that array[p] = 9


Case 3:
The pivot is equal to m or h and both left and right sub-arrays are sorted.

  Suppose array = [5,6,7,8,9,1,2,3,4]
                   ^       ^       ^
                   l       m       h
  n = 9,
  l = 0, such that array[l] = 5
  h = n-1, such that array[h] = 4
  m = l + (h - l) / 2, such that array[m] = 9
  p = m, such that array[p] = 9

  Suppose array = [1,2,3,4,5,6,7,8,9]
                   ^       ^       ^
                   l       m       h
  n = 9,
  l = 0, such that array[l] = 1
  h = n-1, such that array[h] = 9
  m = l + (h - l) / 2, such that array[m] = 5
  p = h, such that array[p] = 9



We let the division point of the two haves be m
giving array[l..m] and array[m..h].

By comparing start and end element of each half we can determine which half is sorted:
  if array[l] <= array[m] then the left half is sorted
  if array[m] <= array[h] then the right half is sorted

When we determine which half is sorted, we can check that half for the key and iterate on either half with the same logic that standard binary search uses.

if the left half is sorted   
  if array[l] <= E && array[m] >= E
  then the search value is present in the left half
    we iterate on the left half by updating h = m - 1
  else the key must be in the right half
    we iterate on the right half by updating l = m + 1

else the right half is sorted
  if array[m] <= E && array[h] >= E
  then the key is present in the right half
    we iterate on the right half by updating l = mid + 1
  else the key must be in the left half
    we iterate on the left half by updating h = m - 1


As with standard binary search, we terminate our iteration/recursion when
  we have found the search element:
    array[m] == E, thus we return m

  the base case is hit:
    l > h, thus we return -1


Pseudo code:

function search(array[], E, l, h)

  //perform base case check
  if(l > h)
    // E not present
    return -1

  m = l + (h - l) / 2

  //check for solution
  if(array[m] == E)
    // E found
    return m

  // check the if left half is sorted.
  if(array[l] <= array[m])

    // if E is present in left half.
    if (array[l] <= E && array[m] >= E)
      //search the left half
      return search(array,E,l,m-1)

    // otherwise E is present in right half
    else
      //search right half
      return search(array,E,m+1,h)
    end-if

  // otherwise the right half is sorted.
  else    
    // if E is present in right half.
    if(array[m] <= E && array[h] >= E)
      //search right half
      return search(array,E,m+1,h)

    // otherwise E is present in left half
    else
      //search in left half
      return search(array,E,l,m-1)
    end-if
  end-if  
end-function





Complexity
The key here is that one sub-array will always be sorted,
using this information, we can determine if the search value is within the range of the sorted portion. Once we determine if the value is within this range we may rely on the standard binary search logic to iterate/recurs discarding the other half of the array


As we are discarding one half of the array in each iteration this algorithm is O(logN)

The maximum-subarray problem
In the maximum subarray problem we want to find a sequence of days over which the net change from the first day to the last is maximum.

A brute-force solution to the maximum-subarray problem tries every possible pair of buy and sell dates in which the buy date precedes the sell date. A period of n days has n^2  such pairs of dates. Since (n/2) is θ(n^2), and the best we can hope for is to evaluate each pair of dates in constant time, this approach would take Ω(n^2) time.

Write pseudocode for the brute-force method of solving the maximum-subarray problem. Your procedure should run in Θ(n2) time.

FIND-MAX-SUBARRAY(A, low, high)
  left = right = 0
  sum = -∞
  for i = low to high
      current_sum = 0
      for j = i to high
      current_sum += A[j]
      if sum < current_sum
          sum = current_sum
      left = i
      right = j
  return (left, right, sum)

should run in Θ(n2) time.


Instead of looking at the daily prices, instead consider the daily change in price, where the change on day i is the difference between the prices after day i-1 and after day i. Then find the nonempty, contiguous subarray of A whose values have the largest sum. We call this contiguous subarray the maximum subarray.

we will usually speak of “a” maximum subarray rather than “the” maximum subarray, since there could be more than one subarray that achieves the maximum sum.

A solution to maximum subarray using divide-and-conquer
    divide subarray A[low..high] at mid point, equal as possible
    A[low..mid] A[mid+1..high]

any contiguous subarray must occur in one of three cases:
  entirely in the subarray A[low..mid] so that low ≤  i ≤ j ≤ mid,
  entirely in the subarray A[mid+1..high], so that mid < i ≤ j ≤ high,
  crossing the midpoint, so that low ≤ i ≤ mid < j ≤ high.

In fact, a maximum subarray of A[low..high] must have the greatest
sum over all subarrays entirely in A[low..mid], entirely in A[mid+1..high], or crossing the midpoint.

We can find maximum subarrays of A[low..mid] and A[mid+1..high] recursively, because these two subproblems are smaller instances of the problem of finding a maximum subarray.

Once we find the maximum subarrays of A[low..mid] and A[mid+1..high] recursively we then find the maximum subarray that crosses the midpoint, and
return the subarray with the largest sum of the three

We can easily find a maximum subarray crossing the midpoint in time linear in the size of the subarray  A[low..high].

Finding a maximum subarray crossing the midpoint is not a smaller instance of our original problem, because it has the added restriction
the subarray it chooses must cross the midpoint.

Any subarray of A[low..high] crossing the midpoint comprises two subarrays A[i..mid] and A[mid+1..j], where low ≤  i ≤ mid and mid < j ≤ high.

midpoint max subarray is comprised of the maximum subarrays of the form A[i..mid] and A[mid+1..j], where low ≤  i ≤ mid and mid < j ≤ high then combine them.

FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
  left-sum = -∞
  sum = 0

  for i = mid to low
    sum = sum + A[i]

    if sum > left_sum
      left_sum = sum
      max_left = i

  right_sum = -∞
  sum = 0

  for j = mid+1 to high
    sum = sum + A[j]

    if sum > right-sum
      right-sum = sum
      max-right = j

return (max-left, max-right, left-sum + right-sum)

Lines 1–7 find a maximum subarray of the left half, A[low..mid].
1: left-sum holds the greatest sum found so far
2: sum holds the sum of the entries in A[imid]
3-7: subarray must contain A[mid], for loop starts index i at mid down to low
    5: When we find subarray A[i..mid] with  a sum of values greater than left-sum,
6: we update left-sum to this subarray’s sum
7: we update the variable max-left to record this index i.

Lines 8–14 work analogously find a maximum subarray of right half, A[mid+1..high].
    8: right-sum holds the greatest sum found so far
9: sum holds the sum of the entries in A[mid+1..high]
10-14: subarray must contain A[mid+1], for loop starts index i at mid+1 down to high
    12: When we find subarray A[mid+1..high] with a sum of values greater than right-sum,
13: we update left-sum to this subarray’s sum
14: we update the variable max-left to record this index i.


Finally, line 15 returns
the indices max-left and max-right that demarcate a maximum subarray crossing the midpoint,
along with the sum left_sum+right_sum of the values in the subarray A[max-left..max-right]

If the subarray A[low..high] contains n entries (so that n = high - low + 1), FIND-MAX-CROSSING-SUBARRAY (A; low; mid; high) takes
θ(n) time


Each iteration of FIND-MAX-CROSSING-SUBARRAY for loops takes θ(1) time, we just need to
count up how many iterations there are altogether.

FIND-MAX-CROSSING-SUBARRAY for loop lines 3–7 makes how many iterations?
(mid -low + 1) iterations

FIND-MAX-CROSSING-SUBARRAY for loop lines 10–14 makes how many iterations?
(high - mid iterations)

IN total FIND-MAX-CROSSING-SUBARRAY for loops make how many iterations?
(mid-low+1) + (high - mid) = ( high - low + 1) = n



FIND-MAXIMUM-SUBARRAY(A, low, high)
if high == low
  return(low, high, A[low])

else
  mid = ⌊(low+high)/2⌋
  (left-low, left-high, left-sum) =  FIND-MAXIMUM-SUBARRAY(A, low, mid)
  (right-low, right-high, right-sum) =  FIND-MAXIMUM-SUBARRAY(A, mid+1, high)
  (cross-low, cross-high, cross-sum) =  FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)

  if left-sum ≥ right-sum and left-sum ≥ cross-sum
    return (left-low, left-high, left-sum)
  elseif right-sum ≥ left-sum and right-sum ≥ cross-sum
    return (right-low, right-high, right-sum)
  else
    return (cross-low, cross-high, cross-sum)

The initial call FIND-MAXIMUM-SUBARRAY(A, 1, A.length) will find a maximum subarray of
A[1..n]

The recursive procedure FIND-MAXIMUM-SUBARRAY returns a tuple containing the indices that demarcate a maximum subarray, along with the sum of the values in a maximum subarray

In the FIND-MAXIMUM-SUBARRAY base case the subarray has just one element.

A subarray with just one element has only one subarray so FIND-MAXIMUM-SUBARRAY returns a tuple with the starting and ending indices of just the one element, along with its value.

Because we know that the subarray A[low..high] contains at least two elements, each of the left and right subarrays must have at least one element.

Lines 3–11 handle the recursive case.
Line 3 does the divide part, computing the index mid of the midpoint.
Lines 4 and 5 conquer by recursively finding maximum subarrays within the left and right subarrays, respectively.
Lines 6–11 form the combine part.
Line 6 finds a maximum subarray that crosses the midpoint.
Line 7 tests whether the left subarray contains a subarray with the maximum sum
line 8 returns that maximum subarray.
Otherwise, line 9 tests whether the right subarray contains a subarray with the maximum sum, line 10 returns that maximum subarray.
If neither the left nor right subarrays contain a subarray achieving the maximum sum, then a maximum subarray must cross the midpoint, and line 11 returns it.

Analyzing the divide-and-conquer algorithm

We denote by T(n) the running time of FIND-MAXIMUM-SUBARRAY on a subarray of n elements.
line 1 and 2 take constant time. base case, n = 1 T(1) = θ(1)

The recursive case occurs when n > 1.
Lines 1 and 3 take constant time.
lines 4 and 5 operate on a subarray of n/2 elements and so we spend T(n/2) time solving each Line 6 call to FIND-MAX-CROSSING-SUBARRAY takes θ(n) time.
Lines 7–11 take only θ(1) time.

T(n) = Θ(1) + 2T(n/2) + Θ(n) + Θ(1)
     = 2T(n/2) + Θ(n)

recurrence
T(n) = Θ(1)             if n = 1
     = 2T(n/2) + Θ(n)   if n > 1

has the solution
T(n) = Θ(n lg n)

What does FIND-MAXIMUM-SUBARRAY return when all elements of A are negative?

It will return a single-element array with the largest negative integer.

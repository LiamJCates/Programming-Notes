## Bisection / Binary Search
Binary search, also called bisection search, is a search algorithm that finds the position of a target value within a sorted linear collection.

A binary search is an extremely efficient searching algorithm when compared to a linear search.

However, required preconditions are:
  The collection must be sorted or ordered
  The binary search algorithm must expect the ordering the sort uses

Binary search compares the target value to the middle element of a linear collection.
If a match is found, then the position of that element is returned
otherwise, the value is either less than or greater than that of the middle element, thus the either the upper or lower half, respectively is eliminated as that is the half in which the target cannot lie is, and the search iterates on the remaining half.

This repeated until the target value is found or the remaining half is empty, indicating the target is not in the array.

Binary search
input:        sorted array of elements
output:        element index or -1 if DNE

The bisection search proceeds as follows:
given a sorted linear collection, array, and a search value, E.

Start with a search interval of size n,
  where [low, high] is initialized with low = 0 and high = n − 1

where n denote the array length.
Let m denote the index of the middle element of this range: m = low + (high - low)/2.

Then execute the following recursive steps:
  If array[m] = E
    then we are done, and we return the index position m,
  If array[m] < E,
    then the solution exists within range [m + 1,high],
  If array[m]>E,
    then the solution exists within range [low,m + 1].

The search algorithm terminates, returning -1 to signal that the search element is not in the collection, whenever low >= high.




### Iterative Solution

int BinarySearch(int[] searchArray, int searchValue)
{
  int low = 0;
  int high = searchArray.length - 1;
  int guess, mid;

  while (high > low)
  {
    mid = low + (high - low)/2;
    guess = searchArray[mid];

    if (guess == searchValue)
    {
      return mid;
    }
    else if (guess > searchValue)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}



### Recursive Solution

int RecursiveBinarySearch(int[] searchArray, int searchValue, int low, int high)
{
  if(high > low){
    return -1;
  }

  int mid = low + (high - low)/2;
  int guess = searchArray[mid];

  if (guess == searchValue)
  {
    return mid;
  }
  else if (guess > searchValue)
  {
    return RecursiveBinarySearch(searchArray, searchValue, low, mid-1);
  }
  else
  {
    return RecursiveBinarySearch(searchArray, searchValue, mid+1, high);
  }
}

int RecursiveBinarySearch(int[] searchArray, int searchValue)
{
  return RecursiveBinarySearch(searchArray, searchValue, 0, searchArry.length-1);
}







Complexity
binary or bisection search is a fast method for searching whether a query element is inside a sorted array or not by successively halving the index range. The number of steps required to answer an element membership is thus proportional to O(log n) and is said to have logarithmic complexity.

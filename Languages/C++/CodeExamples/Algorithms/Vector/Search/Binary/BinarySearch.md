Binary search is sued to search in a sorted array. Each iteration search space is divided into half.

int BinarySearch(std::vector<int> &arr, int value)
{
  int size = arr.size();
  int mid;
  int low = 0;
  int high = size - 1;
  while (low <= high)
  {
    mid = low + (high - low) / 2; // To avoid the overflow
    if (arr[mid] == value)
    {
    return mid;
    }
    else
    {
    if (arr[mid] < value)
      low = mid + 1;
    else
      high = mid - 1;
    }
  }
  return -1;
}

Analysis:
Since we have data sorted in increasing / decreasing order, we can apply more efficient binary search. At each step, we reduce our search space by half.
· Each iteration compares the upper and lower most array search index values to ensure we are in a valid search space.
· We find the middle value: mid = low + (high - low) / 2
· Then compare the middle value with the search value:
  if equal we return the middle index.
  otherwise:
  · If the value is smaller than the middle value, we search the left half of the array: arr[low, mid -1]
  · If the value is grater then the middle value then we search the right half of the array: arr [mid+1, high]

· Loop termination indicates our value was not in the array -1 is returned.





Recursive BinarySearch

bool BinarySearchRecursive(std::vector<int> &data, int low, int high, int value) {
  if (low > high)
    return false;

  int mid = low + (high - low) / 2; // To avoid the overflow

  if (data[mid] == value)
    return true;
  else if (data[mid] < value)
    return BinarySearchRecursive(data, mid + 1, high, value);
  else
    return BinarySearchRecursive(data, low, mid - 1, value);

}
Time Complexity: O(logn). Space Complexity: O(logn) For system stack in
recursion

Analysis: Similar iterative solution we had already seen.
Now let us look into the recursive solution of the same problem in this solution also, we are diving the search space into half and doing the same what we had done in the iterative solution.

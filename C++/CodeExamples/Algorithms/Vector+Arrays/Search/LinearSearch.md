Linear Search – Unsorted Input
When elements of an array are not ordered or sorted and we want to search for a particular value, we need to scan the full array unless we find the desired value.

This kind of algorithm known as unordered linear search. The major problem with this algorithm is less performance or high Time Complexity in worst case.

bool linearSearchUnsorted(std::vector<int> &data, int value)
{
  int size = data.size();
  for (int i = 0; i < size; i++)
    if (value == data[i])
      return true;

  return false;
}
Time Complexity: O(n). As we need to traverse the complete array in worst
case. Worst case is when your desired element is at the last position of the array.
Here, ‘n’ is the size of the array.
Space Complexity: O(1). No extra memory is used to allocate the array.



int SequentialSearch(std::vector<int> &arr, int value)
{
  int size = arr.size();
  for (int i = 0; i < size; i++)
    if (value == arr[i])
      return i;

  return -1;
}

int main()
{
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "Location of element value 7: " << SequentialSearch(arr, 7) << std::endl;
  std::cout << "Location of element value 17: " << SequentialSearch(arr, 17) << std::endl;
}

Output
Location of element value 7: 6
Location of element value 17: -1

Analysis:
· Since we have no idea about the data stored in the array, or if the data is not sorted then we have to search the array in sequential manner one by one.
· If we find the value, we are looking for we return that index.
· Else, we return -1 index, as we did not found the value we are looking for.
In the above example, the data are not sorted. If the data is sorted, a binary search may be done. We examine the middle position at each step. Depending upon the data that we are searching is greater or smaller than the middle value.
We will search either the left or the right portion of the array. At each step, we are eliminating half of the search space there by making this algorithm very efficient the linear search.







Linear Search – Sorted
If elements of the array are sorted either in increasing order or in decreasing
order, searching for a desired element will be much more efficient than
unordered linear search. In many cases, we do not need to traverse the complete
array. Following example explains when you encounter a greater element from
the increasing sorted array, you stop searching further. This is how this algorithm
saves the time and improves the performance.
Example 5.2
bool linearSearchSorted(std::vector<int> &data, int value)
{
int size = data.size();
for (int i = 0; i < size; i++)
{
if (value == data[i])
{
return true;
}e
lse if (value < data[i])
{
return false;
}
}re
turn false;
} T
ime Complexity: O(n). As we need to traverse the complete array in worst
case. Worst case is when your desired element is at the last position of the sorted
array. However, in the average case this algorithm is more efficient even though
the growth rate is same as unsorted.
Space Complexity: O(1). No extra memory is used to allocate the array.

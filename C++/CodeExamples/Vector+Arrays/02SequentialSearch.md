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

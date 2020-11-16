Sum Array
Write a method that will return the sum of all the elements of the integer array given array and its size as an argument.

int SumArray(std::vector<int> &arr)
{
  int size = arr.size();
  int total = 0, index = 0;

  for (index = 0; index < size; index++)
    total = total + arr[index];
  return total;
}

int main()
{
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "sum of all the values in array:" << SumArray(arr) << std::endl;
}

Output:
sum of all values in array: 45

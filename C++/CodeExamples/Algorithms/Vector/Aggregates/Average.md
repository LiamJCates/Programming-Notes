Find average of all the elements in an array

int SumArray(std::vector<int> &arr)
{
  int total = 0
  for(int i : arr)
    total += i;

  return total / arr.size();
}

int main()
{
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "average of all the values in array:" << SumArray(arr) << std::endl;
}

Output:
Average of all values in array: 5

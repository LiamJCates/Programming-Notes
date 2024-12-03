/*
Sum Array
Write a method that will return the sum of all the elements of the integer array given array and its size as an argument.
*/

int SumArray(std::vector<int> &arr)
{
  int size = arr.size();
  int total = 0, index = 0;

  for (index = 0; index < size; index++)
    total = total + arr[index];
  return total;
}

int get_sum(std::vector <int> &arr)
{
  return accumulate(arr.begin(), arr.end(), 0);
}

int Sum2DArray(std::vector<int> &arr) {
  int total = 0;

  for (std::vector<int>  v : arr)
    for(int i : v)
      total += i;
  return total;
}


int main()
{
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "sum of all the values:" << SumArray(arr) << std::endl;
  std::vector<int> arr2D = { {1,2,3}, {4,5,6}, {7,8,9} };
  std::cout << "sum of all the values:" << Sum2DArray(arr2D) << std::endl;
}

/*
Output:
sum of all values: 45
sum of all values: 45
*/



// Generic numeric

template <class T>
T sum(std::vector<T> nums) {
  T sum = 0;

  for(T item : nums)
    sum += item;

  return sum;
}

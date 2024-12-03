/*
Sum the differences between consecutive pairs in the array.

For example:

sumOfDifferences([2, 1, 10])

Returns 9

Descending order: [10, 2, 1]

Sum: (10 - 2) + (2 - 1) = 8 + 1 = 9
*/


#include <vector>


int sumOfDifferences(const std::vector<int>& arr){
  std::vector<int> arr2 = arr;

  int sum = 0;
  for(int i = 0; i < (int)arr2.size() - 1; i++)
    sum += arr2[i] - arr2[i+1];

  return sum;
}


/*
(for a given sequence of numbers, the result value of f will be lastNumber - firstNumber, because all the others in between will get canceled out)
*/

int sumOfDifferences(const std::vector<int>& arr){
  return arr[0] - arr[arr.size()];
}


/*
sum the differences between consecutive pairs in the array in descending order.

collection size >= 2
*/

//sorts the array then finds the sum of difference using the efficient method
#include <algorithm>
#include <functional>

int sumOfSortedDifferences(const std::vector<int> arr){
  sort(arr.begin(), arr.end(), std::greater<>());

  return arr[0] - arr[arr.size()-1];
}

/*
Uses a minmax_element to return a pair with an iterator pointing to the element with the smallest value in the range [first,last) as first element, and the largest as second.
*/

int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  return *p.second - *p.first;
}

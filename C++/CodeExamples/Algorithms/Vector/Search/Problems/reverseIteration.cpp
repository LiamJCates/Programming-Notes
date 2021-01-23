/*
Given an array of digital numbers, return a new array of length number containing the last even numbers from the original array (in the same order). The original array will be not empty and will contain at least "number" even numbers.

For example:

([1, 2, 3, 4, 5, 6, 7, 8, 9], 3) => [4, 6, 8]
([-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26], 2) => [-8, 26]
([6, -25, 3, 7, 5, 5, 7, -3, 23], 1) => [6]


*/

#include <vector>

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  std::vector<int> ans(0);

  if(n == 0)
     return ans;

  auto itr = arr.rbegin();

  while(ans.size() < n)
  {
    if(*itr % 2 == 0)
      ans.insert(ans.begin(), *itr);
    ++itr;
  }

  return ans;
}

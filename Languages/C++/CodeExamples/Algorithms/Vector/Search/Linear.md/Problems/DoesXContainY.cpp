/*
A contains_all method accepts two vectors and returns true if all values within the second vector are present within the first vector.

For each number in the target numbers to search
linearly search the list for that target
*/

#include <vector>

bool contains_all(const std::vector<int>& arr, const std::vector<int>& target) {
  for (auto &num : target)
    if(std::find(arr.begin(), arr.end(), num) == arr.end())  return false;

	return true;
}

int main()
{
	items = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}
	contains_all(items, {1, 2, 3})	//true
	contains_all(items, {1, 5, 13}) //false because 13 is not within the items array
}

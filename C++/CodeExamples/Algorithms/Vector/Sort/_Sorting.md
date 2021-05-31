Sorting Algorithms
Sorting is the process of placing elements from a collection into ascending or
descending order.
Sorting arranges data elements in order so that searching become easier.
There are good sorting functions available which does sorting in O(nlogn) time,
so in this book when we need sorting we will use sort() function and will assume
that the sorting is done in O(nlogn) time.


#include <vector>
#include <algorithm>

std::vector<int> flip(const char dir, std::vector<int> arr) {
  std::sort(arr.begin(), arr.end(), [dir](int a, int b){return dir == 'R' ? a < b : a > b;});
  return arr;
}

std::vector<int> flip(const char dir, std::vector<int> arr) {
    dir == 'R' ?
      sort(arr.begin(),arr.end()):
      sort(arr.rbegin(),arr.rend());
    return arr;
}

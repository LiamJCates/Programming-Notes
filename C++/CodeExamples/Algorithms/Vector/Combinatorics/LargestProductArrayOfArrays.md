#include <limits.h>
using namespace std;

int solve(vector<vector<int>> v){
  int maxProduct = INT_MIN;
  int currentProduct = 1;    
  int n = v.size();
  int next;

  vector<int> indices(n, 0);

  while (1) {
    for (int i = 0; i < n; i++)
      currentProduct *= v[i][indices[i]];

    if(maxProduct < currentProduct)
     maxProduct = currentProduct;
    currentProduct = 1;

    next = n - 1;
    while (next >= 0 &&
          (indices[next] + 1 >= (int)v[next].size()))
      next--;

    if (next < 0)
      return maxProduct;

    indices[next]++;

    for (int i = next + 1; i < n; i++)
      indices[i] = 0;
  }

  return maxProduct;
}

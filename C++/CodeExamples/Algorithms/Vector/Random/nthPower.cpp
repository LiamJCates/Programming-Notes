/*
You are given an array with positive numbers and a non-negative number N. You should find the N-th power of the element in the array with the index N. If N is outside of the array, then return -1. Don't forget that the first element has the index 0.

Let's look at a few examples:

    array = [1, 2, 3, 4] and N = 2, then the result is 3^2 == 9;
    array = [1, 2, 3] and N = 3, but N is outside of the array, so the result is -1.

*/


#include <vector>
#include <cmath> //std::pow

int index(const std::vector<int> &vector, int n) {
  return n >= vector.size() ? -1 : pow(vector[n], n);
}

int index(const std::vector<int> &vector, int n) {

  if (vector.size() <= n)
    return -1;

  int i = 1, p = n;

  while(p--)
    i *= vector.at(n);

  return i;
}

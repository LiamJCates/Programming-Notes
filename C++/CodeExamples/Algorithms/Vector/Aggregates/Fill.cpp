/*

Write a function that produces an array with the numbers 0 to N-1.

For example, the following code will result in an array containing the numbers 0 to 4:

arr(5) // => [0,1,2,3,4]


*/


#include <vector>

//Forward direction
std::vector<int> arr(int n = 0) {
  std::vector<int> vec(n);

  for(int i = 0; i < n; i++)
    vec.push_back(i);

  return vec;
}


std::vector<int> arr(int n = 0) {
  std::vector<int> a(n);
  for(int i=0; i<n; i++){
    a[i] = i;
  }
  return a;
}

//Reverse direction
std::vector<int> arr(int n = 0) {

  std::vector<int> v(n);
  while(n--)
    v.insert(v.begin(), n);

  return v;
}

// std::iota Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value.
#include <numeric>

std::vector<int> arr( int n = 0 ) {
  std::vector<int> r( n );
  std::iota( r.begin(), r.end(), 0 );
  return r;
}




/*
Reverse fill
*/

//Forward direction
std::vector<int> arr(int n = 0) {
  std::vector<int> vec(n);

  while(n > 0)
    vec.push_back(n--);

  return vec;
}

// using std::iota in reverse

std::vector<int> reverseSeq(int n) {
  std::vector<int> r( n );
  std::iota(r.rbegin(), r.rend(), 1);
  return r;
}

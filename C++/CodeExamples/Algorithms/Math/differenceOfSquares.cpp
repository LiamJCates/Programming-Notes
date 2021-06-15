/*
You are to write a function that takes an odd integer which is the difference between two consecutive perfect squares and find the squares

Input Format

num : Odd Integer 0<n<1000000

Output Format

Answer: String containing the bigger and smaller squares in one line like "Max-Min"
Examples

findSquares(9)  //returns '25-16'
findSquares(5)  // returns '9-4'

*/


#include <iostream>
#include <string>

using namespace std;


/*
Naive solution

The niave solution entails generating successive squares and finding their differences
Once the differences match the parameter value we return
*/

string perfectSquaresDifferences(int n)
{
  long i, diff = 0;
  for(i = 0; diff != n; i++ )
  {
    diff = (i+1) * (i+1) - i * i;
  }

  return ((i)*(i)) + "-" + ((i-1)*(i-1));
}


/*
Efficient Solution

The difference between two squares:

d = j*j - i*i

This solution uses the fact that the difference of two square numbers can be determined using

j = (d+1)/2
i = (d-1)/2


*/
string perfectSquaresDifferences(int n)
{
  long i = (n-1)/2;
  long j = i+1;
  return (j*j) + "-" + (i*i);
}

// Driver code
int main()
{
    cout << perfectSquaresDifferences(9) << endl;
}

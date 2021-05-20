/*
Find average of all the elements in an array
*/

#include <vector>
#include <iostream>
#include <numeric> // std::accumulate
using namespace std;

/*
Uses a ranged for loop and divides by the size of the collection
*/
int AverageArray(std::vector<int> &arr)
{
  int total = 0;
  for(int i : arr) total += i;

  return total / arr.size();
}

/*
Uses the function template std::accumulate and two iterator functions to accumulate all values in the range then divides by the size of the collection
*/
int get_average(std::vector<int> &arr)
{
  return accumulate(arr.begin(), arr.end(), 0) / arr.size();
}

void average(std::vector<int> &arr)
{
  int sum{0};
  int count{};

  int x;
  for(int i : arr)
  {
    sum += i;
    count++;
  }

  if (count == 0)
    std::cout << "No data.\n";
  else
    std::cout << "average = " << sum / count << '\n';
}

int main()
{
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
  std::cout << "average of all the values in array:" << AverageArray(arr) << std::endl;
  std::vector<int> v;
  average(v);
  average(arr);
}

/*
Output:
Average of all values in array: 5
*/

// Instructions
/*
  Given a sorted array of distinct integers,
	write a function that returns the lowest index for which
	array[index] == index.

	Return -1 if there is no such index.
  Your algorithm should be very performant.

	[input] array of integers ( with 0-based nonnegative indexing )
  [output] integer

	Examples:
  input: [-8,0,2,5]
  output: 2
	since array[2] == 2

	input: [-1,0,3,6]

	output: -1
	since no index in array satisfies array[index] == index
*/

#include <vector>
#include <iostream>

using namespace std;

int indexEqualsValue(vector<int> a)
{
    int ans = -1;
    for (int start = 0, end = a.size() - 1; start <= end;)
    {
        int mid = (start + end) / 2;

        if (a[mid] == mid)      end = (ans = mid) - 1;
        else if (a[mid] < mid)  start = mid + 1;
        else                    end = mid - 1;
    }

    return ans;
}

int main()
{
    std::vector<int> v = {-5, 1, 2, 3, 4, 5, 7, 10, 15};
    std::cout << indexEqualsValue(v) << std::endl;
}

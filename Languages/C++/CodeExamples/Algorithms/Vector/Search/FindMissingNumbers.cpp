/*
Finding missing numbers:

Cases:
	Finding a single missing number in a sorted array
		Linear Search
		Binary Search

	Finding a single missing number in an unsorted array
		Summation Formula vs Linear Sum
		Running Sum
		XOR

	Finding multiple missing numbers in an unsorted array
		Array of bools tracking found values
*/




/*
Finding a single missing number in a sorted array
*/


/*
Techniques O(n) linear search

Given a sorted array, we can iterate through each member until the current element does not equal the last element + 1
	return last element + 1
*/
int linearSearch(std::vector<int> v)
{
	int last = v[0] - 1;
	for(int i : v)
	{
		if(i != last + 1)
			return i-1;
		else
			last = i;
	}
	return -1;
}




/*

Techniques: O(log n) Binary Search

Given a sorted list of n-1 integers in the range of 1 to n with no duplicates, we must find the integer that is missing from the list.

We can perform a binary search to find the value of the skipped element.

The concept behind this solution is that the elements appearing before the missing element will have ar[i] – i = 1 and those appearing after the missing element will have ar[i] – i = 2

Given:
vec[] = {1, 2, 3, 4, 6, 7, 8, 9}

We can see above that for the vec array indexes 0 - 3, values stored at thoes indexes, vec[i],  are equal to the index plus one. i + 1:

	vec[2] = 3
	i + 1 = 2 + 1 = 3

Using this information, we can implement a binary search that checks array indecies by finding the middle element between a low and high index.

	mid = low + (high - low)/2;

Then uses the value at that index, vec[mid], to determine whether or not an element has been skiped:

	vec[mid] - mid == 1

If these values are equal, then the missing element has yet to occur, if they are not equal, then the skipped element has occured previously. With each test, we remove the half of the array that does not contain the missing element. Eventually we will arrive at the two indecies which would be on either side of the missing element.


      0                    7
ar = {1, 2, 3, 4, 5, 7, 8, 9}
low = 0, high = 7 mid = 0 + (7 - 0) / 2 = 3, ar[3] = 4
ar[3] - mid = 4 - 3 = 1
	low = mid

      3           7
ar = {4, 5, 7, 8, 9}
low = 3, high = 7 mid = 3 + (7 - 3) / 2 = 5, ar[5] = 7
ar[5] - mid = 7 - 5 = 2
	high = mid

      3     5
ar = {4, 5, 7}
low = 3, high = 5, mid = 3 + (5 - 3) / 2 = 4, ar[4] = 5
ar[4] - mid = 5 - 4 = 1
	low = mid

      4  5
ar = {5, 7}
low = 4, high = 5
 high - low = 1
return ar[low] + 1


*/

int binarySearch(std::vector<int> ar)
{
    int low = 0, high = ar.size() - 1, mid;

    while ((high - low) > 1)
    {
        mid = low + (high - low) / 2;

				//if true the skipped element would be in the upper half of the array
				if (ar[mid] - mid == 1)
					low = mid; //the low index is moved to mid

				//else the skipped element would be in the lower half of the array
				else
					high = mid; //the high index is moved down to mid
    }

		//As the low and high index border the missing element,
		//we can return ar[low] + 1 or ar[high] - 1
    return (ar[low] + 1);
}


/*
	Finding a single missing number in an unsorted array
*/


/*
	Summation Formula vs Linear Sum
	Time Complexity O(n) Space Complexity O(1)

	Given an unsorted list of n-1 integers in the range of 1 to n with no duplicates, we must find the integer that is missing from the list.

	For a range [1, n] the sum of all n elements can be calculated using the formula n*(n+1)/2.

	To determine which element is missing from the list, perform a linear summation of the list elements and subtract it from the calculated total, or subtract each list element from the calculated sum. The difference is the answer.
*/

int summationFormula(std::vector<int> a)
{
 	int n = a.size() + 1; // we add one to size to account for the missing element
  int total = ((n) * (n + 1)) / 2;
  for (int i = 0; i < n; i++)
      total -= a[i];
  return total;
}

/*
	For larger lists, we have to make a small adjustment to deal with over flow.

	Rather than find the total sum of the range, we use a running sum which iterates through the list adding the value of the index and subtracting the value at a given index.
*/
int runningSum(std::vector<int> a)
{
 	int n = a.size() + 1; // we add one to size to account for the missing element
  int total = 0;
  for (int i = 1; i <= n; i++)
	{
		total += i;
		total -= a[i-1];
	}
	return total;
}


/*
	Use of XOR to solve this issue

	Algorithm:

    Create two variables a = 0 and b = 0
    Run a loop from 1 to n with i as counter.
    For every index update a as a = a ^ i
    Now traverse the array from start to end.
    For every index update b as b = b ^ array[i]
    Print the missing number as a ^ b.
*/
int xorSearch(std::vector<int> a)
{
    // For xor of all the elements in array
    int x1 = 0;
    // For xor of all the elements from 1 to n+1
    int x2 = 0;

    for (int i = 1, n = a.size() + 1; i <= n; i++)
    {
        x1 ^= a[i - 1];
        x2 ^= i;
    }

    return (x1 ^ x2);
}




/*
	Finding multiple missing numbers in an unsorted array
*/


/*
	Using vector of bools

	vector<bool> behaves like the unspecialized version of vector, however, the library implementation may optimize storage so that each value is stored in a single bit. This means that the space usage will potentially be less than if we had used a hash or another vector.

	Iterates through the int vector, setting the bool vector bit to true at the position dictated by each int, potentially resizing the bool vector to make the number of bits equal to the largest number in the int vector.

	Once the int vector has been interated through, we can iterate through the bool vector adding the indexes that have not been set to true.

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

std::string boolSearch(std::vector<int> a)
{
    std::string missing = "";
    std::vector<bool> b(3);


    for(int i : a)
    {
        if( i+1 > b.size()) b.resize(i+1);
        b[i] = 1;
    }

    for(int i = 1; i < b.size(); i++)
        if(!b[i]) missing += " " + to_string(i);

    return missing.substr(1);
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 27, 28, 29};
    std::cout << boolSearch(v) << std::endl;
}

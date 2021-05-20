The lower_bound and upper_bound algorithms performs a binary search that tries to find a value in a range of sorted values.


std::lower_bound() is an STL library function, which comes under the algorithm header library and finds the lower bound of the searching element in a range. Lower bound means the least element in the range which is greater or equal to the searching element.

Cases:

    When a searching element exists:
    std::lower_bound() returns iterator to the element itself
    When searching element doesn't exist:
        If all elements are greater than the searching element:
        lower_bound() returns an iterator to begin of the range.
        If all elements are lower than the searching element:
        lower_bound() returns an iterator to end of the range( No lower bound exists).
        Otherwise,
        lower_bound() returns an iterator to the next greater element to the search element(The closest element greater than the search element) of the range

To use the lower_bound() the range needs to be sorted.


std::upper_bound() is an STL library function, which comes under the algorithm header library and finds the upper bound of the searching element in a range. Upper bound means the next greater element in the sorted range for the searching element.

Cases:

    When a searching element exists:
    std::upper_bound() returns an iterator to the next greater element of the searching element
    When searching element doesn't exist:
        If all elements are greater than the searching element:
        upper_bound() returns an iterator to begin of the range.
        If all elements are lower than the searching element:
        upper_bound() returns an iterator to end of the range( No upper bound exists).
        Otherwise,
        upper_bound() returns an iterator to the next greater element to the search element (The closest element greater than the search element) of the range.

To use the upper_bound() the range needs to be sorted.

// lower_bound and upper_bound in vector
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
    int gfg[] = { 5, 6, 7, 7, 6, 5, 5, 6 };

    vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6

    sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), 6);
    upper = upper_bound(v.begin(), v.end(), 6);

    cout << "lower_bound for 6 at position "
         << (lower - v.begin() + 1) << '\n';
    cout << "upper_bound for 6 at position "
         << (upper - v.begin() + 1) << '\n';

    return 0;
}

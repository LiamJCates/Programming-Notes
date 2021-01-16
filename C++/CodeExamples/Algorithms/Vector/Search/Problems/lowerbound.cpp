/*
You are given N integers in sorted order. Also, you are given Q queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.

Lower bound is a function that can be used with a sorted vector.


Input Format

The first line of the input contains the number of integers.
The next line contains integers in sorted order.
The next line contains the number of queries.
Then lines follow each containing a single integer

Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Output Format

For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.

If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.

You have to output each query in a new line.

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15

Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, e;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> e;
        v.push_back(e);
    }

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> e;
        auto lower = lower_bound (v.begin(), v.end(), e);
        cout << (binary_search (v.begin(), v.end(), e) ? "Yes " : "No " )
             << to_string( distance(v.begin(), lower) + 1 )
             << '\n';
    }
    return 0;
}

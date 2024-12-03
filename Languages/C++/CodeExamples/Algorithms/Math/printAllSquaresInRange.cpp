/*
Given a range [L, R], the task is to print all the perfect squares from the given range.
Examples:

    Input: L = 2, R = 24
    Output: 4 9 16
    Input: L = 1, R = 100
    Output: 1 4 9 16 25 36 49 64 81 100

*/

/*
Naive Approach

Naive approach: Starting from L to R check whether the current element is a perfect square or not. If yes then print it.
Below is the implementation of the above approach:
*/

#include <cmath>
#include <iostream>

using namespace std;

void perfectSquares(int l, int r)
{
    // For every element from the range
    for (float s; l <= r; l++) {
      //determine the square root of the current value
        s = sqrt(l);
        // check if the sqrt is an integer
        if ( s == (int)s)
            cout << l << " ";
    }
    cout << endl;
}

// Driver code
int main()
{
    int l = 2, r = 24;

    perfectSquares(l, r);
}


/*
This solution with O(n). moreover the use of number of square roots leads to computational expense.
*/

/*
Efficient approach:

This method is based on the fact that the very first perfect square after number L will definitely be the square of ⌈sqrt(L)⌉.

Therefore, the first number in the range [L, R] will be pow(ceil(sqrt(L)), 2).

The very first perfect square is important for this method. Now the original answer is hidden over this pattern i.e. 0 1 4 9 16 25
the difference between 0 and 1 is 1
the difference between 1 and 4 is 3
the difference between 4 and 9 is 5 and so on…

which means that the difference between two perfect squares is an odd number.

Now, the question arises what must be added to get the next number

the answer is (sqrt(X) * 2) + 1 where X is the already known perfect square.

Let the current perfect square be 4
then the next perfect square will definitely be 4 + (sqrt(4) * 2 + 1) = 9.

Here, number 5 is added and the next number to be added will be 7 then 9 and so on… which makes a series of odd numbers.

Addition is computationally less expensive than performing multiplication or finding square roots of every number.
Below is the implementation of the above approach:


*/

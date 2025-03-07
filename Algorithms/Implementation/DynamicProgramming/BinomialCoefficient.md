
1) A binomial coefficientC(n, k) can be defined as the coefficient of X^kin the expansion of (1+ X)^n.

2) A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; more formally, the number of k-element subsets (or k-combinations) of an n-element set.

The Problem
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

1) Optimal Substructure

Thevalue of C(n, k) can recursively calculated using following standard formula for BinomialCofficients.

C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1

2) Overlapping Subproblems

Following is simple recursive implementation that simply followsthe recursive structurementioned above.

```cpp
// A Naive Recursive Implementation
#include <iostream>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
  // Base Cases
  if (k == 0 || k == n)
    return 1;
  // Recur
  return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

/* Drier program to test above function*/
int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    return 0;
}
```


re-computations of the same subproblems can be avoided by constructing a temporary 2D-array C[][] in a bottom-up manner. Following is Dynamic Programming based implementation.
```cpp
// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

// Prototype of a utility function that
// returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Caculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

// A utility function to return
// minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Driver Code
int main()
{
    int n = 5, k = 2;
    cout << "Value of C[" << n << "][" << k << "] is "
         << binomialCoeff(n, k);
}
```
Time Complexity: O(n*k)
Auxiliary Space: O(n*k)



### Space optimized
Following is a space-optimized version of the above code. The following code only uses O(k). Thanks to AK for suggesting this method.

```cpp
// C++ program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
    int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

/* Driver code*/
int main()
{
    int n = 5, k = 2;
    printf("Value of C(%d, %d) is %d ", n, k,
           binomialCoeff(n, k));
    return 0;
}
```


Time Complexity: O(n*k)
Auxiliary Space: O(k)

Explanation:
1==========>> n = 0, C(0,0) = 1
1–1========>> n = 1, C(1,0) = 1, C(1,1) = 1
1–2–1======>> n = 2, C(2,0) = 1, C(2,1) = 2, C(2,2) = 1
1–3–3–1====>> n = 3, C(3,0) = 1, C(3,1) = 3, C(3,2) = 3, C(3,3)=1
1–4–6–4–1==>> n = 4, C(4,0) = 1, C(4,1) = 4, C(4,2) = 6, C(4,3)=4, C(4,4)=1

So here every loop on i, builds i’th row of pascal triangle, using (i-1)th row

At any time, every element of array C will have some value (ZERO or more) and in next iteration, value for those elements comes from previous iteration.

In statement,  C[j] = C[j] + C[j-1]

The right-hand side represents the value coming from the previous iteration (A row of Pascal’s triangle depends on the previous row). The left-Hand side represents the value of the current iteration which will be obtained by this statement.

Let's say we want to calculate C(4, 3),
i.e. n=4, k=3:

All elements of array C of size 4 (k+1) are
initialized to ZERO.

i.e. C[0] = C[1] = C[2] = C[3] = C[4] = 0;
Then C[0] is set to 1

For i = 1:
C[1] = C[1] + C[0] = 0 + 1 = 1 ==>> C(1,1) = 1

For i = 2:
C[2] = C[2] + C[1] = 0 + 1 = 1 ==>> C(2,2) = 1
C[1] = C[1] + C[0] = 1 + 1 = 2 ==>> C(2,1) = 2

For i=3:
C[3] = C[3] + C[2] = 0 + 1 = 1 ==>> C(3,3) = 1
C[2] = C[2] + C[1] = 1 + 2 = 3 ==>> C(3,2) = 3
C[1] = C[1] + C[0] = 2 + 1 = 3 ==>> C(3,1) = 3

For i=4:
C[4] = C[4] + C[3] = 0 + 1 = 1 ==>> C(4,4) = 1
C[3] = C[3] + C[2] = 1 + 3 = 4 ==>> C(4,3) = 4
C[2] = C[2] + C[1] = 3 + 3 = 6 ==>> C(4,2) = 6
C[1] = C[1] + C[0] = 3 + 1 = 4 ==>> C(4,1) = 4

C(4,3) = 4 is would be the answer in our example.


### Memoization Approach:

The idea is to create a lookup table and follow the recursive top-down approach. Before computing any value, we check if it is already in the lookup table. If yes, we return the value. Else we compute the value and store it in the lookup table. Following is the Top-down approach of dynamic programming to finding the value of the Binomial Coefficient.

```cpp
// A Dynamic Programming based solution
// uses table dp[][] to calculate the Binomial Coefficient
// A naive recursive approach with table C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffUtil(int n, int k, int** dp)
{
    // If value in lookup table then return
    if (dp[n][k] != -1) //    
        return dp[n][k];

    // store value in a table before return
    if (k == 0) {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // store value in table before return
    if (k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
               binomialCoeffUtil(n - 1, k, dp);
    return dp[n][k];
}

int binomialCoeff(int n, int k)
{
    int** dp; // make a temporary lookup table
    dp = new int*[n + 1];

    // loop to create table dynamically
    for (int i = 0; i < (n + 1); i++)
        dp[i] = new int[k + 1];

			// nested loop to initialise the table with -1
     for (int i = 0; i < (n + 1) * (k + 1); i++)
             dp[i/(k+1)][i%(k+1)] = -1;

    return binomialCoeffUtil(n, k, dp);
}

/* Driver code*/
int main()
{
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k) << endl;
    return 0;
}
```

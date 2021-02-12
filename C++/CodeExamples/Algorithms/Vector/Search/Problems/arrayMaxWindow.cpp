/*
Given a set of arrays of size N and an integer K, find the maximum integer for each and every contiguous subarray of size K for each of the given arrays.

Input Format

First line of input will contain the number of test cases T.
For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Output Format

For each of the contiguous subarrays of size K of each array, you have to print the maximum integer.

Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Sample Output

4 6 6 4
8 8 8 10

Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
    int max = *std::max_element(arr,arr+k);

    cout<< max<<" ";

    for ( int i=1; i <= n-k; i++)
    {
        if(arr[i+k-1]>max)
            max=arr[i+k-1];

        else if(arr[i-1] != max)
            ;

        else
            max = *std::max_element(&arr[i],&arr[i+k]);

        cout<< max<<" ";
    }

    cout<<endl;
}

int main(){

	int t;
	cin >> t;
	while(t-- > 0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
  	}
  	return 0;
}

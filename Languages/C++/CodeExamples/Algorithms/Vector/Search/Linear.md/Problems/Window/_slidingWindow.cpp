/*
This technique shows how a nested for loop, in some problems, can be converted to a single for loop to reduce the time complexity.

Let’s start with a problem for illustration where we can apply this technique –

Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’
consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/

/*
Brute Force Approach

The outer loop is used to iterate through the first n-k indexes
The inner sums k elements starting from the index provided by the outer loop

We start with first index and sum till k-th element.
We do it for all possible consecutive blocks or groups of k elements.

The time complexity is O(k*n) as it contains two nested loops.
One loop reliant on the input size of the array (n)
One loop reliant on the input size of the window (k)
*/

int maxSum(int arr[], int n, int k)
{
    // Initialize result
    int max_sum = INT_MIN;

    // Consider all blocks starting with i.
    for (int i = 0; i < n - k + 1; i++) {
        int current_sum = 0;
        for (int j = 0; j < k; j++)
            current_sum = current_sum + arr[i + j];

        // Update result if required.
        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

/*
Window Sliding Technique

The technique can be best understood with the window pane, consider a window of length n and the pane which is fixed in it of length k. Consider, initially the pane is at extreme left i.e., at 0 units from the left. Now, co-relate the window with array arr[] of size n and pane with current_sum of size k elements. Now, if we apply force on the window such that it moves a unit distance ahead. The pane will cover next k consecutive elements.
Consider an array arr[] = {5, 2, -1, 0, 3} and value of k = 3 and n = 5
Applying sliding window technique :

    We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable window_sum.
    Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
    To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block .

The below representation will make it clear how the window slides over the array.
This is the initial phase where we have calculated the initial window sum starting from index 0 . At this stage the window sum is 6. Now, we set the maximum_sum as current_window i.e 6.

{5, 2, -1, 0, 3}  < array
|5, 2, -1|        < window  5 + 2 + -1 = 6

Now, we slide our window by a unit index. Therefore, now it discards 5 from the window and adds 0 to the window. Hence, we will get our new window sum by subtracting 5 and then adding 0 to it. So, our window sum now becomes 1. Now, we will compare this window sum with the maximum_sum. As it is smaller we wont the change the maximum_sum.

{5, 2, -1, 0, 3}  < array
   |2, -1, 0|     < window 5 + 2 + -1 = 6 - 5 + 0 = 1

Similarly, now once again we slide our window by a unit index and obtain the new window sum to be 2. Again we check if this current window sum is greater than the maximum_sum till now. Once, again it is smaller so we don’t change the maximum_sum.

{5, 2, -1, 0, 3}  < array
      |-1, 0, 3|  < window 2 + -1 + 0 = 1 - 2 + 3 = 2

Therefore, for the above array our maximum_sum is 6.

*/

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
    // n must be greater
    if (n < k) {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

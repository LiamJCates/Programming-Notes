/*
Reverse an array in-place. (Space Complexity O(1).)

Use two variable, start and end.

Start set to 0 and end set to (n-1).

Increment start and decrement end.

Swap the values stored at arr[start] and arr[end].

Stop when start is equal to or greater than end.
*/
void reverseArray(std::vector<int> &a) {

  for (int start = 0, end = a.size() - 1; start < end;)
  {
    int temp = a[start];
    a[start++] = a[end];
    a[end--] = temp;
  }
}

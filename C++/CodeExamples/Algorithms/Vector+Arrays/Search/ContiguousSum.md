Find the largest sum contiguous subarray.

Given an array of positive and negative integer s, find a contiguous subarray whose sum (sum of elements) is maximized.

int maxSubArraySum(std::vector<int> &a)
{
  int size = a.size();
  int maxSoFar = 0, maxEndingHere = 0;
  for (int i = 0; i < size; i++) {
    maxEndingHere = maxEndingHere + a[i];
    if (maxEndingHere < 0)
      maxEndingHere = 0;
    if (maxSoFar < maxEndingHere)
      maxSoFar = maxEndingHere;
  }
  return maxSoFar;
}

int main() {
  std::vector<int> arr = { 1,-2,3,4,-4,6,-14,8,2 };
  std::cout << "Max sub array sum :" << maxSubArraySum(arr);
}

Analysis:
· Maximum subarray in an array is found in a single scan. We keep track of global maximum sum so far and the maximum sum, which includes the current element.
· When we find global maximum value so far is less than the maximum
value containing current value we update the global maximum value.
· Finally return the global maximum value.

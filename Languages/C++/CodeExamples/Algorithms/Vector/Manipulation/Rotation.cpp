/*
Rotating an Array by K positions.

For example, an array [10,20,30,40,50,60] rotate by 2 positions to
[30,40,50,60,10,20]
*/

void reverseArray(std::vector<int> &a, int start, int end)
{
  for (int i = start, j = end; i < j; i++, j--){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  }
}

void rotateArray(std::vector<int> &arr, int k)
{
  int n = arr.size();
  reverseArray(arr, 0, k - 1);
  reverseArray(arr, k, n - 1);
  reverseArray(arr, 0, n - 1);
}

/*
1,2,3,4,5,6,7,8,9,10 => 5,6,7,8,9,10,1,2,3,4
1,2,3,4,5,6,7,8,9,10 => 4,3,2,1,10,9,8,7,6,5 => 5,6,7,8,9,10,1,2,3,4

Analysis:
· Rotating array is done in two parts trick.
  In the first part, we first reverse elements of array first half and then second half.
· Then we reverse the whole array there by completing the whole rotation.
*/

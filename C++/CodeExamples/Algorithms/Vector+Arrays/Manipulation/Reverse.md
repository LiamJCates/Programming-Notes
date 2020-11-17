void reverseArray(std::vector<int> &a, int start, int end)
{
  for (int i = start, j = end; i < j; i++, j--){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  }
}

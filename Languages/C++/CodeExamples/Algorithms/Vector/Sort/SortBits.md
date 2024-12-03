Given an array with value 0 or 1, write a program to segregate 0 on the left side and 1 on the right side

std::vector sortBits(std::vector<int> arr){
  int n = arr.size();
  std::vector<int> ans(n, 1);
  int i = 0;
  for(int j : arr)
    if(j == 0)
      ans[i++] = 0;

  return ans;
}

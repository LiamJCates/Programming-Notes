All permutations of an integer array

void permutation(std::vector<int> &data, int i, int length)
{
  if (length == i) {
    printArray(data, length);
    return;
  }
  int j = i;
  for (j = i; j < length; j++) {
    swap(data, i, j);
    permutation(data, i + 1, length);
    swap(data, i, j);
  }
  return;
}

void swap(std::vector<int> &data, int x, int y) {
  int temp = data[x];
  data[x] = data[y];
  data[y] = temp;
  return;
}

void printArray(std::vector<int> &data, int count) {
  std::cout << "Values stored are : ";
  for (int i = 0; i < count; i++)
    std::cout << " " << data[i];
}

void main() {
  std::vector<int> data(5);
  for (int i = 0; i < 5; i++)
    data[i] = i;

  permutation(data, 0, 5);
}

Analysis:
In permutation method at each recursive call number at index, “i” is swapped with all the numbers that are right of it. Since the number is swapped with all the numbers in its right one by one it will produce all the permutation possible.

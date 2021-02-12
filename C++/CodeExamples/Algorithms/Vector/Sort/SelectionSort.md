void selectionSort(int list[], int length)
{
  int index;
  int smallestIndex;
  int location;
  int temp;
  for (index = 0; index < length - 1; index++) {

    smallestIndex = index;
    for (location = index + 1; location < length; location++)
      if (list[location] < list[smallestIndex])
        smallestIndex = location;

    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
  }
}

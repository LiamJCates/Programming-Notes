The Tower of Hanoi (also called the Tower of Brahma)

We are given three rods and N number of disks, initially all disks are on the first rod (leftmost) in decreasing size order.

The objective is to transfer the entire stack of disks from first tower to third tower (rightmost),
moving only one disk at a time
never placing a larger disk on top of a smaller disk.


void towerOfHanoi(int num, char src, char dst, char temp) {
  if (num < 1)
    return;

  towerOfHanoi(num - 1, src, temp, dst);
  std::cout << "Move " << num << " disk from peg " << src << " to peg " << dst << std::endl;
  towerOfHanoi(num - 1, temp, dst, src);
}

int main() {
  int num = 4;
  std::cout << "The sequence of moves involved in the Tower of Hanoi are :" << std::endl;
  towerOfHanoi(num, 'A', 'C', 'B');
  return 0;
}
Analysis:

TowerOfHanoi problem if we want to move N disks from source to
destination, then we first move N-1 disks from source to temp, then move the lowest Nth disk from source to destination. Then will move N-1 disks from temp to destination.

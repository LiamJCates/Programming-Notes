Linked List ADT Operations

Insert(k): adds k to the start of the list.

Insert an element at the start of the list. Just create a new element and move pointers. So that this new element becomes the head element of the list.

O(1) constant time.

Delete(): delete element at the start of the list

Delete an element at the start of the list. We just need to move one pointer and free the old head node.

O(1) constant time.

PrintList(): display all the elements of the list.

Start with the first element and then follow the pointers.

O(N) time

Find(k): find the position of element with value k

Start with the first element and follow the pointers until we get the value we are looking for or reach the end of the list.

O(N) time

FindKth(k): find element at position k

Start from the first element and follow the links until you reach the kth element.

O(N) time

IsEmpty(): check if the number of elements in the list are zero.
Just check the head pointer of the list it should be nullptr. Which means list is
empty.

O(1) time






Linked List implementation in C++ Collections list<E> in by C++ Collections is a data structure which implements linked list.
When we have insertion and deletion from both the front and back, we use linked list.

#include <list>
int main()
{
  std::list<int> ll;
  ll.push_front(1);
  ll.push_back(11);
  ll.push_front(2);
  ll.push_back(21);
  ll.push_front(3);
  ll.push_back(31);
  std::cout << "Contents of Linked List: ";
  for (auto var : ll)
  std::cout << var << " ";
  std::cout << std::endl;
  ll.pop_front();
  ll.pop_back();
  std::cout << "Contents of Linked List: “;
  for (auto var : ll)
  std::cout << var << " ";
  return 0;
}

Output
Contents of Linked List: 3 2 1 11 21 31
Contents of Linked List: 2 1 11 21

Analysis:
Values are added to the back and front of the linked list. Then the value stored in linked list are printed. Then values are removed from linked list from front and back and again linked list content is printed to screen.

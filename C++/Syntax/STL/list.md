Sequence Container: list

List containers are implemented
as doubly linked lists. Thus, every element in a list points to both its immediate
predecessor and its immediate successor (except the first and last elements).

The name of the class containing the definition of the class list is list. The
definition of the class list, and the definitions of the functions to implement the
various operations on a list, are contained in the header file list. Therefore, to use
list in a program, the program must include the following statement:
#include <list>

| Constructor | Description |
|-------------|-------------|
| list<elementType> listCont; | Creates the empty list container listCont. (The default constructor is invoked.) |
| list<elementType> listCont(otherList); | Creates the list container listCont and initializes it to the elements of otherList. |
| list<elementType> listCont(size); | Creates the list container listCont of size size. listCont is initialized using the default constructor.|
| list<elementType> listCont(n, elm); | Creates the list container listCont of size n. listCont is initialized using n copies of the element elm. |
| list<elementType> listCont(beg, end); | Creates the list container listCont. listCont is initialized to the elements in the range of iterators [beg, end); |

| Expression  | Description |
|-------------|-------------|
| listCont.assign(n, elem); Assigns n copies of elem.
listCont.assign(beg, end);
Assigns all of the elements in the
range beg...end−1. Both
beg and end are iterators.
listCont.push_front(elem); Inserts elem at the beginning of
listCont.
listCont.pop_front(); Removes the first element from
listCont.
listCont.front(); Returns the first element. (Does not
check whether the container is empty.)
listCont.back();
Returns the last element. (Does
not check whether the container
is empty.)
listCont.remove(elem); Removes all of the elements that
are equal to elem.
listCont.remove_if(oper); Removes all of the elements for
which oper is true.
listCont.unique();
If the consecutive elements in
listCont have the same
value, removes the duplicates.
listCont.unique(oper);
If the consecutive elements in
listCont have the same
value, removes the duplicates, for
which oper is true.

listCont1.splice(pos, listCont2);
All of the elements of
listCont2 are moved to
listCont1 before the position
specified by the iterator pos. After
this operation,listCont2 is
empty.
listCont1.splice(pos, listCont2, pos2);
All of the elements starting at
pos2 of listCont2 are
moved to listCont1 before
the position specified by the
iterator pos.
listCont1.splice(pos, listCont2,
beg, end);
All of the elements in the
range beg...end−1 of
listCont2 are moved
to listCont1 before the
position specified by the iterator
pos. Both beg and end are
iterators.
listCont.sort(); The elements of listCont are
sorted. The sort criteria is <.
listCont.sort(oper);
The elements of listCont are
sorted.
The sort criteria is specified by
oper.
listCont1.merge(listCont2);
Suppose that the elements
of listCont1 and
listCont2 are sorted.
This operation moves all of the
elements of listCont2
into listCont1. After
this operation, the elements
in listCont1 are sorted.
Moreover, after this operation,
listCont2 is empty.

listCont1.merge(listCont2, oper);
Suppose that the elements
of listCont1 and
listCont2 are sorted
according to the sort criteria
oper. This operation moves all
of the elements of listCont2
into listCont1. After
this operation, the elements
in listCont1 are sorted
according to the sort criteria oper.
listCont.reverse(); The elements of listCont are
reversed.


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

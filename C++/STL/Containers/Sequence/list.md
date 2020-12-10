list
A list is a sequence container with fast insert/remove operations everywhere
but with no random element access.

insertion and deletion in the middle of the data structures are very inefficient operations for contiguous data structures. And that's where linked-list-like structures come into the picture.

List containers are implemented as doubly linked lists. Thus, every element in a list points to both its immediate predecessor and its immediate successor (except the first and last elements).

As a result of a lack of random access, you cannot use operator[] or at to access arbitrary elements in a list, because such operations would be very inefficient.

The trade­off is that inserting and removing elements in a list is much faster.



The STL implementation std::list is available from the <list> header. To use list in a program, the program must include the following statement:
#include <list>


The list container supports the same constructor patterns as vector.


| Constructor | Description |
|-------------|-------------|
| list<elementType> listCont; | Creates the empty list container listCont. (The default constructor is invoked.) |
| list<elementType> listCont(otherList); | Creates the list container listCont and initializes it to the elements of otherList. |
| list<elementType> listCont(size); | Creates the list container listCont of size size. listCont is initialized using the default constructor.|
| list<elementType> listCont(n, elm); | Creates the list container listCont of size n. listCont is initialized using n copies of the element elm. |
| list<elementType> listCont(beg, end); | Creates the list container listCont. listCont is initialized to the elements in the range of iterators [beg, end); |


All the vector methods not implemented by list, along with an explanation for their absence, are as follows:
capacity, reserve, shrink_to_fit Because list acquires memory incrementally, it doesn’t require periodic resizing.
operator[], at Random element access is prohibitively expensive on lists.
data Unneeded because list elements are not contiguous.

You can perform special operations on lists, such as splicing elements
from one list into another using the splice method, removing consecutive
duplicate elements using the unique method, and even sorting the elements
of a container using the sort method. Consider, for example, the remove_if
method. The remove_if method accepts a function object as a parameter,
and it traverses the list while invoking the function object on each element.
If the result is true, remove_if removes the element.




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




Operation Notes
lst.emplace_front(...) Constructs an element in place at the front of the d by forwarding all arguments to the appropriate constructor.
lst.push_front(t) Constructs an element in place at the front of d by copying t.
lst.pop_front() Removes the element at the front of d.
lst.push_back(t) Constructs an element in place at the back of d by copying t.
lst.pop_back() Removes the element at the back of d.
lst1.splice(itr1,lst2,
[itr2a], [itr2b])
Transfers items from lst2 into lst1 at position itr1.
Optionally, only transfer the element at itr2a or the elements
within the half-open range itr2a to itr2b.Containers 427

lst.remove(t) Removes all elements in lst equal to t.
lst.remove_if(pred) Eliminates elements in lst where pred returns true; pred
accepts a single T argument.
lst.unique(pred) Eliminates duplicate consecutive elements in lst according to
the function object pred, which accepts two T arguments and
returns t1 == t2.
lst1.merge(lst2, comp) Merges lst1 and lst2 according to the function object comp,
which accepts two T arguments and returns t1 < t2.
lst.sort(comp) Sorts lst according to the function object comp.
lst.reverse() Reverses the order of lst’s elements (mutates lst).








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

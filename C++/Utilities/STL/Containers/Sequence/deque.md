Sequence Container: deque
A deque (pronounced “deck”) is a sequential container with fast insert and
remove operations from the front and back.

Deque is a portmanteau of double-ended queue.

Deque containers are implemented as dynamic arrays in such a way that the elements can be inserted at both ends efficiently. Inserting elements in the middle, however, is time consuming because the elements in the queue need to be shifted.

The STL implementation std::deque is available from the <deque> header. To use a deque container in a program, the program must include the following statement:
#include <deque>

A vector and a deque have very similar interfaces, but internally their
storage models are totally different. A vector guarantees that all elements
are sequential in memory, whereas a deque’s memory is usually scattered
about, like a hybrid between a vector and a list. This makes large resizing
operations more efficient and enables fast element insertion/deletion at the
container’s front.
Constructing and accessing members are identical operations for vectors
and deques.
Because the internal structure of deque is complex, it doesn’t expose a
data method. In exchange, you gain access to push_front and emplace_front,
which mirror the push_back and emplace_back that you’re familiar with from
vector.

The vector methods not implemented by deque, along with an explanation
for their absence, are as follows:

capacity, reserve
  Because the internal structure is complicated, it might not be efficient to compute capacity. Also, deque allocations are relatively fast because a deque doesn’t relocate existing elements, so reserving memory ahead of time is unnecessary.

data
  The elements of deque are not contiguous


| Constructor | Description |
|-------------|-------------|
| deque<elementType> deq; | Creates an empty deque container deq. (The default constructor is invoked.) |
| deque<elementType> deq(otherDeq); | Creates the deque container deq and initializes it to the elements of otherDeq; deq and otherDeq are of the same type. |
| deque<elementType> deq(size); | Creates the deque container deq of size size. deq is initialized using the default constructor. |
| deque<elementType> deq(n, elm); | Creates the deque container deq of size n. deq is initialized using n copies of the element elm. |
| deque<elementType> deq(beg, end); | Creates the deque container deq. deq is initialized to the elements in the range of iterators [beg, end);. |

| Expression  | Description |
|-------------|-------------|
| deq.assign(n,elem) | Assigns n copies of elem. |
| deq.assign(beg, end) | Assigns all of the elements in the range beg...end−1. |
| deq.push_front(elem) | Inserts elem at the beginning of deq. |
|deq.pop_front() | Removes the first element from deq. |
| deq.at(index)  | Returns the element at the position specified by index. |
| deq[index] | Returns the element at the position specified by index. |
| deq.front() | Returns the first element. (Does not check whether the container is empty.) |
| deq.back() | Returns the last element. (Does not check whether the container is empty.) |
| deq.emplace_front(...) | Constructs an element in place at the front of the d by forwarding all arguments to the appropriate constructor. |
| deq.push_front(t) | Constructs an element in place at the front of the d by copying t. |
| deq.pop_front() | Removes the element at the front of d. |

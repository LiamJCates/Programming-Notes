Sequence Container: deque

The term deque stands for
double-ended queue. Deque containers are implemented as dynamic arrays in such
a way that the elements can be inserted at both ends efficiently.

inserting elements in the middle, however, is time
consuming because the elements in the queue need to be shifted.

The name of the class defining the deque containers is deque. The definition of the
class deque, and the functions to implement the various operations on a deque
object, are also contained in the header file deque. Therefore, to use a deque container in a program, the program must include the following statement:
#include <deque>


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

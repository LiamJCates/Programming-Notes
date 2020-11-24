A queue is an ordered, non-unique lists of values.
A queue stores values in the order in which they were added and are retrieved in the order in which they were added (FIFO—first in, first out).

To preserve this method of operation a queue is a list with the following restrictions
insertions can be performed in only one position, namely, the end of the list, called the rear.
deletions can be performed in only one position, namely, the start of the list, called the front.

Structure
Either a linked list or dynamic array can be used as the underlying data structure.

Linked lists usually allocate memory dynamically for each element. Depending on the overhead of the memory allocator, these allocations are often more time consuming than the copies required by a dynamic array, so a stack based on a dynamic array is usually faster than one based on a linked list. Implementing a linked list is less complicated than implementing a dynamic array, so in an interview, a linked list is probably the best choice for your solution.

Whichever choice you make, be sure to know the pros and cons of both approaches.


API
public class Queue<Item> implements Iterable<Item>
Queue()             create an empty queue
void enqueue(Item item)     add an item
Item dequeue()             remove the least recently added item
boolean isEmpty()         is the queue empty?
int size()             number of items in the queue


Typical implementation is achieved through the use of a list or resizing array as the underlying data structure and the use of a size variable
insertion increments and deletion decrements the size variable

list insertion (enqueue) and deletion (dequeue) are done using the head and tail pointers respectively
a head pointer is maintained to handle deletion of nodes there
a tail pointer is maintained to handle insertion of nodes there

array insertion (enqueue) and deletion (dequeue) are done using head and tail index variables
    Update head and tail modulo the array capacity

both implementations return the size and check if the stack is empty using the size variable (size == 0)


Exceptions
Underflow:  throw exception if pop from an empty stack, (use of pop() when size == 0)
Overflow:  use resizing array for array implementation. (use of push() when size == array.length)
Loitering.  arrays holding a reference to an object when it is no longer needed.

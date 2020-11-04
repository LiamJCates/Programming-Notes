Queues and stacks are both ordered, non-unique lists of values.
A queue and a stack both store values in the order in which they were added.
Their difference is in how items are retrieved
Items are retrieved from a queue in the order in which they were added (FIFO—first in, first out)
Items are retrieved from a stack in reverse order (LIFO—last in, first out).

Either a linked list or dynamic array can be used as the underlying data structure.

Linked lists usually allocate memory dynamically for each element. Depending on the overhead of the memory allocator, these allocations are often more time consuming than the copies required by a dynamic array, so a stack based on a dynamic array is usually faster than one based on a linkedlist. Implementing a linked list is less complicated than implementing a dynamic array, so in an interview, a linked list is probably the best choice for your solution. Whichever choice you make, be sure to explain the pros and cons of both approaches to your interviewer.


















FIFO queue
A collection based on doing tasks in the same order that they arrive, first-in-first-out (FIFO) policy.

Ordered
Nonunique

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




















Stack
A stack is an ordered, non-unique list with the restriction that insertions and deletions can be performed in only one position, namely, the end of the list, called the top.

A collection based on doing tasks in the order of most recent arrival, last-in-first-out (LIFO) policy.



push/insert    O(1)    Insert item at the top of stack
peek/find    O(1)    Return top of stack
pop/delete    O(1)    Remove and return top of stack



Typical implementation is achieved through the use of a list or resizing array as the underlying data structure

list insertion (push) and deletion (pop) is done using the head pointer reference
array insertion (push) and deletion (pop) is done using the size to determine the index

both implementations return the size and check if the stack is empty using the size variable (size == 0)


Exceptions
Underflow:  throw exception if pop from an empty stack, (use of pop() when size == 0)
Overflow:  use resizing array for array implementation. (use of push() when size == array.length)
Loitering.  arrays holding a reference to an object when it is no longer needed.



Stack Uses:
A typical reason to use a stack iterator in an application is to save items in a collection while at the same time reversing their relative order.

Expression evaluation
developed by E. W. Dijkstra in the 1960s
uses two stacks (one for operands and one for operators) to do this job. An expression consists of parentheses, operators, and operands (numbers). Proceeding from left to right and taking these entities one at a time,
we manipulate the stacks according to four possible cases, as follows:
■ Push operands onto the operand stack.
■ Push operators onto the operator stack.
■ Ignore left parentheses.
■ On encountering a right parenthesis, pop an operator, pop the requisite number
of operands, and push onto the operand stack the result of applying that operator to those operands.

After the final right parenthesis has been processed, there is one value on the stack,
which is the value of the expression.

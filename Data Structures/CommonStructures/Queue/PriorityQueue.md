A priority queue is another variant of a queue in which elements are
processed on the basis of assigned priority. Each element in a priority queue
is assigned a special value called the priority of the element.

The elements in the priority queue are processed based on the following rules:

1. An element with higher priority is processed first, and then the element
with lower priority is processed.

2. If the two elements have the same priority, then the elements are processed on the First Come First Served basis. The priority of the element is selected by its value called the implicit priority, and the priority number given with each element is called the explicit priority.

In a priority queue, an element with high priority is served before an element with low priority. In some implementations, if two elements have the same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is undefined.

The priority given to the elements in the queue is based on several factors.


priority queues are further divided into two types which are:
1. Ascending Priority Queue – In this type of priority queue, elements
can be inserted in any order, but at the time of deletion of elements from
the queue, the smallest element is searched and deleted first.

2. Descending Priority Queue – In this type of priority queue, elements
can be inserted in any order. But at the time of deletion of elements from
the queue, the largest element is searched and deleted first.


Implementation
There are a variety of simple, usually inefficient, ways to implement a priority queue.

A basic implementation can use either a static array, dynamic array, or linked list

A linked structure provides an analogy to help one understand what a priority queue is.

For instance, one can keep all the elements in an unsorted list ( O(1) insertion time ). Whenever the highest-priority element is requested, search through all elements for the one with the highest priority. (O(n) pull time),

insert(node) {
  list.append(node)
}

pull() {
  foreach node in list{
     if highest.priority < node.priority{
         highest = node
     }
  }
  list.remove(highest)
  return highest
}

In another case, one can keep all the elements in priority sorted list (O(n) insertion sort time ), whenever the highest-priority element is requested, the first one in the list can be returned. ( O(1) pull time )

insert(node) {
  foreach (index,element) in list{
    if node.priority < element.priority{
       list.insert_at_index(node,index)
    }
  }
}

pull() {
    highest = list.get_at_index(list.length-1)
    list.remove(highest)
    return highest
}



Implementation of a priority queue using arrays
While implementing a priority queue using arrays, the following points
must be considered:
•	 Maintain a separate queue for each level of priority or priority number.
•	 Each queue will appear in its own circular array and must have its own
pairs of pointers, that is, FRONT AND REAR.
•	 If each queue is allocated the same amount of memory, then a 2D
array can be used instead of a linear array.
For example – FRONT [K] and REAR [K] are the pointers containing
the front and rear values of row “K” of the queue, where K is the priority
number. If we want to insert an element with priority K, then we will add
the element at the REAR end of row K; K is the row as well as the priority number of that element.



Implementation of a priority queue using linked lists
A priority queue can be implemented using a linked list. While implementing the priority queue using a linked list, every node will have three
parts:
a) Information part
b) Priority number of the element
c) Address of the next element
An element with higher priority will precede the element having lower priority. Also, priority number and priority are opposite to each other;
that is, an element having a lower priority number means it has higher
priority.

While inserting a new element in a linked priority queue, first we will
traverse the entire queue until we find a node which has a lower priority
than the new element. Thus, the new element is inserted before the element with the lower priority. Also, if there is an element in the queue which
has same priority as that of the new element, then in that case the new element is inserted after that element.

Deleting an element from a linked priority queue is a very simple process. In that case, the first node from the priority queue is deleted and the
information of that node is processed first.




To improve performance, priority queues typically use a heap as their backbone, giving O(log n) performance for inserts and removals, and O(n) to build initially from a set of n elements.

While priority queues are often implemented with heaps, they are conceptually distinct from heaps. A priority queue is a concept like "a list" or "a map"; just as a list can be implemented with a linked list or an array, a priority queue can be implemented with a heap or a variety of other methods such as an unordered array.

Uses
Priority queues are commonly used in operating systems for executing higher
priority processes first. The priority assigned to these processes may be
based on the time taken by the CPU to execute these processes completely

**Linear data structures** are a type of data structure where elements are arranged in a linear sequence, meaning each element has a unique predecessor and successor (except for the first and last elements). In these structures, data elements are stored and accessed in a sequential order. Linear data structures are often the simplest and most intuitive types of data structures.

### Common Examples of **Linear Data Structures**:

#### 1. **Array**
   - **Definition**: An **array** is a collection of elements, all of the same type, stored in contiguous memory locations. Arrays allow direct access to elements via indices.
   - **Characteristics**: 
     - Fixed size (in many languages).
     - Efficient random access to elements.
     - Elements can be accessed sequentially.
   - **Example (Python)**:
     ```python
     my_array = [1, 2, 3, 4, 5]
     print(my_array[0])  # Output: 1
     ```

#### 2. **Linked List**
   - **Definition**: A **linked list** is a linear collection of nodes, where each node contains data and a reference (or pointer) to the next node in the sequence. Linked lists can be singly linked (one direction) or doubly linked (two directions).
   - **Types**:
     - **Singly Linked List**: Each node points to the next node.
     - **Doubly Linked List**: Each node has a pointer to both the next and the previous node.
     - **Circular Linked List**: The last node points back to the first node.
   - **Example (Singly Linked List in Python)**:
     ```python
     class Node:
         def __init__(self, value):
             self.value = value
             self.next = None

     head = Node(1)
     second = Node(2)
     third = Node(3)
     head.next = second
     second.next = third
     ```

#### 3. **Stack**
   - **Definition**: A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. In a stack, elements are added and removed from the same end, called the "top".
   - **Operations**:
     - **Push**: Adds an element to the top.
     - **Pop**: Removes an element from the top.
     - **Peek/Top**: Retrieves the top element without removing it.
   - **Example (Python)**:
     ```python
     stack = []
     stack.append(1)  # Push
     stack.append(2)
     print(stack.pop())  # Output: 2 (Pop)
     ```

#### 4. **Queue**
   - **Definition**: A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. In a queue, elements are added at the back (enqueue) and removed from the front (dequeue).
   - **Operations**:
     - **Enqueue**: Adds an element to the back.
     - **Dequeue**: Removes an element from the front.
     - **Peek/Front**: Retrieves the front element without removing it.
   - **Example (Python)**:
     ```python
     from collections import deque
     queue = deque()
     queue.append(1)  # Enqueue
     queue.append(2)
     print(queue.popleft())  # Output: 1 (Dequeue)
     ```

#### 5. **Deque (Double-Ended Queue)**
   - **Definition**: A **deque** is a linear data structure that allows adding and removing elements from both ends (front and back). It combines the functionality of both a stack and a queue.
   - **Operations**:
     - **Append**: Adds an element to the back.
     - **Appendleft**: Adds an element to the front.
     - **Pop**: Removes an element from the back.
     - **Popleft**: Removes an element from the front.
   - **Example (Python)**:
     ```python
     from collections import deque
     deque_example = deque()
     deque_example.append(1)  # Add to back
     deque_example.appendleft(0)  # Add to front
     print(deque_example.pop())  # Output: 1
     ```

### Key Characteristics of **Linear Data Structures**:
- **Sequential Arrangement**: Elements are arranged in a sequence where each element is connected to its predecessor and successor.
- **Fixed or Dynamic Size**: Some linear data structures, like arrays, have a fixed size, while others like linked lists and queues can grow or shrink dynamically.
- **Order Preservation**: The order of elements is important in linear data structures, and operations are typically performed in a sequential manner.

### Summary of Common Linear Data Structures:
- **Array**: A collection of elements stored in contiguous memory locations with efficient random access.
- **Linked List**: A collection of nodes where each node points to the next node in the sequence.
- **Stack**: A collection of elements with LIFO order (Last In, First Out).
- **Queue**: A collection of elements with FIFO order (First In, First Out).
- **Deque**: A double-ended queue that allows adding/removing elements from both ends.

These linear data structures are foundational in computer science and are commonly used in algorithms, applications, and systems requiring sequential data access and manipulation.
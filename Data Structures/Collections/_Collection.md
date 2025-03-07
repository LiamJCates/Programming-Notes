The most general data structure is a Collection

Collection types can be partitioned to Linear Collections, Associative Collections, Graphs

Collection
In computer science, a collection is a grouping of some variable number of data items (possibly zero). 
The members of a collection are generally called elements, 
These elements have some shared significance to the problem being solved and need to be operated upon together in some controlled fashion.

Generally, a collection's data items will be of the same type or, in languages supporting inheritance, derived from some common ancestor type.

The various kinds of collections are abstract concepts. 

There exists in the literature considerable confusion between the abstract concepts of computer science and their specific implementations in various languages or kinds of languages. Assertions that collections, lists, sets, trees, etc. are data structures, abstract data types or classes must be read with this in mind. 

Collections are first and foremost abstractions that are useful in formulating solutions to computing problems. Viewed in this light, they retain important links to underlying mathematical concepts which can be lost when the focus is on the implementation.

For example, a priority queue is often implemented as a heap, while an associative array is often implemented as a hash table, so these abstract types are often referred to by this preferred implementation, as a "heap" or a "hash", though this is not strictly correct.






Data Structures


Linear
    Direct Access   
        Homogeneous: Array
        Heterogenous: Tuple

    Sequential Access  
        General: List
            LIFO: Stack
            FIFO: Queue

Non-Linear
Sets
Heiarchical: Trees
Associative: Maps
Graphs






| Characteristic | Description | Example |
| --------------- | --------------- | --------------- |
| Linear | Linear data structure's elements are arranged in a linear sequence. | Array |
| Non-Linear | In Non-Linear data structures elements are not in sequence. | Tree, Graph |
| Homogeneous | In homogeneous data structures, all the elements are of the same type. | Array |
| Heterogenous | In heterogenous data structure, the elements may or may not be of the same type. | Structures |
| Static | Static data structures are those whose sizes and structures associated memory locations are fixed, at compile time. | Array |
| Dynamic | Dynamic structures are those which expand or shrink depending upon the program's needs. To support this the structure's associated memory locations are reallocated during runtime. | Linked List using pointers |







Data structures can be classified into **two main types** based on the **organization of their elements**:

### 1. **Linear Data Structures**
   - **Definition**: In linear data structures, the elements are arranged in a **sequential manner**, where each element has a unique predecessor and successor (except the first and last elements). The elements are processed one after another in a linear sequence.
   - **Characteristics**: 
     - Elements are stored in a **contiguous** or **sequential** manner.
     - **Operations** (like insertion, deletion, access) are typically done in a **linear sequence**.
   - **Examples**:
     - **Arrays**: Elements are stored in contiguous memory locations and accessed by indices.
     - **Linked Lists**: A series of nodes where each node contains data and a reference to the next node.
     - **Stacks**: A collection where elements are added and removed in a **last in, first out (LIFO)** order.
     - **Queues**: A collection where elements are added at the rear and removed from the front in a **first in, first out (FIFO)** order.

### 2. **Non-Linear Data Structures**
   - **Definition**: In non-linear data structures, the elements are arranged in a **hierarchical or interconnected manner**, where each element can have multiple relationships with other elements. These structures do not follow a strict sequential order.
   - **Characteristics**:
     - Elements can have multiple **connections** or relationships with other elements.
     - Operations may involve traversal across multiple elements in more complex ways (e.g., hierarchically or graphically).
   - **Examples**:
     - **Trees**: A hierarchical structure where each element (node) has a parent and possibly multiple children (e.g., binary trees, heaps).
     - **Graphs**: A collection of nodes (vertices) connected by edges, which can be directed or undirected (e.g., social networks, roadmaps).

### Summary:
- **Linear data structures**: Elements are arranged in a sequential order (e.g., arrays, linked lists, stacks, queues).
- **Non-linear data structures**: Elements are arranged in a more complex, hierarchical, or interconnected manner (e.g., trees, graphs).



Depending on the organization of the elements, data structures may be classified into two types:

Linear data structures:
Elements are accessed in a sequential order but it is not compulsory to store all elements sequentially.

Linear Data structure can further be divided into
Contiguous
    Arrays, Arraylist
Linked
    Singly Linked, Doubly Linked, Circular Linked List

The array and linked list are two principal choices in representing a more abstract data structure called a linear list or simply a list. A list is a finite sequence of data items, i.e., a collection of data items arranged in a certain linear order.

Lists
    Stack, Queue, Deque, Priority Queue





Non – linear data structures:
Elements of this data structure are stored/accessed in a non-linear order.
Trees
Binary trees, B-trees, Heaps


Hash-based structures
Dictionary


Graphs
Undirected, Directed, Weighted




From the data structure point of view, following are some important categories of algorithms

| Operation | Explanation |
|-----------|-------------|
| Insertion | Addition of a new data element in a data structure |
| Access | Reading the value of a specified data element |
| Deletion | Removal of a data element from a data structure |
| Searching | Searching for a specified data element in a data structure |
| Traversal | Processing all the data elements present |
| Sorting | Arranging data structure elements according to a specified order |
| Merging | Combining elements of two data structures to form a new data structure of the same type |


A useful metric for determining the type of data structure to be used is algorithmic complexity, also called time complexity. Time complexity indicates the relative amount of time required, in proportion to the size of the data, to perform a certain operation.

Thus, time complexity shows how the time will vary if we change the size of the dataset. The time complexity of different operations on any data type is dependent on how the data is stored inside it.

[Complexity.png]



Data Structure Complexity

|Data Structure | Insert | Delete |  Balance  | Get at index | Search/Query | Find minimum | Find maximum | Space usage |
| --------------- | --------------- | --------------- | --------------- | --------------- | --------------- | --------------- | --------------- | --------------- |
| Unsorted array | O(1)(Unordered) <br /> O(n)(in place) | O(1)(Unordered) <br /> O(n)(in place) | N/A | O(1) | O(n) | O(n) | O(n) | O(n) |
| Sorted array | O(n) | O(n) | N/A | O(1) | O(log n) | O(1) | O(1) | O(n) |
| Stack | O(1) | O(1) | | | O(n) | | | O(n) |
| Queue | O(1) | O(1) | | | O(n) | | | O(n) |
| Unsorted linked list | O(1) | O(1) + <br /> O(n) search | N/A | O(n) | O(n) | O(n) | O(n) | O(n) |
| Sorted linked list | O(n) | O(1) | N/A | O(n) | O(n) | O(1) | O(1) | O(n) |
| Skip list |  |  |  |  |  |  |  |  |
| Self-balancing binary search tree | O(log n) | O(log n) | O(log n) | N/A | O(log n) | O(log n) | O(log n) | O(n) |
| Heap | O(log n) | O(log n) | O(log n) | N/A | O(n) | O(1)minheap <br /> O(n)maxheap | O(1)maxheap <br /> O(n)minheap | O(n) |
| Hash table | O(1) | O(1) | O(n) | N/A | O(1) | O(n) | O(n) | O(n) |
| Trie (k = avg len of key) | O(k) | O(k) | N/A | O(k) | O(k) | O(k) |  O(k n) |
| Cartesian tree | O(log n) | Θ(log n) <br /> O(log n) | O(log n) | N/A | O(log n) | O(log n) | O(log n) | O(n) |
B-tree | O(log n) | O(log n) | O(log n) | N/A | O(log n) | O(log n) | O(log n) | O(n) |
| Red-black tree |  |  |  |  |  |  |  |  |
| Splay tree |  |  |  |  |  |  |  |  |
| AVL tree | O(log n) | O(log n) <br /> Θ(log n) | O(log n) | N/A | O(log n) | O(log n) | O(log n) | O(n) |
| k-d tree | | | | | | | | |
| Adj List | Vertex O(1) <br /> Edge O(1) | Vertex O(V+E) <br /> Edge O(E)| | | O(V) | | | O(V+E) |
| Incidence List | Vertex O(1) <br /> Edge O(1) | Vertex O(E) <br /> Edge O(E) | | | O(E) | | | O(V+E) |
| Adj Matrix | Vertex O(V^2) <br /> Edge O(1) | Vertex O(V^2) <br /> Edge O(1) | | | O(1) | | | O(V^2) |
| Incidence Matrix | Vertex O(V*E) <br /> Edge O(V*E) | Vertex O(V*E) <br /> Edge O(V*E) | | | O(E) | | | O(V*E) |

https://en.wikipedia.org/wiki/Search_data_structure

This table is only an approximate summary; for each data structure there are special situations and variants that may lead to different costs. Also two or more data structures can be combined to obtain lower costs.

Note: Insert on an unsorted array is sometimes quoted as being O(n) due to the assumption that the element to be inserted must be inserted at one particular location of the array, which would require shifting all the subsequent elements by one position. However, in a classic array, the array is used to store arbitrary unsorted elements, and hence the exact position of any given element is of no consequence, and insert is carried out by increasing the array size by 1 and storing the element at the end of the array, which is a O(1) operation. Likewise, the deletion operation is sometimes quoted as being O(n) due to the assumption that subsequent elements must be shifted, but in a classic unsorted array the order is unimportant (though elements are implicitly ordered by insert-time), so deletion can be carried out by swapping the element to be deleted with the last element in the array and then decrementing the array size by 1, which is a O(1) operation.


Useful Links

https://xlinux.nist.gov/dads/






### **Categories of Data Structures**  

Data structures are broadly classified into **two main categories** based on how they organize and store data:  

1. **Linear Data Structures**  
2. **Non-Linear Data Structures**  

Additionally, they can be further categorized based on their functionality and storage method.

---

## **1. Linear Data Structures**  
🔹 **Definition:** Data elements are arranged **sequentially** in memory, and each element is connected to its adjacent elements.  
🔹 **Key Characteristics:**  
- **Simple to implement** and traverse  
- **Fixed or dynamic size**  
- **Efficient for ordered data processing**  

### **Types of Linear Data Structures**  
| **Data Structure** | **Description** | **Time Complexity (Common Ops)** |
|----------------|----------------|----------------|
| **Array** | Fixed-size, contiguous memory allocation | Access: \(O(1)\), Insert/Delete: \(O(n)\) |
| **Linked List** | Dynamic size, each element points to the next | Access: \(O(n)\), Insert/Delete: \(O(1)\) |
| **Stack** | LIFO (Last In, First Out) | Push/Pop: \(O(1)\), Search: \(O(n)\) |
| **Queue** | FIFO (First In, First Out) | Enqueue/Dequeue: \(O(1)\), Search: \(O(n)\) |
| **Deque** | Double-ended queue (insert/remove from both ends) | Insert/Delete: \(O(1)\) |

---

## **2. Non-Linear Data Structures**  
🔹 **Definition:** Data elements are **not arranged sequentially**; they follow a hierarchical or interconnected structure.  
🔹 **Key Characteristics:**  
- Efficient for complex relationships  
- Good for **hierarchical** or **graph-based** problems  
- May require **advanced traversal techniques**  

### **Types of Non-Linear Data Structures**  
| **Data Structure** | **Description** | **Common Applications** |
|----------------|----------------|----------------|
| **Tree** | Hierarchical structure, parent-child relationships | File systems, databases, AI (decision trees) |
| **Binary Tree** | Each node has at most two children | Expression evaluation, searching |
| **Binary Search Tree (BST)** | Left child < Parent < Right child | Searching: \(O(\log n)\), Worst case \(O(n)\) |
| **Heap** | Specialized tree for priority-based operations | Priority queues, scheduling |
| **Graph** | Set of nodes (vertices) connected by edges | Networks, social media, shortest path algorithms |

---

## **3. Static vs. Dynamic Data Structures**  
🔹 **Static Data Structures:**  
- **Fixed size**, allocated at compile-time  
- **Example:** Arrays  

🔹 **Dynamic Data Structures:**  
- **Size can grow or shrink**, allocated at runtime  
- **Example:** Linked lists, trees, graphs  

---

## **4. Primitive vs. Abstract Data Structures**  
🔹 **Primitive Data Structures:** Built-in types used as the foundation for complex structures.  
- **Examples:** Integer, Float, Character, Boolean  

🔹 **Abstract Data Structures (ADTs):** Defined by operations rather than implementation.  
- **Examples:** Stack, Queue, List, Dictionary  

---

## **5. Linear vs. Hierarchical vs. Graph-Based Structures**  
| **Category** | **Examples** | **Structure** |
|------------|------------|------------|
| **Linear** | Arrays, Linked Lists, Stacks, Queues | Elements in sequence |
| **Hierarchical** | Trees, Heaps | Parent-child relationships |
| **Graph-Based** | Graphs (Adjacency List/Matrix) | Complex connections between nodes |

---

### **Conclusion**  
Choosing the right data structure **depends on the problem requirements** (speed, memory, traversal). **Linear structures** are great for ordered data, while **non-linear structures** handle complex relationships. Would you like a comparison of specific data structures? 🚀





Container data structures are fundamental structures used to store and manage collections of data. The basic categories of container data structures are:

1. **Linear Containers**: These store elements in a sequential order, where each element is linked to the next in some way.
   - **Arrays**: Fixed-size containers that store elements of the same type.
   - **Lists**: Dynamic collections that store elements in a sequence, often allowing efficient insertion and removal of elements.
     - **Singly Linked List**
     - **Doubly Linked List**
   - **Queues**: Follow FIFO (First-In, First-Out) order, where elements are added at the end and removed from the front.
   - **Stacks**: Follow LIFO (Last-In, First-Out) order, where elements are added and removed from the top.

2. **Associative Containers**: These store elements in key-value pairs, with fast lookups based on keys.
   - **Hash Tables**: Store key-value pairs and allow fast access to elements using a hash function.
   - **Maps (or Dictionaries)**: Store elements as key-value pairs, with keys providing direct access to the associated value.
   - **Sets**: Collections of unique elements, typically implemented using hash tables or trees.

3. **Graph Containers**: Used to represent relationships between elements, with nodes (vertices) and edges (connections).
   - **Adjacency List**: A list of lists or dictionaries where each vertex has a collection of its adjacent vertices.
   - **Adjacency Matrix**: A 2D array where each cell represents the presence or weight of an edge between two vertices.
    
    **Tree-Based Containers**: These store elements in a hierarchical structure with nodes, which can be ordered or unordered.
   - **Binary Trees**: Each node has at most two children.
   - **Binary Search Trees (BST)**: A type of binary tree where elements are ordered so that for any node, the left child’s value is smaller and the right child’s value is larger.
   - **Heaps**: Specialized trees used to maintain a partial order (e.g., a max-heap or min-heap).

These categories cover the general types of containers, but there can be further specialization and combinations depending on the specific requirements of the application.
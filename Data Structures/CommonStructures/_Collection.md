The most general data structure is a Collection

Collection types can be partitioned to Linear Collections, Associative Collections, and Graphs

Collection
In computer science, a collection is a grouping of some variable number of data items (possibly zero), generally called elements, that have some shared significance to the problem being solved and need to be operated upon together in some controlled fashion.

Generally, a collection's data items will be of the same type or, in languages supporting inheritance, derived from some common ancestor type. A collection is the implementation of the Container abstract data types, and does not prescribe a specific implementation as a concrete data structure, though often there is a conventional choice.

As described here, a collection and the various kinds of collections are abstract concepts. There exists in the literature considerable confusion between the abstract concepts of computer science and their specific implementations in various languages or kinds of languages. Assertions that collections, lists, sets, trees, etc. are data structures, abstract data types or classes must be read with this in mind. Collections are first and foremost abstractions that are useful in formulating solutions to computing problems. Viewed in this light, they retain important links to underlying mathematical concepts which can be lost when the focus is on the implementation.
For example, a priority queue is often implemented as a heap, while an associative array is often implemented as a hash table, so these abstract types are often referred to by this preferred implementation, as a "heap" or a "hash", though this is not strictly correct.


While the concrete data type implementing fixed-size arrays (or tables) are usually not considered a collection because they hold a fixed number of data items, they commonly play a role in the implementation of collections. Variable-size arrays are generally considered collections.

Examples of collections include lists, sets, multisets, trees and graphs.

[DataStructures.png]



Data Structures


Linear
Direct Access   
Homogeneous: Array
Heterogenous: Record

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
| Non-Homogeneous | In Non-Homogeneous data structure, the elements may or may not be of the same type. | Structures |
| Static | Static data structures are those whose sizes and structures associated memory locations are fixed, at compile time. | Array |
| Dynamic | Dynamic structures are those which expand or shrink depending upon the program's needs. To support this the structure's associated memory locations are reallocated during runtime. | Linked List using pointers |








Fundamental Data Structures




Depending on the organization of the elements, data structures may be classified into two types:

Linear data structures:
Elements are accessed in a sequential order but it is not compulsory to store all elements sequentially.

Linear Data structure can further be divided into
Contiguous
    Arrays,    Arraylist
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

## List

A list is an ordered, nonunique, linear collection of dynamic size containing values of a certain type

The list is often compared to another basic linear collection, the array.

The key differences between the List and Array ADTs follow

List Advantages
  Dynamic
    Linked lists are dynamic data structures; that is, they can grow or shrink during the execution of the program.
  Memory Efficient
    Memory is allocated whenever it is required, and it is de-allocated whenever it is no longer needed.




### Notation
List indexing is of the general form: A<sub>0</sub>, A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N-1</sub><br/>
The size of this list is N.<br/>
A list of size 0 is the empty list.<br/>

For any list except the empty list, we say<br/>
A<sub>0</sub> is the first list element<br/>
A<sub>N-1</sub> is the last list element<br/>
i is the position of the A<sub>i</sub>th element.<br/>

A<sub>i</sub> follows (or succeeds) A<sub>i−1</sub>     
A<sub>i−1</sub> precedes A<sub>i</sub>        
for 0 ≤ i < N
<br/><br/>

General List Operations<br/>

add/insert: insert some element into some position in the list<br/>
(pushing subsequent items one position higher)<br/>
  adding at position 0 is adding at the front<br/>
  adding at position size-1 is adding an item at the end<br/>

clear: returns an empty list

contains/find/search: return the position of the first occurrence of an item;

get/find: returns the element in some position, K.

remove/delete: remove some element from some position in the list

set/update: replace an item at specific index
<br/><br/>

Complexity

The time and space complexity of these operations depends on the implementation
There are two popular list implementations: LinkedLists and ArrayLists
The time and space complexity of these implementations are often compared to (static) Arrays and a Self-Balancing Tree (B-Tree)

    Operation             Linked   Array   ArrayList    B-Tree
    Insert/delete at end  Θ(1)     N/A     Θ(1)**       Θ(log n)
    Insert/delete not end Θ(1)     N/A     Θ(n)         Θ(log n)

    Index/access          Θ(n)     Θ(1)    Θ(1)         Θ(log n)
    Search                Θ(n)     Θ(n)    Θ(n)         Θ(log n)

    Wasted space          Θ(n)     0       Θ(n)         Θ(n)

Search Time O(n)
** Amortized


Iterator
We could also add operations such as next and previous, which would take a position as argument and return the position of the successor and predecessor, respectively.

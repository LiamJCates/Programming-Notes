List

A list is an ordered, nonunique, linear collection of dynamic size containing values of a certain type

List indexing is of the general form A<sub>0</sub>, A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N-1</sub>
The size of this list is N.
A list of size 0 is the empty list.

For any list except the empty list, we say
A<sub>0</sub> is the first list element
A<sub>N-1</sub> is the last list element
i is the position of the A<sub>i</sub>th element.

A<sub>i</sub> follows (or succeeds) A<sub>i−1</sub>     
A<sub>i−1</sub> precedes A<sub>i</sub>        
for 0 ≤ i < N




General List Operations
clear                 returns an empty list

contains/find/search  Traverse and return the position of the first occurrence of an item;

find/get              returns the element in some position, K.

insert/add            insert some element from some position in the list
(pushing subsequent items one position higher).
  add at position 0 is adding at the front
  add at position size-1 is adding an item at the end

delete/remove         remove some element from some position in the list

update/set            Traverse list to replace an item at specific index

Iterator
We could also add operations such as next and previous, which would take a position as argument and return the position of the successor and predecessor, respectively.

The time and space complexity of these operations depends on the implementation
There are two popular list implementations: ArrayList and LinkedList

    Operation             Linked   Array   ArrayList    B-Tree
    Index/access          Θ(n)     Θ(1)    Θ(1)         Θ(log n)
    Search                Θ(n)     Θ(n)    Θ(n)         Θ(log n)
    Insert/delete at end  Θ(1)     N/A     Θ(1)**       Θ(log n)
    Insert/delete not end Θ(1)     N/A     Θ(n)         Θ(log n)
    Wasted space          Θ(n)     0       Θ(n)         Θ(n)

+   Search Time O(n)
** Amortized

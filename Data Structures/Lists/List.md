List

A list is an ordered, nonunique, linear collection of dynamic size containing values of a certain type

List indexing is of the general form A0, A1, A2, ..., AN−1
The size of this list is N.
A list of size 0 is the empty list.

For any list except the empty list, we say
A0 is the first list element
AN−1 is the last list element
i is the position of the A<sub>i</sub> th element.

A<sub>i</sub> follows (or succeeds) A<sub>i−1</sub>     
A<sub>i−1</sub> precedes A<sub>i</sub>        
for 0 ≤ i < N




General List Operations
Creation        
printList            O(n)    Traverse and print the contents of the list

clear               O(1)    returns an empty list

contains/find/search    O(n)    Traverse and returns the position of the first occurrence of an item;

findKth/get           returns the element in some position (specified as an argument).

insert/add            insert some element from some position in the list
(pushing subsequent items one position higher).
        add at position 0 is adding at the front
add at position size() is adding an item as the new last item.

remove/delete        remove some element from some position in the list

update/set            O(n)    Traverse list to replace an item at specific index

We could also add operations such as next and previous, which would take a position as argument and return the position of the successor and predecessor, respectively.

The time and space complexity of these operations depends on the implementation
There are two popular list implementations: ArrayList and LinkedList

                                  Linked list       Array       ArrayList    Balanced tree

Indexing                              Θ(n)        Θ(1)       Θ(1)        Θ(log n)
Insert/delete at beginning        Θ(1)        N/A    Θ(n)        Θ(log n)
Insert/delete at end              Θ(1)        N/A        Θ(1) amortized    Θ(log n)
Insert/delete in middle         search time
                                    + Θ(1)        N/A    Θ(n)             Θ(log n)

Wasted space (average)            Θ(n)        0         Θ(n)        Θ(n)

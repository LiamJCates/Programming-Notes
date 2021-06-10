Operations on a Singly Linked List
•	 Traversal
•	 Searching for a given value
•	 Inserting a new node
•	 Deleting a node
•	 Concatenation of two linked lists
•	 Reversing a linked list



### Operation Analysis

Insert(k): adds k to the start of the list.
  Insert element at list head. Create a new node, assign it to the head and point link to list head. So that this new element becomes the head element of the list.
  O(1) constant time.

Delete(): delete element at the start of the list
  Delete an element at list. We just need to move one pointer and free the old head node.
  O(1) constant time.

PrintList(): display list elements
  Start with the first element and then follow the pointers to print the value of each list element.
  O(N) time

Find(k): find the position of element with value k
  Linear Search starting with the first element and follow the pointers until we get the value we are looking for or reach the end of the list.
  O(N) time

FindKth(k): find element at position k
  Start from the first element and follow the links until you reach the kth element.
  O(N) time

IsEmpty(): check if there are zero elements in the list.
  Return true if the head pointer is nullptr, indicating an empty list.
  O(1) time



### Operation Implementation

#### Traversal
Traversing a linked list means accessing all the nodes of the linked list
exactly once

Traversal begins at the head by assigning the head to a traversal pointer, we then access each data element. To continue to the next node, we update the traversal pointer by assigning to it the next list element's link. Traversal stops once we reach the null link value.

#### Searching
Searching a link list means performing a linear search through list elements to determine if a given value exists within the list.

Searching begins at the head by assigning the head to a traversal pointer, we then access each data element and compare the value to the given value. To continue to the next node, we update the traversal pointer by assigning to it the next list element's link. Searching stops once we have found an element with a value matching the given value indicating that the search value exists within the list, or we reach the null link value indicating that the search value does not exist within the list.

#### Insertion
Linked list insertion is the process by which new elements are added to the list.

Insertion has three basic cases:
  Insertion at the beginning of the list
  Insertion at the end of the list
  Insertion after a given node in the linked list

Each case begins with the creation of the new node to be included in the list.
The node's value is set to the a given insertion value
The node's link is set according to the insertion case

Insertion at the beginning of the list is performed by assigning the value of the head to the insertion node's link, indicating that it is now subsequent to the insertion node. The value of the list's head is then set to the address of the insertion node, indicating that it is now the beginning of the list.

Insertion at the end of the list is performed using a traversal of the list to determine which link is the tail, the node with a null link value. Once we have traversed to the tail, the address of the insertion node is assigned to the link value of the tail, then the link value of the insertion node is set to null, indicating that the insertion node is now the tail of the list.

Insertion after a given node is performed without a traversal because the insertion algorithm has been supplied with the node necessary to perform the insertion. The link value of the given node is assigned to the link value of the insertion node, indicating the node subsequent to the given node is now subsequent to the insertion node. The link value of the given node is then assigned to the address of the insertion node, indicating that the insertion node is now subsequent to the given node.



#### Deletion
Linked list deletion is the process by which elements are removed from the list.

Deletion has three basic cases:
  Deletion at the beginning of the list
  Deletion at the end of the list
  Deletion after a given node in the linked list

Deletion at the beginning of the list is performed by accessing the link value of the list's head and assigning it to the head.next value, indicating that the second node is now the first node in the list. The original head is the deallocated, indicating that it is no longer in the list.

Deletion at the end of the list is performed using a traversal of the list, however two traversal pointers are necessary. One traversal pointer to detect the list tail, and another to track the node directly previous to the tail. The traversal pointers are assigned the address value of head and head's link value. During list traversal, both are updated with the link value of their subsequent node such that one remains directly previous to the other. Traversal continues until the front most pointer detects the null link value indicating that the tail of the list had been found. The rear traversal pointer then indicates the second to last list element. This element's link value is set to null indicating that the second to last list element is now the tail of the list and the original tail of the list is deallocated.

Deletion after a given node is performed using a traversal with two pointers. One traversal pointer to detect the given node and another to track the node directly previous to it. The traversal pointers are assigned the address value of head and head's link value. During list traversal, both are updated with the link value of their subsequent node such that one remains directly previous to the other. Traversal continues until the front most pointer detects the given node indicating the node to be deleted. The rear traversal pointer indicates the node that will be altered during deletion. The link value of the rear node is set to the link value of the node to be deleted, indicating that the node that was once two node away is now directly subsequent. The node to be deleted is then deallocated and removed from the list.

If the list is doubly linked, we must also update n.next to set n.next.prev equal to n.prev. The important things to remember are
(1) to check for the null pointer
(2) to update the head or tail pointer as necessary.


#### Concatenation
Concatenation joins two individual linked lists

The concatenation of two given lists is performed by specifying an ordering on the two lists. We then perform a traversal to obtain the tail node of the list specified to come before the other. We then complete the concatenation by replacing the null link value of the list tail with the head value of the other. The head of the traversed list is then the head of the concatenated list.

#### Reversal
Reversal of a link list inverts the ordering of a linked lists members

The reversal of a linked list is performed using three pointer variables which will hold the addresses of the previous node, current node, and the next node. We assign the value of the head to current, and a null value to previous. The traversal iterates through the list performing link value reassignments for each node:
The value of next is set to the link value of current.
The link value of current is assigned the value of previous.
Previous is assigned the value of current.
The value of current is assigned next.

The list is traversed until the value of current is the null link value indicating that traversal has reached the end of the original list and all link values have been reversed.

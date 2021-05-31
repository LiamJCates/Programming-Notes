A simple implementation of a hash table uses an array of linked lists and a hash code function.

### Insert:
	compute the hey's hash code, resulting in either an int or a long

	Map the hash code to an index in the array
		hash(key) % array_length

	At any given index there is a linked list of keys and values. Note that two different keys could have the same hash code and thus index, as there may be an infinite number of key values and a finite number of hash table positions.

	If there is an empty linked list then no element has yet been stored at that index of the hash table, initialize the linked list with the a node for the key value pair.

	If there is a non-empty linked list at some index of the hash table, store the key, value pair as a new node at the head of the linked list.

### Search:
	compute the hey's hash code, resulting in either an int or a long

	Map the hash code to an index in the array
		hash(key) % array_length

	Search through the linked list for the key value to 

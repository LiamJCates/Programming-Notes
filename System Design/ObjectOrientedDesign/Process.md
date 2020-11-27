Before a program is written, we should have a fairly good idea of how to accomplish the task being implemented by this program. An outline of the program containing its requirements should precede the coding process. The larger and more complex the project, the more detailed the outline phase should be. The implementation details should be delayed to the later stages of the project. In particular, the details of the particular data structures to be used in the implementation should not be specified at the beginning.

We specify each task in terms of input and output, what the program should do, not how it should or could be done.

For example, if an item is needed to accomplish some task, the item is specified in terms of operations performed on it rather than in terms of its inner structure. These operations may act upon this item, for example, modifying it, searching for some details in it, or storing something in it.

After these operations are precisely specified, the implementation of the program may start.

The implementation decides which data structure should be used to make execution most efficient in terms of time and space.

An item specified in terms of operations is called an abstract data type. An abstract data type is not a part of a program, because a program written in a programming language requires the definition of a data structure, not just the operations on the data structure. However, an object oriented language (OOL) such as C++ has a direct link to abstract data types by implementing them as a class.

B+ Trees
A B+ tree is a variant of a B-tree which also stores sorted data like a
B-tree. The structure of a B-tree is the standard organization for indexes in
database systems. Multilevel indexing is done in a B+ tree; that is, leaf nodes
constitute a dense index, while non-leaf nodes constitute a sparse index.

A B+ tree is a slightly different data structure which allows sequential processing of data and stores all the data in the lowest level of the tree. A Btree can store both records and keys in its interior nodes, while a B+ tree
stores all the records in its leaf nodes and the keys in its interior nodes. In
a B+ tree, the leaf nodes are linked to one another like a linked list. A B+
tree is usually used to store big amounts of data which cannot be stored in
the primary memory. Hence, in a B+ tree the leaf nodes are stored in the
secondary storage, while the internal nodes are stored in the main memory.
In a B+ tree, all the internal nodes are called index nodes because they
store the index values. Similarly, all the external nodes are called data nodes
because they store the keys. A B+ tree is always balanced and is very efficient for the searching of data, as all the data is stored in the leaf nodes.
Various advantages of a B+ tree are as follows:
a. A B+ tree is always balanced, and the height of the tree always remains
less.
b. All the leaf nodes are linked to one another, which make it very efficient.
c. The leaf nodes are also linked to the nodes at an upper level; thus, it can
be easily used for a wide range of search queries.
d. The records can be fetched in equal number of disk access.
e. The records can be accessed either sequentially or randomly.
f. Searching of data becomes very simple, as all the information is stored
only in leaf nodes.
g. Similarly, deletion is also very simple, as it will only take place in the leaf nodes.

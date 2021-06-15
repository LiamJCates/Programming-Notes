Tree is a hierarchical data structure. The top element of a tree is called the root
of the tree. Except the root element, every element in a tree has a parent element,
and zero or more child elements. The tree is the most useful data structure when
you have hierarchical information to store.
There are many types of trees, for example, binary-tree, Red-black tree, AVL
tree, etc.

Binary Tree
A binary tree is a type of tree in which each node has at most two children (0, 1
or 2) which are referred as left child and right child.

Binary Search Trees (BST)
A binary search tree (BST) is a binary tree on which nodes are ordered in the following way:

1. The key in the left subtree is less than the key in its parent node.

2. The key in the right subtree is greater or equal the key in its parent node.

Binary Search Tree ADT Operations
Insert(k): Insert an element k into the tree.
Delete(k): Delete an element k from the tree.
Search(k): Search a particular value k into the tree if it is present or not.
FindMax(): Find the maximum value stored in the tree.
FindMin(): Find the minimum value stored in the tree.

The average Time Complexity of all the above operations on a binary search tree is O(log n), the case when the tree is balanced.

The worst-case Time Complexity will be O(n) when the tree is skewed.

A binary tree is skewed when tree is not balanced.
There are two types of skewed tree.
1. Right Skewed binary tree: A binary tree in which each node is having either only a right child or no child at all.
2. Left Skewed binary tree: A binary tree in which each node is having either only a left child or no child at all.

Balanced Binary search tree
There are few binary search tree, which always keeps themselves balanced. Most important among them are Red-Black Tree (RB-Tree) and AVL tree. The standard template library (STL) is implemented using this Red-Black Tree (RBTree).





Set implementation in C++ Collections
Set<> is a class which implements Set which means that it store only unique
elements. Set<> is implemented using a red-black balanced binary search tree in
C++ Collections. Since Set<> is implemented using a binary search tree its
elements are stored in sequential order.
Example 4.5
#include <set>
int main()
{
// Create a hash set.
std::set<std::string> ts;
// Add elements to the hash set.
ts.insert("India");
ts.insert("USA");
ts.insert("Brazile");
ts.insert("Canada");
ts.insert("UK");
ts.insert("China");
ts.insert("France");
ts.insert("Spain");
ts.insert("Italy");
for each (auto var in ts)
{
std::cout << var << " ";
}s
td::cout << std::endl;
std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) <<
std::endl;
std::cout << "Hash Table contains Russia : " << (std::find(ts.begin(), ts.end(), "Russia") != ts.end())
<< std::endl;ts.erase("USA");
for each (auto var in ts)
{
std::cout << var << " ";
}s
td::cout << std::endl;
std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) <<
std::endl;
return 0;
}

Output
Brazile Canada China France India Italy Spain UK USA
Hash Table contains USA : 1
Hash Table contains Russia : 0
Brazile Canada China France India Italy Spain UK
Hash Table contains USA : 0

Note:- TreeSet is implemented using a binary search tree so add, remove, and contains methods have logarithmic time complexity O(log (n)), where n is the number of elements in the set.








Map implementation in C++ Collection
A Map<> is an interface that maps keys to values. Also called a dictionary. A
Map<> is implemented using red-black balanced binary tree so the key value
pairs are stored in sorted order.
Example 4.6
#include <map>
int main()
{
// Create a hash map.
std::map<std::string, int> tm;
// Put elements into the map
tm["Mason"] = 55;
tm["Jacob"] = 77;
tm["Jacob"] = 77;
tm["William"] = 99;
tm["Alexander"] = 80;
tm["Michael"] = 50;
tm["Emma"] = 65;
tm["Olivia"] = 77;
tm["Sophia"] = 88;tm["Emily"] = 99;
tm["Isabella"] = 100;
std::cout << "Total number of students in class :: " << tm.size() << std::endl;
for (auto key : tm)
{
std::cout << key.first << " score marks :" << tm[key.first] << std::endl;
}a
uto temp = tm.find("Emma") != tm.end();
std::cout << "Emma present in class :: " << temp << std::endl;
auto result = tm.find("John") != tm.end();
std::cout << "John present in class :: " << result << std::endl;
return 0;
}

Output
Total number of students in class :: 10
Alexander score marks :80
Emily score marks :99
Emma score marks :65
Isabella score marks :100
Jacob score marks :77
Mason score marks :55
Michael score marks :50
Olivia score marks :77
Sophia score marks :88
William score marks :99
Emma present in class :: 1
John present in class :: 0













Dictionary / Symbol Table
A symbol table is a mapping between a string (key) and a value, which can be of
any data type. A value can be an integer such as occurrence count, dictionary
meaning of a word and so on.
Binary Search Tree (BST) for Strings
Binary Search Tree (BST) is the simplest way to implement symbol table.
Simple string compare function can be used to compare two strings. If all the
keys are random, and the tree is balanced. Then on an average key lookup can be
done in logarithmic time.
Hash-Table
The Hash-Table is another data structure, which can be used for symbol table
implementation. Below Hash-Table diagram, we can see the name of that person
is taken as the key, and their meaning is the value of the search. The first key is
converted into a hash code by passing it to appropriate hash function. Inside hash
function the size of Hash-Table is also passed, which is used to find the actual
index where values will be stored. Finally, the value that is meaning of name is
stored in the Hash-Table, or you can store a pointer to the string which store
meaning can be stored into the Hash-Table.Hash-Table has an excellent lookup of constant time.
Let us suppose we want to implement autocomplete the box feature of Google
search. When you type some string to search in google search, it proposes some
complete string even before you have done typing. BST cannot solve this
problem as related strings can be in both right and left subtree.
The Hash-Table is also not suited for this job. One cannot perform a partial
match or range query on a Hash-Table. Hash function transforms string to a
number. Moreover, a good hash function will give a distributed hash bode even
for partial string and there is no way to relate two strings in a Hash-Table.
Trie and Ternary Search tree are a special kind of tree, which solves partial
match, and range query problem well.
Trie
Trie is a tree, in which we store only one character at each node. This final key
value pair is stored in the leaves. Each node has K children, one for each
possible character. For simplicity purpose, let us consider that the character set is
26, corresponds to different characters of English alphabets.
Trie is an efficient data structure. Using Trie, we can search the key in O(M)
time. Where M is the maximum string length. Trie is also suitable for solving
partial match and range query problems.Ternary Search Trie/ Ternary Search Tree
Tries having a very good search performance of O(M) where M is the maximum
size of the search string. However, tries having very high space requirement.
Every node Trie contain pointers to multiple nodes, each pointer corresponds to
possible characters of the key. To avoid this high space requirement Ternary
Search Trie (TST) is used.
A TST avoid the heavy space requirement of the traditional Trie while still
keeping many of its advantages. In a TST, each node contains a character, an end
of key indicator, and three pointers. The three pointers are corresponding to
current char hold by the node (equal), characters less than and character greater
than.
The Time Complexity of ternary search tree operation is proportional to the
height of the ternary search tree. In the worst case, we need to traverse up to 3
times that many links. However, this case is rare.Therefore, TST is a very good solution for implementing Symbol Table, Partial
match and range query.

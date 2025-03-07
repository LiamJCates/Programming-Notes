**Associative data structures** are a class of data structures that store **key-value pairs**. In these structures, each element (value) is associated with a unique identifier (key), which allows efficient retrieval, insertion, and deletion based on the key. These data structures enable **fast lookups** and allow access to the associated value using its key.

### Key Characteristics:
- **Key-Value Pair**: Each element consists of a key and an associated value.
- **Efficient Lookup**: You can access a value using its key in constant or logarithmic time.
- **Uniqueness of Keys**: Each key is unique within the data structure, meaning it can only be associated with one value.

### Common Examples of Associative Data Structures:

#### 1. **Hash Table (Hash Map)**
   - **Description**: A **hash table** stores key-value pairs, where each key is hashed into a unique index in an array. The value is then stored at that index, allowing for fast retrieval based on the key.
   - **Time Complexity**: In the average case, operations (like insertion, lookup, and deletion) have a time complexity of **O(1)**, but can degrade to **O(n)** if there are many hash collisions.
   - **Example**: 
     - **Python**'s `dict` (dictionary) is implemented using a hash table.
     ```python
     my_dict = {"apple": 1, "banana": 2}
     print(my_dict["apple"])  # Output: 1
     ```

#### 2. **Dictionary (in general)**
   - **Description**: In many programming languages, the term **dictionary** is used to refer to an associative data structure that stores key-value pairs. It is implemented using a variety of underlying data structures like hash tables, balanced trees, or tries, depending on the language.
   - **Example**:
     - In **Python**, the `dict` type is a dictionary.
     ```python
     my_dict = {"name": "Alice", "age": 30}
     ```

#### 3. **Tree Map (or Ordered Map)**
   - **Description**: A **tree map** stores key-value pairs in a balanced binary search tree (BST). It maintains the keys in a specific order (usually in ascending order). The time complexity for operations like lookup, insertion, and deletion is **O(log n)** due to the underlying balanced tree structure.
   - **Example**:
     - **Java**'s `TreeMap` is an ordered associative structure that keeps the keys in sorted order.
     ```java
     TreeMap<String, Integer> treeMap = new TreeMap<>();
     treeMap.put("apple", 1);
     treeMap.put("banana", 2);
     System.out.println(treeMap.get("apple"));  // Output: 1
     ```

#### 4. **Associative Array (or Array Map)**
   - **Description**: An **associative array** is similar to a hash table in that it maps keys to values. In some programming languages, arrays or lists are used in a way that allows non-integer keys (such as strings) to be mapped to values, making them an associative array.
   - **Example**:
     - In **PHP**, associative arrays are used to map keys to values.
     ```php
     $arr = array("name" => "Alice", "age" => 25);
     echo $arr["name"];  // Output: Alice
     ```

#### 5. **Trie (Prefix Tree)**
   - **Description**: A **trie** (or **prefix tree**) is a tree-based data structure that stores strings in a way that allows efficient searching, insertion, and deletion. Each node represents a character of the string, and common prefixes are shared among strings. While it's not typically used for arbitrary key-value pairs, it's an associative structure when used to map keys (like strings) to values.
   - **Example**:
     - Tries are often used in applications like autocomplete systems or dictionaries.
     ```python
     class TrieNode:
         def __init__(self):
             self.children = {}
             self.is_end_of_word = False
     ```

#### 6. **Set (with Associative Properties)**
   - **Description**: While a **set** typically stores unique values (not key-value pairs), some data structures like **hash sets** and **sorted sets** maintain a form of association where values themselves act as keys. In **sorted sets**, for example, values are associated with a score.
   - **Example**:
     - **Python's `set`** is an unordered collection of unique elements, but doesn't store explicit key-value pairs.
     ```python
     my_set = {1, 2, 3}
     ```

### Summary of Common Associative Data Structures:
- **Hash Table (Hash Map)**: Stores key-value pairs using a hash function for fast access.
- **Dictionary**: A general term for key-value pair storage, usually implemented as a hash table or a tree map.
- **Tree Map (Ordered Map)**: Stores key-value pairs in a balanced tree (e.g., AVL or Red-Black Tree) and maintains an order of keys.
- **Associative Array**: A simple mapping of keys to values, often implemented using hash tables or arrays.
- **Trie**: A tree-based structure used to store strings or sequences, mapping each string or prefix to a value.
- **Set (with Associative Properties)**: Although sets don’t typically store key-value pairs, sorted sets and hash sets provide a type of association.

These associative structures provide efficient ways to map keys to values and are heavily used in applications such as caching, databases, indexing, and autocomplete systems.
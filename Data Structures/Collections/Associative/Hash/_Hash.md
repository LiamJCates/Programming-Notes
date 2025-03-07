A hash table is a data structure that maps keys to values for highly efficient lookup

Also known as an associative array, a hash map, and sometimes simply a hash.

A hash table is similar to an array in that it allows you to store a collection of values, but instead of accessing elements via sequential integers, the elements of an associative array are accessed using arbitrary data types such as strings, dates, or even classes you’ve created yourself.


Quick lookups are often really important. This is a common reason, to use arrays (O(1)-time lookups) over linked lists (O(n)-time lookups), for example.

In fact, many implementations of hash tables use arrays as an underlying data structure.

We can think of an array as a table with two columns:
	indexes:	sequential numbers starting at 0, {0, 1, 2, ...}
	elements:	values of a given type

In a standard array we don't get to pick the index values.

Suppose there is an array of size N and all elements to be stored in the array are represented by some key value, these key values are unique and also are in the range 0 to N-1. We can then store all the elements in the array based on the key where array index and keys are same.

In this case, we can access a given element in a constant time without the need for a linear search of O(n) comparisons. When we intend to search the array for a given element of key value x. We can access the desired value by using the key value as an index.

	int element = array[x];

This is called direct addressing:  
We store the key at the same address as the value of the key.
For a given key value, we must have an array large enough to have a corresponding address. 
For a collection of keys that have large differences between their key values much of the array is empty.

In the above example the key is required to be an integer from 0 to N-1 such that we can use the key to access the element at a given index.

What if we wanted to use any value as a key and still get quick lookups?
This is a process known as hashing.

In hashing, the address of the key is determined by using a mathematical function known as a hash function. The hash function will operate on a key of a given type to produce an integer between 0 and N-1 which is determined to be the address of the key in an N sized array.

The output of the hash function can be adjusted to produce integer values within some range. This is in contrast to the method of direct addressing, discussed above, which may result in a wide distribution of the keys throughout the memory, and hence lead to more wastage of space when compared with hashing.

By applying a hash function to the key value, a hash table provides constant time lookup similar to an array. The difference is, instead of accessing elements via sequential integers, the elements of an associative array are accessed using arbitrary data types such as strings, dates, or even user defined classes, processed via some hash function, to produce the array index where data is to be stored.

This data structure, which is implemented with an array and indexes values using a hashing function is known as an associative array, a hash map, a hash table, and sometimes simply a hash.



### **Basic Hash Table Data Structure Operations**  

A **hash table** (or **hash map**) is a data structure that provides efficient operations for storing and retrieving key-value pairs. It uses a **hash function** to compute an index where values are stored.  

---

## **1. Insert (Put)**
🔹 **Operation:** Add a new key-value pair to the hash table.  
🔹 **Steps:**  
1. Compute the hash value of the key using a **hash function**.  
2. Map the hash value to an **index** within the table size.  
3. Store the key-value pair at that index.  
4. If a collision occurs, handle it using **chaining** or **open addressing**.  

🔹 **Time Complexity:**  
- **Best case:** \( O(1) \) (if no collisions)  
- **Worst case:** \( O(n) \) (if all keys collide and chaining is used)  

🔹 **Example (Python - Dictionary Equivalent):**
```python
hash_table["name"] = "Alice"
```

---

## **2. Search (Get/Lookup)**
🔹 **Operation:** Retrieve the value associated with a given key.  
🔹 **Steps:**  
1. Compute the **hash value** of the key.  
2. Use the computed index to locate the value.  
3. If multiple values exist (due to collisions), search within the list of values stored at that index.  

🔹 **Time Complexity:**  
- **Best case:** \( O(1) \) (direct lookup)  
- **Worst case:** \( O(n) \) (if all keys hash to the same index)  

🔹 **Example:**
```python
value = hash_table["name"]  # Returns "Alice"
```

---

## **3. Delete (Remove)**
🔹 **Operation:** Remove a key-value pair from the hash table.  
🔹 **Steps:**  
1. Compute the **hash value** of the key.  
2. Find the key in the computed index.  
3. Remove the key-value pair.  
4. If **chaining** is used, remove only the specific key-value from the linked list.  
5. If **open addressing** is used, mark the slot as **deleted** instead of empty to maintain lookup efficiency.  

🔹 **Time Complexity:**  
- **Best case:** \( O(1) \) (if key is found quickly)  
- **Worst case:** \( O(n) \) (if a collision-based search is required)  

🔹 **Example:**
```python
del hash_table["name"]
```

---

## **4. Update**
🔹 **Operation:** Modify the value associated with a given key.  
🔹 **Steps:**  
1. Compute the **hash value** of the key.  
2. Locate the key in the hash table.  
3. Replace the old value with the new value.  

🔹 **Time Complexity:** \( O(1) \) in the best case, \( O(n) \) in the worst case.  

🔹 **Example:**
```python
hash_table["name"] = "Bob"  # Updates "Alice" to "Bob"
```

---

## **5. Handling Collisions**
Collisions occur when two keys hash to the **same index**. Common collision resolution strategies include:

🔹 **Chaining** (Linked List at each index)  
- Each bucket stores a linked list of key-value pairs.  
- **Time Complexity:** \( O(1) \) for insertion, \( O(n) \) in the worst case for search.  

🔹 **Open Addressing** (Linear/Quadratic Probing, Double Hashing)  
- If a collision occurs, the function searches for the **next available slot**.  
- **Time Complexity:** \( O(1) \) if table is sparsely populated, \( O(n) \) if filled.  

---

## **6. Resizing (Rehashing)**
🔹 **Operation:** Expand or shrink the hash table when the **load factor** (entries/size) crosses a threshold.  
🔹 **Steps:**  
1. Create a new hash table with **double the size**.  
2. Recompute hashes and insert existing entries into the new table.  
3. Free the old table.  

🔹 **Time Complexity:** \( O(n) \) (one-time expensive operation).  

🔹 **Example:**
```python
# Python's dict resizes automatically when needed
```

---

### **Summary Table**
| **Operation** | **Purpose** | **Time Complexity** |
|-------------|-----------|------------------|
| **Insert (Put)** | Add a key-value pair | \( O(1) \) avg, \( O(n) \) worst |
| **Search (Get)** | Retrieve value for a key | \( O(1) \) avg, \( O(n) \) worst |
| **Delete (Remove)** | Remove a key-value pair | \( O(1) \) avg, \( O(n) \) worst |
| **Update** | Modify an existing key’s value | \( O(1) \) avg, \( O(n) \) worst |
| **Resizing (Rehashing)** | Expand/shrink table | \( O(n) \) |

---

### **Conclusion**
Hash tables are **efficient** data structures for **quick lookups, insertions, and deletions**. However, they require **collision handling** and periodic **resizing** to maintain efficiency.  

Would you like a more detailed explanation of any operation? 🚀
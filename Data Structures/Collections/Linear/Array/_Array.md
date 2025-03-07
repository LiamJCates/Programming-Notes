# Arrays

An array is a contiguous collection of same typed data

Properties of arrays are its capacity, type, and size:
* Capacity is generally the number of elements that the array can potentially store
* Type specifies the type of elements stored by an array, the type of these items determines the memory space needed by each individual array member
* Array size is the size of an array in memory and it determined by: capacity * element memory size


An array is a sequence of elements where each element is identified by a number.
This number is known as an index
Accessing an element in an array is always a quick operation because the address of each element is obtained by a simple calculation:
offset = index × size of (element)
In other words, the offset of an element at a given index can be calculated by multiplying the index number by the size of the element.

The size of an array is normally declared before the array is used, which can be 
  Optimal when you know the size of array needed, and this size is not required to change
  Costly when you don’t know how the size required and the array must be resized



### **Properties of an Array Data Structure**  

An **array** is a fundamental data structure that stores elements in a **contiguous** memory block. 
It allows **fast access** via indexing and is widely used in algorithms, databases, and system programming.  

---

## **1. Fixed Size**
- **Definition:** The size of an array is defined at the time of creation and remains fixed.  
- **Implication:**  
  Generally, an array is not resizeable. To shrink or grow an given array, a new array must be made, and all array elements moved.

---

## **2. Contiguous Memory Allocation**
- **Definition:** All elements are stored **sequentially** in memory without gaps.  
- **Implication:**  
  - Enables **O(1) time complexity** for direct access using an index.  
  - Allows **fast iteration** since data is stored in adjacent memory locations.  

---

## **3. Homogeneous Elements**
- **Definition:** All elements in an array must be of the **same data type**.  
- **Implication:**  
  - Ensures **consistent memory allocation** for elements.  
  - Optimized for efficient CPU caching and memory access.  

---

## **4. Direct Access via Indexing (Random Access)**
- **Definition:** Any element in an array can be accessed in **constant time** using its index.  
- **Formula:**  
  - **Address of element at index \( i \) = Base Address + \( i \times \) Size of each element**
- **Time Complexity:** \( O(1) \)  
- **Example (Python):**  
  ```python
  arr = [10, 20, 30]
  print(arr[1])  # Output: 20 (Direct access in O(1) time)
  ```

---

## **5. Efficient Traversal**
- **Definition:** Since arrays are stored in contiguous memory, iterating through them is highly efficient.  
- **Time Complexity:** \( O(n) \)  
- **Example:**  
  ```python
  for num in arr:
      print(num)
  ```

---

## **6. Insertion & Deletion Complexity**
- **Insertion (at the end)** → \( O(1) \) (for dynamic arrays with available space).  
- **Insertion (at the middle or beginning)** → \( O(n) \) (requires shifting elements).  
- **Deletion (at the end)** → \( O(1) \) (does not require shifting elements).  
- **Deletion (from the middle or beginning)** → \( O(n) \) (requires shifting elements).  

---

## **8. Cache Friendliness**
- **Definition:** Since arrays are stored in contiguous memory, they take advantage of **CPU caching** for fast access.  
- **Implication:**  
  - Faster than linked lists for sequential access.  
  - Optimized for hardware-level memory fetching.  

---

## **9. No Built-in Insertion & Deletion Support**
- **Definition:** Unlike linked lists, arrays **do not have built-in methods** for inserting or deleting elements in the middle.  
- **Implication:**  
  - **Inserting in the middle requires shifting elements**, making it costly in terms of time complexity.  
  - **Deleting an element** leaves a gap, requiring shifting of elements to maintain order.  

---

### **Summary Table**
| **Property** | **Description** | **Time Complexity Impact** |
|-------------|---------------|----------------------------|
| **Fixed Size** | Cannot change size after creation (static arrays) | Limits flexibility |
| **Contiguous Memory** | Stored in a single block of memory | Fast access, efficient iteration |
| **Homogeneous Elements** | Same data type for all elements | Efficient memory usage |
| **Direct Access via Indexing** | Access elements using an index in O(1) | Random access is fast |
| **Efficient Traversal** | Iterating is optimized due to contiguous memory | \( O(n) \) |
| **Insertion & Deletion Complexity** | Inserting/deleting requires shifting elements | \( O(n) \) for middle/beginning |
| **Fixed Memory Size** | Cannot grow or shrink dynamically (except dynamic arrays) | Requires careful memory management |
| **Cache Friendliness** | Optimized for CPU cache due to contiguous memory | Improves performance |
| **No Built-in Insertion/Deletion** | Lacks methods like linked lists | Manual shifting required |

---

### **Conclusion**
Arrays are **fast, memory-efficient**, and provide **constant-time indexing** but suffer from **high insertion/deletion costs** in the middle. They are ideal when **random access is needed** but not the best choice for frequent modifications.  






### **Basic Array Data Structure Operations**  

Operations
  Insertion − Adds an element at the given index.
  Deletion − Deletes an element at the given index.
  Update − Updates an element at the given index.
  Traverse − print all the array elements one by one.
  Search − Searches an element using the given index or by the value.
  Sorting − enforce element order
  Merge - Combining arrays



---

## **1. Insert (Append)**
🔹 **Operation:** Add an element to the array.  
🔹 **Types:**
   - **Appending (End Insertion)** → Adds to the end (efficient for dynamic arrays).
   - **Insertion at a Specific Index** → Inserts at any position, shifting elements if needed.

🔹 **Time Complexity:**
   - **Appending:** \( O(1) \) (amortized for dynamic arrays)
   - **Insertion at a specific index:** \( O(n) \) (shifts elements)

🔹 **Example (Python):**
```python
arr = [1, 2, 3]
arr.append(4)  # [1, 2, 3, 4]
arr.insert(1, 99)  # [1, 99, 2, 3, 4]
```

---

## **2. Delete (Remove)**
🔹 **Operation:** Remove an element by value or index.  
🔹 **Steps:**  
1. Find the index of the element (if not known).  
2. Remove it and shift elements (if necessary).  

🔹 **Time Complexity:**
   - **Deleting last element:** \( O(1) \)
   - **Deleting from the middle:** \( O(n) \) (shifting required)

🔹 **Example:**
```python
arr.pop()  # Removes last element (O(1))
arr.pop(1)  # Removes element at index 1 (O(n))
arr.remove(2)  # Removes first occurrence of value 2 (O(n))
```

---

## **3. Search (Lookup)**
🔹 **Operation:** Find if an element exists in the array.  
🔹 **Types:**
   - **Direct Index Lookup** (for known index) → \( O(1) \)
   - **Linear Search** (for unknown index) → \( O(n) \)
   - **Binary Search** (sorted arrays) → \( O(\log n) \)

🔹 **Example:**
```python
arr = [10, 20, 30, 40]
x = arr[2]  # Accessing index 2 (O(1))
if 20 in arr:  # Checking existence (O(n))
    print("Found 20")
```

---

## **4. Update (Modify an Element)**
🔹 **Operation:** Change an element’s value at a given index.  
🔹 **Time Complexity:** \( O(1) \) (direct index access)  

🔹 **Example:**
```python
arr[1] = 50  # Modify element at index 1
```

---

## **5. Traversal (Iterating Through Elements)**
🔹 **Operation:** Process each element in the array (e.g., printing, summing).  
🔹 **Time Complexity:** \( O(n) \)  

🔹 **Example:**
```python
for num in arr:
    print(num)
```

---

## **6. Sorting**
🔹 **Operation:** Arrange elements in ascending/descending order.  
🔹 **Common Sorting Algorithms:**
   - **Bubble Sort, Selection Sort** → \( O(n^2) \)
   - **Merge Sort, Quick Sort** → \( O(n \log n) \ )
   - **Timsort (Python's `sorted()`)** → \( O(n \log n) \)

🔹 **Example:**
```python
arr.sort()  # Sorts in-place (O(n log n))
sorted_arr = sorted(arr)  # Returns a new sorted array
```

---

## **7. Merging Two Arrays**
🔹 **Operation:** Combine two arrays into one.  
🔹 **Time Complexity:** \( O(m + n) \) (where \( m \) and \( n \) are sizes of the arrays)  

🔹 **Example:**
```python
arr1 = [1, 3, 5]
arr2 = [2, 4, 6]
merged = arr1 + arr2  # [1, 3, 5, 2, 4, 6]
```

---

## **Summary Table**
| **Operation** | **Purpose** | **Time Complexity** |
|--------------|------------|---------------------|
| **Insert (Append)** | Add element to the array | \( O(1) \) (end), \( O(n) \) (middle) |
| **Delete (Remove)** | Remove an element | \( O(1) \) (end), \( O(n) \) (middle) |
| **Search (Lookup)** | Find element by value | \( O(n) \) (unsorted), \( O(\log n) \) (sorted) |
| **Update** | Modify element at index | \( O(1) \) |
| **Traversal** | Visit each element | \( O(n) \) |
| **Sorting** | Arrange elements in order | \( O(n \log n) \) |
| **Merging** | Combine two arrays | \( O(m + n) \) |

---

### **Conclusion**
Arrays provide **fast lookups** but are **slow for insertions/deletions in the middle** due to shifting. They are **ideal** when random access is required.  

Would you like a deeper explanation of a specific operation? 🚀
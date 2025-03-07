### ** Sparse Arrays**

A **sparse array** is a type of array where most of the elements have default or "empty" values (e.g., zeros or nulls). Instead of allocating space for every element, a sparse array only stores non-default values and their indices.

#### Key Characteristics:
- **Storage Efficiency**: Only stores non-default values, saving memory when dealing with large arrays where many elements are unused or set to a default value.
- **Index Mapping**: Often implemented using a map (e.g., hash table) that maps indices to values.

#### Use Cases:
- Storing large matrices or grids with many zero values (e.g., for scientific computing or image processing).
- Representing large sparse datasets (e.g., large graph representations, document-term matrices in natural language processing).

#### Example:
In Python, a sparse array could be represented using a dictionary:
```python
sparse_array = {1: 10, 4: 15, 7: 20}  # Only stores non-default values at indices 1, 4, and 7
```

---
In associative containers, elements are inserted in a pre-defined order—for example, as sorted ascending. Unordered associative containers are also available. The associative containers can be grouped into two subsets: maps and sets.

Associative containers allow for very fast element search. Sequential containers
have some natural ordering that allows you to iterate from the beginning of
the container to the end in a well­-specified order. Associative containers are
a bit different. This container family splits along three axes:
•	 Whether elements contain keys (a set) or key-­value pairs (a map)
•	 Whether elements are ordered
•	 Whether keys are unique

A map, sometimes referred to as a dictionary, consists of a key/value pair. The key is used to order the sequence, and the value is associated with that key. For example, a map might contain keys that represent every unique word in a text and corresponding values that represent the number of times that each word appears in the text. The unordered version of map is unordered_map. For more information, see map Class and unordered_map Class.

A set is just an ascending container of unique elements—the value is also the key. The unordered version of set is unordered_set. For more information, see set Class and unordered_set Class.

Both map and set only allow one instance of a key or element to be inserted into the container. If multiple instances of elements are required, use multimap or multiset. The unordered versions are unordered_multimap and unordered_multiset. For more information, see multimap Class, unordered_multimap Class, multiset Class, and unordered_multiset Class.

Ordered maps and sets support bi-directional iterators, and their unordered counterparts support forward iterators.


The associative containers supplied by STL are
  std::set — Stores unique values sorted on insertion in a container featuring logarithmic complexity

  std::unordered_set — Stores unique values sorted on insertion in a container featuring near constant complexity. Available starting C++11

  std::map — Stores key-value pairs sorted by their unique keys in a container with logarithmic complexity

  std::unordered_map — Stores key-value pairs sorted by their unique keys in a container with near constant complexity. Available starting C++11

  std::multiset — Akin to a set. Additionally, supports the ability to store multiple items having the same value; that is, the value doesn’t need to be unique

  std::unordered_multiset — Akin to a unordered_set. Additionally, supports
  the ability to store multiple items having the same value; that is, the value doesn’t need to be unique. Available starting C++11.

  std::multimap — Akin to a map. Additionally, supports the ability to store
  key-value pairs where keys don’t need to be unique.

  std::unordered_multimap — Akin to a unordered_map. Additionally, supports
  the ability to store key-value pairs where keys don’t need to be unique. Available starting C++11

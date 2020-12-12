Unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys.

In an unordered_map, the key value is generally used to uniquely identify the element, while the mapped value is an object with the content associated to this key. Types of key and mapped value may differ.

Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

unordered_map containers are faster than map containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements.

Unordered maps implement the direct access operator (operator[]) which allows for direct access of the mapped value using its key value as argument.

Member functions
(constructor) | Construct unordered_map
(destructor) | Destroy unordered map
operator= | Assign content

Capacity
empty | Test whether container is empty
size | Return container size
max_size | Return maximum size

Iterators
begin | Return iterator to beginning
end | Return iterator to end
cbegin | Return const_iterator to beginning
cend | Return const_iterator to end

Element access
operator[] | Access element
at | Access element

Element lookup
find | Get iterator to element
count | Count elements with a specific key
equal_range | Get range of elements with specific key

Modifiers
emplace | Construct and insert element
emplace_hint | Construct and insert element with hint
insert | Insert elements
erase | Erase elements
clear | Clear content
swap | Swap content

Buckets
bucket_count | Return number of buckets
max_bucket_count | Return maximum number of buckets
bucket_size | Return bucket size (public member type)
bucket | Locate element's bucket

Hash policy
load_factor | Return load factor
max_load_factor | Get or set maximum load factor
rehash | Set number of buckets
reserve | Request a capacity change

Observers
hash_function | Get hash function (public member type)
key_eq | Get key equivalence predicate (public member type)
get_allocator | Get allocator



a map is known as an associative array or a dictionary. It is implemented as a balanced binary tree.
The standard-library map is a container of pairs of values optimized for lookup. We can use the
same initializer as for vector and list


When indexed by a value of its first type (called the key), a map returns the corresponding value of
the second type (called the value or the mapped type).

If a key isn’t found, it is entered into the map with a default value for its value.

To avoid this use find() and insert() instead of [ ]


Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:


typedef pair<const Key, T> value_type;

Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).

Maps are typically implemented as binary search trees.




(constructor) | Construct map
(destructor) | Map destructor
operator= | Copy container content

## Iterators
| Expression | Description|
|------------|------------|
| map.begin() | Return iterator to beginning |
| map.end() | Return iterator to end |
| map.rbegin() | Return reverse iterator to reverse beginning |
| map.rend() | Return reverse iterator to reverse end |
| map.cbegin() | Return const_iterator to beginning |
| map.cend() | Return const_iterator to end |
| map.crbegin() | Return const_reverse_iterator to reverse beginning |
| map.crend() | Return const_reverse_iterator to reverse end |

## Capacity

| Expression | Description|
|------------|------------|
empty | Test whether container is empty
size | Return container size
max_size | Return maximum size

## Element access

| Expression | Description|
|------------|------------|
operator[] | Access element
at | Access element

## Modifiers

| Expression | Description|
|------------|------------| |
| map.insert() | Insert elements |
| map.erase() | Erase elements |
| map.swap() | Swap content |
| map.clear() | Clear content |
| map.emplace() | Construct and insert element |
| map.emplace_hint() | Construct and insert element with hint |

Observers:
key_comp | Return key comparison object
value_comp | Return value comparison object

Operations:
find | Get iterator to element
count | Count elements with a specific key
lower_bound | Return iterator to lower bound
upper_bound | Return iterator to upper bound
equal_range | Get range of equal elements

Allocator:
get_allocator | Get allocator

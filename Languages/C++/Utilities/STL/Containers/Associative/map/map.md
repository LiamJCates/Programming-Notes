A map is known as an associative array or a dictionary.

The standard-library map is a container of pairs of values optimized for lookup, implemented as a balanced binary search tree.  

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

When indexed by a value of its first type (called the key), a map returns the corresponding value of the second type (called the value or the mapped type).
Within a map, keys are unique.

Naturally, your program needs the <map> header:
	#include <map>

The map datatype is called std::map. To define a map, you need to specify the key and value type within angle brackets (separated by a comma), as shown in the
following example:

std::map<K, V> mapIdentifier;

You can use almost any type as the key and value types, even another map.
If you do not initialize a map, it starts out empty.

In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key.

Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

The simplest way to use a map is to look up values using square brackets. The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).

V valueIdenfier = mapIdentifier[keyValue];

If the key is not present in the map, it is added with a zero initialed value.


### Accessing Key and Value
The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:

typedef pair<const Key, T> value_type;

Each map element is a single object that contains the key and the value. The key is called first, and the value is called second. Use a dot (.) operator to access a member of the pair.

The two parts of the map element’s value are not named key and value, because the std::pair type is a generic part of the c++ library. The library uses this type in several different places. Thus, the names of the parts of a pair are also generic and not tied specifically to map.

When iterating over the map, you know you will use the .first and .second members, so using auto for the key/value pairs helps keep the code readable. Let the compiler worry about the details.

For example, the best way to print the map is to use a range-based for loop to iterate over the map.

for (auto element : mapIdentifier)
	std::cout << element.first << '\t' << element.second << '\n';




### Searching in Maps
A map stores its data in sorted order by key. Searching in a map, therefore, is pretty fast (logarithmic time).
Because a map keeps its keys in order, you can use any of the binary search algorithms, but even better is to
use map’s member functions. These member functions have the same names as the standard algorithms
but can take advantage of their knowledge of a map’s internal structure. The member functions also run in
logarithmic time, but with less overhead than the standard algorithms.

For example, suppose you want to know the value associated with a specific key, you can call the find(keyIdentifier) to see if the key is in the
map, and if so, get an iterator that points to its key/value pair. If the key is not in the map, find() returns the end() iterator.

If the key is present, you can extract the value from the pair pointed to by the iterator. You have to use an arrow (->) to access a member from an iterator.

The official type is std::map<K, V>::iterator

You can
see why I prefer auto in this case. But there’s another solution that preserves the explicit use of a type and
maintains a sense of brevity: type synonyms



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

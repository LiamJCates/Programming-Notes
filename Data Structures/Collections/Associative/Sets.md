Set Types
Set
Ordered Set
Bag (Multiset)



Bag (Multiset)
Generalization of the notion of a set collection allowing the indiscriminate (nonunique) item insertion and order, removing items unsupported

Unordered
Nonunique

In mathematics, a multiset (aka bag or mset) is a modification of the concept of a set
unlike a set, bags allows for multiple instances for each of its elements.
The number of instances, given for each element is called the multiplicity of this element in the multiset.
As a consequence, an infinite number of multisets exist, which contain only elements a and b, but vary by the multiplicity of their elements:

    The multiset {a, b} contains only elements a and b, each having multiplicity 1.
    In multiset {a, a, b}, the element a has multiplicity 2, and b has multiplicity 1.

As with sets, and in contrast to tuples, order does not matter in discriminating multisets, so {a, a, b} and {a, b, a} denote the same multiset.


A bag is a collection where removing items is not supported—its purpose is to provide clients with the ability to collect items and then to iterate through the collected items (the client can also test if a bag is empty and find its number of items). The order of iteration is unspecified and should be immaterial to the client.

public class Bag<Item> implements Iterable<Item>
Bag()                 //create an empty bag            O(1)
void add(Item item)         //add an item                O(1)
boolean isEmpty()         //is the bag empty?            O(1)
int size()             //number of items in the bag        O(1)

With our Bag API, a client can add items to a bag and process them all with a foreach statement whenever needed.

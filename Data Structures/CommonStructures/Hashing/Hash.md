Quick lookups are often really important. For that reason, we tend to use arrays (O(1)-time lookups) much more often than linked lists (O(i)-time lookups).

We can think of an array as a table with two columns...except you don't really get to pick the values in one column (the indices)—they're always 0, 1, 2, 3, etc.

But what if we wanted to put any value in that column and still get quick lookups?

A hash table is similar to an array in that it allows you to store a collection of values, but instead of accessing elements via sequential integers, the elements of an associative array are accessed using arbitrary data types such as strings, dates, or even classes you’ve created yourself.

known as an associative array, a hash map, a hash table, and sometimes simply a hash

Hash tables are implemented with a hash function

An idea hashing function converts any value into an evenly distributed member of a predetermined set.
The hash table uses the hashing function to then convert any value into an array index

A key into an index of the element where the corresponding value is stored.
Hash functions typically produce a number that is the result of a fixed set of calculations based on the input key.

You can think of this number as roughly equivalent to an array index, except that you are not exposed to these numbers as you are to array indexes. They are calculated and handled behind the scenes by the framework. Keys in a hash table must be unique; you cannot store more than one of each key. Values can be duplicated as many times as you like.

While keys may be arbitrarily large, the resulting index value will always be a relatively small size (otherwise it wouldn’t be suitable for use as an index). Every now and then a hash function might calculate the same index for two different keys. This event is known as a hash collision. When this happens, the hash function resolves the collision by either recalculating the hash with a different set of calculations (rehashing) or by storing the element in a secondary data structure using a method known as chaining. Again, this detail is not normally exposed to the programmer using the hash table.

Hash functions run in constant time, which means that hash tables are quick to store and retrieve elements.

Note that our quick lookups are only in one direction—we can quickly get the value for a given key, but the only way to get the key for a given value is to walk through all the values and keys.
Same thing with arrays—we can quickly look up the value at a given index, but the only way to figure out the index for a given value is to walk through the whole array.

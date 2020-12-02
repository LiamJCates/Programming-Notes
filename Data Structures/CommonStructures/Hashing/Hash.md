Quick lookups are often really important. For that reason, we tend to use arrays (O(1)-time lookups) much more often than linked lists (O(i)-time lookups).

We can think of an array as a table with two columns...except you don't really get to pick the values in one column (the indices)—they're always 0, 1, 2, 3, etc.

Suppose there is an array of size N and all the keys to
be stored in the array are unique and also are in the range 0 to N-1. Now,
we will store all the records in the array based on the key where array index
and keys are same. Thus, in that case we can access the records in a constant time along with no key comparisons involved in it.

This is called direct addressing:  we store the key at the same address as the value of the key

But what if we wanted to put any value in that column and still get quick lookups?

in hashing the address of the key is determined by using a mathematical function known as a hash function. The hash function will operate on the key to
determine the address of the key.

Direct addressing may result in a more
random distribution of the key throughout the memory, and hence sometimes leads to more wastage of space when compared with hashing.


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



Hash Functions
A hash function is a mathematical formula which, when applied to a
key, produces an integer which is used as an index to find a key in the hash
table.
Characteristics of the Hash Function
There are four main characteristics of hash functions which are:
1. The hash function uses all the input data.
2. The hash function must generate different hash values.
3. The hash value is fully determined by the data being hashed.
4. The hash function must distribute the keys uniformly across the entire
hash table.



Different Types of Hash Functions

Division Method
In the division method, a key k is mapped into one
of the m slots by taking the remainder of k divided by m. In simple terms,
we can say that this method divides an integer, say x, by m and then uses
the remainder so obtained. It is the simplest method of hashing. The
hash function is given by:

hash(k) = k mod m

the division
method works very fast, as it requires only a single division operation. Although
this method is good for any value of m, consider that if m is an even number
then h(k) is even when the value of k is even, and similarly h(k) is odd when the
value of k is odd. Therefore, if the even and odd keys are almost equal, then
there will be no problem. But if there is a larger number of even keys, then the
division method is not good, as it will not distribute the keys uniformly in the
hash table. Also, we avoid certain values of m; that is, m should not be a power
of 2, because if h(k) = k mod 2x, then h(k) will extract the lowest x bits of k. The
main drawback of the division method is that many consecutive keys map to
consecutive hash values, which means that consecutive array locations will be
occupied, and hence there will be an effect on the performance.




Mid Square Method
In the mid square method, we will calculate the
square of the given key. After getting the number, we will extract some
digits from the middle of that number as an address.

For Example, if key k = 5025, then k^2 = 25250625. Thus, h(5025) = 50.

This method works very well, as all the digits of the key contribute to
the output; that is, all the digits contribute in producing the middle digits. In addition, the same r digits must be chosen from all the keys in this
method.





Folding Method
In the folding method, we will break the key into
pieces such that each piece has the same number of digits except the last
one, which may have fewer digits as compared to the other pieces. Now,
these individual pieces are added. We will ignore the carry if it exists.
Hence, the hash value is formed.
For example, if m = 100 and the key k = 12345678, then the indices
will vary from 0 to 99, and thus each piece of the key must have two digits.
Therefore, the given key will be broken into four pieces, that is, 12, 34, 56,
and 78. Now we will add all these, that is, 12 + 34 + 56 + 78 = 180. Thus,
the hash value will be 80 (ignore the last carry).

### Hash Function

An ideal hashing function converts any value, known as the key of some element, into an evenly distributed member of a predetermined set, known as the hash of the key. This hash then represents the index of the key value in an index.

The hashes produced by the hash function typically produce a number that is the result of a fixed set of calculations based on the input key.

You can think of this number as roughly equivalent to an array index, except that you are not exposed to these numbers as you are to array indexes. They are calculated and handled behind the scenes by the data structures implementation.


Keys in a hash table must be unique; you cannot store more than one of each key.
Values can be duplicated as many times as you like.

While keys may be arbitrarily large, the resulting hash or index value will always be a relatively small size (otherwise it wouldn’t be suitable for use as an index).

Every now and then a hash function might calculate the same index for two different keys. This event is known as a hash collision. When this happens, the hash function resolves the collision by either recalculating the hash with a different set of calculations (rehashing) or by storing the element in a secondary data structure using a method known as chaining. Again, this detail is not normally exposed to the programmer using the hash table.

Hash functions run in constant time, which means that hash tables are quick to store and retrieve elements.

Note that our quick lookups are only in one direction — we can quickly get the value for a given key, but the only way to get the key for a given value is to walk through all the values and keys.

This property is the same for a standard array — we can quickly look up the value at a given index, but the only way to figure out the index for a given value is to walk through the whole array.

A hash function is a mathematical formula which, when applied to a
key, produces an integer which is used as an index to find a key in the hash
table.

### Hash Function Characteristics

There are four main characteristics of hash functions which are:
1. The hash function uses all the input data.
2. The hash function must generate different hash values.
3. The hash value is fully determined by the data being hashed.
4. The hash function must distribute the keys uniformly across the entire
hash table.



#### Different Types of Hash Functions

##### Division Method
In the division method, a key k is mapped into one
of the m slots by taking the remainder of k divided by m. In simple terms,
we can say that this method divides an integer, say x, by m and then uses
the remainder so obtained. It is the simplest method of hashing. The
hash function is given by:

hash(k) = k mod m

the division method works very fast, as it requires only a single division operation. Although this method is good for any value of m, consider that if m is an even number then h(k) is even when the value of k is even, and similarly h(k) is odd when the value of k is odd. Therefore, if the even and odd keys are almost equal, then there will be no problem. But if there is a larger number of even keys, then the division method is not good, as it will not distribute the keys uniformly in the hash table.

Also, we avoid certain values of m; that is, m should not be a power of 2, because if h(k) = k mod 2^x, then h(k) will extract the lowest x bits of k.

The main drawback of the division method is that many consecutive keys map to consecutive hash values, which means that consecutive array locations will be occupied, and hence there will be an effect on the performance.




##### Mid Square Method
In the mid square method, we will calculate the square of the given key. After getting the number, we will extract some digits from the middle of that number as an address.

For Example, if key k = 5025, then k^2 = 25250625. Thus, h(5025) = 50.

This method works very well, as all the digits of the key contribute to
the output; that is, all the digits contribute in producing the middle digits. In addition, the same r digits must be chosen from all the keys in this
method.




##### Folding Method
In the folding method, we will break the key into pieces such that each piece has the same number of digits. when using this method we decide whether we want to break the key up from right to left or left to right then be aware that one piece may have fewer digits as compared to the others.
	from right to left the first pair might have less digits
	from left to right the last pair might have less digits



These individual pieces are added. Then the higher order digits are truncated to form a number with the same number of digits as the array size.
Hence, the hash value is formed.

For example, if table size m = 100 and the key k = 123456789, then the indices
will vary from 0 to 99, and thus each piece of the key must have two digits.

Therefore the key will be broken into five pieces:
	From left to right 12, 34, 56, 78, 9
	From right to left 1, 23, 45, 67, 89

We will then add the pieces and truncate the higher order digits of the result.
12 + 34 + 56 + 78 +  9 = 189 (truncate) = 89
1  + 23 + 45 + 67 + 89 = 225 (truncate) = 25

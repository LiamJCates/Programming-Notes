## Parameter Passing Example

To see the reasons why call-by-value is not sufficient as the only parameter-passing mechanism in C++, consider the three function declarations below:

	double average( double a, double b ); // returns average of a and b
	void swap( double a, double b ); // swaps a and b in the caller's environment
	int randomItem( vector<int> arr ); // returns random arr item

average illustrates an ideal use of call-by-value:

	double z = average(x, y);

call-by-value copies x into a, y into b, and then executes the code. Presuming that x and y are local variables inaccessible to average, it is guaranteed that when average returns, x and y are unchanged, which is a very desirable property.

However, this desirable property is exactly why call-by-value cannot work for swap. If we make the call:

	swap( x, y );

then call-by-value guarantees that regardless of how swap is implemented, x and y will remain unchanged.

What we need, instead, is to declare that a and b are references:

	void swap( double & a, double & b );

With this signature, a is an alias for x, and b is a alias for y. Changes to a and b in the implementation of swap are thus changes to x and y in the caller's environment.

This form of parameter passing has always been known as call-by-reference in C++. In C++11, this is more technically call-by-lvalue-reference.

The second problem with call-by-value is illustrated in randomItem. This function intends to return a random item from the vector arr; in principle, this is a quick operation consisting of the generation of a “random” number between 0 and arr.size()-1, inclusive, in order to determine an array index and the returning of the item at this randomly chosen array index.

But using call-by-value as the parameter-passing mechanism forces the copy of the vector vec in the call randomItem(vec). This is a tremendously expensive operation compared to the cost of computing and returning a randomly chosen array index and is completely unnecessary. Normally, the only reason to make a copy is to make changes to the copy while preserving the original. But randomItem doesn’t intend to make any changes at all; it is just viewing arr.

Thus, we can avoid the copy but achieve the same semantics by declaring that arr is a constant reference to vec; as a result, arr is an aliase for vec, with no copy, but since it is a const, it cannot be modified:

	int randomItem( const vector<int> & arr );

This essentially provides the same viewable behavior as call-by-value.

This form of parameter passing is known as call-by-reference-to-a-constant in C++, but as that is overly verbose and the const precedes the &, it is also known by the simpler terminology of call-by-constant reference.

Put another way,
1. Call-by-value is appropriate for small objects that should not be altered by the function.
2. Call-by-constant-reference is appropriate for large objects that should not be altered by the function and are expensive to copy.
3. Call-by-reference is appropriate for all objects that may be altered by the function.

Compute whether or not an unsigned number is a power of two


Solution
Suppose that the number is nonzero.
If it is a power of two, than the only bit set is in position i.

In this case we subtract 1, so all the bits at the left of will be unset.

Therefore a positive number is a power of 2 if and only if n & (n-1) is 0.

Note that this check only works if n > 0


Code
bool isPowerOfTwo(unsigned n)
{
	return n && (!(n & (n - 1)));
}

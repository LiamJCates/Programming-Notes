Given an unsigned int, swap the bits in odd and even positions

Solution
We seek to swap the bits in position 2n with those in 2n+1
for n>0 where n is there index of a binary digit

Assume that an unsigned int is 32bits

To select all the even bits we can AND with bitmask 0xAAAAAAAAAA,
 	A 32 bit number with even bits set (0xA is decimal 10, 1010 binary)

To select the odd bits we can AND with bitmask 0×55555555,
	 	A 32 bit number with odd bits set (0x5 is decimal5, 0101 in binary).

Then we need to shift left (respectively right) of one position and OR the two intermediate results.

Code

unsigned int swapBits(unsigned int x)
{
	unsigned int evenBits = x & 0xAAAAAAAA;
	unsigned int oddBits = x & 0x55555555;

	evenBits >>= 1;
	oddBits <<= 1;
	return (evenBits | oddBits);
}

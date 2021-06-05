/*
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

Some considerations:

	The size of the character set
	If whitespace and punctuation are considered



Strings with even length must have even character counts.
Strings with an odd length must have only a single odd character count.
Since
*/


#include <string>
#include <map>

using namespace std;

bool palindromePermutation(string s)
{
	map<char, int> m;
	for(char c : s)
	{
			if(!m[c]) m[c] = 0;
			++m[c];
	}
	bool odd = false;
	for(auto p : m)
	{
		if(p.second%2)
			if(odd) return false;
			else odd = true;
	}
	return true;
}

//While we can't optimize the big O time as any algorithm will always have to look through the entire string, however we can keep a running sum of odd integers so that we do not have to iterate through the map after we construct it
bool palindromePermutation(string s)
{
	map<char, int> m;
	int oddCount = 0;
	for(char c : s)
	{
        if(!m[c]) m[c] = 0;
        ++m[c];
        oddCount += m[c]%2 ? 1 : -1;
	}

	return oddCount <= 1;
}

/*
We can use a single integer (as a bit vector). When we see a letter, we map it to an integer between O and 26 (assuming an English alphabet). We then toggle the bit at that value. At the end of the iteration, we check that at most one bit in the integer is set to 1 by subtracting

Picture an integer like 00010000.

We could of course shift the integer repeatedly to check that there's only a single 1.

Alternatively, if we subtract 1 from the number, we'll get 00001111. What's notable about this is that there is no overlap between the numbers (as opposed to say 00101000, which, when we subtract 1
from, we get 00100111.)

We can check to see that a number has exactly one 1 because if we subtract 1
from it and then AND it with the new number, we should get 0.

00010000 - 1 = 00001111
00010000 & 00001111 = 0
*/
bool palindromePermutation(string s)
{
	int b = 0;
	for(char c : s)
		b ^= (1 << (c-'a'));

	return (b & (b - 1)) == 0;
}

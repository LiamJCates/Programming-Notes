/*
One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

EXAMPLE
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false

There is a "brute force" algorithm to do this. We could check all possible strings that are one edit away by testing the removal of each character (and comparing), testing the replacement of each character (and comparing), and then testing the insertion of each possible character (and comparing).
That would be too slow, so let's not bother with implementing it.


It's helpful to think about the "meaning" of each of these operations.
What does it mean for two strings to be one insertion, replacement, or removal away from each other?

Replacement: Consider two strings, such as bale and pale, that are one replacement away. Yes, that does mean that you could replace a character in bale to make pale. But more precisely, it means that they are different only in one place.

• Insertion: The strings apple and aple are one insertion away. This means that if you compared the strings, they would be identical-except for a shift at some point in the strings.

• Removal: The strings apple and aple are also one removal away, since removal is just the inverse of insertion.

We can go ahead and implement this algorithm now. We'll merge the insertion and removal check into one step, and check the replacement step separately.

*/

#include <string>

using namespace std;

bool oneChange(std::string a, std::string b)
{
	if(a.length() == b.length())
}

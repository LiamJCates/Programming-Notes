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




bool oneEditAway(std::string first, std::string second)
{
	if (first.length() == second.length())
	{
		return oneEditReplace(first, second);
	}
	else if (first.length() + 1 == second.length())
	{
		return oneEditinsert(first, second);
	}
	else if (first.length() - 1 == second.length())
	{
		return oneEditinsert(second, first);
	}
	return false;
}

bool oneEditReplace(std::string sl, std::string s2)
{
	bool foundDifference = false;
	for (int i = 0; i < sl.length(); i++)
	{
		if (sl[i] != s2[i])
		{
			if (foundDifference) return false;
			foundDifference = true;
		}
	}
	return true;
}

/* Check if you can insert a character into sl to make s2. */
bool oneEditinsert(std::string sl, std::string s2)
{
	int idxl = 0;
	int idx2 = 0;
	while (idx2 < s2.length() && idxl < sl.length())
	{
		if (sl[idxl] != s2[idx2])
		{
			if (idxl != idx2)
			{
				return false;
			}
			idx2++;
		}
		else
		{
			idxl++;
			idx2++;
		}
	}
	return true;
}






/*
We might notice that the code for oneEditReplace is very simtlar to that for oneEditinsert. We can
merge them into one method.
To do this, observe that both methods follow similar logic: compare each character and ensure that the
strings are only different by one. The methods vary in how they handle that difference. The method
oneEditReplace does nothing other than flag the difference, whereas oneEditinsert increments
the pointer to the longer string. We can handle both of these in the same method.
*/
bool oneEdit(std::string first, std::string second)
{
	if (abs(first.length() - second.length()) > 1)
		return false;

	std::string sl = first.length() < second.length() ? first : second;
	std::string s2 = first.length() < second.length() ? second : first;

	bool foundDifference = false;
	for (int idxl = 0, idx2 = 0; idx2 < s2.length() && idxl < sl.length();)
	{
		if (sl[idxl] != s2[idx2])
		{
			/* Ensure that this is the first difference found.*/
			if (foundDifference)
				return false;
			foundDifference = true;
			//On replace, move shorter pointer
			if (sl.length() == s2.length())
				idxl++;
		}
		else
			idxl++; // If matching, move shorter pointer

		idx2++; // Always move pointer for longer string
	}
	return true;
}

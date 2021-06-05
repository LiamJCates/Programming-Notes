/*
Like any with question, we should confirm some details with our interviewer:
	Are comparisons case sensitive, i.e. God a permutation of dog?
	Is whitespace significant, i.e. "god " is different from "dog"?

For this solution we will assume that comparisons are case sensitive and
whitespace is significant.
*/

/*
Solution methods

When the strings are sorted are they equal?

Time Complexity O(n log n)
	due to sorting complexity is O(n log n)
Space Complexity O(1)
	No added space when using an in-place sorting method is O(1)

Do the strings have the same character counts?
Time Complexity O(n)
	due to string traversal
Space Complexity O(min(c, n))
	space complexity is either the number of charcters in the alphabet for small alphabets or the size of the input for large character sets, due to auxillary structure to hold character counts.


Optimizations:
A common optimization is to compare the size of the strings, a strings of different sizes can't be anagrams
*/


//Sorting
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool permutation(string s, string t)
{
	if(s.length() != t.length()) return false;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}


bool permutation(string s, string t)
{
    if (s.length() != t.length())
        return false;

    int frequency[256]{0}; //Should be the size of the character set

    for (int i = 0; i < s.length(); i++)
    {
        ++frequency[s[i]];
        --frequency[t[i]];
    }

    for (auto i : frequency)
        if (i != 0)
            return false;

    return true;
}

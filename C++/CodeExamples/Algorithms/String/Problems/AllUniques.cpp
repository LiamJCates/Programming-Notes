/*
Implement an algorithm to determine if a string has all unique characters.

You should first ask your interviewer if the string is an ASCII string or a Unicode string.

A Unicode string would require a hash set to implement the solution
An ASCII string will allow the use of an array

The space complexity is O(1), either the size of the alphabet, or
We can reduce our space usage by a factor of eight by using a bit vector.


The time complexity for this code is O(n), where n is the length of the string.
(You could also argue the time complexity is 0(1), since the for loop will never iterate through more than 256 ASCII characters.) If you didn't want to assume the character set is fixed, you could express the complexity as
O(c) space andO(min (c, n)) or O(c) time, where c is the size of the character set.
*/

#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

//Use of Hashset
bool allUnique(std::string str)
{
	std::unordered_set<char> counts;
	for(char c : str)
	{
		if(counts.find(c) != counts.end())
			return false;
		counts.insert(c);
	}
	return true;
}

//Use of character array
bool allUnique(std::string str)
{
    if (str.length() > 256)
        return false;

    bool char_set[128];
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if (char_set[val]) return false;
        char_set[val] = true;
    }
    return true;
}

//Use of bool vector
bool allUnique(std::string str)
{
    if (str.length() > 256)
        return false;

    std::vector<bool> set(256);
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if (set[val]) return false;
        set[val] = true;
    }
    return true;
}

int main()
{
	std::string test = "abcdefghijklmnopqrstuvwxyz";
	std::cout << allUnique(test) << std::endl;
}

/*
If we can't use additional data structures, we can do the following:
1. Compare every character of the string to every other character of the string. This will take 0(n2) time and 0(1) space.

2. If we are allowed to modify the input string, we could sort the string in O(n log(n)) time and then linearly check the string for neighboring characters that are identical.

Careful, though: many sorting algorithms take up extra space.

These solutions are not as optimal in some respects, but might be better depending on the constraints of the problem.
*/

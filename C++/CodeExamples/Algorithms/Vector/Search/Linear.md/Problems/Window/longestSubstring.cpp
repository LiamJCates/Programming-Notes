/*
Given a string str, find the length of the longest substring without repeating characters.

    For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
    For “BBBB” the longest substring is “B”, with length 1.

*/

/*
Method 1 O(n^3):

We can consider all substrings one by one and check for each substring whether it contains all unique characters or not. There will be n*(n+1)/2 substrings. Whether a substring contains all unique characters or not can be checked in linear time by scanning it from left to right and keeping a map of visited characters.

Time complexity of this solution would be O(n^3).
*/

using namespace std;

// This function returns true if all characters in str[i..j]
// are distinct, otherwise returns false
bool areDistinct(string str, int i, int j)
{

		// Note : Default values in visited are false
		vector<bool> visited(256);

    for (int k = i; k <= j; k++) {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
    return true;
}

// Returns length of the longest substring
// with all distinct characters.
int longestUniqueSubsttr_On3(string str)
{
    int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}


/*
Method 2 O(n^2)

The idea is to use window sliding. Whenever we see repitition, we remove the pervious occurrance and slide the window.

For a demo of the sliding window technique, see:
[C++\CodeExamples\Algorithms\Vector\Search\Problems\slidingWindow.cpp]
*/

int longestUniqueSubsttr_On2(string str)
{
    int n = str.size();
    int res = 0; // result

    for (int i = 0; i < n; i++) {

        // Note : Default values in visited are false
        vector<bool> visited(256);

        for (int j = i; j < n; j++) {

            // If current character is visited
            // Break the loop
            if (visited[str[j]] == true)
                break;

            // Else update the result if
            // this window is larger, and mark
            // current character as visited.
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }

        // Remove the first character of previous
        // window
        visited[str[i]] = false;
    }
    return res;
}


/*
Method 3 (Linear Time)

This solution uses extra space to store the last indexes of already visited characters. The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we traverse the string, to know the length of current window we need two indexes.

1) Ending index ( j ) : We consider current index as ending index.
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.
*/

#define NO_OF_CHARS 256

int longestUniqueSubsttr_On(string str)
{
    int n = str.size();

    int res = 0; // result

    // last index of all characters is initialized as -1
    vector<int> lastIndex(NO_OF_CHARS, -1);

    // Initialize start of current window
    int i = 0;

    // Move end of current window
    for (int j = 0; j < n; j++) {

        // Find the last index of str[j]
        // Update i (starting index of current window)
        // as maximum of current value of i and last
        // index plus 1
        i = max(i, lastIndex[str[j]] + 1);

        // Update result if we get a larger window
        res = max(res, j - i + 1);

        // Update last index of j.
        lastIndex[str[j]] = j;
    }
    return res;
}


/*
Time Complexity: O(n + d)

where
n is length of the input string
d is number of characters in input string alphabet.

For example, if string consists of lowercase English characters then value of d is 26.

A map is the associative collection used to pair characters with their last occurance in the string

Auxiliary Space: O(d)
*/

#include <map>

int longestUniqueSubsttr_Ond(string s)
{
	// Creating a set to store the last positions of occurrence
	map<char, int> m;
	int len = s.length();
	int maximum_length = 0;

	// starting the inital point of window to index 0
	int start = 0;

	for (int end = 0; end < len; end++)
	{
		//retrive character from string
		char c = s.at(end);

		// Checking if we have already seen the character
		if (m.find(c) != m.end())
			// If so, move start pointer after the last occurrence
			start = max(start, m[c] + 1);

		// Updating the last seen value of the character
		m[c] = end;
		maximum_length = max(maximum_length, end - start + 1);
	}
	return maximum_length;
}

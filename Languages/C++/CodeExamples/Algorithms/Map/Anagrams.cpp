/*
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

We will return a vector of strings that groups anagrams by listing groups of anagrams together.

To determine whether a given string is an anagram, Generate footprint for each string, if they has the same footprint, they are anagrams. A footprint is a  hash number for each string.

A potential risk is hash collision. So choose a prime number as the factor to avoid this.

*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

long footprint(string str)
{
    int *index = new int[26]{0};
    for (int i = 0; i < str.size(); i++)
        index[str[i] - 'a']++;

    long footp = 0;
    int feed = 7;
    for (int i = 0; i < 26; i++)
        footp = footp * feed + index[i];

    return footp;
}

map<long, vector<string>> anagrams(vector<string> &strs)
{
    map<long, vector<string>> smap;
    for (int i = 0; i < strs.size(); i++)
        smap[footprint(strs[i])].push_back(strs[i]);

    return smap;
}

int main()
{
    vector<string> v =
        {
            "asdf",
            "fdsa",
            "dsfa",
            "lkjh",
            "jklh",
            "hjkl"
					};
    map<long, vector<string>> result = anagrams(v);

    for (auto pair : result)
    {
        for (string s : pair.second)
            cout << s << endl;
        cout << endl;
    }
}

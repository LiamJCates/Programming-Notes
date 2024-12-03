#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <string>

char firstNonRepeatedMap(std::string &s)
{
    std::map<char, int> m;

    for(char c : s)
    {
        if(m.find(c) == m.end())    m[c] = 1;
        else                        m[c]++;
    }

    for(auto e : m)
        if(e.second == 1) return e.first;

    return 0;
}

char firstNonRepeatedUnorderedMap(std::string &s)
{
    std::unordered_map<char, int> m;

    for(char c : s)
    {
        if(m.find(c) == m.end())    m[c] = 1;
        else                        m[c]++;
    }

    for(auto c : s)
        if(m[c] == 1) return c;

    return 0;
}

char firstNonRepeatedSet(std::string &str)
{
    std::set<char> repeated;
    std::set<char> notrepeated;

    for(char c : str)
    {
        if(repeated.find(c) != repeated.end())
            continue;
        if(notrepeated.find(c) == notrepeated.end())
            notrepeated.insert(c);
        else
        {
            notrepeated.erase(c);
            repeated.insert(c);
        }
    }

    return *notrepeated.begin();
}

int main()
{
    std::string test = "aabbccddeeffgghiijjk";
    std::cout << firstNonRepeated(test) << std::endl;
}

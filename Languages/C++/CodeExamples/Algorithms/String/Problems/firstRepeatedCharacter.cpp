#include <map>
#include <iostream>
#include <string>

char firstRepeated(std::string &s)
{
    std::map<char, int> m;

    for(char c : s)
    {
        if(m.find(c) == m.end())    m[c] = 1;
        else                        m[c]++;
    }

    for(auto e : m)
        if(e.second != 1) return e.first;

    return 0;
}

int main()
{
    std::string test = "abcdefgghijk";
    std::cout << firstRepeated(test) << std::endl;
}

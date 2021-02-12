/*
Given an unsorted list of integers, write a function that returns a new list with all duplicate values removed.
*/

#include <list>
#include <unordered_set>
std::list<int> removeDuplicates( const std::list<int>& in )
{
	std::unordered_set<int> s( in.begin(), in.end() );
	std::list<int> out( s.begin(), s.end() );
	return out;
}

int main()
{
    std::list<int> l {1,2,3,3,2,1,4,5,6,7};
    for(auto i : l)
        std::cout << i << '\n';
    l = removeDuplicates(l);
    for(auto i : l)
        std::cout << i << '\n';
}

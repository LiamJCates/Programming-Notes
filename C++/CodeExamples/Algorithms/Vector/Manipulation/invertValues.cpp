/*
Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives.

invert([1,2,3,4,5]) == [-1,-2,-3,-4,-5]
invert([1,-2,3,-4,5]) == [-1,2,-3,4,-5]
invert([]) == []

*/

#include <vector>
#include <algorithm>	//std::transform

std::vector<int> invert(std::vector<int> values)
{
    for( int i = 0; i < values.size(); i++)
      values[i] *= -1;
      return values;
}

std::vector<int> invert(std::vector<int> values)
{
    for(int &v : values)
      v = -v;
    return values;
}

std::vector<int> invert(std::vector<int> values)
{
    transform(values.begin(), values.end(), values.begin(), std::negate<int>());;
    return values;
}

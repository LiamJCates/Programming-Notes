/*

Given the string representations of two integers, return the string representation of the sum of those integers.

For example:

sumStrings('1','2') // => '3'

A string representation of an integer will contain no characters besides the ten numerals "0" to "9".


*/

#include <string>

std::string sum_strings(const std::string& a, const std::string& b)
{
  
  std::string str = "";
  char digit;

  int sum = 0, i = a.size(), j = b.size();

  while(i > 0 || j > 0)
  {
    if(i > 0) sum += a[--i] - 48;
    if(j > 0) sum += b[--j] - 48;

    digit = sum % 10 + 48;

    str.insert(str.begin(), digit);

    sum /= 10;
  }

  if(sum) str.insert(str.begin(), '1');

  return str;
}

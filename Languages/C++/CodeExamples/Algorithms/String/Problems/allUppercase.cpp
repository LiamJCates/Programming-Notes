/*
Create a function is_uppercase() to see whether the string is ALL CAPS. For example:

is_uppercase("c") == false
is_uppercase("C") == true
is_uppercase("hello I AM DONALD") == false
is_uppercase("HELLO I AM DONALD") == true
is_uppercase("ACSKLDFJSgSKLDFJSKLDFJ") == false
is_uppercase("ACSKLDFJSGSKLDFJSKLDFJ") == true

In this Kata, a string is said to be in ALL CAPS whenever it does not contain any lowercase letter so any string containing no letters at all is trivially considered to be in ALL CAPS.

*/

#include <string>

bool is_uppercase(const std::string &s) {
  for (int i = 0; s[i] != 0; ++i)
    if (s[i] >= 97 && s[i] <= 122)
      return false;
  return true;
}

bool is_uppercase(const std::string &s) {

  for(auto& c : s)
		if('a' <= c && c <= 'z')
			return false;

  return true;
}


#include <cctype>

bool is_uppercase(const std::string &s) {

  for(char c : s)
    if(islower(c))
      return false;

  return true;
}


#include <algorithm>

bool is_uppercase(const std::string &s) {
  return std::none_of(s.begin(), s.end(), islower);
}

bool is_uppercase(const std::string &s)
{
    std::string answer = s;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    return s == answer;
}

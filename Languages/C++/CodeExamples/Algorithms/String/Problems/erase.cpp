/*
Create a function that removes certain values from a string then return the string.
*/

//spaces

std::string no_space(std::string x)
{
    std::string result = "";
    for (char c: x) {
        if (c != ' ')
            result += c;
    }
    return result;
}

#include <sstream>

std::string no_space(std::string x)
{
  std::stringstream result;
  for (char c : x)
    if (c != ' ')
      result << c;

  return result.str();
}

std::string no_space(std::string x) {
  std::string s;
  auto ss {std::istringstream(x)};
  while (ss >> x)
    s += x;
  return s;
}

std::string no_space(std::string x)
{
  for(int i = 0; i < x.size(); i++)
    if(x[i] == ' ')
      x.erase(x.begin()+i--);

  return x;
}

#include <algorithm>

std::string no_space(std::string x)
{
    x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
    return x;
}


std::string no_space(std::string x) {
  while (x.find(" ") != -1)
    x.replace(x.find(" "), 1, "");

  return x;
}

#include <regex>

std::string no_space(std::string s)
{
  return std::regex_replace(s, std::regex(" "), "");
}

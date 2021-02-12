/*
We need a function that can transform a string into a number. What ways of achieving this do you know?

Note: Don't worry, all inputs will be strings, and every string is a perfectly valid representation of an integral number.
Examples

string_to_number("1234")  == 1234
string_to_number("605")   == 605
string_to_number("1405")  == 1405
string_to_number("-7")    == -7
*/

int string_to_number(const std::string& s) {
  int ans = 0;
  for(char c : s){
    if(c == '-') continue;
    ans *= 10;
    ans += c - '0';
  }
  return s[0]=='-' ? -ans : ans;
}


int string_to_number(const std::string& s) {
  return std::stoi(s);
}


int string_to_number(const std::string& s) {
  int result;
  stringstream (s) >> result;
  return result;
}


#define string_to_number std::stoi


int string_to_number(const std::string& s) {
  return std::strtol(s.c_str() ,nullptr,10);
}

#include <stdio.h>

int string_to_number(const std::string& s) {
  int i;
  sscanf (s.c_str(),"%d",&i);
  return i;
}

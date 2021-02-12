/*
We need a function that can transform a number into a string.

What ways of achieving this do you know?
Examples:

number_to_string(123) // "123"
number_to_string(999) // "999"

*/

#include <string>

std::string number_to_string(int num) {
  return std::to_string(num);
}



std::string number_to_string(int num) {
  std::stringstream s;
  s << num;
  return s.str();
}



auto& number_to_string = static_cast<std::string(&)(int)>(std::to_string);



#define number_to_string std::to_string

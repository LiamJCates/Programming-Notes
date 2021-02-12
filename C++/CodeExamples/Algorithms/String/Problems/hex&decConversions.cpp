/*
Functions which deal with the coneversion of strings in one base to integers in another
*/


//converts hex number (given as a string) to a decimal number.
#include <iostream>

int hexToDec(std::string hexString)
{
  int x;
  std::stringstream ss;
  ss << std::hex << hexString;
  ss >> x;
  return x;
}

int hexToDec(std::string hexString)
{
  int n;
  std::istringstream(hexString) >> std::hex >> n;

  return n;
}

int hexToDec(const std::string& hexString)
{
    return std::stoi(hexString, nullptr, 16);
}

int hexToDec(std::string hexString)
{
    return (int)strtol(hexString.c_str(), 0, 16);
}

#define hexToDec(asd) std::stoi(asd, nullptr, 16)

int hexToDec(std::string hex) {
    int decValue;
    sscanf(hex.c_str(), "%x", &decValue);
    return decValue;
}


// converts decimal integer to hex number string
std::string decToHex(int dec){

	std::stringstream ss;
  ss << hex << dec;
  return ss.str();
}

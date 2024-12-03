/*
altERnaTIng cAsE <=> ALTerNAtiNG CaSe

Define a function/method such as to_alternating_case such that each lowercase letter becomes uppercase and each uppercase letter becomes lowercase.

For example:

"hello world".toAlternatingCase() === "HELLO WORLD"
"HELLO WORLD".toAlternatingCase() === "hello world"
"hello WORLD".toAlternatingCase() === "HELLO world"
"HeLLo WoRLD".toAlternatingCase() === "hEllO wOrld"
"12345".toAlternatingCase() === "12345" // Non-alphabetical characters are unaffected
"1a2b3c4d5e".toAlternatingCase() === "1A2B3C4D5E"
*/






#include <string>
#include <cctype>

using namespace std;

string to_alternating_case(const string& str)
{
  string ans = str;

  for(char &c : ans)
    if(islower(c))       c = toupper(c);
    else if(isupper(c))  c = tolower(c);

  return ans;
}

string to_alternating_case(const string& str)
{
  string ret = str;
  for (char &c : ret)
      c = isupper(c) ? tolower(c) : toupper(c);

  return ret;
}

string to_alternating_case(const string& str)
{
    string result;

    for(char c : str){
        if(isupper(c))	result.push_back(tolower(c));
        else 						result.push_back(toupper(c));
    }

    return result;
}

string to_alternating_case(const string& str)
{
  string result = str;
  for_each(result.begin(), result.end(), [&] (char &c) {
		c = isupper(c)? tolower(c) : toupper(c);});
  return result;
}


string to_alternating_case(const string& str)
{
  std::string altstr = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (str.at(i) >= 65 && str.at(i) <= 90)
    {
      altstr += str.at(i) + 32;
    }
    else if (str.at(i) >= 97 && str.at(i) <= 122)
    {
      altstr += str.at(i) - 32;
    }
    else
    {
      altstr += str.at(i);
    }
  }

  return altstr;
}


string to_alternating_case(const string& str)
{
  std::string altstr = str;

  for (char &c : altstr)
  {
		if(isalpha(c))
			if(isupper(c))	c += 32;
			else						c -= 32;
	}

  return altstr;
}

// For Toogling the case of letter, xor with 32 beacuse letters are in such a way that toggling the 6th LSB will change its case from lower to upper and vice verse
string to_alternating_case(const string& str)
{
    std::string result = str;
    for(char& c : result) {
        if(isalpha(c)) c^=32;
    }
    return result;
}

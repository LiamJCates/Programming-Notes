/*
Write a function partlist that gives all the ways to divide a list (an array) of at least two elements into two non-empty parts.

    Each two non empty parts will be in a pair (or an array for languages without tuples or a structin C - C: see Examples test Cases - )
    Each part will be in a string
    Elements of a pair must be in the same order as in the original array.

Examples of returns in different languages:

a = ["az", "toto", "picaro", "zone", "kiwi"] -->
[["az", "toto picaro zone kiwi"], ["az toto", "picaro zone kiwi"], ["az toto picaro", "zone kiwi"], ["az toto picaro zone", "kiwi"]]
or
 a = {"az", "toto", "picaro", "zone", "kiwi"} -->
{{"az", "toto picaro zone kiwi"}, {"az toto", "picaro zone kiwi"}, {"az toto picaro", "zone kiwi"}, {"az toto picaro zone", "kiwi"}}
or
a = ["az", "toto", "picaro", "zone", "kiwi"] -->
[("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
or
a = [|"az", "toto", "picaro", "zone", "kiwi"|] -->
[("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
or
a = ["az", "toto", "picaro", "zone", "kiwi"] -->
"(az, toto picaro zone kiwi)(az toto, picaro zone kiwi)(az toto picaro, zone kiwi)(az toto picaro zone, kiwi)"
*/


using namespace std;


//Combine memebers into a string and split the string into a pair
class PartList
{
public:
  static vector<pair <string, string>> partlist(vector<string> &arr)
  {
    vector<pair <string, string>> rtn;
    string s;
    for(string& s : arr)
      s += " " + s;
    s.erase(0, 1);

    int len = 0, slen = s.length();
    for(int i = 0;i<arr.size()-1;i++)
    {
      len += arr[i].length();
      rtn.push_back(
				make_pair( s.substr(0, len + i), s.substr(len + i + 1, slen) )
			);
    }

    return rtn;
  }
};


//assemble two individual strings and make a pair
class PartList
{
public:
    static vector<pair <string, string>> partlist(vector<string> &arr)
    {
      vector<pair <string, string>> l;

      for(int index = 0; index < arr.size() - 1; index++)
			{
      	string s1, s2;

        for (int i = 0; i <= index; i++)
          s1 += " " + arr[i];

        for (int i = index + 1; i < arr.size(); i++)
          s2 += " " + arr[i];

        l.push_back( make_pair(s1.substr(1), s2.substr(1)) );
      }
      return l;
    }
};

//
class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr) {
      std::vector<std::pair <std::string, std::string>> s(arr.size()-1);
      for (unsigned long i = 0; i < arr.size()-1; i++) {
        for (unsigned long j = 0; j <= i; j++) {
          s[i].first += arr[j];
          if (j != i) s[i].first += ' ';
        }
        for (unsigned long j = i + 1; j < arr.size(); j++) {
          s[i].second += arr[j];
          if (j < arr.size()-1) s[i].second += ' ';
        }
      }
      return s;
    }
};


#include <numeric>

// Use accumulators
class PartList
{
public:
    static vector<pair <string, string>> partlist(vector<string> &arr)
    {
      vector<pair<string, string>> result;
      auto combine = [](string a, string b) { return a + ' ' + b; };
      for (int i = 1; i < arr.size(); i++)
      {
        result.emplace_back(
          accumulate(arr.begin() + 1, arr.begin() + i, arr[0], combine),
          accumulate(arr.begin() + i + 1,  arr.end(), arr[i], combine));
      }
      return result;
    }
};

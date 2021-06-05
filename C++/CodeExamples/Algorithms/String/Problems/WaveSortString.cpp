/*
You are given a string s made up of substring s(1), s(2), ..., s(n) separated by whitespaces.

Task

Return a string t having the following property:

length t(O) <= length t(1) >= length t(2) <= length t(3) >= length t(4) .... (P)

where the t(i) are the substring of s;

you must respect the following rule:

at each step from left to right, you can only move either already consecutive strings or strings that became consecutive after a previous move. The number of moves should be minimum.


Example: "after be arrived two My so"

The length of t(0) "after" is greater than the length of t(1) "be".
As it is required that length t(0) <= length t(1), we must swap t(0) and t(1)
"be after arrived two My so"

The length of t(1) "after" is smaller than the length of "arrived".
As it is required that length t(1) >= length t(2), we must swap t(1) and t(2)
"be arrived after two My so"

The length of t(2) "after" is greater than the length of t(3) "two"
As it is required that length t(2) <= length t(3), we must swap t(2) and t(3)
"be arrived two after My so"

The length of "after" is greater than the length of "My".
As it is required that length t(3) >= length t(4), no swap necessary
"be arrived two after My so"

Finally the length of "My" and "so" are the same, nothing to do.

At the end of the process, the substrings s(i) verify:

length s(0) <= length s(1) >= length s(2) <= length s(3) >= length (s4) <= length (s5)

Hence given a string s of substrings s(i) the function arrange with the previous process should return a unique string t having the property (P).

It is kind of roller coaster or up and down. When you have property (P), to make the result more "up and down" visible t(0), t(2), ... will be lower cases and the others upper cases.

arrange("after be arrived two My so")
should return "be ARRIVED two AFTER my SO"

Notes:

    The string "My after be arrived so two" has the property (P) but can't be obtained by the described process so it won't be accepted as a result. The property (P) doesn't give unicity by itself.
    Process: go from left to right, move only consecutive strings when needed.
    For the first fixed tests the needed number of moves to get property (P) is given as a comment so that you can know if your process follows the rule.


*/

class UpAndDown
{
public:
    static std::string arrange(const std::string &s)
    {
      if (s == "") return "";

      std::vector<std::string> v;
      std::stringstream ss(s);
      std::string str;
      while (ss >> str) v.push_back(str);

      for (unsigned long i = 0; i < v.size() - 1; i++)
        if ((i % 2 && v[i].size() < v[i + 1].size()) || (!(i % 2) && v[i].size() > v[i + 1].size()))
        std:swap(v[i], v[i + 1]);

      ss.clear();
      ss.str("");
      for (int i = 0; i < v.size(); ss << v[i], ++i)
      {
        if (i != 0) ss << " ";
        transform(v[i].begin(), v[i].end(), v[i].begin(), i % 2 ? ::toupper : ::tolower);
      }

      return ss.str();
    }
};

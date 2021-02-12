/*
given a lower case string and a integer k
remove k characters from that string using the following rule:

- first remove all letter 'a', followed by letter 'b', then 'c', etc...
- remove the leftmost character first.

For example:
solve('abracadabra', 1) = 'bracadabra' # remove the leftmost 'a'.
solve('abracadabra', 2) = 'brcadabra'  # remove 2 'a' from the left.
solve('abracadabra', 6) = 'rcdbr'      # remove 5 'a', remove 1 'b'
solve('abracadabra', 8) = 'rdr'
solve('abracadabra', 50) = ''
*/

std::string solve(const std::string &s, unsigned k)
{
  if(k >= s.length())
    return "";

  std::string str = s;
  for(char curChar = 'a'; k ;){
    std::size_t found = str.find(curChar);
    if (found != std::string::npos) {
      str.erase(found, 1);
      k--;
    } else {
      curChar++;
    }
  }
  return str;
}






std::string solve(std::string s, unsigned k) {
  if(k >= s.length())
    return "";

  char curChar = 'a';
  for (int j; k ; k--, s.erase(j, 1))
      for (j = s.find(curChar); j == std::string::npos;)
        j = s.find(++curChar);
  return s;
}

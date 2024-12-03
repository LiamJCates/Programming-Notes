/*
Given a string, spilt it on spaces and push the individual words into a vector of strings.
*/

#include <vector>
#include <string>

std::vector<std::string> filter_long_words(const std::string& s) {
  std::vector<std::string> ans;
  std::string current = "";
  for(char c : s)
  {
    if(c == ' ')
      ans.push_back(current), current = "";
    else current += c;
  }
  ans.push_back(current);

  return ans;
}

#include <istream>

std::vector<std::string> filter_words(const std::string& sentence) {
  std::vector<std::string> r;
  std::istringstream ss(sentence);
  std::string s;
  while (ss >> s) r.push_back(s);
  return r;
}





/*
Write a function filter_long_words
takes a string sentence and an integer n.

Return a list of all words that are longer than n.

Example:

filter_long_words("The quick brown fox jumps over the lazy dog", 4) = {'quick', 'brown', 'jumps'}

*/


#include <vector>
#include <string>

std::vector<std::string> filter_long_words(const std::string& s, int n) {
  std::vector<std::string> ans;
  std::string current = "";
  for(char c : s)
  {
    if(c == ' ')
    {
      if(current.size() > n) ans.push_back(current);
      current = "";
    }
    else current += c;
  }
  if(current.size() > n) ans.push_back(current);

  return ans;
}


#include <istream>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  std::vector<std::string> r;
  std::istringstream ss(sentence);
  std::string s;
  while (ss >> s) if (s.size() > n) r.push_back(s);
  return r;
}


std::vector<std::string> filter_long_words(const std::string& sentence, const int n) {
    std::vector<std::string> res;

    std::istringstream iss{ sentence };
    std::copy_if(
        std::istream_iterator<std::string>{ iss },
        std::istream_iterator<std::string>{},
        std::back_inserter(res),
        [n](const std::string& s) { return s.size() > n; }
    );

    return res;
}



#include <regex>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  const std::regex r(std::string("\\w{") + std::to_string(n + 1) + ",}+");
  return std::vector<std::string>(
      std::sregex_token_iterator(sentence.cbegin(), sentence.cend(), r, 0),
      std::sregex_token_iterator()
    );
}

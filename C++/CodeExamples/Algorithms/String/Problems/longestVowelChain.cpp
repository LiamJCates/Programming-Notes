/*
The vowel substrings in the word "onomatopoeia " are o, o, a, o, oeia. The longest of these has a length of 4. Given a lowercase string that has alphabetic characters only (both vowels and consonants) and no spaces, return the length of the longest vowel substring. Vowels are any of aeiou.
*/

#include <string>

using namespace std;

int solve(string s){
  int longest = 0, current = 0;

  for(char c :s ){
    switch(c){
      case 'a': current++; break;
      case 'e': current++; break;
      case 'i': current++; break;
      case 'o': current++; break;
      case 'u': current++; break;
      default :
        if(current > longest)
          longest = current;
        current = 0;
    }
    if(current > longest)
      longest = current;
  }
  return longest;
}



int solve(string s){

  int count = 0;
  int best = 0;
  for(int i=0;i<s.length();i++)
  {
     if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
        else count = 0;

     best = max(best, count);
  }

  return best;
}



#include <unordered_set>

int solve(string word){
  std::unordered_set<char> vowels {'a', 'e' ,'i', 'o' , 'u'};
  int longest = 0, longSub = 0;

  for (const char& s : word) {
    longSub = (vowels.count(s)) ? (longSub + 1) : 0;
    if (longSub > longest)
      longest = longSub;
  }

  return longest;
}

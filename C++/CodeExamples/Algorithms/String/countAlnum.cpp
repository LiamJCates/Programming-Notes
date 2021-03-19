#include <cctype>
#include <algorithm>



/*

*/
int countLettersAndDigits(std::string input)
{
    int count = 0;
    for(char ch : input)
      if((ch <= 'z' && ch >= 'a') ||
				 (ch <= 'Z' && ch >= 'A') ||
				 (ch <= '9' && ch >= '0'))
            count++;
    return count;
}


/*
Iterative
*/

int countLettersAndDigits(std::string input)
{
  int count = 0;
  for(auto ch : input) if(isalnum(ch)) count++;

  return count;
}

/*
Iterator
*/
int countLettersAndDigits(std::string input)
{
    return std::count_if( input.begin(), input.end(), isalnum );
}

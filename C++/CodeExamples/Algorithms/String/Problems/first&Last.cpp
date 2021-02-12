/*
Create a function that removes the first and last characters of a string. You're given one parameter, the original string. You don't have to worry with strings with less than two characters.
*/

#include <string>
using namespace std;

string sliceString (string str ){
  return str.substr(1, str.size() - 2);
}

string sliceString (string str )
{
  return string(str.begin()+1,str.end()-1) ;
}

string sliceString (string str )
{
  str.erase( str.begin()  );
  str.erase( str.size()-1 );
  return str ;
}

string sliceString (string str )
{
  str.erase(0,1);
  str.erase(str.size()-1,1);
  return str;
}

string sliceString (string str )
{
  str.replace(0, 1, "");
  str.replace(str.size();-2, 1, "");
  return str ;
}

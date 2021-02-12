/*
Write a function to convert a name into initials. input is strictly two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

Patrick Feeney => P.F

*/

std::string abbrevName(std::string name)
{
  int i = 0;
  std::string ans;
  ans += toupper(name[0]);
  while(name[++i] != ' ');
  ans += '.';
  ans += toupper(name[++i]);

  return ans;
}

std::string abbrevName(std::string name)
{
  int i = 0;

  while(name[++i] != ' ');

  return toupper(name[0]) + "." + toupper(name[++i]);
}

std::string abbrevName(std::string name)
{
  std::string ret;
  ret.push_back(toupper(name[0]));
  ret.push_back('.');
  ret.push_back(toupper(name[name.find(' ') + 1] ));
  return ret;
}

std::string abbrevName(std::string name)
{
  return toupper(name[0]) + "." toupper(name[name.find(' ') + 1]);
}

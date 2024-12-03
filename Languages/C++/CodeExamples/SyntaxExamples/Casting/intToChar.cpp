/*
Write a function which takes a number and returns the corresponding ASCII char for that value.

Example:

get_char(65) # => 'A'

For ASCII table, you can refer to http://www.asciitable.com/

*/


char get_char(int i) {
  return i;
}

char get_char(int i) {
  return char(i);
}

char get_char(int i)
{
    return static_cast<char>(i);
}

char get_char(int i) {
 return (char) i;
}

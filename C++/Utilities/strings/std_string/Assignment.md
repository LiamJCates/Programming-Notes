### Assignment

The easiest way to assign a value to a string is to use the overloaded operator= function. There is also an assign() member function that duplicates some of this functionality.
string& string::operator= (const string& str)
string& string::assign (const string& str)
string& string::operator= (const char* str)
string& string::assign (const char* str)
string& string::operator= (char c)

    These functions assign values of various types to the string.
    These functions return *this so they can be “chained”.
    Note that there is no assign() function that takes a single char.

Sample code:

  string sString;

  // Assign a string value
  sString = string("One");
  cout << sString << endl;

  const string sTwo("Two");
  sString.assign(sTwo);
  cout << sString << endl;

  // Assign a C-style string
  sString = "Three";
  cout << sString << endl;

  sString.assign("Four");
  cout << sString << endl;

  // Assign a char
  sString = '5';
  cout << sString << endl;

  // Chain assignment
  string sOther;
  sString = sOther = "Six";
  cout << sString << " " << sOther << endl;

Output:

One
Two
Three
Four
5
Six Six

The assign() member function also comes in a few other flavors:
string& string::assign (const string& str, size_type index, size_type len)

    Assigns a substring of str, starting from index, and of length len
    Throws an out_of_range exception if the index is out of bounds
    Returns *this so it can be “chained”.

Sample code:

  const string sSource("abcdefg");
  string sDest;

  sDest.assign(sSource, 2, 4); // assign a substring of source from index 2 of length 4
  cout << sDest << endl;

Output:

cdef

string& string::assign (const char* chars, size_type len)

Assigns len characters from the C-style array chars.
Throws an length_error exception if the result exceeds the maximum number of characters.
Returns *this so it can be “chained”.

Sample code:

  string sDest;

  sDest.assign("abcdefg", 4);
  cout << sDest << endl;

Output:

abcd

This function is potentially dangerous and its use is not recommended.

string& string::assign (size_type len, char c)

Assigns len occurrences of the character c
Throws a length_error exception if the result exceeds the maximum number of characters
Returns *this so it can be “chained”.

Sample code:

  string sDest;

  sDest.assign(4, 'g');
  cout << sDest << endl;

Output:

gggg

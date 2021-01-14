### Concatenation

str1 = str1 + str2;     str1 += srt2;

You can concatenate a string, a string literal, a C-style string, or a character to a string. The standard string has a move constructor, so returning even long strings by value is efficient:

string compose(const string& name, const string& domain)
{
  return name + '@' + domain;
}
auto addr = compose("dmr","bell−labs.com")

In many applications, the most common form of concatenation is adding something to the end of a string. This is directly supported by the += operation.

void m2(string& s1, string& s2)
{
  s1 = s1 + '\n'; // append newline
  s2 += '\n'; // append newline
}

The two ways of adding to the end of a string are semantically equivalent, but the latter is more explicit about what it does, more concise, and possibly more efficient.



Appending

Appending strings to the end of an existing string is easy using either operator+=, append(), or push_back() function.
string& string::operator+= (const string& str)
string& string::append (const string& str)

    Both functions append the characters of str to the string.
    Both function return *this so they can be “chained”.
    Both functions throw a length_error exception if the result exceeds the maximum number of characters.


string sString("one");

sString += string(" two");

string sThree(" three");
sString.append(sThree);

cout << sString << endl;

Output:

one two three

There’s also a flavor of append() that can append a substring:
string& string::append (const string& str, size_type index, size_type num)

    This function appends num characters from str, starting at index, to the string.
    Returns *this so it can be “chained”.
    Throws an out_of_range if index is out of bounds
    Throws a length_error exception if the result exceeds the maximum number of characters.


string sString("one ");

const string sTemp("twothreefour");
sString.append(sTemp, 3, 5); // append substring of sTemp starting at index 3 of length 5
cout << sString << endl;

Output:

one three

Operator+= and append() also have versions that work on C-style strings:
string& string::operator+= (const char* str)
string& string::append (const char* str)

    Both functions append the characters of str to the string.
    Both function return *this so they can be “chained”.
    Both functions throw a length_error exception if the result exceeds the maximum number of characters.
    str should not be NULL.


string sString("one");

sString += " two";
sString.append(" three");
cout << sString << endl;

Output:

one two three

There is an additional flavor of append() that works on C-style strings:
string& string::append (const char* str, size_type len)

    Appends the first len characters of str to the string.
    Returns *this so they can be “chained”.
    Throw a length_error exception if the result exceeds the maximum number of characters.
    Ignores special characters (including ”)


string sString("one ");

sString.append("threefour", 5);
cout << sString << endl;

Output:

one three

This function is dangerous and its use is not recommended.

There is also a set of functions that append characters. Note that the name of the non-operator function to append a character is push_back(), not append()!
string& string::operator+= (char c)
void string::push_back (char c)

    Both functions append the character c to the string.
    Operator += returns *this so it can be “chained”.
    Both functions throw a length_error exception if the result exceeds the maximum number of characters.

string sString("one");

sString += ' ';
sString.push_back('2');
cout << sString << endl;

Output:

one 2

Now you might be wondering why the name of the function is push_back() and not append(). This follows a naming convention used for stacks, where push_back() is the function that adds a single item to the end of the stack. If you envision a string as a stack of characters, using push_back() to add a single character to the end makes sense. However, the lack of an append() function is inconsistent in my view!

It turns out there is an append() function for characters, that looks like this:
string& string::append (size_type num, char c)

    Adds num occurrences of the character c to the string
    Returns *this so it can be “chained”.
    Throws a length_error exception if the result exceeds the maximum number of characters.

string sString("aaa");

sString.append(4, 'b');
cout << sString << endl;

Output:

aaabbbb

There’s one final flavor of append() that you won’t understand unless you know what iterators are. If you’re not familiar with iterators, you can ignore this function.
string& string::append (InputIterator start, InputIterator end)

    Appends all characters from the range [start, end) (including start up to but not including end)
    Returns *this so it can be “chained”.
    Throws a length_error exception if the result exceeds the maximum number of characters.

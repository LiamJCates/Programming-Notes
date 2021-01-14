## String Member Functions
Here’s a list of all the functions in the string class. Most of these functions have multiple flavors to handle different types of inputs

Size and capacity

| Function | Effect |
|----------|--------|
| capacity() | Returns the number of characters that can be held without reallocation |  
| empty() | Returns a boolean indicating whether the string is empty |
| length(), size() | Returns the number of characters in string |
| max_size() | Returns the maximum string size that can be allocated |
| reserve() | Expand or shrink the capacity of the string |

Element access

| Function | Effect |
|----------|--------|
| [], at() | Accesses the character at a particular index |

Modification

| Function | Effect |
|----------|--------|
| =, assign() | Assigns a new value to the string |
| +=, append(), push_back() | Concatenates characters to end of the string |
| insert() | Inserts characters at an arbitrary index in string |
| clear() | Delete all characters in the string |
| erase() | Erase characters at an arbitrary index in string |
| replace() | Replace characters at an arbitrary index with other characters |
| resize() | Expand or shrink the string (truncates or adds characters at end of string) |
| swap() |Swaps the value of two strings |

Input and Output

| Function | Effect |
|----------|--------|
| \>>, getline() | Reads values from the input stream into the string |
| << | Writes string value to the output stream |
| c_str() | Returns the contents of the string as a NULL-terminated C-style string |
| copy() | Copies contents (not NULL-terminated) to a character array |
| data() | Same as c_str(). The non-const overload allows writing to the returned string. |

String comparison

| Function | Effect |
|----------|--------|
| ==, != | Compares whether two strings are equal/unequal (returns bool) |
| <, <=, > >= | Compares whether two strings are less than / greater than each other |
| compare() | Compares whether two strings are equal/unequal (returns -1, 0, or 1) |

Substrings and concatenation

| Function | Effect |
|----------|--------|
| + | Concatenates two strings |
| substr() | Returns a substring |

Searching
| Function | Effect |
|----------|--------|
| find() | Find index of first character/substring |
| find_first_of() | Find index of first character from a set of characters |
| find_first_not_of() | Find index of first character not from a set of characters |
| find_last_of() | Find index of last character from a set of characters |
| find_last_not_of() | Find index of last character not from a set of characters |
| rfind() | Find index of last character/substring |

Iterator and allocator support

| Function | Effect |
|----------|--------|
| begin(), end() | Forward-direction iterator support for beginning/end of string |
| get_allocator() | Returns the allocator |
| rbegin(), rend() | Reverse-direction iterator support for beginning/end of string |

While the standard library string classes provide a lot of functionality, there are a few notable omissions:
  Regular expression support
  Constructors for creating strings from numbers
  Capitalization / upper case / lower case functions
  Case-insensitive comparisons
  Tokenization / splitting string into array
  Easy functions for getting the left or right hand portion of string
  Whitespace trimming
  Formatting a string sprintf style
  Conversion from utf-8 to utf-16 or vice-versa

For most of these, you will have to either write your own functions, or convert your string to a C-style string (using c_str()) and use the C functions that offer this functionality.




| Expression | Effect |
|------------|--------|
|strVar.at(index) | Returns the element at the position specified by index. |
| strVar[index] | Returns the element at the position specified by index. |
| strVar.append(n, ch) | Appends n copies of ch to strVar, where ch is a char variable or a char constant. |
| strVar.append(str) | Appends str to strVar.|
| strVar.clear() | Deletes all the characters in strVar.|
| strVar.compare(str) | Returns 1 if strVar > str; returns 0 if strVar == str; returns −1 if strVar < str.|
| strVar.empty() | Returns true if strVar is empty; otherwise it returns false. |
| strVar.erase() | Deletes all the characters in strVar.
| strVar.erase(pos, n) | Deletes n characters from strVar starting at position pos. |
| strVar.find(str) | Returns the index of the first occurrence of str in strVar. If str is not found, the special value string::npos is returned.
| strVar.find(str, pos) | Returns the index of the first occurrence at or after pos where str is found in strVar.
| strVar.find_first_of(str, pos) | Returns the index of the first occurrence of any character of strVar in str. The search starts at pos.|
| strVar.find_first_not_of (str, pos) | Returns the index of the first occurrence of any character of str not in strVar. The search starts at pos.|
| strVar.insert(pos, n, ch); | Inserts n occurrences of the character ch at index pos into strVar; pos and n are of type string::size_type; and ch is a character.|
| strVar.insert(pos, str); | Inserts all the characters of str at index pos into strVar.|
| strVar.length() | Returns a value of type string::size_type giving the number of characters in strVar.|
| strVar.replace(pos, n, str); | Starting at index pos, replaces the next n characters of strVar with all the characters of str. If n > length of strVar, then all the characters until the end of strVar are replaced.|
| strVar.substr(pos, len) | Returns a string which is a substring of strVar starting at pos. The length of the substring is at most len characters. If len is too large, it means “to the end“ of the string in strVar.|
| strVar.size() | Returns a value of type string::size_type giving the number of characters in strVar.|
| strVar.swap(str1); | Swaps the contents of strVar and str1. str1 is a string variable.|

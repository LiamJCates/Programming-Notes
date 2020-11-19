The data type string is a programmer-defined data type. It is not directly available
for use in a program like the simple data types discussed earlier. To use this data type,
you need to access program components from the library, which will be discussed
later in this chapter. The data type string is a feature of ANSI/ISO Standard C++.

Prior to the ANSI/ISO C11 language standard, the standard C11 library did not provide
a string data type. Compiler vendors often supplied their own programmer-defined
string type, and the syntax and semantics of string operations often varied from vendor
to vendor.



Strings are contiguous blocks of characters.


A string is a sequence of zero or more characters. Strings in C++ are enclosed in
double quotation marks. A string containing no characters is called a null or empty
string.

Every character in a string has a relative position in the string. The position of the first
character is 0, the position of the second character is 1, and so on. The length of a
string is the number of characters in it.

The string type is very powerful and more complex than simple data types. It provides not only the physical space required to store the string, but many operations to
manipulate strings. For example, it provides operations to find the length of a string,
extract part of a string, and compare strings.

## C-style Strings
C-style strings are a special case of an array of characters.

A C-style string or null-terminated string has a zero-byte appended to its end (a null) to indicate the end of the string.

Because array elements are contiguous, you can store strings in arrays of character types.

An example of C-style strings are string literals:
std::cout << "Hello World";

This is equivalent to using the array declaration:
char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd',
'\0'};
std::cout << sayHello << std::endl;

String-Terminating Character
Note that the last character in the array is a null character '\0'.
Called the string-terminating character because it tells the compiler that the string has ended.
Such C-style strings are a special case of character arrays in that the last character always precedes the null-terminator '\0'.
When you embed a string literal in your code, the compiler does the job of adding a '\0' after it.

Applications programmed in C (or in C++ by programmers who have a strong C background) often use string copy functions such as strcpy(), concatenation functions such as strcat(), and strlen() to determine the length of a string, in addition to others of this kind.
These functions take C-style strings as input and are dangerous as they seek the null-terminator and can exceed the boundaries of the character array they’re using if the programmer has not ensured the presence of the terminating null


## C++ style
C++ standard strings are an efficient and safer way to deal with text input—and to perform string manipulations like concatenations. std::string is not static in size like a char array implementation of a C-style string is and can scale up when more data needs to be stored in it.

to use a C++ string, you need to include the header string:
 #include <string>
 using std::string;

For unicode use wstring





## String Operators
str1 = str1 + str2;     str1 += srt2;

The relational operators can be applied to variables of type string. Variables of type
string are compared character by character, starting with the first character and
using the ASCII collating sequence. The character-by-character comparison continues until either a mismatch is found or the last characters have been compared and
are equal.

str1 == str2; //< > !=

string str1;
cout << str1;
cin >> str1;



## String Member Functions

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


C-String Functions

Requires #include <cstring>

| Function | Effect |
|----------|--------|
| strcpy(s1, s2) |  Copies the string s2 into the string variable s1 <br>The length of s1 should be at least as large as s2 <br>Does not check to make sure that s1 is as large s2 |
| strncpy(s1, s2, limit)  |Copies the string s2 into the string variable s1. At most limit characters are copied into s1. |
| strcmp(s1, s2) | Returns a value < 0 if s1 is less than s2 <br> Returns 0 if s1 and s2 are the same <br> Returns a value > 0 if s1 is greater than s2 |
| strncmp(s1, s2, limit) | This is same as the previous functions strcmp, except that at most limit characters are compared. |
| strlen(s) | Returns the length of the string s, excluding the null character |

In some compilers, the functions strcpy and strcmp have been deprecated, and might give
warning messages when used in a program. Furthermore, the functions strncpy and strncmp
might not be implemented in all versions of C++. To be sure, check your compiler’s documentation.


## string Type and Input/Output Files

values (that is, strings) of type string are not null terminated. Variables of type string can also be used to read and store the names of input/output files. However, the argument to the function open must be a null-terminated string—that is, a C-string. Therefore, if we use a variable of type string to read the name of an
input/output file and then use this variable to open a file, the value of the variable
must (first) be converted to a C-string (that is, a null-terminated string). The header
file string contains the function c_str, which converts a value of type string to
a null-terminated character array (that is, C-string). The syntax to use the function
c_str is:
strVar.c_str()
in which strVar is a variable of type string.
The following statements illustrate how to use variables of type string to read the
names of the input/output files during program execution and open those files:
ifstream infile;
string fileName;560 | Chapter 8: Arrays and Strings
cout << "Enter the input file name: ";
cin >> fileName;
infile.open(fileName.c_str()); //open the input file
Of course, you must also include the header file string in the program. The output
file has similar conventions.
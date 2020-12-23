STL supplies a template class that has been specially designed for string operations.
std::basic_string<T> is used popularly in its two template specializations:
■ std::string — A char-based specialization of std::basic_string used for
the manipulation of simple character strings.
■ std::wstring— A wchar_t-based specialization of std::basic_string
used for the manipulation of wide character strings typically used to store Unicode
characters that support symbols from different languages.

C++ strings are a programmer-defined data type.

The data type string is a feature of ANSI/ISO Standard C++.

Prior to the ANSI/ISO C++ language standard, the standard C++ library did not provide a string data type.

The C++ standard library offers a string type to save most users from C-style manipulation of arrays of characters through pointers.

C++ standard strings are an efficient and safer way to deal with text input—and to perform string manipulations like concatenations.

std::string is not static in size like a char array implementation of a C style string is and can scale up when more data needs to be stored in it.

to use a C++ string, you need to include the header string:
 #include <string>
 using std::string;

For unicode use wstring


A string is a contiguous block containing a sequence of zero or more characters.

Every character in a string has a zero indexed position in the string.
The length of a string is the number of characters in it.
A string containing no characters is called a null or empty string.

String literals in C++ are enclosed in double quotation marks.



## String Operators

If you need a C-style string (a zero-terminated array of char), string offers read-only access to its contained characters.

s.c_str() returns a pointer to s’ characters


void print(const string& s)
{
  printf("For people who like printf: %s\n",s.c_str()); //
  cout << "For people who like streams: " << s << '\n';
}

A C string literal is by definition a const char∗.
To get a literal of type std::string use a s suffix:

auto s = "Cat"s; // a std::string
auto p = "Dog"; // a C-style string: a const char*

To use the s suffix, you need to use the namespace std::literals::string_literals



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




### Mutability
A string is mutable.
In addition to = and +=, subscripting (using [ ]) and substring operations are
supported:

string name = "Niels Stroustrup";
void m3()
{
  string s = name.substr(6,10); // s = "Stroustr up"
  name.replace(0,5,"nicholas"); // name becomes "nicholas Stroustrup"
  name[0] = toupper(name[0]); // name becomes "Nicholas Stroustrup"
}

The substr() operation returns a string that is a copy of the substring indicated by its arguments. The first argument is an index into the string (a position), and the second is the length of the desired substring.

Since indexing starts from 0, s gets the value Stroustrup.

The replace() operation replaces a substring with a value. In this case, the substring starting at 0 with length 5 is Niels; it is replaced by nicholas.

Finally, the initial character is replaced with its uppercase equivalent.

















### Comparison
The relational operators can be applied to variables of type string.
str1 == str2; //< > !=

Variables of type string are compared character by character, starting with the first character and using the ASCII collating sequence. The character-by-character comparison continues until either a mismatch is found or the last characters have been compared and are equal.

Naturally, strings can be compared against each other, against C-style strings, and against string literals:

string incantation;

void respond(const string& answer)
{
  if (answer == incantation) {
    // perform magic
  }
  else if (answer == "yes") {
    // ...
  }
  // ...
}



### IO

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










## String Views
The most common use of a sequence of characters is to pass it to some function to read. This can
be achieved by passing a string by value, a reference to a string, or a C-style string. In many systems there are further alternatives, such as string types not offered by the standard. In all of these
cases, there are extra complexities when we want to pass a substring. To address this, the standard
library offers string_view; a string_view is basically a (pointer,length) pair denoting a sequence of
characters:

A string_view gives access to a contiguous sequence of characters.
The characters can be stored in many possible ways, including in a string and in a C-style string.

A string_view is like a pointer or a reference in that it does not own the characters it points to. In that, it resembles an STL pair of iterators.

Consider a simple function concatenating two strings:

string cat(string_view sv1, string_view sv2)
{
  string res(sv1.length()+sv2.length());
  char∗ p = &res[0];
  for (char c : sv1) // one way to copy
    ∗p++ = c;
  copy(sv2.begin(),sv2.end(),p); // another way
  return res;
}

We can call this cat():
string king = "Harold";
auto s1 = cat(king, "William"); // string and const char*
auto s2 = cat(king, king); // string and string
auto s3 = cat("Edward", "Stephen"sv); // const char * and string_view
auto s4 = cat("Canute"sv, king);
auto s5 = cat({&king[0],2}, "Henry"sv); // HaHenry
auto s6 = cat({&king[0],2}, {&king[2],4}); // Harold

This cat() has three advantages over the compose() that takes const string& arguments (§9.2):
• It can be used for character sequences managed in many different ways.
• No temporary string arguments are created for C-style string arguments.
• We can easily pass substrings.

Note the use of the sv (‘‘string view’’) suffix. To use that we need to
using namespace std::literals::string_view_literals;

Why bother? The reason is that when we pass "Edward" we need to construct a string_view from a
const char∗ and that requires counting the characters. For "Stephen"sv the length is computed at
compile time.
When returning a string_view, remember that it is very much like a pointer; it needs to point to something:

string_view bad()
{
  string s = "Once upon a time";
  return {&s[5],4}; // bad: returning a pointer to a local
}

We are returning a pointer to characters of a string that will be destroyed before we can use them.
One significant restriction of string_view is that it is a read-only view of its characters. For example, you cannot use a string_view to pass characters to a function that modifies its argument to lowercase.

For that, you might consider using a gsl::span or gsl::string_span (§13.3).

The behavior of out-of-range access to a string_view is unspecified. If you want guaranteed range checking, use at(), which throws out_of_range for attempted out-of-range access, use a gsl::string_span (§13.3), or ‘‘just be careful.’’




## string Type and Input/Output Files

values (that is, strings) of type string are not null terminated. Variables of type string can also be used to read and store the names of input/output files. However, the argument to the function open must be a null-terminated string — that is, a C-string. Therefore, if we use a variable of type string to read the name of an input/output file and then use this variable to open a file, the value of the variable must (first) be converted to a C-string  using c_str:

strVar.c_str()


The following statements illustrate how to use variables of type string to read the names of the input/output files during program execution and open those files:
ifstream infile;
string fileName;
cout << "Enter the input file name: ";
cin >> fileName;
infile.open(fileName.c_str()); //open the input file

Of course, you must also include the header file string in the program. The output file has similar conventions.

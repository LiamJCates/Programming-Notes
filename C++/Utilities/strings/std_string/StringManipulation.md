## Need for String Manipulation Classes

In C++, a string is an array of characters, the simplest character array can be defined as following:

char staticName [20];

staticName is the declaration of a character array (also called a string) of a fixed (hence static) length of 20 elements. As you see, this buffer can hold a string of limited length and would soon be overrun if you tried to hold a greater number of characters in it.

Resizing this statically allocated array is not possible. To overcome this constraint, C++ supplies dynamic allocation of data. Therefore, a more dynamic representation of a string array is

char* dynamicName = new char [arrayLen];

dynamicName is a dynamically allocated character array that can be instantiated to the length as stored in the value arrayLen, determinable at runtime, and hence can be allocated to hold a data of variable length. However, should you want to change the length of the array at runtime, you would first have to deallocate the allocated memory and then reallocate to hold the required data.

Things get complicated if these char* strings are used as member attributes of a class. In situations where an object of this class is assigned to another, in the absence of a correctly programmed copy constructor and assignment operator, the two objects contain copies of a pointer, essentially pointing to the same char buffer. The result is two string pointers in two objects, each holding the same address and hence pointing to the same location in memory. The destruction of the first object results in the pointer in the other object being invalidated, and an impending crash looms on the horizon.

String classes solve these problems for you. The STL string classes std::string that models a character string and std::wstring that models a wide character string helps you in the following ways:
  Reduces the effort of string creation and manipulation
  Increases the stability of the application being programmed by internally managing memory allocation details
  Features copy constructor and assignment operators that automatically ensure that member strings get correctly copiedSupplies useful utility functions that help in truncating, finding, and erasing to name a few
  Provides operators that help in comparisons
  Lets you focus efforts on your application’s primary requirements rather than on string manipulation details

Both std::string and std::wstring are actually template specializations of the same class, namely std::basic_string<T> for types char and wchar_t, respectively. When you have learned using one, you can use the same methods and operators on the other.

The most commonly used string functions are
  Copying
  Concatenating
  Finding characters and substrings
  Truncating
  String reversal and case conversions, which are achieved using algorithms provided by the standard library

To use the STL string class, you must include the header <string>.

Instantiating the STL String and Making Copies

The string class features many overloaded constructors and therefore can be
instantiated and initialized in many different ways.

For example, you can simply initialize or assign a constant character string literal to a regular STL std::string object:
const char* constCStyleString = "Hello String!";
std::string strFromConst ("Hello String!");
std::string strFromConst (constCStyleString);
std::string strFromConst = constCStyleString;

As is apparent, instantiating a string object and initializing it to a value did not require supplying the length of the string or the memory allocation details—the constructor of the STL string class automatically did this.

Use one string object to initialize another:
std::string str2Copy (strFromConst);

Only the first n characters of the supplied input string:
std::string strPartialCopy (constCStyleString, 5);

A specific number of instances of a particular character:
std::string strRepeatChars (10, 'a');


If you were to use character strings to copy from another of the same kind, the equivalent of would be this:
const char* constCStyleString = "Hello World!";

// To create a copy, first allocate memory for one...
char* copy = new char [strlen (constCStyleString) + 1];
strcpy (copy, constCStyleString); // The copy step
// deallocate memory after using copy
delete [] copy;

As you can see, the result is many more lines of code and higher probability of introducing errors, and you need to worry about memory management and deallocations. STL string does all this for you, and more!


## String Operations
The character contents of an STL string can be accessed via iterators or via an
array-like syntax where the offset is supplied, using the subscript operator [].
A C-style representation of the string can be obtained via member function c_str().

String concatenation can be achieved by using either the += operator or the append()

The STL string supplies a find() member function with a few overloaded versions
that help find a character or a substring in a given string object.

// Find substring "day" in sampleStr, starting at position 0
size_t charPos = sampleStr.find ("day", 0);
// Check if the substring was found, compare against string::npos
if (charPos != string::npos)
cout << "First instance of \"day\" was found at position " << charPos;
else
cout << "Substring not found." << endl;

The STL string also features find functions such as find_
first_of(), find_first_not_of(), find_last_of(), and
find_last_not_of() that assist the programmer in working with
strings.

The STL string features a function called erase() that can erase
■ A number of characters when given an offset position and count string sampleStr ("Hello String! Wake up to a beautiful day!");
sampleStr.erase (13, 28); // Hello String!

■ A character when supplied with an iterator pointing to it
sampleStr.erase (iCharS); // iterator points to a specific character

■ A number of characters given a range supplied by two iterators that bind the same
sampleStr.erase (sampleStr.begin (), sampleStr.end ());


string sampleStr ("Hello String! We will reverse you!");
reverse (sampleStr.begin (), sampleStr.end ());


String case conversion can be effected using the algorithm std::transform(), which
applies a user-specified function to every element of a collection.

transform(str.begin(), str.end(), str.begin(), ::toupper);

transform(str.begin(), str.end(), str.begin(), ::tolower);




Template-Based Implementation of an STL String
The std::string class, as you have learned, is actually a specialization of the STL template class std::basic_string <T>. The template declaration of container class basic_string is as follows:

template<class _Elem,
  class _Traits,
  class _Ax>
  class basic_string

In this template definition, the parameter of utmost importance is the first one: _Elem. This is the type collected by the basic_string object. The std::string is therefore the template specialization of basic_string for _Elem=char, whereas the wstring is the template specialization of basic_string for _Elem=wchar_t.

The STL string class is defined as typedef basic_string<char, char_traits<char>, allocator<char> > string;

The STL wstring class is defined as typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > string;

So, all string features and functions studied so far are actually those supplied by basic_string, and are therefore also applicable to the STL wstring class.

You would use the std::wstring when programming an application that needs to better support non-Latin characters such as those in Japanese or Chinese.

C++14 compliant versions of the standard library support operator ""s that convert
the string contained within the quotes, in entirety, to a std::basic_string<t>.

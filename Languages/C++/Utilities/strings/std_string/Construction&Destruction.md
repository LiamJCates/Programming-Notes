### Construction and Destruction



String construction

The string classes have a number of constructors that can be used to create strings.

Note: string::size_type resolves to size_t, which is the same unsigned integral type that is returned by the sizeof operator. Its actual size varies depending on environment. For purposes of this tutorial, envision it as an unsigned int.


string::string()
Default constructor creates an empty string.


string::string(const string& str)
Copy constructor. This constructor creates a new string as a copy of str.


string::string(const string& str, size_type unIndex)
string::string(const string& str, size_type unIndex, size_type unLength)

This constructor creates a new string that contains at most unLength characters from strString, starting with index unIndex. If a NULL is encountered, the string copy will end, even if unLength has not been reached.
If no unLength is supplied, all characters starting from unIndex will be used.
If unIndex is larger than the size of the string, the out_of_range exception will be thrown.



string::string(const char *szCString)

This constructor creates a new string from the C-style string szCString, up to but not including the NULL terminator. If the resulting size exceeds the maximum string length, the length_error exception will be thrown. Warning: szCString must not be NULL.



string::string(const char *szCString, size_type unLength)

This constructor creates a new string from the first unLength chars from the C-style string szCString. If the resulting size exceeds the maximum string length, the length_error exception will be thrown. Warning: For this function only, NULLs are not treated as end-of-string characters in szCString! This means it is possible to read off the end of your string if unLength is too big. Be careful not to overflow your string buffer!



string::string(size_type nNum, char chChar)

This constructor creates a new string initialized by nNum occurances of the character chChar. If the resulting size exceeds the maximum string length, the length_error exception will be thrown.


template<class InputIterator> string::string(InputIterator itBeg, InputIterator itEnd)

This constructor creates a new string initialized by the characters of range [itBeg, itEnd). If the resulting size exceeds the maximum string length, the length_error exception will be thrown.



String destruction

string::~string()

This is the destructor. It destroys the string and frees the memory. 

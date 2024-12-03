### Length
A string is a contiguous block containing a sequence of zero or more characters.

Every character in a string has a zero indexed position in the string.
The length of a string is the number of characters in it.
A string containing no characters is called a null or empty string.

Once you’ve created strings, it’s often useful to know how long they are.

There are two identical functions for determining string length:
size_type string::length() const
size_type string::size() const

Both of these functions return the current number of characters in the string, excluding the null terminator.

Although it’s possible to use length() to determine whether a string has any characters or not, it’s more efficient to use the empty() function:

bool string::empty() const

Returns true if the string has no characters, false otherwise.


There is one more size-related function that you will probably never use, but we’ll include it here for completeness:

size_type string::max_size() const

Returns the maximum number of characters that a string is allowed to have. This value will vary depending on operating system and system architecture. 

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




C-style strings have many shortcomings, primarily revolving around the fact that you have to do all the memory management yourself. For example, if you want to assign the string “hello!” into a buffer, you have to first dynamically allocate a buffer of the correct length:

  char *strHello = new char[7];

Don’t forget to account for an extra character for the null terminator!

Then you have to actually copy the value in:

  strcpy(strHello, "hello!");

Hopefully you made your buffer large enough so there’s no buffer overflow!

And of course, because the string is dynamically allocated, you have to remember to deallocate it properly when you’re done with it:

  delete[] strHello;

Don’t forget to use array delete instead of normal delete!

Applications programmed in C (or in C++ by programmers who have a strong C background) often use string copy functions such as strcpy(), concatenation functions such as strcat(), and strlen() to determine the length of a string, in addition to others of this kind.

These functions take C-style strings as input and are dangerous as they seek the null-terminator and can exceed the boundaries of the character array they’re using if the programmer has not ensured the presence of the terminating null


C-String Functions

Requires #include <cstring>

| Function | Effect |
|----------|--------|
| strcpy(s1, s2) |  Copies the string s2 into the string variable s1 <br>The length of s1 should be at least as large as s2 <br>Does not check to make sure that s1 is as large s2 |
| strncpy(s1, s2, limit)  |Copies the string s2 into the string variable s1. At most limit characters are copied into s1. |
| strcmp(s1, s2) | Returns a value < 0 if s1 is less than s2 <br> Returns 0 if s1 and s2 are the same <br> Returns a value > 0 if s1 is greater than s2 |
| strncmp(s1, s2, limit) | This is same as the previous functions strcmp, except that at most limit characters are compared. |
| strlen(s) | Returns the length of the string s, excluding the null character |

In some compilers, the functions strcpy and strcmp have been deprecated, and might give warning messages when used in a program. Furthermore, the functions strncpy and strncmp might not be implemented in all versions of C++. To be sure, check your compiler’s documentation.

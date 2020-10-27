## C-style
C-style strings are a special case of an array of characters.

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

str1 == str2; //< > !=

string str1;
cout << str1;
cin >> str1;



## String Member Functions

string greeting = "Hello";

int len = greeting.length();
string ello = greeting.substr(1,4); //p1 = zeroindex start, p2 = number of characters
int pos = greeting.find("ell"); //determines if p1 in string and return start location

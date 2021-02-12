## String Literals
C++ supports various string types, and provides ways to express literal values of each of these types.

Since the initial versions of C++ had only the "low-level" C string handling functionality and conventions, multiple incompatible designs for string handling classes have been designed over the years and are still used instead of std::string, and C++ programmers may need to handle multiple conventions in a single application.

In your source code, you express the content of your string literals using a character set. Universal character names and escape characters allow you to express any string using only the basic source character set. A raw string literal enables you to avoid using escape characters, and can be used to express all types of string literals. You can also create std::string literals without having to perform extra construction or conversion steps.


Declare a basic string literal by enclosing text in quotation marks (""):

  std::cout << "Hello World" << std::endl;


The C-Style Character String

The C-style character string originated within the C language and continues to be supported within C++. This string is actually a one-dimensional array of characters which is terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

The following fixed array declaration and initialization create a string consisting of the word "Hello". To hold the null character at the end of the array, the size of the character array containing the string is one more than the number of characters in the word "Hello."

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

Also equal to the above declarations are char arrays initialized with a string literal:

char greeting[] = "Hello";
char greeting[]{ "Hello" };

You do not place the null character at the end of a string literal. The C++ compiler automatically places the '\0' at the end of the string when it initializes the array.

C++ also supports a way to create C-style string symbolic constants using pointers:

  const char *greeting{ "Hello" }; // pointer to symbolic constant


In the fixed array case, the program allocates memory for a fixed array of length 5, and initializes that memory with the string "Hello\0". Because memory has been specifically allocated for the array, you’re free to alter the contents of the array. The array itself is treated as a normal local variable, so when the array goes out of scope, the memory used by the array is freed up for other uses.

In the symbolic constant case, how the compiler handles this is implementation defined. What usually happens is that the compiler places the string C++20Alex\0" into read-only memory somewhere, and then sets the pointer to point to it. Because this memory may be read-only, best practice is to make sure the string is const.

For optimization purposes, multiple string literals may be consolidated into a single value. For example:

  const char *name1{ "Alex" };
  const char *name2{ "Alex" };

These are two different string literals with the same value. The compiler may opt to combine these into a single shared string literal, with both name1 and name2 pointed at the same address. Thus, if name1 was not const, making a change to name1 could also impact name2 (which might not be expected).

As a result of string literals being stored in a fixed location in memory, string literals have static duration rather than automatic duration (that is, they die at the end of the program, not the end of the block in which they are defined). That means that when we use string literals, we don’t have to worry about scoping issues. Thus, the following is okay:

  const char* getName()
  {
      return "Alex";
  }

In the above code, getName() will return a pointer to C-style string "Alex". If this function were returning any other local variable by address, the variable would be destroyed at the end of getName(), and we’d return a dangling pointer back to the caller. However, because string literals have static duration, "Alex" will not be destroyed when getName() terminates, so the caller can still successfully access it.

C-style strings are used in a lot of old or low-level code, because they have a very small memory footprint. Modern code should favor the use std::string and std::string_view, as those provide safe and easy access to the string.






A string literal represents a sequence of characters that together form a null-terminated string.

There are the following kinds of string literals:
  Narrow string literals
  UTF-8 encoded strings
  Wide string literals
  Raw string Literals
  std::string literals

Narrow string literals
A narrow string literal is a non-prefixed, double-quote delimited, null-terminated array of type const char[n], where n is the length of the array in bytes. A narrow string literal may contain any graphic character except the double quotation mark ("), backslash (\), or newline character. A narrow string literal may also contain the escape sequences listed above, and universal character names that fit in a byte.
const char *narrow = "abcd";

// represents the string: yes\no
const char *escaped = "yes\\no";

UTF-8 encoded strings

A UTF-8 encoded string is a u8-prefixed, double-quote delimited, null-terminated array of type const char[n], where n is the length of the encoded array in bytes. A u8-prefixed string literal may contain any graphic character except the double quotation mark ("), backslash (\), or newline character. A u8-prefixed string literal may also contain the escape sequences listed above, and any universal character name.
const char* str1 = u8"Hello World";
const char* str2 = u8"\U0001F607 is O:-)";

Wide string literals

A wide string literal is a null-terminated array of constant wchar_t that is prefixed by 'L' and contains any graphic character except the double quotation mark ("), backslash (\), or newline character. A wide string literal may contain the escape sequences listed above and any universal character name.
const wchar_t* wide = L"zyxw";
const wchar_t* newline = L"hello\ngoodbye";

char16_t and char32_t (C++11)

C++11 introduces the portable char16_t (16-bit Unicode) and char32_t (32-bit Unicode) character types:
auto s3 = u"hello"; // const char16_t*
auto s4 = U"hello"; // const char32_t*

Raw string literals (C++11)

A raw string literal is a null-terminated array—of any character type—that contains any graphic character, including the double quotation mark ("), backslash (\), or newline character. Raw string literals are often used in regular expressions that use character classes, and in HTML strings and XML strings. For examples, see the following article: Bjarne Stroustrup's FAQ on C++11.
// represents the string: An unescaped \ character
const char* raw_narrow = R"(An unescaped \ character)";
const wchar_t* raw_wide = LR"(An unescaped \ character)";
const char*       raw_utf8  = u8R"(An unescaped \ character)";
const char16_t* raw_utf16 = uR"(An unescaped \ character)";
const char32_t* raw_utf32 = UR"(An unescaped \ character)";

A delimiter is a user-defined sequence of up to 16 characters that immediately precedes the opening parenthesis of a raw string literal, and immediately follows its closing parenthesis. For example, in R"abc(Hello"\()abc" the delimiter sequence is abc and the string content is Hello"\(. You can use a delimiter to disambiguate raw strings that contain both double quotation marks and parentheses. This string literal causes a compiler error:
// meant to represent the string: )"
const char* bad_parens = R"()")";  // error C2059

But a delimiter resolves it:
const char* good_parens = R"xyz()")xyz";

You can construct a raw string literal that contains a newline (not the escaped character) in the source:
// represents the string: hello
//goodbye
const wchar_t* newline = LR"(hello
goodbye)";

std::string literals (C++14)

std::string literals are Standard Library implementations of user-defined literals (see below) that are represented as "xyz"s (with a s suffix). This kind of string literal produces a temporary object of type std::string, std::wstring, std::u32string, or std::u16string, depending on the prefix that is specified. When no prefix is used, as above, a std::string is produced. L"xyz"s produces a std::wstring. u"xyz"s produces a std::u16string, and U"xyz"s produces a std::u32string.

  //#include <string>
  //using namespace std::string_literals;
  string str{ "hello"s };
  string str2{ u8"Hello World" };
  wstring str3{ L"hello"s };
  u16string str4{ u"hello"s };
  u32string str5{ U"hello"s };

The s suffix may also be used on raw string literals:
u32string str6{ UR"(She said "hello.")"s };

std::string literals are defined in the namespace std::literals::string_literals in the <string> header file. Because std::literals::string_literals, and std::literals are both declared as inline namespaces, std::literals::string_literals is automatically treated as if it belonged directly in namespace std.
Size of string literals

For ANSI char* strings and other single-byte encodings (but not UTF-8), the size (in bytes) of a string literal is the number of characters plus 1 for the terminating null character. For all other string types, the size isn't strictly related to the number of characters. UTF-8 uses up to four char elements to encode some code units, and char16_t or wchar_t encoded as UTF-16 may use two elements (for a total of four bytes) to encode a single code unit. This example shows the size of a wide string literal in bytes:
const wchar_t* str = L"Hello!";
const size_t byteSize = (wcslen(str) + 1) * sizeof(wchar_t);

Notice that strlen() and wcslen() don't include the size of the terminating null character, whose size is equal to the element size of the string type: one byte on a char* or char8_t* string, two bytes on wchar_t* or char16_t* strings, and four bytes on char32_t* strings.

The maximum length of a string literal is 65,535 bytes. This limit applies to both narrow string literals and wide string literals.
Modifying string literals

Because string literals (not including std::string literals) are constants, trying to modify them—for example, str[2] = 'A'—causes a compiler error.
Microsoft-specific

In Microsoft C++, you can use a string literal to initialize a pointer to non-const char or wchar_t. This non-const initialization is allowed in C99 code, but is deprecated in C++98 and removed in C++11. An attempt to modify the string causes an access violation, as in this example:

  wchar_t* str = L"hello";
  str[2] = L'a'; // run-time error: access violation

You can cause the compiler to emit an error when a string literal is converted to a non-const character pointer when you set the /Zc:strictStrings (Disable string literal type conversion) compiler option. We recommend it for standards-compliant portable code. It's also a good practice to use the auto keyword to declare string literal-initialized pointers, because it resolves to the correct (const) type. For example, this code example catches an attempt to write to a string literal at compile time:

  auto str = L"hello";
  str[2] = L'a'; // C3892: you cannot assign to a variable that is const.

In some cases, identical string literals may be pooled to save space in the executable file. In string-literal pooling, the compiler causes all references to a particular string literal to point to the same location in memory, instead of having each reference point to a separate instance of the string literal. To enable string pooling, use the /GF compiler option.








### Continuation

The backslash character (\) is a line-continuation character. When you need a long string, you can use the continuation marker \ (backslash) before a line break. The preprocessor scans the source file before compilation and concatenates lines that are broken by a continuation marker. Thus, the compiler sees such lines as if they were typed without a break. Note that the line break (a hard return/enter) should appear immediately after the backslash.

### Consecutive String Literals

This statement is written as two string literals:
std::cout << "Hello "
"World" << std::endl;


Adjacent wide or narrow string literals are concatenated. This declaration:
char str[] = "12" "34";

is identical to this declaration:
char atr[] = "1234";

and to this declaration:
char atr[] =  "12\
34";

Consecutive string literals get concatenated together, and any intervening whitespaces or newlines get ignored. So, you can place string literals on multiple lines in your source, and the compiler will treat them as one:
  #include <cstdio>

  int main() {
    char house[] = "a "
    "house "
    "of " "gold.";
    printf("A book holds %s\n ", house);
  }

Usually, such constructions are useful for readability only when you
have a long string literal that would span multiple lines in your source code.


The compiler notices two adjacent string literals and concatenates them.








### Unicode
Like character literals, string literals support Unicode: just prepend the literal with the appropriate prefix, such as L.


The following example assigns string literals to the arrays english and chinese:
char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

Printing Unicode to the console is surprisingly complicated. Typically, you need to ensure that the correct code page is selected. If you need to embed Unicode characters into a string literal, look at
wprintf in the <cwchar> header.




The String Class in C++

The standard C++ library provides a string class used to store a sequence of characters. This is not a built-in type, but it behaves like one in its most basic usage.

To use strings, you must include an additional header file in the source code, the <string> library:

// Include the string library
#include <string>

// Create a string variable
string greeting = "Hello";

// Output string value
cout << greeting;







String literals can have no prefix, or u8, L, u, and U prefixes to denote narrow character (single-byte or multi-byte), UTF-8, wide character (UCS-2 or UTF-16), UTF-16 and UTF-32 encodings, respectively. A raw string literal can have R, u8R, LR, uR, and UR prefixes for the raw version equivalents of these encodings. To create temporary or static std::string values, you can use string literals or raw string literals with an s suffix.











#include <string>
using namespace std::string_literals; // enables s-suffix for std::string literals

int main()
{

  // String literals
  auto s0 =   "hello"; // const char*
  auto s1 = u8"hello"; // const char*, encoded as UTF-8
  auto s2 =  L"hello"; // const wchar_t*
  auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
  auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32

  // Raw string literals containing unescaped \ and "
  auto R0 =   R"("Hello \ world")"; // const char*
  auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8
  auto R2 =  LR"("Hello \ world")"; // const wchar_t*
  auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
  auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

  // Combining string literals with standard s-suffix
  auto S0 =   "hello"s; // std::string
  auto S1 = u8"hello"s; // std::string
  auto S2 =  L"hello"s; // std::wstring
  auto S3 =  u"hello"s; // std::u16string
  auto S4 =  U"hello"s; // std::u32string

  // Combining raw string literals with standard s-suffix
  auto S5 =   R"("Hello \ world")"s;
  // std::string from raw const char*

  auto S6 = u8R"("Hello \ world")"s;
  // std::string from raw const char*, encoded as UTF-8

  auto S7 =  LR"("Hello \ world")"s;
  // std::wstring from raw const wchar_t*

  auto S8 =  uR"("Hello \ world")"s;
  // std::u16string from raw const char16_t*, encoded as UTF-16

  auto S9 =  UR"("Hello \ world")"s;
  // std::u32string from raw const char32_t*, encoded as UTF-32
}



Using embedded hexadecimal escape codes to specify string literals can cause unexpected results. The following example seeks to create a string literal that contains the ASCII 5 character, followed by the characters f, i, v, and e:

  "\x05five"

The actual result is a hexadecimal 5F, which is the ASCII code for an underscore, followed by the characters i, v, and e. To get the correct result, you can use one of these escape sequences:
"\005five"     // Use octal literal.
"\x05" "five"  // Use string splicing.

std::string literals, because they're std::string types, can be concatenated with the + operator that is defined for basic_string types. They can also be concatenated in the same way as adjacent string literals. In both cases, the string encoding and the suffix must match:
auto x1 = "hello" " " " world"; // OK
auto x2 = U"hello" " " L"world"; // C2308: disagree on prefix
auto x3 = u8"hello" " "s u8"world"s; // OK, agree on prefixes and suffixes
auto x4 = u8"hello" " "s u8"world"z; // C3688, disagree on suffixes

String literals with universal character names

Native (non-raw) string literals may use universal character names to represent any character, as long as the universal character name can be encoded as one or more characters in the string type. For example, a universal character name representing an extended character can't be encoded in a narrow string using the ANSI code page, but it can be encoded in narrow strings in some multi-byte code pages, or in UTF-8 strings, or in a wide string. In C++11, Unicode support is extended by the char16_t* and char32_t* string types:
// ASCII smiling face
const char*     s1 = ":-)";

// UTF-16 (on Windows) encoded WINKING FACE (U+1F609)
const wchar_t*  s2 = L"😉 = \U0001F609 is ;-)";

// UTF-8  encoded SMILING FACE WITH HALO (U+1F607)
const char*     s3 = u8"😇 = \U0001F607 is O:-)";

// UTF-16 encoded SMILING FACE WITH OPEN MOUTH (U+1F603)
const char16_t* s4 = u"😃 = \U0001F603 is :-D";

// UTF-32 encoded SMILING FACE WITH SUNGLASSES (U+1F60E)
const char32_t* s5 = U"😎 = \U0001F60E is B-)";

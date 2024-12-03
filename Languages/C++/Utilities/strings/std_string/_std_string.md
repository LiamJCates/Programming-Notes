The standard library contains many useful classes -- but perhaps the most useful is std::string. std::string (and std::wstring) is a string class that provides many operations to assign, compare, and modify strings.


The bottom line is that working with C-style strings requires remembering a lot of nit-picky rules about what is safe/unsafe, memorizing a bunch of functions that have funny names like strcat() and strcmp() instead of using intuitive operators, and doing lots of manual memory management.


STL supplies a template class that has been specially designed for string operations.

std::basic_string<T> is used popularly in its two template specializations:
  std::string — A char-based specialization of std::basic_string used for the manipulation of simple character strings.
  std::wstring— A wchar_t-based specialization of std::basic_string used for the manipulation of wide character strings typically used to store Unicode characters that support symbols from different languages.


These are the two classes that you will actually use. std::string is used for standard ascii and utf-8 strings. std::wstring is used for wide-character/unicode (utf-16) strings. There is no built-in class for utf-32 strings (though you should be able to extend your own from basic_string<> if you need one).

Although you will directly use std::string and std::wstring, all of the string functionality is implemented in the basic_string<> class. String and wstring are able to access that functionality directly by virtue of being templated. Consequently, all of the functions presented will work for both string and wstring. However, because basic_string is a templated class, it also means the compiler will produce horrible looking template errors when you do something syntactically incorrect with a string or wstring.

C++ strings are a programmer-defined data type.

The C++ standard library offers a string type to save most users from C-style manipulation of arrays of characters through pointers.

C++ standard strings are an efficient and safer way to deal with text input—and to perform string manipulations like concatenations.

std::string is not static in size like a char array implementation of a C style string is and can scale up when more data needs to be stored in it.

to use a C++ string, you need to include the header string:
 #include <string>

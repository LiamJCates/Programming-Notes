## Character Set

https://en.cppreference.com/w/cpp/language/charset
https://learn.microsoft.com/en-us/cpp/cpp/character-sets?view=msvc-170


C++ character set means the characters and the symbols that are may compose valid C++ applications.

There are several character sets specified by the C++ standard.

The standard names of some character sets are changed in C++23 via P2314R4.

New name(s) 	                  Old name(s)
basic character set             basic source character set

basic literal character set     basic execution character set
                                basic execution wide-character set

Mapping from source file (other than a UTF-8 source file)(since C++23) characters to the basic character set(until C++23)translation character set(since C++23) during translation phase 1 is implementation-defined, so an implementation is required to document how the basic source characters are represented in source files. 

### Basic source character set

The C++ standard specifies a basic source character set that may be used in source files. To represent characters outside of this set, additional characters can be specified by using a universal character name. 

 The basic source character set consists of 96 characters that may be used in source files. This set includes the space character, horizontal tab, vertical tab, form feed and new-line control characters, and this set of graphical characters:

a b c d e f g h i j k l m n o p q r s t u v w x y z

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

0 1 2 3 4 5 6 7 8 9

_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '

These are grouped to create and give the commands, expressions, words, c-statements, and other tokens.

### Universal character names

Because C++ programs can use many more characters than the ones specified in the basic source character set, you can specify these characters in a portable way by using universal character names. A universal character name consists of a sequence of characters that represent a Unicode code point. 

### Execution character sets

The execution character sets represent the characters and strings that can appear in a compiled program. These character sets consist of all the characters permitted in a source file, and also the control characters that represent alert, backspace, carriage return, and the null character. The execution character set has a locale-specific representation.


### Translation character set

The translation character set consists of the following elements:

    each abstract character assigned a code point in the Unicode codespace, and
    a distinct character for each Unicode scalar value not assigned to an abstract character. 

The translation character set is a superset of the basic character set and the basic literal character set (see below). 
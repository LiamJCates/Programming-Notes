The basic character type is char.

A char is guaranteed to be big enough to hold numeric values corresponding to the characters in the machine’s basic character set. That is, a char is the same size as a single machine byte.

There are several other character types, most of which exist to support internationalization and wider characters.

The remaining character types —
  wchar_t, char16_t, and char32_t — are used for extended character sets.

The wchar_t type is guaranteed to be large enough to hold any character in the machine’s largest extended character set.

The types char16_t and char32_t are intended for Unicode characters. (Unicode is a standard for representing characters used in essentially any natural language.)

[Programming Methods\Data Representations\Unicode.md]

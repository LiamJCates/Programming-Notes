Using unicode




Unicode is maintained by Unicode Consortium. 

It covers a wide range of characters. It contains representations for letters in languages such as English, Greek, Arabic etc., mathematical symbols, emoji and many more.

Unicode is a superset of ASCII.

There are three types of encoding available in Unicode.
They are UTF-8, UTF-16 and UTF-32.

UTF-8 uses 8 bits per character
UTF-16 uses 16 bit per character
UTF-32 uses 32 bits for a character

In UTF-8, the first 128 characters are the ASCII characters. Therefore, ASCII is valid in UTF-8. Usually, Unicode is used in internationalization and localization of computer software. This standard is also used in operating systems, XML, .NET framework and programming languages such as Java.


Unicode was designed to provide a single, unambiguous, and unifying representation of character in all written languages, a much bigger set of characters than those used in the English language. 

Prior to Unicode programmers used 7-bit ASCII and what came to be known as code pages. Code pages evolved as an attempt to standardize the interpretation of numbers greater than 127 (the upper limit of a 7-bit number) for different languages and cultures. Unicode was intended to take away the need for code pages, but it hasn’t quite achieved that goal. Code pages are still needed for backward compatibility, and (ironically) they are also used to indicate which character set encoding applies to a Unicode fi le. A very common misconception is that Unicode means each that character takes up 2 bytes instead of 1. That isn’t quite right. Unicode characters can and often do take up 2 bytes in memory, but they can take 1 byte (UTF-8 usually takes 1 byte per character) or more than 2 bytes (UTF-16 takes either 2 or 4 bytes per character). Version 6.2 of the Unicode standard supports more than 110, 000 characters. This is far more than the limit of 65,536 that would be imposed if Unicode were actually restricted to just 2 bytes.

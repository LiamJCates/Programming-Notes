## Character Types
The data type char is mainly used to represent single characters—that is, letters, digits, and special symbols.

Character types store human language data. The six character types are:
char The default type, always 1 byte. May or may not be signed.
(Example: ASCII.)Types 37
char16_t Used for 2-byte character sets. (Example: UTF-16.)
char32_t Used for 4-byte character sets. (Example: UTF-32.)
signed char Same as char but guaranteed to be signed.
unsigned char Same as char but guaranteed to be unsigned.
wchar_t Large enough to contain the largest character of the implementation’s locale. (Example: Unicode.)
The character types char, signed char, and unsigned char are called narrow
characters, whereas char16_t, char32_t, and wchar_t are called wide characters due
to their relative storage requirements.

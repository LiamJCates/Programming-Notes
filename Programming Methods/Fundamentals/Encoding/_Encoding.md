The representation of a character within the computer memory, in storage, and in data transmission, is dependent on a particular character encoding scheme, called the character set.

The choice of character set is one of the first to be made in designing a language syntax. There are several widely used character sets, such as the ASCll set, each containing a different set of special characters in addition to the basic letters and digits. The choice of character set is important in determining the type of input-output (I/O) equipment that can be used in implementing the language.

For example, an ASCII (or extended ASCII) scheme will use a single byte of computer memory, while a UTF-8 scheme will use one or more bytes, depending on the particular character being encoded.

Alternative ways to encode character values include specifying an integer value for a code point, such as an ASCII code value or a Unicode code point. This may be done directly via converting an integer literal to a character, or via an escape sequence.

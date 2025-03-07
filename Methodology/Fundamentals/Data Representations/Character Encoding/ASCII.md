The American Standard Code for Information Interchange (ASCII) table assigns integers to characters.

Each of the 128 values of the ASCII character set represents a different character.

For example:
the value 65 represents 'A'
the value 43 represents '+'.

Thus, each character has a predefined ordering represented by the numeric value associated with the character. This ordering is called a collating sequence, in the set.

The collating sequence is used when you compare characters.
For example,
the value representing 'B' is 66, so 'A' is smaller than 'B'.
Similarly, '+' is smaller than 'A' because 43 is smaller than 65.

ASCII codes 0 to 31 are the control code characters that control devices. These are mostly anachronisms. When the American Standards Association formalized ASCII in the 1960s, modern devices included teletype machines, magnetic tape readers, and dot-matrix printers. Some control codes still in common use are the following:

•	 0 (NULL) is used as a string terminator by programming languages.
•	 4 (EOT), the end of transmission, terminates shell sessions and PostScript printer communications.
•	 7 (BELL) causes a device to make a noise.
•	 8 (BS), the backspace, causes the device to erase the last character.
•	 9 (HT), the horizontal tab, moves a cursor several spaces to the right.
•	 10 (LF), the line feed, is used as the end-of-line marker on most operating systems.
•	 13 (CR), the carriage return, is used in combination with LF as the end-of-line marker on Windows systems.
•	 26 (SUB), the substitute character/end of file/ctrl-Z, suspends the currently executing interactive process on most operating systems.

The remainder of the ASCII table, codes from 32 to 127, is the printable characters. These represent the English characters, digits, and punctuation.

On most systems, the char type’s representation is ASCII. Although this relationship is not strictly guaranteed, it is a de facto standard.
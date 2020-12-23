Delimiters
A delimiter is a sequence of one or more characters for specifying the boundary between separate, independent regions of text.

For string literals, double quotations are the most common delimiters used:

  "Hi There!"

Most modern programming languages use unpaired bracket delimiters to specify string literals.
  Bracket delimiters, also called block delimiters, region delimiters, or balanced delimiters, mark both the start and end of a delimited region.
  Unpaired delimiters, use the same character to open and close the delimited region.



Delimiter Collision
Delimiter collision is a problem that occurs when a programmer intends delimiter symbols themselves to be part of the string literals value rather than to be interpreted as boundaries between separate regions.

An example of delimiter collision is a string literal, as shown above, which seeks to contain double quotations within the string:

  "A "Hello, World!" program is often written by people learning to code."

While the above may be intended to be a single string, many programming languages would interpret it as two strings:

  "A "
  " program is often written by people learning to code."

The result is unintended and the portion of the string that is missing typically causes issues with program interpretation by the machine.

Common methods of handling delimiter collision are:
  Doubling Up
  Dual Quoting
  Escape Sequences


Doubling Up
Some languages, such as Pascal, BASIC, DCL, Smalltalk, SQL, J, and Fortran, avoid delimiter collision by doubling up on the quotation marks that are intended to be part of the string literal itself:
  "I said, ""Can you hear me?"""

Dual Quoting
Some languages, such as Fortran, Modula-2, JavaScript, Python, and PHP avoid delimiter collision by allowing more than one quoting delimiter; in the case of two possible delimiters, this is known as dual quoting. Typically, this consists of allowing the programmer to delimit strings using either single quotations or double quotations:

  'I said, "Can you hear me?"'
  "This is John's apple."

Dual quoting does not allow having a single literal with both delimiters. The following is unsupported:

  'I said, "This is John's apple."'

This can be worked around by using string concatenation, a method of joining string literals:

  'I said, "This is ' + "John's" + ' apple."'

Escape Sequences
Escape sequences are a general technique for representing characters that are otherwise difficult to represent directly, including delimiters, nonprinting characters (such as backspaces), newlines, and whitespace characters (which are otherwise impossible to distinguish visually). They are accordingly widely used in string literals, and adding an escape sequence (either to a single character or throughout a string) is known as escaping.

One character is chosen as a prefix to give encodings for characters that are difficult or impossible to include directly. Most commonly this is backslash; in addition to other characters, a key point is that backslash itself can be encoded as a double backslash \\\ and for delimited strings the delimiter itself can be encoded by escaping, say by \\" for ":

  "I said, \\"Can you hear me?\\""

### What is JSON
JavaScript Object Notation, or JSON, has become the favorite way to encode data for moving between various systems.

JavaScript Object Notation (JSON) is a text-based, language-independent data interchange format for the serialization of data.

JSON is derived from the object literals of JavaScript as defined in the third edition of the ECMAScript Language Specification.

### Advantages
JSON-encoded data has several advantages over previous efforts in that it is very human-readable, easy to parse with programs, and not overly complicated.

JSON allows information be shared in an easy-to-digest format.
Having an easy-to-produce format provides benefits like
ease of programming
ease of proofreading or debugging
low cost of entry




MySQL has a native JSON data type.
So as with an INTEGER, a DECIMAL, or a DATE data type, we can store an entire JSON document in a cell.
Before the native JSON data type, there were special schemas or user-defined functions with limited JSON support.

MySQL 5.7 arrived with the ability to store roughly a gigabyte of data in a single table cell.

This new data type has proven to be very popular and has probably encouraged many site administrators to upgrade from much earlier versions of MySQL to gain access to it.



There are actually two standards for JSON:
Internet Engineering Task Force (IETF) Request For Comment (RFC) 7159 (16 pages) (https://tools.ietf.org/html/rfc7159)
European Computer Manufacturers Association (ECMA) Standard 404 (5 pages) (https://www.ecma-international.org/publica-tions/standards/Ecma-404.htm ).

This is a relatively short set of standards compared to the IETF RFC 5321 for the Simple Mail Transfer Protocol (SMTP) at 95 pages.





### Standard
However, the two standards for JSON are fairly explicit.
JSON has a grammar, and it is simple.
JSON is a series of tokens:
six structural characters "[" "]" "{" "}" ":" ","
strings,
numbers,
and three literal names (false, null, or true).

Objects begin and end with curly brackets, { and }
arrays begin and end with square brackets, [ and ]
A colon (:) is used to separate a name and a value.
Multiple objects or arrays are separated by commas (,).

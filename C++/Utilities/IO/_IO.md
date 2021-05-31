The C++ I/O stream library provides formatted and unformatted buffered I/O of text and numeric values.

C++ I/O uses a convenient abstraction called streams to perform input and output operations in sequential media such as the screen, the keyboard or a file.



### Streams

A stream is an entity where a program can either insert or extract data to/from. A stream represents an infinite sequence of bytes, usually characters.

The characters may be either normal characters (char) or wide characters (wchar_t).

Streams provide a universal character-based interface to any type of storage medium (for example, a file). There is no need to know details about the media associated to the stream or any of its internal specifications. All we need to know is that streams are a source/destination of characters, and that these characters are provided/accepted sequentially (i.e., one after another).

Streams work with built-in data types, and you can make user-defined types work with streams by overloading the insertion operator (<<) to put objects into streams, and the extraction operator (>>) to read objects from streams. Any object that can be written to one type of stream, can be written to all types of streams. In other words, as long as an object has a stream representation, any storage medium can accept objects with that stream representation.

The stream library's consistent interface makes it very friendly to use for outputting to the screen or sending files over a network and everything in-between.



### Stream Types
C++ I/O occurs in streams, which are sequences of bytes.

If bytes flow from a device like a keyboard, a disk drive, or a network connection etc., this is called an input operation

If bytes flow from to a device like a display screen, a printer, a disk drive, or a network connection, etc., this is called an output operation.

There are two types of streams:
  Input stream: A character sequence that flows from an input device.
  Output stream: A character sequence that flows to an output device.

The standard input device is usually the keyboard
The standard output device is usually the screen.

The standard library defines a handful of stream objects that can be used to access what are considered the standard sources and destinations of characters by the environment where the program runs:

| stream | description |
|--------|-------------|
| cin | standard input stream |
| cout | standard output stream |
| cerr | standard error (output) stream |
| clog | standard logging (output) stream |

cerr and clog are also output streams, so they essentially work like cout, with the only difference being that they identify streams for specific purposes: error messages and logging; which, in many cases, in most environment setups, they actually do the exact same thing: they print on screen, although they can also be individually redirected.


## Using Standard Library Streams
To perform standard stream I/O, C++ programs use the header file iostream:

  #include <iostream>

This header file contains, among others, the definitions of two data types:

  istream (input stream)  
  //converts a stream of characters (bytes) to typed objects

  ostream (output stream)
  //converts typed objects to a stream of characters (bytes)

two variable declarations:
  cin (pronounced ‘‘see-in’’), which stands for common input
  cout (pronounced ‘‘see-out’’), which stands for common output.

These variable declarations are similar to the following C++ statements:
  istream cin;
  ostream cout;

use std::cout (pronounced “standard see-out”) to write text data to the console
use std::cin (“standard see-in”) to read text and numbers from the console.

Variables of type istream are called input stream variables;
Variables of type ostream are called output stream variables.
A stream variable is either an input stream or output stream variable.



Operations on istreams and ostreams are typesafe, type-sensitive, and extensible to handle user-defined types

Stream operators:
insertion operator (<<):
```cpp
std::cout << "Hello World" << std::endl;    //sends to stream
```
extraction operator (>>):
```cpp
std::cin >> Variable;                       //reads from stream
```

These I/O operators are just like any other operators in C++, and you can overload them to handle a given object type in the way you overload any other operator.

The input operator, also known as an extractor (because it extracts data from a stream), takes std::istream& as its first parameter. It must be a non-const reference, because the function will modify the stream object. The second parameter must also be a non-const reference, because you will store the input value there.

By convention, the return type is std::istream&, and the return value is the first parameter. That lets you combine multiple input operations in a single expression.

### I/O Library Header Files

There are following header files important to C++ programs −

<iostream>
  Contains <istream> and <ostream>. This file defines the cin, cout, cerr and clog objects, which correspond to the standard input stream, the standard output stream, the un-buffered standard error stream and the buffered standard error stream, respectively. 	

<iomanip>
  This file declares services useful for performing formatted I/O with so-called parameterized stream manipulators, such as setw and setprecision.

<fstream>
  This file declares services for user-controlled file processing.




More: https://www.learncpp.com/cpp-tutorial/input-and-output-io-streams/





A C++ stream is a flow of data into or out of a program, such as the data written to cout or read from cin.


```
               ios_base
                  ^
                  |
                 ios        iomanip
                  ^
                  |
istream  <---- iostream ----> ostream       streambuf
 ^  ^            ^  ^          ^  ^           ^  ^
 |  |            |  |          |  |           |  |
 |  ifstream     |  fstream    |  ofstream    |  filebuf
 istringstream   stringstream  ostringstream  stringbuf
```

The library and its hierarchy of classes is split in different files:

  <ios>, <istream>, <ostream>, <streambuf> and <iosfwd> aren't usually included directly in most C++ programs. They describe the base classes of the hierarchy and are automatically included by other header files of the library that contain derived classes.

  <iostream> declares the objects used to communicate through the standard input and output (including cin and cout).

  <fstream> defines the file stream classes (like the template basic_ifstream or the class ofstream) as well as the internal buffer objects used with these (basic_filebuf). These classes are used to manipulate files using streams.
  <sstream>: The classes defined in this file are used to manipulate string objects as if they were streams.

  <iomanip> declares some standard manipulators with parameters to be used with extraction and insertion operators to modify internal flags and formatting options.


Elements of the iostream library (char instantitation) Classes:

  ios_base	Base class for streams (class )

  ios	Base class for streams (type-dependent components) (class )

  istream	Input stream (class )

  ostream	Output Stream (class )

  iostream	Input/output stream (class )

  ifstream	Input file stream class (class )

  ofstream	Output file stream (class )

  fstream	Input/output file stream class (class )

  istringstream	Input string stream (class )

  ostringstream	Output string stream (class )

  stringstream	Input/output string stream (class )

  streambuf	Base buffer class for streams (class )

  filebuf	File stream buffer (class )

  stringbuf	String stream buffer (class )


Objects:

  cin	Standard input stream (object )

  cout	Standard output stream (object )

  cerr	Standard output stream for errors (object )

  clog	Standard output stream for logging (object )


Types:

  fpos	Stream position class template (class template )

  streamoff	Stream offset type (type )

  streampos	Stream position type (type )

  streamsize	Stream size type (type )


Manipulators:

  boolalpha	Alphanumerical bool values (function )

  dec	Use decimal base (function )

  endl	Insert newline and flush (function )

  ends	Insert null character (function )

  fixed	Use fixed floating-point notation (function )

  flush	Flush stream buffer (function )

  hex	Use hexadecimal base (function )

  internal	Adjust field by inserting characters at an internal position (function )

  left	Adjust output to the left (function )

  noboolalpha	No alphanumerical bool values (function )

  noshowbase	Do not show numerical base prefixes (function )

  noshowpoint	Do not show decimal point (function )

  noshowpos	Do not show positive signs (function )

  noskipws	Do not skip whitespaces (function )

  nounitbuf	Do not force flushes after insertions (function )

  nouppercase	Do not generate upper case letters (function )

  oct	Use octal base (function )

  resetiosflags	Reset format flags (function )

  right	Adjust output to the right (function )

  scientific	Use scientific floating-point notation (function )

  setbase	Set basefield flag (function )

  setfill	Set fill character (function )

  setiosflags	Set format flags (function )

  setprecision	Set decimal precision (function )

  setw	Set field width (function )

  showbase	Show numerical base prefixes (function )

  showpoint	Show decimal point (function )

  showpos	Show positive signs (function )

  skipws	Skip whitespaces (function )

  unitbuf	Flush buffer after insertions (function )

  uppercase	Generate upper-case letters (function )

  ws	Extract whitespaces (function )

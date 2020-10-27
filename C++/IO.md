

You use std::cout (pronounced “standard see-out”) to write simple text data to the
console and use std::cin (“standard see-in”) to read text and numbers (entered using the
keyboard) from the console.

std::cout << "Hello World" << std::endl;

insertion operator: << sends to stream

std::cin >> Variable;

extraction operator: >> reads from stream

If the user input
needs to be stored in two variables, each containing data separated by a space, then you
can do so using one statement:
std::cin >> Variable1 >> Variable2;


Stream IO
C++ standard IO includes input from the keyboard and output to the console as well as other sources like files that support streaming

contrast with record based  or fixed IO

IOstreams can be used for a wide variety of data manipulations thanks to the following features:

    A 'stream' is internally nothing but a series of characters. The characters may be either normal characters (char) or wide characters (wchar_t). Streams provide you with a universal character-based interface to any type of storage medium (for example, a file), without requiring you to know the details of how to write to the storage medium. Any object that can be written to one type of stream, can be written to all types of streams. In other words, as long as an object has a stream representation, any storage medium can accept objects with that stream representation.
    Streams work with built-in data types, and you can make user-defined types work with streams by overloading the insertion operator (<<) to put objects into streams, and the extraction operator (>>) to read objects from streams.
    The stream library's unified approach makes it very friendly to use. Using a consistent interface for outputting to the screen and sending files over a network makes life easier.



I/O operators

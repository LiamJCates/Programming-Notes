

You use std::cout (pronounced “standard see-out”) to write simple text data to the console and use std::cin (“standard see-in”) to read text and numbers (entered using the keyboard) from the console.

std::cout << "Hello World" << std::endl;

insertion operator: << sends to stream

std::cin >> Variable;

extraction operator: >> reads from stream


Reading from the console has some catches. First, the console uses spaces
as delimiters. That means that if you put spaces in what you type, only the
letters up to the space are put into the string. Anything after the space, the
console saves for the next time your application calls cin. That situation can
be confusing. Second, if you want to read into a number, the user can type
any characters, not just numbers. The computer then goes through a bizarre
process that converts any letters into a meaningless number.

If the user input needs to be stored in two variables, each containing data separated by a space, then you can do so using one statement:
std::cin >> Variable1 >> Variable2;

cin is a stream so if we want to intake a space delimited phrase cin will only read the first word in a space delimited phrase. To get the whole line use:
getline([stream], [variable]);

string str;
getline(cin, str);









Stream IO
C++ standard IO includes input from the keyboard and output to the console as well as other sources like files that support streaming

contrast with record based  or fixed IO

IOstreams can be used for a wide variety of data manipulations thanks to the following features:

    A 'stream' is internally nothing but a series of characters. The characters may be either normal characters (char) or wide characters (wchar_t). Streams provide you with a universal character-based interface to any type of storage medium (for example, a file), without requiring you to know the details of how to write to the storage medium. Any object that can be written to one type of stream, can be written to all types of streams. In other words, as long as an object has a stream representation, any storage medium can accept objects with that stream representation.
    Streams work with built-in data types, and you can make user-defined types work with streams by overloading the insertion operator (<<) to put objects into streams, and the extraction operator (>>) to read objects from streams.
    The stream library's unified approach makes it very friendly to use. Using a consistent interface for outputting to the screen and sending files over a network makes life easier.



The C++ standard libraries provide an extensive set of input/output capabilities which we will see in subsequent chapters. This chapter will discuss very basic and most common I/O operations required for C++ programming.

C++ I/O occurs in streams, which are sequences of bytes. If bytes flow from a device like a keyboard, a disk drive, or a network connection etc. to main memory, this is called input operation and if bytes flow from main memory to a device like a display screen, a printer, a disk drive, or a network connection, etc., this is called output operation.
I/O Library Header Files

There are following header files important to C++ programs −
Sr.No 	Header File & Function and Description
1 	

<iostream>

This file defines the cin, cout, cerr and clog objects, which correspond to the standard input stream, the standard output stream, the un-buffered standard error stream and the buffered standard error stream, respectively.
2 	

<iomanip>

This file declares services useful for performing formatted I/O with so-called parameterized stream manipulators, such as setw and setprecision.
3 	

<fstream>

This file declares services for user-controlled file processing. We will discuss about it in detail in File and Stream related chapter.
The Standard Output Stream (cout)

The predefined object cout is an instance of ostream class. The cout object is said to be "connected to" the standard output device, which usually is the display screen. The cout is used in conjunction with the stream insertion operator, which is written as << which are two less than signs as shown in the following example.
Live Demo

#include <iostream>

using namespace std;

int main() {
   char str[] = "Hello C++";

   cout << "Value of str is : " << str << endl;
}

When the above code is compiled and executed, it produces the following result −

Value of str is : Hello C++

The C++ compiler also determines the data type of variable to be output and selects the appropriate stream insertion operator to display the value. The << operator is overloaded to output data items of built-in types integer, float, double, strings and pointer values.

The insertion operator << may be used more than once in a single statement as shown above and endl is used to add a new-line at the end of the line.
The Standard Input Stream (cin)

The predefined object cin is an instance of istream class. The cin object is said to be attached to the standard input device, which usually is the keyboard. The cin is used in conjunction with the stream extraction operator, which is written as >> which are two greater than signs as shown in the following example.
Live Demo

#include <iostream>

using namespace std;

int main() {
   char name[50];

   cout << "Please enter your name: ";
   cin >> name;
   cout << "Your name is: " << name << endl;

}

When the above code is compiled and executed, it will prompt you to enter a name. You enter a value and then hit enter to see the following result −

Please enter your name: cplusplus
Your name is: cplusplus

The C++ compiler also determines the data type of the entered value and selects the appropriate stream extraction operator to extract the value and store it in the given variables.

The stream extraction operator >> may be used more than once in a single statement. To request more than one datum you can use the following −

cin >> name >> age;

This will be equivalent to the following two statements −

cin >> name;
cin >> age;

The Standard Error Stream (cerr)

The predefined object cerr is an instance of ostream class. The cerr object is said to be attached to the standard error device, which is also a display screen but the object cerr is un-buffered and each stream insertion to cerr causes its output to appear immediately.

The cerr is also used in conjunction with the stream insertion operator as shown in the following example.
Live Demo

#include <iostream>

using namespace std;

int main() {
   char str[] = "Unable to read....";

   cerr << "Error message : " << str << endl;
}

When the above code is compiled and executed, it produces the following result −

Error message : Unable to read....

The Standard Log Stream (clog)

The predefined object clog is an instance of ostream class. The clog object is said to be attached to the standard error device, which is also a display screen but the object clog is buffered. This means that each insertion to clog could cause its output to be held in a buffer until the buffer is filled or until the buffer is flushed.

The clog is also used in conjunction with the stream insertion operator as shown in the following example.
Live Demo

#include <iostream>

using namespace std;

int main() {
   char str[] = "Unable to read....";

   clog << "Error message : " << str << endl;
}

When the above code is compiled and executed, it produces the following result −

Error message : Unable to read....

You would not be able to see any difference in cout, cerr and clog with these small examples, but while writing and executing big programs the difference becomes obvious. So it is good practice to display error messages using cerr stream and while displaying other log messages then clog should be used.

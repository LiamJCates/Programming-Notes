https://www.cplusplus.com/reference/cstdio/

The I/O stream library provides formatted and unformatted buffered I/O of text and numeric values.

In C++, I/O is a sequence of bytes, called a stream, from the source to the destination. The bytes are usually characters, unless the program requires other types of information, such as a graphic image or digital speech.

Therefore, a stream is a sequence of characters from the source to the destination.

There are two types of streams:
Input stream: A sequence of characters from an input device to the computer.
Output stream: A sequence of characters from the computer to an output device.

The standard input device is usually the keyboard
The standard output device is usually the screen.

To receive data from the keyboard and send output to the screen, every C++ program must use the header file iostream.
#include <iostream>

This header file contains, among others, the definitions of
two data types:
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

use std::cout (pronounced “standard see-out”) to write simple text data to the console
use std::cin (“standard see-in”) to read text and numbers from the console.

Variables of type istream are called input stream variables;
variables of type ostream are called output stream variables.
A stream variable is either an input stream variable or an output stream variable.

Operations on istreams and ostreams are typesafe, type-sensitive, and extensible to handle user-defined types



Stream operators:
insertion operator <<, sends to stream:
std::cout << "Hello World" << std::endl;

extraction operator >>, reads from stream:
std::cin >> Variable;



## Output
In <ostream>, the I/O stream library defines output for every built-in type. Further, it is easy to define output of a user-defined type.

The operator << (‘‘put to’’) is used as an output operator on objects of type ostream;

cout is the standard output stream
cerr is the standard stream for reporting errors.

By default, values written to cout are converted to a sequence of characters.


##  Input
In <istream>, the standard library offers istreams for input. Like ostreams, istreams deal with character string representations of built-in types and can easily be extended to cope with user-defined types.
The operator >> (‘‘get from’’) is used as an input operator;
cin is the standard input stream.
The type of the right-hand operand of >> determines what input is accepted and what is the target of the input operation

By default, >> skips initial whitespace

By default, a whitespace character, such as a space or a newline, terminates the read


Reading from the console has some catches. First, the console uses spaces
as delimiters. That means that if you put spaces in what you type, only the
letters up to the space are put into the string. Anything after the space, the
console saves for the next time your application calls cin. That situation can
be confusing. Second, if you want to read into a number, the user can type
any characters, not just numbers. The computer then goes through a bizarre
process that converts any letters into a meaningless number.

If the user input needs to be stored in two variables, each containing data separated by a space, then you can do so using one statement:
std::cin >> Variable1 >> Variable2;






















Data Type of a Valid Input
char
One printable character except the blank.

int
An integer, possibly preceded by a + or - sign.

double
A decimal number, possibly preceded by a + or - sign. If the actual data input is an integer, the input is converted to a decimal number with the zero decimal part.

When reading data into a char variable, after skipping any leading whitespace characters, the extraction operator >> finds and stores only the next character; reading stops after a single character.

To read data into an int or double variable, after skipping all leading whitespace characters and reading the plus or minus sign (if any), the extraction operator >> reads the digits of the number, including the decimal point for floating-point variables, and stops when it finds a whitespace character or a character other than a digit.


After the program terminates, any values left in the input stream are discarded. When you enter data for processing, the data values should correspond to the data types of the variables in the input statement. Recall that when entering a number for a double variable, it is not necessary for the input number to have a decimal part. If the input number is an integer and has no decimal part, it is converted to a decimal value. The computer, however, does not tolerate any other kind of mismatch. For example, entering a char value into an int or double variable causes serious errors, called input failure.



cin is a stream so if we want to intake a space delimited phrase cin will only read the first word in a space delimited phrase. To get the whole line use:



Stream Functions
| Usage | Effects |
|-------|---------|
| getline([stream], [variable]) | retrieve a whole line from a stream |
| stream.peek() |  |



cin Functions

| Usage | Effects |
|-------|---------|
| cin.get(charVar) | store the next input character in the variable varChar |
| cin.ignore(int, char) | specifies the number of characters to be ignored in a line or a character to ignore the stream until, whichever comes first. |
|  |  |


The extraction operator, when scanning for the next input in the input stream, skips whitespace such as blanks and the newline character. However, there are situations when these characters must also be stored and processed. For example, if you are processing text in a line-by-line fashion, you must know where in the input stream the newline character is located. Without identifying the position of the newline character, the program would not know where one line ends and another begins. The next few sections teach you how to input data into a program using the input functions, such as get, ignore, putback, and peek. These functions are associated with the data type istream and are called istream member functions. I/O functions such as get, are typically called stream member functions or stream functions.



Because I/O is fundamental to any programming language and because writing instructions to perform a specific I/O operation is not a job for everyone, every programming language provides a set of useful functions to perform specific I/O operations.






## cin and ignore()
When you want to process only partial data (say, within a line), you can use the stream function ignore to discard a portion of the input by specifying the number of characters to be ignored in a line or a character to ignore the stream until, whichever comes first.

When the function ignore is used without any arguments, then it only skips the very next character:
cin.ignore();

This statement is typically used to skip the newline character.




##  putback and peek
Suppose you are processing data that is a mixture of numbers and characters. Moreover, the numbers must be read and processed as numbers. You have also looked at many sets of sample data and cannot determine whether the next input is a character or a number. You could read the entire data set character by character and check whether a certain character is a digit. If a digit is found, you could then read the remaining digits of the number and somehow convert these characters into numbers. This programming code would be somewhat complex.

Fortunately, C++ provides two very useful stream functions that can be used effectively in these types of situations.

The stream function putback lets you put the last character extracted from the input stream by the get function back into the input stream.

The syntax to use the function putback is:
istreamVar.putback(ch);


istreamVar is an input stream variable, such as cin
ch is a char variable.

The stream function peek looks into the input stream and returns the next character value without removing it from the input stream.

The syntax to use the function peek is:
ch = istreamVar.peek();

istreamVar is an input stream variable, such as cin
ch is a char variable.



//Functions peek and putback
 #include <iostream>
 using namespace std;
int main() {
  char ch;
  cout << "Enter a string: ";
  cin.get(ch);
  cout << endl;
  cout << "After first cin.get(ch); ch = " << ch << endl;
  cin.get(ch);
  cout << "After second cin.get(ch); ch = " << ch << endl;
  cin.putback(ch);
  cin.get(ch);
  cout << "After putback cin.get(ch); ch = " << ch << endl;
  ch = cin.peek();
  cout << "After cin.peek(); ch = " << ch << endl;
  cin.get(ch);
  cout << "After cin.get(ch); ch = " << ch << endl;  
}

Sample Run: In this sample run, the user input is shaded.
Enter a string: abcd
After first cin.get(ch); ch = a
After second cin.get(ch); ch = b
After putback and cin.get(ch); ch = b
After cin.peek(); ch = c
After cin.get(ch); ch = c



## Input Failure
What about an attempt to read invalid data? For example, what would happen if
you tried to input a letter into an int variable? If the input data did not match the
corresponding variables, the program would run into problems. For example, trying to read a letter into an int or double variable would result in an input failure.

The input stream then enters a state called the fail state.
What actually happens when the input stream enters the fail state? Once an input
stream enters the fail state, all further I/O statements using that stream are ignored.
Unfortunately, the program quietly continues to execute with whatever values are
stored in variables and produces incorrect results.


### checking for Failure
Once an input stream enters a fail state, all subsequent input statements associated with that input stream are ignored, and the computer continues to
execute the program, which produces erroneous results. You can use if statements4
Relational Operators and the string Type | 219
to check the status of an input stream variable and, if the input stream enters the fail
state, include instructions that stop program execution.
In addition to reading invalid data, other events can cause an input stream to enter
the fail state. Two additional common causes of input failure are the following:
? Attempting to open an input file that does not exist
? Attempting to read beyond the end of an input file
One way to address these causes of input failure is to check the status of the input
stream variable. You can check the status by using the input stream variable as the
logical expression in an if statement. If the last input succeeded, the input stream
variable evaluates to true; if the last input failed, it evaluates to false.
The statement:
if (cin)
cout << "Input is OK." << endl;
prints:
Input is OK.
if the last input from the standard input device succeeded. Similarly, if infile is an
ifstream variable, the statement:
if (!infile)
cout << "Input failed." << endl;
prints:
Input failed.
if the last input associated with the stream variable infile failed.
Suppose an input stream variable tries to open a file for inputting data into a program.
If the input file does not exist, you can use the value of the input stream variable, in
conjunction with the return statement, to terminate the program







## The clear Function
When an input stream enters the fail state, the system ignores all further I/O using
that stream. You can use the stream function clear to restore the input stream to a working state.

The syntax to use the function clear is:
istreamVar.clear();

Here, istreamVar is an input stream variable, such as cin.
After using the function clear to return the input stream to a working state, you still
need to clear the rest of the garbage from the input stream. This can be accomplished
by using the function ignore.





nput/Output and the string Type
You can use an input stream variable, such as cin, and the extraction operator >> to
read a string into a variable of the data type string. For example, if the input is the
string "Shelly", the following code stores this input into the string variable name:
string name; //variable declaration
cin >> name; //input statement


Recall that the extraction operator skips any leading whitespace characters and
that reading stops at a whitespace character. As a consequence, you cannot use the extraction operator to read strings that contain blanks. For example, suppose that the
variable name is defined as noted above. If the input is:
Alice Wonderland
then after the statement:
cin >> name;
executes, the value of the variable name is "Alice".
To read a string containing blanks, you can use the function getline.
The syntax to use the function getline is:
getline(istreamVar, strVar);
where istreamVar is an input stream variable and strVar is a string variable.
The reading is delimited by the newline character '\n'.
The function getline reads until it reaches the end of the current line. The newline
character is also read but not stored in the string variable.







eof Function
In addition to checking the value of an input stream variable, such as cin, to determine whether the end of the file has been reached, C++ provides a function that you
can use with an input stream variable to determine the end-of-file status. This function is called eof.


The syntax to use the function eof is:
istreamVar.eof()

in which istreamVar is an input stream variable, such as cin.
Suppose you have the declaration:
ifstream infile;

Further suppose that you opened a file using the variable infile. Consider the
expression:
infile.eof()
This is a logical (Boolean) expression. The value of this expression is true if the program has read past the end of the input file, infile; otherwise, the value of this
expression is false.
Using the function eof to determine the end-of-file status works best if the input is
text. The earlier method of determining the end-of-file status works best if the input
consists of numeric data.
Suppose you have the declaration:
ifstream infile;
char ch;
infile.open("inputDat.dat");
The following while loop continues to execute as long as the program has not reached
the end of the file:
infile.get(ch);
while (!infile.eof())
{
cout << ch;
infile.get(ch);
}
As long as the program has not reached the end of the input file, the expression:
infile.eof()
is false and so the expression:
!infile.eof()
in the while statement is true. When the program reads past the end of the input
file, the expression:
infile.eof()
becomes true, so the expression:
!infile.eof()
in the while statement becomes false and the loop terminates.



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











Summary
A stream in C++ is an infinite sequence of characters from a source to a destination.
An input stream is a stream from a source to a computer.
An output stream is a stream from a computer to a destination.

cin, which stands for common input, is an input stream object, typically initialized to the standard input device, which is the keyboard.

cout, which stands for common output, is an output stream object, typically initialized to the standard output device, which is the screen.

When the binary operator >> is used with an input stream object, such as cin, it is called the stream extraction operator. The left-side operand of >> must be an input stream variable, such as cin; the right-side operand
must be a variable.

When the binary operator << is used with an output stream object, such as cout, it is called the stream insertion operator. The left-side operand of << must be an output stream variable, such as cout; the right-side operand of << must be an expression or a manipulator.

When inputting data into a variable, the operator >> skips all leading whitespace characters.

To use cin and cout, the program must include the header file iostream.

The function get is used to read data on a character-by-character basis and does not skip any whitespace characters.

The function ignore is used to skip data in a line.

The function putback puts the last character retrieved by the function get back into the input stream.

The function peek returns the next character from the input stream but does not remove the character from the input stream.

Attempting to read invalid data into a variable causes the input stream to enter the fail state.

Once an input failure has occurred, you use the function clear to restore the input stream to a working state.

The manipulator setprecision formats the output of floating-point numbers to a specified number of decimal places.

The manipulator fixed outputs floating-point numbers in the fixed decimal format.

The manipulator showpoint outputs floating-point numbers with a
decimal point and trailing zeros.

In C++, ' (single-quote mark) is digit separator.

The manipulator setw formats the output of an expression in a specific number of columns; the default output is right-justified.

If the number of columns specified in the argument of setw is less than the number of columns needed to print the value of the expression, the output is not truncated and the output of the expression expands to the required number of columns.

The manipulator setfill is used to fill the unused columns on an output device with a character other than a space.

If the number of columns specified in the setw manipulator exceeds the number of columns required by the next expression, the output is rightjustified. To left-justify the output, you use the manipulator left.
To use the stream functions get, ignore, putback, peek, clear, and unsetf for standard I/O, the program must include the header file iostream.

To use the manipulators setprecision, setw, and setfill, the
program must include the header file iomanip.

The header file fstream contains the definitions of ifstream and ofstream.

For file I/O, you must use the statement #include <fstream> to include the header file fstream in the program. You must also do the following: declare variables of type ifstream for file input and of type ofstream for file output and use open statements to open input and output files. You can use <<, >>, get, ignore, peek, putback, or clear with file stream variables.

To close a file as indicated by the ifstream variable inFile, you use the statement inFile.close();. To close a file as indicated by the ofstream variable outFile, you use the statement outFile.close();.

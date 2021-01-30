Stream Functions



## Input Functions

The input functions, such as get, ignore, putback, and peek are associated with the data type istream and are called istream member functions.

| Usage | Effects |
|-------|---------|
| get(charVar) | store the next input character in the variable varChar |
| ignore(int, char) | specifies the number of characters to be ignored in a line or a character to ignore the stream until, whichever comes first. |
| getline([stream], [variable]) | retrieve a whole line from a stream |
| putback(ch) | allows a character ch to be placed
| peek() | returns the next character value without removing it |
| clear() | restore the input stream to a working state |
| eof() | returns a boolean expression that determines  if a program has read past the end of the input file |



### getline

To get an entire line from a stream, getline takes the stream, such as cin, as the first argument, and the string variable as second.

The standard behavior that most users expect from a console program is that each time the program queries the user for input, the user introduces the field, and then presses ENTER (or RETURN). That is to say, input is generally expected to happen in terms of lines on console programs, and this can be achieved by using getline to obtain input from the user. Therefore, unless you have a strong reason not to, you should always use getline to get input in your console programs instead of extracting from cin.

	#include <string>
	#include <fstream>
	using namespace std;

	int main() {
		ifstream in("Scopy.cpp"); // Open for reading
		ofstream out("Scopy2.cpp"); // Open for writing
		string s;
		while(getline(in, s)) // Discards newline char
		out << s << "\n"; // ... must add it back
	}

getline( ) reads in the characters of each line until it discovers a newline (the termination character). However, it discards the newline and doesn’t store it in the resulting string object. Thus, if we want the copied file to look just like the source file, we must add the newline back in.

	Another interesting example is to copy the entire file into a single
	string object:
	#include <string>
	#include <iostream>
	#include <fstream>
	using namespace std;

	int main() {
		ifstream in("FillString.cpp");
		string s, line;
		while(getline(in, line))
			s += line + "\n";
		cout << s;
	}


Because of the dynamic nature of strings, you don’t have to worry about how much storage to allocate for a string; you can just keep adding things and the string will keep expanding to hold whatever you put into it.


### ignore

When you want to process only partial data (say, within a line), you can use the stream function ignore to discard a portion of the input by specifying the number of characters to be ignored in a line or a character to ignore the stream until, whichever comes first.

When ignore is used without arguments it only skips the very next character:

	stream.ignore();

This statement is typically used to skip the newline character.



### putback

The stream function putback lets you put the last character extracted from the input stream by the get function back into the input stream.

The syntax to use the function putback is:

	istreamVar.putback(ch);


istreamVar is an input stream variable, such as cin, ch is a char variable.



### peek

The stream function peek looks into the input stream and returns the next character value without removing it from the input stream.

The syntax to use the function peek is:

ch = istreamVar.peek();

istreamVar is an input stream variable, such as cin ,ch is a char variable.



### clear

When an input stream enters the fail state, the system ignores all further I/O using that stream. You can use the stream function clear to restore the input stream to a working state.

The syntax to use the function clear is:

	istreamVar.clear();

Here, istreamVar is an input stream variable, such as cin.

After using the function clear to return the input stream to a working state, you still need to clear the rest of the garbage from the input stream. This can be accomplished by using the function ignore.


### Checking state flags
The following member functions exist to check for specific states of a stream (all of them return a bool value):

bad()
    Returns true if a reading or writing operation fails. For example, in the case that we try to write to a file that is not open for writing or if the device where we try to write has no space left.
fail()
    Returns true in the same cases as bad(), but also in the case that a format error happens, like when an alphabetical character is extracted when we are trying to read an integer number.
eof()
    Returns true if a file open for reading has reached the end.
good()
    It is the most generic state flag: it returns false in the same cases in which calling any of the previous functions would return true. Note that good and bad are not exact opposites (good checks more state flags at once).


The member function clear() can be used to reset the state flags.

### eof

In addition to checking the value of an input stream variable, such as cin, to determine whether the end of the file has been reached, C++ provides a function that you can use with an input stream variable to determine the end-of-file status. This function is called eof.

The syntax to use the function eof is:

	istreamVar.eof()

in which istreamVar is an input stream variable, such as cin.

Suppose you have the declaration:

	ifstream infile;

and you opened a file using the variable infile:

	infile.eof()

This is a logical (Boolean) expression. The value of this expression is true if the program has read past the end of the input file, infile; otherwise, the value of this expression is false.

Using the function eof to determine the end-of-file status works best if the input is text. The earlier method of determining the end-of-file status works best if the input consists of numeric data.

Suppose you have the declaration:

	ifstream infile;
	char ch;
	infile.open("inputDat.dat");

The following while loop continues to execute as long as the program has not reached the end of the file:

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

## Output
In <ostream>, the I/O stream library defines output for every built-in type. Further, it is easy to define output of a user-defined type.


### The Standard Output Stream (cout)

cout is the standard output stream

The predefined object cout is an instance of ostream class. The cout object is said to be "connected to" the standard output device, which usually is the display screen.

The cout is used in conjunction with the stream insertion operator



### The operator <<

The operator << (‘‘put to’’) is used as an output operator on objects of type ostream;

The << operator inserts the data that follows it into the stream that precedes it. When the binary operator << is used with an output stream object, such as cout, it is called the stream insertion operator. The left-side operand of << must be an output stream variable, such as cout; the right-side operand of << must be an expression or a manipulator.

Multiple insertion operations (<<) may be chained in a single statement:

  cout << "This " << " is a " << "single C++ statement";

Chaining insertions is especially useful to mix literals and variables in a single statement.


### endl
std::endl may be used to add a new-line at the end of the line.

The endl manipulator produces a newline character, exactly as the insertion of '\n' does; but it also has an additional behavior: the stream's buffer (if any) is flushed, which means that the output is requested to be physically written to the device, if it wasn't already. This affects mainly fully buffered streams, and cout is (generally) not a fully buffered stream. Still, it is generally a good idea to use endl only when flushing the stream would be a feature and '\n' when it would not. Bear in mind that a flushing operation incurs a certain overhead, and on some devices it may produce a delay.


### Example

  #include <iostream>

  using namespace std;

  int main() {
     char str[] = "Hello C++";

     cout << "Value of str is : " << str << endl;
  }

Output:

  Value of str is : Hello C++


By default, values written to cout are converted to a sequence of characters.

The C++ compiler also determines the data type of variable to be output and selects the appropriate stream insertion operator to display the value. The << operator is overloaded to output data items of built-in types integer, float, double, strings and pointer values.

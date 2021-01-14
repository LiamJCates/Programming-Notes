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











std::cout and char pointers

At this point, you may have noticed something interesting about the way std::cout handles pointers of different types.

Consider the following example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14

#include <iostream>

int main()
{
    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hello!" };
    const char *name{ "Alex" };

    std::cout << nArray << '\n'; // nArray will decay to type int*
    std::cout << cArray << '\n'; // cArray will decay to type char*
    std::cout << name << '\n'; // name is already type char*

    return 0;
}

On the author’s machine, this printed:

003AF738
Hello!
Alex

Why did the int array print an address, but the character arrays printed strings?

The answer is that std::cout makes some assumptions about your intent. If you pass it a non-char pointer, it will simply print the contents of that pointer (the address that the pointer is holding). However, if you pass it an object of type char* or const char*, it will assume you’re intending to print a string. Consequently, instead of printing the pointer’s value, it will print the string being pointed to instead!

While this is great 99% of the time, it can lead to unexpected results. Consider the following case:

1
2
3
4
5
6
7
8
9

#include <iostream>

int main()
{
    char c{ 'Q' };
    std::cout << &c;

    return 0;
}

In this case, the programmer is intending to print the address of variable c. However, &c has type char*, so std::cout tries to print this as a string! On the author’s machine, this printed:

Q╠╠╠╠╜╡4;¿■A

Why did it do this? Well, it assumed &c (which has type char*) was a string. So it printed the ‘Q’, and then kept going. Next in memory was a bunch of garbage. Eventually, it ran into some memory holding a 0 value, which it interpreted as a null terminator, so it stopped. What you see may be different depending on what’s in memory after variable c.

This case is somewhat unlikely to occur in real-life (as you’re not likely to actually want to print memory addresses), but it is illustrative of how things work under the hood, and how programs can inadvertently go off the rails.

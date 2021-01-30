##  Input

In <istream>, the standard library offers the ostream data type to handle input. Variables of type istream deal with character string representations of built-in types and can easily be extended to cope with user-defined types.

To use istreams we must include the iostream header:

  #include <iostream>



### The Standard Input Stream (cin)

std::cin is the standard input stream.

The predefined object cin is an instance of istream class. The cin object is said to be "connected to" to the standard input device, which usually is the keyboard.

The cin is used in conjunction with the stream extraction operator.



### The operator >>

The stream extraction operator >> (‘‘get from’’) is used as an input operator on object of type istream.

The binary operator >> extracts data from the stream that precedes it into the variable that follows it. The left-side operand must be an input stream variable, such as cin; the right-side operand must be a variable.

Once the statement with the extraction operation on cin is reached, the program will wait for as long as needed until some input is introduced. Generally, this means that the program will wait for the user to enter some sequence with the keyboard. In this case, note that the characters introduced using the keyboard are only transmitted to the program when the ENTER (or RETURN) key is pressed.

The type of the right-hand operand of >> determines what input is accepted and what is the target of the input operation. If the type of the right-hand operand it is an integer, the format expected is a series of digits, if a he operand is a string, a sequence of characters is expected, etc.

This method also has a big drawback. What happens if an int variable is used and the user enters something else that cannot be interpreted as an integer? The extraction operation fails and, by default, lets the program continue without setting a value for variable i, producing undetermined results if the value of i is used later.

This is very poor program behavior. Most programs are expected to behave in an expected manner no matter what the user types, handling invalid values appropriately. Only very simple programs should rely on values extracted directly from cin without further checking.

Multiple extraction operations may be chained in a single statement:

cin >> a >> b;

This will be equivalent to the following two statements:

cin >> a;
cin >> b;

In both cases, the user is expected to introduce two values, one for variable a, and another for variable b. Any kind of space is used to separate two consecutive input operations; this may either be a space, a tab, or a new-line character.



### Example

  #include <iostream>

  using namespace std;

  int main() {
     char name[50];

     cout << "Please enter your name: ";
     cin >> name;
     cout << "Your name is: " << name << endl;

  }

Output:

Please enter your name: cplusplus
Your name is: cplusplus

The C++ compiler also determines the data type of the entered value and selects the appropriate stream extraction operator to extract the value and store it in the given variables.



### cin Complications

Reading from the console has some catches.

First, the console uses spaces as delimiters. That means that if you put spaces in what you type, only the letters up to the space are put into the string. Anything after the space, the console saves for the next time your application calls cin. That situation can be confusing.

Second, if you want to read into a number, the user can type any characters, not just numbers. The computer then goes through a bizarre process that converts any letters into a meaningless number.




### Data Type of a Valid Input

When reading data into a char variable, after skipping any leading whitespace characters, the extraction operator >> finds and stores only the next character; reading stops after a single character.

To read data into an int or double variable, after skipping all leading whitespace characters and reading the plus or minus sign (if any), the extraction operator >> reads the digits of the number, including the decimal point for floating-point variables, and stops when it finds a whitespace character or a character other than a digit.

After the program terminates, any values left in the input stream are discarded. When you enter data for processing, the data values should correspond to the data types of the variables in the input statement. Recall that when entering a number for a double variable, it is not necessary for the input number to have a decimal part. If the input number is an integer and has no decimal part, it is converted to a decimal value. The computer, however, does not tolerate any other kind of mismatch. For example, entering a char value into an int or double variable causes serious errors, called input failure.



## Input Failure

What about an attempt to read invalid data?

If the input data does not match the corresponding variables, the program would run into problems. For example, trying to read a letter into an int or double variable would result in an input failure.

The input stream then enters a state called the fail state.

In addition to reading invalid data, other events can cause an input stream to enter the fail state. Two additional common causes of input failure are the following:
  Attempting to open an input file that does not exist
  Attempting to read beyond the end of an input file

Once an input stream enters the fail state, all further I/O statements using that stream are ignored.

Unfortunately, the program quietly continues to execute with whatever values are stored in variables and produces incorrect results.


### checking for Failure

You can use if statements to check the status of an input stream variable and, if the input stream enters the fail state, include instructions that stop program execution.

You can check the status by using the input stream variable as the logical expression in an if statement. If the last input succeeded, the input stream
variable evaluates to true; if the last input failed, it evaluates to false:

if (cin)
  cout << "Input is OK." << endl;

prints:

  Input is OK.

If the last input from the standard input device succeeded.

Similarly, if infile is an ifstream variable, the statement:

if (!infile)
  cout << "Input failed." << endl;

prints:

  Input failed.

If the last input associated with the stream variable infile failed.

Suppose an input stream variable tries to open a file for inputting data into a program.  If the input file does not exist, you can use the value of the input stream variable, in conjunction with the return statement, to terminate the program

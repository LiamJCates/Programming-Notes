##  Input
In <istream>, the standard library offers istreams for input. Like ostreams, istreams deal with character string representations of built-in types and can easily be extended to cope with user-defined types.


### The Standard Input Stream (cin)

cin is the standard input stream.

The predefined object cin is an instance of istream class. The cin object is said to be attached to the standard input device, which usually is the keyboard.

The cin is used in conjunction with the stream extraction operator.



### The operator >>

The operator >> (‘‘get from’’) is used as an input operator;


When the binary operator >> is used with an input stream object, such as cin, it is called the stream extraction operator. The left-side operand of >> must be an input stream variable, such as cin; the right-side operand must be a variable.

This operation makes the program wait for input from cin; generally, this means that the program will wait for the user to enter some sequence with the keyboard. In this case, note that the characters introduced using the keyboard are only transmitted to the program when the ENTER (or RETURN) key is pressed. Once the statement with the extraction operation on cin is reached, the program will wait for as long as needed until some input is introduced.

The type of the right-hand operand of >> determines what input is accepted and what is the target of the input operation. If the type of the right-hand operand it is an integer, the format expected is a series of digits, if a he operand is a string, a sequence of characters is expected, etc.

This method also has a big drawback. What happens if an int variable is used and the user enters something else that cannot be interpreted as an integer? The extraction operation fails and, by default, lets the program continue without setting a value for variable i, producing undetermined results if the value of i is used later.

This is very poor program behavior. Most programs are expected to behave in an expected manner no matter what the user types, handling invalid values appropriately. Only very simple programs should rely on values extracted directly from cin without further checking.

The stream extraction operator >> may be used more than once in a single statement:

cin >> name >> age;

This will be equivalent to the following two statements:

cin >> name;
cin >> age;

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

When reading data into a char variable, after skipping any leading whitespace characters, the extraction operator >> finds and stores only the next character; reading stops after a single character.

To read data into an int or double variable, after skipping all leading whitespace characters and reading the plus or minus sign (if any), the extraction operator >> reads the digits of the number, including the decimal point for floating-point variables, and stops when it finds a whitespace character or a character other than a digit.

After the program terminates, any values left in the input stream are discarded. When you enter data for processing, the data values should correspond to the data types of the variables in the input statement. Recall that when entering a number for a double variable, it is not necessary for the input number to have a decimal part. If the input number is an integer and has no decimal part, it is converted to a decimal value. The computer, however, does not tolerate any other kind of mismatch. For example, entering a char value into an int or double variable causes serious errors, called input failure.





Stream Functions
| Usage | Effects |
|-------|---------|
| getline([stream], [variable]) | retrieve a whole line from a stream |
| stream.peek() | returns the next character value without removing it |

To get an entire line from cin, getline takes the stream (cin) as first argument, and the string variable as second.

The standard behavior that most users expect from a console program is that each time the program queries the user for input, the user introduces the field, and then presses ENTER (or RETURN). That is to say, input is generally expected to happen in terms of lines on console programs, and this can be achieved by using getline to obtain input from the user. Therefore, unless you have a strong reason not to, you should always use getline to get input in your console programs instead of extracting from cin.


cin Functions

| Usage | Effects |
|-------|---------|
| cin.get(charVar) | store the next input character in the variable varChar |
| cin.ignore(int, char) | specifies the number of characters to be ignored in a line or a character to ignore the stream until, whichever comes first. |



The extraction operator, when scanning for the next input in the input stream, skips whitespace such as blanks and the newline character. However, there are situations when these characters must also be stored and processed. For example, if you are processing text in a line-by-line fashion, you must know where in the input stream the newline character is located. Without identifying the position of the newline character, the program would not know where one line ends and another begins.


The next few sections teach you how to input data into a program using the input functions, such as get, ignore, putback, and peek. These functions are associated with the data type istream and are called istream member functions. I/O functions such as get, are typically called stream member functions or stream functions.







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





Input/Output and the string Type
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

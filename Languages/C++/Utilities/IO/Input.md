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


### Custom Extraction
The I/O operators are just like any other operators in C++, and you can overload them the way you overload
any other operator.

The input operator, also known as an extractor (because it extracts data from a stream), takes std::istream& as its first parameter. It must be a non-const reference, because the function will modify the stream object.

The second parameter must also be a non-const reference, because you will store the input value there. By convention, the return type is std::istream&, and the return value is the first parameter.

That lets you combine multiple input operations in a single expression.

The body of the function must do the work of reading the input stream, parsing the input, and deciding how to interpret that input for a given type.

If the input is not valid, the input function sets failbit in the stream’s error state. When the caller tests whether the stream is okay, it tests the error state. If failbit is set, the check fails. (The test also fails if an unrecoverable error occurs, such as a hardware malfunction, but that’s not pertinent to the current topic.) Now you have to decide on a format for rational numbers. The format should be one that is flexible enough for a human to read and write easily but simple enough for a function to read and parse quickly. The input format must be able to read the output format and might be able to read other formats too. Let’s define the format as an integer, a slash (/), and another integer. White space can appear before or after any of these elements, unless the white space flag is disabled in the input stream. If the input contains an integer that is not followed by a slash, the integer becomes the resulting value (i.e., the implicit denominator is 1). The input operator has to “unread” the character, which may be important to the rest of the program. The unget() member function does exactly that. The input operator for integers will do the same thing: read as many characters as possible until reading a character that is not part of the integer, then unget that last character.   Notice how rat is not modified until the function has successfully read both the numerator and the denominator from the stream. The goal is to ensure that if the stream enters an error state, the function does not alter rat. 

The input stream automatically handles white space.

By default, the input stream skips leading white space in each input operation, which means the rational input operator skips white space before the numerator, the slash separator, and the denominator. If the program turns off the ws flag, the input stream does not skip white space, and all three parts must be contiguous.

```cpp
struct rational
{
    /// Constructs a rational object, given a numerator and a denominator.
    /// Always reduces to normal form.
    /// @param num numerator
    /// @param den denominator
    /// @pre denominator > 0
    rational(int num, int den)
        : numerator{num}, denominator{den}
    {
        reduce();
    }

    /// Assigns a numerator and a denominator, then reduces to normal form.
    /// @param num numerator
    /// @param den denominator
    /// @pre denominator > 0
    void assign(int num, int den)
    {
        numerator = num;
        denominator = den;
        reduce();
    }

    /// Reduces the numerator and denominator by their GCD.
    void reduce()
    {
        assert(denominator != 0);
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        int div{std::gcd(numerator, denominator)};
        numerator = numerator / div;
        denominator = denominator / div;
    }

    int numerator;   ///< numerator gets the sign of the rational value
    int denominator; ///< denominator is always positive
};

std::istream &operator>>(std::istream &in, rational &rat)
{
    int n{0}, d{0};
    char sep{'\0'};
    if (not(in >> n >> sep))
        // Error reading the numerator or the separator character.
        in.setstate(std::cin.failbit);
    else if (sep != '/')
    {
        // Read numerator successfully, but it is not followed by /.
        // Push sep back into the input stream, so the next input operation
        // will read it.
        in.unget();
        rat.assign(n, 1);
    }
    else if (in >> d)
        // Successfully read numerator, separator, and denominator.
        rat.assign(n, d);
    else
        // Error reading denominator.
        in.setstate(std::cin.failbit);
    return in;
}
```

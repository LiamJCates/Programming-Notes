## Manipulators

iostream manipulators don’t print anything, but change the state of the output stream.

The syntax of cout when used together with the insertion operator << is:

  cout << expression or manipulator << expression or manipulator...;

Here, expression is evaluated, its value is printed, and manipulator is used to format the output. The simplest manipulator that you have used so far is endl, which is used to move the insertion point to the beginning of the next line.
Other output manipulators that are of interest include setprecision, fixed, showpoint, and setw.


### setprecision Manipulator

You use the manipulator setprecision to control the output of floating-point numbers:

  setprecision(n);

where n is the number of decimal places.

You use the setprecision manipulator with cout and the insertion operator:

  cout << setprecision(2);

formats the output of decimal numbers to two decimal places until a similar subsequent statement changes the precision. Notice that the number of decimal places, or the precision value, is passed as an argument to setprecision.

To use the manipulator setprecision, include the header file iomanip:

  #include <iomanip>



### fixed Manipulator

To output floating-point numbers in a fixed decimal format, you use the manipulator fixed. The following statement sets the output of floating-point numbers in a fixed decimal format on the standard output device:

  cout << fixed;

After the preceding statement executes, all floating-point numbers are displayed in the fixed decimal format until the manipulator fixed is disabled. You can disable the manipulator fixed by using the stream member function unsetf. For example, to disable the manipulator fixed on the standard output device, you use the following statement:

  cout.unsetf(ios::fixed);

After the manipulator fixed is disabled, the output of the floating-point numbers returns to their default settings. The manipulator scientific is used to output floating-point numbers in scientific format.

On some compilers, the statements

  cout << fixed;
  cout << scientific;

might not work. In this case, you can use:

  cout.setf(ios::fixed);

in place of

  cout << fixed;

and

  cout.setf(ios::scientific);

in place of:

  cout << scientific;



### showpoint Manipulator

Suppose that the decimal part of a decimal number is zero. In this case, when you instruct the computer to output the decimal number in a fixed decimal format, the output may not show the decimal point and the decimal part. To force the output to show the decimal point and trailing zeros, you use the manipulator showpoint. The following statement sets the output of decimal numbers with a decimal point and trailing zeros on the standard output device:

  cout << showpoint;

Of course, the following statement sets the output of a floating-point number in a fixed decimal format with the decimal point and trailing zeros on the standard output device:

  cout << fixed << showpoint;



### C++14 Digit Separator

To make the reading and writing of long numbers easier C++14 introduces digit separator ' (single-quote character). So in C++ 14, the number 87523872918 can be represented as

  87'523'872'918
  87'523872'918
  8'7'5'2'3'8'7'2'9'1'8.



### setw

The manipulator setw is used to output the value of an expression in a specific number of columns. The value of the expression can be either a string or a number.

The expression setw(n) outputs the value of the next expression in n columns. The output is right-justified. Thus, if you specify the number of columns to be 8, for example, and the output requires only four columns, the first four columns are left blank.

Furthermore, if the number of columns specified is less than the number of columns required by the output, the output automatically expands to the required number of columns; the output is not truncated. For example, if x is an int variable, the following statement outputs the value of x in five columns on the standard output device:

  cout << setw(5) << x << endl;

To use the manipulator setw, the program must include the header file iomanip:

  #include <iomanip>

Unlike setprecision, which controls the output of all floating-point numbers until it is reset, setw controls the output of only the next expression.



### setfill Manipulator

Recall that in the manipulator setw, if the number of columns specified exceeds the number of columns required by the expression, the output of the expression is right-justified and the unused columns to the left are filled with spaces.

The output stream variables can use the manipulator setfill to fill the unused columns with a character other than a space.

The syntax to use the manipulator setfill is:

  ostreamVar << setfill(ch);

where ostreamVar is an output stream variable and ch is a character. For example, the statement:

  cout << setfill('#');

sets the fill character to '#' on the standard output device.
To use the manipulator setfill, the program must include the header file iomanip.



### left and right Manipulators

If the number of columns specified in the setw manipulator exceeds the number of columns required by the next expression, the default output is right-justified. Sometimes, you might want the output to be left-justified. To left-justify the output, you use the manipulator left:

  ostreamVar << left;

where ostreamVar is an output stream variable.

You can disable the manipulator left by using the stream function unsetf.

The syntax to disable the manipulator left is:

  ostreamVar.unsetf(ios::left);

where ostreamVar is an output stream variable.

Disabling the manipulator left returns the output to the settings of the default output format.

The syntax to set the manipulator right is:

  ostreamVar << right;

where ostreamVar is an output stream variable.


On some compilers, the statements

  cout << left;
  cout << right;

might not work.

Instead of cout << left, you can use:

  cout.setf(ios::left);

Instead of cout << right, you can use:

  cout.setf(ios::right);



### Boolalpha

The manipulator std::boolalpha (declared in <ios>, so you get it for free from
<iostream>) tells a stream to interpret bool values as words. By default, the words are true and false.

```cpp
#include <iostream>

int main()
{
std::cout << "true=" << true << '\n';
std::cout << "false=" << false << '\n';
std::cout << std::boolalpha;
std::cout << "true=" << true << '\n';
std::cout << "false=" << false << '\n';
}
```


By default, when an input stream has to read a bool value, it actually reads an integer, and if the integer’s
value is 1, the stream interprets that as true. The value 0 is false, and any other value results in an error.
With the std::boolalpha manipulator, the input stream requires the exact text true or false. Integers
are not allowed, nor are any case differences. The input stream accepts only those exact words.
Use the std::noboolalpha manipulator to revert to the default numeric Boolean values. Thus, you can
mix alphabetic and numeric representations of bool in a single stream, as follows:
bool a{true}, b{false};
std::cin >> std::boolalpha >> a >> std::noboolalpha >> b;
std::cout << std::boolalpha << a << ' ' << std::noboolalpha << b;
By default, std::format() converts a bool value to a string, like boolalpha. You can also format a bool
as an integer to format the value 0 or 1.
std::cout << std::format("{} {:d}\n", a, b);





We can also call manipulators as functions on a stream variable.

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    double toPrint[] = {1.0000, 2.000001, 3.123, 4.123456};
    std::cout.precision(3);
    std::cout.width(6);
    std::cout.fill('0');
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);

    for(auto d : toPrint)
        std::cout << d << std::endl;


    std::cout.precision(6);
    std::cout.width(10);
    std::cout.fill('-');
    std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);

    for(auto d : toPrint)
        std::cout << d << std::endl;
}
```

all manipulators are sticky. Except setw/width which seems to be reset after use.

the only reason that setw/width appears to behave differently is because there are requirements on formatted output operations to explicitly call width(0) on the output stream.

Because of this, after the first array element is printed the width goes back to 0.










### Custom Manipulator

Here is an Example how an object can be used to temporaily change the state then put it back by the use of an object:

```cpp
#include <iostream>
#include <iomanip>

// Private object constructed by the format object PutSquareBracket
struct SquareBracktAroundNextItem
{
    SquareBracktAroundNextItem(std::ostream& str)
        :m_str(str)
    {}
    std::ostream& m_str;
};

// New Format Object
struct PutSquareBracket
{};

// Format object passed to stream.
// All it does is return an object that can maintain state away from the
// stream object (so that it is not STICKY)
SquareBracktAroundNextItem operator<<(std::ostream& str,PutSquareBracket const& data)
{
    return SquareBracktAroundNextItem(str);
}

// The Non Sticky formatting.
// Here we temporariy set formating to fixed with a precision of 10.
// After the next value is printed we return the stream to the original state
// Then return the stream for normal processing.
template<typename T>
std::ostream& operator<<(SquareBracktAroundNextItem const& bracket,T const& data)
{
    std::ios_base::fmtflags flags               = bracket.m_str.flags();
    std::streamsize         currentPrecision    = bracket.m_str.precision();

    bracket.m_str << '[' << std::fixed << std::setprecision(10) << data << std::setprecision(currentPrecision) << ']';

    bracket.m_str.flags(flags);

    return bracket.m_str;
}


int main()
{

    std::cout << 5.34 << "\n"                        // Before
              << PutSquareBracket() << 5.34 << "\n"  // Temp change settings.
              << 5.34 << "\n";                       // After
}
```

> ./a.out
5.34
[5.3400000000]
5.34

Manipulator

Recall that the syntax of cout when used together with the insertion operator << is:
cout << expression or manipulator << expression or manipulator...;

Here, expression is evaluated, its value is printed, and manipulator is used to format the output. The simplest manipulator that you have used so far is endl, which is used to move the insertion point to the beginning of the next line.
Other output manipulators that are of interest include setprecision, fixed, showpoint, and setw.





### setprecision Manipulator
You use the manipulator setprecision to control the output of floating-point numbers

he general syntax of the setprecision manipulator is:
where n is the number of decimal places.
You use the setprecision manipulator with cout and the insertion operator. For
example, the statement:
cout << setprecision(2);
formats the output of decimal numbers to two decimal places until a similar subsequent statement changes the precision. Notice that the number of decimal places, or
the precision value, is passed as an argument to setprecision.
To use the manipulator setprecision, the program must include the header file
iomanip. Thus, the following include statement is required:
 #include <iomanip>



### fixed Manipulator
To output floating-point numbers in a fixed decimal format, you use the manipulator fixed. The following statement sets the output of floating-point numbers in a
fixed decimal format on the standard output device:
cout << fixed;
After the preceding statement executes, all floating-point numbers are displayed in the
fixed decimal format until the manipulator fixed is disabled. You can disable the manipulator fixed by using the stream member function unsetf. For example, to disable the
manipulator fixed on the standard output device, you use the following statement:
cout.unsetf(ios::fixed);
After the manipulator fixed is disabled, the output of the floating-point numbers
returns to their default settings. The manipulator scientific is used to output floating-point numbers in scientific format.

On some compilers, the statements cout << fixed; and cout << scientific;
might not work. In this case, you can use cout.setf(ios::fixed); in place of
cout << fixed; and cout.setf(ios::scientific); in place of cout <<
scientific;



### showpoint Manipulator
Suppose that the decimal part of a decimal number is zero. In this case, when you
instruct the computer to output the decimal number in a fixed decimal format, the
output may not show the decimal point and the decimal part. To force the output to
show the decimal point and trailing zeros, you use the manipulator showpoint. The
following statement sets the output of decimal numbers with a decimal point and
trailing zeros on the standard output device:
cout << showpoint;
Of course, the following statement sets the output of a floating-point number in a
fixed decimal format with the decimal point and trailing zeros on the standard output
device:
cout << fixed << showpoint;



C++14 Digit Separator
To make the reading and writing of long numbers easier C++14
introduces digit separator ' (single-quote character). So in C++ 14, the number
87523872918 can be represented as 87'523'872'918 or 87'523872'918 or 8'7'5'2'3'8'7'2'9'1'8.



setw
The manipulator setw is used to output the value of an expression in a specific
number of columns. The value of the expression can be either a string or a number.
The expression setw(n) outputs the value of the next expression in n columns. The
output is right-justified. Thus, if you specify the number of columns to be 8, for example, and the output requires only four columns, the first four columns are left blank.
Furthermore, if the number of columns specified is less than the number of columns
required by the output, the output automatically expands to the required number of
columns; the output is not truncated. For example, if x is an int variable, the following statement outputs the value of x in five columns on the standard output device:
cout << setw(5) << x << endl;
To use the manipulator setw, the program must include the header file iomanip.
Thus, the following include statement is required:
#include <iomanip>
Unlike setprecision, which controls the output of all floating-point numbers until
it is reset, setw controls the output of only the next expression.

setfill Manipulator
Recall that in the manipulator setw, if the number of columns specified exceeds the
number of columns required by the expression, the output of the expression is rightjustified and the unused columns to the left are filled with spaces. The output stream
variables can use the manipulator setfill to fill the unused columns with a character other than a space.
The syntax to use the manipulator setfill is:
ostreamVar << setfill(ch);
where ostreamVar is an output stream variable and ch is a character. For example,
the statement:
cout << setfill('#');
sets the fill character to '#' on the standard output device.
To use the manipulator setfill, the program must include the header file iomanip.







left and right Manipulators

If the number of columns specified in the setw manipulator exceeds the number of columns required by the next expression, the default output is rightjustified. Sometimes, you might want the output to be left-justified. To left-justify the
output, you use the manipulator left:
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


On some compilers, the statements cout << left; and cout << right; might not work. In this case, you can use cout.setf(ios::left); in place of cout << left; and cout.setf(ios::right); in place of cout << right;.

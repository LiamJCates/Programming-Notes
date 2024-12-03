https://en.cppreference.com/w/cpp/utility/format/format

New in C++ 20 is the format() function
Defined in header <format>


The first argument is a format string and subsequent arguments are values to format. The function knows how to format all the built-in types, plus types in the standard library, and you can define formatters for your custom types.

In the format string, each value to format, or field, is specified by a set of curly braces. Text outside of curly braces is copied verbatim. The format string is followed by the values to print as additional function arguments. For example,

std::format("x: {}, y: {}, z: {}\n", 10, 20, 30)

returns the following string:

x: 10, y: 20, z: 30

You can also number the fields, starting at zero. This is useful if the order in the format string does not match the order of the arguments. For example,

std::format("x: {2}, y: {1}, z: {0}\n", 10, 20, 30)

returns the following string:

x: 30, y: 20, z: 10

NOTE Do not mix numbered and unnumbered fields in a single format string.

For more control over the formatting, specify the formatting details after a colon. The details depend on the type of the argument. For standard types, the formatting specifier has the following parts. All parts are optional but if present must be in the following order:

fill-and-align sign # 0 width type

The specifier, if present, begins with an optional fill and alignment. The alignment is '<' for start adjustment, '^' for centered, and '>' for end adjustment. The fill character can be any character except '{' or '}'.

If you specify a fill character, you must also specify the alignment character. By default, numbers are end-adjusted and other types are start-adjusted.

Languages that read from left to right align start-adjusted fields on the left and end-adjusted fields on the right.

Languages that read from right to left reverse that so start-adjusted fields align on the right and end-adjusted fields align on the left.

After the fill and alignment is an optional sign:
'+' to emit a sign for all numbers
'-' to emit a sign only for negative numbers
' ' (space) to emit a sign for negative numbers and a blank for other values. The default is '-'.

Next is an optional '#' character to request an alternate form, such as a base prefix (0x for hexadecimal, 0b for binary, etc.).

The field width is next. If you don’t use a fill and alignment, you can use a '0' character to start the field width, which uses the default alignment and fills with '0' characters after the sign and base.

You can also use an argument as the field width by nesting a set of curly braces and an optional argument number in place of the field width.

Finally, an optional type letter further controls the formatting. For integers, you can use 'b' for binary output, 'd' for decimal, 'o' for octal, 'x' for hexadecimal, or 'c' to format the value as the equivalent character. The default for a character is 'c' and for an integer is 'd'.

For example,

std::format("'{0:c}': {0:#04x} {0:0>#10b} |{0:{1}d}| {2:s}\n", '*', 4, "str")

returns the following string:

'*': 0x2a 0b00101010 | 42| str




### Example

```cpp
//Printing a Multiplication Table Using the format Function
#include <format>
#include <iostream>
int main()
{
    int constexpr low{1};      ///< Minimum value for the table
    int constexpr high{10};    ///< Maximum value for the table
    int constexpr colwidth{4}; ///< Fixed width for all columns
    // First print the header.
    std::cout << std::format("{1:>{0}c}|", colwidth, '*');
    for (int i{low}; i <= high; i = i + 1)
        std::cout << std::format("{1:{0}}", colwidth, i);
    std::cout << '\n';
    // Print the table rule by using the fill character.
    std::cout << std::format("{2:->{0}}+{2:->{1}}\n",
                             colwidth, (high - low + 1) * colwidth, "");
    // For each row...
    for (int row{low}; row <= high; row = row + 1)
    {
        std::cout << std::format("{1:{0}}|", colwidth, row);
        // Print all the columns.
        for (int col{low}; col <= high; col = col + 1)
            std::cout << std::format("{1:{0}}", colwidth, row * col);
        std::cout << '\n';
    }
}
```

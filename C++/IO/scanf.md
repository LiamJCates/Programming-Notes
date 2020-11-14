int scanf ( const char * format, ... );

Read formatted data from stdin
Reads data from stdin and stores them according to the parameter format into the locations pointed by the additional arguments.

The additional arguments should point to already allocated objects of the type specified by their corresponding format specifier within the format string.

Parameters

format
    C string that contains a sequence of characters that control how characters extracted from the stream are treated:

        Whitespace character: the function will read and ignore any whitespace characters encountered before the next non-whitespace character (whitespace characters include spaces, newline and tab characters -- see isspace). A single whitespace in the format string validates any quantity of whitespace characters extracted from the stream (including none).
        Non-whitespace character, except format specifier (%): Any character that is not either a whitespace character (blank, newline or tab) or part of a format specifier (which begin with a % character) causes the function to read the next character from the stream, compare it to this non-whitespace character and if it matches, it is discarded and the function continues with the next character of format. If the character does not match, the function fails, returning and leaving subsequent characters of the stream unread.
        Format specifiers: A sequence formed by an initial percentage sign (%) indicates a format specifier, which is used to specify the type and format of the data to be retrieved from the stream and stored into the locations pointed by the additional arguments.


    A format specifier for scanf follows this prototype:

    %[*][width][length]specifier

<table>
    <thead>
        <tr>
            <th>specifier</th>
            <th>Description</th>
            <th>Characters Extracted</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>i</td>
            <td>Integer</td>
            <td> Any number of digits, optionally preceded by a sign (+ or -). Decimal digits assumed by default (0-9), but a 0 prefix introduces octal digits (0-7), and 0x hexadecimal digits (0-f). Signed argument.</td>
        </tr>
        <tr>
            <td>o</td>
            <td>Octal integer</td>
            <td>Any number of octal digits (0-7), optionally preceded by a sign (+ or -). Unsigned argument.</td>
        </tr>
        <tr>
            <td>x</td>
            <td>Hexadecimal integer</td>
            <td>Any number of hexadecimal digits (0-9, a-f, A-F), optionally preceded by 0x or 0X, and all optionally preceded by a sign (+ or -). Unsigned argument.</td>
        </tr>
        <tr>
            <td>f,e,g</td>
            <td rowspan="2">Floating point number</td>
            <td rowspan="2">A series of decimal digits, optionally containing a decimal point, optionally preceeded by a sign (+ or -) and optionally followed by the e or E character and a decimal integer (or some of the other sequences supported by strtod).
Implementations complying with C99 also support hexadecimal floating-point format when preceded by 0x or 0X.</td>
        </tr>
        <tr>
            <td>a</td>
        </tr>
        <tr>
            <td>c</td>
            <td>Character</td>
            <td>The next character. If a width other than 1 is specified, the function reads exactly width characters and stores them in the successive locations of the array passed as argument. No null character is appended at the end.</td>
        </tr>
        <tr>
            <td>s</td>
            <td>String of characters</td>
            <td>Any number of non-whitespace characters, stopping at the first whitespace character found. A terminating null character is automatically added at the end of the stored sequence.</td>
        </tr>
        <tr>
            <td>p</td>
            <td>Pointer Address</td>
            <td>A sequence of characters representing a pointer. The particular format used depends on the system and library implementation, but it is the same as the one used to format %p in fprintf.</td>
        </tr>
        <tr>
            <td>[characters]</td>
            <td>Scanset</td>
            <td>Any number of the characters specified between the brackets.
A dash (-) that is not the first character may produce non-portable behavior in some library implementations.</td>
        </tr>
        <tr>
            <td>[^characters]</td>
            <td>Negated Scanset</td>
            <td>Any number of characters none of them specified as characters between the brackets.</td>
        </tr>
        <tr>
            <td>n</td>
            <td>Count</td>
            <td>No input is consumed.
The number of characters read so far from stdin is stored in the pointed location.</td>
        </tr>
        <tr>
            <td>%</td>
            <td>%</td>
            <td>A % followed by another % matches a single %</td>
        </tr>
    </tbody>
</table>

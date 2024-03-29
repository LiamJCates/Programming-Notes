## std::cin and handling invalid input

Most programs that have a user interface of some kind need to handle user input.

Because text input is so free-form, it’s very easy for the user to enter input that is not expected.

As you write programs, you should always consider how users will (unintentionally or otherwise) misuse your programs. A well-written program will anticipate how users will misuse it, and either handle those cases gracefully or prevent them from happening in the first place (if possible). A program that handles error cases well is said to be robust.

In this lesson, we’ll take a look specifically at ways the user can enter invalid text input via std::cin, and show you some different ways to handle those cases.


Proper error-handling is difficult, but the basics are easy. Every stream has a state mask that keeps track of errors

I/O State Flags
badbit  Unrecoverable error
eofbit  End-of-file
failbit Invalid input or output
goodbit No errors


If the input is not valid, the input function sets the failbit in the stream’s error state.

inputStream.setstate(std::ios_base::failbit);

When the caller tests whether the stream has the fail bit set using .fail(), it tests the error state.

if(!inputStream.fail())

If failbit is set, the above check fails. (The test also fails if an unrecoverable error occurs, such as a hardware malfunction, but that’s not pertinent to the current topic.)


every stream has a mask of error flags. You can test these flags, set them, or clear them.

Testing the flags is a little unusual. The way most programs test for error conditions on a stream is to use the stream itself or an input operation as a condition.

As an input operator function returns the stream, these two approaches are equivalent.

A stream converts to a bool result by returning the inverse of its fail() function, which returns true, if failbit or badbit is set.

In the normal course of an input loop, the program progresses until the input stream is exhausted. The
stream sets eofbit when it reaches the end of the input stream. The stream’s state is still good, in that fail()
returns false, so the loop continues. However, the next time you try to read from the stream, it sees that no
more input is available, sets failbit, and returns an error condition. The loop condition is false, and the
loop exits.
The loop might also exit if the stream contains invalid input, such as non-numeric characters for integer
input, or the loop can exit if there is a hardware error on the input stream (such as a disk failure).


First, you can test for a hardware or similar error by calling the bad() member function, which returns
true if badbit is set. That means something terrible happened to the file, and the program can’t do anything
to fix the problem.

Next, test for normal end-of-file by calling the eof() member function, which is true only when
eofbit is set. If bad() and eof() are both false and fail() is true, this means the stream contains invalid
input. How your program should handle an input failure depends on your particular circumstances. Some
programs must exit immediately; others may try to continue. For example, your test program can reset the
error state by calling the clear() member function, then continue running. After an input failure, you may
not know the stream’s position, so you don’t know what the stream is prepared to read next. This simple test
program skips to the next line.


```cpp
/// Tests for failbit only
bool iofailure(std::istream &in)
{
    return in.fail() and not in.bad();
}
int main()
{
    rational r{0};
    while (std::cin)
    {
        if (std::cin >> r)
            // Read succeeded, so no failure state is set in the stream.
            std::cout << r << '\n';
        else if (not std::cin.eof())
        {
            // Only failbit is set, meaning invalid input. Clear the state,
            // and then skip the rest of the input line.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
    if (std::cin.bad())
        std::cerr << "Unrecoverable input failure\n";
}
```



### std::cin, buffers, and extraction

In order to discuss how std::cin and operator>> can fail, it first helps to know a little bit about how they work.

When we use operator>> to get user input and put it into a variable, this is called an “extraction”. The >> operator is accordingly called the extraction operator when used in this context.

When the user enters input in response to an extraction operation, that data is placed in a buffer inside of std::cin. A buffer (also called a data buffer) is simply a piece of memory set aside for storing data temporarily while it’s moved from one place to another. In this case, the buffer is used to hold user input while it’s waiting to be extracted to variables.

When the extraction operator is used, the following procedure happens:

    If there is data already in the input buffer, that data is used for extraction.
    If the input buffer contains no data, the user is asked to input data for extraction (this is the case most of the time). When the user hits enter, a ‘\n’ character will be placed in the input buffer.
    operator>> extracts as much data from the input buffer as it can into the variable (ignoring any leading whitespace characters, such as spaces, tabs, or ‘\n’).
    Any data that can not be extracted is left in the input buffer for the next extraction.

Extraction succeeds if at least one character is extracted from the input buffer. Any unextracted input is left in the input buffer for future extractions. For example:

int x{};
std::cin >> x;

If the user enters “5a”, 5 will be extracted, converted to an integer, and assigned to variable x. “a\n” will be left in the input stream for the next extraction.



### Failure

Extraction fails if the input data does not match the type of the variable being extracted to. For example:

int x{};
std::cin >> x;

If the user were to enter ‘b’, extraction would fail because ‘b’ can not be extracted to an integer variable.



### Validating input

The process of checking whether user input conforms to what the program is expecting is called input validation.

There are three basic ways to do input validation:

    Inline (as the user types)
        Prevent the user from typing invalid input in the first place.
    Post-entry (after the user types)
        Let the user enter whatever they want into a string, then validate whether the string is correct, and if so, convert the string to the
				final variable format.
        Let the user enter whatever they want, let std::cin and operator>> try to extract it, and handle the error cases.


#### Inline

Some graphical user interfaces and advanced text interfaces will let you validate input as the user enters it (character by character). Generally speaking, the programmer provides a validation function that accepts the input the user has entered so far, and returns true if the input is valid, and false otherwise. This function is called every time the user presses a key. If the validation function returns true, the key the user just pressed is accepted. If the validation function returns false, the character the user just input is discarded (and not shown on the screen). Using this method, you can ensure that any input the user enters is guaranteed to be valid, because any invalid keystrokes are discovered and discarded immediately. Unfortunately, std::cin does not support this style of validation.



#### Post-entry

Since strings do not have any restrictions on what characters can be entered, extraction is guaranteed to succeed (though remember that std::cin stops extracting at the first non-leading whitespace character).

Once a string is entered, the program can then parse the string to see if it is valid or not. However, parsing strings and converting string input to other types (e.g. numbers) can be challenging, so this is only done in rare cases.

Most often, we let std::cin and the extraction operator do the hard work. Under this method, we let the user enter whatever they want, have std::cin and operator>> try to extract it, and deal with the fallout if it fails. This is the easiest method, and the one we’ll talk more about below.

A sample program

Consider the following calculator program that has no error handling:

```cpp
#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}
```
Output:
```
Enter a double value: 5
Enter one of the following: +, -, *, or /: *
Enter a double value: 7
5 * 7 is 35
```

This simple program asks the user to enter two numbers and a mathematical operator.


Now, consider where invalid user input might break this program.

First, we ask the user to enter some numbers.
What if they enter something other than a number (e.g. ‘q’)?

In this case, extraction will fail.

Second, we ask the user to enter one of four possible symbols.

What if they enter a character other than one of the symbols we’re expecting? We’ll be able to extract the input, but we don’t currently handle what happens afterward.

Third, what if we ask the user to enter a symbol and they enter a string like “*q hello”?

Although we can extract the ‘*’ character we need, there’s additional input left in the buffer that could cause problems down the road.




### Types of invalid text input

We can generally separate input text errors into four types:

    Input extraction succeeds but the input is meaningless to the program (e.g. entering ‘k’ as your mathematical operator).
    Input extraction succeeds but the user enters additional input (e.g. entering ‘*q hello’ as your mathematical operator).
    Input extraction fails (e.g. trying to enter ‘q’ into a numeric input).
    Input extraction succeeds but the user overflows a numeric value.

Thus, to make our programs robust, whenever we ask the user for input, we ideally should determine whether each of the above can possibly occur, and if so, write code to handle those cases.

Let’s dig into each of these cases, and how to handle them using std::cin.




#### Error case 1: Extraction succeeds but input is meaningless

This is the simplest case. Consider the following execution of the above program:

Enter a double value: 5
Enter one of the following: +, -, *, or /: k
Enter a double value: 7

In this case, we asked the user to enter one of four symbols, but they entered ‘k’ instead. ‘k’ is a valid character, so std::cin happily extracts it to variable op, and this gets returned to main. But our program wasn’t expecting this to happen, so it doesn’t properly deal with this case (and thus never outputs anything).

The solution here is simple: do input validation. This usually consists of 3 steps:

1) Check whether the user’s input was what you were expecting.
2) If so, return the value to the caller.
3) If not, tell the user something went wrong and have them try again.

Here’s an updated getOperator() function that does input validation.

```cpp
char getOperator()
{
		while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
          return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // iterate loop and try again
}
```

As you can see, we’re using a while loop to continuously loop until the user provides valid input. If they don’t, we ask them to try again until they either give us valid input, shutdown the program, or destroy their computer.



#### Error case 2: Extraction succeeds but with extraneous input

Consider the following execution of the above program:

Enter a double value: 5*7

What do you think should print next?

Enter a double value: 5*7
Enter one of the following: +, -, *, or /: Enter a double value: 5 * 7 is 35

The program prints the right answer, but the formatting is all messed up.

Let’s take a closer look at why:

	getDouble() is called and prompts for a double value:
	"Enter a double value: "
	When the user enters “5*7” as input, that input goes into the buffer.
	The operator>> extracts the 5 to variable x, leaving “*7\n” in the buffer.

	getOperator() is called and prompts the user for a char:
	“Enter one of the following: +, -, *, or /:”
	The next extraction operator is called
	“*7\n” is waiting in the buffer, and is used instead of waiting for input.
	Consequently, it extracts the ‘*’ character, leaving “7\n” in the buffer.

	getDouble() is called and prompts for a double value:
	"Enter a double value: "
	The “7” in the buffer gets extracted without asking the user.

Even though the output is correct, it is all on the same line. The user never had an opportunity to enter additional data and hit enter (causing a newline), so the output prompts all get run together on the same line.

Although the above problem works, the execution is messy. It would be better if any extraneous characters entered were simply ignored.



### Ignoring Input
Fortunately, it’s easy to ignore characters:

```cpp
std::cin.ignore(100, '\n');  
// clear up to 100 characters out of the buffer, or until a '\n' character is removed
```

This call would remove up to 100 characters.
While it might work for most cases, if the user entered more than 100 characters we’ll get messy output again.

To ignore any number of characters, to std::cin.ignore(), we can pass:

std::numeric_limits<std::streamsize>::max()

std::numeric_limits<std::streamsize>::max() returns the largest value that can be stored in a variable of type std::streamsize. Passing this value to std::cin.ignore() causes it to disable the count check, effectively ignoring input of any size.

To ignore everything up to and including the next ‘\n’ character, we call

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

Because this line is quite long for what it does, it’s handy to wrap it in a function which can be called in place of std::cin.ignore().

```cpp
#include <limits> // for std::numeric_limits

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
```

Since the last character the user entered must be a ‘\n’, we can tell std::cin to ignore buffered characters until it finds a newline character (which is removed as well).

Let’s update our getDouble() function to ignore any extraneous input:

```cpp
double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    ignoreLine();
    return x;
}
```

Now our program will work as expected, even if we enter “5*7” for the first input -- the 5 will be extracted, and the rest of the characters will be removed from the input buffer. Since the input buffer is now empty, the user will be properly asked for input the next time an extraction operation is performed!

NOTE
Some legacy code passes 32767 to std::cin.ignore(). This is a magic number with no special meaning to std::cin.ignore() and should be avoided.

What’s that 32767 magic number?

As stated above, it tells std::cin.ignore() how many characters to ignore up to. That number is picked because it’s the largest signed value guaranteed to fit in a (2-byte) integer on all platforms.

The correct way to ignore an unlimited amount of input is shown above.



### Error case 3: Extraction fails

Now consider the following execution of the calculator program:

Enter a double value: a

You shouldn’t be surprised that the program doesn’t perform as expected, but how it fails is interesting:

Enter a double value: a
Enter one of the following: +, -, *, or /: Enter a double value:

and the program suddenly ends.

This looks pretty similar to the extraneous input case, but it’s a little different. Let’s take a closer look.

When the user enters ‘a’, that character is placed in the buffer. Then operator>> tries to extract ‘a’ to variable x, which is of type double. Since ‘a’ can’t be converted to a double, operator>> can’t do the extraction. Two things happen at this point: ‘a’ is left in the buffer, and std::cin goes into “failure mode”.

Once in ‘failure mode’, future requests for input extraction will silently fail. Thus in our calculator program, the output prompts still print, but any requests for further extraction are ignored. The program simply runs to the end and then terminates (without printing a result, because we never read in a valid mathematical operation).

Fortunately, we can detect whether an extraction has failed and fix it:

if (std::cin.fail()) // has a previous extraction failed?
{
    // yep, so let's handle the failure
    std::cin.clear(); // put us back in 'normal' operation mode
    ignoreLine(); // and remove the bad input
}

That’s it!

Let’s integrate that into our getDouble() function:

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
        }
        else // else our extraction succeeded
        {
            ignoreLine();
            return x; // so return the value we extracted
        }
    }
}

Note: Prior to C++11, a failed extraction would not modify the variable being extracted to. This means that if a variable was uninitialized, it would stay uninitialized in the failed extraction case. However, as of C++11, a failed extraction due to invalid input will cause the variable to be zero-initialized. Zero initialization means the variable is set to 0, 0.0, “”, or whatever value 0 converts to for that type.




#### Error case 4: Extraction succeeds but the user overflows a numeric value

Consider the following simple example:

```cppp
#include <cstdint>
#include <iostream>

int main()
{
    std::int16_t x{}; // x is 16 bits, holds from -32768 to 32767
    std::cout << "Enter a number between -32768 and 32767: ";
    std::cin >> x;

    std::int16_t y{}; // y is 16 bits, holds from -32768 to 32767
    std::cout << "Enter another number between -32768 and 32767: ";
    std::cin >> y;

    std::cout << "The sum is: " << x + y << '\n';
    return 0;
}
```

What happens if the user enters a number that is too large (e.g. 40000)?

Enter a number between -32768 and 32767: 40000
Enter another number between -32768 and 32767: The sum is: 32767

In the above case, std::cin goes immediately into “failure mode”, but also assigns the closest in-range value to the variable. Consequently, x is left with the assigned value of 32767. Additional inputs are skipped, leaving y with the initialized value of 0. We can handle this kind of error in the same way as a failed extraction.

Note: Prior to C++11, a failed extraction would not modify the variable being extracted to. This means that if a variable was uninitialized, it would stay uninitialized in the failed extraction case. However, as of C++11, an out-of-range failed extraction will cause the variable to be set to the closest in-range value.

Putting it all together

Here’s our example calculator with full error checking:

```cpp
#include <iostream>
#include <limits>

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        // Check for failed extraction
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input

            // the user can't enter a meaningless double value, so we don't need to worry about validating that
            return x;
        }
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine();

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees op is valid in this particular program
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}
```


### Conclusion

As you write your programs, consider how users will misuse your program, especially around text input. For each point of text input, consider:

    Could extraction fail?
    Could the user enter more input than expected?
    Could the user enter meaningless input?
    Could the user overflow an input?

You can use if statements and boolean logic to test whether input is expected and meaningful.

The following code will clear any extraneous input:
```cpp
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```
The following code will test for and fix failed extractions or overflow:
```cpp
if (std::cin.fail()) // has a previous extraction failed or overflowed?
{
    // yep, so let's handle the failure
    std::cin.clear(); // put us back in 'normal' operation mode
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
}
```
Finally, use loops to ask the user to re-enter input if the original input was invalid.

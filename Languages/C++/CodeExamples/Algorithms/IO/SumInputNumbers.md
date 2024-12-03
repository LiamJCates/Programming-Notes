#include <iostream>
int main()
{
  int sum = 0, value = 0;

  while (std::cin >> value)
    sum += value;

  std::cout << "Sum is: " << sum << std::endl;
}

When we use an istream as a condition, the effect is to test the state of the
stream. If the stream is valid—that is, if the stream hasn’t encountered an error—
then the test succeeds. An istream becomes invalid when we hit end-of-file or
encounter an invalid input, such as reading a value that is not an integer. An
istream that is in an invalid state will cause the condition to yield false.
Thus, our while executes until we encounter end-of-file (or an input error).

ENTERING AN END-OF-FILE FROM THE KEYBOARD
When we enter input to a program from the keyboard, different operating systems
use different conventions to allow us to indicate end-of-file. On Windows systems
we enter an end-of-file by typing a control-z—hold down the Ctrl key and press z—
followed by hitting either the Enter or Return key. On UNIX systems, including on
Mac OS X machines, end-of-file is usually control-d.

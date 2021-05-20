A halt is a flow control statement that terminates the program.

In C++, halts are implemented as functions (rather than keywords), so our halt statements will be function calls.

Next, a special function called std::exit() is called, with the return value from main() (the status code) passed in as an argument.

### When should you use a halt?

The short answer is “almost never”. In C++, destroying local objects is an important part of C++, and none of the above-mentioned functions clean up local variables. Exceptions are a better and safer mechanism for handling error cases.

Rule
Only use a halt if there is no safe way to return normally from the main function. Prefer using exceptions for handling errors safely.


### Halting Functions

When the following halting functions are used, programs must include the cstdlib header:

  #include <cstdlib>

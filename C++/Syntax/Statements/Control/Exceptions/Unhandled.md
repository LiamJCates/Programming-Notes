Unhandled Exceptions

A terminate handler function is a function automatically called when the exception handling process has to be abandoned for some reason. This happens when no catch handler can be found for a thrown exception.

If a matching handler (or ellipsis catch handler) cannot be found for the current exception, the predefined terminate run-time function is called.

  terminate();

Its default behavior is to call abort. A program may explicitly call the current terminate handler function by calling terminate.

If you want terminate to call some other function in your program before exiting the application, call the set_terminate function with the name of the function to be called as its single argument:

  std::set_terminate (terminate_handler f);

where f is a function that takes no parameters and returns no value (void) and terminate_handler is a function pointer type taking no parameters and returning void. The function shall terminate execution of the program without returning to the caller.

You can call set_terminate at any point in your program. The terminate routine always calls the last function given as an argument to set_terminate.

  // set_terminate example
  #include <iostream>       // std::cerr
  #include <exception>      // std::set_terminate
  #include <cstdlib>        // std::abort

  void myterminate ()
  {
    std::cerr << "terminate handler called\n";
    abort();  // forces abnormal termination
  }

  int main (void)
  {
    std::set_terminate (myterminate);
    throw 0;  // unhandled exception: calls terminate handler
    return 0;
  }

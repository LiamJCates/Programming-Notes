### std::terminate

The std::terminate() function is typically used in conjunction with exceptions. Although std::terminate can be called explicitly, it is more often called implicitly when an exception isn’t handled (and in a few other exception-related cases). By default, std::terminate() calls std::abort().

A program may explicitly call the current terminate handler function by calling terminate:

terminate();

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

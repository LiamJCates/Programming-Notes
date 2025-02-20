### The std::exit() function

std::exit() is a function that causes the program to terminate normally.

Normal termination means the program has exited in an expected way.

Note that the term normal termination does not imply anything about whether the program was successful (that’s what the status code is for). For example, let’s say you were writing a program where you expected the user to type in a filename to process. If the user typed in an invalid filename, your program would probably return a non-zero status code to indicate the failure state, but it would still have a normal termination.

std::exit() performs a number of cleanup functions.

First, objects with static storage duration are destroyed. Then some other miscellaneous file cleanup is done if any files were used. Finally, control is returned back to the OS, with the argument passed to std::exit() used as the status code.



### Calling std::exit() explicitly

Although std::exit() is called implicitly when function main() ends, std::exit() can also be called explicitly to halt the program before it would normally terminate.

Here is an example of using std::exit() explicitly:

  #include <cstdlib>
  #include <iostream>

  void cleanup()
  {
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
  }

  int main()
  {
    std::cout << 1 << '\n';
    cleanup();

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
  }

Output:

1
cleanup!

Note that the statements after the call to std::exit() never execute because the program has already terminated.

Although in the program above we call std::exit() from function main(), std::exit() can be called from any function to terminate the program at that point.

One important note about calling std::exit() explicitly: std::exit() does not clean up any local variables (either in the current function, or in functions up the call stack). Because of this, it’s generally better to avoid calling std::exit().



### std::atexit

Because std::exit() terminates the program immediately, you may want to manually do some cleanup (in the above example, we manually called function cleanup()) before terminating. Remembering to manually call a cleanup function before calling every call to exit() adds burden to the programmer.

To assist with this, C++ offers the std::atexit() function, which allows you to specify a function that will automatically be called on program termination via std:exit().

  #include <cstdlib> // for std::exit()
  #include <iostream>

  void cleanup()
  {
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
  }

  int main()
  {
    std::atexit(cleanup); // register cleanup() to be called automatically when std::exit() is called

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
  }

Output:

1
cleanup!

So why would you want to do this? It allows you to specify a cleanup function in one place (probably in main) and then not have to worry about remembering to call that function explicitly before calling std::exit().

A few notes here about std::atexit() and the cleanup function:
  First, because std::exit() is called implicitly when main() terminates, this will invoke any functions registered by std::atexit() if the program exits that way.
  Second, the function being registered must take no parameters and have no return value.
  Finally, you can register multiple cleanup functions using std::atexit() if you want, and they will be called in reverse order of registration (the last one registered will be called first).



### multi-threaded Exit

In multi-threaded programs, calling std::exit() can cause your program to crash (because the thread calling std::exit() will cleanup static objects that may still be accessed by other threads).

For this reason, C++ has introduced another pair of functions that work similarly to std::exit() and std::atexit() called std::quick_exit() and std::at_quick_exit().

  std::quick_exit() terminates the program normally, but does not clean up static objects, and may or may not do other types of cleanup.

  std::at_quick_exit() performs the same role as std::atexit() for programs terminated with std::quick_exit().

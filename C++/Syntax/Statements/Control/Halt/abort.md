### std::abort

The std::abort() function causes your program to terminate abnormally.

Abnormal termination means the program had some kind of unusual runtime error and the program couldn’t continue to run. For example, trying to divide by 0 will result in an abnormal termination.

std::abort() does not do any cleanup.

  #include <cstdlib>
  #include <iostream>

  int main()
  {
      std::cout << 1 << '\n';
      std::abort();

      // The following statements never execute
      std::cout << 2 << '\n';

      return 0;
  }

We will see cases where std::abort is called implicitly including the assert statement.

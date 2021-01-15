## Boolean Literals

The boolean literals are true and false.

To initialize Boolean types, you use either of the two Boolean literals.

bool trueBool = true;
bool falseBool = false;


If you want std::cout to print “true” or “false” instead of 0 or 1, you can use std::boolalpha. Here’s an example:

  #include <iostream>

  int main()
  {
      std::cout << true << '\n';
      std::cout << false << '\n';

      std::cout << std::boolalpha; // print bools as true or false

      std::cout << true << '\n';
      std::cout << false << '\n';
      return 0;
  }

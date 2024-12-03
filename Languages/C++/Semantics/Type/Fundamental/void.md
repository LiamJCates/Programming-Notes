void
void means “no type”
The void type has an empty set of values.
Consequentially, variables can not be defined with a type of void:

  void value; // won't work, variables can't be defined with a void type

Because a void object cannot hold a value, C++ disallows void objects. You use void in special situations, such as the return type for functions that don’t return any value. For example, the function taunt doesn’t return a value, so you declare its return type void:

  #include <cstdio>

  void taunt()
  {
    printf("Hey, laser lips, your mama was a snow blower.");
  }


Deprecated: Functions that do not take parameters

In C, void is used as a way to indicate that a function does not take any parameters:

  int getValue(void) // void here means no parameters
  {
    int x;
    std::cin >> x;
    return x;
  }

Although this will compile in C++ (for backwards compatibility reasons), this use of keyword void is considered deprecated in C++. The following code is equivalent, and preferred in C++:

  int getValue() // empty function parameters is an implicit void
  {
    int x;
    std::cin >> x;
    return x;
  }

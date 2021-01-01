## Inline
However, what if your function is a very simple one like the following?

int Max(int x, int y) {
   return (x > y)? x : y;
}

The overhead of performing an actual function call on this might be quite high for the amount of time spent actually executing Max.

This is why C++ compilers enable the programmer to declare such functions as inline. Keyword inline is the programmers’
request that these functions be expanded inline where called.

Compilers typically see this keyword as a request to place the contents of the function directly where the function has been invoked which increases the execution speed of the code.

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

 #include <iostream>

using namespace std;

inline int Max(int x, int y) {
   return (x > y)? x : y;
}

// Main function for the program
int main() {
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;

   return 0;
}

### Problems with Inline
Any change to an inline function could require all clients of the function to be recompiled because compiler would need to replace all the code once again otherwise it will continue with old functionality.

Classifying functions as inline can also result in a lot of code bloat, especially if the
function being inline does a lot of sophisticated processing. Using the inline keyword
should be kept to a minimum and reserved for only those functions that do very little and
need to do it with minimal overhead, as demonstrated earlier.

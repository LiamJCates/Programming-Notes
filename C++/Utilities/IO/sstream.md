The standard header <sstream> defines a type called stringstream that allows a string to be treated as a stream, and thus allowing extraction or insertion operations from/to strings in the same way as they are performed on cin and cout.

This feature is most useful to convert strings to numerical values and vice versa. For example, in order to extract an integer from a string we can write:

```cpp
string mystr ("1204");
int myint;
stringstream(mystr) >> myint;
```
The above code stores the numerical value 1204:
The first line declares a string type object, mystr, initialized to a value of "1204"
The second line declares an int variable, myint.
The third line then initializes a stringstream object with the value of the string and uses the extraction operator to extract, convert, and store the integer expressed by the string.

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
  string mystr;
  float price=0;
  int quantity=0;

  cout << "Enter price: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;
  return 0;
}
```

Output:

  Enter price: 22.25
  Enter quantity: 7
  Total price: 155.75

In this example, we acquire numeric values from the standard input indirectly: Instead of extracting numeric values directly from cin, we get lines from it into a string object (mystr), and then we extract the values from this string into the variables price and quantity. Once these are numerical values, arithmetic operations can be performed on them, such as multiplying them to obtain a total price.

With this approach of getting entire lines and extracting their contents, we separate the process of getting user input from its interpretation as data, allowing the input process to be what the user expects, and at the same time gaining more control over the transformation of its content into useful data by the program.

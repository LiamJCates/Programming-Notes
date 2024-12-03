### Swapping

If you have two strings and want to swap their values, there are two functions both named swap() that you can use.

void string::swap (string &str)
void swap (string &str1, string &str2)

Both functions swap the value of the two strings. The member function swaps *this and str, the global function swaps str1 and str2.
These functions are efficient and should be used instead of assignments to perform a string swap.

Sample code:

  string sStr1("red");
  string sStr2("blue");

  cout << sStr1 << " " << sStr2 << endl;
  swap(sStr1, sStr2);
  cout << sStr1 << " " << sStr2 << endl;
  sStr1.swap(sStr2);
  cout << sStr1 << " " << sStr2 << endl;

Output:

red blue
blue red
red blue

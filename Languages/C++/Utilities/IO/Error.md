The Standard Error Stream (cerr)

The predefined object cerr is an instance of ostream class. The cerr object is said to be attached to the standard error device, which is also a display screen but the object cerr is un-buffered and each stream insertion to cerr causes its output to appear immediately.

The cerr is also used in conjunction with the stream insertion operator as shown in the following example.

  #include <iostream>
  using namespace std;

  int main() {
     char str[] = "Unable to read....";

     cerr << "Error message : " << str << endl;
  }

Output:

  Error message : Unable to read....

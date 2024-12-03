### Capacity

The capacity of a string reflects how much memory the string allocated to hold its contents. This value is measured in string characters, excluding the NULL terminator. For example, a string with capacity 8 could hold 8 characters.

size_type string::capacity() const

Returns the number of characters a string can hold without reallocation.

  string sString("01234567");
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

Output:

Length: 8
Capacity: 15

Note that the capacity is higher than the length of the string! Although our string was length 8, the string actually allocated enough memory for 15 characters! Why was this done?

The important thing to recognize here is that if a user wants to put more characters into a string than the string has capacity for, the string has to be reallocated to a larger capacity. For example, if a string had both length and capacity of 8, then adding any characters to the string would force a reallocation. By making the capacity larger than the actual string, this gives the user some buffer room to expand the string before reallocation needs to be done.

As it turns out, reallocation is bad for several reasons:

First, reallocating a string is comparatively expensive. First, new memory has to be allocated. Then each character in the string has to be copied to the new memory. This can take a long time if the string is big. Finally, the old memory has to be deallocated. If you are doing many reallocations, this process can slow your program down significantly.

Second, whenever a string is reallocated, the contents of the string change to a new memory address. This means all references, pointers, and iterators to the string become invalid!

Note that it’s not always the case that strings will be allocated with capacity greater than length.

Let’s add one character over the string capacity and watch the capacity change:

  string sString("0123456789abcde");
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

  // Now add a new character
  sString += "f";
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

This produces the result:

Length: 15
Capacity: 15
Length: 16
Capacity: 31

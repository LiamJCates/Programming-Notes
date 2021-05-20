### get and put stream positioning

All I/O streams objects keep internally -at least- one internal position:

ifstream, like istream, keeps an internal get position with the location of the element to be read in the next input operation.

ofstream, like ostream, keeps an internal put position with the location where the next element has to be written.

Finally, fstream, keeps both, the get and the put position, like iostream.

These internal stream positions point to the locations within the stream where the next reading or writing operation is performed. These positions can be observed and modified using the following member functions:

tellg() and tellp()
These two member functions with no parameters return a value of the member type streampos, which is a type representing the current get position (in the case of tellg) or the put position (in the case of tellp).

seekg() and seekp()
These functions allow to change the location of the get and put positions. Both functions are overloaded with two different prototypes. The first form is:

seekg ( position );
seekp ( position );

Using this prototype, the stream pointer is changed to the absolute position position (counting from the beginning of the file). The type for this parameter is streampos, which is the same type as returned by functions tellg and tellp.

The other form for these functions is:

seekg ( offset, direction );
seekp ( offset, direction );

Using this prototype, the get or put position is set to an offset value relative to some specific point determined by the parameter direction. offset is of type streamoff. And direction is of type seekdir, which is an enumerated type that determines the point from where offset is counted from, and that can take any of the following values:

ios::beg	offset counted from the beginning of the stream
ios::cur	offset counted from the current position
ios::end	offset counted from the end of the stream

The following example uses the member functions we have just seen to obtain the size of a file:

// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  streampos begin,end;
  ifstream myfile ("example.bin", ios::binary);
  begin = myfile.tellg();
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  cout << "size is: " << (end-begin) << " bytes.\n";
  return 0;
}

size is: 40 bytes.

Notice the type we have used for variables begin and end:

streampos size;

streampos is a specific type used for buffer and file positioning and is the type returned by file.tellg(). Values of this type can safely be subtracted from other values of the same type, and can also be converted to an integer type large enough to contain the size of the file.

These stream positioning functions use two particular types: streampos and streamoff. These types are also defined as member types of the stream class:

Type	Member type	Description
streampos	ios::pos_type	Defined as fpos<mbstate_t>.
It can be converted to/from streamoff and can be added or subtracted values of these types.
streamoff	ios::off_type	It is an alias of one of the fundamental integral types (such as int or long long).

Each of the member types above is an alias of its non-member equivalent (they are the exact same type). It does not matter which one is used. The member types are more generic, because they are the same on all stream objects (even on streams using exotic types of characters), but the non-member types are widely used in existing code for historical reasons.

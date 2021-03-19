File: An area in secondary storage used to hold information.

The standard I/O header file, iostream, contains data types and variables that are used only for input from the standard input device and output to the standard output device.

C++ provides the following classes to perform output and input of characters to/from files:

    ofstream: Stream class to write on files
    ifstream: Stream class to read from files
    fstream: Stream class to both read and write from/to files.

Among other things, the fstream header file contains the definitions of two data types:
ifstream, which means input file stream and is similar to istream
ofstream, which means output file stream and is similar to ostream.

These classes are derived directly or indirectly from the classes istream and ostream. We have already used objects whose types were these classes: cin is an object of class istream and cout is an object of class ostream. Therefore, we have already been using classes that are related to our file streams. And in fact, we can use our file streams the same way we are already used to use cin and cout, with the only difference that we have to associate these streams with physical files.

The variables cin and cout are already defined and associated with the standard I/O devices, as well:
  \>>, get, ignore, putback, peek, and so on can be used with cin
  <<, setfill, and so on can be used with cout.

These same operators and functions are also available for file I/O, but the header file fstream does not declare variables to use them. You must declare variables called file stream variables, which include ifstream variables for input and ofstream variables for output. You then use these variables together with >>, <<, or other functions for I/O.

Remember that C++ does not automatically initialize user-defined variables.

Once you declare the fstream variables, you must associate these file variables with the I/O sources.

File I/O is a five-step process:
1. Include the header file fstream in the program.
2. Declare file stream variables.
3. Associate the file stream variables with the I/O sources.
4. Use the file stream variables with >>, <<, or other I/O functions.
5. Close the files.


We will now describe these five steps in detail.

Step 1 requires that the header file fstream be included in the program:

  #include <fstream>

Step 2 requires you to declare file stream variables:

  ifstream inData;
  ofstream outData;

The first statement declares inData to be an input file stream variable.
The second statement declares outData to be an output file stream variable.

Step 3 requires you to associate file stream variables with the I/O sources. This step is called opening the files. The stream member function open is used to open files.

The syntax for opening a file is:

  fileStreamVariable.open(sourceName);

Here, fileStreamVariable is a file stream variable, and sourceName is the name of the I/O file.

Variables of type string can also be used to read and store the names of input/output files. However, the argument to the function open must be a null-terminated string.

Values of type std::string are not null terminated like C-strings. Therefore, if we use a variable of type string to read the name of an input/output file and then use this variable to open a file, the value of the variable must (first) be converted to a C-string  using c_str:

  strVar.c_str()

The following statements illustrate how to use variables of type string to read the names of the input/output files during program execution and open those files:

  ifstream infile;
  string fileName;
  cout << "Enter the input file name: ";
  cin >> fileName;
  infile.open(fileName.c_str()); //open the input file

Of course, you must also include the header file string in the program. The output file has similar conventions.

Suppose you include the declaration from Step 2 in a program.

Further suppose that the input data is stored in a file called prog.dat.

The following statements associate inData with prog.dat and outData with prog.out. That is, the file prog.dat is opened for inputting data, and the file prog.out is opened for outputting data.

inData.open("prog.dat"); //open the input file; Line 1
outData.open("prog.out"); //open the output file; Line 2

The statement in Line 1 assumes that the file prog.dat is in the same directory (subdirectory) as your project. However, if this is in a different directory (subdirectory), then you must specify the path where the file is located, along with the name of the file.

For example, suppose that the file prog.dat is on a flash memory in drive H.

Then the statement in Line 1 should be modified as follows:
inData.open("h:\\prog.dat");


Step 4 typically works as follows. You use the file stream variables with >>, <<, or other I/O functions. The syntax for using >> or << with file stream variables is exactly the same as the syntax for using cin and cout. Instead of using cin and cout, however, you use the file stream variable names that were declared.

Once the I/O is complete, Step 5 requires closing the files.
Closing a file means that the file stream variables are disassociated from the storage area and are freed. Once these variables are freed, they can be reused for other file I/O. Moreover, closing an output file ensures that the entire output is sent to the file; that is, the buffer is emptied. You close files by using the stream function close. For example, assuming the program includes the declarations listed in Steps 2 and 3, the statements for closing the files are:

inData.close();
outData.close();

On some systems, it is not necessary to close the files. When the program terminates, the files are closed automatically. Nevertheless, it is a good practice to close the files yourself.

Also, if you want to use the same file stream variable to open another file, you must close the first file opened with that file stream variable.

  #include <fstream>
  #include <string>
  using namespace std;

  int main()
  {
    //Declare file stream variables such as the following
    ifstream inFile;
    ofstream outFile;

    string inFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    inFile.open(inFileName.c_str()); //open the input file

    string outFileName;
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outFile.open(outFileName.c_str()); //open the input file


    //Code for data manipulation

    //Close files
    inFile.close();
    outFile.close();
    return 0;
  }

Also, for comparison purposes, someone might want to process each file separately and then store the output in separate files. To accomplish this task efficiently, the user would prefer to specify the name of the input and/or output file at execution time rather than in the programming code. C++ allows the user to do so. Consider the following statements:

  cout << "Enter the input file name: ";
  cin >> fileName;
  infile.open(fileName); //open the input file
  ...
  cout << "Enter the output file name: ";
  cin >> fileName;
  outfile.open(fileName); //open the output file






Let's see an example:

  // basic file operations
  #include <iostream>
  #include <fstream>
  using namespace std;

  int main () {
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
  }

[file example.txt]
Writing this to a file.

This code creates a file called example.txt and inserts a sentence into it in the same way we are used to do with cout, but using the file stream myfile instead.

But let's go step by step:

Open a file
The first operation generally performed on an object of one of these classes is to associate it to a real file. This procedure is known as to open a file. An open file is represented within a program by a stream (i.e., an object of one of these classes; in the previous example, this was myfile) and any input or output operation performed on this stream object will be applied to the physical file associated to it.

In order to open a file with a stream object we use its member function open:

open (filename, mode);

Where filename is a string representing the name of the file to be opened, and mode is an optional parameter with a combination of the following flags:

ios::in	Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode.
ios::ate	Set the initial position at the end of the file.
If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

All these flags can be combined using the bitwise operator OR (|). For example, if we want to open the file example.bin in binary mode to add data we could do it by the following call to member function open:

ofstream myfile;
myfile.open ("example.bin", ios::out | ios::app | ios::binary);

Each of the open member functions of classes ofstream, ifstream and fstream has a default mode that is used if the file is opened without a second argument:

class	default mode parameter
ofstream	ios::out
ifstream	ios::in
fstream	ios::in | ios::out

For ifstream and ofstream classes, ios::in and ios::out are automatically and respectively assumed, even if a mode that does not include them is passed as second argument to the open member function (the flags are combined).

For fstream, the default value is only applied if the function is called without specifying any value for the mode parameter. If the function is called with any value in that parameter the default mode is overridden, not combined.

File streams opened in binary mode perform input and output operations independently of any format considerations. Non-binary files are known as text files, and some translations may occur due to formatting of some special characters (like newline and carriage return characters).

Since the first task that is performed on a file stream is generally to open a file, these three classes include a constructor that automatically calls the open member function and has the exact same parameters as this member. Therefore, we could also have declared the previous myfile object and conduct the same opening operation in our previous example by writing:

ofstream myfile ("example.bin", ios::out | ios::app | ios::binary);

Combining object construction and stream opening in a single statement. Both forms to open a file are valid and equivalent.

To check if a file stream was successful opening a file, you can do it by calling to member is_open. This member function returns a bool value of true in the case that indeed the stream object is associated with an open file, or false otherwise:

if (myfile.is_open()) { /* ok, proceed with output */ }

Closing a file
When we are finished with our input and output operations on a file we shall close it so that the operating system is notified and its resources become available again. For that, we call the stream's member function close. This member function takes flushes the associated buffers and closes the file:

myfile.close();

Once this member function is called, the stream object can be re-used to open another file, and the file is available again to be opened by other processes.

In case that an object is destroyed while still associated with an open file, the destructor automatically calls the member function close.

Text files
Text file streams are those where the ios::binary flag is not included in their opening mode. These files are designed to store text and thus all values that are input or output from/to them can suffer some formatting transformations, which do not necessarily correspond to their literal binary value.

Writing operations on text files are performed in the same way we operated with cout:

  // writing on a text file
  #include <iostream>
  #include <fstream>
  using namespace std;

  int main () {
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
      myfile << "This is a line.\n";
      myfile << "This is another line.\n";
      myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
  }

  [file example.txt]
  This is a line.
  This is another line.

Reading from a file can also be performed in the same way that we did with cin:

  // reading a text file
  #include <iostream>
  #include <fstream>
  #include <string>
  using namespace std;

  int main () {
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        cout << line << '\n';
      }
      myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
  }



  This is a line.
  This is another line.  

This last example reads a text file and prints out its content on the screen. We have created a while loop that reads the file line by line, using getline. The value returned by getline is a reference to the stream object itself, which when evaluated as a boolean expression (as in this while-loop) is true if the stream is ready for more operations, and false if either the end of the file has been reached or if some other error occurred.


program breaks up the input into whitespace-separated words instead of lines:

  #include <string>
  #include <iostream>
  #include <fstream>
  #include <vector>
  using namespace std;

  int main() {
    vector<string> words;
    ifstream in("GetWords.cpp");
    string word;

    while(in >> word)
      words.push_back(word);

    for(int i = 0; i < words.size(); i++)
      cout << words[i] << endl;
  }

gets the input one “word” at a time, and when this expression evaluates to “false” it means the end of the file has been reached. Of course, delimiting words by whitespace is quite crude, but it makes for a simple example.


get and put stream positioning
All i/o streams objects keep internally -at least- one internal position:

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

Binary files
For binary files, reading and writing data with the extraction and insertion operators (<< and >>) and functions like getline is not efficient, since we do not need to format any data and data is likely not formatted in lines.

File streams include two member functions specifically designed to read and write binary data sequentially: write and read. The first one (write) is a member function of ostream (inherited by ofstream). And read is a member function of istream (inherited by ifstream). Objects of class fstream have both. Their prototypes are:

write ( memory_block, size );
read ( memory_block, size );

Where memory_block is of type char* (pointer to char), and represents the address of an array of bytes where the read data elements are stored or from where the data elements to be written are taken. The size parameter is an integer value that specifies the number of characters to be read or written from/to the memory block.

// reading an entire binary file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  streampos size;
  char * memblock;

  ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory";

    delete[] memblock;
  }
  else cout << "Unable to open file";
  return 0;
}



the entire file content is in memory


Edit & Run


In this example, the entire file is read and stored in a memory block. Let's examine how this is done:

First, the file is open with the ios::ate flag, which means that the get pointer will be positioned at the end of the file. This way, when we call to member tellg(), we will directly obtain the size of the file.

Once we have obtained the size of the file, we request the allocation of a memory block large enough to hold the entire file:

memblock = new char[size];

Right after that, we proceed to set the get position at the beginning of the file (remember that we opened the file with this pointer at the end), then we read the entire file, and finally close it:

file.seekg (0, ios::beg);
file.read (memblock, size);
file.close();

At this point we could operate with the data obtained from the file. But our program simply announces that the content of the file is in memory and then finishes.

Buffers and Synchronization
When we operate with file streams, these are associated to an internal buffer object of type streambuf. This buffer object may represent a memory block that acts as an intermediary between the stream and the physical file. For example, with an ofstream, each time the member function put (which writes a single character) is called, the character may be inserted in this intermediate buffer instead of being written directly to the physical file with which the stream is associated.

The operating system may also define other layers of buffering for reading and writing to files.

When the buffer is flushed, all the data contained in it is written to the physical medium (if it is an output stream). This process is called synchronization and takes place under any of the following circumstances:

    When the file is closed: before closing a file, all buffers that have not yet been flushed are synchronized and all pending data is written or read to the physical medium.
    When the buffer is full: Buffers have a certain size. When the buffer is full it is automatically synchronized.
    Explicitly, with manipulators: When certain manipulators are used on streams, an explicit synchronization takes place. These manipulators are: flush and endl.
    Explicitly, with member function sync(): Calling the stream's member function sync() causes an immediate synchronization. This function returns an int value equal to -1 if the stream has no associated buffer or in case of failure. Otherwise (if the stream buffer was successfully synchronized) it returns 0.

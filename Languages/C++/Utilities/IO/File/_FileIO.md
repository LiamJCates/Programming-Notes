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

  [fileStreamVariable].open([sourceName]);

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

```cpp
//STEP 1: include the header file
#include <fstream>

#include <string>
using namespace std;

int main(void)
{
  // STEP 2: Declare file stream variables such as the following
  ifstream inFile;
  ofstream outFile;

  // STEP 2b: prompt the user for a file name
  string inFileName;
  cout << "Enter the input file name: ";
  cin >> inFileName;

  // The above step is unnecessary if using a hard-coded filename
  // EX: string filename = "File.txt";



  //STEP 3 (input):  Associate the file stream variables with the I/O sources.
  // Filename must use C type strings, the function c_str() converts a C++ string to a C string
  inFile.open(inFileName.c_str()); //open the input file


  //Alternative to STEP 2 / 3
  ifstream myInfile ("example.txt");


  //STEP 2b: for output to a file
  string outFileName;
  cout << "Enter the output file name: ";
  cin >> outFileName;
  // This step is unnecessary if your program uses a hard-coded filename in a sting variable
  // EX: string filename = "File.txt";


  //STEP 3 (output):  Associate the file stream variables with the I/O sources.
  // Filename must use C type strings, the function c_str() converts a C++ string to a C string
  outFile.open(outFileName.c_str()); //open the output file


  //Alternative to STEP 2 / 3
  ofstream myOutfile ("example.txt");

  //STEP 4: Code for data manipulation
  // ... explained below

  //STEP 5: Close files
  inFile.close();
  outFile.close();
  return 0;
}
```


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












### Opening A File

To check if a file stream was successful in opening a file, you can do it by calling to member is_open. This member function returns a bool value of true in the case that indeed the stream object is associated with an open file, or false otherwise:

if (myfile.is_open()) { /* ok, proceed with output */ }




### Closing A file

When we are finished with our input and output operations on a file we shall close it so that the operating system is notified and its resources become available again. For that, we call the stream's member function close. This member function takes flushes the associated buffers and closes the file:

myfile.close();

Once this member function is called, the stream object can be re-used to open another file, and the file is available again to be opened by other processes.

In case that an object is destroyed while still associated with an open file, the destructor automatically calls the member function close.




### Example Text Files
Text file streams are those where the ios::binary flag is not included in their opening mode. These files are designed to store text and thus all values that are input or output from/to them can suffer some formatting transformations, which do not necessarily correspond to their literal binary value.

Writing operations on text files are performed in the same way we operated with cout:

```cpp
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
```

  [file example.txt]
  This is a line.
  This is another line.

Reading from a file can also be performed in the same way that we did with cin:

```cpp
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
```


  This is a line.
  This is another line.  

This last example reads a text file and prints out its content on the screen. We have created a while loop that reads the file line by line, using getline. The value returned by getline is a reference to the stream object itself, which when evaluated as a boolean expression (as in this while-loop) is true if the stream is ready for more operations, and false if either the end of the file has been reached or if some other error occurred.


program breaks up the input into whitespace-separated words instead of lines:

```cpp
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
```

gets the input one “word” at a time, and when this expression evaluates to “false” it means the end of the file has been reached. Of course, delimiting words by whitespace is quite crude, but it makes for a simple example.

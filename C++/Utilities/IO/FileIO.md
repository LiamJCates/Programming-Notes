File: An area in secondary storage used to hold information.

The standard I/O header file, iostream, contains data types and variables that are used only for input from the standard input device and output to the standard output device. In addition, C++ provides a header file called fstream, which is used for file I/O.

Among other things, the fstream header file contains the definitions of two data types:
ifstream, which means input file stream and is similar to istream
ofstream, which means output file stream and is similar to ostream.

The variables cin and cout are already defined and associated with the standard I/O devices. In addition, >>, get, ignore, putback, peek, and so on can be used with cin, whereas <<, setfill, and so on can be used with cout.

These same operators and functions are also available for file I/O, but the header file fstream does not declare variables to use them. You must declare variables called file stream variables, which include ifstream variables for input and ofstream variables for output. You then use these variables together with >>, <<, or other functions for I/O. Remember that
C++ does not automatically initialize user-defined variables.

Once you declare the fstream variables, you must associate these file variables with the I/O sources.

File I/O is a five-step process:
1. Include the header file fstream in the program.
2. Declare file stream variables.
3. Associate the file stream variables with the I/O sources.
4. Use the file stream variables with >>, <<, or other I/O functions.
5. Close the files.

We will now describe these five steps in detail.

A skeleton program then shows how the steps might appear in a program.

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

Suppose you include the declaration from Step 2 in a program.

Further suppose that the input data is stored in a file called prog.dat.

The following statements associate inData with prog.dat and outData with prog.out. That is, the file prog.dat is opened for inputting data, and the file prog.out is opened for outputting data.

inData.open("prog.dat"); //open the input file; Line 1
outData.open("prog.out"); //open the output file; Line 2

he statement in Line 1
assumes that the file prog.dat is in the same directory (subdirectory) as your project. However, if this is in a different directory (subdirectory), then you must specify the path where the
file is located, along with the name of the file. For example, suppose that the file prog.dat
is on a flash memory in drive H. Then the statement in Line 1 should be modified as follows:
inData.open("h:\\prog.dat");


Step 4 typically works as follows. You use the file stream variables with >>, <<, or other
I/O functions. The syntax for using >> or << with file stream variables is exactly the
same as the syntax for using cin and cout. Instead of using cin and cout, however,
you use the file stream variable names that were declared.

Once the I/O is complete, Step 5 requires closing the files. Closing a file means that the
file stream variables are disassociated from the storage area and are freed. Once these
variables are freed, they can be reused for other file I/O. Moreover, closing an output
file ensures that the entire output is sent to the file; that is, the buffer is emptied. You
close files by using the stream function close. For example, assuming the program
includes the declarations listed in Steps 2 and 3, the statements for closing the files are:
inData.close();
outData.close();

On some systems, it is not necessary to close the files. When the program terminates, the
files are closed automatically. Nevertheless, it is a good practice to close the files yourself.
Also, if you want to use the same file stream variable to open another file, you must close
the first file opened with that file stream variable.

include <fstream>
//Add additional header files you use
using namespace std;

int main()
{
  //Declare file stream variables such as the following
  ifstream inData;
  ofstream outData;
  .
  .
  .
  //Open the files
  inData.open("prog.dat"); //open the input file
  outData.open("prog.out"); //open the output file
  //Code for data manipulation
  //Close files
  inData.close();
  outData.close();
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

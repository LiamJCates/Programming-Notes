## main()

Every C++ program must have exactly one global function named main().

When starting a C++ program, execution starts by invoking the function main(). As such, main() is defined as the program’s entry point.

As any other function, main() is a transformation that defines a relationship between input and output

Typically, main():
  accepts command-line strings as input
  returns an integer exit code upon termination as output



### main return value

The main function is required to have a return type of int

The integer value returned by main() is the program’s return value to ‘‘the system’’, called the exit status.

What the values represent is environment defined. On modern desktop systems, for example, a zero return value corresponds with a successful program execution.  A nonzero value from main() indicates failure.

If no value is returned, the system will receive a value indicating successful completion, a zero.



### The need for command line arguments

When a program is run, execution starts at the top of the function called main(). The following is the most basic declaration of main:

 int main()
 {
     //body
 }

Notice that this version of main() takes no parameters. However, many programs need some kind of input to work with. For example, let’s say you were writing a program called Thumbnail that read in an image file, and then produced a thumbnail (a smaller version of the image). How would Thumbnail know which image to read and process? The user has to have some way of telling the program which file to open. To do this, you might take this approach:

// Program: Thumbnail\
  #include <iostream>
  #include <string>

  int main()
  {
      std::cout << "Please enter an image filename to create a thumbnail for: ";
      std::string filename{};
      std::cin >> filename;

      // open image file
      // create thumbnail
      // output thumbnail
  }

However, there is a potential problem with this approach. Every time the program is run, the program will wait for the user to enter input. This may not be a problem if you’re manually running this program once from the command line. But it is problematic in other cases, such as when you want to run this program on many files, or have this program run by another program.

Let’s look into these cases further.

Consider the case where you want to create thumbnails for all the image files in a given directory. How would you do that? You could run this program as many times as there are images in the directory, typing out each filename by hand. However, if there were hundreds of images, this could take all day! A good solution here would be to write a program that loops through each filename in the directory, calling Thumbnail once for each file.

Now consider the case where you’re running a website, and you want to have your website create a Thumbnail every time a user uploads an image to your website. This program isn’t set up to accept input from the web, so how would the uploader enter a filename in this case? A good solution here would be to have your web server call Thumbnail automatically after upload.

In both of these cases, we really need a way for an external program to pass in the filename as input to our Thumbnail program when Thumbnail is launched, rather than having Thumbnail wait for the user to enter the filename after it has started.

Command line arguments are optional string arguments that are passed by the operating system to the program when it is launched. The program can then use them as input (or ignore them). Much like function parameters provide a way for a function to provide inputs to another function, command line arguments provide a way for people or programs to provide inputs to a program.



### Passing command line arguments

Executable programs can be run on the command line by invoking them by name. For example, to run the executable file “WordCount” that is located in the root directory of the C: drive on a Windows machine, you could type:

C:\>WordCount

In order to pass command line arguments to WordCount, we simply list the command line arguments after the executable name:

C:\>WordCount Myfile.txt

Now when WordCount is executed, Myfile.txt will be provided as a command line argument. A program can have multiple command line arguments, separated by spaces:

C:\>WordCount Myfile.txt Myotherfile.txt

This also works for other command line operating systems, such as Linux (although your prompt and directory structure will undoubtedly vary).

If you are running your program from an IDE, the IDE should provide a way to enter command line arguments.



### main parameters

Programs can accept any number of environment-provided arguments, called command line parameters, upon startup.

Users pass command line parameters to programs to customize their behavior.

You can determine whether your program handles command line parameters by how you declare main().

C++ specifies three valid overloads:
  int main();
  int main(int argc, char* argv[]);
  int main(int argc, char* argv[], impl-parameters);

The first accepts no parameters

The second overload accepts two parameters, argc and argv:
  The first argument, argc, is a non-negative number corresponding to the number of elements in argv.
  The second argument, argv, is an array of pointers to null-terminated strings that corresponds to arguments passed in from the execution environment.

The third overload is an extension of the second overload:
  it accepts an arbitrary number of additional implementation parameters. This way, the target platform can offer some additional arguments to the program. Implementation parameters aren’t common in modern desktop environments.

Usually, an operating system passes the full path to the program’s executable as the first command line argument. This behavior depends on your operating environment. On macOS, Linux, and Windows, the executable’s path is the first argument. The format of this path depends on the operating system.



### Using command line arguments

Now that you know how to provide command line arguments to a program, the next step is to access them from within our C++ program. To do that, we use a different form of main() than we’ve seen before. This new form of main() takes two arguments (named argc and argv by convention) as follows:

  int main(int argc, char *argv[])

You will sometimes also see it written as:

  int main(int argc, char** argv)

Even though these are treated identically, we prefer the first representation because it’s intuitively easier to understand.

argc is an integer parameter containing a count of the number of arguments passed to the program (think: argc = argument count). argc will always be at least 1, because the first argument is always the name of the program itself. Each command line argument the user provides will cause argc to increase by 1.

argv is where the actual argument values are stored (think: argv = argument values, though the proper name is “argument vectors”). Although the declaration of argv looks intimidating, argv is really just an array of C-style strings. The length of this array is argc.

Let’s write a short program named “MyArgs” to print the value of all the command line parameters:

  #include <iostream>

  int main(int argc, char *argv[])
  {
      std::cout << "There are " << argc << " arguments:\n";

      // Loop through each argument and print its number and value
      for (int count{ 0 }; count < argc; ++count)
      {
          std::cout << count << ' ' << argv[count] << '\n';
      }

      return 0;
  }

Now, when we invoke this program with the command line arguments “Myfile.txt” and “100”, the output will be as follows:

  There are 3 arguments:
  0 C:\MyArgs
  1 Myfile.txt
  2 100

Argument 0 is the path and name of the current program being run. Argument 1 and 2 in this case are the two command line parameters we passed in.



### Dealing with numeric arguments

Command line arguments are always passed as strings, even if the value provided is numeric in nature. To use a command line argument as a number, you must convert it from a string to a number. Unfortunately, C++ makes this a little more difficult than it should be.

The C++ way to do this follows:

  #include <iostream>
  #include <sstream> // for std::stringstream
  #include <string>

  int main(int argc, char *argv[])
  {
  	if (argc <= 1)
  	{
  		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
  		// We'll conditionalize our response on whether argv[0] is empty or not.
  		if (argv[0])
  			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
  		else
  			std::cout << "Usage: <program name> <number>" << '\n';

  		return 1;
  	}

    // a stringstream variable named convert, initialized with argv[1]
  	std::stringstream convert{ argv[1] };

  	int myint{};
  	if (!(convert >> myint)) // do the conversion
  		myint = 0; // if conversion fails, set myint to a default value

  	std::cout << "Got integer: " << myint << '\n';

  	return 0;
  }

When run with input “567”, this program prints:

Got integer: 567

std::stringstream works much like std::cin. In this case, we’re initializing it with the value of argv[1], so that we can use operator>> to extract the value to an integer variable (the same as we would with std::cin).



### The OS parses command line arguments first

When you type something at the command line (or run your program from the IDE), it is the operating system’s responsibility to translate and route that request as appropriate. This not only involves running the executable, it also involves parsing any arguments to determine how they should be handled and passed to the application.

Generally, operating systems have special rules about how special characters like double quotes and backslashes are handled.

For example:

  MyArgs Hello world!

prints:

  There are 3 arguments:
  0 C:\MyArgs
  1 Hello
  2 world!

Typically, strings passed in double quotes are considered to be part of the same string:

  MyArgs "Hello world!"

prints:

  There are 2 arguments:
  0 C:\MyArgs
  1 Hello world!

If you want to include a literal double quote, you have to backslash the double quote:

  MyArgs \"Hello world!\"

prints:

  There are 3 arguments:
  0 C:\MyArgs
  1 "Hello
  2 world!"

Conclusion

Command line arguments provide a great way for users or other programs to pass input data into a program at startup. Consider making any input data that a program requires at startup to operate a command line parameter. If the command line isn’t passed in, you can always detect that and ask the user for input. That way, your program can operate either way.

## Make: managing separate compilation

Separate compilation is the act of breaking code into a number of translation units that can be compiled seperately.

Compilation requires us to compile each file and to tell the linker to build all the pieces – along with the appropriate libraries and startup code – into an executable file.

Most compilers allow you to do this with a single command-line statement. For the GNU C++ compiler, for example, you might say:

	g++ SourceFile1.cpp SourceFile2.cpp



### Issue

When making edits to individual translation units rather than recompile all files in the code, we can use seperate compilation to compile only those files that we have made changes to.

For small programs, recompilation of all files is quick, however, for projects that contain many files, it can become prohibitive to recompile everything if you’ve changed only a single file.

The problem with recompilation of all files is that the compiler will compile each individual file, regardless of whether that file needs to be rebuilt or not.



### Solution

The solution to this problem, developed on Unix but available everywhere in some form, is a program called make.

The make utility automatically determines which pieces of a large program need to be recompiled, and issues commands to recompile them.

The make utility manages all the individual files in a project by following the instructions in a text file called a makefile.

To prepare to use make, you must write a file called the makefile that describes the relationships among files in your program and provides commands for updating each file. In a program, typically, the executable file is updated from object files, which are in turn made by compiling source files.

When you edit some of the files in a project and type make, the make program follows the guidelines in the makefile to compare the dates on the source code
files to the dates on the corresponding target files. If a source
code file has been edited, it's date will be more recent than its target file, so make invokes the compiler on the source code file.

By doing this, make only recompiles the source code files that were changed, and any other source-code files that are affected by the modified files.

By using make, you don’t have to re-compile all the files in your project every time you make a change, nor do you have to check to see that everything was built properly. The makefile contains all the commands to put your project together. Learning to use make will save you a lot of time and frustration.

Once a suitable makefile exists, each time you change some source files, this simple shell command:

make

suffices to perform all necessary recompilations. The make program uses the makefile database and the last-modification times of the files to decide which of the files need to beupdated. For each of those files, it issues the recipes recorded in the data base.





### Usage
Examples often show C or C++ programs, since they are most common, but you can use make with any programming language whose compiler can be run with a shell command. Indeed, make is not limited to programs. You can use it to describe any task where some files must be updated automatically from others whenever the others change.

make is the typical way that you install new software on a Linux/Unix machine (although those makefiles tend to be far more complicated than the ones presented in these documents, and you’ll often automatically generate a makefile for your particular machine as part of the installation process).

Because make is available in some form for virtually all C++ compilers (and even if it isn’t, you can use freely-available makes with any compiler), it will be the tool used throughout these documents. However, compiler vendors have also created their own project building tools. These tools ask you which files are in your project and determine all the relationships themselves. These tools use something similar to a makefile, generally called a project file, but the programming environment maintains this file so you don’ have to worry about it.

The configuration and use of project files varies from one development environment to another, so you must find the appropriate documentation on how to use them (although project file tools provided by compiler vendors are usually so simple to use that you can learn them by playing around – my
favorite form of education).

The makefiles used within these documents should work even if you are also using a specific vendor’s project-building tool.

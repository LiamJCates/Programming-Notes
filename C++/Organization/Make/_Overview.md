## Make: managing separate compilation

When using separate compilation (breaking code into a number of translation units), you need some way to automatically compile each file and to tell the linker to build all the pieces – along with the appropriate libraries and startup code – into an executable file.

Most compilers allow you to do this with a single command-line statement. For the GNU C++ compiler, for example, you might say:

	g++ SourceFile1.cpp SourceFile2.cpp



### Issue

The problem with this approach is that the compiler will first compile each individual file, regardless of whether that file needs to be rebuilt or not. With many files in a project, it can become prohibitive to recompile everything if you’ve changed only a single file.



### Solution

The solution to this problem, developed on Unix but available everywhere in some form, is a program called make.

The make utility manages all the individual files in a project by following the instructions in a text file called a makefile.

When you edit some of the files in a project and type make, the make program follows the guidelines in the makefile to compare the dates on the source code
files to the dates on the corresponding target files, and if a source
code file date is more recent than its target file, make invokes the compiler on the source code file. make only recompiles the source code files that were changed, and any other source-code files that are affected by the modified files.

By using make, you don’t have to re-compile all the files in your project every time you make a change, nor do you have to check to see that everything was built properly. The makefile contains all the commands to put your project together. Learning to use make will save you a lot of time and frustration.



### Usage

You’ll also discover that make is the typical way that you install new software on a Linux/Unix machine (although those makefiles tend to be far more complicated than the ones presented in this book, and you’ll often automatically generate a makefile for your particular machine as part of the installation process).

Because make is available in some form for virtually all C++ compilers (and even if it isn’t, you can use freely-available makes with any compiler), it will be the tool used throughout this book. However, compiler vendors have also created their own project building tools. These tools ask you which files are in your project and determine all the relationships themselves. These tools use something similar to a makefile, generally called a project file, but the programming environment maintains this file so you don’ have to worry about it.

The configuration and use of project files varies from one development environment to another, so you must find the appropriate documentation on how to use them (although project file tools provided by compiler vendors are usually so simple to use that you can learn them by playing around – my
favorite form of education).

The makefiles used within this book should work even if you are also using a specific vendor’s project-building tool.

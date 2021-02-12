## Make: managing separate compilation

When using separate compilation (breaking code into a number of translation units), you need some way to automatically compile each file and to tell the linker to build all the pieces – along with the appropriate libraries and startup code – into an executable file.

Most compilers allow you to do this with a single command-line statement. For the GNU C++ compiler, for example, you might say:

	g++ SourceFile1.cpp SourceFile2.cpp

The problem with this approach is that the compiler will first compile each individual file, regardless of whether that file needs to be rebuilt or not. With many files in a project, it can become prohibitive to recompile everything if you’ve changed only a single file.

The solution to this problem, developed on Unix but available everywhere in some form, is a program called make. The make utility manages all the individual files in a project by following the instructions in a text file called a makefile.

When you edit some of the files in a project and type make, the make program follows the guidelines in the makefile to compare the dates on the source code
files to the dates on the corresponding target files, and if a source
code file date is more recent than its target file, make invokes the compiler on the source code file. make only recompiles the source code files that were changed, and any other source-code files that are affected by the modified files.

By using make, you don’t have to re-compile all the files in your project every time you make a change, nor do you have to check to see that everything was built properly. The makefile contains all the commands to put your project together. Learning to use make will save you a lot of time and frustration.

You’ll also discover that make is the typical way that you install new software on a Linux/Unix machine (although those makefiles tend to be far more complicated than the ones presented in this book, and you’ll often automatically generate a makefile for your particular machine as part of the installation process).

Because make is available in some form for virtually all C++ compilers (and even if it isn’t, you can use freely-available makes with any compiler), it will be the tool used throughout this book. However, compiler vendors have also created their own project building tools. These tools ask you which files are in your project and determine all the relationships themselves. These tools use something similar to a makefile, generally called a project file, but the programming environment maintains this file so you don’ have to worry about it.

The configuration and use of project files varies from one development environment to another, so you must find the appropriate documentation on how to use them (although project file tools provided by compiler vendors are usually so simple to use that you can learn them by playing around – my
favorite form of education).

The makefiles used within this book should work even if you are also using a specific vendor’s project-building tool.



### Make activities

When you type make (or whatever the name of your “make” program happens to be), the make program looks in the current directory for a file named makefile, which you’ve created if it’s your project.

This file lists dependencies between source code files. make looks at the dates on files. If a dependent file has an older date than a file it depends on, make executes the rule given after the dependency.

All comments in makefiles start with a # and continue to the end of the line. As a simple example, the makefile for a program called “hello” might contain:

	# A comment
	hello.exe: hello.cpp
		mycompiler hello.cpp

This says that hello.exe (the target) depends on hello.cpp. When hello.cpphas a newer date than hello.exe, make executes the “rule” mycompiler hello.cpp.

There may be multiple dependencies and multiple rules. Many make programs require that all the rulesbegin with a tab. Other than that, whitespace is generally ignored so you can format for readability.

The rules are not restricted to being calls to the compiler; you can call any program you want from within make. By creating groups of interdependent dependency-rule sets, you can modify your source code files, type make and be certain that all the affected files will be rebuilt correctly.



### Macros

A makefile may contain macros (note that these are completely different from C/C++ preprocessor macros).

Macros allow convenient string replacement. The makefiles in this book use a
macro to invoke the C++ compiler:

	CPP = mycompiler
	hello.exe: hello.cpp
		$(CPP) hello.cpp

The = is used to identify CPP as a macro, and the $ and parentheses expand the macro. In this case, the expansion means that the macro call $(CPP) will be replaced with the string mycompiler.

With the macro above, if you want to change to a different compiler called
cpp, you just change the macro to:

	CPP = cpp

You can also add compiler flags, etc., to the macro, or use separate macros to add compiler flags.



### Suffix Rules

It becomes tedious to tell make how to invoke the compiler for every single cpp file in your project, when you know it’s the same basic process each time.

Since make is designed to be a time-saver, it also has a way to abbreviate actions, as long as they depend on file name suffixes. These abbreviations are called suffix rules.

A suffix rule is the way to teach make how to convert a file with one type of extension (.cpp, for example) into a file with another type of extension (.obj or .exe).

Once you teach make the rules for producing one kind of file from another, all you have to do is tell make which files depend on which other files. When make finds a file with a date earlier than the file it depends on, it uses the rule to create a new file.

The suffix rule tells make that it doesn’t need explicit rules to build everything, but instead it can figure out how to build things based on their file extension.

In this case it says “To build a file that ends in exe from one that ends in cpp, invoke the following command.”:

	CPP = mycompiler
	.SUFFIXES: .exe .cpp
	.cpp.exe:
		$(CPP) $<

The .SUFFIXES directive tells make that it should watch out for any of the following file-name extensions because they have special meaning for this particular makefile.

Next you see the suffix rule .cpp.exe, which says “Here’s how to convert any file with an extension of cpp to one with an extension of exe” (when the cpp file is more recent than the exe file).

As before, the $(CPP) macro is used, but then you see something new: $<.

Because this begins with a ‘$’ it’s a macro, but this is one of make’s special built-in macros.

The $< can be used only in suffix rules, and it means “whatever prerequisite triggered the rule” (sometimes called the dependent), which in this case translates to “the cpp file that needs to be compiled.”

Once the suffix rules have been set up, you can simply say, for example, “make Union.exe,” and the suffix rule will kick in, even though there’s no mention of “Union” anywhere in the makefile.



### Default targets

After the macros and suffix rules, make looks for the first “target” in a file, and builds that, unless you specify differently. So for the following makefile:

	CPP = mycompiler
	.SUFFIXES: .exe .cpp
	.cpp.exe:
		$(CPP) $<
	target1.exe:
	target2.exe:

If you just type ‘make’, then target1.exe will be built (using the default suffix rule) because that’s the first target that make encounters. To build target2.exe you’d have to explicitly say ‘make target2.exe’. This becomes tedious, so you normally create a default “dummy” target that depends on all the rest of the targets:

	CPP = mycompiler
	.SUFFIXES: .exe .cpp
	.cpp.exe:
		$(CPP) $<
	all: target1.exe target2.exe

Here, ‘all’ does not exist and there’s no file called ‘all’, so every time you type make, the program sees ‘all’ as the first target in the list (and thus the default target), then it sees that ‘all’ does not exist so it had better make it by checking all the dependencies.

So it looks at target1.exe and (using the suffix rule) sees whether
(1) target1.exe exists
(2) whether target1.cpp is more recent than target1.exe

and if so runs the suffix rule (if you provide an explicit rule for a particular target, that rule is used instead).

Then it moves on to the next file in the default target list.

Thus, by creating a default target list (typically called ‘all’ by convention, but you can call it anything) you can cause every executable in your project to
be made simply by typing ‘make’.

In addition, you can have other non-default target lists that do other things – for example, you could set it up so that typing ‘make debug’ rebuilds all your files with debugging wired in.





### An example makefile

What follows is a shortened version of the one that was automatically generated for this chapter by the book’s extraction tool. You’ll find more than one makefilein each subdirectory (they have different names; you invoke a specific one with ‘make -f’). This one is for GNU C++:

	CPP = g++
	OFLAG = -o
	.SUFFIXES : .o .cpp .c
	.cpp.o :
		$(CPP) $(CPPFLAGS) -c $<
	.c.o :
		$(CPP) $(CPPFLAGS) -c $<

	all: \
		Return \
		Declare \
		Ifthen \
		Guess \
		Guess2
	# Rest of the files for this chapter not shown

	Return: Return.o
		$(CPP) $(OFLAG)Return Return.o
	Declare: Declare.o
		$(CPP) $(OFLAG)Declare Declare.o
	Ifthen: Ifthen.o
		$(CPP) $(OFLAG)Ifthen Ifthen.o
	Guess: Guess.o
		$(CPP) $(OFLAG)Guess Guess.o
	Guess2: Guess2.o
		$(CPP) $(OFLAG)Guess2 Guess2.o

	Return.o: Return.cpp
	Declare.o: Declare.cpp
	Ifthen.o: Ifthen.cpp
	Guess.o: Guess.cpp
	Guess2.o: Guess2.cpp

The macro CPP is set to the name of the compiler. To use a different
compiler, you can either edit the makefile or change the value of
the macro on the command line, like this:

	make CPP=cpp

The second macro OFLAG is the flag that’s used to indicate the name of the output file. Although many compilers automatically assume the output file has the same base name as the input file, others don’t (such as Linux/Unix compilers, which default to creating a file called a.out).

You can see that there are two suffix rules here, one for cpp files and one for .c files (in case any C source code needs to be compiled).

The default target is all, and each line for this target is “continued” by using the backslash, up until Guess2, which is the last one in the list and thus has no backslash.

The suffix rules take care of creating object files (with a .o extension) from cpp files, but in general you need to explicitly state rules for creating the executable, because normally an executable is created by linking many different object files and make cannot guess what those are. Also, in this case (Linux/Unix) there is no standard extension for executables so a suffix rule won’t work for these simple situations. Thus, you see all the rules for building the
final executables explicitly stated.

This makefile takes the absolute safest route of using as few make features as possible; it only uses the basic make concepts of targets and dependencies, as well as macros. This way it is virtually assured of working with as many make programs as possible. It tends to produce a larger makefile.

There are lots of other make features, as well as newer and cleverer versions and variations of make with advanced shortcuts that can save a lot of time.

Your local documentation may describe the further features of your particular make, and you can learn more about make from Managing Projects with Make by Oram and Talbott (O’Reilly, 1993). Also, if your compiler vendor does not supply a make or it uses a non-standard make, you can find GNU make for virtually any platform in existence by searching the Internet for GNU archives (of which there are many).

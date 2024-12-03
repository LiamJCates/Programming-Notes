### An example makefile

What follows is a shortened version of the one that was automatically generated for this chapter by the book’s extraction tool. You’ll find more than one makefilein each subdirectory (they have different names; you invoke a specific one with ‘make -f’). This one is for GNU C++:

```make
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

	Return: Return.o
		$(CPP) $(OFLAG) Return Return.o
	Declare: Declare.o
		$(CPP) $(OFLAG) Declare Declare.o
	Ifthen: Ifthen.o
		$(CPP) $(OFLAG) Ifthen Ifthen.o
	Guess: Guess.o
		$(CPP) $(OFLAG) Guess Guess.o
	Guess2: Guess2.o
		$(CPP) $(OFLAG) Guess2 Guess2.o

	Return.o: Return.cpp
	Declare.o: Declare.cpp
	Ifthen.o: Ifthen.cpp
	Guess.o: Guess.cpp
	Guess2.o: Guess2.cpp
```

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

### Make Rule

When you type make (or whatever the name of your “make” program happens to be), the make program looks in the current directory for a file named makefile, which you’ve created if it’s your project.

This file lists dependencies between source code files. make looks at the dates on files. If a dependent file has an older date than a file it depends on, make executes the rule given after the dependency.

As a simple example, the makefile for a program called “hello” might contain:

```make
	hello.exe: hello.cpp
		[compiler] hello.cpp
```

This says that hello.exe (the target) depends on hello.cpp.
When hello.cpp has a newer date than hello.exe, make executes the “rule” [compiler] hello.cpp.

There may be multiple dependencies and multiple rules. Many make programs require that all the rules begin with a tab. Other than that, whitespace is generally ignored so you can format for readability.

The rules are not restricted to being calls to the compiler; you can call any program you want from within make. By creating groups of interdependent dependency-rule sets, you can modify your source code files, type make and be certain that all the affected files will be rebuilt correctly.



### Macros

A makefile may contain macros
(note these are different from C/C++ preprocessor macros).

Macros allow convenient string replacement.

A makefiles might use a macro to invoke the C++ compiler:

```make
	CPP = mycompiler 			#like g++
	hello.exe: hello.cpp
		$(CPP) hello.cpp
```

The = is used to identify CPP as a macro, and the $ and parentheses expand the macro.

In this case, the expansion means that the macro call $(CPP) will be replaced with the string mycompiler.

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

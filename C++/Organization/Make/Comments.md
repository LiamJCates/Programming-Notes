All comments in makefiles start with a # and continue to the end of the line, specified by the newline character.

As a simple example, the makefile for a program called “hello” might contain:

	# A comment
	hello.exe: hello.cpp
		[compiler] hello.cpp

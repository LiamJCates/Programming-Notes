All comments in makefiles start with a # and continue to the end of the line, specified by the newline character.

As a simple example, the makefile for a program called “hello” might contain:

	# A comment
	hello.exe: hello.cpp
		[compiler] hello.cpp




‘#’ in a line of a makefile starts a comment. It and the rest of the line are ignored, except that a trailing backslash not escaped by another backslash will continue the comment across multiple lines. A line containing just a comment (with perhaps spaces before it) is effectively blank, and is ignored. If you want a literal #, escape it with a backslash (e.g., \#). Comments may appear on any line in the makefile, although they are treated specially in certain situations.
You cannot use comments within variable references or function calls: any instance of # will be treated literally (rather than as the start of a comment) inside a variable reference or function call.
Comments within a recipe are passed to the shell, just as with any other recipe text.
The shell decides how to interpret it: whether or not this is a comment is up to the
shell.
Within a define directive, comments are not ignored during the definition of the
variable, but rather kept intact in the value of the variable. When the variable is
expanded they will either be treated as make comments or as recipe text, depending
on the context in which the variable is evaluated.

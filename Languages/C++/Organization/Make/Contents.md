The information that tells make how to recompile a system comes from reading a data base called the makefile.

### What Makefiles Contain

Makefiles contain five kinds of things:
	explicit rules
	implicit rules
	variable definitions
	directives
	comments

Rules, variables, and directives are described at length in later chapters.

• An explicit rule says when and how to remake one or more files, called the rule’s targets. It lists the other files that the targets depend on, called the prerequisites of the target, and may also give a recipe to use to create or update the targets. [Writing Rules]

• An implicit rule says when and how to remake a class of files based on their names. It describes how a target may depend on a file with a name similar to the target and gives a recipe to create or update such a target. [Using Implicit Rules]

• A variable definition is a line that specifies a text string value for a variable that can be substituted into the text later. The simple makefile example shows a variable definition for objects as a list of all object files. [Variables Make Makefiles Simpler]

• Directives are instructions for make to do something special while reading the makefile.
	These include:
	• Reading another makefile ([Including Other Makefiles])
	• Deciding (based on the values of variables) whether to use or ignore a part of the makefile ([Conditional Parts of Makefiles]).
	• Defining a variable from a verbatim string containing multiple lines ([Defining Multi-Line Variables]).

• Comments [C++\Organization\Make\Comments.md]

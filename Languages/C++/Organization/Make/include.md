## Including Other Makefiles

The include directive tells make to suspend reading the current makefile and read one or more other makefiles before continuing. The directive is a line in the makefile that looks like this:

include filenames...

filenames can contain shell file name patterns.

If filenames is empty, nothing is included and no error is printed.

Extra spaces are allowed and ignored at the beginning of the line, but the first character must not be a tab (or the value of .RECIPEPREFIX)—if the line begins with a tab, it will be considered a recipe line.

Whitespace is required between include and the file names, and between file names; extra whitespace is ignored there and at the end of the directive.

A comment starting with ‘#’ is allowed at the end of the line. If the file names contain any variable or function references, they are expanded.

For example, if you have three .mk files, a.mk, b.mk, and c.mk, and $(bar) expands to bish bash, then the following expression

include foo *.mk $(bar)

is equivalent to

include foo a.mk b.mk c.mk bish bash

When make processes an include directive, it suspends reading of the containing makefile and reads from each listed file in turn. When that is finished, make resumes reading the makefile in which the directive appears.

One occasion for using include directives is when several programs, handled by individual makefiles in various directories, need to use a common set of variable definitions ([Setting Variables]) or pattern rules ([Defining and Redefining Pattern Rules]).

Another such occasion is when you want to generate prerequisites from source files automatically; the prerequisites can be put in a file that is included by the main makefile.

This practice is generally cleaner than that of somehow appending the prerequisites to the end of the main makefile as has been traditionally done with other versions of make. See Section 4.13 [Automatic Prerequisites], page 41.

If the specified name does not start with a slash, and the file is not found in the current directory, several other directories are searched. First, any directories you have specified with the ‘-I’ or ‘--include-dir’ option are searched (see Section 9.7 [Summary of Options], page 108).

Then the following directories (if they exist) are searched, in this order:
	prefix/include (normally /usr/local/include1)
	/usr/gnu/include
	/usr/local/include
	/usr/include

If an included makefile cannot be found in any of these directories, a warning message is generated, but it is not an immediately fatal error; processing of the makefile containing the include continues.

Once it has finished reading makefiles, make will try to remake any that are out of date or don’t exist.

[How Makefiles Are Remade]

Only after it has tried to find a way to remake a makefile and failed, will make diagnose the missing makefile as a fatal error.

If you want make to simply ignore a makefile which does not exist or cannot be remade, with no error message, use the -include directive instead of include, like this:

-include filenames...

This acts like include in every way except that there is no error (not even a warning) if any of the filenames (or any prerequisites of any of the filenames) do not exist or cannot be remade.

For compatibility with some other make implementations, sinclude is another name for -include.



### The Variable MAKEFILES

If the environment variable MAKEFILES is defined, make considers its value as a list of names (separated by whitespace) of additional makefiles to be read before the others.

This works much like the include directive: various directories are searched for those files (see Section 3.3 [Including Other Makefiles], page 13).

In addition, the default goal is never taken from one of these makefiles (or any makefile included by them) and it is not an error if the files listed in MAKEFILES are not found.

The main use of MAKEFILES is in communication between recursive invocations of make (see Section 5.7 [Recursive Use of make], page 53).

It usually is not desirable to set the environment variable before a top-level invocation of make, because it is usually better not to mess with a makefile from outside. However, if you are running make without a specific makefile, a makefile in MAKEFILES can do useful things to help the built-in implicit rules
work better, such as defining search paths (see Section 4.4 [Directory Search], page 27).

Some users are tempted to set MAKEFILES in the environment automatically on login, and program makefiles to expect this to be done. This is a very bad idea, because such makefiles will fail to work if run by anyone else. It is much better to write explicit include directives in the makefiles. See Section 3.3 [Including Other Makefiles], page 13.



### Overriding Part of Another Makefile
Sometimes it is useful to have a makefile that is mostly just like another makefile. You can often use the ‘include’ directive to include one in the other, and add more targets or variable definitions.

However, it is invalid for two makefiles to give different recipes for the same target. But there is another way.

In the containing makefile (the one that wants to include the other), you can use a match-anything pattern rule to say that to remake any target that cannot be made from the information in the containing makefile, make should look in another makefile.

See Section 10.5 [Pattern Rules], page 123, for more information on pattern rules.

For example, if you have a makefile called Makefile that says how to make the target ‘foo’ (and other targets), you can write a makefile called GNUmakefile that contains:

foo:
	frobnicate > foo

%: force
	@$(MAKE) -f Makefile $@
force: ;

If you say ‘make foo’, make will find GNUmakefile, read it, and see that to make foo, it needs to run the recipe ‘frobnicate > foo’. If you say ‘make bar’, make will find no way to make bar in GNUmakefile, so it will use the recipe from the pattern rule: ‘make -f Makefile bar’. If Makefile provides a rule for updating bar, make will apply the rule.

And likewise for any other target that GNUmakefile does not say how to make.

The way this works is that the pattern rule has a pattern of just ‘%’, so it matches any target whatever. The rule specifies a prerequisite force, to guarantee that the recipe will be run even if the target file already exists. We give the force target an empty recipe to prevent make from searching for an implicit rule to build it — otherwise it would apply the same match - anything rule to force itself and create a prerequisite loop!

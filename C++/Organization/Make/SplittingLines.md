## Splitting Long Lines

Makefiles use a “line-based” syntax in which the newline character is special and marks the end of a statement.

GNU make has no limit on the length of a statement line, up to the amount of memory in your computer. However, it is difficult to read lines which are too long to display without wrapping or scrolling.

We can format your makefiles for readability by adding newlines into the middle of a statement: you do this by escaping the internal newlines with a backslash (\) character.

Where we need to make a distinction we will refer to “physical lines” as a single line ending with a newline (regardless of whether it is escaped) and a “logical line” being a complete statement including all escaped newlines up to the first non-escaped newline.

The way in which backslash/newline combinations are handled depends on whether the statement is a recipe line or a non-recipe line.

Handling of backslash/newline in a recipe line is discussed in the next section.



### Splitting Non-recipe Lines
Outside of recipe lines, backslash/newlines and surrounding whitespace is converted into a single space character.

All whitespace around the backslash/newline is condensed into a single space: this includes all whitespace preceding the backslash, all whitespace at the beginning of the line after the backslash/newline, and any consecutive backslash/newline combinations.

If the .POSIX special target is defined then backslash/newline handling is modified slightly to conform to POSIX.2:
	whitespace preceding a backslash is not removed
	consecutive backslash/newlines are not condensed.



### Splitting Without Adding Whitespace
If you need to split a line but do not want any whitespace added, you can utilize a subtle trick: replace your backslash/newline pairs with the three characters dollar sign/backslash/newline:

```make
var := one$\
			 word
```
After make removes the backslash/newline and condenses the following line into a single space, this is equivalent to:

```make
var := one$ word
```

Then make will perform variable expansion. The variable reference ‘$ ’ refers to a variable with the one-character name “ ” (space) which does not exist, and so expands to the empty string, giving a final assignment which is the equivalent of:

```make
var := oneword
```

### Splitting Recipe Lines
One of the few ways in which make does interpret recipes is checking for a backslash just before the newline.

A single logical recipe line can be split into multiple physical lines in the makefile by placing a backslash before each newline. A sequence of lines like this is considered a single recipe line, and one instance of the shell will be invoked to run it.

However, in contrast to how they are treated in other places in a makefile discussed above, backslash/newline pairs are not removed from the recipe. Both the backslash and the newline characters are preserved and passed to the shell.

How the backslash/newline is interpreted depends on your shell.

If the first character of the next line after the backslash/newline is the recipe prefix character (a tab by default; see Section 6.14 [Special Variables], page 75), then that character (and only that character) is removed. Whitespace is never added to the recipe.

For example, the recipe for the all target in this makefile:

```make
all :
	@echo no\
space
	@echo no\
	space
	@echo one \
	space
	@echo one\
	 space
```
consists of four separate shell commands where the output is:
```
nospace
nospace
one space
one space
```

As a more complex example, this makefile:

```make
all : ; @echo 'hello \
		world' ; echo "hello \
	world"
```

will invoke one shell with a command of:

echo 'hello \
world' ; echo "hello \
world"

which, according to shell quoting rules, will yield the following output:

```
hello \
world
hello world
```
Notice how the backslash/newline pair was removed inside the string quoted with double quotes ("..."), but not from the string quoted with single quotes ('...'). This is the way the default shell (/bin/sh) handles backslash/newline pairs.

If you specify a different shell in your makefiles it may treat them differently.

Sometimes you want to split a long line inside of single quotes, but you don’t want the backslash/newline to appear in the quoted content. This is often the case when passing scripts to languages such as Perl, where extraneous backslashes inside the script can change its meaning or even be a syntax error.

One simple way of handling this is to place the quoted string, or even the entire command, into a make variable then use the variable in the recipe. In this situation the newline quoting rules for makefiles will be used, and the backslash/newline will be removed. If we rewrite our example above using this method:

```make
HELLO = 'hello \
world'
all : ; @echo $(HELLO)
```

we will get output like this:

```
hello world
```
For more information regarding

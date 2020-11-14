## Statements
C++ programs are composed of statements.
All statements in C++ end with a semicolon (;)

The next statement can start immediately after the semicolon, but for convenience and readability you often program successive statements on successive lines.

Whitespaces typically are not visible to the compiler. This includes spaces, tabs, line feeds, carriage returns, and so on. Whitespaces within string literals, though, make a difference to the output.

If you need to spread a statement over two lines by inserting a backslash (\) at the end:
cout << "Hello \
World" << endl; // split to two lines is OK

The preceding statement can be written as two string literals:
cout << "Hello "
"World" << endl; // two string literals is also OK

The compiler notices two adjacent string literals and concatenates them.


When you group statements together within braces {...}, you create a compound statement or a block




## increment and decrement
You often hear of cases where prefix increment or decrement
operators are preferred on grounds of better performance. That
is, ++startValue is preferred over startValue++.
This is true at least theoretically because with the postfix
operators, the compiler needs to store the initial value
temporarily in the event of it needing to be assigned. The effect
on performance in these cases is negligible with respect to
integers, but in the case of certain classes there might be a
point in this argument. Smart compilers may optimize away the
differences.










## Controlling Program Flow
if, switch, ternary, break, continue statements same as java
for, for in, while, do while loops same as java


for loop:
✦ The initializer: First portion, sets counter variables.
✦ The condition: Second portion, condition by which loop continues to run.
✦ The finalizer: Third portion, happens after each loop cycle.








goto

goto instructs execution to continue from a particular, labeled,
point in code. You can use it to go backward and re-execute certain statements.
The syntax for the goto statement is
SomeFunction()
{
Start: // Called a label
CodeThatRepeats;
goto Start;
}





## Preprocessor Directive

As the name suggests, a preprocessor is a tool that runs before the actual compilation
starts. Preprocessor directives are commands to the preprocessor and always start with
a pound sign #
 #include
Professionally programmed C++ applications include standard
headers
if an artifact declared in FileA needs to be used in
FileB, you need to include the former in the latter. You usually do
that by inserting the following include statement in FileA:
 #include "...relative path \FileB"
We use quotes in this case and not angle brackets in including
a self-programmed header. <> brackets are typically used when
including standard headers.



The preprocessor also provides you with a lot of other directives besides #include. One of the more useful ones is the #define directive. Here’s a
sample #define line:

 #define MYSPECIALNUMBER 42

After the preprocessor sees this line, every time it encounters the word
MYSPECIALNUMBER, it replaces it with the word 42 (that is, whatever sequence
of letters, numbers, and other characters follow the definition). But #define
also lets you create what are called macros:

#define oldmax(x, y) ((x)>(y)?(x):(y))
After the preprocessor learns this line, every time it sees the word oldmax
followed by two things in parentheses separated by a comma, it replaces
it with the form ((x)>(y)?(x):(y)), substituting the thing before the
comma for x and the thing after the comma for y.


At times, you may want to compile one version of your application for one
situation and compile another for a different situation. For example, you may
want to have a debug version of your application that has in it some extra
goodies that spit out special information for you that you can use during the
development of your application. Then, after your application is ready to
ship to the masses so that millions of people can use it, you no longer want
that extra debug information.
To accomplish this, you can use a conditional compilation. Take a look at
these lines:
#ifdef DEBUG
cout << "The value of j is " << j << endl;
#else
cout << j << endl;
#endif
The lines that begin with # are preprocessor directives. The preprocessor
has its own version of if statements. In your code, you can have a line like
the following, with nothing after it:
#define DEBUG
This simply defines a symbol. It works just like the symbols we described
earlier, except that it’s not set to be replaced by anything.


To define the DEBUG symbol
through a command-line option, you add the following line to your command
-D DEBUG
either in the gcc command  when you include this compiler option, the DEBUG
symbol is defined throughout your application, just as though you had
included a #define DEBUG line at the beginning


Using preprocessor directives, you can have two different versions of your
application. In the example we gave, we’re gearing up for two versions: a
debug version and a release version. To tell the compiler which version to
build, we then modify the command-line options by either removing or
adding the -D DEBUG line.
The -D option works either with or without a space after the D. Thus, you
can either use -DDEBUG or -D DEBUG. They both do the same thing

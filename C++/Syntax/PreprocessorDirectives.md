## Preprocessor Directive

As the name suggests, a preprocessor is a tool that runs before the actual compilation starts.

Preprocessor directives are commands to the preprocessor

Preprocessor directives cause the preprocessor to modify the text of a C++ program before it is compiled.

Preprocessor directives always start with a pound sign #

There are no semicolons at the end of preprocessor commands because they are not C++ statements.

### #include
You use preprocessor directives and the names of header files to tell the computer the locations of the code provided
in libraries.

To use a header file in a C++ program, use the preprocessor directive include.

 #include

 The general syntax to include a header file (provided by the IDE) in a C++ program is:

  #include <headerFileName>

<> brackets are typically used when including standard headers.

Every library has a name and is referred to by a header file. For example, the descriptions of the functions needed to perform input/output (I/O) are contained in the header file iostream.

if an artifact declared in FileA needs to be used in FileB, you need to include the former in the latter using this include statement in FileA:

 #include "...relative path \FileB"

We use quotes in this case and not angle brackets in including
a self-programmed header.


Preprocessor directives to include header files are placed in the first few lines of a source file so that the identifiers declared in those header files can be used throughout the
program.


### define#
The preprocessor also provides you with a lot of other directives besides #include. One of the more useful ones is the #define directive. Here’s a
sample #define line:

 #define MYSPECIALNUMBER 42

After the preprocessor sees this line, every time it encounters the word MYSPECIALNUMBER, it replaces it with the word 42 (that is, whatever sequence of letters, numbers, and other characters follow the definition).

The #define preprocessor directive also lets you create what are called macros:

#define oldmax(x, y) ((x)>(y)?(x):(y))

After the preprocessor learns this line, every time it sees the word oldmax followed by two things in parentheses separated by a comma, it replaces it with the form ((x)>(y)?(x):(y)), substituting the thing before the comma for x and the thing after the comma for y.

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

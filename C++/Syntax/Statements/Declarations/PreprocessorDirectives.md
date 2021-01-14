## Preprocessor Directive
Preprocessor directives are commands to the preprocessor

As the name suggests, a preprocessor is a tool that runs before the actual compilation starts. Preprocessor directives cause the preprocessor to modify the text of a C++ program before it is compiled.

Prior to compilation, the code file goes through a phase known as translation. Many things happen in the translation phase to get your code ready to be compiled. A code file with translations applied to it is called a translation unit.

Preprocessor directives always start with a hash sign #

These preprocessor directives extend only across a single line of code. As soon as a newline character is found, the preprocessor directive is ends. No semicolon (;) is expected at the end of a preprocessor directive. The only way a preprocessor directive can extend through more than one line is by preceding the newline character at the end of the line by a backslash (\).

### #include
You use preprocessor directives and the names of header files to tell the computer the locations of the code provided in libraries.

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


The NULL macro

In C++, there is a special preprocessor macro called NULL (defined in the <cstddef> header). This macro was inherited from C, where it is commonly used to indicate a null pointer.

#include <cstddef> // for NULL

double *ptr { NULL }; // ptr is a null pointer

The value of NULL is implementation defined, but is usually defined as the integer constant 0. Note: as of C++11, NULL can be defined as nullptr instead (which we’ll discuss in a bit).

Rule

Because NULL is a preprocessor macro with an implementation defined value, avoid using NULL.

https://www.learncpp.com/cpp-tutorial/header-files/
https://www.learncpp.com/cpp-tutorial/header-guards/

### define
The #define directive specifies a preprocessor macro.

In C++, a macro is a rule that defines how input text is converted into replacement output text.

There are two basic types of macros: object-like macros, and function-like macros.

#### Object macros

Object-like macros can be defined in one of two ways:

  #define identifier
  #define identifier substitution_text

The top definition has no substitution text, whereas the bottom one does. Because these are preprocessor directives (not statements), note that neither form ends with a semicolon.

##### Object-like macros with substitution text

  #define identifier substitution_text

When the preprocessor encounters this directive, any further occurrence of the identifier is replaced by substitution_text. The identifier is traditionally typed in all capital letters, using underscores to represent spaces.

When the preprocessor encounters this directive, it replaces any occurrence of identifier in the rest of the code by replacement. This replacement can be an expression, a statement, a block or simply anything. The preprocessor does not understand C++ proper, it simply replaces any occurrence of identifier by replacement.

Here’s a
sample #define line:

 #define MYSPECIALNUMBER 42

After the preprocessor sees this line, every time it encounters the word MYSPECIALNUMBER, it replaces it with the word 42 (that is, whatever sequence of letters, numbers, and other characters follow the definition).

Object-like macros should only be seen in legacy code anymore.



##### Object-like macros without substitution text

Object-like macros can also be defined without substitution text.

For example:

  #define USE_YEN

Macros of this form work like you might expect: any further occurrence of the identifier is removed and replaced by nothing!

This might seem pretty useless, and it is useless for doing text substitution. However, that’s not what this form of the directive is generally used for.

Unlike object-like macros with substitution text, macros of this form are generally considered acceptable to use for things like conditional inclusions.



##### Object-like macros don’t affect other preprocessor directives

Now you might be wondering:

  #define PRINT_JOE

  #ifdef PRINT_JOE
  // ...

Since we defined PRINT_JOE to be nothing, how come the preprocessor didn’t replace PRINT_JOE in #ifdef PRINT_JOE with nothing?

Macros only cause text substitution for normal code. Other preprocessor commands are ignored.




#### Function macros
Function-like macros act like functions, and serve a similar purpose.

The #define preprocessor directive can work with parameters to define function macros:

  #define oldmax(x, y) ((x)>(y)?(x):(y))

After the preprocessor learns this line, every time it sees the word oldmax followed by two things in parentheses separated by a comma, it replaces it with the form ((x)>(y)?(x):(y)), substituting the thing before the comma for x and the thing after the comma for y.

Defined macros are not affected by block structure. A macro lasts until it is undefined with the #undef preprocessor directive:

  #define TABLE_SIZE 100
  int table1[TABLE_SIZE];
  #undef TABLE_SIZE
  #define TABLE_SIZE 200
  int table2[TABLE_SIZE];

This would generate the same code as:

  int table1[100];
  int table2[200];


Function macro definitions accept two special operators (# and ##) in the replacement sequence.

The operator #, followed by a parameter name, is replaced by a string literal that contains the argument passed (as if enclosed between double quotes):

  #define str(x) #x
  cout << str(test);

This would be translated into:

  cout << "test";

The operator ## concatenates two arguments leaving no blank spaces between them:

  #define glue(a,b) a ## b
  glue(c,out) << "test";

This would also be translated into:

  cout << "test";

Because preprocessor replacements happen before any C++ syntax check, macro definitions can be a tricky feature. But, be careful: code that relies heavily on complicated macros become less readable, since the syntax expected is on many occasions different from the normal expressions programmers expect in C++.



### Conditional Inclusions
The conditional compilation preprocessor directives allow you to specify under what conditions something will or won’t compile.

The conditional inclusions are #ifdef, #ifndef, #if, #endif, #else and #elif

These directives allow to include or discard part of the code of a program if a certain condition is met.

ifdef allows a section of a program to be compiled only if the macro that is specified as the parameter has been defined, no matter which its value is. For example:

  #ifdef TABLE_SIZE
  int table[TABLE_SIZE];
  #endif  

In this case, the line of code int table[TABLE_SIZE]; is only compiled if TABLE_SIZE was previously defined with #define, independently of its value. If it was not defined, that line will not be included in the program compilation.

ifndef serves for the exact opposite: the code between #ifndef and #endif directives is only compiled if the specified identifier has not been previously defined. For example:

  #ifndef TABLE_SIZE
  #define TABLE_SIZE 100
  #endif
  int table[TABLE_SIZE];

In this case, if when arriving at this piece of code, the TABLE_SIZE macro has not been defined yet, it would be defined to a value of 100. If it already existed it would keep its previous value since the #define directive would not be executed.

The #if, #else and #elif (i.e., "else if") directives serve to specify some condition to be met in order for the portion of code they surround to be compiled. The condition that follows #if or #elif can only evaluate constant expressions, including macro expressions. For example:

  #if TABLE_SIZE>200
  #undef TABLE_SIZE
  #define TABLE_SIZE 200

  #elif TABLE_SIZE<50
  #undef TABLE_SIZE
  #define TABLE_SIZE 50

  #else
  #undef TABLE_SIZE
  #define TABLE_SIZE 100
  #endif

int table[TABLE_SIZE];

Notice how the entire structure of #if, #elif and #else chained directives ends with #endif.

The behavior of #ifdef and #ifndef can also be achieved by using the special operators defined and !defined respectively in any #if or #elif directive:

  #if defined ARRAY_SIZE
  #define TABLE_SIZE ARRAY_SIZE
  #elif !defined BUFFER_SIZE
  #define TABLE_SIZE 128
  #else
  #define TABLE_SIZE BUFFER_SIZE
  #endif

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



### if 0

One more common use of conditional compilation involves using #if 0 to exclude a block of code from being compiled (as if it were inside a comment block):

  #include <iostream>

  int main()
  {
    std::cout << "Joe\n";

  #if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
  #endif // until this point

    return 0;
  }

The above code only prints “Joe”, because “Bob” and “Steve” were inside an #if 0 block that the preprocessor will exclude from compilation.

This provides a convenient way to “comment out” code that contains multi-line comments.




Line control (#line)
When we compile a program and some error happens during the compiling process, the compiler shows an error message with references to the name of the file where the error happened and a line number, so it is easier to find the code generating the error.

The #line directive allows us to control both things, the line numbers within the code files as well as the file name that we want that appears when an error takes place. Its format is:

  #line number "filename"

Where number is the new line number that will be assigned to the next code line. The line numbers of successive lines will be increased one by one from this point on.

"filename" is an optional parameter that allows to redefine the file name that will be shown. For example:

  #line 20 "assigning variable"
  int a?;

This code will generate an error that will be shown as error in file "assigning variable", line 20.

Error directive (#error)
This directive aborts the compilation process when it is found, generating a compilation error that can be specified as its parameter:

  #ifndef __cplusplus
  #error A C++ compiler is required!
  #endif

This example aborts the compilation process if the macro name __cplusplus is not defined (this macro name is defined by default in all C++ compilers).

Source file inclusion (#include)
This directive has been used assiduously in other sections of this tutorial. When the preprocessor finds an #include directive it replaces it by the entire content of the specified header or file. There are two ways to use #include:

  #include <header>
  #include "file"

In the first case, a header is specified between angle-brackets <>. This is used to include headers provided by the implementation, such as the headers that compose the standard library (iostream, string,...). Whether the headers are actually files or exist in some other form is implementation-defined, but in any case they shall be properly included with this directive.

The syntax used in the second #include uses quotes, and includes a file. The file is searched for in an implementation-defined manner, which generally includes the current path. In the case that the file is not found, the compiler interprets the directive as a header inclusion, just as if the quotes ("") were replaced by angle-brackets (<>).

Pragma directive (#pragma)
This directive is used to specify diverse options to the compiler. These options are specific for the platform and the compiler you use. Consult the manual or the reference of your compiler for more information on the possible parameters that you can define with #pragma.

If the compiler does not support a specific argument for #pragma, it is ignored - no syntax error is generated.

Predefined macro names
The following macro names are always defined (they all begin and end with two underscore characters, _):

macro	value
__LINE__	Integer value representing the current line in the source code file being compiled.
__FILE__	A string literal containing the presumed name of the source file being compiled.
__DATE__	A string literal in the form "Mmm dd yyyy" containing the date in which the compilation process began.
__TIME__	A string literal in the form "hh:mm:ss" containing the time at which the compilation process began.
__cplusplus	An integer value. All C++ compilers have this constant defined to some value. Its value depends on the version of the standard supported by the compiler:

    199711L: ISO C++ 1998/2003
    201103L: ISO C++ 2011

Non conforming compilers define this constant as some value at most five digits long. Note that many compilers are not fully conforming and thus will have this constant defined as neither of the values above.
__STDC_HOSTED__	1 if the implementation is a hosted implementation (with all standard headers available)
0 otherwise.

The following macros are optionally defined, generally depending on whether a feature is available:

macro	value
__STDC__	In C: if defined to 1, the implementation conforms to the C standard.
In C++: Implementation defined.
__STDC_VERSION__	In C:

    199401L: ISO C 1990, Ammendment 1
    199901L: ISO C 1999
    201112L: ISO C 2011

In C++: Implementation defined.
__STDC_MB_MIGHT_NEQ_WC__	1 if multibyte encoding might give a character a different value in character literals
__STDC_ISO_10646__	A value in the form yyyymmL, specifying the date of the Unicode standard followed by the encoding of wchar_t characters
__STDCPP_STRICT_POINTER_SAFETY__	1 if the implementation has strict pointer safety (see get_pointer_safety)
__STDCPP_THREADS__	1 if the program can have more than one thread

Particular implementations may define additional constants.

For example:

  // standard macro names
  #include <iostream>
  using namespace std;

  int main()
  {
    cout << "This is the line number " << __LINE__;
    cout << " of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The compiler gives a __cplusplus value of " << __cplusplus;
    return 0;
  }


This is the line number 7 of file /home/jay/stdmacronames.cpp.
Its compilation began Nov  1 2005 at 10:12:29.
The compiler gives a __cplusplus value of 1

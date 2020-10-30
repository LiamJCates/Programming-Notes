Using a Function from a Separate File

For the compiler to understand a function call, all it needs at the point that
the code makes the call is a function prototype. It’s up to the linker to determine whether that function really exists.
Because the function call needs only a function prototype, you can put the
function itself in another source code file. You could, therefore, have two separate source code files, as in the MultipleSourceFiles example, shown
in Listings 6-1 and 6-2. (The first source code file — main.cpp — is shown
in Listing 6-1, and the second source code file — mystuff.cpp — is shown in
Listing 6-2.)


Listing 6-1: Calling a Function with Only a Prototype
#include <iostream>
using namespace std;
void BigDog(int KibblesCount);
int main()
{
BigDog(3);
return 0;
}

Listing 6-2: Using a Function from a Separate File
#include <iostream>
using namespace std;
void BigDog(int KibblesCount)
{
cout << "I'm a lucky dog" << endl;
cout << "I have " << KibblesCount << " pieces of food" << endl;
}

Sharing with Header Files
Breaking apart source code into multiple files is easy, but soon you may
run into a problem. If you have a function — say, SafeCracker() — and
this function is extremely useful and is likely to be called many times from
within several other source code files, you would need a prototype for
SafeCracker() in every file that calls it. The prototype may look like this:
string SafeCracker(int SafeID);
But instead of putting this line in every file that uses the function, we know
of an easier way. (We computer people are always looking for the easier way
so that we can finally retire.) Simply put this line inside its own file, called a
header file, and give the filename an .h or .hpp extension. (It’s your choice
which extension you use, because it really doesn’t matter; we usually just go
with .h.) For example, we might save the line string SafeCracker (int
SafeID); in a file called safestuff.h.
Then, instead of typing the header line at the start of each file that needs the
function, you type
#include "safestuff.h"
You would then have the three source code files used for the Multiple
SourceFiles2 example, which we have shown in Listings 6-3, 6-4, and 6-5.
The first is main.cpp, which calls the function. The second is safestuff.h,
which contains the function prototype. The third is safestuff.cpp, which
contains the actual code for the function whose prototype appears in the
header file. Lots of files, but now the code is broken into manageable pieces.
Also, make sure that you save all three of these files in the same directory.
Listing 6-3: Including the Header File in the main File
#include <iostream>
#include "safestuff.h"
using namespace std;
int main()
{
cout << "Surprise, surprise!" << endl;
cout << "The combination is (once again)" << endl;
cout << SafeCracker(12) << endl;
return 0;
}


Listing 6-4: Containing the Function Prototype in the Header File
using namespace std;
#ifndef SAFESTUFF_H_INCLUDED
#define SAFESTUFF_H_INCLUDED
string SafeCracker(int SafeID);
#endif // SAFESTUFF_H_INCLUDED
Listing 6-5: Containing the Actual Function Code
#include <iostream>
using namespace std;
string SafeCracker(int SafeID)
{
return "13-26-16";
}
Before you compile this application, however, we need to give you a couple
of pointers. First, the compiler does not compile the header file into a separate .o or .obj file. With the application in Listings 6-3 through 6-5, the
compiler compiles only two files: main.cpp and mystuff.cpp. Instead of
compiling the header file, when the compiler reads the main.cpp file and
reaches the #include line for the header file, it temporarily switches over
and reads that file, pretending that it’s still reading the same main.cpp file.
As it continues, it compiles everything as if it’s all part of the main.cpp
file. And if you include this header file in other source code files, it does the
same thing again for those source files.


Regardless of where you put your header files, here is the rule for when to
use quotes and when to use brackets: The compiler looks in several directories to find header files. And it can, possibly, look in the same directory as
the source file. If you use angle brackets (that is, less-than and greater-than
signs), as in #include <string>, the compiler does not look in the same
directory as the source file. But if you use double quotes, as in #include
"safestuff.h", the compiler first looks in the same directory as the source
file. And if the compiler doesn’t find the header file there, it looks in the
remaining directories, as it would with angle brackets.
Some people always like to use double quotes. That way, whether the header
file is in the same file as the source file or not, the compiler should find it.
Most professional programmers today always use angle brackets. This
forces programmers to put their header files in a common area. With really
big projects, programmers like to have a directory dedicated to source files
and another directory dedicated to header files. No header file is ever in the
same directory as the source file.
For small projects, some people like to lump all the source and header files
into a single directory. These people typically use angle brackets around
system header files (such as #include <string>) and use double quotes
around their own header files. In the projects in this book, we generally
follow this rule. The header files that we write are in the same directory as
the source files, and we use double quotes for #include lines of our own
files and use angle brackets for the #include lines of system headers.
If you follow the same approach that we use here, you immediately know
whether the #include line refers to one of your own header files or another
header file. If it refers to your own, it has double quotes.
If you start working on a large C++ project, you will probably find that project managers use the rule of always using angle brackets. For large projects,
this is typically the best policy.
If you try to compile and you get a No such file or directory error on
the #include line, it’s probably because you put the header file in a source
file directory but used angle brackets instead of double quotes. Try switching that line to double quotes.


Sharing Variables among Source Files
There’s a trick to making this work. Declare the variable inside one and
only one of the source files. Then you declare it again inside one (and only
one) header file, but you precede it with the word extern, as in extern int
DoubleCheeseburgers;.

6-6: Making Use of a Global Variable
#include <iostream>
#include "sharealike.h"
using namespace std;
int main()
{
DoubleCheeseburgers = 20;
EatAtJoes();
return 0;
}

Listing 6-7: Using a Header File to Declare a Global Variable
#ifndef SHAREALIKE_H_INCLUDED
#define SHAREALIKE_H_INCLUDED
extern int DoubleCheeseburgers;
void EatAtJoes();
#endif // SHAREALIKE_H_INCLUDED

Listing 6-8: Declaring the Actual Storage for the Global Variable
#include <iostream>
#include "sharealike.h"
using namespace std;
int DoubleCheeseburgers;
void EatAtJoes() {
cout << "How many cheeseburgers today?" << endl;
cout << DoubleCheeseburgers << endl;
}

Be careful when you do this; getting it exactly right is very tricky. You declare
the variable once inside the header file, but you must remember the word
extern. That tells the various files, “This variable is declared elsewhere,
but here’s its name and type so that you can use it.” Then you declare the
variable in one of the source files, without the word extern; this creates the
actual storage bin for the variable. Finally, you include the header file in each
of your source files that uses the global variable.
When you share a variable among multiple source files, it is a global variable. A variable used by a single function is a local variable. If you share a
variable between functions within a single source file but not between
multiple source files, people call this a global variable that is local to the
source file.
Use the word extern in your header file when using a global variable. If you
forget to do that, you give each source file its own variable that happens to
have the same name.

Using the Mysterious Header Wrappers
When you include a header file, you usually want to include it only once per
source file. But that can create a problem: Suppose that you have a huge
software project, and several header files include another of your header
files, called superheader.h. If you include all these other header files, how
can you be sure to pick up the superheader.h file only once?
The answer looks strange but does the trick. You start each header file with
these lines:
#ifndef SHAREALIKE_H
#define SHAREALIKE_H
#endif


These header wrappers, as they are often called, ensure that the code in the
header gets processed only once per source code file each time you compile. The wrappers use special lines called preprocessor directives. Basically,
the second line defines something that is sort of like a variable but is used
only during compilation; this something is called a symbol. In our case, the
symbol is called SHAREALIKE_H; we picked it by taking the filename, making
it all caps, and replacing the dot with an underscore.
The first line checks to see whether this symbol has been defined. If not, it
proceeds with the lines of code that follow. The next line goes ahead and
defines the symbol, so now it’s actually defined for later. Then the compiler
does all the rest of the lines in the file. Finally, the last line, #endif, simply
finishes the very first line.

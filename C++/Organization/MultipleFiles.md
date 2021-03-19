Separate Compilation

C++ supports a notion of separate compilation where user code sees only declarations of the types and functions used. The definitions of those types and functions are in separate source files and are compiled separately. This can be used to organize a program into a set of semi-independent code fragments. Such separation can be used to minimize compilation times and to strictly enforce separation of logically distinct parts of a program (thus minimizing the chance of errors). A library is often a collection of separately compiled code fragments (e.g., functions).

Typically, we place the declarations that specify the interface to a module in a file with a name indicating its intended use.


When a class is defined that can be used in a different file, a header can be used to separate the interface (the declaration) from the implementation (the
definition of the member variables and functions) so the implementation can be
changed without forcing a re-compile of the entire system. You achieve this end by putting the declaration for your new type in a header file.


// Vector.h:
class Vector {
public:
  Vector(int s);
  double& operator[](int i);
  int size();
private:
  double∗ elem; // elem points to an array of sz doubles
  int sz;
};

This declaration is placed in the file Vector.h.

Users then include that file, called a header file, to access that interface. For example:

// user.cpp:
 #include "Vector.h" //Vector’s interface
 #include <cmath>    //standard-library math function interface including sqrt()

double sqrt_sum(Vector& v)
{
  double sum = 0;
  for (int i=0; i!=v.siz e(); ++i)
  sum+=std::sqr t(v[i]); // sum of square roots
  return sum;
}

To help the compiler ensure consistency, the .cpp file providing the implementation of Vector will also include the .h file providing its interface:

// Vector.cpp:
 #include "Vector.h" // get Vector’s interface

Vector::Vector(int s)
: elem{new double[s]}, sz{s} // initialize members
{}

double& Vector::operator[](int i)
{
  return elem[i];
}

int Vector::siz e()
{
  return sz;
}

The code in user.cpp and Vector.cpp shares the Vector interface information presented in Vector.h, but the two files are otherwise independent and can be separately compiled.

Strictly speaking, using separate compilation isn’t a language issue; it is an issue of how best to take advantage of a particular language implementation. However, it is of great practical importance. The best approach to program organization is to think of the program as a set of modules with well-defined dependencies, represent that modularity logically through language features, and
then exploit the modularity physically through files for effective separate compilation.

A .cpp file that is compiled by itself (including the h files it #includes) is called a translation unit.

A program can consist of many thousand translation units.




The asm keyword
This is an escape mechanism that allows you to write assembly
code for your hardware within a C++ program. Often you’re able
to reference C++ variables within the assembly code, which means
you can easily communicate with your C++ code and limit the
assembly code to that necessary for efficiency tuning or to use
special processor instructions. The exact syntax that you must use
when writing the assembly language is compiler-dependent and
can be discovered in your compiler’s documentation.


Global constants
In some applications, certain symbolic constants may need to be used throughout your code (not just in one location). These can include physics or mathematical constants that don’t change (e.g. pi or Avogadro’s number), or application-specific “tuning” values (e.g. friction or gravity coefficients). Instead of redefining these constants in every file that needs them (a violation of the “Don’t Repeat Yourself” rule), it’s better to declare them once in a central location and use them wherever needed. That way, if you ever need to change them, you only need to change them in one place, and those changes can be propagated out.

Global constants as internal variables

There are multiple ways to facilitate this within C++. Pre-C++17, the following is probably the easiest and most common:

1) Create a header file to hold these constants
2) Inside this header file, define a namespace (discussed in lesson 6.2 -- User-defined namespaces)
3) Add all your constants inside the namespace (make sure they’re constexpr)
4) #include the header file wherever you need it

For example:

constants.h:

  #ifndef CONSTANTS_H
  #define CONSTANTS_H

  // define your own namespace to hold constants
  namespace constants
  {
    // constants have internal linkage by default
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double my_gravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
  }
  #endif

Then use the scope resolution operator (::) with the namespace name to the left, and your variable name to the right in order to access your constants in .cpp files:

main.cpp:

  #include "constants.h" // include a copy of each constant in this file

  #include <iostream>

  int main()
  {
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;

    std::cout << "Circumference is: " << 2.0 * radius * constants::pi << '\n';

    return 0;
  }

When this header gets #included into a .cpp file, each of these variables defined in the header will be copied into that code file at the point of inclusion. Because these variables live outside of a function, they’re treated as global variables within the file they are included into, which is why you can use them anywhere in that file.

Because const globals have internal linkage, each .cpp file gets an independent version of the global variable that the linker can’t see. In most cases, because these are const, the compiler will simply optimize the variables away.

As an aside...

The term “optimizing away” refers to any process where the compiler optimizes the performance of your program by removing things in a way that doesn’t affect the output of your program. For example, lets say you have some const variable x that’s initialized to value 4. Wherever your code references variable x, the compiler can just replace x with 4 (since x is const, we know it won’t ever change to a different value) and avoid having to create and initialize a variable altogether.

Global constants as external variables

The above method has a few potential downsides.

While this is simple (and fine for smaller programs), every time constants.h gets #included into a different code file, each of these variables is copied into the including code file. Therefore, if constants.h gets included into 20 different code files, each of these variables is duplicated 20 times. Header guards won’t stop this from happening, as they only prevent a header from being included more than once into a single including file, not from being included one time into multiple different code files. This introduces two challenges:
1) Changing a single constant value would require recompiling every file that includes the constants header, which can lead to lengthy rebuild times for larger projects.
2) If the constants are large in size and can’t be optimized away, this can use a lot of memory.

One way to avoid these problems is by turning these constants into external variables, since we can then have a single variable (initialized once) that is shared across all files. In this method, we’ll define the constants in a .cpp file (to ensure the definitions only exist in one place), and put forward declarations in the header (which will be included by other files).

Author's note

We use const instead of constexpr in this method because constexpr variables can’t be forward declared, even if they have external linkage.

constants.cpp:

  #include "constants.h"

  namespace constants
  {
    // actual global variables
    extern const double pi { 3.14159 };
    extern const double avogadro { 6.0221413e23 };
    extern const double my_gravity { 9.2 }; // m/s^2 -- gravity is light on this planet
  }

constants.h:

  #ifndef CONSTANTS_H
  #define CONSTANTS_H

  namespace constants
  {
      // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
      extern const double pi;
      extern const double avogadro;
      extern const double my_gravity;
  }

  #endif

Use in the code file stays the same:

main.cpp:

  #include "constants.h" // include all the forward declarations

  #include <iostream>

  int main()
  {
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;

    std::cout << "Circumference is: " << 2.0 * radius * constants::pi << '\n';

    return 0;
  }

Because global symbolic constants should be namespaced (to avoid naming conflicts with other identifiers in the global namespace), the use of a “g_” naming prefix is not necessary.

Now the symbolic constants will get instantiated only once (in constants.cpp), instead of once every time constants.h is #included, and the other uses will simply refer to the version in constants.cpp. Any changes made to constants.cpp will require recompiling only constants.cpp.

However, there are a couple of downsides to this method. First, these constants are now considered compile-time constants only within the file they are actually defined in (constants.cpp), not anywhere else they are used. This means that outside of constants.cpp, they can’t be used anywhere that requires a compile-time constant. Second, the compiler may not be able to optimize these as much.

Given the above downsides, prefer defining your constants in the header file. If you find that for some reason those constants are causing trouble, you can move some or all of them into a .cpp file as needed.

Global constants as inline variables

C++17 introduced a new concept called inline variables. In C++, the term inline has evolved to mean “multiple definitions are allowed”. Thus, an inline variable is one that is allowed to be defined in multiple files without violating the one definition rule. Inline global variables have external linkage by default.

Inline variables have two primary restrictions that must be obeyed:
1) All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
2) The inline variable definition (not a forward declaration) must be present in any file that uses the variable.

The linker will consolidate all inline definitions into a single variable definition. This allows us to define variables in a header file and have them treated as if there was only one definition in a .cpp file somewhere. These variables also retain their constexpr-ness in all files in which they are included.

With this, we can go back to defining our globals in a header file without the downside of duplicated variables:

constants.h:

  #ifndef CONSTANTS_H
  #define CONSTANTS_H

  // define your own namespace to hold constants
  namespace constants
  {
      inline constexpr double pi { 3.14159 }; // note: now inline constexpr
      inline constexpr double avogadro { 6.0221413e23 };
      inline constexpr double my_gravity { 9.2 }; // m/s^2 -- gravity is light on this planet
      // ... other related constants
  }
  #endif

main.cpp:

  #include "constants.h"

  #include <iostream>

  int main()
  {
      std::cout << "Enter a radius: ";
      int radius{};
      std::cin >> radius;

      std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';

      return 0;
  }

We can include constants.h into as many code files as we want, but these variables will only be instantiated once and shared across all code files.



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

Separate Compilation
The basic principle is that you can define any function or global object in any source file. The compiler does not care which file contains what. As long as it has a declaration for every name it needs, it can compile a source file to an object file. (In this unfortunate case of convergent terminology, object files are unrelated to objects in a C++ program.) To create the final program, you have to link all the object files together. The linker doesn’t care which file contains which definition; it simply has to find a definition for every name reference that the compiler generates.

C++ supports the above functionality, called separate compilation, where user code sees only declarations of the types and functions used. The definitions of those types and functions are in separate source files and are compiled separately.

This can be used to organize a program into a set of semi-independent code fragments. Such separation can be used to minimize compilation times and to strictly enforce separation of logically distinct parts of a program (thus minimizing the chance of errors).

A library is often a collection of separately compiled code fragments (e.g., functions).


### Using a Function from a Separate File

For the compiler to understand a function call, all it needs at the point that the code makes the call is a function prototype. It’s up to the linker to determine whether that function really exists. Because the function call needs only a function prototype, you can put the function itself in another source code file. You could, therefore, have two separate source code files, as in this example:

//main.cpp
```cpp
#include <iostream>
using namespace std;
void BigDog(int KibblesCount);
int main()
{
  BigDog(3);
  return 0;
}
```

//mystuff.cpp
```cpp
#include <iostream>
using namespace std;
void BigDog(int KibblesCount)
{
  cout << "I'm a lucky dog" << endl;
  cout << "I have " << KibblesCount << " pieces of food" << endl;
}
```



### Sharing with Header Files

Breaking apart source code into multiple files is easy, but soon you may run into a problem. If you have a function — say, SafeCracker() — and this function is extremely useful and is likely to be called many times from within several other source code files, you would need a prototype for SafeCracker() in every file that calls it.

The prototype may look like this:

```cpp
string SafeCracker(int SafeID);
```

But instead of putting this line in every file that uses the function, we know of an easier way. (We computer people are always looking for the easier way so that we can finally retire.) Simply put this line inside its own file, called a
header file, and give the filename an .h or .hpp extension. (It’s your choice
which extension you use, because it really doesn’t matter; conventionally common is .h.)

For example, we might save the line

```cpp
string SafeCracker (int SafeID);
```

in a file called safestuff.h.

Then, instead of typing the prototype line at the start of each file that needs the function, you type:

```cpp
#include "safestuff.h"
```

You would then have the three source code files:
main.cpp, which calls the function
safestuff.h, which contains the function prototype.
safestuff.cpp, which contains the actual code for the function whose prototype appears in the header file.

Lots of files, but now the code is broken into manageable pieces.

Also, make sure that you save all three of these files in the same directory.

//main.cpp
```cpp
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
```

//safestuff.h
```cpp
using namespace std;
#ifndef SAFESTUFF_H_INCLUDED
#define SAFESTUFF_H_INCLUDED
string SafeCracker(int SafeID);
#endif // SAFESTUFF_H_INCLUDED
```

//safestuff.cpp
```cpp
#include <iostream>
using namespace std;
string SafeCracker(int SafeID)
{
return "13-26-16";
}
```


You can compile and link the above files at the same time, by listing all the source file names in one compilation:
```
g++ main.cpp saftestuff.cpp safestuff.h
```

Note that the compiler does not compile the header file into a separate .o or .obj file. To compile the application from the file above, the compiler compiles only two files: main.cpp and safestuff.cpp. Instead of compiling the header file, when the compiler reads the main.cpp file and reaches the #include line for the header file, it temporarily switches over and reads that file, pretending that it’s still reading the same main.cpp file.

As it continues, it compiles everything as if it’s all part of the main.cpp
file.

If you include this header file in other source code files, it does the
same thing again for those source files.



### Sharing Variables among Source Files

There’s a trick to making this work. Declare the variable inside one and
only one of the source files. Then you declare it again inside one (and only
one) header file, but you precede it with the word extern, as in extern int
DoubleCheeseburgers;.

//main.cpp
```cpp
#include <iostream>
#include "sharealike.h"
using namespace std;
int main()
{
  DoubleCheeseburgers = 20;
  EatAtJoes();
  return 0;
}
```

//sharealike.h
```cpp
#ifndef SHAREALIKE_H_INCLUDED
#define SHAREALIKE_H_INCLUDED
extern int DoubleCheeseburgers;
void EatAtJoes();
#endif // SHAREALIKE_H_INCLUDED
```

//sharealike.cpp
```cpp
#include <iostream>
#include "sharealike.h"
using namespace std;
int DoubleCheeseburgers;
void EatAtJoes() {
  cout << "How many cheeseburgers today?" << endl;
  cout << DoubleCheeseburgers << endl;
}
```

Be careful when you do this; getting it exactly right is very tricky. You declare the variable once inside the header file, but you must remember the word
extern. That tells the various files, “This variable is declared elsewhere,
but here’s its name and type so that you can use it.” Then you declare the
variable in one of the source files, without the word extern; this creates the
actual storage bin for the variable. Finally, you include the header file in each of your source files that uses the global variable.
When you share a variable among multiple source files, it is a global variable. A variable used by a single function is a local variable. If you share a
variable between functions within a single source file but not between
multiple source files, people call this a global variable that is local to the
source file.
Use the word extern in your header file when using a global variable. If you
forget to do that, you give each source file its own variable that happens to
have the same name.



### Quotes or Brackets

Regardless of where you put your header files, there are rules for when to
use quotes and when to use brackets.

The compiler looks in several directories to find header files. And it can, possibly, look in the same directory as the source file.

If you use angle brackets (that is, less-than and greater-than signs), as in #include <string>, the compiler does not look in the same directory as the source file.

If you use double quotes, as in #include "safestuff.h", the compiler first looks in the same directory as the source file. And if the compiler doesn’t find the header file there, it looks in the remaining directories, as it would with angle brackets.

Some people always like to use double quotes. That way, whether the header
file is in the same file as the source file or not, the compiler should find it.




The difference is that you should use angle brackets only for the standard library and system headers, although some third-party libraries recommend the use of angle brackets too. Use double quotes for everything else. The C++ standard is deliberately vague and recommends that angle brackets be used for headers that are provided with the system and quotes be used for other headers. Vendors of add-on libraries have all taken different approaches concerning naming their library files and whether they require angle brackets or double quotes.


For your own files, the important aspect is that the compiler must be able to find all your #include files. The easiest way to do that is to keep them in the same directory or folder as your source files. As your projects become larger and more complex, you probably will want to move all the #include files to a separate area. In this case, you have to consult your compiler documentation, to learn how to inform the compiler about that separate area. Users of g++ and other UNIX and UNIX-like command-line tools typically use the -I (capital letter I) option. Microsoft’s command-line compiler uses /I. IDEs have a project option with which you can add a directory or folder to the list of places to search for #include files. For many compilers, the only difference between angle brackets and quotes is where it looks for the file. A few compilers have additional differences that are specific to that compiler. In a source file, I like to list all the standard headers together, in alphabetical order, and list them first, followed by the #include files that are specific to the program (also in alphabetical order). This organization makes it easy for me to determine whether a source file #includes a particular header and helps me add or remove #include directives as needed.


Most professional programmers today always use angle brackets. This forces programmers to put their header files in a common area. With really big projects, programmers like to have a directory dedicated to source files and another directory dedicated to header files. No header file is ever in the same directory as the source file.

For small projects, some people like to lump all the source and header files into a single directory. These people typically use angle brackets around system header files (such as #include <string>) and use double quotes around their own header files.

If you follow this same approach, you immediately know whether the #include line refers to one of your own header files or another header file. If it refers to your own, it has double quotes.

If you start working on a large C++ project, you will probably find that project managers use the rule of always using angle brackets. For large projects, this is typically the best policy.

If you try to compile and you get a No such file or directory error on the #include line, it’s probably because you put the header file in a source file directory but used angle brackets instead of double quotes. Try switching that line to double quotes.






### Using the Mysterious Header Wrappers
When you include a header file, you usually want to include it only once per source file.

This can create a problem: Suppose that you have a huge software project, and several header files include another of your header files, called superheader.h. If you include all these other header files, how can you be sure to pick up the superheader.h file only once?

"#include-ing" the same file more than once might repeat all the declarations in that file, which is not allowed.

The answer looks strange but does the trick. These lines protects against this possible mistake with #ifndef, #define, and #endif.

Incorperate these preprocessor directive in your header files:

```cpp
#ifndef SHAREALIKE_H
#define SHAREALIKE_H
  //... header file code
#endif
```
These lines use statements called preprocessor directives.
These lines deal with the definition of a preprocessor symbol, in this case SHAREALIKE_H, that is sort of like a variable but is used only during compilation.

In this case, the symbol is called SHAREALIKE_H; we picked it by taking the filename, making it all caps, and replacing the dot with an underscore.


The first line has the directive #ifndef which is short for “if not defined,” so the first line tests whether the symbol definition that follows it has previously been defined or not.

The second line has the directive #define which goes about defining a special variable called a symbol, once the symbol has been defined subsequent #ifndef checks will fail.

The last line has the directive #endif, which closes the first line conditional #ifndef at the end of the file.

In this example,
When the file is first #include-ed, the first line checks to see whether the symbol has been defined. If not, it proceeds with the lines of code that follow. The next line defines the symbol SHAREALIKE_H, which is then defined for the rest of the compilation process. Then the compiler handles all the rest of the lines in the file. Finally, the last line, #endif, simply finishes the very first line. If the same file is #include-ed again, SHAREALIKE_H is now defined, so the #ifndef is false, and the entire file is skipped, down to #endif.

This idiom is called an include guard or header wrappers, and serve to ensure  that the code in the header gets processed only once per source code file each time you compile.











### Separate Compilation Of Classes
Typically, we place the declarations that specify the interface to a module in a file with a name indicating its intended use.

When a class is defined that can be used in a different file, a header can be used to separate the interface (the declaration) from the implementation (the
definition of the member variables and functions) so the implementation can be
changed without forcing a re-compile of the entire system.

You achieve this end by putting the declaration for your new type in a header file. This declaration is placed in the file Vector.h.

```cpp
// Vector.h:
class Vector {
public:
  inline Vector(int s);
  inline double& operator[](int i);
  inline int size();
private:
  double∗ elem; // elem points to an array of sz doubles
  int sz;
};
```

functions defined inside the class declaration are implicitly inline. But
I declared them with the inline keyword anyway. This is a good practice to remind the human reader that
these functions are inline. It also promotes a hybrid style of programming.

Users then include that file, called a header file, to access that interface. For example:

```cpp
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
```

To help the compiler ensure consistency, the .cpp file providing the implementation of Vector will also include the .h file providing its interface:

```cpp
// Vector.cpp:
 #include "Vector.h" // get Vector’s interface

 Vector::Vector(int s)
 : elem{new double[s]}, sz{s} // initialize members
 {}

 double& Vector::operator[](int i)
 {
   return elem[i];
 }

 int Vector::size()
 {
   return sz;
 }
```

The code in user.cpp and Vector.cpp shares the Vector interface information presented in Vector.h, but the two files are otherwise independent and can be separately compiled.

Strictly speaking, using separate compilation isn’t a language issue; it is an issue of how best to take advantage of a particular language implementation.

However, it is of great practical importance. The best approach to program organization is to think of the program as a set of modules with well-defined dependencies, represent that modularity logically through language features, and
then exploit the modularity physically through files for effective separate compilation.

A .cpp file that is compiled by itself (including the h files it #includes) is called a translation unit.

A program can consist of many thousand translation units.




### Global constants
In some applications, certain symbolic constants may need to be used throughout your code (not just in one location). These can include physics or mathematical constants that don’t change (e.g. pi or Avogadro’s number), or application-specific “tuning” values (e.g. friction or gravity coefficients). Instead of redefining these constants in every file that needs them (a violation of the “Don’t Repeat Yourself” rule), it’s better to declare them once in a central location and use them wherever needed. That way, if you ever need to change them, you only need to change them in one place, and those changes can be propagated out.

Global variables are usually a bad idea, but global constants can be extremely helpful. If you define a constexpr constant, you can put that in a header and not worry about it again. But not all constant objects can be constexpr. If you need to define a global constant and cannot make it constexpr, you need to declare it in a header and define it in a separate source file, which you link with the rest of your program. Use the extern keyword to declare the constant in the header. Another reason to separate the declaration and definition of a global constant is when you may need to change the value of the constant but do not want to recompile the entire program. For example, suppose you need to define some global constants for use in a larger program. The program name and global version number will not change often or will change when the program is rebuilt anyway, so they can be made constexpr and declared in globals.hpp. But you also want to declare a string called credits, which contains citations and credits for the entire project. You don’t want to rebuild your component just because someone else added a credit to the string. So the definition of credits goes into a separate globals.cpp file.

globals.hpp has include guards and uses constexpr for globals with values and extern for globals without values.

//globals.hpp
```cpp
#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_
#include <string_view>
constexpr std::string_view program_name{ "The Ultimate Program" };
constexpr std::string_view program_version{ "1.0" };
extern const std::string_view program_credits;
#endif
```

//globals.cpp
```cpp
#include "globals.hpp"
std::string_view const program_credits{
  "Ray Lischner\n"
  "Jane Doe\n"
  "A. Nony Mouse\n"
};
```

//main.cpp
```cpp
#include <iostream>
#include "globals.hpp"
int main()
{
std::cout << "Welcome to " << program_name << ' ' << program_version << '\n';
std::cout << program_credits;
}
```

Global constants as internal variables

There are multiple ways to facilitate this within C++. Pre-C++17, the following is probably the easiest and most common:

1) Create a header file to hold these constants
2) Inside this header file, define a namespace
3) Add all your constants inside the namespace (make sure they’re constexpr)
4) #include the header file wherever you need it

For example:

//constants.h:
```cpp
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
```

Then use the scope resolution operator (::) with the namespace name to the left, and your variable name to the right in order to access your constants in .cpp files:

//main.cpp:
```cpp
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
```

When this header gets #included into a .cpp file, each of these variables defined in the header will be copied into that code file at the point of inclusion. Because these variables live outside of a function, they’re treated as global variables within the file they are included into, which is why you can use them anywhere in that file.

Because const globals have internal linkage, each .cpp file gets an independent version of the global variable that the linker can’t see. In most cases, because these are const, the compiler will simply optimize the variables away.

As an aside...

The term “optimizing away” refers to any process where the compiler optimizes the performance of your program by removing things in a way that doesn’t affect the output of your program. For example, lets say you have some const variable x that’s initialized to value 4. Wherever your code references variable x, the compiler can just replace x with 4 (since x is const, we know it won’t ever change to a different value) and avoid having to create and initialize a variable altogether.



### Global constants as external variables

The above method has a few potential downsides.

While this is simple (and fine for smaller programs), every time constants.h gets #included into a different code file, each of these variables is copied into the including code file. Therefore, if constants.h gets included into 20 different code files, each of these variables is duplicated 20 times. Header guards won’t stop this from happening, as they only prevent a header from being included more than once into a single including file, not from being included one time into multiple different code files.

This introduces two challenges:
1) Changing a single constant value would require recompiling every file that includes the constants header, which can lead to lengthy rebuild times for larger projects.
2) If the constants are large in size and can’t be optimized away, this can use a lot of memory.

One way to avoid these problems is by turning these constants into external variables, since we can then have a single variable (initialized once) that is shared across all files. In this method, we’ll define the constants in a .cpp file (to ensure the definitions only exist in one place), and put forward declarations in the header (which will be included by other files).

NOTE

We use const instead of constexpr in this method because constexpr variables can’t be forward declared, even if they have external linkage.

//constants.cpp
```cpp
#include "constants.h"

namespace constants
{
  // actual global variables
  extern const double pi { 3.14159 };
  extern const double avogadro { 6.0221413e23 };
  extern const double my_gravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}
```

//constants.h
```cpp
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
```

Use in the code file stays the same:

//main.cpp
```cpp
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
```

Because global symbolic constants should be namespaced (to avoid naming conflicts with other identifiers in the global namespace), the conventional use of a “g_” naming prefix is not necessary.

Now the symbolic constants will get instantiated only once (in constants.cpp), instead of once every time constants.h is #included, and the other uses will simply refer to the version in constants.cpp. Any changes made to constants.cpp will require recompiling only constants.cpp.

However, there are a couple of downsides to this method. First, these constants are now considered compile-time constants only within the file they are actually defined in (constants.cpp), not anywhere else they are used. This means that outside of constants.cpp, they can’t be used anywhere that requires a compile-time constant. Second, the compiler may not be able to optimize these as much.

Given the above downsides, prefer defining your constants in the header file. If you find that for some reason those constants are causing trouble, you can move some or all of them into a .cpp file as needed.



### Global constants as inline variables

C++17 introduced a new concept called inline variables. In C++, the term inline has evolved to mean “multiple definitions are allowed”. Thus, an inline variable is one that is allowed to be defined in multiple files without violating the one definition rule. Inline global variables have external linkage by default.

Inline variables have two primary restrictions that must be obeyed:
1) All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
2) The inline variable definition (not a forward declaration) must be present in any file that uses the variable.

The linker will consolidate all inline definitions into a single variable definition. This allows us to define variables in a header file and have them treated as if there was only one definition in a .cpp file somewhere. These variables also retain their constexpr-ness in all files in which they are included.

With this, we can go back to defining our globals in a header file without the downside of duplicated variables:

//constants.h:
```cpp
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
```
main.cpp:
```cpp
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
```
We can include constants.h into as many code files as we want, but these variables will only be instantiated once and shared across all code files.

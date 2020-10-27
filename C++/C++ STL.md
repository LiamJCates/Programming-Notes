Initially developed by Bjarne Stroustroup at Bell Labs in 1979, C++ was designed to be an object-oriented successor to C that implements concepts such as inheritance, abstraction, polymorphism, and encapsulation.

C++ features classes that are used to contain member data and member
methods. These member methods operate using member data. The effect of this
organization is that the programmer models data and actions he wants to perform
using the same.

C++ is a statically typed language. That is, the type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use.
The type of an object determines the set of operations applicable to it.






C++ is a compiled language, this means, for a program to run, its source text has to be processed by a compiler, producing object files, which are combined by a linker yielding an executable program.

Many popular C++ compilers have continued to support C programming too.

A C++ program typically consists of many source code files (called source files).






The ISO C++ standard defines two kinds of entities:
• Core language features, such as built-in types (e.g., char and int) and loops (e.g., for-statements and while-statements)
• Standard-library components, such as containers (e.g., vector and map) and I/O operations
(e.g., << and getline())










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


## Namespaces
The reason you used std::cout in the program and not only cout is that the artifact (cout) that you want to invoke is in the standard (std) namespace.

Assume that you didn’t use the namespace qualifier in invoking cout and assume that
cout existed in two locations known to the compiler—which one should the compiler
invoke? This causes a conflict and the compilation fails, of course. This is where
namespaces get useful. Namespaces are names given to parts of code that help in
reducing the potential for a naming conflict. By invoking std::cout, you are telling the
compiler to use that one unique cout that is available in the std namespace.
You use the std (pronounced “standard”) namespace to invoke
functions, streams, and utilities that have been ratified by the
ISO Standards Committee.

By telling the compiler that you are using the namespace std, you
don’t need to explicitly mention the namespace when using std::cout or
std::endl.


using namespace std;
effect is that, when compiling, for any unrecognized name, the compiler will try prepending std:: to it to see if it exists in the std namespaces can have unintended effects

it is recommended that if you are only using a small number of namespace members, such as cout for instance, instead use
using std::cout;

this will ensure that you only use what you need from a library and also document what you are using from a given library

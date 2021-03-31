It's traditional to use different files for different classes.

This means that you're going to have some code in one file that's going to use a class, maybe create an instance of it or call its functions and so on, using  code that is in another file.

The names of program elements such as variables, functions, classes, and so on must be declared before they can be used. For example, you can't just write x = 42 without first declaring 'x'.
C++

int x; // declaration
x = 42; // use x

The declaration tells the compiler whether the element is an int, a double, a function, a class or some other thing. Furthermore, each name must be declared (directly or indirectly) in every .cpp file in which it is used. When you compile a program, each .cpp file is compiled independently into a compilation unit. The compiler has no knowledge of what names are declared in other compilation units. That means that if you define a class or function or global variable, you must provide a declaration of that thing in each additional .cpp file that uses it. Each declaration of that thing must be exactly identical in all files. A slight inconsistency will cause errors, or unintended behavior, when the linker attempts to merge all the compilation units into a single program.

To minimize the potential for errors, C++ has adopted the convention of using header files to contain declarations. You make the declarations in a header file, then use the #include directive in every .cpp file or other header file that requires that declaration. The #include directive inserts a copy of the header file directly into the .cpp file prior to compilation.


Example

The following example shows a common way to declare a class and then use it in a different source file. We'll start with the header file, my_class.h. It contains a class definition, but note that the definition is incomplete; the member function do_something is not defined:
C++

// my_class.h
namespace N
{
    class my_class
    {
    public:
        void do_something();
    };

}

Next, create an implementation file (typically with a .cpp or similar extension). We'll call the file my_class.cpp and provide a definition for the member declaration. We add an #include directive for "my_class.h" file in order to have the my_class declaration inserted at this point in the .cpp file, and we include <iostream> to pull in the declaration for std::cout. Note that quotes are used for header files in the same directory as the source file, and angle brackets are used for standard library headers. Also, many standard library headers do not have .h or any other file extension.

In the implementation file, we can optionally use a using statement to avoid having to qualify every mention of "my_class" or "cout" with "N::" or "std::". Don't put using statements in your header files!
C++

// my_class.cpp
#include "my_class.h" // header in local directory
#include <iostream> // header in standard library

using namespace N;
using namespace std;

void my_class::do_something()
{
    cout << "Doing something!" << endl;
}

Now we can use my_class in another .cpp file. We #include the header file so that the compiler pulls in the declaration. All the compiler needs to know is that my_class is a class that has a public member function called do_something().
C++

// my_program.cpp
#include "my_class.h"

using namespace N;

int main()
{
    my_class mc;
    mc.do_something();
    return 0;
}

After the compiler finishes compiling each .cpp file into .obj files, it passes the .obj files to the linker. When the linker merges the object files it finds exactly one definition for my_class; it is in the .obj file produced for my_class.cpp, and the build succeeds.
Include guards

Typically, header files have an include guard or a #pragma once directive to ensure that they are not inserted multiple times into a single .cpp file.
C++

// my_class.h
#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

namespace N
{
    class my_class
    {
    public:
        void do_something();
    };
}

#endif /* MY_CLASS_H */

What to put in a header file

Because a header file might potentially be included by multiple files, it cannot contain definitions that might produce multiple definitions of the same name. The following are not allowed, or are considered very bad practice:

    built-in type definitions at namespace or global scope
    non-inline function definitions
    non-const variable definitions
    aggregate definitions
    unnamed namespaces
    using directives

Use of the using directive will not necessarily cause an error, but can potentially cause a problem because it brings the namespace into scope in every .cpp file that directly or indirectly includes that header.
Sample header file

The following example shows the various kinds of declarations and definitions that are allowed in a header file:
C++

// sample.h
#pragma once
#include <vector> // #include directive
#include <string>

namespace N  // namespace declaration
{
    inline namespace P
    {
        //...
    }

    enum class colors : short { red, blue, purple, azure };

    const double PI = 3.14;  // const and constexpr definitions
    constexpr int MeaningOfLife{ 42 };
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); // static_assert
        return MeaningOfLife;
    }
    using vstr = std::vector<int>;  // type alias
    extern double d; // extern variable

#define LOG   // macro definition

#ifdef LOG   // conditional compilation directive
    void print_to_log();
#endif

    class my_class   // regular class definition,
    {                // but no non-inline function definitions

        friend class other_class;
    public:
        void do_something();   // definition in my_class.cpp
        inline void put_value(int i) { vals.push_back(i); } // inline OK

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{ 0 };  // member initialization
        short g{ 0 };
        short b{ 0 };
    };

    template <typename T>  // template definition
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... function definition OK in template
        }
    private:
        std::vector<T> vals;
    };

    template <typename T>  // template declaration
    class value_widget;
}










You have to tell the compiler in the calling code a little bit about the class, it is a class, here are its functions, that kind of thing. You don't have to implement them all, you just declare the class, and that's essentially making a promise to the compiler. It says somewhere else in my system I have some implementation of a class that looks like this. That last step in building, where you link all the compiled sources together, is how that promise gets kept. So as long as there's a file being compiled that actually implements the class, the linker will take care of making the connection between the code that uses the class and the code that implements the class. In C++, unlike some other languages you may know, there isn't such a thing as reflection or metadata, so you have to tell the compiler, there is a class called whatever and here's what it can do. Now you could type that declaration of the class into every file that uses it, or paste it from somewhere, but obviously it's more convenient to just put that in one place, and that's what the include directive does. It essentially pastes another source file into your source file. And this has an obvious advantage, if you change the declaration you just change the thing you're pasting in, or including in, and it will get included the changed version everywhere that you used it. Generally we call these header files and we give them the extension .h. Then your actual implementation of the file is in a .cpp or whatever extension you're using on your system that implements all of the things that the declaration of the class promised would be there.

Error messages can come from the compiler or the linker. You know the compiler cares, have you declared that function? The linker cares, have you implemented that function? You usually declare things in a. h, you usually implement them in a. cpp. So if you have a linker error don't go looking in a header file for the problem. If you have a compiler error you may look in either file. Compiler's about making a promise and the linker is about keeping that promise.

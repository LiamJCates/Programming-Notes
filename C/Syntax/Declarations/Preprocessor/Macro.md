Often something described as a function may have a macro definition as well. This normally has no effect on how your program runs—the macro definition does the same thing as the function would. In particular, macro equivalents for library functions evaluate arguments exactly once, in the same way that a function call would.

The main reason for these macro definitions is that sometimes they can produce an inline expansion that is considerably faster than an actual function call.

Taking the address of a library function works even if it is also defined as a macro. This is because, in this context, the name of the function isn’t followed by the left parenthesis that is syntactically necessary to recognize a macro call.

You might occasionally want to avoid using the macro definition of a function—perhaps to make your program easier to debug. There are two ways you can do this:

• You can avoid a macro definition in a specific use by enclosing the name of the function in parentheses. This works because the name of the function doesn’t appear in a syntactic context where it is recognizable as a macro call.

• You can suppress any macro definition for a whole source file by using the ‘#undef’ preprocessor directive, unless otherwise stated explicitly in the description of that facility.

For example, suppose the header file stdlib.h declares a function named abs with extern int abs (int); and also provides a macro definition for abs. Then, in:

 #include <stdlib.h> int f (int *i) { return abs (++*i); }

the reference to abs might refer to either a macro or a function. On the other hand, in each of the following examples the reference is to a function and not a macro.

 #include <stdlib.h>
 int g (int *i) { return (abs) (++*i); }

 #undef abs
 int h (int *i) { return abs (++*i); }

Since macro definitions that double for a function behave in exactly the same way as the actual function version, there is usually no need for any of these methods. In fact, removing macro definitions usually just makes your program slower.

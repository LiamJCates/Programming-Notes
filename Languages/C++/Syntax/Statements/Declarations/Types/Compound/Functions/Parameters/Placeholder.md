Placeholder arguments
Arguments in a function declaration can be declared without
identifiers. When these are used with default arguments, it can look
a bit funny. You can end up with
void f(int x, int = 0, float = 1.1);
In C++ you don’t need identifiers in the function definition, either:
void f(int x, int, float flt) { /* ... */ }
In the function body, x and flt can be referenced, but not the
middle argument, because it has no name. Function calls must still
provide a value for the placeholder, though: f(1) or f(1,2,3.0). This
syntax allows you to put the argument in as a placeholder without
using it. The idea is that you might want to change the function
definition to use the placeholder later, without changing all the
code where the function is called. Of course, you can accomplish
the same thing by using a named argument, but if you define the
argument for the function body without using it, most compilers
will give you a warning message, assuming you’ve made a logical
error. By intentionally leaving the argument name out, you
suppress this warning.
More important, if you start out using a function argument and
later decide that you don’t need it, you can effectively remove it
without generating warnings, and yet not disturb any client code
that was calling the previous version of the function.

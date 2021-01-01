## Value Return
Once we have computed a result, we need to get it out of the function and back to the caller. Again,
the default for value return is to copy and for small objects that’s ideal. We return ‘‘by reference’’
only when we want to grant a caller access to something that is not local to the function. For example:
class Vector {
public:
// ...
double& operator[](int i) { return elem[i]; } // retur n reference to ith element
private:
double∗ elem; // elem points to an array of sz
// ...
};
The ith element of a Vector exists independently of the call of the subscript operator, so we can
return a reference to it.
On the other hand, a local variable disappears when the function returns, so we should not
return a pointer or reference to it:
int& bad()
{
int x;
// ...
return x; // bad: return a reference to the local var iable x
}
Fortunately, all major C++ compilers will catch the obvious error in bad().
Returning a reference or a value of a ‘‘small’’ type is efficient, but how do we pass large
amounts of information out of a function? Consider:44 Modularity Chapter 3
Matrix operator+(const Matrix& x, const Matrix& y)
{
Matrix res;
// ... for all res[i,j], res[i,j] = x[i,j]+y[i,j] ...
return res;
}
Matrix m1, m2;
// ...
Matrix m3 = m1+m2; // no copy
A Matrix may be very large and expensive to copy even on modern hardware. So we don’t copy, we
give Matrix a move constructor (§5.2.2) and very cheaply move the Matrix out of operator+(). We do
not need to regress to using manual memory management:
Matrix∗ add(const Matrix& x, const Matrix& y) // complicated and error-prone 20th century style
{
Matrix∗ p = new Matrix;
// ... for all *p[i,j], *p[i,j] = x[i,j]+y[i,j] ...
return p;
}
Matrix m1, m2;
// ...
Matrix∗ m3 = add(m1,m2); // just copy a pointer
// ...
delete m3; // easily forgotten
Unfortunately, returning large objects by returning a pointer to it is common in older code and a
major source of hard-to-find errors. Don’t write such code. Note that operator+() is as efficient as
add(), but far easier to define, easier to use, and less error-prone.
If a function cannot perform its required task, it can throw an exception (§3.5.1). This can help
avoid code from being littered with error-code tests for ‘‘exceptional problems.’’
The return type of a function can be deduced from its return value. For example:
auto mul(int i, double d) { return i∗d; } // here, "auto" means "deduce the return type"
This can be convenient, especially for generic functions (function templates; §6.3.1) and lambdas
(§6.3.3), but should be used carefully because a deduced type does not offer a stable interface: a
change to the implementation of the function (or lambda) can change the type.





## Automatic Return Type Deduction

Starting with C++14, the same
applies also to functions. Instead of specifying the return type, you would use auto and
let the compiler deduce the return type for you on the basis of return values you program.

Functions that rely on automatic return type deduction need to
be defined (i.e., implemented) before they’re invoked. This is
because the compiler needs to know a function’s return type at
the point where it is used. If such a function has multiple return
statements, they need to all deduce to the same type. Recursive
calls need to follow at least one return statement.

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


In addition to functions (§1.3), classes (§2.3), and enumerations (§2.5), C++ offers namespaces as a
mechanism for expressing that some declarations belong together and that their names shouldn’t
clash with other names. For example, I might want to experiment with my own complex number
type (§4.2.1, §14.4):
namespace My_code {
class complex {
// ...
};
complex sqr t(complex);
// ...
int main();
}
int My_code::main()
{
complex z {1,2};
auto z2 = sqrt(z);
std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
// ...
}
int main()
{
return My_code::main();
}
By putting my code into the namespace My_code, I make sure that my names do not conflict

The simplest way to access a name in another namespace is to qualify it with the namespace
name (e.g., std::cout and My_code::main). The ‘‘real main()’’ is defined in the global namespace,
that is, not local to a defined namespace, class, or function.
If repeatedly qualifying a name becomes tedious or distracting, we can bring the name into a
scope with a using-declaration:Section 3.4 Namespaces 35
void my_code(vector<int>& x, vector<int>& y)
{
using std::swap; // use the standard-librar y sw ap
// ...
swap(x,y); // std::swap()
other::swap(x,y); // some other swap()
// ...
}
A using-declaration makes a name from a namespace usable as if it was declared in the scope in
which it appears. After using std::swap, it is exactly as if swap had been declared in my_code().
To gain access to all names in the standard-library namespace, we can use a using-directive:
using namespace std;
A using-directive makes unqualified names from the named namespace accessible from the scope
in which we placed the directive. So after the using-directive for std, we can simply write cout
rather than std::cout. By using a using-directive, we lose the ability to selectively use names from
that namespace, so this facility should be used carefully, usually for a library that’s pervasive in an
application (e.g., std) or during a transition for an application that didn’t use namespaces.

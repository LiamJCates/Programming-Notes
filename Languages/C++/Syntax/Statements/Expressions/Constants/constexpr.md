### constexpr

Constant expressions are expressions that can be evaluated at compile time.

Whenever all the information required to compute an expression is present at compile time, the compiler is compelled to do so if that expression is marked constexpr. This simple commitment can enable a surprisingly large impact on code readability and runtime performance.

For performance and safety reasons, whenever a computation can be done at compile time rather than runtime, you should do it.



Both const and constexpr are closely related.

Whereas constexpr enforces that an expression is compile time evaluable, const enforces that a variable cannot change within some scope (at runtime). All constexpr expressions are const because they’re always fixed at runtime.



### Constant Expressions
Simple mathematical operations involving literals are an obvious example of expressions that can be evaluated at compile time.

All constexpr expressions begin with one or more fundamental types. You can build on top of these types by using operators and other constexpr functions.

Nonintegral constants must be converted (either explicitly or implicitly) to integral types to be legal in a constant expression.

The integral types are bool, char, char8_t, char16_t, char32_t, wchar_t, short, int, long, long long, or any implementation-defined extended integer types, including any signed, unsigned, and cv-qualified variants

Explicit conversions to integral types are legal in constant expressions; all other types and derived types are illegal except when used as operands to the sizeof operator.




Examples

constexpr int dmv = 17; // dmv is a named constant


vector<double> v {1.2, 3.4, 4.5}; // v is not a constant
constexpr double s2 = sum(v); // error : sum(v) is not a constant expression



### constexpr Functions
For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined by the prefix constexpr:

  constexpr double square(double x) { return x∗x; }

  constexpr double max1 = 1.4∗square(17);
  // OK 1.4*square(17) is a constant expression

  int var = 17; // var is not a constant

  constexpr double max2 = 1.4∗square(var);
  // error : var is not a constant expression

A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression.

We allow a constexpr function to be called with non-constant-expression arguments in contexts that do not require constant expressions. That way, we don’t have to define essentially the same function twice: once for constant expressions and once for variables.



Keyword constexpr allows function-like declaration of constants:

  constexpr double GetPi() {return 22.0 / 7;}

One constexpr can use another:

  constexpr double TwicePi() {return 2 * GetPi();}

constexpr may look like a function, however, allows for optimization possibilities from the compiler’s and application’s point of view.

In the preceding example, TwicePi() is a constexpr that uses a constant expression GetPi(). This will possibly trigger a compile-time optimization wherein every usage of TwicePi() is simply replaced by 6.28571 by the compiler rather than the code that would calculate 2 x 22 / 7 when executed.

Constant expressions need to contain simple implementations that evaluate to simple types like integer, double, and so on.

C++14 allows constexpr to contain decision-making constructs such as if and switch statements.

The usage of constexpr will not guarantee compile-time optimization—for example, if you use a constexpr expression to double a user provided number. The outcome of such an expression cannot be calculated by the compiler, which may ignore the usage of constexpr and compile as a regular function.

To be constexpr, a function must be rather simple and cannot have side effects and can only use information passed to it as arguments. In particular, it cannot modify non-local variables, but it can have loops and use its own local variables.

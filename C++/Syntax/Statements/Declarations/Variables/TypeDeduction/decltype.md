A decltype type expression yields another expression’s resultant type:

  decltype(expression)

This expression resolves to the resulting type of the expression:

  decltype(100) //int

Outside of generic programming with templates, decltype is rare. You can combine auto-return-type deduction and decltype to document the return types of function templates.

Consider an add function, which defines a function template add that adds two arguments together.

  #include <cstdio>
  template <typename X, typename Y>
    auto add(X x, Y y) -> decltype(x + y) {
    return x + y;
  }

  int main() {
    auto my_double = add(100., -10);
    printf("decltype(double + int) = double; %f\n", my_double);
    auto my_uint = add(100U, -20);
    printf("decltype(uint + int) = uint; %u\n", my_uint);
    auto my_ulonglong = add(char{ 100 }, 54'999'900ull);
    printf("decltype(char + ulonglong) = ulonglong; %llu\n", my_ulonglong);
  }

Output

  decltype(double + int) = double; 90.000000
  decltype(uint + int) = uint; 80
  decltype(char + ulonglong) = longlong; 55000000


The add function employs auto type deduction with the decltype type expression.

Each time you instantiate a template with two types X and Y, the compiler evaluates decltype(X + Y) and fixes the return type of add. Within main, you provide three instantiations. First, you add a double and an int. The compiler determines that decltype(double{ 100. } + int{ -10 }) is a double, which fixes the return type of this add instantiation. This, in turn, sets the type of my_double to double.

You have two other instantiations:
  one for an unsigned int and int (results in an unsigned int)
  one for a char and an unsigned long long (results in an unsigned long long).

### Named Constants
A memory location whose content is not allowed to change during program execution.

In C++, you can use a named constant to instruct a program to mark those memory locations in which data is fixed throughout program execution.


To allocate constant memory, we use C++’s declaration statement with the const keyword type qualifier:

const dataType identifier = value;

In C++, const is a reserved word. It should be noted that a named constant must be initialized when it is declared as the compiler will reject any attempt to change the value after declaration.

Named constant's named follow the typical rules for identifiers:
[C++\Syntax\Statements\Declarations\Identifiers.md]

By convention identifiers of named constants use upper snake case:
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Using a named constant to store fixed data, rather than using a literal, has one major advantage. If the fixed data changes, a literal value would need to be replace throughout the entire program. Instead, the literal can be assigned once to a named constant and that constant can be used throughout your code, to change the value throughout the program, change the single const declaration.

This can also reduce error. The compiler is unable to determine if a properly formatted literal value is inconsistent throughout the program. It is, however, able to determine if the identifier of a named constant is incorrect, and will throw an error.



Examples:

int var = 17; // var is not a constant

const double SQRV = sqrt(var);
// SQRV is a named constant, possibly computed at run time

double sum(const vector<double>&)   // function sum wont modify its argument
  {...}


vector<double> v {1.2, 3.4, 4.5}; // v is not a constant

const double S1 = sum(v); // OK: sum(v) is evaluated at run time

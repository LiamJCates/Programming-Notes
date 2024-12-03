### Named Constants

In C++, you can use a named constant to instruct a program to mark memory locations in which data is fixed, or unchanged, throughout program execution.

To allocate constant memory, we use C++’s declaration statement with the const keyword type qualifier:

const dataType identifier = expression;

In C++, const is a reserved word. It should be noted that a named constant must be initialized when it is declared as the compiler will reject any attempt to change the value after declaration.

Named constant's named follow the typical rules for identifiers

For more information regarding Identifiers, see:
[C++\Syntax\Statements\Declarations\Identifiers.md]

By convention, identifiers of named constants use upper snake case.

For general information regarding identifier conventions, see:
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Using a named constant to store fixed data, rather than using a literal, has one major advantage. If the fixed data changes, a literal value would need to be replaced at every usage, throughout the entire program. Instead, the literal can be assigned once to a named constant and that constant can be used throughout your code. If that value ever changes, to change the value throughout the program, change the assignment statement.

This can also reduce error. The compiler is unable to determine if a properly formatted literal value is inconsistent throughout the program. It is, however, able to determine if the identifier of a named constant is incorrect, and will throw an error.

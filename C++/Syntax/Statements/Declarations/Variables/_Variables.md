C++ defines variables to store values that the program processes

Information on values:
[C++\Types&Values\Values.md]

C++ is a strongly-typed language, and requires every variable to be declared with its type before its first use. This informs the compiler the size to reserve in memory for the variable and how to interpret its value. The syntax to declare a new variable in C++ is straightforward: we simply write the type followed by the variable name (i.e., its identifier).

Variable Declaration:

  VariableType VariableName;

Example:

  int score;
  float GPA;
  bool isRaining;

Each of the three variables declared specify a type and an identifier.

C++ makes it possible to declare multiple variables of a type at once. If declaring more than one variable of the same type, they can all be declared in a single statement by separating their identifiers with commas.

  int firstNumber, secondNumber, multiplicationResult;

Is equal to:

  int firstNumber;
  int secondNumber;
  int multiplicationResult;

When the variables in the example above are declared, they have an undetermined value until they are assigned a value for the first time. But it is possible for a variable to have a specific value from the moment it is declared. This is called the initialization of the variable.

For more information about initialization see:
[C++\Types&Values\Initialization.md]


VariableType VariableName = InitialValue;

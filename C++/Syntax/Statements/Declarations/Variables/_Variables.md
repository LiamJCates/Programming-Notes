C++ defines variables to store values that the program processes

Information on values:
[C++\Semantics\Values.md]

Objects and variables

All computers have memory, called RAM (short for random access memory), that is available for your programs to use. You can think of RAM as a series of mailboxes that can be used to hold data while the program is running. A single piece of data, stored in memory somewhere, is called a value.

In some older programming languages (like Apple Basic), you could directly access these mailboxes (a statement could say something like go get the value stored in mailbox number 7532).

In C++, direct memory access is not allowed. Instead, we access memory indirectly through an object. An object is a region of storage (usually memory) that has a value and other associated properties (that we’ll cover in future lessons). When an object is defined, the compiler automatically determines where the object will be placed in memory. As a result, rather than say go get the value stored in mailbox number 7532, we can say, go get the value stored by this object and the compiler knows where in memory to look for that value. This means we can focus on using objects to store and retrieve values, and not have to worry about where in memory they’re actually being placed.

Objects can be named or unnamed (anonymous). A named object is called a variable, and the name of the object is called an identifier. In our programs, most of the objects we create will be variables.

In general programming, the term object typically refers to a variable, data structure in memory, or function. In C++, the term object has a narrower definition that excludes functions.

In order to create a variable, we use a special kind of declaration statement called a definition (we’ll clarify the difference between a declaration and definition later).

Variable Declaration:

  VariableType VariableName;

Example:

  int score;
  float GPA;
  bool isRaining;

Each of the three variables declared specify a type and an identifier.

C++ is a strongly-typed language, and requires every object be declared with its type before its first use.

In C++, the type of a variable must be known at compile-time (when the program is compiled), and that type can not be changed without recompiling the program. This means an integer variable can only hold integer values. If you want to store some other kind of value, you’ll need to use a different variable.

The type informs the compiler the size to reserve in memory for the object and how to interpret its value. The syntax to declare a new variable in C++ is straightforward: we simply write the type followed by the variable name (i.e., its identifier).

Variables are a named region of storage that can store a data value. A data type (more commonly just called a type) tells the compiler what type of value (e.g. a number, a letter, text, etc…) the variable will store.

A specific example:

  int x;

At compile time, when the compiler sees this statement, it makes a note to itself that we are defining a variable, giving it the name x, and that it is of type int. From that point forward, whenever the compiler sees the identifier x, it will know that we’re referencing this variable.

When the program is run (called runtime), the variable will be instantiated. Instantiation is a fancy word that means the object will be created and assigned a memory address. Variables must be instantiated before they can be used to store values. For the sake of example, let’s say that variable x is instantiated at memory location 140. Whenever the program then uses variable x, it will access the value in memory location 140. An instantiated object is sometimes also called an instance.

C++ makes it possible to declare multiple variables of a type at once. If declaring more than one variable of the same type, they can all be declared in a single statement by separating their identifiers with commas.

  int firstNumber, secondNumber, multiplicationResult;

Is equal to:

  int firstNumber;
  int secondNumber;
  int multiplicationResult;

When the variables in the example above are declared, they have an undetermined value until they are assigned a value for the first time. But it is possible for a variable to have a specific value from the moment it is declared. This is called the initialization of the variable.

After a variable has been defined, you can give it a value using the = operator. This process is called copy assignment (or just assignment) for short.

int width; // define an integer variable named width
width = 5; // copy assignment of value 5 into variable width

Copy assignment is named such because it copies the value on the right-hand side of the = operator to the variable on the left-hand side of the operator. The = operator is called the assignment operator.

One downside of assignment is that it requires at least two statements: one to define the variable, and one to assign the value.

These two steps can be combined. When a variable is defined, you can also provide an initial value for the variable at the same time. This is called initialization.

For more information about initialization see:
[C++\Types&Values\Initialization.md]


The C++ programming language defines three kinds of variables:

1. Instance Variables (Non-Static): They are instance variables so they are unique to each instance/object of a class.

2. Class Variables (Static): A class variable is any field with the static modifier. These variables are linked with the class not with the objects of the class. There is exactly one copy of these variables regardless of how many instances of the class are created.

3. Local Variables: the temporary variables in a method are called local variables. The local variables are only visible to the method in which they are declared. The parameters that are passed to the methods are also local variables of the called method.

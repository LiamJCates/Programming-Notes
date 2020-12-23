Programs usually use data in some shape or form. For data elements that change during program execution, as the program processes input to output, modern programming languages provide a construct known as variables to aid the programmer read, transform, and write values to computer memory.


Variables

A variable is a named memory block that holds a value. The value held in a variable can - and usually does - change as the program runs.

A variable's name is known as an identifier and follows certain naming conventions depending on the language used:
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Variables make it easy for a programmer to read and write values to locations in computer memory. The computer keeps track of which memory location the variable references and all the programmer has to do is remember the identifier the variable was given.



Declaration

Most programming languages require a variable to be declared before a value is assigned to it.

To declare a variable we must define a valid identifier and potentially a data type for languages for which the type system does not support type inference.

For more information about data types:
[Data Structures\Overview\Introduction to Data Types.md]

For more information about type systems:
[Programming Methods\Fundamentals\TypeSystem\TypeSystem.md]



Syntax
[type] [identifier]

Integer score
- would declare a variable called score which will hold integers.



Initialization



Assignment
Providing a value to be referenced by a named variable is called assignment.

Assignment is typically indicated by specifying a previously declared variable, the "=" symbol, and a value.

Some programming languages, such as Python, do not require variables to be explicitly declared before use.


Syntax
[identifier] = [value]

score = 0
- would assign the value 0 to the variable score

pseudocode will also use the "←" symbol to model assignment.

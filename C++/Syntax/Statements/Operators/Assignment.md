In C++ assignment is an expression that assigns a value to the specified identifier and resolves to the value assigned:

  x = 1 + 2;

As a consequence, it can be used within another assignment:

  x2 = x = 1 + 2;

Assignments are evaluated from right to left.

The above example would be executed

  x2 = (x = (1 + 2))

where both x and x2 are assigned the value 3

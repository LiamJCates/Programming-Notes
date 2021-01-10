### The Range-Based for Loop
Executes a for loop over a range.

Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a container.

For certain objects which are collections of other objects, like arrays, a C++ for loop may iterate over the range of values within an object. Each loop iteration references one element from the collection. The syntax is:

Syntax
(until C++20)

  attr(optional) for ( range_declaration : range_expression )
    statement 		

(since C++20)

  attr(optional) for ( init-statement; range_declaration : range_expression )
    statement

attr: is any number of attributes
init-statement(C++20) is either
    an expression statement (which may be a null statement ";")
    a simple declaration, typically a declaration of a variable with initializer, but it may declare arbitrary many variables or be a structured binding declaration

range_declaration: is a declaration of a named variable, whose type is the type of the element of the sequence represented by range_expression, or a reference to that type. Often uses the auto specifier for automatic type deduction

range_expression: is any expression that represents a suitable sequence (either an array or an object for which begin and end member functions or free functions are defined, see below) or a braced-init-list.

statement: is any statement, typically a compound statement, which is the loop body


Example:

  #include <cstdio>

  int main()
  {
    unsigned long maximum = 0;
    unsigned long values[] = { 10, 50, 20, 40, 0 };

    for(unsigned long value : values)
    {
      if (value > maximum) maximum = value;
    }
    printf("The maximum value is %lu.", maximum);
  }

Primary expressions are the building blocks of more complex expressions.

A complex C++ expressions are those made up of nested expressions, combined through the use of operators, and those nested expressions may in turn be either primary or complex.

The operands of any operator may be other expressions or primary expressions

The value of each primary expression operand must first be evaluated to achieve the resulting value of an expression.

primary: z = 2 + 1;

complex: z = f(y) / max(a[c], b[c]);

If you decompose a complex expression into ever smaller units, at some point you'll be left with units that are atomic in the sense that they cannot be decomposed further. Those are primary expressions.

Primary expressions are any of the following:
  Literals
  An expression in parentheses
  Id-expressions, including
      suitably declared unqualified identifiers (e.g. n or cout), and
      suitably declared qualified identifiers (e.g. std::string::npos)
  Lambda-expressions (C++11)
  Fold-expressions (C++17)
  Requires-expressions (C++20)

Examples of primary expressions include:

```cpp
  100 // literal
  'c' // literal
  this // in a member function, a pointer to the class instance
  ::func // a global function
  ::operator + // a global operator function
  ::A::B // a global qualified name
  ( i + 1 ) // a parenthesized expression

//more names
  MyClass // an identifier
  MyClass::f // a qualified name
  operator = // an operator function name
  operator char* // a conversion operator function name
  ~MyClass // a destructor name
  A::B   // a qualified name
  A<int> // a template id
```



### Parentheses

However, there is one non-atomic construct that the C++ Standard defines as primary: Expressions enclosed in round brackets (aka parentheses). The Standard lists them as primary expressions because they play the some role as truly atomic expressions when it comes to the order of evaluation.

Anything within the brackets must be evaluated before the value of the backeted expressions can enter into evaluations with other expressions. As this grouping by parentheses precedes all operators, we can change the order of evaluation to suit our needs:

  x * (y + z)   //computes the addition first

Parentheses preserve value, type, and value category.

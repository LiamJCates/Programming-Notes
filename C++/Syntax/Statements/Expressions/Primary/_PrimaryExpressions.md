C++ expressions can be complex, which is to say they can be made up of nested expressions, combined through the use of operators, and those nested expressions may in turn be complex.

If you decompose a complex expression into ever smaller units, at some point you'll be left with units that are atomic in the sense that they cannot be decomposed further. Those are primary expressions; they include identifiers, literals, the keyword this, and lambda expressions.

Primary expressions are any of the following:
  Literals
  An expression in parentheses
  Id-expressions, including
      suitably declared unqualified identifiers (e.g. n or cout), and
      suitably declared qualified identifiers (e.g. std::string::npos)
  Lambda-expressions (C++11)
  Fold-expressions (C++17)
  Requires-expressions (C++20)

The operands of any operator may be other expressions or primary expressions

The value of each primary expression operand must first be evaluated to achieve the resulting value of an expression.

However, there is one non-atomic construct that the C++ Standard defines as primary: Expressions enclosed in round brackets (aka parentheses). The Standard lists them as primary expressions because they play the some role as truly atomic expressions when it comes to the order of evaluation.

Anything within the brackets must be evaluated before the value of the backeted expressions can enter into evaluations with other expressions. As this grouping by parentheses precedes all operators, we can change the order of evaluation to suit our needs:

  x * (y + z)   //computes the addition first

Parentheses preserve value, type, and value category.

Binary Operators
Operators that function on two operands are called binary operators.

The definition of a binary operator implemented as a global function or a static member function is the following:

  return_type operator_type (parameter1, parameter2);

The definition of a binary operator implemented as a class member is

  return_type operator_type (parameter);

The reason the class member version of a binary operator accepts only one parameter is that the second parameter is usually derived from the attributes of the class itself.


Overloadable Binary Operators
| Symbol | Name |
|--------|------| |
| , | Comma |
| != | Inequality |
| % | Modulus |
| %= | Modulus/assignment |
| & | Bitwise AND |
| && | Logical AND |
| &= | Bitwise AND/assignment |
| * | Multiplication |
| *= | Multiplication/assignment |
| + | Addition |
| += | Addition/assignment |
| - | Subtraction |
| -= | Subtraction/assignment |
| ->* | Pointer-to-member selection |
| / | Division |
| /= | Division/assignment |
| < | Less than |
| << | Left shift |
| <<= | Left shift/assignment |
| <= | Less than or equal to |
| = | Assignment, Copy Assignment and Move Assignment |
| == | Equality |
| \> | Greater than |
| \>= | Greater than or equal to |
| \>> | Right shift |
| \>>= | Right shift/assignment |
| ^ | Exclusive OR |
| ^= | Exclusive OR/assignment |
| | | Bitwise inclusive OR |
| |= | Bitwise inclusive OR/assignment |
| || | Logical OR |
| [] | Subscript operator |


For example, cartesian vectors are sets of two coordinates: x and y. The addition operation of two cartesian vectors is defined as the addition both x coordinates together, and both y coordinates together. For example, adding the cartesian vectors (3,1) and (1,2) together would result in (3+1,1+2) = (4,3). This could be implemented in C++ with the following code:

  // overloading operators example
  #include <iostream>
  using namespace std;

  class CVector {
    public:
      int x,y;
      CVector () {};
      CVector (int a,int b) : x(a), y(b) {}
      CVector operator + (const CVector&);
  };

  CVector CVector::operator+ (const CVector& param) {
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
  }

  int main () {
    CVector foo (3,1);
    CVector bar (1,2);
    CVector result;
    result = foo + bar;
    cout << result.x << ',' << result.y << '\n';
    return 0;
  }


If confused about so many appearances of CVector, consider that some of them refer to the class name (i.e., the type) CVector and some others are functions with that name (i.e., constructors, which must have the same name as the class). For example:

  CVector (int, int) : x(a), y(b) {}  // function name CVector (constructor)
  CVector operator+ (const CVector&); // function that returns a CVector  

The function operator+ of class CVector overloads the addition operator (+) for that type. Once declared, this function can be called either implicitly using the operator, or explicitly using its functional name:

  c = a + b;
  c = a.operator+ (b);

Both expressions are equivalent.

The operator overloads are just regular functions which can have any behavior; there is actually no requirement that the operation performed by that overload bears a relation to the mathematical or usual meaning of the operator, although it is strongly recommended. For example, a class that overloads operator+ to actually subtract or that overloads operator== to fill the object with zeros, is perfectly valid, although using such a class could be challenging.

The parameter expected for a member function overload for operations such as operator+ is naturally the operand to the right hand side of the operator. This is common to all binary operators (those with an operand to its left and one operand to its right). But operators can come in diverse forms. Here you have a table with a summary of the parameters needed for each of the different operators than can be overloaded (please, replace @ by the operator in each case):

| Expression | Operator | Member function | Non-member function |
|------------|----------|-----------------|---------------------|
| @a | + - * & ! ~ ++ -- | A::operator@() | operator@(A) |
| a@ | ++ -- | A::operator@(int) | operator@(A,int) |
| a@b | + - * / % ^ & | < > == != <= >= << >> && || , | A::operator@(B) | operator@(A,B) |
| a@b | = += -= *= /= %= ^= &= |= <<= >>= [] | A::operator@(B) | - |
| a(b,c...) | () | A::operator()(B,C...) | - |
| a->b | -> | A::operator->() | - |
| (TYPE) a | TYPE | A::operator TYPE() | - |

Where a is an object of class A, b is an object of class B and c is an object of class C. TYPE is just any type (that operators overloads the conversion to type TYPE).

Notice that some operators may be overloaded in two forms: either as a member function or as a non-member function: The first case has been used in the example above for operator+. But some operators can also be overloaded as non-member functions; In this case, the operator function takes an object of the proper class as first argument.

  // non-member operator overloads
  #include <iostream>
  using namespace std;

  class CVector {
    public:
      int x,y;
      CVector () {}
      CVector (int a, int b) : x(a), y(b) {}
  };


  CVector operator+ (const CVector& lhs, const CVector& rhs) {
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
  }

  int main () {
    CVector foo (3,1);
    CVector bar (1,2);
    CVector result;
    result = foo + bar;
    cout << result.x << ',' << result.y << '\n';
    return 0;
  }

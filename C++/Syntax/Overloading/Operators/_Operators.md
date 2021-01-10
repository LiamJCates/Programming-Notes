### Operator Overloading
For each fundamental type, some portion of the operators will be available.

Classes, essentially, define new types to be used in C++ code. Types in C++ not only interact with code by means of constructions and assignments, they also interact by means of operators.

For user-defined types, you can specify custom behavior for these operators by employing operator overloading. You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

An operator declaration looks quite like a function declaration:

  return_type operator operator_symbol (...parameter list...);

where operator_symbol in this case could be any of the several operator types that the programmer can define.


When overloading an operator, keep the following in mind:
  You cannot change the precedence or associativity of an operator.
  You cannot specify default parameters with an overloaded operator.
  You cannot change the number of parameters an operator takes.
  You cannot create new operators.
  The meaning of how an operator works with built-in types, such as int, remains the same. That is, you cannot redefine how operators work with built-in data types.
  Operators can be overloaded either for objects of the user-defined types, or for a combination of objects of the user-defined type and objects of the built-in type.


Overloadable/Non-overloadable Operators

Following is the list of operators which can be overloaded −
\+ 	- 	* 	/ 	% 	^
& 	| 	~ 	! 	, 	=
< 	> 	<= 	>= 	++ 	--
<< 	>> 	== 	!= 	&& 	||
+= 	-= 	/= 	%= 	^= 	&=
|= 	*= 	<<= 	>>= 	[] 	()
-> 	->* 	new 	new [] 	delete 	delete []

Following is the list of operators, which can not be overloaded −
:: 	.* 	. 	?:

On a broad level, operators in C++ can be classified into two types:
  unary
  binary

Unary Operators
operators that function on a single operand are called unary operators. A unary operator that is implemented in the global namespace or as a static member function of a class uses the following structure:

  return_type operator operator_type (parameter_type)
  {
    //implementation
  }

A unary operator that is a (non-static) member of a class has a similar structure but is lacking in parameters, because the single parameter that it works upon is the instance of the class itself (*this):

  return_type operator operator_type ()
  {
  // ... implementation
  }

Unary Operators

| Symbol | Name |
|--------|------|
| ++ | Increment |
| -- | Decrement |
| * | Pointer dereference |
| -> | Member selection |
| ! | Logical NOT |
| & | Address-of |
| ~ | One’s complement |
| + | Unary plus |
| - | Unary negation |



Example
A unary prefix increment operator (++) can be programmed using the following syntax within the class declaration:

  // Unary increment operator (prefix)
  Date& operator ++ ()
  {
    // operator implementation code
    return *this;
  }

The postfix increment operator (++), on the other hand, has a different return type and an input parameter (that is not always used):

  Date operator ++ (int)
  {
    // Store a copy of the current object state before incrementing day
    Date copy (*this);
    // increment implementation code
    // Return state before increment (because, postfix)
    return copy;
  }


The prefix and postfix decrement operators have a similar syntax as the increment operators, just that the declaration would contain a -- where you see a ++.

As the implementation of the postfix operators demonstrates, a copy containing the existing state of the object is created before the increment or decrement operation to be returned thereafter. In other words, if you had the choice between using ++ object; and object ++; to essentially only increment, you should choose the former to avoid the creation of a temporary copy that will not be used.






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



Operator Overloading Examples

Here are various operator overloading examples to help you in understanding the concept.

Unary Operators Overloading
https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm

Binary Operators Overloading
https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm

Relational Operators Overloading
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm

Input/Output Operators Overloading
https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm

++ and -- Operators Overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm

Assignment/Copy Operators Overloading
https://www.tutorialspoint.com/cplusplus/assignment_operators_overloading.htm

Function call () Operator Overloading
https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm

Subscripting [] Operator Overloading
https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm

Class Member Access Operator -> Overloading
https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm

C++ Overloading (Operator and Function)

C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).

When you call an overloaded function or operator, the compiler determines the most appropriate definition to use, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload resolution.





## Function Overloading in C++

You can have multiple definitions for the same function name in the same scope. The definition of the function must differ from each other by the types and/or the number of arguments in the argument list. You cannot overload function declarations that differ only by return type.

Following is the example where same function print() is being used to print different data types −
Live Demo

#include <iostream>
using namespace std;

class printData {
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }
      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }
      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void) {
   printData pd;

   // Call print to print integer
   pd.print(5);

   // Call print to print float
   pd.print(500.263);

   // Call print to print character
   pd.print("Hello C++");

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Printing int: 5
Printing float: 500.263
Printing character: Hello C++






## Operators Overloading in C++

You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

An operator declaration looks quite like a
function declaration:
return_type operator operator_symbol (...parameter list...);

The operator_symbol in this case could be any of the several operator types that the
programmer can define. It could be + (addition) or && (logical AND) and so on.


Overloadable/Non-overloadable Operators

Following is the list of operators which can be overloaded −
+ 	- 	* 	/ 	% 	^
& 	| 	~ 	! 	, 	=
< 	> 	<= 	>= 	++ 	--
<< 	>> 	== 	!= 	&& 	||
+= 	-= 	/= 	%= 	^= 	&=
|= 	*= 	<<= 	>>= 	[] 	()
-> 	->* 	new 	new [] 	delete 	delete []

Following is the list of operators, which can not be overloaded −
:: 	.* 	. 	?:



On a broad level, operators in C++ can be classified into two types: unary operators and
binary operators.

Unary Operators
operators that function on a single operand are called unary
operators. A unary operator that is implemented in the global namespace or as a static
member function of a class uses the following structure:
return_type operator operator_type (parameter_type)
{
// ... implementation
}
A unary operator that is a (non-static) member of a class has a similar structure but is
lacking in parameters, because the single parameter that it works upon is the instance of
the class itself (*this):
return_type operator operator_type ()
{
// ... implementation
}

Unary Operators
++ Increment
-- Decrement
* Pointer dereference
-> Member selection
! Logical NOT
& Address-of
~ One’s complement
+ Unary plus
- Unary negation
Conversion operators Conversion into other types


Example
A unary prefix increment operator (++) can be programmed using the following syntax
within the class declaration:
// Unary increment operator (prefix)
Date& operator ++ ()
{
// operator implementation code
return *this;
}

The postfix increment operator (++), on the other hand, has a different return type and an
input parameter (that is not always used):
Date operator ++ (int)
{
// Store a copy of the current state of the object, before incrementing day
Date copy (*this);
// increment implementation code
// Return state before increment (because, postfix)
return copy;
}


The prefix and postfix decrement operators have a similar syntax as the increment
operators, just that the declaration would contain a -- where you see a ++.

As the implementation of the postfix operators demonstrates, a
copy containing the existing state of the object is created before
the increment or decrement operation to be returned thereafter.
In other words, if you had the choice between using ++ object;
and object ++; to essentially only increment, you should
choose the former to avoid the creation of a temporary copy that
will not be used.


Programming Conversion Operators

Date holiday (12, 25, 2016); // instantiate
cout << holiday; // error in absence of conversion operator
The code would result in the following compile failure: error: binary '<<' : no
operator found which takes a right-hand operand of type 'Date'
(or there is no acceptable conversion). This error essentially indicates that
cout doesn’t know how to interpret an instance of Date as class Date does not support the operators that convert its contents into a type that cout would accept.
We know that cout can work well with a const char*:
std::cout << "Hello world"; // const char* works!
So, getting cout to work with an instance of type Date might be as simple as adding an
operator that returns a const char* version:
operator const char*()
{
// operator implementation that returns a char*
}

Note that such assignments cause implicit conversions, that is,
the compiler has used the available conversion operator (in this
case const char*) thereby permitting unintended assignments
that get compiled without error. To avoid implicit conversions, use
keyword explicit at the beginning of an operator declaration,
as follows:
explicit operator const char*()
{
// conversion code here
}
Using explicit would force the programmer to assert his
intention to convert using a cast:
string strHoliday(static_cast<const char*>(Holiday));
strHoliday=static_cast<const char*>(Date(11,11,2016));

rogram as many operators as you think your class would be
used with. If your application needs an integer representation of
a Date, then you may program it as follows:
explicit operator int()
{
return day + month + year;
}
This would allow an instance of Date to be used or transacted
as an integer:
FuncTakesInt(static_cast<int>(Date(12, 25, 2016)));



Binary Operators
Operators that function on two operands are called binary operators. The definition of
a binary operator implemented as a global function or a static member function is the
following:
return_type operator_type (parameter1, parameter2);
The definition of a binary operator implemented as a class member is
return_type operator_type (parameter);
The reason the class member version of a binary operator accepts only one parameter is
that the second parameter is usually derived from the attributes of the class itself.


Overloadable Binary Operators

  , Comma
  != Inequality
  % Modulus
  %= Modulus/assignment
  & Bitwise AND
  && Logical AND
  &= Bitwise AND/assignment
  * Multiplication
  *= Multiplication/assignment
  + Addition
  += Addition/assignment
  - Subtraction
  -= Subtraction/assignment
  ->* Pointer-to-member selection
  / Division
  /= Division/assignment
  < Less than
  << Left shift
  <<= Left shift/assignment
  <= Less than or equal to
  = Assignment, Copy Assignment and Move
  Assignment
  == Equality
  > Greater than
  >= Greater than or equal to
  >> Right shift
  >>= Right shift/assignment
  ^ Exclusive OR
  ^= Exclusive OR/assignment
  | Bitwise inclusive OR
  |= Bitwise inclusive OR/assignment
  || Logical OR
  [] Subscript operator


## Programming Binary Addition (a+b) and Subtraction (a-b) Operators
Similar to the increment/decrement operators, the binary plus and minus, when defined,
enable you to add or subtract the value of a supported data type from an object of the
class that implements these operators.



Box operator+(const Box&);

declares the addition operator that can be used to add two Box objects and returns a Box object. Most overloaded operators may be defined as ordinary non-member functions or as class member functions. In case we define above function as non-member function of a class then we would have to pass two arguments for each operand as follows −

Box operator+(const Box&, const Box&);

Following is the example to show the concept of operator over loading using a member function. Here an object is passed as an argument whose properties will be accessed using this object, the object which will call this operator can be accessed using this operator as explained below −
Live Demo

#include <iostream>
using namespace std;

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }

      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here

   // box 1 specification
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);

   // box 2 specification
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);

   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}

When the above code is compiled and executed, it produces the following result −

Volume of Box1 : 210
Volume of Box2 : 1560
Volume of Box3 : 5400


Operator Overloading Examples

Here are various operator overloading examples to help you in understanding the concept.
Sr.No 	Operators & Example
1 	Unary Operators Overloading
https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm
2 	Binary Operators Overloading
https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm
3 	Relational Operators Overloading
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm
4 	Input/Output Operators Overloading
https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
5 	++ and -- Operators Overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm
6 	Assignment/Copy Operators Overloading
https://www.tutorialspoint.com/cplusplus/assignment_operators_overloading.htm
7 	Function call () Operator Overloading
https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm
8 	Subscripting [] Operator Overloading
https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
9 	Class Member Access Operator -> Overloading
https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm



Casting Operators
Casting is a mechanism by which the programmer can temporarily or
permanently change the interpretation of an object by the compiler.
Note that this does not imply that the programmer changes the object
itself—he simply changes the interpretation thereof. Operators that
change the interpretation of an object are called casting operators.

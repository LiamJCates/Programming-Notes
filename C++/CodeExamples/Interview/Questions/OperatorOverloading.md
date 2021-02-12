Operator overloading is the art of adding new, useful and creative functionalities to operators. It is a part of ‘Polymorphism’. This chapter travels all across overloading operators and will make you strong enough to face them.




1. Identify the characteristics of overloading and overriding.

(a) Overloaded entities are bound during compile time and overriding during runtime.
(b) Overloaded entities are bound during runtime and overriding during compile time.
(c) Both exhibit the same characteristics.
(d) None of the above.

Answer: (a)



2. Using what kind of functions, we can overload operators in C++
(a) Member functions which are non-static
(b) Friend functions
(c) Member functions which are static
(d) a and b
(e) b and c
(f) a and c

Answer: (f) a and c



3. Say True or False – by overloading operator, the original purpose is lost.

Answer: (b) False



4. Choose the operators which cannot be overloaded in C++
(a) .
(b) .*
(c) ?:
(d) All of the above

Answer: All of the above. In addition to the above operators, we cannot
overload ::, #, ##, sizeof in C++



5. Which of the following points are true about operator overloading in C++?

(a) We can’t have the default arguments while overloading operators
(b) Operators doesn’t follow
(c) Both bitwise operator & and Address of operator & take same
number of operands
(d) Operator overloading is performed using functions.
(e) a,b,c
(f) a,d
(g) d only
Answer: (f) a, d



6. True or False: native return types are not mandatory while overloading unary operators.
(a) True
(b) False
Answer: True



7. Predict the output of the following program.

	#include <iostream>
	using namespace std;
	class Inc
	{
	private:
	    int num;

	public:
	    Inc(int b) { num = b; }
	    int operator++() { return num += 1; }
	};

	int main()
	{
	    Inc t(10);
	    cout << ++t;
	    return 0;
	}

(a) Error, since we cannot use ++ over an instance of a class
(b) Prints 11
(c) Prints a junk value
(d) None of the above

Answer: (b) Prints 11



8. By default, the compiler overloads an operator. Choose the operator.
(a) =
(b) *
(c) ?:
(d) ==

Answer: (a) Assignment operator is able to handle values and variables of
any type. This is able through overloading.



9. What is the following technique called, to assign one object to another of
same type?
int main()
{
	Inc t(10), t1(0);
	std::cout << ++t << endl9;
	t1=t;
	std::cout<<++t1;
	return 0;
}

(a) Copy constructor
(b) Overload constructor
(c) Copy operator
(d) Overload operator

Answer: (a) Copy constructor



10. Identify the statements that are true regarding operator functions.

(a) They are similar to member functions, except the fact that, they have the keyword operator and the to-be overloaded symbol
(b) The return type can be void
(c) It can either return by value or return by reference
(d) All the above

Answer: (d) All the above



11. Predict the output of the following code.

#include <iostream>
using namespace std;
class Inc
{
private:
    int num;

public:
    Inc(int b) { num = b; }
    int operator++() { return num += 1; }
};

int main()
{
	Inc t(10),t1(0);
	cout<<++t<<"\t";
	t1=t;
	cout<<++t1;
	return 0;
}
(a) Since the operator= is not overloaded, it is illegal to assign t1=t. it
throws error
(b) 11 12
(c) 11 1
(d) 11 2
Answer: (b) t gets 10 initially and is pre-incremented to 11. Then t1 gets t, which is already 11. So one further pre-increment of t gives 12.



12. How to differentiate postfix and prefix operator overloads?

(a) We aren’t allowed to overload both the operators in the same class
(b) We will overload postfix operator as a global function
(c) We will overload prefix operator as a global function
(d) We will pass a dummy value to the postfix operator overload function

Answer: (d) We will pass a dummy value to the postfix operator overload
function



13. Identify issue with the following code.

	#include <iostream>
	using namespace std;
	class Negation
	{
	    int param1;

	public:
	    Negation(){}
	    Negation(int paramPassed) { param1 = paramPassed;}

			int operator+(Negation obj) { return param1 + obj.param1; }

			int operator+(int obj) { return param1 + obj; }
	};

	int main()
	{
	    Negation obj1(100), obj2(200);
	    cout <<"add 2 obj-->"<< obj1 + obj2 << endl;
	    cout <<"add a scalar number with obj-->"<< obj1 + 200 << endl;
	}

(a) We can’t overload the same operator multiple times
(b) no issue, give output as add 2 obj-->300 add a scalar number with obj-->300
(c) no issue, give output as add 2 obj-->300 add a scalar number with obj-->100
(d) none of the above

Answer: (b) It works normally as expected.



14. Identify the output of the following program.

	#include <iostream>
	using namespace std;
	class Negation
	{
			int param1;

	public:
			Negation() {}
			Negation(int paramPassed) { param1 = paramPassed; }
			int operator+(Negation obj) { return param1 + obj.param1; }
			int operator+(int obj) { return param1 + obj; }
	};

	int main()
	{
			Negation obj1(100), obj2(200);
			cout <<"add 2 obj-- >"<< obj1 + obj2 << endl;
			cout <<"add a scalar number with obj-- >"<< 200 + obj1 << endl;
	}

(a) add 2 obj-->300 add a scalar number with obj-->300
(b) add 2 obj-->300 add a scalar number with obj-->200
(c) compile error, no match for operator+ with operands int and Negation
(d) no error, no output

Answer: (c) the first operator is integer which is not allowed by the method signature.



15. Identify the output of the following program.

#include <iostream>
using namespace std;
class Negation
{
public:
    int param1;
    Negation()
    {
    }
    Negation(int paramPassed)
    {
        param1 = paramPassed;
    }
    int operator+(Negation obj)
    {
        return param1 + obj.param1;
    }
    friend void operator+(int obj, Negation obj2);
};

void operator+(int obj, Negation obj2)
{
    cout << obj + obj2.param1;
}

int main()
{
    Negation obj1(100), obj2(200);
    cout << "add 2 obj-->" << obj1 + obj2 << endl;
    cout << "add a scalar number with obj-->";
    200 + obj1;
}

(a) Compile error, since first operand cannot be integer
(b) Program throws exception and terminates
(c) add 2 obj-->300
add a scalar number with obj-->300
(d) add 2 obj-->300
add a scalar number with obj-->200

Answer: (c) Using friend functions, we can pass a scalar variable as the first parameter to the overloaded method.



16. Which of the following operators cannot be overloaded by friend
functions?
(a) ()
(b) []
(c) Only a
(d) Both a and b
Answer: (d) Both a and b



17. How many parameters we need to pass when we overload a binary
operator using friend function?
(a) 1
(b) 2
(c) 3
(d) 0
Answer: (b)



18. How many parameters we need to pass when we overload a unary
operator using friend function?
(a) 1
(b) 2
(c) 3
(d) 0
Answer: (a) 1



19. Which of the following operators, when overloaded, are not inherited by the child class?
(a) *
(b) =
(c) ++
(d) –
Answer: (b) =



20. Can we pass a scalar variable value to an overloaded member function
as the first parameter?
(a) Yes
(b) No
Answer: (b) No



21. Identify the properties of a binary operator overload.
(a) When overloaded as a member function, it takes one parameter
(b) When overloaded as a global function, it takes two parameters
(c) One of the parameters should be of type class
(d) All of the above
Answer: (d) All of the above



22. Predict the output of the following code..

	#include <iostream>
	using namespace std;

	class TestAssignment
	{
	public:
	    TestAssignment &operator=(TestAssignment &);
	    int param1, param2;
	};
	TestAssignment &TestAssignment::operator=(TestAssignment &ptRHS)
	{
	    param1 = ptRHS.param1;
	    param2 = ptRHS.param2;
	    return *this;
	}
	int main()
	{
	    TestAssignment p1, p2, p3;
	    p3.param1 = 100;
	    p3.param2 = 100;
	    p1 = p2 = p3;
	    cout << "P1 Values=" << p1.param1 << "," << p1.param2 << endl;
	    cout << "P2 Values=" << p2.param1 << "," << p2.param2 << endl;
	    cout << "P3 Values=" << p3.param1 << "," << p3.param2 << endl;
	}

(a) P1 Values=100,100
P2 Values=100,100
P3 Values=100,100
(b) Error, to use p1=p2=p3
(c) Program terminates
(d) Junk values

Answer: (a) First P3 is assigned to P2. And then P2 is assigned to P1.



23. Say Yes or No – can we overload function call operator ()?
(a) Yes
(b) No
Answer: (a) Yes



24. Identify the output of the following code..

	#include <iostream>
	using namespace std;
	typedef void (*ptrtofunc)();
	void Wish()
	{
	    cout << "Hi from function called using overloaded ()";
	}
	struct testFnCallOverload
	{
	    operator ptrtofunc()
	    {
	        return Wish;
	    }
	};

	int main()
	{
	    testFnCallOverload obj;
	    obj();
	}

(a) Compile error as call to function obj() is wrong
(b) Hi from function called using overloaded ()
(c) Unexpected behavior
(d) None of the above

Answer: (b) We have overloaded the function call operator with the help of
function pointer.



25. Say True or False: function call operator is treated as a binary operator
when we overload it.
(a) True
(b) False
Answer: (a) True



26. Identify the output of the following code..

	#include <iostream>
	using namespace std;
	class Test
	{
	    int var = 100;

	public:
	    operator int()
	    {
	        return var;
	    }
	};
	void TestFun(int var)
	{
	    cout << "Function with integer parameter called";
	    cout << endl << var;
	}
	int main()
	{
	    Test obj;
	    TestFun(obj);
	    return 0;
	}

(a) TestFun(obj) throws error as there is no appropriate function definition
(b) Function with integer parameter called
100
(c) Function with integer parameter called
Junk value
(d) None of the above

Answer: (b) Here operator int () overloads the type cast operator.



27. Say Yes or No: Can we change the behavior of ++ operator so that it
subtracts one value from the given value using operator overloading?
(a) Yes
(b) No
Answer: (a) Yes. But it is not a good practice.



28. What does the following code signify?
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class newOperatorExampple
{
private:
    void *operator new(size_t size) {}
    void *operator new[](size_t size) {}
};

int main()
{
    newOperatorExampple *obj = new newOperatorExampple;
    newOperatorExampple *arr = new newOperatorExampple[10];
    return 0;
}

(a) It lets the class allocate memory as needed
(b) It throws error during compile time
(c) It prevents the user from instantiating newOperatorExampple class
(d) a and b
(e) a and c
(f) b and c
Answer: (f) b and c



29. Say Yes or No. can we overload a destructor?
(a) Yes’
(b) No
Answer: (b) No, there can only be one destructor in a class.



30. Among the following operators, which will throw error when we declare the operator function with global scope?
(a) +=
(b) -=
(c) ()
(d) None of the above

Answer: (c) () The left operand is actually the calling object, so the operand
must be of object type.



31. While we are about to overload a binary operator, what point should be
kept in mind among the following?

(a) All the operands should be an object
(b) Operand in RHS must be of type object
(c) Operand in LHS must be of type object
(d) All of these should be considered.

Answer: (c) Operand in LHS must be of type object. The left operand is actually the calling object, so the must be of object type.



32. True/False: We can overload any new (apart from built-in ones) operator in C++.

Answer: (b) False. We can only overload built-in operators.



33. True/False : When we overload unary operator +, we need to overload – too.

Answer: (b) False



34. Predict the output of the following program.

	#include <iostream>
	using namespace std;
	class Inc
	{
	private:
	    int num;

	public:
	    Inc(int b)
	    {
	        num = b;
	    }
	    int operator++()
	    {
	        return num = num + 1;
	    }
	};
	int main()
	{
	    Inc t(10);
	    cout << ++t++;
	    return 0;
	}

(a) Prints 12
(b) Prints 11
(c) Prints junk value
(d) Compile error
Answer: (d) Because, we have not overloaded the postfix operator.



35. True / False
It is not allowed to overload assignment operator since copy constructor is already there by default.

Answer: False
We can overload the assignment operator even though it is done by default.



36. Predict the output of the following..

	#include <iostream>
	using namespace std;
	class Inc
	{
	private:
	    int num;

	public:
	    Inc(int b)
	    {
	        num = b;
	    }
	    int operator++()
	    {
	        return num = num + 1;
	    }
	    bool operator==(Inc op1)
	    {
	        return op1.num == this->num;
	    }
	};
	int main()
	{
	    Inc t1(10), t2(0);
	    t2 = t1;
	    if (t1 == t2)
	        cout << "Both objects are same";
	    else
	        cout << "Both objects are not same";
	    return 0;
	}

(a) Error since there is no definition for !=
(b) Prints both objects are same
(c) Prints both objects are not same
(d) None of the above

Answer: (b) This is a way of overloading relational operators.



37. True/False: You can use == operator to compare two strings?

Answer: False, because, when we overload a binary operator, at least one of the operands should be of type class or any other user defined type.



38. Predict the output of the following code..

#include <iostream>
using namespace std;
class Inc
{
private:
    int num;

public:
    Inc(int b)
    {
        num = b;
    }
    int operator++()
    {
        return num = num + 1;
    }
    bool operator!=(Inc op1)
    {
        return op1.num != this->num;
    }
};

int main()
{
    Inc t1(10), t2(0);
    if (t1 != t2)
        cout << "Both objects are not same";
    return 0;
}

(a) Prints Both objects are not same
(b) Prints nothing
(c) Error
(d) None of the above
Answer: (a) Prints Both objects are not same.



39. True/False. When we declare an overload function for ==, compiler automatically inserts one function for !=

Answer: (b) False



40. Identify the output of the following code..

#include <iostream>
using namespace std;
class IntArray
{
private:
    int privateArray[10];

public:
    int &operator[](const int index);
};
int &IntArray::operator[](const int index)
{
    return privateArray[index];
}
int main()
{
    IntArray array;
    array[1] = 100;        // set a value
    std::cout << array[1]; // get a value
    return 0;
}

(a) Error as the array is privately scoped in class
(b) Prints 100
(c) Prints junk
(d) Program hangs

Answer: (b) Prints 100, the program overloads the subscript operator to assign value to the privately scoped array and to get the set value

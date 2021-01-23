1. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		int b;
	};

	class dev : public base
	{};

	int main()
	{
		dev S;
		S.b = 9;
		cout << S.b;
	}

Answer: 9

Here class 'dev' inherits class 'base' functionalities in 'public' mode. The colon is the operator for inheritance. 'public' mode of inheritance means all the 'public' members of base class become 'public' members of derived class and 'protected' members of base class become 'protected' members of derived class. This is simple inheritance.



2. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		protected:
		int b;
	};

	class dev : public base
	{};

	int main()
	{
		dev S;
		S.b = 9;
		cout << S.b;
	}

Answer: error

'protected' members of base class will be inherited as 'protected' members of derived class in 'public' inheritance. 'protected' members cannot be directly accessed by an object.



3. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		protected:
		int b;
	};

	class dev : public base
	{
		public:
		void play()
		{
			b = 4;
			cout <<b;
		}
	}S;

	int main() {
		S.play();
	}

Answer: 4

In public inheritance, 'protected' members can be called by 'public' members.



4. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev : public base
	{}D;

	int main()
	{
		D.b = 5;
		cout << S.b;
	}

Answer: 0

Initializing inherited members doesn't have any effect on base class members.



5. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev : public base
	{
		public:
		int b;
	}D;

	int main(){
		D.b = 5;
		D.base::b = 9;
		cout << D.b << " " << D.base::b;
	}

Answer: 5 9

Here 'D.b' refers to the variable declared in 'dev'. To access the inherited variable the base class name is used with '::'.



6. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev : public base
	{
	  public:
			int b;
			void fun()
			{
				((base *) this)->b = 2;
				cout << b << " " << ((base *) this)->b;
			}
	}D;

	int main()
	{
		D.b = 5;
		D.fun();
	}

Answer: 5 2

'this' operator is another way of accessing the inherited variable.



7. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		int b;
	}S;

	class dev : public base
	{
		public:
		int b;
	}D;

	int main()
	{
		D.b = 5;
		D.((base *) this)->b = 2;
		cout << b<< " " << D.((base *) this)->b;
	}

Answer: error
Invalid use of 'this' operator.



8. What will be the error thrown by the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev : public base
	{
		public:
		int b;
	}D;

	int main()
	{
		D.b = 5;
		D.((base *) this)->b = 2;
		cout << b<< " " << D.((base *) this)->b;
	}

Answer:
Expected unqualified-id before '(' token in D.((base *) this)->b = 2;
Invalid use of 'this' in 'main()'

'this' can be used only inside a member function. So outside the class member functions, to access the inherited variable 'base class ::' should be used.



9. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev :: public base
	{}D;

	int main()
	{
		D.b = 8;
		cout << D.b;
	}

Answer: Syntax error

'::' cannot be used for inheritance. It is used for defining functions and static variables declared inside the class.




11. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
		public:
		  int b;
	}S;

	class dev
	: public base
	{}D;

	int main()
	{
		D.b = 8;
		cout << D.b;
	}

Answer: 8

Even though the inherited part is given in a new line, it is treated as continuous lines as the previous line doesn't meet an expected end or '{' for its block.




12. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	class dev : public base
	{}D;

	int dev::b = 3;

	int main() { cout << dev::b; }

Answer: error
error: ISO C++ does not permit ‘base::b’ to be defined as ‘dev::b’ [-fpermissive]
'static' variables will not be inherited as 'static'.




14. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base{
	  public:
		static int b;
	};

	class dev : public base
	{}D;

	int main()
	{
		D.b = 9;
		cout << D.b;
	}

Answer: error

'static' variables will not be inherited at all.




15. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	class dev : public base
	{}D;

	int main()
	{
		D.b = 9;
		cout << D.b;
	}

Answer:  undefined reference to 'base::b'

The compiler knows that 'D.b' is access of the static variable of 'base'.




16. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	class dev : public base
	{}D;

	D.base::b = 3;

	int main()
	{
		cout << D.base::b;
	}

Answer: error
error: ‘D’ does not name a type

This is not an appropriate initializing of base class static variable.




18. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	int base::b = 3;

	class dev : public base
	{
	  public:
		void fun()
		{
			cout << ((base *)this)->b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 3

The 'static' variable retains the same value irrespective of the class from which it is called from.




19. How many copies of 'b' will be created while executing the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	int base::b = 3;

	class dev : public base
	{
	  public:
		void fun()
		{
			cout << ((base *)this)->b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 1

'static' members will not be inherited. It is created only once for the base class. It is accessed from the derived class. The derived class doesn't have a copy of the variable for its own.




20. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	class dev : public base
	{
	  public:
		void fun()
		{
		cout << ((base *)this)->b;
		}
	}D;

	int dev::base::b = 3;

	int main()
	{
		D.fun();
	}

Answer: 3

Even this is right. The '::' is used to represent the full inheritance hierarchy.




21. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	protected:
		int a;
	public:
		int b;
	};

	class dev : protected base
	{
	  public:
		void fun()
		{
			a=1;
			b=4;
			cout << a << " " << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 1 4

In 'protected' mode of inheritance, the 'public' and 'protected' members of base class is inherited as 'protected' members of derived class.




22. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	protected:
		int a;
	public:
		int b;
	};

	class dev : protected base
	{
	  public:
		void fun()
		{
		a=1;
		cout << a << " " << b;
		}
	}D;

	int main()
	{
		D.b = 3;
		D.fun();
	}

Answer: error
error: ‘int base::b’ is inaccessible within this context
In 'dev' 'b' is a protected member. It cannot be accessed by an object.




24. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	protected:
		int a;
		static int b;
	};

	int base::b = 1;

	class dev : protected base
	{
	  public:
		void fun()
		{
			a=1;
			cout << a << " " << dev::b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 1 1
'static' variables also behave in the same way as expected.




25. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	protected:
		int a;
		static int b;
	};

	int base::b = 1;

	class dev : protected base
	{
	protected:
		int b;
	public:
		int b;
		void fun()
		{
		a=1;
		base::b = 2;
		cout << a << " "<< b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
error: redeclaration of ‘int dev::b’
A class cannot have two members with same name in different access blocks.




27. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	protected:
		int a,b;
	};

	class dev : protected base
	{
	public:
		int b;
		void fun()
		{
			a=1;
			base::b = 2;
			cout << a << " "<< b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 1 0

Here 'b' is uninitiated. Only the inherited variable is initialized — result is 1 0.




29. What is the output of the code?

#include <iostream>
using namespace std;

class base
{
	int b;
};

class dev : protected base
{
  public:
	void fun()
	{
		b = 2;
		cout<< b;
	}
}D;

int main()
{
	D.fun();
}

Answer: error
error: 'int base::b' is private
'b' is a private member of class 'base' so will not be inherited.
The compiler knows 'b' is a 'private' variable of base class.
As 'dev' is inherited from 'base' class it knows the variable is in 'private'
of 'base'.




31. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		int b;
	};

	class dev : private base
	{
	  public:
		void fun()
		{
			b = 2;
			cout<< b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 2

'private' mode of inheritance makes both 'public' and 'protected' members of base class into 'private' members of derived class.
So it is accessible from a function.




32. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev : private base
	{}D;

	int main()
	{
		D.b = 2;
		cout << D.b;
	}

Answer: error
'int base::b' is inaccessible
As said above, 'b' will be inherited as 'private' variable.




35. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int b;
	};

	class dev : private base
	{}D;

	int dev::base::b = 4;

	int main()
	{
		cout << dev::base::b;
	}

Answer: error
error: ‘class base base::base’ is inaccessible within this context
This is not an appropriate usage of static variable.




36. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	class dev : private base
	{
	  public:
		void fun()
		{
			base::b = 3;
			cout << ((base *)this)->b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
undefined reference to 'base::b'
This is also not valid, 'private static' variable cannot be inherited or accessed.




38. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int b;
	};

	class dev : private base
	{
	  public:
		void fun()
		{
			b = 3;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error

Undefined reference to 'base::b'. This is because, static variable is not initialized. So the memory is not allocated.




39. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int b;
	};

	int base::b = 8;

	class dev : private base
	{
	  public:
		void fun()
		{
			b = 3;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 3
Now this works as expected.




40. What is the output of the code?

#include <iostream>
using namespace std;

class base
{
public:
	static int b;
};

int base::b = 8;

class dev : private base
{
public:
	int b;
	void fun()
	{
		base::b = 3;
		cout << base::b;
	}
}D;

int main()
{
	D.fun();
}

Answer: 3
This too works normally as explained above. Not the 'static' variable has been defined outside and so it is defined.




41. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int b;
	};

	int base::b = 8;

	class dev : private base
	{
	  public:
		int b;
		void fun()
		{
			base::b = 3;
		}
	}D;

	int main()
	{
		D.fun();
		cout << base::b;
	}

Answer: 8

'3' is initiated only within the context of 'D'. The original value is not changed.




42. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int b;
	};

	int base::b = 8;

	class dev : private base
	{
	  public:
		int b;
		void fun()
		{
			base::b = 3;
		}
	}D;

	int main()
	{
		D.fun();
		cout << dev::base::b;
	}

Answer: error
It throws "'class base base::base' is inaccessible". This is because static variables are not inherited.




43. What will be the error thrown by the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev private base
	{
	  public:
		void fun()
		{
			b = 2;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: Expected unqualified-id before 'private'
':' is very important in inheritance.




44. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	private:
		int v;
	public:
		int c;
	};

	class dev : public base
	{}D;

	int main()
	{
		D.b = 9;
		D.c = 8;
		cout << D.b << " " << D.c;
	}


Answer: 9 8
Even though two 'public' blocks have been defined, both the blocks are inherited.



45. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	protected:
		int c;
	};

	class dev : public, protected base
	{
	  public:
		void fun()
		{
			b = 9;
			c = 7;
			cout << b << " " << c;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
error: Expected class-name before ',' token in 'public, protected base'
A class cannot be inherited with multiple access modes.
The compiler knows that class-name is required in the location according to inheritance syntax.




47. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev : base
	{
	  public:
		void fun()
		{
			b = 9;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 9
The default mode of inheritance is private.




48. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		int b;
	};

	class dev : base
	{}D;

	int main()
	{
		D.b = 3;
		cout << D.b;
	}

Answer: error

When the access mode is not specified it is inherited in 'private' mode.




49. What is the output of the code?

	#include <iostream>
	using namespace std;

	class dev : public base
	{
	  public:
		int b;
		void fun()
		{
			b = 9;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
Undefined class cannot be specified in inheritance. Here 'base'is unknown to the compiler.




51. What is the output of the code?

	#include <iostream>
	using namespace std;

	typedef int base;

	class dev : public base
	{
	  public:
		int b;
		void fun()
		{
			b = 9;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
Even though 'base' is a defined type, it cannot be used as base class for inheritance. So it throws the same error.




56. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		void fun()
		{
			cout << "fun";
		}
	};

	class dev : public base
	{}D;

	int main()
	{
		D.fun();
	}

Answer: fun
functions are inherited.




57. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static void fun()
		{
			cout << "fun";
		}
	};

	class dev : public base
	{}D;

	int main()
	{
		D.fun();
	}

Answer: fun

Even static functions can be called like any normal functions.




58. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static void fun()
		{
		cout << "fun";
		}
	};

	class dev : public base
	{}D;

	int main()
	{
		dev::fun();
	}

Answer: fun

This call is also allowed unlike 'static' variables.



59. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static void fun()
		{
			cout << "fun1";
		}
	};

	class dev : public base
	{
	  public:
		static void fun()
		{
			cout << "fun2";
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: fun2

While there are two functions, derived class object calls the original function and not the inherited function.




60. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static void fun()
		{
		cout << "fun1";
		}
	};

	class dev : public base
	{
	  public:
		static void fun()
		{
			cout << "fun2";
		}
	}D;

	int main()
	{
		D.base::fun();
	}

Answer: fun1
The base class function can be called using the derived class object by using '::' operator.




61. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static void fun()
		{
			cout << "fun1";
		}
	};

	class dev : public base
	{
	  public:
		static void funcall()
		{
			((base *)this)->fun();
		}
	}D;

	int main()
	{
		D.funcall();
	}

Answer: fun1
'this' operator can also be used for calling the function.




62. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		int b;
	};

	class dev : public base , protected base
	{
	  public:
		void fun()
		{
			b = 8;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error

Same class cannot be inherited multiple times.




64. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class base : public base
	{
	  public:
		void fun()
		{
			b = 8;
			cout << b;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: error
A class can be defined only once.




66. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1
	{
	public:
		int c;
	};

	class dev2 : public base , public dev1
	{
		public:
		void fun()
		{
			b = 9;
			c = 2;
			cout << b << " " << c;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 9 2
A class can simultaneously inherit multiple classes. This is called multiple inheritance.




67. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1
	{
	public:
		int c;
	};

	class dev2 : public base , protected dev1
	{
		public:
		void fun()
		{
			b = 9;
			c = 2;
			cout << b << " " << c;
		}
	}D;

	int main()
	{
		D.fun();
	}

Answer: 9 2
A parent class can have any access mode and is unaffected by others.




69. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1
	{
	  public:
	int c;
	};

	class dev2 : public base , dev1
	{}D;

	int main()
	{
		D.b = 9;
		D.c = 2;
		cout << D.b << " " << D.c;
	}

Answer: error
The mode is not specified for the second class. So it is inherited in 'private' mode. Thus, member 'c' is 'private'. It is inaccessible.




75. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1
	{
	public:
		int c;
	};

	class dev2 : (public base , public dev1)
	{}D;

	int main()
	{
		D.b = 9;
		D.c = 2;
		cout << D.b << " " << D.c;
	}

Answer: error
Base class list cannot be specified inside '()'.




76. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1 : public base
	{
	public:
		int c;
	};

	class dev2 : public dev1
	{}D;

	int main()
	{
		D.b = 9;
		D.c = 2;
		cout << D.b << " " << D.c;
	}

Answer: 9 2
This type of inheritance is called multi-level inheritance. Here 'dev1' inherits 'base' and 'dev2' inherits 'dev1'. Thus, 'dev2' has members of both 'base' and 'dev1'.




77. What is the output of the code?

#include <iostream>
using namespace std;

class base
{
  public:
	static void fun()
	{
		cout<< "fun";
	}
};

class dev1 : public base
{};

class dev2 : public dev1
{}D;

int main()
{
	dev2::fun();
}

Answer: fun
'static' function is still 'static' after many inheritances.




78. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		static int fun;
	};

	class dev1 : public base
	{};

	class dev2 : public dev1
	{}D;

	int dev2::fun = 3;

	int main()
	{
		cout << dev2::fun;
	}

Answer: error
ISO forbids does not permit 'base::fun' to be defined as 'dev2::fun'
[-fpermissive]

'fun' is a static member of 'base' only.

'static' member is not 'static' after many inheritance. Its copy is also not created for every class.





80. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int fun;
	};

	class dev1 : public base
	{};

	class dev2 : public dev1
	{}D;

	int dev2::dev1::base::fun = 3;

	int main()
	{
	cout << dev2::dev1::base::fun;
	}

Answer: 3

Here the hierarchy specified is right, so works on the right way.



81. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int fun;
	};

	class dev1 : public base
	{};

	class dev2 : public dev1
	{}D;

	int dev2::base::fun = 3;

	int main()
	{
		cout << dev2::base:: fun;
	}

Answer: 3
This works normally, mainly because the 'static' member is defined in 'base' and that is right in the inheritance hierarchy.




82. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{};

	class dev1 : public base
	{
	public:
		static int fun;
	};

	class dev2 : public dev1
	{}D;

	int dev2::dev1::fun = 3;

	int main()
	{
		cout << dev2::dev1::fun;
	}

Answer: 3
This also works normally.




83. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{};

	class dev1 : public base
	{
	public:
		static int fun;
	};

	class dev2 : public dev1
	{}D;

	int dev2::base::fun = 3;

	int main()
	{
		cout << dev2::base::fun;
	}

Answer: error
'fun' is declared in 'dev1' only. So it cannot be accessed from 'base'.




84. What will be the error thrown by the code?

	#include <iostream>
	using namespace std;

	class base
	{};

	class dev1 : public base
	{
	public:
		static int fun;
	};

	class dev2 : public dev1
	{}D;

	int dev2::base::fun = 3;

	int main()
	{
		cout << dev2::base::fun;
	}

Answer:
'fun' is not a member of 'base'
'int base::fun' is not a static member of 'class base'




85. What is the output of the code?

	#include <iostream>
	using namespace std;

	class dev1 : public base
	{};

	class base
	{
	public:
		static int fun;
	};

	class dev2 : public dev1
	{}D;

	int dev2::base::fun = 3;

	int main()
	{
		cout << dev2::base::fun;
	}

Answer: error

Base class must be defined before the derived class. It throws the error "Expected class-name before '{' token".




86. What is the output of the code?
	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
	};

	class dev1 : public base
	{}S;

	class dev2 : public base
	{}D;

	int main()
	{
		S.b = 9;
		D.b = 3;
		cout << S.b<< " " << D.b;
	}

Answer: 9 3
This form of inheritance is called hierarchical inheritance.




87. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{};

	class dev1 : public base
	{
	public:
		int b;
	}S;

	class dev2 : public base
	{
	public:
		int fun;
	}D;

	int main()
	{
		S.b = 9;
		D.b = 3;
		cout << S.b<< " " << D.b;
	}

Answer: 9 3
Empty classes can also be inherited.




88. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		void fun()
		{
			cout << b<< " ";
		}
	};

	class dev1 : public base
	{
	public:
		int b;
	}S;

	class dev2 : public base
	{
	public:
		int b;
	}D;

	int main()
	{
		S.b = 9;
		D.b = 3;
		D.fun();
		S.fun();
	}

Answer: error
'b' was not declared in this scope
Undefined variables cannot be used in a function.





90. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:
		void fun()
		{
			cout<< "fun";
		}
	};

	class dev1 : public base
	{
	  public:
		int b;
		void fun()
		{
			cout << b<< " ";
		}
	}S;

	class dev2 : public base
	{
	  public:
	int b;
	}D;

	int main()
	{
		S.b = 9;
		D.b = 3;
		D.fun();
		S.fun();
	}

Answer: fun 9

In 'dev1' 'fun' is defined. So it accesses the local function. While in 'dev2' it is not defined, so calls the inherited function. But the definitions do not affect each other.




91. What is the output of the code?

#include <iostream>
using namespace std;

class base
{
  public:
	void fun()
	{
		cout<< "fun";
	}
};

class dev1 : public base
{
  public:
	void fun()
	{
		fun();
	}
}S;

class dev2 : public base
{}D;

int main()
{
	D.fun();
	S.fun();
}

Answer: seg fault

In 'dev1' call 'fun()' is a recursive call and doesn't call the
inherited function. On continuous recursion, the stack overflows and
segmentation fault occurs.




92. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		static int b;
		static void fun()
		{
			cout<< b;
		}
	};

	class dev1 : public base
	{}S;

	class dev2 : public base
	{}D;

	int main()
	{
		base::dev1::b = 9;
		base::dev2::b = 3;
		dev1::fun();
		dev2::fun();
	}

Answer: error
The hierarchy given is wrong; should be 'dev1::base' and 'dev2::base'.





94. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	  public:int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : public base
	{
	public:
		int b;
	}S;

	class dev2 : public base
	{}D;

	class dev3 : public base
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer:
It prints '0 2 5'. Here '3' in 'dev1' goes to its original member. But 'fun' in 'base' points to its member 'b'. So the inherited member 'b' of 'dev1' doesn't get value. Thus, it gets 0.




95. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : public base
	{
		int b;
	}S;

	class dev2 : public base
	{}D;

	class dev3 : public base
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: error

Here also 'S.b' points to the private member of 'dev1' and not the inherited variable. So it is not accessible and throws error.




96. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : public base
	{}S;

	class dev2 : public base{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: error

This type of inheritance is called hybrid or virtual inheritance. It is a combination of multilevel, hierarchical and multiple inheritance. Here, the public members of 'base' are copied twice to 'dev3' one copy from 'dev1' and another from 'dev3'. So it throws some errors.




97. Which of the following will be a part of the error thrown by the code?


	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
		cout<< b<< " ";
		}
	};

	class dev1 : public base
	{}S;

	class dev2 : public base
	{}D;

	class dev3 : public dev1, public dev2{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: Request for member 'b' is ambiguous.

Also it gives a note: "candidates are: int base::b". The same happens for 'base::fun()' also.




98. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : virtual public base
	{}S;

	class dev2 : virtual public base
	{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: 3 2 5
Adding 'virtual' to first level inheritance avoids this duplicating. Now in 'dev3' only one copy of 'base' members will be inherited.




99. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : public base
	{}S;

	class dev2 : virtual public base
	{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}


Answer: error

To avoid duplication, virtual must be specified in all duplication possible classes. Gives the same set of errors.



100. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : virtual public base
	{}S;

	class dev2 : virtual base
	{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: error

The inheritance will be in private mode, so 'D.base::b' is inaccessible.



101. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
		cout<< b<< " ";
		}
	};

	class dev1 : virtual public base
	{
	public:
		int b;
	}S;

	class dev2 : virtual public base
	{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: '0 3 0'.

When calling to variable, the compiler points to the variable that is closest in hierarchy. So in 'E.b' the value initialized is 'dev1::b' and not 'base::b'. So while 'base::fun()' is called 0 is printed and not 5.




102. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : public base
	{
	public:
		int b;
	}S;

	class dev2 : public base
	{}D;

	class dev3 : public dev1, public dev2
	{}E;

	int main()
	{
		S.b = 3;
		D.b = 2;
		E.b = 5;
		S.fun();
		D.fun();
		E.fun();
	}

Answer: error

Even though the preference is changed, while inheriting all the members will follow. So duplication occurs and errors will be thrown.




103. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{
	public:
		int b;
		void fun()
		{
			cout<< b<< " ";
		}
	};

	class dev1 : virtual public base
	{}S;

	class dev2 : virtual public dev1
	{}D;

	class dev3 : virtual public dev1
	{}E;

	class dev4 : public dev2, public dev3
	{}F;

	int main()
	{
		F.b = 3;
		F.fun();
	}

Answer: 3

This works as expected.




104. What is the output of the code?

#include <iostream>
using namespace std;

class base
{
public:
	int b;
	void fun()
	{
		cout<< b<< " ";
	}
};

class dev1 : virtual public base
{}S;

class dev2 : virtual public dev1
{}D;

class dev3 : virtual public dev1
{}E;

class dev4 : virtual public dev2, virtual public dev3
{}F;

int main()
{
	F.b = 3;
	F.fun();
}

Answer: 3

This also works fine, but the 'virtual' specified while inheriting dev4 goes useless.



105. What is the output of the code?

		#include <iostream>
		using namespace std;

		class base
		{
		public:
			int b;
			void fun()
			{
			cout<< b<< " ";
			}
		};

		class dev1 : public base
		{}S;

		class dev2 : virtual public dev1
		{}D;

		class dev3 : virtual public dev1
		{}E;

		class dev4 : public dev2, public dev3
		{}F;

		int main()
		{
			F.b = 3;
			F.fun();
		}


Answer: 3

Even this works right. The necessity of 'virtual' is only on hierarchical inheritance part.



106. What is the output of the code?

	#include <iostream>
	using namespace std;

	class base
	{};

	class dev1 : public base
	{}S;

	class dev2 : public dev1
	{}D;

	class dev3 : public dev1
	{}E;

	class dev4 : public dev2, public dev3
	{}F;

	int main()
	{
		cout<< "fun";
	}

Answer: fun

When both the base classes is empty there is no chance of collision and 'virtual' keyword can be skipped. But it has no significance.



107. What is the type of inheritance used?

#include <iostream>
using namespace std;

class base
{
//block
}A;

class dev1 : public base
{
//block
}S;

class dev2 : public dev1
{
//block
}D;

class dev3 : public dev1
{
//block
}E;

class dev4 : public dev2, public dev3
{
//block
}F;

class dev5 : public dev4
{
//block
}V;

int main()
{
//block }

(a) Hybrid
(b) Hierarchical
(c) Multilevel
(d) Multiple

Answer: (a)
It is a combination of simple, multilevel and hierarchical modes.




108. What is the type of inheritance used?

	#include <iostream>
	using namespace std;

	class base
	{
	//block
	}A;

	class dev1 : public base
	{
	//block
	}S;

	class dev2 : public dev1
	{
	//block
	}D;

	class dev3 : public dev2
	{
	//block
	}E;

	class dev4 : public dev3
	{
	//block
	}F;

	class dev5 : public dev3
	{
	//block
	}V;

	int main()
	{
	//block
	}

(a) Hybrid
(b) Hierarchical
(c) Multilevel
(d) Multiple

Answer: (a)

It has multilevel followed by hierarchical.




109. What is the type of inheritance used?

	#include <iostream>
	using namespace std;

	class base
	{//block }A;

	class dev1 : public base
	{//block }S;

	class dev2 : public dev1
	{//block }D;

	class dev3 : public dev2
	{//block }E;

	class dev4 : public dev3
	{//block }F;

	class dev5 : public dev4, public dev3
	{//block }V;

	int main()
	{//block }

(a) Hybrid
(b) Hierarchical
(c) Multilevel
(d) Multiple

Answer: (a) It is considered to be a type of hybrid inheritance.




110. What is the type of inheritance used?

#include <iostream>
using namespace std;

class base
{
//block }A;

class dev1 : public base
{
//block }S;

class dev2 : public base
{
//block }D;

class dev3 : public dev2 , public dev1
{
//block }E;

int main()
{//block }

(a) Hybrid
(b) Hierarchical
(c) Multilevel
(d) Multiple
Answer: (a) It is also considered to be a type of hybrid inheritance

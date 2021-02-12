Function overloading is one of the most useful features of OOP that allows increasing the functionality of a program without losing readability. This chapter deals in detail about the nooks and corners of function overloading and leads you into overriding.




1. Which of the object orientation concepts is used in the below piece of
code?

	#include <iostream>
	using namespace std;
	class function_echo
	{
	public:
	    void echo(int x)
	    {
	        cout << "Output: " << x << endl;
	    }
	    void echo(double y)
	    {
	        cout << "Output: " << y << endl;
	    }
	    void echo(char *z)
	    {
	        cout << "Output: " << z << endl;
	    }
	};
	int main(void)
	{
	    function_echo foo;
	    foo.echo(76);
	    foo.echo(7878.099);
	    foo.echo("Hello, Welcome to Polymorphism");
	    return 0;
	}

(a) Operator overloading
(b) Function overloading
(c) Function overriding
(d) None of the above
Answer: (b) Function overloading is used in the code. Function name echo
has been used for getting all data types printed.



2. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class function_echo
	{
	public:
	    void echo()
	    {
	        cout << "I have nothing passed as an argument" << endl;
	    }
	    void echo(double y)
	    {
	        cout << "Output: " << y << endl;
	    }
	    void echo(char *z)
	    {
	        cout << "Output: " << z << endl;
	    }
	};
	int main(void)
	{
	    function_echo foo;
	    foo.echo();
	    foo.echo(780.23);
	    foo.echo("Hello");
	    return 0;
	}

(a) No output
(b) Syntax error
(c) I have nothing passed as an argument
780.23
Hello
(d) Compilation error
Answer: (c) This code will work fine and the function will be identified
based on the number of arguments and since there is no argument for the
first call, it would search for the appropriate function with no arguments and
call the same. So C is the answer.



3. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class function_echo
	{
	public:
	    void echo()
	    {
	        cout << "I have nothing passed as an argument" << endl;
	    }
	    void echo()
	    {
	        cout << "I too have nothing with me: " << endl;
	    }
	    void echo(char *z)
	    {
	        cout << "Output: " << z << endl;
	    }
	};
	int main(void)
	{
	    function_echo foo;
	    foo.echo();
	    foo.echo();
	    foo.echo("Hello");
	    return 0;
	}

(a) Code will get compilation error
(b) Code will run smoothly
(c) Code will fetch syntax error
(d) None of the above

Answer: (a) Code will fetch compilation error as echo has been ambiguous
with no arguments twice. Compiler will not be able to select one as both
resemble the same.



4. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;

	class function_add
	{
	public:
	    void add(int x, int y)
	    {
	        cout << x + y << " ";
	    }
	    void add(double x, double y)
	    {
	        cout << x + y << " ";
	    }
	};

	int main(void)
	{
	    function_add foo;
	    foo.add(76, 45);
	    foo.add(1.0000, 2.000);
	    return 0;
	}

(a) Compilation fault
(b) Syntax error
(c) 121 3
(d) 3 121

Answer: (c) This is proper function overloading and function add has been
overloaded to handle double arguments.


5. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;

	class function_add
	{
	public:
	    void add(int x, int y)
	    {
	        cout << x + y << " ";
	    }
	    void add(double x, double y, int z)
	    {
	        cout << x + y + z << " ";
	    }
	};

	int main(void)
	{
	    function_add foo;
	    foo.add(76, 45);
	    foo.add(1.0000, 2.000, 2);
	    return 0;
	}

(a) Compilation fault
(b) Syntax error
(c) 121 5
(d) 5.0 121

Answer: (c) This is the right way of using function overloading and will work fine. The number of arguments are different for both the functions hence, the call will be made based on the number of arguments. 2 arguments for the former and 3 for the latter.



6. Which of the following points about function overloading are true?

(a) Number of arguments can be the same for the functions.
(b) Number of arguments must be different for all the functions.
(c) Number of arguments or type of the arguments shall be different.
(d) There is no requirement on data types or number of arguments.

Answer: (c)



7. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class function_add
	{
	public:
	    void add(int x, int y, int z)
	    {
	        cout << x + y + z << " ";
	    }
	    void add(int a, int b, int c)
	    {
	        cout << a + b + c << " ";
	    }
	};
	int main(void)
	{
	    function_add foo;
	    foo.add(1, 2, 3);
	    foo.add(4, 5, 6);
	    return 0;
	}

(a) 6 15
(b) 15 6
(c) Compilation error (Cannot be overloaded)
(d) None of the above

Answer: c) The number and type of arguments remain the same for both the functions while name of the function being the same. This is ambiguous and shall fail the compilation saying cannot overload.



8. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	void show(char[]);
	void show(char[], char[]);
	void show(char[], char[], char[]);
	int main()
	{
	    char one[] = "I love programming";
	    char two[] = "It is so fun";
	    char three[] = "How about you";
	    show(one);
	    show(one, two);
	    show(one, two, three);
	    return 0;
	}
	void show(char x[])
	{
	    cout << x << endl;
	}
	void show(char x[], char y[])
	{
	    cout << x << endl
	         << y << endl;
	}
	void show(char x[], char y[], char z[])
	{
	    cout << x << endl
	         << y << endl
	         << z << endl;
	}

(a) No output.
(b) I love programming
I love programming
It is so fun
I love programming
It is so fun
How about you
(c) Compilation fault
Answer: (b) This is an example for how number of arguments would be
used for identifying appropriate function.



9.  In general, which of the following are inappropriate with respect to function overloading in C++?

(a) Overloading functions is not possible.
(b) Overloading operators is not possible.
(c) Overloading constructors is not possible.
(d) Overloading destructors is not possible.

Answer: d



10. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	void add(int);
	void add(int, int);
	void add(int, int, int);
	int main()
	{
	    int x = 1;
	    int y = 2;
	    int z = 3;
	    add(x);
	    add(x, y);
	    add(x, y, z);
	    return 0;
	}
	void add(int a)
	{
	    cout << a << endl;
	}
	void add(int a, int b)
	{
	    cout << a + b << endl;
	}
	void add(int a, int b, int c)
	{
	    cout << a + b + c << endl;
	}

(a) Syntax error
(b) 1
3
6
(c) Compilation fault
(d) None of the above

Answer: (b)



11. Why could someone overload constructor? Select the probable reasons from the below given options.

(a) To attain more flexibility
(b) Because it is mandatory
(c) To support the concept of copy constructors
(d) To avoid compilation faults

Answer: (a) and (c) It is not mandatory to overload the constructors and if
it is not overloaded it would not result in any compilation faults.



12. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class constructor_overloading
	{
	public:
	    int a;
	    constructor_overloading(int b)
	    {
	        cout << "\n" << "single parameter" << endl;
	        a = b;
	    }
	    constructor_overloading()
	    {
	        cout << "\n" << "No Argument" << endl;
	    }
	};

	int main()
	{
	    constructor_overloading obj1(2);
	    cout << obj1.a << endl;
	    constructor_overloading obj2;
	    return 0;
	}

(a) Syntax error
(b) Constructors cannot be overloaded
(c) Single parameter
2
No argument
(d) Since there is no destructor in the code, it will fail.

Answer: (c) is the correct answer as the constructors can be overloaded and
the first one would call the constructor with one argument and the second
will call the constructor with none.



13. What is the output of the following code?

	#include <iostream>
	using namespace std;

	class constructor_overloading
	{
	public:
	    int a, c;
	    constructor_overloading(int b)
	    {
	        cout << "\n" << "single parameter" << endl;
	        a = b;
	    }
	    constructor_overloading()
	    {
	        cout << "\n" << "No Argument" << endl;
	    }
	    constructor_overloading(int d)
	    {
	        cout << "\n" << "single parameter" << endl;
	        c = d;
	    }
	};
	int main()
	{
	    constructor_overloading obj1(2);
	    cout << obj1.a << endl;
	    constructor_overloading obj2;
	    constructor_overloading obj3(4);
	    cout << obj1.c << endl;
	    return 0;
	}

(a) Compilation fault
(b) The code will throw segmentation fault
(c) No output
(d) Destructor missing error
Answer: (a) 'constructor_overloading ::constructor_overloading(int)'
cannot be overloaded'. The code has tried to overload constructor with
same argument type and number of arguments.



14. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class constructor_overloading
	{
	public:
	    int a, c;
	    constructor_overloading(int b)
	    {
	        cout << "\n" << "single parameter" << endl;
	        a = b;
	        cout << a << endl;
	    }
	    constructor_overloading(int d, int e)
	    {
	        cout << "\n" << "two arguments" << endl;
	        c = d + e;
	        cout << c << endl;
	    }
	};
	int main()
	{
	    constructor_overloading obj1(2);
	    constructor_overloading obj3(4, 3);
	    return 0;
	}

(a) 2, 4, 3
(b) 2, 7
(c) single parameter
2
Two arguments
7
(d) none of the above

Answer: (c)



15. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class constructor_overloading
	{
	public:
			int a;
			constructor_overloading(int b)
			{
					cout << "single parameter" << endl;
					a = b;
					cout << a << endl;
			}
			constructor_overloading(int d, int e)
			{
					cout << "two arguments" << endl;
					a = d + e;
					cout << a << endl;
			}
			~constructor_overloading()
			{
					cout << "calling the destructor " << a << endl;
			}
	};
	int main()
	{
			constructor_overloading obj1(2);
			constructor_overloading obj3(4, 3);
			return 0;
	}

(a) Compilation error
(b) 2, 7
(c) single parameter
2
two arguments
7
calling the destructor 7
calling the destructor 2
(d) None of the above

Answer: (c) The destructor will be called appropriately and 'c)' is the
correct answer.



16. What is the output of the below code snippet?

	#include <iostream>
	using namespace std;
	class constructor_overloading
	{
	public:
	    int a, c;
	    constructor_overloading(int b)
	    {
	        cout << "\n" << "single parameter" << endl;
	        a = b;
	        cout << a << endl;
	    }
	    constructor_overloading(int d, int e)
	    {
	        cout << "\n" << "two arguments" << endl;
	        c = d + e;
	        cout << c << endl;
	    }
	    ~constructor_overloading()
	    {
	        cout << "This is a destructor for base class" << endl;
	    }
	    ~constructor_overloading()
	    {
	        cout << "This is a destructor for derived class" << endl;
	    }
	};
	int main()
	{
		constructor_overloading obj1(2);
		constructor_overloading obj3(4, 3);
		return 0;
	}

(a) Compilation error as destructor cannot be overloaded.
(b) Code will throw syntax error.
(c) No output, no warning.
(d) Code will compile normally.
Answer: (a) Compilation error as destructor cannot be overloaded. This is a
basic rule and destructors cannot be overloaded.



17. What is the output of the below code snippet?

	#include <iostream>
	using namespace std;
	class constructor_overloading
	{
	public:
	    int a;
			~constructor_overloading()
			{
					cout << "calling the destructor " << a << endl;
			}
	    constructor_overloading(int b)
	    {
	        cout << "\n" << "single parameter" << endl;
	        a = b;
	        cout << a << endl;
	    }
	    constructor_overloading(int d, int e)
	    {
	        cout << "\n" << "two arguments" << endl;
	        a = d + e;
	        cout << c << endl;
	    }
	};
	int main()
	{
	    constructor_overloading obj1(2);
	    constructor_overloading obj3(4, 3);
	    return 0;
	}

(a) Destructor has to follow the constructor in the sequence.
(b) Warning will be thrown as Destructor in wrong place.
(c) single parameter
2
two arguments
7
calling the destructor 7
calling the destructor 2
(d) None of the above. Code will not produce any output.

Answer: (c) is the correct answer as the destructor can be placed in the top
of the class or bottom. Does not matter for the execution to be carried out.



18. What is the output of the below piece of code?

	#include <iostream>
	using namespace std;
	class Constructor_Array_Overloading
	{
	    int x;

	public:
	    Constructor_Array_Overloading()
	    {
	        x = 0;
	    }
	    Constructor_Array_Overloading(int n)
	    {
	        x = n;
	    }
	    int get_value()
	    {
	        return x;
	    }
	};
	int main()
	{
	    constructor_Array_Overloading obj1[2];
	    Constructor_Array_Overloading obj2[2] = {
	        1,
	        2,
	    };
	    int i;
	    for (i = 0; i < 2; i++)
	    {
	        cout << "obj1[" << i << "]: " << obj1[i].get_value() << endl;
	        cout << "obj2[" << i << "]: " << obj2[i].get_value() << endl;
	    }
	    return 0;
	}

(a) obj1[0]: 0
obj2[0]: 1
obj1[1]: 0
obj2[1]: 2
(b) Compilation error
(c) Segmentation fault
(d) obj1[0]: 2
obj2[0]: 0

Answer: (a) Is the correct answer and constructors can be overloaded to
initialize array as well.



19. Which of the following points are true with respect to constructor overloading?
(a) If a program has no constructor of appropriate type found, object creation will result in compile time error.
(b) Constructor overloading permits usage of individual objects as well as array of objects within the same code.
(c) Usage of constructor increases the compile time by a huge volume.
(d) Constructor must be definitely accompanied by a destructor.

Answer: (a) and (b) are true with respect to the constructor overloading.




20. What is the output of the below piece of code?

	#include <iostream>
	using namespace std;
	class Constructor_Array_Overloading
	{
	    int x;

	public:
	    Constructor_Array_Overloading()
	    {
	        x = 0;
	    }
	    Constructor_Array_Overloading(int n)
	    {
	        x = n;
	    }
	    int get_value()
	    {
	        return x;
	    }
	};
	int main()
	{
	    Constructor_Array_Overloading obj1[2];
	    Constructor_Array_Overloading obj2[2] = {1};
	    int i;
	    for (i = 0; i < 2; i++)
	    {
	        cout << "obj1[" << i << "]: " << obj1[i].get_value() << endl;
	        cout << "obj2[" << i << "]: " << obj2[i].get_value() << endl;
	    }
	    return 0;
	}

(a) obj1[0]: 0
obj2[0]: 1
obj1[1]: 0
obj2[1]: 0
(b) Compilation error
(c) Segmentation fault
(d) obj1[0]: 0
obj2[0]: 1
obj1[1]: 0
obj2[1]: 1
Answer: (a) Because, if one element of the array is initialized, rest all will
be zero.



21. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a = 0, float b = 0.000, char c = 'a')
	{
	    cout << "\n" << a
		   		 << "\n" << b
	    		 << "\n" << c;
	}
	int main()
	{
	    func();
	    func(10);
	    func(10, 20.000);
	    return 0;
	}

(a) Compilation fault
(b) Overloading error
(c) 0
0
a
10
0
a
10
20
a
(d) None of the above

Answer: (c) is the answer and this concept is referred to as Default
Arguments.



23. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a = 0, int b, char c = 'a')
	{
		cout << "\n" << a
				 << "\n" << b
				 << "\n" << c;
	}
	int main()
	{
	    func();
	    func(10);
	    func(10, 20.000);
	    return 0;
	}

(a) Compilation error
(b) 00a
(c) Syntax error
(d) 10
20
000

Answer: (a) Compilation error. Default argument missing for parameter 2
of 'void func (int, int, char)'
All default arguments must appear after those without defaults



24. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a = 0, int b = 0, char c = 'a')
	{
	    int a = 1;
	    int b = 1;
	    cout << a << "," << b << "," << c;
	}
	int main()
	{
	    func();
	    func(10);
	    func(10, 20.000);
	    return 0;
	}

(a) Compilation error
(b) 1,1,a
(c) Syntax error
(d) 10,20,000
Answer: (a) Compilation error. Redeclaration of 'int a' and 'int b' shadows
the default values and is not permitted.



25. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a = 0, int b = 0, char c = 'a', int d = 0)
	{
		cout << "\n" << a
				 << "\n" << b
				 << "\n" << c;
	}
	int main()
	{
	    func();
	    func(10);
	    func(10, 20.000);
	    return 0;
	}

(a) Compilation fault
(b) Overloading error
(c) 0
0
a
10
0
a
10
20
a
(d) None of the above
Answer: (c) The code will get compiled normally and one more variable in
the function definition will not change the course of flow.



26. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a = 0, int a = 1, int b = 0, char c = 'a')
	{
		cout << "\n" << a
				 << "\n" << b
				 << "\n" << c;
	}
	int main()
	{
	    func();
	    func(10);
	    func(10, 20.000);
	    return 0;
	}

(a) Compilation error
(b) 1
0a1
0
0a1
0
20
a
(c) 0
0a1
0
0a1
0
20
a
(d) None of the above.

Answer: (a) Duplicate formal parameter name.



27. What is the output of the following code?

	#include <iostream>
	using namespace std;
	int a, b;
	int ambiguity_learn(int x, int y)
	{
	    a = x + y;
	    return a;
	}
	int ambiguity_learn(int x, int y)
	{
	    b = x - y;
	    return b;
	}
	int main()
	{
	    int x = 9, y = 7;
	    ambiguity_learn(x, y);
	    return 0;
	}

(a) 16
(b) 2
(c) Compilation error
(d) None of the above
Answer: (c) redefinition of 'int ambiguity_learn(int, int)' is not permitted.



28. What is the output of the following code?

	#include <iostream>
	using namespace std;
	int a, b;
	ambiguity_learn(int &x, int &y)
	{
	    a = x + y;
	    return a;
	}
	(
	ambiguity_learn(int &x, int &y)
	{
	    b = x * y;
	    return b;
	}
	int main()
	{
	    int x = 9, y = 7;
	    ambiguity_learn(x, y);
	    return 0;
	}

(a) 16
(b) 63
(c) Compilation error
(d) None of the above

Answer: (c) Call of overloaded 'ambiguity_learn(int&, int&)' is ambiguous. There is no difference from syntax point of view for calling a function with a value and with a reference.



30. What is the output of the following code?

	#include <iostream>
	using namespace std;
	void func(int a, int b = 1)
	{
	    cout << a << ",";
	    cout << b << " ";
	}
	void func(int a)
	{
	    cout << a << " ";
	}
	int main()
	{
	    func(10);
	    func(10, 20);
	    return 0;
	}

(a) 10 10 20
(b) 10 20 10
(c) Compilation error
(d) Syntax error

Answer: (c) It is ambiguous here as func(10) call matches both thefunctions hence, it is ambiguous.



31. What is the OOPS feature used in the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in base class" << endl;
	    }
	};
	class derived_class : public Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in derived class" << endl;
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo();
	    derived_class d;
	    d.function_foo();
	    getchar();
	    return 0;
	}

(a) Operator overloading
(b) Function overloading
(c) Function overriding
(d) None of the above

Answer: (c) It is function overriding. The function function_foo has different contents in the base class and derived class thus, overriding the function.



32. What would be the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in base class. ";
	    }
	};
	class derived_class : public Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in derived class. ";
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo();
	    derived_class d;
	    d.function_foo();
	    getchar();
	    return 0;
	}

(a) Hello, I am in base class. Hello, I am in base class.
(b) Hello, I am in base class. Hello, I am in derived class.
(c) Hello, I am in derived class. Hello, I am in derived class.
(d) Syntax error

Answer: (b) Since the function is overridden successfully, it will call the functions appropriately for each function call. Base class object will call base class function and derived class object will call derived call function.



33. What would be the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in base class. "
	    }
	};
	class derived_class : private Base_class
	{
	public:
	    void function_foo()
	    {
	        cout << "Hello, I am in derived class. "
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo();
	    derived_class d;
	    d.function_foo();
	    return 0;
	}

(a) Hello, I am in base class. Hello, I am in base class.
(b) Hello, I am in base class. Hello, I am in derived class.
(c) Hello, I am in derived class. Hello, I am in derived class.
(d) Syntax error

Answer: (b) Deriving the class with private rights has not affected the overridden function. Since the function is overridden successfully, it will call the functions appropriately for each function call. Base class object will call base class function and derived class object will call derived call function.



34. Which of the following points hold good for function overriding?

	1. The definition of the function being overridden must have same method name.
	2. The base class function and the overriding function must have same data type.
	3. The base class function and the overriding function must have same argument list.
	4. The derived class must be inherited only with private access rights.

(a) 1, 2
(b) 1, 2, 3
(c) 1, 2, 3, 4
(d) 4



Answer: (b) 1,2 and 3 are true with respect to function overriding. It is
referred to as the signature.



35. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int c;
	    void function_foo(int a, int b)
	    {
	        c = a + b;
	        cout << c;
	    }
	};
	class derived_class : private Base_class
	{
	public:
	    int d;
	    void function_foo(int e, int f)
	    {
	        d = e + f;
	        cout << d;
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo(3, 4);
	    derived_class d;
	    d.function_foo(4, 5);
	    return 0;
	}

(a) 3 5
(b) 7 9
(c) 9 7
(d) Error

Answer: (b) Since the function signatures match, the code will work fine and
overriding will happen.



36. Identify mistakes if any in the following code.

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    float c;
	    void function_foo(float a, float b)
	    {
	        c = a + b;
	        cout << endl << c;
	    }
	};
	class derived_class : private Base_class
	{
	public:
	    int d;
	    void function_foo(int e, int f)
	    {
	        d = e + f;
	        cout << endl << d;
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo(3.222, 4.568);
	    derived_class d;
	    d.function_foo(4, 5);
	    return 0;
	}

(a) The code will run fine, no errors. Output will be 7.79 and 9.
(b) The code will generate error as the arguments passed are different to
the called function.
(c) The code will generate warning.
(d) None of the above.

Answer: (a) The code will run. But, this does not qualify to be called function overriding as the signature is changed. This is referred as shadowing.



37. Which of the following are/is true about overriding?

	1. Overriding can be done with only one class in place.
	2. Overriding can be done even without inheritance.
	3. Overriding cannot be done within a class.
	4. Overriding cannot be achieved if no inheritance is deployed.

(a) 1 and 2
(b) 2 and 3
(c) 3 and 4
(d) None of the above

Answer: c, 3 and 4 are the true about overriding.



38. What will be the output in the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void function_foo(void a, void b)
	    {
	        cout << a << b;
	    }
	};
	class derived_class : public Base_class
	{
	public:
	    void function_foo(void e, void f)
	    {
	        cout << e << f;
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo(3, 4);
	    derived_class d;
	    d.function_foo(4, 5);
	}

(a) 3445
(b) Unpredictable symbols
(c) Error
(d) None of the above

Answer: (c) Void is the not the type of argument being passed. So, it is an
error.



39. Which of the following rules are broken in the following code with respect to overriding?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    float c;
	    void function_foo(float a, float b)
	    {
	        c = a + b;
	        cout << endl
	             << c;
	    }
	};
	class derived_class : public Base_class
	{
	public:
	    int d;
	    void function_foo(int e, int f)
	    {
	        d = e + f;
	        cout << endl
	             << d;
	    }
	};
	int main()
	{
	    Base_class b;
	    b.function_foo(3.222, 4.568);
	    derived_class d;
	    d.function_foo(4, 5);
	    return 0;
	}

1. The definition of the function being overridden must have same
method name.
2. The base class function and the overriding function must have same
data type.
3. The base class function and the overriding function must have same argument list.
4. Everything is fine and no rule is broken.
(a) 1 and 2
(b) 1, 2 and 3
(c) 2
(d) 4

Answer: (c) The base class function and the overriding function must have
same data type and this rule is not followed in the above code snippet.



40. Which of the following types of inheritances supports overriding?

	1. Multiple inheritance
	2. Multilevel inheritance
	3. Single inheritance
	4. Hybrid inheritance
	5. All the above

	(a) 1, 2, 3
	(b) 1,3
	(c) 5.
	(d) 1

Answer: (c) All the types of inheritances support overriding.



41. Which of the following is true about virtual functions?

	(a) Virtual functions will enable the programmer to redefine functions declared in the base class in derived class.
	(b) No specific keywords are required to make a function virtual.
	(c) Virtual function enables early binding or compile time binding.
	(d) Virtual function enables late binding or runtime binding.

Answer: (a) and (d) are true.



42. Which of the following is said to be late binding?

	(a) A function call is resolved at runtime.
	(b) Compiler will determine object type at runtime, and will bind the
	function call.
	(c) Compiler determines the object type well in advance and binds it intime.
	(d) None of the above.

Answer: (a) and (b)



43.	True or False

	Virtual functions also follow the same principle of one interface and
	multiple methods like polymorphism.

Answer: True. It is referred as runtime polymorphism.



44. True of False

	A class if using virtual function can be referred by the term
	polymorphic class.

Answer: True.



45. Which of the following are wrong about virtual functions?

	(a) It is one of the member functions of a class and carries no additional
	privilege.
	(b) The keyword 'virtual' is used to make a function virtual function.
	(c) Provides no different functionality in the derived class.
	(d) 'virtual' keyword has to be used only in upper case letters.

Answer: (c) and (d) are wrong perceptions about virtual functions.



46. What is the object orientation concept used in the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void virtual show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    p->display();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    p->display();
	    return 0;
	}

(a) Inline functions
(b) pure virtual function
(c) virtual function
(d) function overloading

Answer: (c) The virtual keyword used the base class member function reveals the fact that the concept used is virtual functions.



47. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void virtual show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    p->display();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    p->display();
	    return 0;
	}

(a) Syntax error
(b) Function Show in Base Class
Function display in Base Class
Function Show in Derived Class
Function display in Base Class
(c) Function Show in Base Class
Function display in Base Class
Function Show in Derived Class
Function display in Derived Class
(d) Compilation fault, invalid usage of keyword virtual

Answer: (b) is the correct answer. Keyword virtual is used for the function
show hence, the compiler will call the redefined show from derived class
appropriately.



48. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void virtual show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	    void virtual display()
	    {
	        cout << "Function display in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    p->display();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    p->display();
	    return 0;
	}

(a) Syntax error
(b) Function Show in Base Class
Function display in Base Class
Function Show in Derived Class
Function display in Base Class
(c) Function Show in Base Class
Function display in Base Class
Function Show in Derived Class
Function display in Derived Class
(d) Compilation fault, invalid usage of keyword virtual

Answer: (c) Since both the functions in the base class are made virtual, the
calls will be made to appropriate functions from the derived class at runtime
through late binding concept.



49. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	    void display()
	    {
	        cout << "Function display in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    p->display();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    p->display();
	    return 0;
	}

(a) Syntax error
(b) Function Show in Base Class
Function display in Base Class
Function Show in Base Class
Function display in Base Class
(c) Function Show in Base Class
Function display in Base Class
Function Show in Derived Class
Function display in Derived Class
(d) Compilation fault, invalid usage of keyword virtual

Answer: (b) is the answer. Since the early binding will happen the compiler
would call only the base class functions as everything gets resolved at
compile time. Virtual keyword as used in previous examples would avoid
this error.



50. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Syntax error
(b) Function Show in Base Class
Function Show in Base Class
(c) Function Show in Base Class
Function Show in Derived Class
(d) Virtual keyword should be used as void virtual show and not virtual
void show.

Answer: (c) It does not matter if the virtual is kept before or after function
return type. It will work fine.


51. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Syntax error
(b) Function Show in Base Class
Function Show in Base Class
(c) Function Show in Base Class
Function Show in Derived Class
(d) Compilation error. Keyword virtual cannot be used in derived class.

Answer: (b) It is absolutely fine to use virtual in a base class or a derived class. Classes derived from the class using virtual will reflect the usage.



52. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	class Derived_1_class : public Derived_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in derived _ 1 Class (derived to derived)" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    Derived_1_class obj3;
	    p = &obj3;
	    p->show();
	    return 0;
	}

(a) Function Show in Base Class
Function Show in Base Class
Function Show in Base Class
(b) Function Show in Base Class
Function Show in Base Class
(c) Function Show in Base Class
(d) Compilation error. Keyword virtual cannot be used in derived class.

Answer: (a) The keyword virtual is used the first derived class and it is to
be noted that the pointer is of type base class hence, is the result.



53. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	class Derived_1_class : public Derived_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in derived _ 1 Class (derived to derived)" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    Derived_class *p1;
	    Derived_1_class obj3;
	    p1 = &obj3;
	    p1->show();
	    return 0;
	}

(a) Function Show in Base Class
Function Show in Base Class
Function Show in Base Class
(b) Function Show in Base Class
Function Show in Base Class
Function Show in derived _ 1 Class (derived to derived)
(c) Function Show in Base Class
(d) Compilation error. Keyword virtual cannot be used in derived class.

Answer: (b) Since the pointer of type derived class is used properly, the
code will work as expected.



54. Identify the error in the following piece of code.

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : private Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	class Derived_1_class : private Derived_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in derived _ 1 Class (derived to derived)" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    Derived_class *p1;
	    Derived_1_class obj3;
	    p1 = &obj3;
	    p1->show();
	    return 0;
	}

(a) No mistake, the code will run fine.
(b) Syntax error will be thrown.
(c) 'Base_class' is an inaccessible base of 'Derived_class' and
'Derived_class' is an inaccessible base of 'Derived_1_class'
(d) None of the above.

Answer: (c) The access specifier used is Private and hence 'Base_class' is an inaccessible base of 'Derived_class' and 'Derived_class' is an inaccessible base of 'Derived_1_class'



55. Identify the error in the following code.

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : protected Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) No mistake, the code will run fine.
(b) Syntax error will be thrown.
(c) 'Base_class' is an inaccessible base of 'Derived_class'
(d) None of the above

Answer: (c) Since the access specifier is chosen to be protected, it would
throw the error "'Base_class' is an inaccessible base of 'Derived_class'"



56. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class" << endl;
	    }
	};
	class Derived_class_2 : public Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class_2" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    Derived_class_2 obj3;
	    p = &obj3;
	    p->show();
	    return 0;
	}

(a) Virtual keyword is used wrongly
(b) Function Show in Base Class
Function Show in Derived Class
Function Show in Derived Class_2
(c) Function Show in Derived Class
Function Show in Derived Class_2
(d) None of the above

Answer: (b) Virtual once used in the base class will be valid for all derived classes.




59. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show()
	    {
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Compilation fault
(b) No error. No output
(c) Illegal as a function cannot be made virtual in base and derived
classes
(d) None of the above
Answer: (b) No error and no output and it is not harmful to have same
function virtual in both base and derived classes.



60. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show() = 0;
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n" << " This is a demo for pure virtual function";
	    }
	};
	int main()
	{
	    Base_class *p;
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Compilation fault
(b) No error. No output
(c) This is a demo for pure virtual function
(d) None of the above

Answer: (c) This is demo for pure virtual function as the base class virtual
function is equated to zero and has been overridden in the derived class.




62. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show() = NULL;
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n" << " This is a demo for pure virtual function";
	    }
	};
	int main()
	{
	    Base_class *p;
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Compilation fault
(b) No error. No output
(c) This is a demo for pure virtual function
(d) None of the above

Answer: (a) Compilation error as NULL is invalid pure specifier. Only 0 is
preferred as pure specifier.



63. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show() = "ZERO";
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n"
	             << " This is a demo for pure virtual function";
	    }
	};
	int main()
	{
	    Base_class *p;
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
}

(a) Compilation fault
(b) No error. No output
(c) This is a demo for pure virtual function
(d) None of the above

Answer: (a) Compilation error as "ZERO" is invalid pure specifier. Only 0
is preferred as pure specifier.



64. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show();
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n" << " This is a demo for pure virtual function";
	    }
	};
	int main()
	{
	    Base_class *p;
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Compilation fault
(b) No error. No output
(c) This is a demo for pure virtual function
(d) None of the above

Answer: (a) Compilation error. Virtual void show () is not presented properly and it has to be equated to 0.



65. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show() = 80;
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n" << " This is a demo for pure virtual function";
	    }
	};
	int main()
	{
	    Base_class *p;
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Compilation fault
(b) No error. No output
(c) This is a demo for pure virtual function
(d) None of the above

Answer: (a) Compilation error as 80 is invalid pure specifier. Only 0 is
preferred as pure specifier.



66. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show() = 0;
	};
	class Derived_class_2 : public Derived_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class_2" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class *p1;
	    Derived_class_2 obj3;
	    p1 = &obj3;
	    p1->show();
	    return 0;
	}

(a) Compilation error with usage of virtual in derived class
(b) No error. No output
(c) Function Show in Base Class
Function Show in Derived Class_2
(d) None of the above

Answer: (c) It is absolutely legal to use the keyword virtual with base class
or derived class and it does not matter at all.



67. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Base Class" << endl;
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show();
	};
	class Derived_class_2 : public Derived_class
	{
	public:
	    void show()
	    {
	        cout << "Function Show in Derived Class_2" << endl;
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class *p1;
	    Derived_class_2 obj3;
	    p1 = &obj3;
	    p1->show();
	    return 0;
	}

(a) Syntax error.
(b) Compilation error.
(c) Function Show in Derived Class_2
(d) Function Show in Base Class

Answer: (b) Compilation error. As the virtual function has been drafted
wrongly. It could be either equated to 0 or { } should have been used.



68. What is wrong in the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual void show() = 0;
	};
	class Derived_class : public Base_class
	{
	public:
	    virtual void show()
	    {
	        cout << "\n" << "Test";
	    }
	};
	int main()
	{
	    Base_class obj1;
	    Base_class *p;
	    p = &obj1;
	    p->show();
	    Derived_class obj2;
	    p = &obj2;
	    p->show();
	    return 0;
	}

(a) Nothing wrong. The code will get compiled.
(b) Syntax error.
(c) No output.
(d) Compilation error.

Answer: (d) Compilation error. Cannot declare variable 'obj1' to be of abstract type 'Base_class'. When a function is equated to 0, one cannot try to create an object for that class as it qualifies to be abstract class.



69. Which of the following are/is true about virtual function?

	(a) A virtual function gets qualified to be pure if assigned with 0.
	(b) Keyword pure is required to make a function pure virtual function.
	(c) If a pure virtual function is created in an abstract class, there will be a slot reserved in for function in Virtual table, with having no address being stored there in the slot.
	(d) Instance of abstract class cannot be created.

Answer: (a), (c) and (d)



70. Which of the following is/are true about virtual function?

	(a) When a function gets called as virtual function, binding happens at compile time.
	(b) When a function gets called as virtual function, binding happens at runtime.
	(c) Assigning a NULL is equivalent to assigning 0 with respect to pure virtual function.
	(d) Using virtual functions will slow down the execution speed as the binding happens runtime.

Answer: (b) and (d)



71. What is the output of the following piece of code? Also point out the
error in the code which could be logical.

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    Base_class()
	    {
	        cout << "This is a base class constructor" << "\n";
	    }
	    ~Base_class()
	    {
	        cout << "This is a base class destructor" << "\n";
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    Derived_class()
	    {
	        cout << "This is a Derived_class constructor" << "\n";
	    }
	    ~Derived_class()
	    {
	        cout << "This is a Derived_class destructor" << "\n";
	    }
	};
	int main()
	{
	    Base_class *b;
	    b = new Derived_class;
	    delete b;
	    return 0;
	}

Answer: The expected output would not arrive and the following is the
output one would get.
This is a base class constructor.
This is a Derived_class constructor.
This is a base class destructor.
Reasoning: If the destructor in the base class is not made virtual, then an object that might have been declared of type base class and instance of child class would simply call the base class destructor without having called the derived class destructor. This can be related and is synonymous to the previous learning about virtual functions.



72. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    Base_class()
	    {
	        cout << "This is a base class constructor" << "\n";
	    }
	    virtual ~Base_class()
	    {
	        cout << "This is a base class destructor" << "\n";
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    Derived_class()
	    {
	        cout << "This is a Derived_class constructor" << "\n";
	    }
	    ~Derived_class()
	    {
	        cout << "This is a Derived_class destructor" << "\n";
	    }
	};
	int main()
	{
	    Base_class *b;
	    b = new Derived_class;
	    delete b;
	    return 0;
	}

(a) This is a base class constructor
This is a Derived_class constructor
This is a base class destructor
(b) This is a base class constructor
This is a Derived_class constructor
This is a Derived_class destructor
This is a base class destructor
(c) Compilation fault. Keyword virtual used wrongly for destructor
(d) Syntax error

Answer: (b) Since, keyword virtual is used appropriately with the
destructor of base class, calling sequence of the destructor would be proper.



73. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    virtual Base_class()
	    {
	        cout << "This is a base class constructor" << "\n";
	    }
	    virtual ~Base_class()
	    {
	        cout << "This is a base class destructor" << "\n";
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    Derived_class()
	    {
	        cout << "This is a Derived_class constructor" << "\n";
	    }
	    ~Derived_class()
	    {
	        cout << "This is a Derived_class destructor" << "\n";
	    }
	};
	int main()
	{
	    Base_class *b;
	    b = new Derived_class;
	    delete b;
	    return 0;
	}

(a) This is a base class constructor
This is a Derived_class constructor
This is a base class destructor
(b) This is a base class constructor
This is a Derived_class constructor
This is a Derived_class destructor
This is a base class destructor
(c) Compilation fault. Keyword
(d) Syntax Error.

Answer: (c) The compiler would throw compilation error. One can never make the constructor virtual.



74. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    Base_class()
	    {
	        cout << "This is a base class constructor"
	             << "\n";
	    }
	    ~Base_class()
	    {
	        cout << "This is a base class destructor"
	             << "\n";
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    Derived_class()
	    {
	        cout << "This is a Derived_class constructor"
	             << "\n";
	    }
	    virtual ~Derived_class()
	    {
	        cout << "This is a Derived_class destructor"
	             << "\n";
	    }
	};
	int main()
	{
	    Base_class *b;
	    b = new Derived_class;
	    delete b;
	    return 0;
	}

(a) This is a base class constructor
This is a Derived_class constructor
This is a base class destructor
(b) This is a base class constructor
This is a Derived_class constructor
This is a Derived_class destructor
This is a base class destructor
(c) Compilation fault.
(d) Syntax error.

Answer: (a) Since the base class destructor is not made virtual, the sequence of calling the destructor would remain as quoted in Q.No. 71.



75. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    Base_class()
	    {
	        cout << "This is a base class constructor"
	             << "\n";
	    }
	    ~Base_class virtual()
	    {
	        cout << "This is a base class destructor"
	             << "\n";
	    }
	};
	class Derived_class : public Base_class
	{
	public:
	    Derived_class()
	    {
	        cout << "This is a Derived_class constructor"
	             << "\n";
	    }
	    ~Derived_class()
	    {
	        cout << "This is a Derived_class destructor"
	             << "\n";
	    }
	};
	int main()
	{
	    Base_class *b;
	    b = new Derived_class;
	    delete b;
	    return 0;
	}

(a) This is a base class constructor
This is a Derived_class constructor
This is a base class destructor
(b) This is a base class constructor
This is a Derived_class constructor
This is a Derived_class destructor
This is a base class destructor
(c) Compilation fault. Invalid use of virtual with destructor
(d) Syntax Error

Answer: (c) Virtual cannot be used the way it has been used in this example.



76. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Code will throw syntax error.
(b) Derived class No. 2
(c) Will this code work
(d) Compilation error.

Answer: (d) The compiler throw compilation error as there is an ambiguity associated with the variable x. Since both the derived classes will have copy of x, the ambiguity will raise on using the x from one of the derived classes. This can be avoided by virtual base class concept.



77. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error. Fault with using virtual keyword)
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1Derived Class No. 2

Answer: (b) Since the virtual base class concept is used appropriately, there will not be any ambiguity associated with the code and it shall have one copy of the variable to avoid ambiguity.



78. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error. Ambiguity raised.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Since the virtual keyword is not used with the second derived class, it would tend to create ambiguity with the copy of the variable. Hence, virtual keyword is expected for the derived classes which are going to form another class from them.



79. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class virtual Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Virtual keyword for the class in the base class is done wrongly. For a class, virtual cannot precede the class name.



80. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class virtual
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Invalid usage of virtual keyword with base class. Invalid use
of incomplete type 'class Base_class' will be raised.



81. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived :: public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Though the usage of virtual keywords are all perfect, in the
class mix_derived, we have used :: instead of :. Hence, it is an invalid usage
of the operators at an inappropriate place.


82. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: b



83. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Since the Derived_1_class and Derived_2_class are private by default, the access restrictions are imposed on the mix_derived which is derived from Derived_1_class and Derived_2_class. Hence, compilation fault would be raised.



84. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) It needs both the Derived_1_class and Derived_2_class to be public for the mix_derived to be working fine. Though virtual keywords and concepts of virtual base class are properly embedded, it will throw compilation fault.



85. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Compilation error. Even in the derived class if its access
restrictions are private, one would not get access from the main (). Hence,
there would be a compilation error raised for this code.



86. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : virtual virtual public Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (a) Virtual keyword has been specified more than once in the
Derived_1_class. Hence it is a compilation fault.



87. What is the output of the following code?

	#include <iostream>
	using namespace std;
	class Base_class
	{
	public:
	    int x;
	};
	class Derived_1_class : public virtual Base_class
	{
	public:
	    Derived_1_class()
	    {
	        cout << "\n"
	             << "Derived Class No.1";
	    }
	};
	class Derived_2_class : virtual public Base_class
	{
	public:
	    Derived_2_class()
	    {
	        cout << "\n"
	             << "Derived Class No.2";
	    }
	};
	class mix_derived : public Derived_1_class, public Derived_2_class
	{
	public:
	    int example()
	    {
	        cout << "\n"
	             << "Will this code work"
	             << "\n";
	        return x;
	    }
	};
	int main()
	{
	    mix_derived obj;
	    int i = obj.example();
	    return 0;
	}

(a) Compilation error.
(b) Derived Class No. 1
Derived Class No. 2
Will this code work
(c) Will this code work
(d) Derived Class No. 1
Derived Class No. 2

Answer: (b) In this scenario, the keyword virtual can be used before or
after the class name and there would not be any compilation fault. The code
will run fine resulting in the output as b)

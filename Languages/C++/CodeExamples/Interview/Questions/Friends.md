Friend class and friend functions are the only members that can access the ‘private’ data of the class.



1. True or False

	When data members of a class are to be accessed by another class, the easiest way to achieve this is through friend class.

Answer: True



3. True or False

	Friendship between classes are mutual.

Answer: False. (If class X is friend of Y, it does not mean class Y is friend
of X.)



4. True or False

	Friendship gets inherited naturally.

Answer: False. (No friendship will get inherited by default)



5. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;
	public:
	    void test()
	    {
	        a = 1;
	        b = 2;
	    }
	    int calculate(base_class e1);
	};
	int calculate(base_class x)
	{
	    return int(x.a + x.b) + 9 - 3;
	}
	int main()
	{
	    base_class e;
	    e.test();
	    cout << calculate(e) <<"\n";

	    return 0;
	}

(a) 8
(b) 9
(c) Compilation error
(d) Syntax error

Answer: (c) Since the data members a and b are private to the class
base_class, the access restrictions are imposed.



6. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;
	public:
	    void test()
	    {
	        a = 1;
	        b = 2;
	    }
	    friend int calculate(base_class e1);
	};
	int calculate(base_class x)
	{
	    return int(x.a + x.b) + 9 - 3;
	}
	int main()
	{
	    base_class e;
	    e.test();
	    cout << calculate(e) <<"\n";

	    return 0;
	}

(a) 8
(b) 9
(c) Compilation error
(d) Syntax error

Answer: (b) Since the keyword friend is used, the function calculate which
is made friend will gain access even to the private members. Hence, the
output is (1 + 2) + 6 = 9.



7. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;

	public:
	    void test()
	    {
	        a = 1;
	        b = 2;
	    }
	    Friend int calculate(base_class e1);
	};
	int calculate(base_class x)
	{
	    return int(x.a + x.b) + 9 - 3;
	}
	int main()
	{
	    base_class e;
	    e.test();
	    cout << calculate(e) <<"\n";

	    return 0;
	}

(a) 8
(b) 9
(c) Compilation error
(d) Syntax error

Answer: (c) Friend is to be used as 'friend'.



8. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	public:
	    int a, b;
	    void test()
	    {
	        a = 1;
	        b = 2;
	    }
	};
	int calculate(base_class x)
	{
	    return int(x.a + x.b) + 9 - 3;
	}
	int main()
	{
	    base_class e;
	    e.test();
	    cout << calculate(e) <<"\n";

	    return 0;
	}

(a) 8
(b) 9
(c) Compilation error
(d) Syntax error

Answer: (b) Since the data members are public, there are no access restrictions.



9. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;

	public:
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	    }
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation error
(b) 10
(c) 15
(d) Compiler dependent

Answer: (a) Since ‘a’ and ‘b’ are private, they are not accessible from other
classes.



10. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;

	public:
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	    }
	    friend class friend_class;
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation error
(b) 10
(c) 15
(d) Compiler dependent

Answer: (c) This code reveals the concept of friend class. Since a class has
been made a friend to another class, by law, the private data members are
even accessible. Hence, the output is 15.


11. What is the output of the following piece of code?

	#include<iostream>
	using namespace std;
	class base_class
	{
	private:
	    int a, b;

	public:
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	    }
	    friend class friend_class;
	    friend class friend_class;
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation fault
(b) 15
(c) 10
(d) No output and no error

Answer: (b) It is not wrong to have a class being made a friend twice, but,
it is a bad practice. So, it is better to avoid it.



12. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	public:
	    int a, b;
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	    }
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation error
(b) 15
(c) 10
(d) No output and no error

Answer: (b) Since the data members a and b are public, no access
restrictions would be imposed and the code will work fine. There is no need
for someone to use the friend class as well in this case.



13. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	protected:
	    int a, b;
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	    }
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation error
(b) 15
(c) 10
(d) No output and no error

Answer: (a) Protected is the access specifier used in this scenario hence,
the data members of the base class are accessible only by its derived class.
This would result in compilation fault.



14. What is the output of the below code snippet?

	#include <iostream>
	using namespace std;
	class base_class
	{
	protected:
	    int a, b;

	public:
	    int d;
	    void read_input()
	    {
	        a = 5;
	        b = 10;
	        d = 10;
	    }
	    friend class friend_class;
	};
	class friend_class
	{
	public:
	    int c;
	    void add(base_class rd)
	    {
	        c = rd.a + rd.b + rd.d;
	        cout << “\n" << c;
	    }
	};
	int main()
	{
	    int cont;
	    base_class rd;
	    friend_class rs;
	    rd.read_input();
	    rs.add(rd);

	    return 0;
	}

(a) Compilation fault
(b) 25
(c) 15
(d) Syntax error

Answer: (b) Though protected, since the base_class is made friend to friend_class, the access would not be a problem.

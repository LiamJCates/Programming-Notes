### Simple Inheritance Example

The following example indicates the order of construction and destruction for simple inheritance.

  #include <iostream>

  using namespace std;

  class A
  {
  	public:
  	A() { cout << "A constructor\n"; }
  	~A() { cout << "A destructor\n"; }
  };

  class B : public A
  {
  	public:
  	B() { cout << "B constructor\n"; }
  	~B() { cout << "B destructor\n"; }
  };

  int main()
  {
    B b;
  }

Output:
  A constructor
  B constructor
  B destructor
  A destructor



### Multilevel Inheritance Example

The following example indicates the order of construction and destruction for multilevel inheritance.

  #include <iostream>

  using namespace std;

  class A
  {
  	public:
  	A() { cout << "A constructor\n"; }
  	~A() { cout << "A destructor\n"; }
  };

  class B : public A
  {
  	public:
  	B() { cout << "B constructor\n"; }
  	~B() { cout << "B destructor\n"; }
  };

  class C : public B
  {
  	public:
  	C() { cout << "C constructor\n"; }
  	~C() { cout << "C destructor\n"; }
  };

  int main()
  {
  	C c;
  }

Output:
  A constructor
  B constructor
  C constructor
  C destructor
  B destructor
  A destructor



### Multiple Inheritance Example 1

The following example indicates the order of construction and destruction for multiple inheritance.

  #include <iostream>

  using namespace std;

  class A
  {
  	public:
  	A() { cout << "A constructor\n"; }
  	~A() { cout << "A destructor\n"; }
  };

  class A2
  {
  	public:
  	A2() { cout << "A2 constructor\n"; }
  	~A2() { cout << "A2 destructor\n"; }
  };

  class B : public A, public A2
  {
  	public:
  	B() { cout << "B constructor\n"; }
  	~B() { cout << "B destructor\n"; }
  };

  int main()
  {
  	B b;
  }

Output

  A constructor
  A2 constructor
  B constructor
  B destructor
  A2 destructor
  A destructor



### Multiple Inheritance Example 2

The following example indicates the order of construction and destruction for multiple inheritance with the base class order switched.

  #include <iostream>

  using namespace std;

  class A
  {
  	public:
  	A() { cout << "A constructor\n"; }
  	~A() { cout << "A destructor\n"; }
  };

  class A2
  {
  	public:
  	A2() { cout << "A2 constructor\n"; }
  	~A2() { cout << "A2 destructor\n"; }
  };

  class B : public A2, public A
  {
  	public:
  	B() { cout << "B constructor\n"; }
  	~B() { cout << "B destructor\n"; }
  };

  int main()
  {
  	B b;
  }

Output:

  A2 constructor
  A constructor
  B constructor
  B destructor
  A destructor
  A2 destructor


## Hierarchical Inheritance Example 1

The following example indicates the order of construction and destruction for hierarchical inheritance.

	#include <iostream>

	using namespace std;

	class A
	{
		public:
		A() { cout << "A constructor\n"; }
		~A() { cout << "A destructor\n"; }
	};

	class B : public A
	{
		public:
		B() { cout << "B constructor\n"; }
		~B() { cout << "B destructor\n"; }
	};

	class C : public A
	{
		public:
		C() { cout << "C constructor\n"; }
		~C() { cout << "C destructor\n"; }
	};

	int main()
	{
		cout << "Constructors\n";
		B b;
		C c;
		cout << "Destructors\n";
	}

Output:
	Constructors
	A constructor
	B constructor
	A constructor
	C constructor
	Destructors
	C destructor
	A destructor
	B destructor
	A destructor



## Hierarchical Inheritance Example 2

The following example indicates the order of construction and destruction for hierarchical inheritance with the base class order switched.

	#include <iostream>

	using namespace std;

	class A
	{
		public:
		A() { cout << "A constructor\n"; }
		~A() { cout << "A destructor\n"; }
	};

	class B : public A
	{
		public:
		B() { cout << "B constructor\n"; }
		~B() { cout << "B destructor\n"; }
	};

	class C : public A
	{
		public:
		C() { cout << "C constructor\n"; }
		~C() { cout << "C destructor\n"; }
	};

	int main()
	{
		cout << "Constructors\n";
		C c;
		B b;
		cout << "Destructors\n";
	}

Output:
	Constructors
	A constructor
	C constructor
	A constructor
	B constructor
	Destructors
	B destructor
	A destructor
	C destructor
	A destructor





### Hybrid Inheritance Example

The following example indicates the order of construction and destruction for Hybrid inheritance.

  #include <iostream>

  using namespace std;

  class A
  {
  	public:
  	A() { cout << "A constructor\n"; }
  	~A() { cout << "A destructor\n"; }
  };

  class B : public A
  {
  	public:
  	B() { cout << "B constructor\n"; }
  	~B() { cout << "B destructor\n"; }
  };

  class B2 : public A
  {
  	public:
  	B2() { cout << "B2 constructor\n"; }
  	~B2() { cout << "B2 destructor\n"; }
  };

  class D : public B, public B2
  {
  	public:
  	D() { cout << "D constructor\n"; }
  	~D() { cout << "D destructor\n"; }
  };

  int main()
  {
  	D d;
  }

Output:

  A constructor
  B constructor
  A constructor
  B2 constructor
  D constructor
  D destructor
  B2 destructor
  A destructor
  B destructor
  A destructor

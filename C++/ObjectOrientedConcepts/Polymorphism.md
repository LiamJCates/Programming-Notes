Polymorphism refers to the ability of acquiring many forms. In the context of OOP this means that the same function name denotes many functions that are members of different objects.

Polymorphic code is code you write once and can reuse with different types.
Ultimately, this flexibility yields loosely coupled and highly reusable code. It
eliminates tedious copying and pasting, making your code more maintainable and readable.

C++ offers two polymorphic approaches:
	Compile-time polymorphism incorporates types determined at compile time.
	Runtime polymorphism incorporates types determined at runtime.

Which approach you choose depends on whether you know the types you want to use with your polymorphic code at compile time or at runtime.




Consider the following example:
class Class1 {
public:
	virtual void f() {
		cout << "Function f() in Class1\n";
	}
	void g() {
		cout << "Function g() in Class1\n";
	}
};
class Class2 {
public:
	virtual void f() {
		cout << "Function f() in Class2\n";
	}
	void g() {
		cout << "Function g() in Class2\n";
	}
};

class Class3 {
public:
	virtual void h() {
		cout << "Function h() in Class3\n";
	}
};

int main() {
	Class1 object1, *p;
	Class2 object2;
	Class3 object3;
	p = &object1;
	p->f();
	p->g();
	p = (Class1*) &object2;
	p->f();
	p->g();
	p = (Class1*) &object3;
	p->f(); // possibly abnormal program termination;
	p->g();
	// p->h(); // h() is not a member of Class1;
	return 0;
}

Output:
Function f() in Class1
Function g() in Class1
Function f() in Class2
Function g() in Class1
Function h() in Class3
Function g() in Class1


When p is declared as a pointer to object1 of class type Class1, then the two function members are activated that are defined in Class1.

After p becomes a pointer to object2 of class type Class2, then p->f() activates a function defined in Class2, whereas p->g() activates a function defined in Class1.

How is this possible?
The difference lies in the moment at which a decision is made about the function to be called.

In the case of the so-called static binding, the decision concerning a function to be executed is determined at compilation time.
In the case of dynamic binding, the decision is delayed until run time.

Dynamic Binding
In C++, dynamic binding is enforced by declaring a member function as virtual.

In this way, if a virtual function member is called, then the function chosen for execution depends not on the type of pointer determined by its declaration, but on the type of value the pointer currently has.

In our example, pointer p was declared to be of type Class1*. Therefore, if p points to function g() that is not virtual, then regardless of the place in the program in which the call instruction p->g() occurs, this is always considered a call to the function g() defined in Class1.

This is due to the fact that the compiler makes this decision based on the type declaration of p and the fact that g() is not virtual. For virtual function members the situation drastically changes. This time, the decision is made during run time: if a function
member is virtual, then the system looks at the type of the current pointer value and
invokes the proper function member. After the initial declaration of p as being of type
Class1*, virtual function f() belonging to Class1 is called, whereas after assigning
to p the address of object2 of type Class2, f() belonging to Class2 is called.


Note that after p was assigned the address of object3, it still invokes g()defined in Class1. This is because g() is not redefined in Class3 and g() from
Class1 is called. But an attempt to call p->f() results in a program crash—or gives
a wrong output since the C++ picks the first virtual function in Class3—because f()
is declared virtual in Class1 so the system tries to find, unsuccessfully, in Class3 a
definition of f(). Also, notwithstanding the fact that p points to object3, instruction p->h() results in a compilation error, because the compiler does not find h()
in Class1, where Class1* is still the type of pointer p. To the compiler, it does not
matter that h() is defined in Class3 (be it virtual or not).
Polymorphism is a powerful tool in OOP. It is enough to send a standard message to many different objects without specifying how the message will be processed.
There is no need to know of what type the objects are. The receiver is responsible for
interpreting the message and following it. The sender does not have to modify the
message depending on the type of receiver. There is no need for switch or if-else
statements. Also, new units can be added to a complex program without needing to
recompile the entire program.

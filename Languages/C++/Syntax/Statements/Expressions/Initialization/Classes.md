
Unlike fundamental types and PODs, fully featured classes are always initialized. In other words, one of a fully featured class’s constructors always gets called during initialization.

Which constructor is called depends on the arguments given during initialization.

	#include <cstdio>

	struct Taxonomist {
		Taxonomist() {
			printf("(no argument)\n");
		}
		Taxonomist(char x) {
			printf("char: %c\n", x);
		}
		Taxonomist(int x) {
			printf("int: %d\n", x);
		}
		Taxonomist(float x) {
			printf("float: %f\n", x);
		}
	};

The Taxonomist class has four constructors. If you supply no argument, the constructor with no arguments gets called. If you supply a char, int, or float during initialization, the corresponding constructor gets called. In each case, the constructor alerts you with a printf
statement.

	#include <cstdio>

	struct Taxonomist {
		--snip--
	};
	int main() {
		Taxonomist t1;
		Taxonomist t2{ 'c' };
		Taxonomist t3{ 65537 };
		Taxonomist t4{ 6.02e23f };
		Taxonomist t5('g');
		Taxonomist t6 = { 'l' };
		Taxonomist t7{};
		Taxonomist t8();
	}

Without any braces or parentheses, the no argument constructor gets called.

Unlike with POD and fundamental types, you can rely on this initialization no matter where you’ve declared the object. With braced initializers, the char, int, and float constructors get called as expected. You can also use parentheses and the equals-plus-braces syntaxes; these invoke the expected constructors.

Although fully featured classes always get initialized, some programmers like the uniformity of using the same initialization syntax for all objects. This is no problem with braced initializers; the default constructor gets invoked as expected.

Unfortunately, using parentheses causes some surprising behavior:

	Taxonomist t8();

In the example above, this preceding statement generates no output.

This initialization looks like a function declaration, and that’s because it is. Because of some arcane language-parsing rules, what you’ve declared to the compiler is that a yet-to-be-defined function t8 takes no arguments and returns an object of type Taxonomist. This is because you can provide a function declaration that defines a function’s modifiers, name, arguments, and return type and then later provide the body in its definition.



### Initializing Class Members

You can use braced initializers to initialize the members of classes

struct JohanVanDerSmut {
  bool bool_value = true;
  int int_value{ 1234 };
  char char_array[8] = { "a string" };
};

It’s not possible to use parentheses to initialize member variables.

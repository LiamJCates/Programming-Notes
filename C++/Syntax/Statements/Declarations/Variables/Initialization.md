## initialization
In C++, there are three ways to initialize variables. They are all equivalent and are reminiscent of the evolution of the language over the years:


### c-like initialization
The first one, known as c-like initialization (because it is inherited from the C language), consists of appending an equal sign followed by the value to which the variable is initialized:

  type identifier = initial_value;

For example, to declare a variable of type int called x and initialize it to a value of zero from the same moment it is declared, we can write:

  int x = 0;



### constructor initialization
A second method, known as constructor initialization (introduced by the C++ language), encloses the initial value between parentheses (()):

  type identifier (initial_value);

For example:

  int x (0);



### uniform initialization
Finally, a third method, known as uniform initialization, similar to the above, but using curly braces ({}) instead of parentheses (this was introduced by the revision of the C++ standard, in 2011):

  type identifier {initial_value};

For example:

  int x {0};


All three ways of initializing variables are valid and equivalent in C++.


If in doubt, use the general {}-list form as it saves you from conversions that lose information:
int i1 = 7.8; // i1 becomes 7 (surprise?)
int i2 {7.8}; // error : floating-point to integer conversion not allowed

Unfortunately, conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied when you use = (but not when you use {}).

The problems caused by implicit narrowing conversions are a price paid for C compatibility (§16.3).

A constant (§1.6) cannot be left uninitialized and a variable should only be left uninitialized in extremely rare circumstances. Don’t introduce a name until you have a suitable value for it.

Userdefined types (such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be implicitly initialized (§4.2.1).



https://en.cppreference.com/w/cpp/language/initialization


## Object Initialization
Object initialization, or simply initialization, is how you bring objects to life. Unfortunately, object initialization syntax is complicated. Fortunately, the initialization process is straightforward.

### Initializing a Fundamental Type to Zero
Let’s start by initializing an object of fundamental type to zero. There are
four ways to do so:
int a = 0; // Initialized to 0
int b{}; // Initialized to 0
int c = {}; // Initialized to 0
int d; // Initialized to 0 (maybe)

Three of these are reliable: explicitly set the value using a literal, use braces {}, or use the equals-plus-braces approach = {}. Declaring the object with no extra notation is unreliable; it works only in certain situations. Even if you know what these situations are, you should avoid relying on this behavior because it sows confusion.

Using braces {} to initialize a variable is, unsurprisingly, called braced initialization. Part of the reason C++ initialization syntax is such a mess is that the language grew out of C, where object life cycles are primitive, into a language with a robust and featureful object life cycle. Language designers incorporated braced initialization into modern C++ to help smooth over the sharp corners this has caused in the initialization syntax. In short, no matter the object’s scope or type, braced initialization is always applicable, whereas the other notations are not.

### Initializing a Fundamental Type to an Arbitrary Value
Initializing to an arbitrary value is similar to initializing a fundamental type to zero:
int e = 42;       // Initialized to 42
int f{ 42 };      // Initialized to 42
int g = { 42 };   // Initialized to 42
int h(42);        // Initialized to 42

There are four ways: equals, braced initialization, equals-plus braces initialization, and parentheses. All of these produce identical
code.

### Initializing PODs
The notation for initializing a POD mostly follows fundamental types.

#include <cstdint>
struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
};
int main() {
  PodStruct initialized_pod1{}; // All fields zeroed
  PodStruct initialized_pod2 = {}; // All fields zeroed
  PodStruct initialized_pod3{ 42, "Hello" }; // Fields a & b set; c = 0
  PodStruct initialized_pod4{ 42, "Hello", true }; // All fields set
}

Initializing a POD object to zero is similar to initializing objects of fundamental types to zero. The braces and equals-plus-braces approaches produce the same code: fields initialize to zero.

NOTE
You cannot use the equals-zero approach with PODs. The following will not compile because it’s expressly forbidden in the language rules:

PodStruct initialized_pod = 0;


### Initializing PODs to Arbitrary Values
You can initialize fields to arbitrary values using braced initializers. The arguments within braced initializers must match types with POD members. The order of arguments from left to right matches the order of members from top to bottom. Any omitted members are zeroed. Members a and b initialize to 42 and Hello after the initialization of initialized_pod3, and c is zeroed (set to false) because you omitted it from the braced initialization.
The initialization of initialized_pod4 includes an argument for c (true), so its value is set to true after initialization.

The equals-plus-braces initialization works identically:
PodStruct initialized_pod4 = { 42, "Hello", true };

You can only omit fields from right to left, so the following won’t compile:
PodStruct initialized_pod4 = { 42, true };

You cannot use parentheses to initialize PODs. The following will not compile:
PodStruct initialized_pod(42, "Hello", true);




Initializing Arrays
You initialize arrays like PODs. The main difference between array and
POD declarations is that arrays specify length. Recall that this argument
goes in square brackets [].
When you use braced initializers to initialize arrays, the length argument becomes optional; the compiler can infer the size argument from the number of braced initializer arguments.

int main() {
  int array_1[]{ 1, 2, 3 }; // Array of length 3; 1, 2, 3
  int array_2[5]{}; // Array of length 5; 0, 0, 0, 0, 0
  int array_3[5]{ 1, 2, 3 }; // Array of length 5; 1, 2, 3, 0, 0
  int array_4[5]; // Array of length 5; uninitialized values
}

The array array_1 has length three, and its elements equal 1, 2, and 3.
The array array_2 has length five because you specified a length argument. The braced initializer is empty, so all five elements initialize to zero.
The array array_3 also has length five, but the braced initializer is not empty. It contains three elements, so the remaining two elements initialize to zero.
The array array_4 has no braced initializer, so it contains uninitialized objects.



Fully Featured Classes
Unlike fundamental types and PODs, fully featured classes are always initialized. In other words, one of a fully featured class’s constructors always gets
called during initialization. Which constructor is called depends on the
arguments given during initialization.

#include <cstdio>
struct Taxonomist {
Taxonomist() { u
printf("(no argument)\n");
}
Taxonomist(char x) { v
printf("char: %c\n", x);
}
Taxonomist(int x) { w
printf("int: %d\n", x);
}
Taxonomist(float x) { x
printf("float: %f\n", x);
}
};

The Taxonomist class has four constructors. If you supply no argument,
the constructor with no arguments gets called. If you supply a char, int, or float during initialization, the corresponding constructor gets called. In each case, the constructor alerts you with a printf
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

Without any braces or parentheses, the no argument constructor gets
called. Unlike with POD and fundamental types, you can rely on this initialization no matter where you’ve declared the object. With braced initializers, the char, int, and float constructors get called as expected. You can also use parentheses and the equals-plus-braces syntaxes; these invoke the expected constructors.

Although fully featured classes always get initialized, some programmers like the uniformity of using the same initialization syntax for all objects. This is no problem with braced initializers; the default constructor gets invoked as expected.

Unfortunately, using parentheses causes some surprising behavior.
You get no output.
This initialization looks like a function declaration, and that’s because it is. Because of some arcane language-parsing rules, what you’ve declared to the compiler is that a yet-to-be-defined function t8 takes no arguments and returns an object of type Taxonomist. This is because you can provide a function declaration that defines a
function’s modifiers, name, arguments, and return type and then later provide the body in its definition.

Narrowing Conversions
Braced initialization will generate warnings whenever implicit narrowing
conversions are encountered. This is a nice feature that can save you from
nasty bugs. Consider the following example:
float a{ 1 };
float b{ 2 };
int narrowed_result(a/b); u // Potentially nasty narrowing conversion
int result{ a/b }; v // Compiler generates warning

Dividing two float literals yields a float. When initializing narrowed_result, the compiler silently narrows the result of a/b (0.5) to 0 because you’ve used parentheses ( ) to initialize. When you use braced initializers, the compiler generates a warning.

Initializing Class Members
You can use braced initializers to initialize the members of classes

struct JohanVanDerSmut {
  bool bool_value = true;
  int int_value{ 1234 };
  char char_array[8] = { "a string" };
};

It’s not possible to use parentheses to initialize member variables.


NOTE
As a general rule to make initialization simple: use braced
initializers, everywhere.

Braced initializers work as intended almost everywhere, and they cause the fewest surprises. For this reason, braced initialization is also called uniform initialization.

## initialization
In C++, there are three ways to initialize variables. They are all equivalent and are reminiscent of the evolution of the language over the years:



### copy initialization
copy initialization consists of appending an equal sign followed by the value to which the variable is initialized:

  type identifier = initial_value;

Much like copy assignment, this copies the value on the right-hand side of the equals to the variable being created on the left-hand side.

For example, to declare a variable of type int called x and initialize it to a value of zero from the same moment it is declared, we can write:

  int x = 0;

Also known as c-like initialization because it is inherited from the C language.



### constructor initialization
A second method, known as constructor initialization (introduced by the C++ language), encloses the initial value between parentheses (()):

  type identifier (initial_value);

For example:

  int x (0);

For simple data types (like integers), copy and direct initialization are essentially the same.



### list initialization
Unfortunately, parenthesis-based direct initialization can’t be used for all types of initialization (such as initializing an object with a list of data). To provide a more consistent initialization mechanism, there’s list initialization (also sometimes called uniform initialization or brace initialization).

List initialization is similar to direct initialization, but using curly braces ({}) instead of parentheses (this was introduced by the revision of the C++ standard, in 2011). There are two forms:

  type identifier {initial_value};    //direct list initialization
  type identifier = {initial_value};  //copy list initialization

These two forms function almost identically, but the direct form is generally preferred.

For example:

  int x {0};
  int x = {0};

Initializing a variable with empty braces indicates value initialization. Value initialization generally initializes the variable to zero (or empty, if that’s more appropriate for a given type).

  type identifier {};




### Initialization Method Selection
List initialization has the added benefit of disallowing “narrowing” conversions, conversions that lose information. This means that if you try to use list initialization to initialize a variable with a value it can not safely hold, the compiler will throw a warning or an error.

If in doubt, use list initialization:
int i1 = 7.8; // i1 becomes 7 (surprise?)
int i2 {7.8}; // error : floating-point to integer conversion not allowed

Unfortunately, conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied when you use other forms of initialization.

The problems caused by implicit narrowing conversions are a price paid for C compatibility (§16.3).

A constant (§1.6) cannot be left uninitialized and a variable should only be left uninitialized in extremely rare circumstances. Don’t introduce a name until you have a suitable value for it.

Userdefined types (such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be implicitly initialized (§4.2.1).



### Initializing multiple variables

It is possible to define multiple variables of the same type in a single statement by separating the names with a comma:

int a, b;

While the best practice is to avoid this syntax altogether. However, you may encounter other code that uses this style.

You can initialize multiple variables defined on the same line:

  int a = 5, b = 6; // copy initialization
  int c( 7 ), d( 8 ); // direct initialization
  int e{ 9 }, f{ 10 }; // list initialization (preferred)

Unfortunately, there’s a common pitfall here that can occur when the programmer mistakenly tries to initialize both variables by using one initialization statement:

  int a, b = 5; // wrong (a is not initialized!)
  int a = 5, b = 5; // correct

In the top statement, variable “a” will be left uninitialized, and the compiler may or may not complain. If it doesn’t, this is a great way to have your program intermittently crash and produce sporadic results. We’ll talk more about what happens if you use uninitialized variables shortly.

The best way to remember that this is wrong is to consider the case of direct initialization or list initialization:

int a, b( 5 );
int c, d{ 5 };

This makes it seem a little more clear that the value 5 is only being used to initialize variable b or d, not a or c.




Uninitialized variables

Unlike some programming languages, C/C++ does not initialize most variables to a given value (such as zero) automatically. Thus when a variable is assigned a memory location by the compiler, the default value of that variable is whatever (garbage) value happens to already be in that memory location! A variable that has not been given a known value (usually through initialization or assignment) is called an uninitialized variable.

Initialization means the object was provided with an initial value at the point of definition. Uninitialized means the object has not been given a known value (through any means, including assignment). Therefore, an object that is not initialized but is then assigned a value is no longer uninitialized (because it has been given a known value).

To recap:

   Initialization = The object is given a known value at the point of definition.
   Assignment = The object is given a known value beyond the point of definition.
   Uninitialized = The object has not been given a known value yet.


Using the values of uninitialized variables can lead to unexpected results. Most modern compilers will attempt to detect if a variable is being used without being given a value. If they are able to detect this, they will generally issue a compile-time error.

Undefined behavior

Using the value from an uninitialized variable is our first example of undefined behavior. Undefined behavior (often abbreviated UB) is the result of executing code whose behavior is not well defined by the C++ language. In this case, the C++ language doesn’t have any rules determining what happens if you use the value of a variable that has not been given a known value. Consequently, if you actually do this, undefined behavior will result.

Code implementing undefined behavior may exhibit any of the following symptoms:

    Your program produces different results every time it is run.
    Your program consistently produces the same incorrect result.
    Your program behaves inconsistently (sometimes produces the correct result, sometimes not).
    Your program seems like its working but produces incorrect results later in the program.
    Your program crashes, either immediately or later.
    Your program works on some compilers but not others.
    Your program works until you change some other seemingly unrelated code.

Or, your code may actually produce the correct behavior anyway. The nature of undefined behavior is that you never quite know what you’re going to get, whether you’ll get it every time, and whether that behavior will change when you make other changes.

C++ contains many cases that can result in undefined behavior if you’re not careful.



https://en.cppreference.com/w/cpp/language/initialization


## Object Initialization
Object initialization, or simply initialization, is how you bring objects to life. Unfortunately, object initialization syntax is complicated. Fortunately, the initialization process is straightforward.

Part of the reason C++ initialization syntax is such a mess is that the language grew out of C, where object life cycles are primitive, into a language with a robust and featureful object life cycle. Language designers incorporated braced initialization into modern C++ to help smooth over the sharp corners this has caused in the initialization syntax. In short, no matter the object’s scope or type, braced initialization is always applicable, whereas the other notations are not.


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

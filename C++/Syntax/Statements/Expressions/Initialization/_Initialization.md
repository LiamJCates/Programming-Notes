## initialization
The initial value may be provided in the initializer section of a declarator or  new expression. It also takes place during function calls: function parameters and the function return values are also initialized.

For each declarator, the initializer may be one of the following:


In C++, there are three ways to initialize variables. They are a result of the language's  evolution and are all equivalent:

  Copy Initialization
  Constructor Initialization
  List Initialization



### copy initialization

copy initialization consists of appending an equal sign followed by the value to which the variable is initialized:

  type identifier = initial_value;

Much like copy assignment, this copies the value on the right-hand side of the equals to the variable being created on the left-hand side.

For example, to declare a variable of type int called x and initialize it to a value of zero from the same moment it is declared, we can write:

  int x = 0;

Also known as c-like initialization because it is inherited from the C language.



### constructor initialization

A second method, known as constructor initialization, encloses the initial value between parentheses, ():

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



### Narrowing Conversions

Braced initialization will generate warnings whenever implicit narrowing conversions are encountered. This is a nice feature that can save you from nasty bugs. Consider the following example:

  float a{ 1 };
  float b{ 2 };
  int narrowed_result(a/b); // Potentially nasty narrowing conversion
  int result{ a/b }; // Compiler generates warning

Dividing two float literals yields a float. When initializing narrowed_result, the compiler silently narrows the result of a/b (0.5) to 0 because you’ve used parentheses ( ) to initialize. When you use braced initializers, the compiler generates a warning.



### Initialization Method Selection

Language designers incorporated list or braced initialization into modern C++ to help smooth over the sharp corners this has caused in the initialization syntax. In short, no matter the object’s scope or type, braced initialization is always applicable, whereas the other notations are not.

List initialization has the added benefit of disallowing “narrowing” conversions, conversions that lose information. This means that if you try to use list initialization to initialize a variable with a value it can not safely hold, the compiler will throw a warning or an error.

If in doubt, use list initialization:

  int i1 = 7.8; // i1 becomes 7 (surprise?)
  int i2 {7.8}; // error : floating-point to integer conversion not allowed

Unfortunately, conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied when you use other forms of initialization.

The problems caused by implicit narrowing conversions are a price paid for C compatibility.

A constant cannot be left uninitialized and a variable should only be left uninitialized in extremely rare circumstances. Don’t introduce a name until you have a suitable value for it.



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




### Uninitialized variables

Unlike some programming languages, C/C++ does not initialize most variables to a given value (such as zero) automatically. Thus when a variable is assigned a memory location by the compiler, the default value of that variable is whatever (garbage) value happens to already be in that memory location! A variable that has not been given a known value (usually through initialization or assignment) is called an uninitialized variable.

Initialization means the object was provided with an initial value at the point of definition. Uninitialized means the object has not been given a known value (through any means, including assignment). Therefore, an object that is not initialized but is then assigned a value is no longer uninitialized (because it has been given a known value).

To recap:

   Initialization = The object is given a known value at the point of definition.
   Assignment = The object is given a known value beyond the point of definition.
   Uninitialized = The object has not been given a known value yet.


Using the values of uninitialized variables can lead to unexpected results. Most modern compilers will attempt to detect if a variable is being used without being given a value. If they are able to detect this, they will generally issue a compile-time error.



### Undefined behavior

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

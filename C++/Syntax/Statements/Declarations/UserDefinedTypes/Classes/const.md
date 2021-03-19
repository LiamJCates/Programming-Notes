the const keyword can be used for a number of purposes throughout the declaration of a class.

You
may want to create a local const in a class to use inside constant
expressions that will be evaluated at compile time. However, the
meaning of const is different inside classes, so you must
understand the options in order to create const data members of a
class.

You can also make an entire object const. But
preserving the constness of an object is more complex. The
compiler can ensure the constness of a built-in type but it cannot
monitor the intricacies of a class. To guarantee the constness of a
class object, the const member function is introduced: only a const
member function may be called for a const object.


The use of const inside a class means
“This is constant for the lifetime of the object.” However, each
different object may contain a different value for that constant.
Thus, when you create an ordinary (non-static) const inside a class,
you cannot give it an initial value. This initialization must occur in
the constructor, of course, but in a special place in the constructor.
Because a const must be initialized at the point it is created, inside
the main body of the constructor the const must already be
initialized. Otherwise you’re left with the choice of waiting until
some point later in the constructor body, which means the const
would be un-initialized for a while. Also, there would be nothing to
keep you from changing the value of the const at various places in
the constructor body.



The constructor initializer list
The special initialization point is called the constructor initializer list,
and it was originally developed for use in inheritance (covered in
Chapter 14). The constructor initializer list – which, as the name
implies, occurs only in the definition of the constructor – is a list of
“constructor calls” that occur after the function argument list and a8: Constants 375
colon, but before the opening brace of the constructor body. This is
to remind you that the initialization in the list occurs before any of
the main constructor code is executed. This is the place to put all
const initializations. The proper form for const inside a class is
shown here:
//: C08:ConstInitialization.cpp
// Initializing const in classes
#include <iostream>
using namespace std;
class Fred {
const int size;
public:
Fred(int sz);
void print();
};
Fred::Fred(int sz) : size(sz) {}
void Fred::print() { cout << size << endl; }
int main() {
Fred a(1), b(2), c(3);
a.print(), b.print(), c.print();
} ///:~
The form of the constructor initializer list shown above is confusing
at first because you’re not used to seeing a built-in type treated as if
it has a constructor.



### const Member Variables
You can mark member variables const by adding the keyword to the member’s type. The const member variables cannot be modified after their initialization.

struct Avout {
  const char* name = "Erasmas";
};

The name member is const, meaning the pointed-to value cannot be modified. On the other hand, apert is not const.

Sometimes you want the safety of marking a member variable const but would also like to initialize the member with arguments passed into a constructor. For this, you employ member initializer lists.

struct Avout {
  Avout(const char* name, long year_of_apert)
  : name{ name }, apert{ year_of_apert } {
  }  

  const char* name;
};





### Constant Objects

When an object of a class is qualified as a const object:

  const MyClass myobject;

The access to its data members from outside the class is restricted to read-only, as if all its data members were const for those accessing them from outside the class. Note though, that the constructor is still called and is allowed to initialize and modify these data members:

  // constructor on const object
  #include <iostream>
  using namespace std;

  class MyClass {
    public:
      int x;
      MyClass(int val) : x(val) {}
      int get() {return x;}
  };

  int main() {
    const MyClass foo(10);
  // foo.x = 20;            // not valid: x cannot be modified
    cout << foo.x << '\n';  // ok: data member x can be read
    return 0;
  }

The member functions of a const object can only be called if they are themselves specified as const members; in the example above, member get (which is not specified as const) cannot be called from foo. To specify that a member is a const member, the const keyword shall follow the function prototype, after the closing parenthesis for its parameters:

  int get() const {return x;}

Note that const can be used to qualify the type returned by a member function. This const is not the same as the one which specifies a member as const. Both are independent and are located at different places in the function prototype:

  int get() const {return x;}        // const member function
  const int& get() {return x;}       // member function returning a const&
  const int& get() const {return x;} // const member function returning a const&

Member functions specified to be const cannot modify non-static data members nor call other non-const member functions. In essence, const members shall not modify the state of an object.

const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access both const and non-const member functions alike.

You may think that anyway you are seldom going to declare const objects, and thus marking all members that don't modify the object as const is not worth the effort, but const objects are actually very common. Most functions taking classes as parameters actually take them by const reference, and thus, these functions can only access their const members:

  // const objects
  #include <iostream>
  using namespace std;

  class MyClass {
      int x;
    public:
      MyClass(int val) : x(val) {}
      const int& get() const {return x;}
  };

  void print (const MyClass& arg) {
    cout << arg.get() << '\n';
  }

  int main() {
    MyClass foo (10);
    print(foo);

    return 0;
  }


If in this example, get was not specified as a const member, the call to arg.get() in the print function would not be possible, because const objects only have access to const member functions.

Member functions can be overloaded on their constness: i.e., a class may have two member functions with identical signatures except that one is const and the other is not: in this case, the const version is called only when the object is itself const, and the non-const version is called when the object is itself non-const.

  // overloading members on constness
  #include <iostream>
  using namespace std;

  class MyClass {
      int x;
    public:
      MyClass(int val) : x(val) {}
      const int& get() const {return x;}
      int& get() {return x;}
  };

  int main() {
    MyClass foo (10);
    const MyClass bar (20);
    foo.get() = 15;         // ok: get() returns int&
  // bar.get() = 25;        // not valid: get() returns const int&
    cout << foo.get() << '\n';
    cout << bar.get() << '\n';

    return 0;
  }
















const objects & member functions
Class member functions can be made const. What does this mean?
To understand, you must first grasp the concept of const objects.
A const object is defined the same for a user-defined type as a builtin type. For example:
const int i = 1;
const blob b(2);8: Constants 381
Here, b is a const object of type blob. Its constructor is called with
an argument of two. For the compiler to enforce constness, it must
ensure that no data members of the object are changed during the
object’s lifetime. It can easily ensure that no public data is modified,
but how is it to know which member functions will change the data
and which ones are “safe” for a const object?
If you declare a member function const, you tell the compiler the
function can be called for a const object. A member function that is
not specifically declared const is treated as one that will modify
data members in an object, and the compiler will not allow you to
call it for a const object.
It doesn’t stop there, however. Just claiming a member function is
const doesn’t guarantee it will act that way, so the compiler forces
you to reiterate the const specification when defining the function.
(The const becomes part of the function signature, so both the
compiler and linker check for constness.) Then it enforces constness
during the function definition by issuing an error message if you
try to change any members of the object or call a non-const member
function. Thus, any member function you declare const is
guaranteed to behave that way in the definition.
To understand the syntax for declaring const member functions,
first notice that preceding the function declaration with const
means the return value is const, so that doesn’t produce the desired
results. Instead, you must place the const specifier after the
argument list. For example,
//: C08:ConstMember.cpp
class X {
int i;
public:
X(int ii);
int f() const;
};
X::X(int ii) : i(ii) {}
int X::f() const { return i; }382 Thinking in C++ www.BruceEckel.com
int main() {
X x1(10);
const X x2(20);
x1.f();
x2.f();
} ///:~
Note that the const keyword must be repeated in the definition or
the compiler sees it as a different function. Since f( ) is a const
member function, if it attempts to change i in any way or to call
another member function that is not const, the compiler flags it as
an error.
You can see that a const member function is safe to call with both
const and non-const objects. Thus, you could think of it as the most
general form of a member function (and because of this, it is
unfortunate that member functions do not automatically default to
const). Any function that doesn’t modify member data should be
declared as const, so it can be used with const objects.
Here’s an example that contrasts a const and non-const member
function:
//: C08:Quoter.cpp
// Random quote selection
#include <iostream>
#include <cstdlib> // Random number generator
#include <ctime> // To seed random generator
using namespace std;
class Quoter {
int lastquote;
public:
Quoter();
int lastQuote() const;
const char* quote();
};
Quoter::Quoter(){
lastquote = -1;
srand(time(0)); // Seed random number generator8: Constants 38



mutable: bitwise vs. logical const
What if you want to create a const member function, but you’d still
like to change some of the data in the object? This is sometimes
referred to as the difference between bitwise const and logical const
(also sometimes called memberwise const). Bitwise const means that
every bit in the object is permanent, so a bit image of the object will
never change. Logical const means that, although the entire object
is conceptually constant, there may be changes on a member-bymember basis. However, if the compiler is told that an object is
const, it will jealously guard that object to ensure bitwise constness.
To effect logical constness, there are two ways to change a data
member from within a const member function.
The first approach is the historical one and is called casting away
constness. It is performed in a rather odd fashion. You take this (the
keyword that produces the address of the current object) and cast it
to a pointer to an object of the current type. It would seem that this
is already such a pointer. However, inside a const member function
it’s actually a const pointer, so by casting it to an ordinary pointer,
you remove the constness for that operation. Here’s an example:
//: C08:Castaway.cpp
// "Casting away" constness
class Y {
int i;
public:
Y();
void f() const;
};
Y::Y() { i = 0; }
void Y::f() const {
//! i++; // Error -- const member function
((Y*)this)->i++; // OK: cast away const-ness
// Better: use C++ explicit cast syntax:
(const_cast<Y*>(this))->i++;
}8: Constants 385
int main() {
const Y yy;
yy.f(); // Actually changes it!
} ///:~
This approach works and you’ll see it used in legacy code, but it is
not the preferred technique. The problem is that this lack of
constness is hidden away in a member function definition, and you
have no clue from the class interface that the data of the object is
actually being modified unless you have access to the source code
(and you must suspect that constness is being cast away, and look
for the cast). To put everything out in the open, you should use the
mutablekeyword in the class declaration to specify that a
particular data member may be changed inside a const object:
//: C08:Mutable.cpp
// The "mutable" keyword
class Z {
int i;
mutable int j;
public:
Z();
void f() const;
};
Z::Z() : i(0), j(0) {}
void Z::f() const {
//! i++; // Error -- const member function
j++; // OK: mutable
}
int main() {
const Z zz;
zz.f(); // Actually changes it!
} ///:~
This way, the user of the class can see from the declaration which
members are likely to be modified in a const member function.386 Thinking in C++ www.BruceEckel.com
ROMability
If an object is defined as const, it is a candidate to be placed in readonly memory (ROM), which is often an important consideration in
embedded systems programming. Simply making an object const,
however, is not enough – the requirements for ROMability are
much stricter. Of course, the object must be bitwise-const, rather
than logical-const. This is easy to see if logical constness is
implemented only through the mutablekeyword, but probably not
detectable by the compiler if constness is cast away inside a const
member function. In addition,
1. The class or structmust have no user-defined constructors or
destructor.
2. There can be no base classes (covered in Chapter 14) or
member objects with user-defined constructors or
destructors.
The effect of a write operation on any part of a const object of a
ROMable type is undefined. Although a suitably formed object
may be placed in ROM, no objects are ever required to be placed in
ROM.







Const class objects and member functions

Fundamental data types (int, double, char, etc…) can be made const via the const keyword, and that all const variables must be initialized at time of creation.

In the case of const fundamental data types, initialization can be done through copy, direct, or uniform initialization:

```cpp
const int value1 = 5; // copy initialization
const int value2(7); // direct initialization
const int value3 { 9 }; // uniform initialization (C++11)
```

### Const classes

Similarly, instantiated class objects can also be made const by using the const keyword. Initialization is done via class constructors:

```cpp
const Date date1;
// initialize using default constructor

const Date date2(2020, 10, 16);
// initialize using parameterized constructor

const Date date3 { 2020, 10, 16 };
// initialize using parameterized constructor (C++11)
```

Once a const class object has been initialized via constructor, any attempt to modify the member variables of the object is disallowed, as it would violate the const-ness of the object. This includes both changing member variables directly (if they are public), or calling member functions that set the value of member variables. Consider the following class:

```cpp
class Something
{
public:
    int m_value;

    Something(): m_value{0} { }

    void setValue(int value) { m_value = value; }
    int getValue() { return m_value ; }
};

int main()
{
    const Something something{}; // calls default constructor

    something.m_value = 5; // compiler error: violates const
    something.setValue(5); // compiler error: violates const

    return 0;
}
```

Both of the above lines involving variable something are illegal because they violate the constness of something by either attempting to change a member variable directly, or by calling a member function that attempts to change a member variable.

Just like with normal variables, you’ll generally want to make your class objects const when you need to ensure they aren’t modified after creation.




### Const member functions

Now, consider the following line of code:

  std::cout << something.getValue();

Perhaps surprisingly, this will also cause a compile error, even though getValue() doesn’t do anything to change a member variable! It turns out that const class objects can only explicitly call const member functions, and getValue() has not been marked as a const member function.

A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object).

To make getValue() a const member function, we simply append the const keyword to the function prototype, after the parameter list, but before the function body:

```cpp
class Something
{
public:
    int m_value;

    Something(): m_value{0} { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const { return m_value; } // note addition of const keyword after parameter list, but before function body
};
```

Now getValue() has been made a const member function, which means we can call it on any const objects.

For member functions defined outside of the class definition, the const keyword must be used on both the function prototype in the class definition and on the function definition:

```cpp
class Something
{
public:
    int m_value;

    Something(): m_value{0} { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const; // note addition of const keyword here
};

int Something::getValue() const // and here
{
    return m_value;
}
```

Futhermore, any const member function that attempts to change a member variable or call a non-const member function will cause a compiler error to occur. For example:

```cpp
class Something
{
public:
    int m_value ;

    void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
};
```

In this example, resetValue() has been marked as a const member function, but it attempts to change m_value. This will cause a compiler error.

Note that constructors cannot be marked as const. This is because constructors need to be able to initialize their member variables, and a const constructor would not be able to do so. Consequently, the language disallows const constructors.

Rule

Make any member function that does not modify the state of the class object const, so that it can be called by const objects.



### Const references

Although instantiating const class objects is one way to create const objects, a more common way is by passing an object to a function by const reference.

In the lesson on passing arguments by reference, we covered the merits of passing class arguments by const reference instead of by value. To recap, passing a class argument by value causes a copy of the class to be made (which is slow) -- most of the time, we don’t need a copy, a reference to the original argument works just fine, and is more performant because it avoids the needless copy. We typically make the reference const in order to ensure the function does not inadvertently change the argument, and to allow the function to work with R-values (e.g. literals), which can be passed as const references, but not non-const references.

Can you figure out what’s wrong with the following code?

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40

#include <iostream>

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }
};

// note: We're passing date by const reference here to avoid making a copy of date
void printDate(const Date &date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int main()
{
    Date date{2016, 10, 16};
    printDate(date);

    return 0;
}

The answer is that inside of the printDate function, date is treated as a const object. And with that const date, we’re calling functions getYear(), getMonth(), and getDay(), which are all non-const. Since we can’t call non-const member functions on const objects, this will cause a compile error.

The fix is simple: make getYear(), getMonth(), and getDay() const:


class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    // setDate() cannot be const, modifies member variables
    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    // The following getters can all be made const
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

Now in function printDate(), const date will be able to successfully call getYear(), getMonth(), and getDay().

Overloading const and non-const function

Finally, although it is not done very often, it is possible to overload a function in such a way to have a const and non-const version of the same function:

#include <string>

class Something
{
private:
    std::string m_value;

public:
    Something(const std::string &value=""): m_value{ value } {}

    const std::string& getValue() const { return m_value; } // getValue() for const objects
    std::string& getValue() { return m_value; } // getValue() for non-const objects
};

The const version of the function will be called on any const objects, and the non-const version will be called on any non-const objects:

1
2
3
4
5
6
7
8
9
10

int main()
{
	Something something{};
	something.getValue() = "Hi"; // calls non-const getValue();

	const Something something2{};
	something2.getValue(); // calls const getValue();

	return 0;
}

Overloading a function with a const and non-const version is typically done when the return value needs to differ in constness. In the example above, the non-const version of getValue() will only work with non-const objects, but is more flexible in that we can use it to both read and write m_value (which we do by assigning the string “Hi”).

The const version of getValue() will work with either const or non-const objects, but returns a const reference, to ensure we can’t modify the const object’s data.

This works because the const-ness of the function is considered part of the function’s signature, so a const and non-const function which differ only in const-ness are considered distinct.

Summary

Because passing objects by const reference is common, your classes should be const-friendly. That means making any member function that does not modify the state of the class object const!

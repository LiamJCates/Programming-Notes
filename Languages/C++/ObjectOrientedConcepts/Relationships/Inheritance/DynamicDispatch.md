Dynamic Dispatch

The virtual table

To implement virtual functions, C++ uses a special form of late binding known as the virtual table. The virtual table is a lookup table of functions used to resolve function calls in a dynamic/late binding manner. The virtual table sometimes goes by other names, such as “vtable”, “virtual function table”, “virtual method table”, or “dispatch table”.

Because knowing how the virtual table works is not necessary to use virtual functions, this section can be considered optional reading.

The virtual table is actually quite simple, though it’s a little complex to describe in words. First, every class that uses virtual functions (or is derived from a class that uses virtual functions) is given its own virtual table. This table is simply a static array that the compiler sets up at compile time. A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.

Second, the compiler also adds a hidden pointer to the base class, which we will call *__vptr. *__vptr is set (automatically) when a class instance is created so that it points to the virtual table for that class. Unlike the *this pointer, which is actually a function parameter used by the compiler to resolve self-references, *__vptr is a real pointer. Consequently, it makes each class object allocated bigger by the size of one pointer. It also means that *__vptr is inherited by derived classes, which is important.

By now, you’re probably confused as to how these things all fit together, so let’s take a look at a simple example:

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

class Base
{
public:
   virtual void function1() {};
   virtual void function2() {};
};

class D1: public Base
{
public:
   virtual void function1() {};
};

class D2: public Base
{
public:
   virtual void function2() {};
};

Because there are 3 classes here, the compiler will set up 3 virtual tables: one for Base, one for D1, and one for D2.

The compiler also adds a hidden pointer to the most base class that uses virtual functions. Although the compiler does this automatically, we’ll put it in the next example just to show where it’s added:

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

class Base
{
public:
   FunctionPointer *__vptr;
   virtual void function1() {};
   virtual void function2() {};
};

class D1: public Base
{
public:
   virtual void function1() {};
};

class D2: public Base
{
public:
   virtual void function2() {};
};

When a class object is created, *__vptr is set to point to the virtual table for that class. For example, when an object of type Base is created, *__vptr is set to point to the virtual table for Base. When objects of type D1 or D2 are constructed, *__vptr is set to point to the virtual table for D1 or D2 respectively.

Now, let’s talk about how these virtual tables are filled out. Because there are only two virtual functions here, each virtual table will have two entries (one for function1() and one for function2()). Remember that when these virtual tables are filled out, each entry is filled out with the most-derived function an object of that class type can call.

The virtual table for Base objects is simple. An object of type Base can only access the members of Base. Base has no access to D1 or D2 functions. Consequently, the entry for function1 points to Base::function1() and the entry for function2 points to Base::function2().

The virtual table for D1 is slightly more complex. An object of type D1 can access members of both D1 and Base. However, D1 has overridden function1(), making D1::function1() more derived than Base::function1(). Consequently, the entry for function1 points to D1::function1(). D1 hasn’t overridden function2(), so the entry for function2 will point to Base::function2().

The virtual table for D2 is similar to D1, except the entry for function1 points to Base::function1(), and the entry for function2 points to D2::function2().

So consider what happens when we create an object of type D1:

1
2
3
4

int main()
{
    D1 d1;
}

Because d1 is a D1 object, d1 has its *__vptr set to the D1 virtual table.

Now, let’s set a base pointer to D1:

1
2
3
4
5
6
7

int main()
{
    D1 d1;
    Base *dPtr = &d1;

    return 0;
}

Note that because dPtr is a base pointer, it only points to the Base portion of d1. However, also note that *__vptr is in the Base portion of the class, so dPtr has access to this pointer. Finally, note that dPtr->__vptr points to the D1 virtual table! Consequently, even though dPtr is of type Base, it still has access to D1’s virtual table (through __vptr).

So what happens when we try to call dPtr->function1()?

1
2
3
4
5
6
7
8

int main()
{
    D1 d1;
    Base *dPtr = &d1;
    dPtr->function1();

    return 0;
}

First, the program recognizes that function1() is a virtual function. Second, the program uses dPtr->__vptr to get to D1’s virtual table. Third, it looks up which version of function1() to call in D1’s virtual table. This has been set to D1::function1(). Therefore, dPtr->function1() resolves to D1::function1()!

Now, you might be saying, “But what if dPtr really pointed to a Base object instead of a D1 object. Would it still call D1::function1()?”. The answer is no.

1
2
3
4
5
6
7
8

int main()
{
    Base b;
    Base *bPtr = &b;
    bPtr->function1();

    return 0;
}

In this case, when b is created, __vptr points to Base’s virtual table, not D1’s virtual table. Consequently, bPtr->__vptr will also be pointing to Base’s virtual table. Base’s virtual table entry for function1() points to Base::function1(). Thus, bPtr->function1() resolves to Base::function1(), which is the most-derived version of function1() that a Base object should be able to call.

By using these tables, the compiler and program are able to ensure function calls resolve to the appropriate virtual function, even if you’re only using a pointer or reference to a base class!

Calling a virtual function is slower than calling a non-virtual function for a couple of reasons: First, we have to use the *__vptr to get to the appropriate virtual table. Second, we have to index the virtual table to find the correct function to call. Only then can we call the function. As a result, we have to do 3 operations to find the function to call, as opposed to 2 operations for a normal indirect function call, or one operation for a direct function call. However, with modern computers, this added time is usually fairly insignificant.

Also as a reminder, any class that uses virtual functions has a *__vptr, and thus each object of that class will be bigger by one pointer. Virtual functions are powerful, but they do have a performance cost.






A C++ subclass B of a class A overrides a method f.

A B instance is created with new, but the pointer is assigned to an A pointer variable:

class A {                       class B: public A {
public:                         public:
   virtual void f();               virtual void f();
   ...                          ...
};                              };



int main()
{
   A *pa = new B();
   pa->f();
   ...
}

Question: To which implementation is the call to f() bound? The one in class A or the one in class B?

Answer:

Class B's f.

Dynamic Dispatch means that the binding of the method is determined at run time depending on the type of the object pointed to by pa.


Static Dispatch in C++

C++ doesn't always use dynamic dispatch:

int main()
{
  A a; // An A instance is created on the stack
  B b; // A B instance, also on the stack

  a = b;  // Only the A part of 'b' is copied into a.

  a.f();  // Static dispatch. This determines the binding
          // of f to A's f and this is done at compile time.
}


The binding of f is done statically; that is, at compile time based on the declared type of the variable a.

Recalling a previous lecture discussion of 'value' types versus 'reference' types, the situation in C++ is:



When does C++ use Dynamic Dispatch



        Value or              f virtual     Static or
Type    Reference?  Call      in A?         Dynamic Dispatch?
--------------------------------------------------------------
A a    Value        a.f()     virtual         static
A a    Value        a.f()     not virtual     static
A *pa  reference   pa->f()    virtual         dynamic
A *pa  reference   pa->f()    not virtual     static


Variables of value types are represented by memory to hold an actual value.

Variables of reference type are represented by memory to hold an address of a value.



Implementation of Dynamic Dispatch in OO Programming Languages

This sketch will use C++ as an example, but the concepts apply equally as well to Java.

Consider the following two classes:

class A                    class B : public A
{                          {
public:                    public:
   virtual void f();          virtual void f();
   virtual void g();          virtual void k();
   void h();               };
};

All the instances of class A will share the class A's Virtual Function Table. This table contains the beginning addresses of the code for each of the virtual functions of a class (declared directly in the class or inherited).

Virtual Function Tables for class A and class B



Class A's vtable                 Class B's vtable
  +-----------+                    +-----------+
0 |   A::f    |                  0 |   B::f    |
  +-----------+                    +-----------+
1 |   A::g    |                  1 |   A::g    |
  +-----------+                    +-----------+
                                 2 |   B::k    |
                                   +-----------+

The first 2 entries of B's vtable are for the same methods as in A's vtable.
These first 2 entries in B's vtable either contain a pointer to a new implementation if B overrides the method, or it contains the same entry as in A's table if the method is simply inherited but not overriden.
Class B's vtable may contain entries for additional virtual methods declared in B that are not in A.
The method h in class A is not in A's vtable (or B's) since it is not declared virtual.

Compiler Code for Calling Virtual Methods

Although dynamic dispatch means that the method called will be determined by the run time, the compiler must still generate code that when executed at run time will determine the correct method implementation based on the run time type of the object.

Each instance of class A will contain in addition to its data members, a pointer to class A's vtable. This pointer will be referred to as 'vptr' for this sketch. Similarly each instance of the subclass B will contain 'vptr' in the same offset location, but it will point to B's vtable.

Example 1

The run time object is an instance of the base class.

Example 1:



A *pa;
pa = new A();
pa->f();


Compiler generated code:

pa->vptr[0]();      // 0 is because f is at that index
                    // 1 would be used for g



         A instance               A's vtable
pa ---> +--------+              +-----------+
        | vptr --|----------> 0 |   A::f    |
        |------- |              +-----------+
        | rest   |            1 |   A::g    |
        | of     |              +-----------+
        | A's    |
        | data   |
        | members|
        +--------+

Example 2

The run time object is an instance of the subclass. Note that the code generated is the same, but since the vptr in the object points to a different vtable, this code looks up a different implementation of f at run time than Example 1.

Example 1:



A *pa;
pa = new B();
pa->f();



Compiler generated code:



pa->vptr[0]();      // 0 is because f is at that index

                    // 1 would be used for g



         B instance               B's vtable
pa ---> +--------+              +-----------+
        | vptr --|----------> 0 |   B::f    |
        |------- |              +-----------+
        | rest   |            1 |   A::g    |
        | of     |              +-----------+
        | B's    |            2 |   B::k    |
        | data   |              +-----------+
        | members|
        +--------+

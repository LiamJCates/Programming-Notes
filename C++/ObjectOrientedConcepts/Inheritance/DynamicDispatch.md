Dynamic Dispatch

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

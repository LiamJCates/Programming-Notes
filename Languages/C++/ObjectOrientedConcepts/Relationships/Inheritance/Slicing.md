The Problem of Slicing

In C++, a derived class object can be assigned to a base class object, but the other way is not possible.

When you pass an argument by value or assign a derived class object to a base class variable, you lose polymorphism. The data members that a derived class adds are sliced away when the object is copied to a base class variable. Another way to look at it is this: because the derived class members are sliced away, what is left is only a base object, so you cannot have polymorphism.

```cpp
class Base { int x, y; };

class Derived : public Base { int z, w; };

int main()  
{
    Derived d;
    Base b = d; // Object Slicing,  z and w of d are sliced off
}
```

Object slicing happens when a derived class object is assigned to a base class object, additional attributes of a derived class object are sliced off to form the base class object.

Slicing happens when a programmer does the following:

  Derived objDerived;
  Base objectBase = objDerived;

Or:

```cpp
void UseBase(Base input);
...
Derived objDerived;
UseBase(objDerived); // copy of objDerived will be sliced and sent
```

In both cases, an object of type Derived is being copied into another of type Base, either explicitly via assignment or by passing as an argument.

What happens in these cases is that the compiler copies only the Base part of objDerived — that is, not the complete object. The information contained by the data members belonging to Derived is lost in the process. This is not anticipated, and this unwanted reduction of that part of data that makes the Derived a specialization of Base is called slicing.

To avoid slicing problems, don’t pass parameters by value. Pass them as pointers to the base class or as a (optionally const) reference

We can avoid above unexpected behavior with the use of pointers or references. Object slicing doesn’t occur when pointers or references to objects are passed as function arguments since a pointer or reference of any type takes same amount of memory.

Object slicing can be prevented by making the base class function pure virtual there by disallowing object creation. It is not possible to create the object of a class which contains a pure virtual method.


Object slicing


```cpp
class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const { return "Derived"; }
};

int main()
{
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base &ref{ derived };
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base *ptr{ &derived };
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    return 0;
}
```

Output:
```
derived is a Derived and has value 5
ref is a Derived and has value 5
ptr is a Derived and has value 5
```

In the above example, ref references and ptr points to derived, which has a Base part, and a Derived part. Because ref and ptr are of type Base, ref and ptr can only see the Base part of derived -- the Derived part of derived still exists, but simply can’t be seen through ref or ptr. However, through use of virtual functions, we can access the most-derived version of a function.

But what happens if instead of setting a Base reference or pointer to a Derived object, we simply assign a Derived object to a Base object?

```cpp
int main()
{
    Derived derived{ 5 };
    Base base{ derived }; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

    return 0;
}
```
Remember that derived has a Base part and a Derived part. When we assign a Derived object to a Base object, only the Base portion of the Derived object is copied. The Derived portion is not. In the example above, base receives a copy of the Base portion of derived, but not the Derived portion. That Derived portion has effectively been “sliced off”. Consequently, the assigning of a Derived class object to a Base class object is called object slicing (or slicing for short).

Because variable base does not have a Derived part, base.getName() resolves to Base::getName().

The above example prints:

base is a Base and has value 5

Used conscientiously, slicing can be benign. However, used improperly, slicing can cause unexpected results in quite a few different ways. Let’s examine some of those cases.

### Slicing and functions

Now, you might think the above example is a bit silly. After all, why would you assign derived to base like that? You probably wouldn’t. However, slicing is much more likely to occur accidentally with functions.

Consider the following function:

```cpp
void printName(const Base base) // note: base passed by value, not reference
{
    std::cout << "I am a " << base.getName() << '\n';
}
```

This is a pretty simple function with a const base object parameter that is passed by value. If we call this function like such:
```cpp
int main()
{
    Derived d{ 5 };
    printName(d); // oops, didn't realize this was pass by value on the calling end

    return 0;
}
```

Output:
```
I am a Base
```

When you wrote this program, you may not have noticed that base is a value parameter, not a reference. Therefore, when called as printName(d), we might have expected base.getName() to call virtualized function getName() and print “I am a Derived”, that is not what happens.

Instead, Derived object d is sliced and only the Base portion is copied into the base parameter. When base.getName() executes, even though the getName() function is virtualized, there’s no Derived portion of the class for it to resolve to.

In this case, it’s pretty obvious what happened, but if your functions don’t actually print any identifying information like this, tracking down the error can be challenging.

Of course, slicing here can all be easily avoided by making the function parameter a reference instead of a pass by value (yet another reason why passing classes by reference instead of value is a good idea).

```cpp
void printName(const Base &base) // note: base now passed by reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
    Derived d{ 5 };
    printName(d);

    return 0;
}
```
Outputs:
```
I am a Derived
```

### Slicing vectors

Yet another area where new programmers run into trouble with slicing is trying to implement polymorphism with std::vector. Consider the following program:

```cpp
#include <vector>

int main()
{
	std::vector<Base> v{};
	v.push_back(Base{ 5 }); // add a Base object to our vector
	v.push_back(Derived{ 6 }); // add a Derived object to our vector

        // Print out all of the elements in our vector
	for (const auto& element : v)
		std::cout << "I am a " << element.getName() << " with value " << element.getValue() << '\n';

	return 0;
}
```

This program compiles just fine. But when run, it prints:

I am a Base with value 5
I am a Base with value 6

Similar to the previous examples, because the std::vector was declared to be a vector of type Base, when Derived(6) was added to the vector, it was sliced.

Fixing this is a little more difficult. Many new programmers try creating a std::vector of references to an object, like this:

1

std::vector<Base&> v{};

Unfortunately, this won’t compile. The elements of std::vector must be assignable, whereas references can’t be reassigned (only initialized).

One way to address this is to make a vector of pointers:

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

#include <iostream>
#include <vector>

int main()
{
	std::vector<Base*> v{};

	Base b{ 5 }; // b and d can't be anonymous objects
	Derived d{ 6 };

	v.push_back(&b); // add a Base object to our vector
	v.push_back(&d); // add a Derived object to our vector

	// Print out all of the elements in our vector
	for (const auto* element : v)
		std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';

	return 0;
}

This prints:

I am a Base with value 5
I am a Derived with value 6

which works! A few comments about this. First, nullptr is now a valid option, which may or may not be desirable. Second, you now have to deal with pointer semantics, which can be awkward. But on the upside, this also allows the possibility of dynamic memory allocation, which is useful if your objects might otherwise go out of scope.

The Frankenobject

In the above examples, we’ve seen cases where slicing lead to the wrong result because the derived class had been sliced off. Now let’s take a look at another dangerous case where the derived object still exists!

Consider the following code:

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
    Derived d1{ 5 };
    Derived d2{ 6 };
    Base &b{ d2 };

    b = d1; // this line is problematic

    return 0;
}

The first three lines in the function are pretty straightforward. Create two Derived objects, and set a Base reference to the second one.

The fourth line is where things go astray. Since b points at d2, and we’re assigning d1 to b, you might think that the result would be that d1 would get copied into d2 -- and it would, if b were a Derived. But b is a Base, and the operator= that C++ provides for classes isn’t virtual by default. Consequently, only the Base portion of d1 is copied into d2.

As a result, you’ll discover that d2 now has the Base portion of d1 and the Derived portion of d2. In this particular example, that’s not a problem (because the Derived class has no data of its own), but in most cases, you’ll have just created a Frankenobject -- composed of parts of multiple objects. Worse, there’s no easy way to prevent this from happening (other than avoiding assignments like this as much as possible).

Conclusion

Although C++ supports assigning derived objects to base objects via object slicing, in general, this is likely to cause nothing but headaches, and you should generally try to avoid slicing. Make sure your function parameters are references (or pointers) and try to avoid any kind of pass-by-value when it comes to derived classes.

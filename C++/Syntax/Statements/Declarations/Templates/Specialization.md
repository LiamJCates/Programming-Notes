Template specialization
It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called a template specialization.

For example, let's suppose that we have a very simple class called mycontainer that can store one element of any type and that has just one member function called increase, which increases its value. But we find that when it stores an element of type char it would be more convenient to have a completely different implementation with a function member uppercase, so we decide to declare a class template specialization for that type:


  #include <iostream>
  using namespace std;

  // class template:
  template <class T>
  class mycontainer {
      T element;
    public:
      mycontainer (T arg) {element=arg;}
      T increase () {return ++element;}
  };

  // class template specialization:
  template <>
  class mycontainer <char> {
      char element;
    public:
      mycontainer (char arg) {element=arg;}
      char uppercase ()
      {
        if ((element>='a')&&(element<='z'))
        element+='A'-'a';
        return element;
      }
  };

  int main () {
    mycontainer<int> myint (7);
    mycontainer<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
    return 0;
  }

This is the syntax used for the class template specialization:

  template <> class mycontainer <char> { ... };

First of all, notice that we precede the class name with template<> , including an empty parameter list. This is because all types are known and no template arguments are required for this specialization, but still, it is the specialization of a class template, and thus it requires to be noted as such.

But more important than this prefix, is the <char> specialization parameter after the class template name. This specialization parameter itself identifies the type for which the template class is being specialized (char). Notice the differences between the generic class template and the specialization:

  template <class T> class mycontainer { ... };
  template <> class mycontainer <char> { ... };

The first line is the generic template, and the second one is the specialization.

When we declare specializations for a template class, we must also define all its members, even those identical to the generic template class, because there is no "inheritance" of members from the generic template to the specialization.
















Function template specialization
By Alex on December 3rd, 2016 | last modified by Alex on December 21st, 2020

When instantiating a function template for a given type, the compiler stencils out a copy of the templated function and replaces the template type parameters with the actual types used in the variable declaration. This means a particular function will have the same implementation details for each instanced type (just using different types). While most of the time, this is exactly what you want, occasionally there are cases where it is useful to implement a templated function slightly different for a specific data type.

Template specialization is one way to accomplish this.

Let’s take a look at a very simple template class:

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

template <class T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
    {
         m_value = value;
    }

    ~Storage()
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

The above code will work fine for many data types:

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
    // Define some storage units
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    // Print out some values
    nValue.print();
    dValue.print();
}

This prints:

5
6.7

Now, let’s say we want double values (and only double values) to output in scientific notation. To do so, we can use a function template specialization (sometimes called a full or explicit function template specialization) to create a specialized version of the print() function for type double. This is extremely simple: simply define the specialized function (if the function is a member function, do so outside of the class definition), replacing the template type with the specific type you wish to redefine the function for. Here is our specialized print() function for doubles:

1
2
3
4
5

template <>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}

When the compiler goes to instantiate Storage<double>::print(), it will see we’ve already explicitly defined that function, and it will use the one we’ve defined instead of stenciling out a version from the generic templated class.

The template <> tells the compiler that this is a template function, but that there are no template parameters (since in this case, we’re explicitly specifying all of the types). Some compilers may allow you to omit this, but it’s proper to include it.

As a result, when we rerun the above program, it will print:

5
6.700000e+000

Another example

Now let’s take a look at another example where template specialization can be useful. Consider what happens if we try to use our templated Storage class with datatype char*:

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

int main()
{
    // Dynamically allocate a temporary string
    char *string = new char[40];

    // Ask user for their name
    std::cout << "Enter your name: ";
    std::cin >> string;

    // Store the name
    Storage<char*> storage(string);

    // Delete the temporary string
    delete[] string;

    // Print out our value
    storage.print(); // This will print garbage
}

As it turns out, instead of printing the name the user input, storage.print() prints garbage! What’s going on here?

When Storage is instantiated for type char*, the constructor for Storage<char*> looks like this:

1
2
3
4
5

template <>
Storage<char*>::Storage(char* value)
{
     m_value = value;
}

In other words, this just does a pointer assignment (shallow copy)! As a result, m_value ends up pointing at the same memory location as string. When we delete string in main(), we end up deleting the value that m_value was pointing at! And thus, we get garbage when trying to print that value.

Fortunately, we can fix this problem using template specialization. Instead of doing a pointer copy, we’d really like our constructor to make a copy of the input string. So let’s write a specialized constructor for datatype char* that does exactly that:

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

template <>
Storage<char*>::Storage(char* value)
{
    // Figure out how long the string in value is
    int length=0;
    while (value[length] != '\0')
        ++length;
    ++length; // +1 to account for null terminator

    // Allocate memory to hold the value string
    m_value = new char[length];

    // Copy the actual value string into the m_value memory we just allocated
    for (int count=0; count < length; ++count)
        m_value[count] = value[count];
}

Now when we allocate a variable of type Storage<char*>, this constructor will get used instead of the default one. As a result, m_value will receive its own copy of string. Consequently, when we delete string, m_value will be unaffected.

However, this class now has a memory leak for type char*, because m_value will not be deleted when a Storage variable goes out of scope. As you might have guessed, this can also be solved by specializing the Storage<char*> destructor:

1
2
3
4
5

template <>
Storage<char*>::~Storage()
{
    delete[] m_value;
}

Now when variables of type Storage<char*> go out of scope, the memory allocated in the specialized constructor will be deleted in the specialized destructor.

Although the above examples have all used member functions, you can also specialize non-member template functions in the same way.





Class template specialization
By Alex on August 16th, 2008 | last modified by Alex on December 21st, 2020

In the previous lesson 19.5 -- Function template specialization, we saw how it was possible to specialize functions in order to provide different functionality for specific data types. As it turns out, it is not only possible to specialize functions, it is also possible to specialize an entire class!

Consider the case where you want to design a class that stores 8 objects. Here’s a simplified class to do so:

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

template <class T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T &value)
    {
        m_array[index] = value;
    }

    const T& get(int index) const
    {
        return m_array[index];
    }
};

Because this class is templated, it will work fine for any given type:

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

#include <iostream>

int main()
{
    // Define a Storage8 for integers
    Storage8<int> intStorage;

    for (int count{ 0 }; count < 8; ++count)
        intStorage.set(count, count);

    for (int count{ 0 }; count < 8; ++count)
        std::cout << intStorage.get(count) << '\n';

    // Define a Storage8 for bool
    Storage8<bool> boolStorage;
    for (int count{ 0 }; count < 8; ++count)
        boolStorage.set(count, count & 3);

	std::cout << std::boolalpha;

    for (int count{ 0 }; count<8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }

    return 0;
}

This example prints:

0
1
2
3
4
5
6
7
false
true
true
true
false
true
true
true

While this class is completely functional, it turns out that the implementation of Storage8<bool> is much more inefficient than it needs to be. Because all variables must have an address, and the CPU can’t address anything smaller than a byte, all variables must be at least a byte in size. Consequently, a variable of type bool ends up using an entire byte even though technically it only needs a single bit to store its true or false value! Thus, a bool is 1 bit of useful information and 7 bits of wasted space. Our Storage8<bool> class, which contains 8 bools, is 1 byte worth of useful information and 7 bytes of wasted space.

As it turns out, using some basic bit logic, it’s possible to compress all 8 bools into a single byte, eliminating the wasted space altogether. However, in order to do this, we’ll need to revamp the class when used with type bool, replacing the array of 8 bools with a variable that is a single byte in size. While we could create an entirely new class to do so, this has one major downside: we have to give it a different name. Then the programmer has to remember that Storage8<T> is meant for non-bool types, whereas Storage8Bool (or whatever we name the new class) is meant for bools. That’s needless complexity we’d rather avoid. Fortunately, C++ provides us a better method: class template specialization.

Class template specialization

Class template specialization allows us to specialize a template class for a particular data type (or data types, if there are multiple template parameters). In this case, we’re going to use class template specialization to write a customized version of Storage8<bool> that will take precedence over the generic Storage8<T> class. This works analogously to how a specialized function takes precedence over a generic template function.

Class template specializations are treated as completely independent classes, even though they are allocated in the same way as the templated class. This means that we can change anything and everything about our specialization class, including the way it’s implemented and even the functions it makes public, just as if it were an independent class. Here’s our specialized class:

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

template <> // the following is a template class with no templated parameters
class Storage8<bool> // we're specializing Storage8 for bool
{
// What follows is just standard class implementation details
private:
    unsigned char m_data{};

public:
    void set(int index, bool value)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        auto mask{ 1 << index };

        if (value)  // If we're setting a bit
            m_data |= mask;  // Use bitwise-or to turn that bit on
        else  // if we're turning a bit off
            m_data &= ~mask;  // bitwise-and the inverse mask to turn that bit off
	}

    bool get(int index)
    {
        // Figure out which bit we're getting
        auto mask{ 1 << index };
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask);
    }
};

First, note that we start off with template<>. The template keyword tells the compiler that what follows is templated, and the empty angle braces means that there aren’t any template parameters. In this case, there aren’t any template parameters because we’re replacing the only template parameter (T) with a specific type (bool).

Next, we add <bool> to the class name to denote that we’re specializing a bool version of class Storage8.

All of the other changes are just class implementation details. You do not need to understand how the bit-logic works in order to use the class (though you can review O.2 -- Bitwise operators if you want to figure it out, but need a refresher on how bitwise operators work).

Note that this specialization class utilizes a single unsigned char (1 byte) instead of an array of 8 bools (8 bytes).

Now, when we declare a class of type Storage8<T>, where T is not a bool, we’ll get a version stenciled from the generic templated Storage8<T> class. When we declare a class of type Storage8<bool>, we’ll get the specialized version we just created. Note that we have kept the publicly exposed interface of both classes the same -- while C++ gives us free reign to add, remove, or change functions of Storage8<bool> as we see fit, keeping a consistent interface means the programmer can use either class in exactly the same manner.

We can use the exact same example as before to show both Storage8<T> and Storage8<bool> being instantiated:

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

int main()
{
    // Define a Storage8 for integers (instantiates Storage8<T>, where T = int)
    Storage8<int> intStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        intStorage.set(count, count);
	}

    for (int count{ 0 }; count<8; ++count)
    {
        std::cout << intStorage.get(count) << '\n';
    }

    // Define a Storage8 for bool  (instantiates Storage8<bool> specialization)
    Storage8<bool> boolStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        boolStorage.set(count, count & 3);
    }

	std::cout << std::boolalpha;

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }

    return 0;
}

As you might expect, this prints the same result as the previous example that used the non-specialized version of Storage8<bool>:

0
1
2
3
4
5
6
7
false
true
true
true
false
true
true
true

It’s worth noting again that keeping the public interface between your template class and all of the specializations identical is generally a good idea, as it makes them easier to use -- however, it’s not strictly necessary.



Partial template specialization
By Alex on August 17th, 2008 | last modified by Alex on December 21st, 2020

This lesson and the next are optional reading for those desiring a deeper knowledge of C++ templates. Partial template specialization is not used all that often (but can be useful in specific cases).

In lesson 19.4 -- Template non-type parameters, you learned how expression parameters could be used to parameterize template classes.

Let’s take another look at the Static Array class we used in one of our previous examples:

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

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
    // The expression parameter controls the size of the array
    T m_array[size]{};

public:
    T* getArray() { return m_array; }

    T& operator[](int index)
    {
        return m_array[index];
    }
};

This class takes two template parameters, a type parameter, and an expression parameter.

Now, let’s say we wanted to write a function to print out the whole array. Although we could implement this as a member function, we’re going to do it as a non-member function instead because it will make the successive examples easier to follow.

Using templates, we might write something like this:

1
2
3
4
5
6

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
    for (int count{ 0 }; count < size; ++count)
        std::cout << array[count] << ' ';
}

This would allow us to do the following:

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
#include <cstring>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

int main()
{
	// declare an int array
	StaticArray<int, 4> int4{};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;

	// Print the array
	print(int4);

	return 0;
}

and get the following result:

0 1 2 3

Although this works, it has a design flaw. Consider the following:

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

int main()
{
    // declare a char array
    StaticArray<char, 14> char14{};

    std::strcpy(char14.getArray(), "Hello, world!");

    // Print the array
    print(char14);

    return 0;
}

(We covered std::strcpy in lesson 9.6 -- C-style strings if you need a refresher)

This program will compile, execute, and produce the following value (or one similar):

H e l l o ,   w o r l d !

For non-char types, it makes sense to put a space between each array element, so they don’t run together. However, with a char type, it makes more sense to print everything run together as a C-style string, which our print() function doesn’t do.

So how can we fix this?

Template specialization to the rescue?

One might first think of using template specialization. The problem with full template specialization is that all template parameters must be explicitly defined.

Consider:

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
41
42
43
44
45
46

#include <iostream>
#include <cstring>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(StaticArray<char, 14> &array)
{
	for (int count{ 0 }; count < 14; ++count)
		std::cout << array[count];
}

int main()
{
    // declare a char array
    StaticArray<char, 14> char14{};

    std::strcpy(char14.getArray(), "Hello, world!");

    // Print the array
    print(char14);

    return 0;
}

As you can see, we’ve now provided an overloaded print function for fully specialized StaticArray<char, 14>. Indeed, this prints:

Hello, world!

Although this solves the issue of making sure print() can be called with a StaticArray<char, 14>, it brings up another problem: using full template specialization means we have to explicitly define the length of the array this function will accept! Consider the following example:

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

int main()
{
    // declare a char array
    StaticArray<char, 12> char12{};

    std::strcpy(char12.getArray(), "Hello, mom!");

    // Print the array
    print(char12);

    return 0;
}

Calling print() with char12 will call the version of print() that takes a StaticArray<T, size>, because char12 is of type StaticArray<char, 12>, and our overloaded print() will only be called when passed a StaticArray<char, 14>.

Although we could make a copy of print() that handles StaticArray<char, 12>, what happens when we want to call print() with an array size of 5, or 22? We’d have to copy the function for each different array size. That’s redundant.

Obviously full template specialization is too restrictive a solution here. The solution we are looking for is partial template specialization.

Partial template specialization

Partial template specialization allows us to specialize classes (but not individual functions!) where some, but not all, of the template parameters have been explicitly defined. For our challenge above, the ideal solution would be to have our overloaded print function work with StaticArray of type char, but leave the length expression parameter templated so it can vary as needed. Partial template specialization allows us to do just that!

Here’s our example with an overloaded print function that takes a partially specialized StaticArray:

1
2
3
4
5
6
7

// overload of print() function for partially specialized StaticArray<char, size>
template <int size> // size is still a templated expression parameter
void print(StaticArray<char, size> &array) // we're explicitly defining type char here
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
}

As you can see here, we’ve explicitly declared that this function will only work for StaticArray of type char, but size is still a templated expression parameter, so it will work for char arrays of any size. That’s all there is to it!

Here’s a full program using this:

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
41
42
43
44
45
46
47
48
49
50
51
52
53
54

#include <iostream>
#include <cstring>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// overload of print() function for partially specialized StaticArray<char, size>
template <int size>
void print(StaticArray<char, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
}

int main()
{
	// Declare an char array of size 14
	StaticArray<char, 14> char14{};

	std::strcpy(char14.getArray(), "Hello, world!");

	// Print the array
	print(char14);

	// Now declare an char array of size 12
	StaticArray<char, 12> char12{};

	std::strcpy(char12.getArray(), "Hello, mom!");

	// Print the array
	print(char12);

	return 0;
}

This prints:

Hello, world! Hello, mom!

Just as we expect.

Note that as of C++14, partial template specialization can only be used with classes, not template functions (functions must be fully specialized). Our void print(StaticArray<char, size> &array) example works because the print function is not partially specialized (it’s just an overloaded function using a class parameter that’s partially specialized).

Partial template specialization for member functions

The limitation on the partial specialization of functions can lead to some challenges when dealing with member functions. For example, what if we had defined StaticArray like this?

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

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
    // The expression parameter controls the size of the array
    T m_array[size]{};

public:
    T* getArray() { return m_array; }

    T& operator[](int index)
    {
        return m_array[index];
    }

    void print()
    {
        for (int i{ 0 }; i < size; ++i)
            std::cout << m_array[i] << ' ';
        std::cout << '\n';
    }
};

print() is now a member function of class StaticArray<T, int>. So what happens when we want to partially specialize print(), so that it works differently? You might try this:

1
2
3
4
5
6
7
8

// Doesn't work
template <int size>
void StaticArray<double, size>::print()
{
	for (int i{ 0 }; i < size; ++i)
		std::cout << std::scientific << m_array[i] << ' ';
	std::cout << '\n';
}

Unfortunately, this doesn’t work, because we’re trying to partially specialize a function, which is disallowed.

So how do we get around this? One obvious way is to partially specialize the entire class:

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
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67

#include<iostream>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << "\n";
	}
};

template <int size> // size is the expression parameter
class StaticArray<double, size>
{
private:
	// The expression parameter controls the size of the array
	double m_array[size]{};

public:
	double* getArray() { return m_array; }

	double& operator[](int index)
	{
		return m_array[index];
	}
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << std::scientific << m_array[i] << ' ';
		std::cout << '\n';
	}
};

int main()
{
	// declare an integer array with room for 6 integers
	StaticArray<int, 6> intArray{};

	// Fill it up in order, then print it
	for (int count{ 0 }; count < 6; ++count)
		intArray[count] = count;

	intArray.print();

	// declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray{};

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);

	doubleArray.print();

	return 0;
}

This prints:

0 1 2 3 4 5
4.000000e+00 4.100000e+00 4.200000e+00 4.300000e+00

While it works, this isn’t a great solution, because we had to duplicate a lot of code from StaticArray<T, size> to StaticArray<double, size>.

If only there were some way to reuse the code in StaticArray<T, size> in StaticArray<double, size>. Sounds like a job for inheritance!

You might start off trying to write that code like this:

1
2

template <int size> // size is the expression parameter
class StaticArray<double, size>: public StaticArray< // Then what?

How do we reference StaticArray? We can’t.

Fortunately, there’s a workaround, by using a common base class:

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
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69

#include<iostream>

template <class T, int size> // size is the expression parameter
class StaticArray_Base
{
protected:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << m_array[i];
		std::cout << '\n';
	}

	virtual ~StaticArray_Base() = default;
};

template <class T, int size> // size is the expression parameter
class StaticArray: public StaticArray_Base<T, size>
{
public:
};

template <int size> // size is the expression parameter
class StaticArray<double, size>: public StaticArray_Base<double, size>
{
public:

	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << std::scientific << this->m_array[i] << ' ';
// note: The this-> prefix in the above line is needed.
// See https://stackoverflow.com/a/6592617 or https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members for more info on why.
		std::cout << '\n';
	}
};

int main()
{
	// declare an integer array with room for 6 integers
	StaticArray<int, 6> intArray{};

	// Fill it up in order, then print it
	for (int count{ 0 }; count < 6; ++count)
		intArray[count] = count;

	intArray.print();

	// declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray{};

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);

	doubleArray.print();

	return 0;
}

This prints the same as above, but has significantly less duplicated code.









Partial template specialization for pointers
By Alex on December 5th, 2016 | last modified by Alex on December 22nd, 2020

In previous lesson 19.5 -- Function template specialization, we took a look at a simple templated Storage class:

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

#include <iostream>

template <class T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
    {
         m_value = value;
    }

    ~Storage()
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

We showed that this class had problems when template parameter T was of type char* because of the shallow copy/pointer assignment that takes place in the constructor. In that lesson, we used full template specialization to create a specialized version of the Storage constructor for type char* that allocated memory and created an actual deep copy of m_value. For reference, here’s the fully specialized char* Storage constructor and destructor:

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

// You need to include the Storage<T> class from the example above here

template <>
Storage<char*>::Storage(char* value)
{
    // Figure out how long the string in value is
    int length=0;
    while (value[length] != '\0')
        ++length;
    ++length; // +1 to account for null terminator

    // Allocate memory to hold the value string
    m_value = new char[length];

    // Copy the actual value string into the m_value memory we just allocated
    for (int count=0; count < length; ++count)
        m_value[count] = value[count];
}

template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

While that worked great for Storage<char*>, what about other pointer types (such as int*)? It’s fairly easy to see that if T is any pointer type, then we run into the problem of the constructor doing a pointer assignment instead of making an actual deep copy of the element being pointed to.

Because full template specialization forces us to fully resolve templated types, in order to fix this issue we’d have to define a new specialized constructor (and destructor) for each and every pointer type we wanted to use Storage with! This leads to lots of duplicate code, which as you well know by now is something we want to avoid as much as possible.

Fortunately, partial template specialization offers us a convenient solution. In this case, we’ll use class partial template specialization to define a special version of the Storage class that works for pointer values. This class is considered partially specialized because we’re telling the compiler that it’s only for use with pointer types, even though we haven’t specified the underlying type exactly.

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

#include <iostream>

// You need to include the Storage<T> class from the example above here

template <typename T>
class Storage<T*> // this is a partial-specialization of Storage that works with pointer types
{
private:
    T* m_value;
public:
    Storage(T* value) // for pointer type T
    {
         // For pointers, we'll do a deep copy
         m_value = new T(*value); // this copies a single value, not an array
    }

    ~Storage()
    {
        delete m_value; // so we use scalar delete here, not array delete
    }

    void print()
    {
        std::cout << *m_value << '\n';
    }
};

And an example of this working:

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

int main()
{
	// Declare a non-pointer Storage to show it works
	Storage<int> myint(5);
	myint.print();

	// Declare a pointer Storage to show it works
	int x = 7;
	Storage<int*> myintptr(&x);

	// Let's show that myintptr is separate from x.
	// If we change x, myintptr should not change
	x = 9;
	myintptr.print();

    return 0;
}

This prints the value:

5
7

When myintptr is defined with an int* template parameter, the compiler sees that we have defined a partially specialized template class that works with any pointer type, and instantiates a version of Storage using that template. The constructor of that class makes a deep copy of parameter x. Later, when we change x to 9, the myintptr.m_value is not affected because it’s pointing at its own separate copy of the value.

If the partial template specialization class did not exist, myintptr would have used the normal (non-partially-specialized) version of the template. The constructor of that class does a shallow copy pointer assignment, which means that myintptr.m_value and x would be referencing the same address. Then when we changed the value of x to 9, we would have changed myintptr’s value too.

It’s worth noting that because this partially specialized Storage class only allocates a single value, for C-style strings, only the first character will be copied. If the desire is to copy entire strings, a specialization of the constructor (and destructor) for type char* can be fully specialized. The fully specialized version will take precedence over the partially specialized version. Here’s an example program that uses both partial specialization for pointers, and full specialization for char*:

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
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112

#include <iostream>
#include <cstring>

// Our Storage class for non-pointers
template <class T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

// Partial-specialization of Storage class for pointers
template <class T>
class Storage<T*>
{
private:
	T* m_value;
public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}

	~Storage()
	{
		delete m_value;
	}

	void print()
	{
		std::cout << *m_value << '\n';
	}
};

// Full specialization of constructor for type char*
template <>
Storage<char*>::Storage(char* value)
{
	// Figure out how long the string in value is
	int length = 0;
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator

	// Allocate memory to hold the value string
	m_value = new char[length];

	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first element
template<>
void Storage<char*>::print()
{
	std::cout << m_value;
}

int main()
{
	// Declare a non-pointer Storage to show it works
	Storage<int> myint(5);
	myint.print();

	// Declare a pointer Storage to show it works
	int x = 7;
	Storage<int*> myintptr(&x);

	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.print();

	// Dynamically allocate a temporary string
	char *name = new char[40]{ "Alex" }; // requires C++14

	// If your compiler isn't C++14 compatible, comment out the above line and uncomment these
//	char *name = new char[40];
//	strcpy(name, "Alex");

	// Store the name
	Storage< char*> myname(name);

	// Delete the temporary string
	delete[] name;

	// Print out our name
	myname.print();
}

This works as we expect:

5
7
Alex

Using partial template class specialization to create separate pointer and non-pointer implementations of a class is extremely useful when you want a class to handle both differently, but in a way that’s completely transparent to the end-user.

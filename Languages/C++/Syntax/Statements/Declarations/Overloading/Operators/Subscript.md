Overloading the subscript operator
By Alex on October 19th, 2007 | last modified by Alex on December 21st, 2020

When working with arrays, we typically use the subscript operator ([]) to index specific elements of an array:

1

myArray[0] = 7; // put the value 7 in the first element of the array

However, consider the following IntList class, which has a member variable that is an array:

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

class IntList
{
private:
    int m_list[10]{};
};

int main()
{
    IntList list{};
    // how do we access elements from m_list?
    return 0;
}

Because the m_list member variable is private, we can not access it directly from variable list. This means we have no way to directly get or set values in the m_list array. So how do we get or put elements into our list?

Without operator overloading, the typical method would be to create access functions:

1
2
3
4
5
6
7
8
9

class IntList
{
private:
    int m_list[10]{};

public:
    void setItem(int index, int value) { m_list[index] = value; }
    int getItem(int index) const { return m_list[index]; }
};

While this works, it’s not particularly user friendly. Consider the following example:

1
2
3
4
5
6
7

int main()
{
    IntList list{};
    list.setItem(2, 3);

    return 0;
}

Are we setting element 2 to the value 3, or element 3 to the value 2? Without seeing the definition of setItem(), it’s simply not clear.

You could also just return the entire list and use operator[] to access the element:

1
2
3
4
5
6
7
8

class IntList
{
private:
    int m_list[10]{};

public:
    int* getList() { return m_list; }
};

While this also works, it’s syntactically odd:

1
2
3
4
5
6
7

int main()
{
    IntList list{};
    list.getList()[2] = 3;

    return 0;
}

Overloading operator[]

However, a better solution in this case is to overload the subscript operator ([]) to allow access to the elements of m_list. The subscript operator is one of the operators that must be overloaded as a member function. An overloaded operator[] function will always take one parameter: the subscript that the user places between the hard braces. In our IntList case, we expect the user to pass in an integer index, and we’ll return an integer value back as a result.

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

class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index)
{
    return m_list[index];
}

Now, whenever we use the subscript operator ([]) on an object of our class, the compiler will return the corresponding element from the m_list member variable! This allows us to both get and set values of m_list directly:

1
2
3
4
5

    IntList list{};
    list[2] = 3; // set a value
    std::cout << list[2] << '\n'; // get a value

    return 0;

This is both easy syntactically and from a comprehension standpoint. When list[2] evaluates, the compiler first checks to see if there’s an overloaded operator[] function. If so, it passes the value inside the hard braces (in this case, 2) as an argument to the function.

Note that although you can provide a default value for the function parameter, actually using operator[] without a subscript inside is not considered a valid syntax, so there’s no point.

Why operator[] returns a reference

Let’s take a closer look at how list[2] = 3 evaluates. Because the subscript operator has a higher precedence than the assignment operator, list[2] evaluates first. list[2] calls operator[], which we’ve defined to return a reference to list.m_list[2]. Because operator[] is returning a reference, it returns the actual list.m_list[2] array element. Our partially evaluated expression becomes list.m_list[2] = 3, which is a straightforward integer assignment.

In lesson 1.3 -- Introduction to variables, you learned that any value on the left hand side of an assignment statement must be an l-value (which is a variable that has an actual memory address). Because the result of operator[] can be used on the left hand side of an assignment (e.g. list[2] = 3), the return value of operator[] must be an l-value. As it turns out, references are always l-values, because you can only take a reference of variables that have memory addresses. So by returning a reference, the compiler is satisfied that we are returning an l-value.

Consider what would happen if operator[] returned an integer by value instead of by reference. list[2] would call operator[], which would return the value of list.m_list[2]. For example, if m_list[2] had the value of 6, operator[] would return the value 6. list[2] = 3 would partially evaluate to 6 = 3, which makes no sense! If you try to do this, the C++ compiler will complain:

C:VCProjectsTest.cpp(386) : error C2106: '=' : left operand must be l-value

Dealing with const objects

In the above IntList example, operator[] is non-const, and we can use it as an l-value to change the state of non-const objects. However, what if our IntList object was const? In this case, we wouldn’t be able to call the non-const version of operator[] because that would allow us to potentially change the state of a const object.

The good news is that we can define a non-const and a const version of operator[] separately. The non-const version will be used with non-const objects, and the const version with const-objects.

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

#include <iostream>

class IntList
{
private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // give this class some initial state for this example

public:
    int& operator[] (int index);
    const int& operator[] (int index) const;
};

int& IntList::operator[] (int index) // for non-const objects: can be used for assignment
{
    return m_list[index];
}

const int& IntList::operator[] (int index) const // for const objects: can only be used for access
{
    return m_list[index];
}

int main()
{
    IntList list{};
    list[2] = 3; // okay: calls non-const version of operator[]
    std::cout << list[2] << '\n';

    const IntList clist{};
    clist[2] = 3; // compile error: calls const version of operator[], which returns a const reference.  Cannot assign to this.
    std::cout << clist[2] << '\n';

    return 0;
}

If we comment out the line clist[2] = 3, the above program compiles and executes as expected.

Error checking

One other advantage of overloading the subscript operator is that we can make it safer than accessing arrays directly. Normally, when accessing arrays, the subscript operator does not check whether the index is valid. For example, the compiler will not complain about the following code:

1
2

int list[5]{};
list[7] = 3; // index 7 is out of bounds!

However, if we know the size of our array, we can make our overloaded subscript operator check to ensure the index is within bounds:

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

#include <cassert> // for assert()

class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index)
{
    assert(index >= 0 && index < 10);

    return m_list[index];
}

In the above example, we have used the assert() function (included in the cassert header) to make sure our index is valid. If the expression inside the assert evaluates to false (which means the user passed in an invalid index), the program will terminate with an error message, which is much better than the alternative (corrupting memory). This is probably the most common method of doing error checking of this sort.

Pointers to objects and overloaded operator[] don’t mix

If you try to call operator[] on a pointer to an object, C++ will assume you’re trying to index an array of objects of that type.

Consider the following example:

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

#include <cassert> // for assert()

class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index)
{
    assert(index >= 0 && index < 10);

    return m_list[index];
}

int main()
{
    IntList *list{ new IntList{} };
    list [2] = 3; // error: this will assume we're accessing index 2 of an array of IntLists
    delete list;

    return 0;
}

Because we can’t assign an integer to an IntList, this won’t compile. However, if assigning an integer was valid, this would compile and run, with undefined results.

Rule

Make sure you’re not trying to call an overloaded operator[] on a pointer to an object.

The proper syntax would be to dereference the pointer first (making sure to use parenthesis since operator[] has higher precedence than operator*), then call operator[]:

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
    IntList *list{ new IntList{} };
    (*list)[2] = 3; // get our IntList object, then call overloaded operator[]
    delete list;

    return 0;
}

This is ugly and error prone. Better yet, don’t set pointers to your objects if you don’t have to.

The function parameter does not need to be an integer

As mentioned above, C++ passes what the user types between the hard braces as an argument to the overloaded function. In most cases, this will be an integer value. However, this is not required -- and in fact, you can define that your overloaded operator[] take a value of any type you desire. You could define your overloaded operator[] to take a double, a std::string, or whatever else you like.

As a ridiculous example, just so you can see that it works:

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

#include <iostream>
#include <string>

class Stupid
{
private:

public:
	void operator[] (const std::string& index);
};

// It doesn't make sense to overload operator[] to print something
// but it is the easiest way to show that the function parameter can be a non-integer
void Stupid::operator[] (const std::string& index)
{
	std::cout << index;
}

int main()
{
	Stupid stupid{};
	stupid["Hello, world!"];

	return 0;
}

As you would expect, this prints:

Hello, world!

Overloading operator[] to take a std::string parameter can be useful when writing certain kinds of classes, such as those that use words as indices.

Conclusion

The subscript operator is typically overloaded to provide direct access to individual elements from an array (or other similar structure) contained within a class. Because strings are often implemented as arrays of characters, operator[] is often implemented in string classes to allow the user to access a single character of the string.

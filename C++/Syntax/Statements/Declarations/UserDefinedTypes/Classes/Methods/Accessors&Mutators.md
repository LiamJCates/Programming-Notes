### Access functions

One of the most important uses of inlines inside classes is the access function. This is a small function that allows you to read or change part of the state of an object – that is, an internal variable or variables. The reason inlines are so important for access functions can be seen in the following example:

```cpp
class Access
{
	int i;

public:
	int read() const { return i; }
	void set(int ii) { i = ii; }
};
int main()
{
	Access A;
	A.set(100);
	int x = A.read();
}
```

Here, the class user never has direct contact with the state variables inside the class, and they can be kept private, under the control of the class designer. All the access to the private data members can be controlled through the member function interface.

In addition, access is remarkably efficient. Consider the read( ), for example. Without inlines, the code generated for the call to read( ) would typically include pushing this on the stack and making an assembly language CALL.

With most machines, the size of this code would be larger than the code created by the inline, and the execution time would certainly be longer.

Without inline functions, an efficiency-conscious class designer will be tempted to simply make i a public member, eliminating the overhead by allowing the user to directly access i. From a design standpoint, this is disastrous because i then becomes part of the public interface, which means the class designer can never change it. You’re stuck with an int called i. This is a problem because you may learn sometime later that it would be much more useful to represent the state information as a float rather than an int, but because int i is part of the public interface, you can’t change it.

Or you may want to perform some additional calculation as part of reading or setting i, which you can’t do if it’s public. If, on the other hand, you’ve always used member functions to read and change the state information of an object, you can modify the underlying representation of the object to your heart’s content.

In addition, the use of member functions to control data members allows you to add code to the member function to detect when that data is being changed, which can be very useful during debugging.

If a data member is public, anyone can change it anytime without you knowing about it.


### Accessors and Mutators

Some people further divide the concept of access functions into accessors (to read state information from an object) and mutators (to change the state of an object).

In addition, function overloading may be used to provide the same function name for both the accessor and mutator; how you call the function determines whether you’re reading or modifying state information:

```cpp
// Accessors & mutators
class Rectangle
{
	int wide, high;

public:
	Rectangle(int w = 0, int h = 0)
		: wide(w), high(h) {}
	int width() const { return wide; }	// Read
	void width(int w) { wide = w; }			// Set
	int height() const { return high; } // Read
	void height(int h) { high = h; }		// Set
};

int main()
{
	Rectangle r(19, 47);
	// Change width & height:
	r.height(2 * r.width());
	r.width(2 * r.height());
}
```

The constructor uses the constructor initializer list to initialize the values of wide and high (using the pseudoconstructor form for built-in types).

You cannot have member function names using the same identifiers as data members, so you might be tempted to distinguish the data members with a leading underscore. However, identifiers with leading underscores are reserved so you should not use them.

You may choose instead to use “get” and “set” to indicate accessors and mutators:

```cpp
//: C09:Rectangle2.cpp
// Accessors & mutators with "get" and "set"
class Rectangle
{
	int width, height;

public:
	Rectangle(int w = 0, int h = 0)
		: width(w), height(h) {}
	int getWidth() const { return width; }
	void setWidth(int w) { width = w; }
	int getHeight() const { return height; }
	void setHeight(int h) { height = h; }
};
int main()
{
	Rectangle r(19, 47);
	// Change width & height:
	r.setHeight(2 * r.getWidth());
	r.setWidth(2 * r.getHeight());
}
```

Of course, accessors and mutators don’t have to be simple pipelines to an internal variable. Sometimes they can perform more sophisticated calculations. The following example uses the Standard C library time functions to produce a simple Time class:

```cpp
// A simple time class
#ifndef CPPTIME_H
#define CPPTIME_H
#include <ctime>
#include <cstring>
class Time
{
	std::time_t t;
	std::tm local;
	char asciiRep[26];
	unsigned char lflag, aflag;
	void updateLocal()
	{
		if (!lflag)
		{
			local = *std::localtime(&t);
			lflag++;
		}
	}
	void updateAscii()
	{
		if (!aflag)
		{
			updateLocal();
			std::strcpy(asciiRep, std::asctime(&local));
			aflag++;
		}
	}

public:
	Time() { mark(); }
	void mark()
	{
		lflag = aflag = 0;
		std::time(&t);
	}
	const char *ascii()
	{
		updateAscii();
		return asciiRep;
	}
	// Difference in seconds:
	int delta(Time *dt) const
	{
		return int(std::difftime(t, dt->t));
	}
	int daylightSavings()
	{
		updateLocal();
		return local.tm_isdst;
	}
	int dayOfYear()
	{ // Since January 1
		updateLocal();
		return local.tm_yday;
	}
	int dayOfWeek()
	{ // Since Sunday
		updateLocal();
		return local.tm_wday;
	}
	int since1900()
	{ // Years since 1900
		updateLocal();
		return local.tm_year;
	}
	int month()
	{ // Since January
		updateLocal();
		return local.tm_mon;
	}
	int dayOfMonth()
	{
		updateLocal();
		return local.tm_mday;
	}
	int hour()
	{ // Since midnight, 24-hour clock
		updateLocal();
		return local.tm_hour;
	}
	int minute()
	{
		updateLocal();
		return local.tm_min;
	}
	int second()
	{
		updateLocal();
		return local.tm_sec;
	}
};
#endif
```

The Standard C library functions have multiple representations for time, and these are all part of the Time class. However, it isn’t necessary to update all of them, so instead the time_t tis used as the base representation, and the tm localand ASCII character representation asciiRepeach have flags to indicate if they’ve been updated to the current time_t. The two privatefunctions
updateLocal( and ) updateAscii( check the flags and conditionally )
perform the update.9: Inline Functions 407
The constructor calls the mark( )function (which the user can also
call to force the object to represent the current time), and this clears
the two flags to indicate that the local time and ASCII
representation are now invalid. The ascii( )function calls
updateAscii( , which copies the result of the Standard C library )
function asctime( )into a local buffer because asctime( )uses a
static data area that is overwritten if the function is called
elsewhere. The ascii( )function return value is the address of this
local buffer.
All the functions starting with daylightSavings( use the )
updateLocal( function, which causes the resulting composite )
inlines to be fairly large. This doesn’t seem worthwhile, especially
considering you probably won’t call the functions very much.
However, this doesn’t mean all the functions should be made noninline. If you make other functions non-inline, at least keep
updateLocal( inline so that its code will be duplicated in the non- )
inline functions, eliminating extra function-call overhead.
Here’s a small test program:

```cpp
// Testing a simple time class
#include "Cpptime.h"
#include <iostream>
using namespace std;
int main()
{
	Time start;
	for (int i = 1; i < 1000; i++)
	{
		cout << i << ' ';
		if (i % 10 == 0)
			cout << endl;
	}
	Time end;
	cout << endl;
	cout << "start = " << start.ascii();
	cout << "end = " << end.ascii();
	cout << "delta = " << end.delta(&start);
}
```
A Time object is created, then some time-consuming activity is
performed, then a second Time object is created to mark the ending
time. These are used to show starting, ending, and elapsed times.

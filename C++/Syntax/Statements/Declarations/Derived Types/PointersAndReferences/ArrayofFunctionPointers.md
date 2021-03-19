One of the more interesting constructs you can create is an array of pointers to functions.

To select a function, you just index into the array and dereference the pointer.

	(*func_table[index])();

This supports the concept of table-driven code; instead of using conditionals or case statements, you select functions to execute based on a state variable (or a combination of state variables).

This kind of design can be useful if you often add or delete functions from the table (or if you want to create or change such a table dynamically).

The following example creates some dummy functions using a preprocessor macro, then creates an array of pointers to those functions using automatic aggregate initialization. As you can see, it is easy to add or remove functions from the table (and thus, functionality from the program) by changing a small amount of code:

```cpp
// Using an array of pointers to functions
#include <iostream>
using namespace std;
// A macro to define dummy functions:
#define DF(N)                                        \
	void N()                                         \
	{                                                \
		cout << "function " #N " called..." << endl; \
	}
DF(a);
DF(b);
DF(c);
DF(d);
DF(e);
DF(f);
DF(g);
void (*func_table[])() = {a, b, c, d, e, f, g};
int main()
{
	while (1)
	{
		cout << "press a key from 'a' to 'g' "
				"or q to quit"
			 << endl;
		char c, cr;
		cin.get(c);
		cin.get(cr); // second one for CR
		if (c == 'q')
			break; // ... out of while(1)
		if (c < 'a' || c > 'g')
			continue;
		(*func_table[c - 'a'])();
	}
}
```

At this point, you might be able to imagine how this technique could be useful when creating some sort of interpreter or list processing program.

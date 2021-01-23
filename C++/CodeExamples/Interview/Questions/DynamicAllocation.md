One of the very important and tricky parts of code is memory allocation. A good programmer should have a keen eye over the resources, especially the memory. Dynamic memory allocation allows us to manage memory easily and keep the code robust. This chapter elaborates the terms and techniques of DMA.




1. What would be the output of the following code snippet?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer = new int;
		cout << "return value: " <<pointer;
	}

Answer: An address would be printed

If there is sufficient memory in the store, it would allocate memory for the integer and new shall return an address.



2. Assuming the memory allocation would start from 1000, what would be
the output of the following code? (Assume you are using Dev C++ or
G++)

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer = new int [2];
		cout << "return value: " << pointer << "\n";
		cout << "return value: " <<pointer+1;
	}

Answer: 1000, 1004

Since the usage of new and array is proper, the allocation would start with 1000 and would also print 1004 for second cout statement.




3. Which of the following is true with respect to memory allocation being
done with new?

	(a) Memory would be allocated based on the request and new would return an address.

	(b) When sufficient memory is not available, an error would be displayed.

	(c) When sufficient memory is not available, an exception would be thrown.

	(d) If sufficient memory is not available, it would free the already used memory and allocate memory for current request.

Answer: 'a' and 'c' are valid.



4. Which of the following is true with respect to memory allocation?

	(a) New must be used with free always, if not it would throw an exception.
	(b) New must be used with delete always, if not it would throw an exception.
	(c) New need not be associated with delete.
	(d) Though not mandatory, it is a good practice to use delete.

Answer: 'b', 'c' and 'd'



5. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int ;
		cout << "return value: " << pointer <<"\n";
		free pointer;
	}


Answer: Compilation error

Usage of free is not allowed in this context.



6. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int;
		cout << "return value: " << pointer << "\n";
		delete pointer;
	}

Answer: An address is printed

An address would be returned by new if space is available and delete will be
executed properly.



7. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int [2];
		cout << "return value: " << pointer << "\n";
		delete [2] pointer;
	}

Answer:  error: expected ‘]’ before numeric constant




8. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer = new int [2];
		cout << "return value: " << pointer << "\n";
		delete [] pointer;
	}

Answer: The address of the array's first member is printed

An address would be returned by new if space is available and delete will be
executed properly. Usage of [ ] is proper with delete and it is acceptable with the code.



9. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *ptr = NULL;
		delete ptr;
	}

Answer: Nothing

Deleting a null pointer is a normal practice.




10. What is output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int;
		cout << "return value: " << pointer << "\n";
		delete pointer;
		delete pointer;
	}

Answer: Undefined behavior

Deleting the same memory twice is undefined behavior. Anything may happen, including nothing. It may e.g. cause a crash sometime later.




11. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int;
		cout << "return value: " << pointer << "\n";
		delete [] pointer;
	}


Answer: No error and would return the address allotted.

It is fine with using delete pointer or delete [] pointer.




12. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *pointer;
		pointer = new int;
		pointer = new int;
		cout << "address: " << pointer << "\n";
		delete pointer;
	}
Answer: An address

It is not illegal to use new twice for the same instance. But, it is not a good practice as it could cause a memory leak.




13. What is the output of the following code?
(Assume address allocation starts from 1000)

	#include <iostream>
	using namespace std;

	int main ()
	{
		int n = 10;
		int *pointer;
		pointer = new (nothrow) int;
		cout << pointer << ",";
		*pointer = n;
		cout << * pointer << endl;
	}

Answer: 1000, 10

Here, nothrow is used by the program to avoid throwing exception. Instead of throwing exception it would give the address allotted as return value or zero if address allocation fails.



14. What is the output of the following code?
(Assume address allocation starts from 1000)

	#include <iostream>
	using namespace std;

	int main ()
	{
		int n = 10;
		int *pointer;
		pointer = new (no throw) int;
		cout << pointer << ",";
		*pointer = n;
		cout << *pointer << endl;
	}

Answer: Compilation fault
error: ‘no’ was not declared in this scope; did you mean ‘n’?

nothrow is a single word




15. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int n = 10;
		int *pointer;
		pointer = new (nothrow) float;
		cout << pointer << ",";
		*pointer = n;
		cout << *pointer << endl;
	}

Answer: Compilation fault.

Pointer is of type integer and compiler cannot convert float to integer in assignment and vice versa.




16. Null pointer is same as the void pointer. – True or False.

Answer: False – Both are significantly different.




17. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p = NULL;
		cout << "\n" << p;
	}

Answer: 0

This is a proper code and the NULL assigned to a pointer makes the pointer a NULL pointer which has a 0 value. It is very much legal to do this way of assignment and will prevent garbage from entering the pointer.




18. What is the output of the following piece of code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p = null;
		cout << "\n" << p;
	}

Answer: Compilation error

NULL != null, null is not defined by the system.




19. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p = 0;
		cout << "\n" << p;
	}

Answer: 0

This is another way of keeping the pointer safe from garbage. This is also a form of NULL pointer.




20. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p;
		cout << "\n" << p;
		p = 0;
		cout << "\n" << p;
	}

Answer: Garbage and 0

Since p is a pointer it would hold an address, originally a garbage value until it is initialized, in this case by the NULL value 0.




21. What is the output of the following code snippet ?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p;
		cout << "\n" << *p;
		p = 0;
		cout << "\n" << p;
	}

Answer: Segmentation fault

Applying the indirection operator to a garbage value exhibits undefined behavior and will commonly eg fault




22. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p;
		p = 0;
		p = NULL;
		cout << "\n" << p;
	}

Answer: 0

Nothing wrong in loading a variable or pointer twice with the
same value. Hence, would not return any error.




23. Using new is preferred over Malloc. – True or False.

Answer: True.




24. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int a = 10;
		float b = 10.235;
		void *p;
		p = &a;
		cout << *(int *)p;
		p = &b;
		cout <<", " << *(float *)p;
	}

Answer: 10, 10.235

This is referred as void pointer and is a general purpose pointer. It can hold the address of any data type.




25. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int a = 10;
		float b = 10.235;
		void p;
		p = &a;
		cout << *(int *)p;
		p = &b;
		cout <<", " << *(float *)p;
	}

Answer: error: variable or field ‘p’ declared void

void can only be used to declare a pointer object, void* p should be used.



26. What is the output of the following code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		void *p;
		int *q;
		q = NULL;
		p = q;
		cout << p;
	}

Answer: 0

NULL can be assigned to a void pointer.




27. What is the output of the below given piece of code?

	#include <iostream>
	using namespace std;

	int main ()
	{
		void *p;
		cout << sizeof(p) <<"\n";
	}


Answer: 4 or 8 if 32 or 64 bit system respectively

Any pointer needs word size bytes for it to be stored.




28. What is the output of the following code snippet?

	#include <iostream>
	using namespace std;

	int main ()
	{
		int *p = NULL;
		cout << sizeof(p) <<"\n";
	}

Answer: 4 or 8 if 32 or 64 bit system respectively

Any pointer needs word size bytes for it to be stored, assigning NULL does not change the size of the pointer.

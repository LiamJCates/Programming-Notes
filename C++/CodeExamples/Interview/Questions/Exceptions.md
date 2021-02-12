Errors and bugs are always a burden to a professional programmer.
Exception handling is an intelligent way to handle the various errors and
bypass them while programming. This chapter introduces you the art of
exception handling and increase your skill set in debugging.



1. Which of the following class is the parent class for any exception that
may occur in a C++ program?

	(a) std::parentException
	(b) std::exception
	(c) std::bad_Exception
	(d) std::invalid_argument

Answer: (b)
std::exception is the parent class of all the exception classes present in C++



2. True or False

	We can declare user defined exceptions in C++?

Answer: True
We can declare user defined exceptions by inheriting the Exception class



3. Predict the output of the following code snippet, given val1=10, val2=20

	#include <iostream>
	#include <exception>
	using namespace std;
	struct UserDefinedException : public exception
	{
	    const char *what() const throw()
	    {
	        return "Value 2 cannot be greater than value 1";
	    }
	};
	int main()
	{
	    int val1, val2;
	    std::cout <<"Please enter value1";
	    std::cin >> val1;
	    std::cout <<"Please enter value2";
	    std::cin >> val2;
	    try
	    {
	        if (val2 > val1)
	            throw UserDefinedException();
	        else
	            std::cout << val1 / val2;
	    }
	    catch (UserDefinedException &e)
	    {
	        std::cout << e.what() << std::endl;
	    }
	}


(a) No output
(b) Value 2 cannot be greater than value 1
(c) 0
(d) Compile error
Answer: (b)
Value2 cannot be greater than value1.
Try block compares value1 with value2. When value2 is greater than value1, we are throwing user defined exception. When we call What() method present in user defined exception class, it prints the output statement, Value2 cannot be greater than value1.



4. True or False

	We can attach more than one catch block with a try block?


Answer: True
We can capture multiple types of exceptions in a program. For that, we can attach more than one catch block, each of which capturing a type of exception.



5. Which of the following exception occurs when we allocate memory using new keyword?

	(a) std::bad_cast
	(b) std::length_error
	(c) std::out_of_range
	(d) std::bad_alloc

Answer: (d) std::bad_alloc



6. Predict the outcome of the following program, when the array size is 10
and index position is 11.

	#include <iostream>
	#include <stdexcept>
	using namespace std;
	int main()
	{
	    int i, index, value;
	    std::cout <<"enter array size";
	    std::cin >> i;
	    int array[i];
	    try
	    {
	        std::cout <<"enter the array index position";
	        std::cin >> index;
	        if (index < i)
	        {
	            cout <<"enter value";
	            cin >> value;
	            array[index] = value;
	            cout << array[index];
	        }
	        else
	            throw std::out_of_range("Range Overflow");
	    }
	    catch (std::out_of_range &e)
	    {
	        std::cout << e.what();
	    }
	    return 0;
	}


(a) – 1
(b) Range overflow
(c) Compile time error
(d) None of the above

Answer: (b) Range overflow



7. What happens when we don’t include the header file <stdexcept> in following program?

	#include <iostream>
	#include <stdexcept>
	using namespace std;
	int main()
	{
	    int i, index, value;
	    std::cout <<"enter array size";
	    std::cin >> i;
	    int array[i];
	    try
	    {
	        std::cout <<"enter the array index position";
	        std::cin >> index;
	        if (index < i)
	        {
	            cout <<"enter value";
	            cin >> value;
	            array[index] = value;
	        }
	        else
	            throw std::range_error("Range Overflow");
	    }
	    catch (std::range_error &e)
	    {
	        std::cout << e.what();
	    }
	    return 0;
	}


(a) Throws the compile time error - ‘range_error’ is not a member of ‘std’
(b) Prints Range Overflow
(c) Prints the value of array[index]
(d) None of the above

Answer: (a)
It is mandatory to include the header stdexcept in order to use the exception classes.



8. Which of the following symbols is used in catch block in order to make the catch block catch any type of exception?

	(a) ::
	(b) ??
	(c) …
	(d) **

Answer: (c)
… ellipsis symbol is used in the catch block in order to make it catch any type of exception.



9. Which of the following exception types doesn’t get derived from logic_error class?

	(a) Invalid_argument
	(b) Domain_error
	(c) Out_of_range
	(d) Range_error

Answer: (d) range_error.
It is derived from the class runtime_error.



10. Predict the error of the following code.

	#include <iostream>
	#include <typeinfo>
	struct Chocolate
	{
	    virtual ~Chocolate() {}
	};
	struct Biscuits
	{
	    virtual ~Biscuits() {}
	};
	int main()
	{
	    Chocolate c;
	    try
	    {
	        Biscuits &b = dynamic_cast<Biscuits &>(c);
	    }
	    catch (const std::bad_cast &e)
	    {
	        std::cout << e.what();
	    }
	}


(a) It throws a compile time error
(b) It executes without any exception
(c) It generates std::bad_cast exception and prints the message std::bad_cast
(d) None of the above

Answer: (c)
It generates bad_Cast exception as we are trying to do a dynamic cast of a Chocolate class instance to a Biscuits class instance.



11. Predict the output of the following code, provided a=100 and b=100

	#include <iostream>
	using namespace std;
	class TestException
	{
	    int a, b;

	public:
	    TestException(int a, int b)
	    {
	        this->a = a;
	        this->b = b;
	    }
	    int divide()
	    {
	        std::cout << "a=" << a << "\n"
	                  << "b=" << b << "\n"
	                  << "a/b=" << a / b << "\n";
	        return a / b;
	    }
	};
	int main(void)
	{
	    try
	    {
	        int a, b;
	        cout << "Enter a = ";
	        cin >> a;
	        cout << "Enter b = ";
	        cin >> b;
	        TestException obj(a, b);
	        std::cout << "Trying to divide"
	                  << "\n";
	        int quotient = obj.divide();
	        if (quotient == -1)
	            throw quotient;
	        else
	            cout << "quotient=" << quotient;
	    }
	    catch (int quotient)
	    {
	        std::cout << "caught an exception" << quotient;
	    }
	};


(a) Trying to divide
a=100
b=100
a/b=1
quotient=1
(b) Trying to divide
a=100
b=100
a/b=-1
caught an exception-1
(c) Trying to divide
a=100
b=100
a/b=1
caught an exception1
(d) None of the above

Answer: (a)



12. Predict the output of the following code, given a=100, b=100

	#include <iostream>
	using namespace std;
	int main(void)
	{
	    try
	    {
	        int a, b;
	        cout << "Enter a = ";
	        cin >> a;
	        cout << "Enter b = ";
	        cin >> b;
	        std::cout << "Trying to divide"
	                  << "\n";
	        int quotient = a / b;
	        if (quotient == -1)
	        {
	            throw quotient;
	            cout << "after throw";
	        }
	        else
	            cout << "quotient=" << quotient;
	    }
	    catch (int quotient)
	    {
	        std::cout << "after catch" << quotient;
	    }
	};


(a) Trying to divide
quotient=1
(b) Trying to divide
after throw after catch
after catch
(c) after catch
(d) after throw
after throw after catch

Answer: (a) The statements after catch will not be executed, they remain
unreachable code.



13. Predict the output of the following code snippet.

	#include <iostream>
	using namespace std;
	class Parent
	{
	public:
	    Parent()
	    {
	        std::cout << "Parent Constructor" << endl;
	    }
	};
	class Child : public Parent
	{
	public:
	    Child()
	    {
	        std::cout << "Child Constructor" << endl;
	    }
	};
	int main()
	{
	    Child c;
	    try
	    {
	        throw c;
	    }
	    catch (Child c)
	    {
	        cout << "Caught Child Exception" << endl;
	    }
	    catch (Parent p)
	    {
	        cout << "Caught Parent Exception" << endl;
	    }
	    return 0;
	}


(a) Child Constructor
Parent Constructor
Caught Child Exception
(b) Parent Constructor
Child Constructor
Caught Child Exception
(c) Child Constructor
Parent Constructor
Caught Parent Exception
(d) Parent Constructor
Child Constructor
Caught Parent Exception

Answer: (b)



14. Predict the output of the following piece of code.

	#include <iostream>
	using namespace std;
	void MyFunction()
	{
	    try
	    {
	        throw 1;
	    }
	    catch (int arg)
	    {
	        cout << "int exception\n";
	        throw;
	    }
	    catch (char arg)
	    {
	        cout << "char exception!\n";
	    }
	    catch (...)
	    {
	        cout << "generic exception!\n";
	    }
	    cout << "After Exception";
	}
	int main()
	{
	    try
	    {
	        MyFunction();
	    }
	    catch (...)
	    {
	        std::cout << "Caught Rethrown Exception";
	    }
	}


(a) int exception
Caught Rethrown Exception
After Exception
(b) int exception
Caught Rethrown Exception
(c) int exception
After exception
(d) generic exception
caught Rethrown Exception

Answer: (b) There is a ‘throw’ in the catch of type int. This makes it to throw exception in the return block of address which leads it to print "Caught Rethrown Exception"



15. Predict the output of the following piece of code.

	#include <iostream>
	using namespace std;
	void MyFunction()
	{
	    try
	    {
	        throw 1;
	    }
	    catch (...)
	    {
	        cout << "generic exception!\n";
	    }
	    catch (int arg)
	    {
	        cout << "int exception\n";
	        throw;
	    }
	    catch (char arg)
	    {
	        cout << "char exception!\n";
	    }
	    cout << "After Exception";
	}
	int main()
	{
	    try
	    {
	        MyFunction();
	    }
	    catch (...)
	    {
	        std::cout << "Caught Rethrown Exception";
	    }
	}


(a) Doesn’t compile, since catch block with ellipsis should be the last among other catch blocks
(b) generic exception
Caught Rethrown Exception
(c) int exception
Caught Rethrown Exception
(d) None of the above

Answer: (a)



16. Predict the output of the following code snippet.

	#include <iostream>
	using namespace std;
	class Exceptiontest
	{
	    int num1, num2;

	public:
	    Exceptiontest(int num1, int num2)
	    {
	        cout << "Inside Constructor" << endl;
	        this->num1 = num1;
	        this->num2 = num2;
	    }
	    ~Exceptiontest()
	    {
	        cout << "Inside destructor" << endl;
	    }
	    void PrintSum()
	    {
	        cout << "A+B=" << num1 + num2 << endl;
	    }
	};
	int main()
	{
	    try
	    {
	        Exceptiontest obj(10, 10);
	        obj.PrintSum();
	        throw -1;
	    }
	    catch (int num)
	    {
	        cout << "Caught Exception " << -1 << endl;
	    }
	}


(a) Inside Constructor
A+B = 20
Caught Exception -1
Inside destructor
(b) Inside Constructor
A+B = 20
Inside destructor
Caught Exception -1
(c) Inside Constructor
A+B = 20
Inside destructor
(d) Inside Destructor
A+B = 20
Inside Constructor
Caught Exception -1

Answer: (b) Since destructor is called before the control gets transferred to
catch block as the try block is no longer in scope and the obj is within the try block.



17. Predict the output of the following code.

	#include <iostream>
	using namespace std;
	class Exceptiontest
	{
	    int num1, num2;

	public:
	    Exceptiontest(int num1, int num2)
	    {
	        cout << "Inside Constructor" << endl;
	        this->num1 = num1;
	        this->num2 = num2;
	    }
	    ~Exceptiontest()
	    {
	        cout << "Inside destructor" << endl;
	    }
	    void PrintSum()
	    {
	        cout << "A+B=" << num1 + num2 << endl;
	    }
	};
	int main()
	{
	    try
	    {
	        Exceptiontest obj(10, 10);
	        obj.PrintSum();
	        throw true;
	    }
	    catch (bool num)
	    {
	        cout << "Caught Exception " << num << endl;
	    }
	}


(a) Inside Constructor
A+B = 20;
Inside destructor
Caught Exception true
(b) Inside Constructor
A+B = 20;
Inside destructor
Caught Exception 1
(c) Inside Constructor
A+B = 20;
Inside destructor
Caught Exception 0
(d) Inside Constructor
A+B = 20;
Inside destructor
Caught Exception -1

Answer: (b)
Throwing true assigns the value 1, false will print 0.



18. True or False

We can use throw statement to throw any kind of exception?

Answer: True
Any type of operand can be thrown



19. Identify the output of the following code.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	using namespace std;
	int main()
	{
	    try
	    {
	        string str1("Except");
	        string str2("ion");
	        str1.append(str2, 0, 2);
	        cout << str1 << endl;
	    }
	    catch (exception &ex)
	    {
	        cout << "Type: " << typeid(ex).name() << endl;
	    };
	    return 0;
	}


(a) Throws out of range exception
(b) Compiles and executes successfully printing ioExcept
(c) Throws bad_cast exception
(d) Compiles and executes successfully printing Exceptio

Answer: (d)



20. Identify the output of the following program.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	using namespace std;
	int main()
	{
	    try
	    {
	        string str1("Except");
	        string str2("ion");
	        str1.append(str2, -1, 2);
	        cout << str1 << endl;
	    }
	    catch (exception &ex)
	    {
	        cout << "Type: " << typeid(ex).name() << endl;
	    };
	    return 0;
	}


(a) Throws out of range exception
(b) Compiles and executes successfully printing ioExcept
(c) Throws bad_cast exception
(d) Compiles and executes successfully printing Exceptio
Answer: (a) Throws out of range exception, since we are trying to append 2characters from – 1 position in str2 whose index starts from 0.



21. Predict the output of the following code snippet.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	using namespace std;
	int main()
	{
	    try
	    {
	        string str1("Except");
	        string str2("ion");
	        str1.append(str2, 3, 2);
	        cout << "Str2" << str2.substr(100, 10);
	        cout << str1 << endl;
	        cout << str2 << endl;
	    }
	    catch (int)
	    {
	        cout << "Exception Caught";
	    };
	    return 0;
	}


(a) Throws compile time error
(b) Executes successfully and prints Exception Caught
(c) The program terminates
(d) None of the above

Answer: (c) The program terminates; in the above program, there is no appropriate catch handler for catching out of_range exceptions. The exception is thrown when substr(100, 10) is called, but there is no matching catch to receive it. The exception is not caught and the program is terminated.



22. Predict the output of the following code snippet.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	using namespace std;
	void testfunction()
	{
	    cout << "testfunction is called before terminating";
	}
	int main()
	{
	    try
	    {
	        set_terminate(testfunction);
	        string str1("Except");
	        string str2("ion");
	        str1.append(str2, 3, 2);
	        cout << "Str2" << str2.substr(100, 10);
	        cout << str1 << endl;
	        cout << str2 << endl;
	    }
	    catch (int)
	    {
	        cout << "Exception Caught";
	    };
	    return 0;
	}


(a) Executes successfully and prints Exception Caught
(b) Executes successfully and prints testfunction is called before
terminating
(c) Program terminates after calling the function testfunction()
(d) Program terminates without calling the function testfunction()

Answer: (c) Program terminates after calling the function testfunction(), since we have set the terminate function, using set_terminate. It calls the mentioned function before calling terminate() function.


23. True or False

	We cannot place the catch handler of a parent class before the catch handler of the child class.


Answer: True
this is why we keep the catch handler with ellipsis at last.



24. How can we mention the compiler that, a particular function will not
propagate any exceptions.

	(a) Use noexcept
	(b) Use nocatch
	(c) Use nothrow
	(d) Use noexception

Answer: (a) Use noexcept



25. What happens when an exception reaches a function marked noexcept?

	(a) The program behaves in an unexpected manner
	(b) Terminate() method will be called
	(c) It throws logic_error exception
	(d) None of the above

Answer: (b) Terminate() method will be called



26. Choose all that are applicable with respect to stack unwinding.


	(a) Destruction of variables happen in the opposite way as construction
	(b) This is a process to perform destruction of all automatic variables that go out of scope after an exception has been thrown in the try block
	(c) a and b
	(d) Only b

Answer: (c) a and b



27. What happens when an exception is thrown from a function that is
marked with throw()?

	(a) The program may not execute correctly
	(b) The exception will be caught by the catch block present in calling code
	(c) The program terminates
	(d) The program will call unexpected()

Answer: (a)
The program may not execute correctly



28. What is the meaning of attaching throw(type) with a function?


	(a) The function can throw any type of exception
	(b) The function cannot throw exception of type type
	(c) The function can throw exception of type specified
	(d) None of the above

Answer: (c)
The function can throw exception of type specified.



29. True or False

	We can’t have a finally block in a C++ program.


Answer: True



30. When will be unexpected() function called in a C++ program?

	(a) When there is more than one catch handler to handle same type of exception
	(b) When there is no catch block associated with the try block
	(c) When throw statement is not used
	(d) When there occurs an exception in function which is of different type than that of the exception specification, unexpected() method will be called

Answer: (d)



31. Identify the statements that are correct with respect to unexpected() function.

	(a) Unexpected() calls terminate() by default
	(b) It aborts the program
	(c) It is called when there is an exception thrown in a function which is of different type than that of the exception specification
	(d) b and c
	(e) a and c

Answer: (d) b and c



32. Identify the error with the following piece of code.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	using namespace std;
	void testfunction() throw(int, bool)
	{
	    cout << "testfunction is called" << endl;
	    throw true;
	}
	int main()
	{
	    try
	    {
	        testfunction();
	    }
	    catch (...)
	    {
	        cout << "Exception Caught";
	    };
	    return 0;
	}


(a) No error
(b) Termination occurs
(c) Unexpected behavior
(d) Throws invalid_cast exception

Answer: (a) No error



33. Which of these keywords is used to re-throw a caught exception?

	(a) throw
	(b) rethrow
	(c) finally
	(d) catch(…)

Answer: (a)



34. C++ throws exceptions which are of which kind among the following?

(a) Checked
(b) Unchecked

Answer: (b) Unchecked
In C++, all the exceptions are unchecked. They are not checked by the compiler during compile time. It is the programmers’ responsibility to take care of situations.



35. True or False

	We can nest try-catch blocks in a C++ program?

Answer: True



36. True or False

	Divide by zero error has to be handled by the programmers themselves.

Answer: (a) True.
std::overflow_error has to be thrown, after checking if the denominator is zero.



37. Predict the output of the following program.

	#include <iostream>
	#include <string>
	#include <typeinfo>
	#include <stdexcept>
	using namespace std;
	int main()
	{
	    try
	    {
	        cout << "Outside try" << endl;
	        try
	        {
	            int numerator = 10, denominator = 0;
	            if (denominator == 0)
	                throw std::overflow_error("Divide by zero exception occured");
	            else
	                cout << numerator / denominator;
	        }
	        catch (std::overflow_error &e)
	        {
	            cout << "Inner catch" << endl
	                 << e.what() << endl;
	            throw;
	        }
	    }
	    catch (...)
	    {
	        cout << "Outer catch" << endl;
	    };
	    return 0;
	}


(a) Outside try; after this, the program terminates
(b) Outside try
Inner catch
Divide by zero exception occurred
Outer catch
(c) Outside try
Outer catch
Inner catch
Divide by zero exception occurred
(d) Compile time error occurs

Answer: (b)


38. Choose the exception which is not handled by C++ program?

	(a) Out of range exception
	(b) Memory overflow exception
	(c) Keyboard interrupts
	(d) Invalid cast exception

Answer: (c) Keyboard interrupts. It is an asynchronous exception, which is
not supported by C++.



39. What happens when there is no exception specification attached to a
method in C++?

	(a) The method can throw no exception
	(b) The method can throw any type of exception
	(c) The method can catch any type of exception
	(d) None of the above

Answer: (b) The method can throw any type of exception



40. True or False

	range_error and out_of_range error are one and the same.

Answer: (b) False.

range_error is meant to throw exceptions when there occurs an exception in internal computations. Out_of_range is thrown when the value is not in the expected range of the specified type

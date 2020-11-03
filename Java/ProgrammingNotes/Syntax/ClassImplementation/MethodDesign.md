Method Design

Parameters
Parameters are names given to data that we pass in to the method in order for it to perform its task.

The method caller passes arguments which the method uses as parameters.
Parameters are essentially variables that receive the value of the arguments passed to the method when it is called.

The variables defined in the method header are known as formal parameters or simply parameters. A parameter is like a placeholder: when a method is invoked, you pass a value to the parameter. This value is referred to as an actual parameter or argument. The parameter list refers to the method’s type, order, and the number of parameters. The method name and the parameter list together constitute the method signature. Parameters are optional; that is, a method may contain no parameters.

 If the method requires no data, we just add a pair of empty parentheses after the method name. If a method has parameters, the number and type of arguments you pass in must match the order and type of the parameters declared by the method.

A parameter is nothing more than a local variable: A variable with a type and a name, that can be used inside the body of the method.

Values passed in and out of methods can be implicitly promoted to a larger type or explicitly cast to a smaller type.

To use an array as a parameter, we add a square bracket [] after the parameter’s data type in the method declaration:
public void printFirstElement(int[] a) {
    //Do Some Task
}

Within a method declaration, the parameter declaration syntax is the same as that used for variables. A parameter is within the scope of its method, and aside from its special task of receiving an argument, it acts like any other local variable.

The object reference on which you invoke a method is called the implicit parameter.
A method may have any number of explicit parameters that are supplied between parentheses.
The explicit parameters are so named because they are explicitly defined in a method, whereas the implicit parameter is implied in the method definition.

When calling a method, you need to provide arguments, which must be given in the same order as their respective parameters in the method signature. This is known as parameter order association.

The arguments must match the parameters in order, number, and compatible type, as defined in the method signature. Compatible type means you can pass an argument to a parameter without explicit casting, such as passing an int value argument to a double value parameter.

Final Parameter
a parameter declaration preceded with the final keyword cannot have its value reassigned during a method body or a compiler error is thrown  

Pass by reference/value
In Java, a method can modify the state of an object because the corresponding parameter variable is set to a copy of the passed object reference.
A method can change the state of an object whose reference it receives.
However, in Java, a method can never update the contents of the variable that is passed as a parameter, only the object it references

It is not possible to write a method that would change the contents of an argument to another object reference. In this regard, Java differs from languages such as C++ and C# that have a "call by reference" mechanism.

Java uses "call by value" when passing parameters.

Changing the value of the parameter variable does not affect the variable supplied in the method call. Thus, Java has no call by reference. Java uses the "call by value" mechanism for both primitive types and object references.

Keep in mind that when you create a variable of a class type, you are creating a reference to an object. It is the reference, not the object itself, that is actually passed to the method. As a result, when you pass this reference to a method, the parameter that receives it will refer to the same object as that referred to by the argument. This effectively means that objects are passed to methods by use of call-by-reference. Changes to the object inside the method do affect the object used as an argument

Remember, when an object reference is passed to a method, the reference itself is passed by use of call-by-value. However, since the value being passed refers to an object, the copy of that value will still refer to the same object referred to by its corresponding argument.


Q: Is there any way that I can pass a primitive type by reference? A: Not directly. However, Java defines a set of classes that wrap the primitive types in objects. These are Double, Float, Byte, Short, Integer, Long, and Character. In addition to allowing a primitive type to be passed by reference, these wrapper classes define several methods that enable you to manipulate their values. For example, the numeric type wrappers include methods that convert a numeric value from its binary form into its humanreadable String form, and vice versa.

Java is pass-by-value. That means pass-by-copy.
When arguments are passed to a method their bits are copied into the parameter, a local variable in the method. The value of the copy in the local variable is changed but not the value of the original outside the method

In addition to using arrays as parameters, we can also return an array from a method. To return an array from a method, we add a square bracket [] after the return type in the method declaration:
public int[] returnArray() {
    //Do Some Task
}

Q:What happens if the argument you want to pass is an object instead of a primitive?
Java passes everything by value. So if you pass a reference to an object into a method, you’re passing in the value of the reference which can still be used to mutate the object outside the method scope

When you pass in a primitive type variable, any change made to the value of that variable is only valid within the method itself. Once the program exits the method, the change is no longer valid. On the other hand, when you pass in a reference type variable, any change made to the value of that variable is valid even after the method ends.

The reason for this is because when you pass in a reference type variable, you are passing in the address of the variable. The compiler can go to the address that you passed in and make the relevant changes to the variable. On the other hand, when you pass in a primitive type variable, you are passing in the value of the variable and not the address.



Varargs: Variable-Length Arguments
A variable number of arguments of the same type can be passed to a method and treated as an array.
In the method declaration, you specify the type followed by an ellipsis (...). Only one variable-length parameter may be specified in a method, and this parameter must be the last parameter. Any regular parameters must precede it. The parameter is declared as follows:
typeName... parameterName

Java treats a variable-length parameter as an array. You can pass an array or a variable number of arguments to a variable-length parameter. When invoking a method with a variable number of arguments, Java creates an array and passes the arguments to it.

Sometimes you will want to create a method that takes a variable number of arguments, based on its precise usage. We would supply defaults if some of the arguments are not provided by the caller. In this situation, it would be convenient to pass only the arguments to which the defaults did not apply.

This feature is called varargs, which is short for variable-length arguments. A method that takes a variable number of arguments is called a variable-arity method, or simply a varargs method. The parameter list for a varargs method is not fixed, but rather variable in length. Thus, a varargs method can take a variable number of arguments.

Varargs Basics
A variable-length argument is specified by three periods (...)

void test(int … v) {
}

This syntax tells the compiler that test( ) can be called with zero or more arguments. Furthermore, it causes v to be implicitly declared as an array of type int[ ]. Thus, inside test( ), v is accessed using the normal array syntax, this is because v is an array. The ... syntax simply tells the compiler that a variable number of arguments will be used, and that these arguments will be stored in the array referred to by v. test( ) can then be called with different numbers of arguments, including no arguments at all. The arguments are automatically put in an array and passed to v. In the case of no arguments, the length of the array is zero.

A method can have “normal” parameters along with a variable-length parameter. However, the variable-length parameter must be the last parameter declared by the method. in this case all arguments are matched with parameters of the same location then remaining arguments are assumed to belong to the varargs, we cannot declare a regular parameter after the varargs parameter.

There is one more restriction to be aware of: there must be only one varargs parameter.

public static void printMax(int... numbers) {
if (numbers.length == 0) {
System.out.println("No argument passed");
return;
}

double result = numbers[0];

for (int i = 1; i < numbers.length; i++)
if (numbers[i] > result)
result = numbers[i];

System.out.println("The max value is " + result);
}


Overloading
Overloading methods enable you to define the methods with the same name within the same class, with one important restriction: the type and/or number of the parameters of each overloaded method must differ. It is not sufficient for two methods to differ only in their return types.

Method overloading supports polymorphism because it is one way that Java implements the “one interface, multiple methods” paradigm. To understand how, consider the following: In languages that do not support method overloading, each method must be given a unique name. However, frequently you will want to implement essentially the same method for different types of data.

When you overload a method, each version of that method can perform any activity you desire. There is no rule stating that overloaded methods must relate to one another. However, from a stylistic point of view, method overloading implies a relationship. Thus, while you can use the same name to overload unrelated methods, you should not.

You can overload a method that takes a variable-length argument.
the types of its vararg parameter can differ. Remember, the ... causes the parameter to be treated as an array of the specified type. Therefore, just as you can overload methods by using different types of array parameters, you can overload varargs methods by using different types of varargs. In this case, Java uses the type difference to determine which overloaded method to call. The second way to overload a varargs method is to add one or more normal parameters. Java uses both the number of arguments and the type of the arguments to determine which method to call.

Varargs and Ambiguity
Somewhat unexpected errors can result when overloading a method that takes a variable-length argument. These errors involve ambiguity because it is possible to create an ambiguous call to an overloaded varargs method.


These methods differ in only in the type of vararg used, a call that provides zero arguments to the vararg will be ambiguous:
void test(int … v) {}
void test(boolean … v) {}

test();    //Ambiguous call to test

These methods have parameters of the same type as the vararg,
void test(int … v) {}
void test(int i, int … v) {}

test(1);    //Ambiguous call to test

Because of ambiguity errors like those just shown, sometimes you will need to forego overloading and simply use two different method names. Also, in some cases, ambiguity errors expose a conceptual flaw in your code, which you can remedy by more carefully crafting a solution.
Returning
All methods return a result after performing its task.
A method that returns a value must declare a return type of that value.
If the method does not return any value, we use the void keyword.
If a method returns a value, it is called a value-returning method; otherwise, it is called a void method.
Any place where a particular type value can be used, a method call that returns that type can be used.

In order for a value-returning method to return a value, a return statement using the keyword return is required:

Syntax:
type methodName( parameter list ){
    return expression;
}

The method terminates when a return statement is executed
The value of the expression following the return keyword is provided in place of the client invocation.
If you declare a method to return a value, the expression value you return must be compatible.

A method that does not execute a return statement must have a void return type.
There can be more than one return statement in a method.
However, only one return statement is ever executed

In general, there are two conditions that cause a method to return
    when the method’s closing curly brace is encountered. (returns void)
    when a return statement is executed.


In a void method, you can cause the immediate termination of a method using:
return;

Methods that return a value to the calling routine must use this form of return:
return <value>;

Q:Is there some way to return more than one value?
A method can declare only one return value. BUT... if you want to return, say, three int values, then the declared return type can be an int array.

Q:Do I have to return the exact type I declared?
A: You can return anything that can be implicitly promoted to that type. otherwise an explicate cast is needed.

Q:Do I have to do something with the return value of a method? Can I just ignore it?
A: Java doesn’t require you to handle the return value. You might want to call a method with a non-void return type, even though you don’t care about the return value. In this case, you’re calling the method for the work it does inside the method, rather than for what the method gives returns. In Java, you don’t have to assign or use the return value.

A well-designed method performs only one task.  

Methods provide the interface that other classes use to access and modify an object instance's attributes.

Object-oriented programming follows the "client-server" model.
The code that invokes a method is called client code.
The client code requests a service by invoking a method on an object.
We think of the object as providing a service for the client.

Precondition and postcondition are the terms often used to describe the properties of
a method. Preconditions are the things that are true before the method is invoked, and
postconditions are the things that are true after the method is returned.

The precondition for the binary search method is that the list must be sorted in increasing
order. The postcondition is that the method returns the index of the element that matches the
key if the key is in the list or a negative integer k such that −k ­ 1 is the position for inserting
the key.

Modularizing Code
Modularizing makes the code easy to maintain and debug and enables the code to be reused. Methods can be used to reduce redundant code and enable code reuse. Methods can also be used to modularize code and improve the quality of the program.

Method Abstraction and Stepwise Refinement
The key to developing software is to apply the concept of abstraction.
Method abstraction is achieved by separating the use of a method from its implementation. The client can use a method without knowing how it is implemented. The details of the implementation are encapsulated in the method and hidden from the client who invokes the method. This is also known as information hiding or encapsulation. If you decide to change the implementation, the client program will not be affected, provided that you do not change the method signature. The implementation of the method is hidden from the client in a “black box,”

The concept of method abstraction can be applied to the process of developing programs. When writing a large program, you can use the divide-and-conquer strategy, also known as stepwise refinement, to decompose it into subproblems. The subproblems can be further decomposed into smaller, more manageable problems.

Top-Down Design
Beginning programmers often start by trying to work out the solution to every detail. Although details are important in the final program, concern for detail in the early stages may block the problem-solving process. To make problem solving flow as smoothly as possible, this example begins by using method abstraction to isolate details from design and only later implements the details.

Top-Down and/or Bottom-Up Implementation
Now we turn our attention to implementation. In general, a subproblem corresponds to a method in the implementation, although some are so simple that this is unnecessary. You would need to decide which modules to implement as methods and which to combine with other methods. Decisions of this kind should be based on whether the overall program will be easier to read as a result of your choice.

You can use either a “top-down” or a “bottom-up” approach.

The top-down approach implements one method in the structure chart at a time from the top to the bottom. Stubs—a simple but incomplete version of a method—can be used for the methods waiting to be implemented. The use of stubs enables you to quickly build the framework of the program.

The bottom-up approach implements one method in the structure chart at a time from the bottom to the top. For each method implemented, write a test program, known as the driver, to test it. The top-down and bottom-up approaches are equally good: Both approaches implement methods incrementally, help to isolate programming errors, and make debugging easy. They can be used together.

Benefits of Stepwise Refinement
Stepwise refinement breaks a large problem into smaller manageable subproblems. Each subproblem can be implemented using a method. This approach makes the program easier to write, reuse, debug, test, modify, and maintain.

Simpler Program
Rather than writing a long sequence of statements in one method, stepwise refinement breaks it into smaller methods. This simplifies the program and makes the whole program easier to read and understand.

Reusing Methods
Stepwise refinement promotes code reuse within a program. This reduces redundant code.

Easier Developing, Debugging, and Testing
Since each subproblem is solved in a method, a method can be developed, debugged, and tested
individually. This isolates the errors and makes developing, debugging, and testing easier.
When implementing a large program, use the top-down and/or bottom-up approach. Do not
write the entire program at once. Using these approaches seems to take more development time
(because you repeatedly compile and run the program), but it actually saves time and makes
debugging easier.

Recursion
In Java, a method can call itself. This process is called recursion, and a method that calls itself is said to be recursive. In general, recursion is the process of defining something in terms of itself and is somewhat similar to a circular definition. The key component of a recursive method is a statement that executes a call to itself.

When a method calls itself, new local variables and parameters are allocated storage on the stack, and the method code is executed with these new variables from the start. A recursive call does not make a new copy of the method. Only the arguments are new. As each recursive call returns, the old local variables and parameters are removed from the stack, and execution resumes at the point of the call inside the method. Recursive methods could be said to “telescope” out and back. Recursive versions of many routines may execute a bit more slowly than their iterative equivalents because of the added overhead of the additional method calls. Too many recursive calls to a method could cause a stack overrun. Because storage for parameters and local variables is on the stack and each new call creates a new copy of these variables, it is possible that the stack could be exhausted. If this occurs, the Java run-time system will cause an exception. However, you probably will not encounter this unless a recursive routine runs wild. The main advantage to recursion is that some types of algorithms can be implemented more clearly and simply recursively than they can be iteratively

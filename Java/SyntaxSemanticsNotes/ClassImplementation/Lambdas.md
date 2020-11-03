Lambda expressions are the most important new feature of Java 8.
Lambda expressions allow you to pass the functionality of a method as a parameter.

A lambda expression can be used only in a context in which a target type is specified.
A functional interface defines the target type of a lambda expression.
Key to understanding the lambda expression are functional interfaces


Functional Interfaces
An Interface that contains exactly one abstract method is known as functional interface.
This method specifies the intended purpose of the interface, generally representing a single action.
sometimes referred to as a SAM type, Single Abstract Method type

The standard interface Runnable is a functional interface because it defines only one method: run().
Therefore, run() defines the action of Runnable.

Syntax:
@FunctionalInterface
interface MyNumber{
double getValue();
}

The method getValue() is implicitly abstract, and it is the only method defined by MyValue.
Since this interface only contains one abstract method, it is known as a functional interface.



Beginning with JDK 8, it is possible for an interface to have one or more default methods.
A functional Interface can have any number of default, static, private or object class methods but can contain only one abstract method.

Because non-default, non-static, non-private interface methods are implicitly abstract, there is no need to use the abstract modifier (although you can specify it).

A functional interface may specify any public method defined by Object, such as equals(), without affecting its “functional interface” status. The public Object methods are considered implicit members of a functional interface because they are automatically implemented by an instance of a functional interface.







Lambda Expression
A lambda expression is, essentially, an anonymous (unnamed) method.
However, this method is not executed on its own.
Instead, it is used to implement a method defined by a functional interface.
Thus, a lambda expression results in a form of anonymous class.
However, they allow you to eliminate the enclosing method and anonymous class declarations.
As a result, they are sometimes called anonymous functions.
Lambda expressions are also commonly referred to as closures.

We can implement functional interfaces using lambda expressions

Syntax:
(parameter list) -> { body; };

The lambda operator, or arrow operator, –>,  divides a lambda expression into two parts.
The left side specifies a list of parameters required by the lambda expression.
The right side is the lambda body, it specifies statements executed by the lambda expression.


Suppose you want to implement the MyNumber functional interface:
double getValue() {return 12.3; };

We can rewrite it as the following lambda expression:
() -> 12.3;

The left side is an empty pair of parentheses indicating that the method has no parameter.
The right side simply consists of the number 12.3, which is returned.

Suppose you want to implement getValue() as
double getValue() {
int counter = 1;
int sum = 0;
while (counter<5) {
sum = sum + counter;
counter++;
}
return sum;
}

You can rewrite it as the following lambda expression:

() -> {
int counter = 1;
int sum = 0;
while (counter<5){
sum = sum + counter;
counter++;
}
return sum;
};

The lambda body is known as either an
expression body    consists of a single expression.
block body        consists of a code block, allowing multiple statements.
A block body is enclosed in braces with a return statement and a semi-colon after the closing brace.


Lambda Expressions with Parameters

@FunctionalInterface
interface MyNumberPara{
double getValue(int n, int m);
}

This interface has a method called getValue() that has two int parameters n and m.
Method Implementation:

double getValue(int n, int m) {
return n + m;
}

Lambda expression:
(n, m) -> n + m;

It is not necessary for us to explicitly state the data type of the parameters when we use lambda expressions. Although it is possible to explicitly specify the type of a parameter, often you won’t need to because, in many cases, its type can be inferred.

Like a named method, a lambda expression can specify as many parameters as needed.
When a lambda expression has only one parameter, it is not necessary to surround the parameter name with parentheses when it is specified on the left side of the lambda operator.


Example
As mentioned earlier, a lambda expression is not executed on its own. Rather, it forms the implementation of the abstract method defined by the functional interface that specifies its target type. As a result, a lambda expression can be specified only in a context in which a target type is defined. One of these contexts is created when a lambda expression is assigned to a functional interface reference. Other target type contexts include variable initialization, return statements, and method arguments, to name a few.

@FunctionalInterface
interface MyNumber {
double getValue();
}

First, a reference to the functional interface MyNumber is declared:
MyNumber myVal;

Next, a lambda expression is assigned to that interface reference:
myVal = () -> 98.6;

This lambda expression is compatible with getValue() because, like getValue(), it has no parameters and returns a double result. In general, the type of the abstract method defined by the functional interface and the type of the lambda expression must be compatible. If they aren’t, a compile-time error will result.

As you can probably guess, the two steps just shown can be combined into a single statement, if desired
MyNumber myVal = () -> 98.6;

When a lambda expression occurs in a target type context, an instance of a class is automatically created that implements the functional interface, with the lambda expression defining the behavior of the abstract method declared by the functional interface. When that method is called through the target, the lambda expression is executed. Thus, a lambda expression gives us a way to transform a code segment into an object.














Example
Now that we are familiar with some basic lambda expressions, let’s understand how we invoke these methods. To invoke these methods, we have to do two things:
First, we need to declare a reference to each of the functional interfaces. We do that by writing
MyNumber num1;
MyNumberPara num2;

Recall that we cannot instantiate an interface, hence we cannot write something like
MyNumber num1 = new MyNumber();

However, declaring a reference to it is valid. After declaring the references, we can assign multiple lambda expressions to them.

Here, we’ll assign the lambda expressions with no parameter to num1 and the lambda expressions with two parameters to num2.

Following that, we can use num1 and num2 to call the getValue() and getValue2() methods using the dot operator:


package lambdademo;

 @FunctionalInterface
interface MyNumber{
double getValue();
 }

 @FunctionalInterface
interface MyNumberPara{
double getValue2(int n, int m);
 }

public class LambdaDemo {
public static void main(String[] args) {
MyNumber num1;

num1 = () -> 12.3;
System.out.println("The value is " + num1.getValue());    //12.3

num1 = () -> 2 + 3;
System.out.println("The value is " + num1.getValue());    //5.0

num1 = () -> {
int counter = 1;
int sum = 0;
while (counter<5) {
sum += counter;
counter++;
 }

return sum;
 };
 System.out.println("The value is " + num1.getValue());    //10.0

 MyNumberPara num2 = (n, m) -> n + m;
 System.out.println("The value is " + num2.getValue2(2,3));    //5.0

 num2 = (n, m) -> {
if (n > 10) return m;
else return m+1;
 };
 System.out.println("The value is " + num2.getValue2(3,9));    //10.0
     }

 }

Q: Earlier you mentioned that I can explicitly declare the type of a parameter in a lambda expression if needed. In cases in which a lambda expression requires two or more parameters, must I specify the types of all parameters, or can I let one or more use type inference?
A: In cases in which you need to explicitly declare the type of a parameter, then all of the parameters in the list must have declared types. For example, this is legal:

(int n, int d) -> (n%d)==0
But this is not legal:
(int n, d) -> (n%d)==0
Nor is this legal:
(n, int d) -> (n%d)==0


Generic Functional Interfaces
A lambda expression, itself, cannot specify type parameters. Thus, a lambda expression cannot be generic. (Of course, because of type inference, all lambda expressions exhibit some “generic-like” qualities.) However, the functional interface associated with a lambda expression can be generic. In this case, the target type of the lambda expression is determined, in part, by the type argument or arguments specified when a functional interface reference is declared.

Instead of having two functional interfaces whose methods differ only in their data types, it is possible to declare one generic interface that can be used to handle both circumstances. The following program shows this approach:

interface SomeTest<T> {
boolean test(T n, Tm);
}

class GenericFunctional InterfaceDemo {
public static void main (String args ) {
// This lambda expression determines if one integer is a factor of another .
SomeTest<Integer> isFactor = (n, d) -> (n % d) == 0;
if (isFactor.test (10, 2))
System.out.println("2 is a factor of 10") ;
System.out.println();

// The next lambda expression determines if one Double is a factor Of another .
SomeTest<Doub1e> isFactorD = (n, d) -> (n % d) == 0;
if (isFactor.test (212.0, 4.0))
            System.out.println("4.0 is a factor of 212.0") ;
System.out.println();

SomeTest<String> isln = (a, b) -> a.indexOf(b) != -1;

String str = "Generic Functional Interface";
System.out.println("Testing string: " + str);
if (isln.test(str, "face")) System.out.println( "'face' is found. " ) ;
}
}

Here, T specifies the type of both parameters for test(). This means that it is compatible with any lambda expression that takes two parameters of the same type and returns a boolean result.

Pass a Lambda Expression as an Argument
A lambda expression can be used in any context that provides a target type. The target contexts used by the preceding examples are assignment and initialization. Another one is when a lambda expression is passed as an argument. In fact, passing a lambda expression as an argument is a common use of lambdas. Moreover, it is a very powerful use because it gives you a way to pass executable code as an argument to a method. This greatly enhances the expressive power of Java.

Q: In addition to variable initialization, assignment, and argument passing, what other places constitute a target type context for a lambda expression?

A: Casts, the ? operator, array initializers, return statements, and lambda expressions, themselves, can also serve as target type contexts.
Lambda Expressions and Variable Capture

Variables defined by the enclosing scope of a lambda expression are accessible within the lambda expression. For example, a lambda expression can use an instance variable or static variable defined by its enclosing class.

A lambda expression also has access to this (both explicitly and implicitly), which refers to the invoking instance of the lambda expression’s enclosing class. Thus, a lambda expression can obtain or set the value of an instance variable or static variable and call a method defined by its enclosing class.

However, when a lambda expression uses a local variable from its enclosing scope, a special situation is created that is referred to as a variable capture. In this case, a lambda expression may only use local variables that are effectively final. An effectively final variable is one whose value does not change after it is first assigned. There is no need to explicitly declare such a variable as final, although doing so would not be an error. (The this parameter of an enclosing scope is automatically effectively final, and lambda expressions do not have a this of their own.) It is important to understand that a local variable of the enclosing scope cannot be modified by the lambda expression. Doing so would remove its effectively final status, thus rendering it illegal for capture.

interface MyFunc {
int func(int n);
}

class VarCapture {
public static void main (String args[] ) {
// A local variable that can be captured.
int num = 10;

MyFunc myLambda = n -> {
// This use Of num is 0K. It does not modify num.
int v = num + n;
// The following would be illegal as it attempts to modify the value of num.
// n++;
return v;
};

// Use the lambda. This will display 18.
System.out.println(myLambda.func(8));
// The following line would also cause an error, because
// it would remove the effectively final status from num.
// num = 9;
}
}

As the comments indicate, num is effectively final and can, therefore, be used inside myLambda. This is why the println() statement outputs the number 18. When func() is called with the argument 8, the value of v inside the lambda is set by adding num (which is 10) to the value passed to n (which is 8). Thus, func() returns 18. This works because num is not modified after it is initialized. However, if num were to be modified, either inside the lambda or outside of it, num would lose its effectively final status. This would cause an error, and the program would not compile.

It is important to emphasize that a lambda expression can use and modify an instance variable from its invoking class. It just can’t use a local variable of its enclosing scope unless that variable is effectively final.

Q: Can a lambda expression use a parameter that is an array?

A: Yes. However, when the type of the parameter is inferred, the parameter to the lambda expression is not specified using the normal array syntax. Rather, the parameter is specified as a simple name, such as n, not as n[ ]. Remember, the type of a lambda expression parameter will be inferred from the target
context. Thus, if the target context requires an array, then the parameter’s type will automatically be inferred as an array. To better understand this, let’s work through a short example.
interface MyTransform<T>{
    void transform(T [] a);
}

Notice that the parameter to the transform() method is an array of type T. Now, consider the following lambda expression that uses MyTransform to convert the elements of an array of Double values into their square roots:

MyTransform<Double> sqrts = v -> {
    for(int i = 0; i < v.length; i++) v[i] = Math.sqrt(v[i]);
}

Here, the type of a in transform() is Double[ ], because Double is specified as the type parameter for MyTransform when sqrts is declared. Therefore, the type of v in the lambda expression is inferred as Double[ ]. It is not necessary (or legal) to specify it as v[ ].

One last point: It is legal to declare the lambda parameter as Double[ ] v, because doing so explicitly declares the type of the parameter. However, doing so gains nothing in this case.


Throw an Exception from Within a Lambda Expression

A lambda expression can throw an exception. If it throws a checked exception, however, then that exception must be compatible with the exception(s) listed in the throws clause of the abstract method in the functional interface. For example, if a lambda expression throws an IOException, then the abstract method in the functional interface must list IOException in a throws clause.

import java. io.*;

interface MylOAction {
int ioAction (Reader rdr) throw IOException
}
class LambdaExcept ionDemo {
public static void main (String args [J) {
// This block lambda could throw an IOException.
// Thus, IOException must be specified in a throws
// clause Of ioAction() in MylOAction.

MylOAction mylO (rdr) - > {
int ch = rdr.read() ; / / could throw IOException
return ch;
};
}
}

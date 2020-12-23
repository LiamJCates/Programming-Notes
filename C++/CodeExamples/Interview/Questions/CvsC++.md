All questions use g++

### Question Set 1

1. What is the output of the code?

  #include <iostream.h>
  void main()
  {
    cout<< "hello world";
  }

Answer:
Fatal error: iostream.h: no such file or directory

A fatal error terminates compilation. Then no other errors will be thrown. This is because 'g++' doesn't support this way of compilation.

However, this is compiler dependent, in other compilers and some older versions it might give 'hello world'.



2. What will be error thrown by the code?

  #include <iostream>
  using namespace std;
  int main()
  {
    cout<< "hello world";
  }

Answer:
error: '::main' must return 'int'

In 'G++' the return type of 'main' must be of 'int' and not 'void'. Thus, the error. But it is also to be noted that the compiler doesn't throw any error or warning even if there is no return statement given at the end of 'main' as main defaults to 0.



3. What will be error thrown by the code?

  #include <iostream>
  int main()
  {
    std::cout<< "hello world";
  }

Answer:
None
Trick question, this program compiles normally and outputs hello world as intended.



4. What is the output of the code? (without header file and namespace)

  int main()
  {
    cout<< "hello world";
  }

Answer:
'cout' was not declared in this scope. Unlike 'C' in 'C++' you
cannot compile a code without the header file.



5. What will be the error thrown by the code? (without header file)

  using namespace std;
  int main()
  {
    cout<< "hello world";
  }

Answer:
error: 'cout' was not declared in this scope
'cout' is defined inside the header file only so it throws an error.



6. What will be the error thrown by the code?

  #include<iostream.h>
  using namespace std;
  int main()
  {
    cout<< "hello world";
  }

Answer:
Fatal error: iostream.h: No such file or directory.
The usage of '.h' for 'iostream' is not implemented in 'G++'.



7. What is the output of the code?
  #include <iostream>
  using namespace std
  int main()
  {
    cout<< "hello world";
  }

Answer: error: expected ';' before 'int'
Like 'C'';' is mandatory in every single statement.



What is the output of the code?
#include<iostream>
using namespace std
int main()
{ std::cout<< "hi";}

Answer:
error: expected ';' before 'int'
The additional 'std' doesn't take care of the missing ';' in the using declaration.



What is the output of the code?
#include<iostream>
using namespace std;
int main()
{ std::cout<< "hi";}

Answer: hi
This works normally, while the resolution of std:: is unnecessary due to the using declaration it does not cause an issue.



### Question Set 2
1. What is the output of the code?

  #include<iostream>
  #include<math.h>
  using namespace std;
  int main()
  {
    cout<< sqrt(9);
  }

Answer: 3
for other header file '.h'; 'sqrt' is the inbuilt function that
returns the square root of the given number.



2. What is the output of the code?
  #include <iostream>
  #include<math>
  using namespace std;
  int main()
  {
    cout<< sqrt(9);
  }

Answer: fatal error: math: No such file or directory




3. What is the output of the code?
  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    cout<< "hi "<<a;
  }

Answer: hi 9
'cout' can print multiple values of different types simultaneously.



4. What is the output of the code?
  #include<iostream>
  using namespace std;
  int main()
  {
    cout<< "hi "<<9;
  }

Answer: hi 9
This also works normally.



5. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    cout<< "hi "<< ("%d",a);
  }

Answer: "hi 9"
Here, the ',' in between overwrites "%d" by 'a'. This is same as in 'C'.



6. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    cout<< 9,8,7,6;
  }

Answer: 9
For every single variable and value the extraction operator is required. This is called cascading operators.



7. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a = 9;
    cout<< a++<<a++<<a++;
  }

Answer: 11109
The associativity of the operator is from right to left.



8. What is the output of the code?

  #include <iostream>
  using namespace std;
  int main()
  {
    int a=9;
    cout<< ++a<<++a<<++a;
  }

Answer: 121212
This result is because the prefix increment will point to the value in the each usage. Whereas in postfix increment the temporary value alone will be stored and not the pointer to the value is used.



9. What is the output of the code?

  #include<iostream>
  #include<math.h>
  using namespace std;
  int main()
  {
    cout<< sqrt(9)<< " "<<sqrt(5);
  }


Answer: 3 2.23607
The cout handles each value according to its value.



10. What is the output of the code? (assume given: 2,3,4)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a>>b>>c;
    cout<< a<< " "<< " "<<b<< " "<<c;
  }

Answer: 2 3 4
This is called cascading insertion operator. Here also the
associativity is from left to right only.



11. What is the output of the code? (assume given: 2,3,4)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a>>b>>c;
    cout<< a;
    cout<< b;
    cout<< c;
  }

Answer: 234
Unless new line is specified the output will not be taken to the
next line.



12. What is the output of the code? (assume given: 2,3,4.34)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a>>b>>c;
    cout<< a;
    cout<< b;
    cout<< c;
  }

Answer: 234
When data of different types is given, it internally converts it into the required type and saves it.



13. What is the output of the code? (values given: 2.23,3,4.34)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a>>b>>c;
    cout<< a;
    cout<< b;
    cout<< c;
  }

Answer: (d) 2XX
is the output. 'cin' stops reading the value when it encounters a mismatch in type.



14. What is the output of the code? (values given: 2.23,3,4.34)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    cout<< a;
    cout<< b;
    cout<< c;
  }

Answer: 2XX
This also works in the same way. When one 'cin' fails all the others are skipped.



15. What is the output of the code? (values given: 2.23,3,4.34)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    cout<< int(a);
    cout<< b;
    cout<< int(c);
  }

Answer: 2XX
This also works the same as above. But the conversion has no issues, it is all the same as 'C'.



16. What is the output of the code? (assume given: 2.23,3,4.34)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a,b,c;
    cin>>int(a);
    cin>>b;
    cin>>int(c);
    cout<< a;
    cout<< b;
    cout<< c;
  }

Answer: error
error: no match for 'operator>>' (operand types are 'std::istream' {aka 'std::basic_istream<char>'} and 'int')

It gives a long description of the internal definition of the operator and the possible overloading of it. Overloading is a concept of object oriented programing which means giving multiple definitions for an operator based on usage.



17. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    cin>>9;
    cout<< 9;
  }

Answer: errors
error: no match for 'operator>>' (operand types are 'std::istream' {aka 'std::basic_istream<char>'} and 'int')

description is the same as above.



18. What is the output of the code? (assume the value given for 'a' is 3)

  #include<iostream>
  using namespace std;
  int main()
  {
    int a;
    cin<<a;
    cout<< a;
  }

Answer: error
error: no match for 'operator<<' (operand types are 'std::istream' {aka 'std::basic_istream<char>'} and 'int')

This means, "<<" operator has no possible usages with 'cin'.



19. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9,b=0;
    cout<< a<<endl<<b;
  }

Answer: 9 0 (in consecutive lines)
"endl" is used to specify new line in C++.



20. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9,b=0;
    cout<< a << "\n" << b;
  }

Answer: 9 0(in consecutive lines)
This works normally and is equivalent to the  "endl" syntax introduced for C++.



21. What is the output of the code?
  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int& b=a;
    cout<< a<< " "<<b;
  }

Answer: 9 9
The variable '&b' is called reference variable, which is specific to C++. It is a way similar to pointers. But still has some major differences. So both reference variables and pointers exist in C++. Here 'b' points to value of 'a'. Reference variable means giving multiple names for same memory location.


22. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int& b=0;
    cout<< a<< " "<<b;
  }

Answer: error
error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

Unlike pointers, reference variables cannot be initialised to 0.



23. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int& b=0;
    cout<< a<< " "<<b;
  }


Answer: error
error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

It is also to be noted that 'rvalue' is used in error statement which was not used in 'C'.



24. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int& b=NULL;
    cout<< a<< " "<<b;
  }

Answer: error
error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
Unlike pointers, reference variables cannot be initialised to NULL.



25. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int& b;
    &b=a;
    cout<< a<< " "<<b;
  }
(a) 9 9
(b) 9 0
(c) Error
(d) None of the above
Answer: error
error: ‘b’ declared as reference but not initialized

Reference variables should be declared and initialised in the same statement. They cannot be initialised later.



26. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  int main()
  { int a=9;
    int& b;
    &b=a;
    cout<< a<< " "<<b;
  }

Answer: errors
error: ‘b’ declared as reference but not initialized
error: lvalue required as left operand of assignment
(c) Separate usage of reference operator is not legal in C++.



27. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int b=a<<2;
    cout<<b;
  }

Answer: 36
When used on an int value "<<" is shift left for numbers. 'a<<n' means shift the bits of 'a' to left by n bits. This is equal to multiplication by 2 power n. Hence, here it is 36 (9 × 4).



28. What is the output of the code?

  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    int b=a>>2;
    cout<<b;
  }

Answer: 2
When used on an int value ">>" is shift right for numbers. 'a>>n' means shift the bits of 'a' to right by n bits. This is equivalent to division by 2 power n. Here, 9/2 = 4 and 4/2 gives 2 as the final output.



29. What is the output of the code?
  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    cout<<a<<2;
  }

Answer: 92
Here the '<<' in between 'a' and 2 gets associated with the 'cout'. This shows that cout maintains priority over '<<'.



30. What is the output of the code?
  #include<iostream>
  using namespace std;
  int main()
  {
    int a=9;
    cout<<(a<<2);
  }

Answer: 36
The parenthesis changes the associativity.


What is the output of the code?
  #include<iostream>
  using namespace std;
  int a=3;
  int main()
  {
    int a=9;
    cout<<::a;
  }

Answer: 3
The operator '::' is called scope resolution operator. It is used to access the global variable even if there is a local variable of the same name.



31. What is the output of the code?
  #include<iostream>
  using namespace std;
  struct tea
  {
    int rate;
    void bonus() { cout<<"festival"; }
  }t;

  int main()
  {
    t.rate=9;
    cout<<t.rate;
    t.bonus();
  }

Answer: 9festival
Unlike 'C' Structure in C++ can have functions.



32. What is the output of the code?
  #include<iostream>
  using namespace std;
  struct tea
  {
    int rate;
    float f;
    void bonus(){ cout<<"festival"; }
  }t;

  int main()
  {
    t.rate=9;
    cout<<sizeof(t);
  }

Answer: 8
Both int and float are typically 4 bytes and functions do not consume any. Memory allocation of structure and union is similar to 'C'.



33. What is the output of the code?
  #include<iostream>
  using namespace std;
  struct tea
  {
    int rate;
    struct bun{ int temp; };
  }t;

  int main()
  {
    t.rate=9;
    struct bun b;
    b.temp = 98;
    cout<<b.temp;
  }

Answer: error
error: aggregate ‘main()::bun b’ has incomplete type and cannot be defined
structures inside another structure do not get global scope in C++.

Unlike 'C' it handles it differently.



34. What is the output of the code?

  #include<iostream>
  using namespace std;
  struct tea
  {
    int rate;
    struct bun{ int temp; };
    struct bun b;
  }t;

  int main()
  {
    t.rate=9;
    b.temp = 98;
    cout<<b.temp;
  }

Answer: error
error: ‘b’ was not declared in this scope
We cannot treat the object of inner struct is treated as a member of the outer struct.



35. What is the output of the code?
  #include<iostream>
  using namespace std;
  struct tea
  {
    int rate;
    struct bun{ int temp; };
    struct bun b;
  }t;

  int main()
  {
    t.rate=9;
    t.b.temp = 98;
    cout<<t.b.temp;
  }

Answer: 98
This is the most apt way of accessing members. It is also to be noted that all these changes are applicable to the 'union' also in C++.


36. What is the output of the code?
  #include<iostream>
  using namespace std;
  union tea
  {
    int rate;
    void bonus(){ cout<<"festival"; }
  }t;

  int main()
  {
    t.rate=9;
    cout<<t.rate;
    t.bonus();
  }

Answer: 9festival
Unlike 'C' Union in C++ can have functions.



37. What is the output of the code?
#include<iostream>
using namespace std;
union tea
{
  int rate;
  void bonus(){ cout<<"festival"; }
}t;

int main()
{
  cout<<sizeof(t);
}

Answer: 4
An int is typically 4 bytes and functions do not consume any.
Memory allocation of structure and union is similar to 'C'.



38. What is the output of the code?
  #include<iostream>
  using namespace std;
  class tea
  {
    int rate;
    void bonus(){ cout<<"festival"; }
  }t;

  int main()
  {
    t.rate=9;
    cout<<t.rate;
    t.bonus();
  }

Answer: Error
error: ‘int tea::rate’ is private within this context
error: ‘void tea::bonus()’ is private within this context

'class' is the most advantageous new concept of 'C++'. This forms the basis for Object Oriented Programming. By default all the variables and functions are treated as 'private' variables.



39. What is the output of the code?
  #include<iostream>
  using namespace std;
  class tea
  {
    public:
    int rate;
    void bonus(){ cout<<"festival"; }
  }t;

  int main()
  {
    t.rate=9;
    cout<<t.rate;
    t.bonus();
  }

Answer: 9festival
This works normally. Only 'public' data will be accessible by the objects.

What is the output of the code?
  #include<iostream>
  using namespace std;
  class tea
  {
    public:
    int rate;
    void bonus(){ cout<<"festival"; }
  }t;

  int main()
  {
    cout<<sizeof(t);
  }

Answer: 4
An int is typically 4 bytes and functions do not consume any.
Memory allocation of structure and union is similar to 'C'.

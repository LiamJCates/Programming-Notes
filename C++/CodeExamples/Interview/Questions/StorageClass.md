If no storage-class specifier is provided, the defaults are:
    extern for all functions
    extern for objects at file scope
    auto for objects at block scope

The auto keyword is no longer a C++ storage-class specifier, and the register keyword is deprecated.


1. What is the output of the code?

  #include<iostream>
  using namespace std;
  void fun() {
    int m = 9;
    cout << m;
  }
  int main()
  {
    fun();
  }

Answer: 9

The storage class of m is auto.
It means the variable will be automatically deleted after the block in which it is defined is completed.



2. What is the output of the code?

  #include<iostream>
  using namespace std;
  void fun() {
    auto int m = 9;
    cout << m;
  }

  int main()
  {
    fun();
  }

Answer: error
error: two or more data types in declaration of ‘m’.
The auto keyword is no longer a C++ storage-class specifier.



11. What is the output of the code?

#include<iostream>
using namespace std;
void fun() {
  static int count;
  cout << count;
};
int main()
{
    fun();
  }

(a) 0(b) Unpredictable(c) Error(d) None of the above
Answer: (a)‘ static’ storage class means that the variable will be stored in
  memory even after the block completes its execution.The variable will be
freed only after the execution of the whole program.If next time the
variable is called, it retains the old value.



12. What is the output of the code?

  #include<iostream>
  using namespace std;
  void fun() {
    static int count;
    cout << count;
  };
  int main()
  {
    fun();
    cout << count;
  }

(a) 0(b) 1(c) Error(d) None of the above
Answer: (c) Even though‘ count’ is in memory, it will be accessible only
within its scope.



13. What is the output of the code?

#include<iostream>
using namespace std;
void fun() {
  static int count;
  cout << count++ << “”;
};
int main()
{
    fun();
    fun();
    fun();
  }

(a) 0 1 2(b) 0 0 0(c) Error(d) None of the above
Answer: (a) As said previously, as‘ count’ is static it will retain the old
value.



14. What is the output of the code?

#include<iostream>
using namespace std;
void fun() {
  static int count = 0;
  cout << count++ << “”;
};
int main()
{
    fun();
    fun();
    fun();
  }

(a) 0 1 2(b) 0 0 0(c) Error(d) None of the above
Answer: (a) Repeated declaration of ‘static’ variable is skipped, so the
assignment is also skipped.It works normally.



15. What is the output of the code?

#include<iostream>
using namespace std;
void fun() {
  static int count;
  count = 0;
  cout << count++ << “”;
};
int main()
{
    fun();
    fun();
    fun();
  }

(a) 0 1 2(b) 0 0 0(c) Error(d) None of the above
Answer: (b) Here the variable will be reinitialised on every call.



16. What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    int r = 9;
    while (r--> 5) {
      static int count;
      cout << count++;
    }
  }

(a) 0 1 2(b) 0 1 2 3(c) 0 0 0(d) None of the above
Answer: (b) It works even in loops as explained.It will be declared only on
the first iteration.



17. What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    static int count;
    cout << count++ << “”;
    main();
  }

(a) 0 1 2 3…..till stack overflows(b) 0 0 0….till stack overflows(c) Error(d) None of the above
Answer: (a) Works as expected.It is a way to find the maximum number of
  recursions possible.



18. What is the output of the code?

#include<iostream>
using namespace std;
void fun(int c) {
  cout << c;
}
int main()
{
    static int count = 9;
    fun(count);
  }

(a) 9(b) 0(c) Error(d) None of the above
Answer: (a) A static value can be passed to a
function.It just takes the
value without any issues.But the dummy variable will no more be static.



19. What is the output of the code?

#include<iostream>
using namespace std;
void fun(auto int c) {
  cout << c;
}
int main()
{
    static int count = 9;
    fun(count);
  }

(a) 9(b) 0(c) Error(d) None of the above
Answer: (a) Even this works.As the value is just copied there is no issue of
  storage class clash .



20. What is the output of the code?

#include<iostream>
using namespace std;
void fun(auto int * c) {
  cout << c;
}
int main()
{
    static int count = 9;
    fun( & count);
  }

(a) 9(b) 0(c) Error(d) None of the above
Answer: (a) Passing the value by reference also doesn’ t consider the
storage class of the variable.



21. What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    static count = 9;
    cout << count;
  }

(a) 9(b) 0(c) Error(d) None of the above
Answer: (c)“‘ count’ does not name a type”.Storage classes do not
  associate any type with the variable.



22. What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    static int c = 9;
    cout << sizeof(c);
  }

(a) 4(b) 6(c) Error(d) None of the above
Answer: (a)‘ static’ storage class doesn’ t affect the size of the variable.It
just changes the storage properties of the variable.



23. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
}S;

int main()
{
    S.c = 8;
    cout << S.c;
  }

(a) 8(b) 0(c) Error(d) None of the above
Answer: (c)‘ static’ member means, irrespective of the number of objects
the member will be only one.It retains common value in a common
memory.As it is not associated with any object it cannot be initiated with
an object.It should be initiated only by using the class name with‘::’
  operator.



24. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c = 8;
}S;

int main()
{
    cout << sto::c;
  }

(a) 8(b) 0(c) Error(d) None of the above
Answer: (c) Even though the static variable is common to the class, it
cannot be initiated within the class.



25. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
}S;

int sto::c = 3;
int main()
{
    cout << sto::c;
  }

(a) 3(b) 0(c) Error(d) None of the above
Answer: (a) This is the way of initialising static variable.



26. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
}S;

int sto::c = 6;
int main()
{
    cout << S.c;
  }

(a) 6(b) Unpredictable(c) Error(d) None of the above
Answer: (a) Static variable can be read with separate objects also.



27. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
}S;

sto::c = 6;
int main()
{
    cout << S.c;
  }

(a) 6(b) Unpredictable(c) Error(d) None of the above
Answer: (c) While initializing also type is required.It throws“‘ c’ in ‘class
sto’ and does not name a type”.



28. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    sto() {
      static int c = 4;
      cout << c;
    }
};
int main()
{
    sto S;
  }

(a) ISO C++forbids in -class initialization of member‘ sto::c’(b) Undefined reference to‘ sto::c’(c)‘ sto’ has no member named‘ c’(d) No error
Answer: (d) Here the static variable goes into the
function.So it is not a
class member.So it has no error.



29. What is the output of the code?

#include<iostream>
using namespace std;
class student {
  public:
    void fun() {
      cout << m;
    }
}S;

int student::m;
int main()
{
    S.m = 9;
    S.fun();
  }

(a) 9(b) 0(c) Unpredictable(d) Error
Answer: (d) This doesn’ t make the member‘ m’ as static.Instead it throws
the error“‘ int student::m’ is not a static member of ‘class student’”.Static
members cannot be added like this.They should be declared inside the class
only.



30. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  static int b;
}S;

int sto::b = 6;
int sto::c = & (sto::b);
int main()
{
    cout << * (sto::c);
  }

(a) 6(b) Unpredictable(c) Error(d) None of the above
Answer: (c) This type of usage is not possible.The‘ & ’and‘ * ’do not go
  well with static variables.So pointers cannot be static members.



31. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
}S;

int sto:: * c = NULL;
int main()
{
    cout << sizeof(sto::c);
  }

(a)‘ c’ was not declared in this scope(b) Expected variable before‘ * ’ in ‘int sto:: * c = NULL’(c) Both‘ a’ and‘ b’(d) None of the above
Answer: (d) It throws no error.It is actually the right way of using static
pointers.The output will be‘ 8’ as usual.



32. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
}S;

int sto:: * c = NULL;
int main()
{
    cout << sizeof(sto:: * c);
  }

(a) ISO C++forbids pointer of static‘ sto::c’(b) Expected variable before‘ * ’ in ‘sto:: * c’(c) Expected unqualified id before‘ * ’token(d) No error
Answer: (c) This usage inside main causes problem.



33. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  int b;
}S;

S.b = 6;
int sto::c = & (S.b);
int main()
{
    cout << sizeof(sto:: * c);
  }

(a) 6(b) 8(c) Error(d) Unpredictable
Answer: (c) Global object member cannot be defined globally.It can be
initialised only inside a particular scope.



34. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  static int b;
};
int sto::b = 6;
int * sto::c = & (sto::b);
int main()
{
    cout << * (sto::c);
  }

(a) 6(b) 0(c) Error(d) Unpredictable
Answer: (a) This works properly.



35. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  static int b;
}S;

int main()
{
    S.b = 9;
    int * sto::c = & (S.b);
    cout << * (sto::c);
  }

(a) Invalid use of unqualified - name‘ sto::c’(b) Undefined call‘ sto::c’ inside main(c) Invalid use of qualified - name‘ sto::c’(d) No error, gives output 9
Answer: (c)“ usage of 'class::member” is not possible inside main.



36. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  static int b;
}S;

int * sto::c = & (S.b);
int main()
{
    S.b = 9;
    cout << * (sto::c);
  }

(a) 9(b) 0(c) Unpredictable(d) Error
Answer: (a) This is the only way of assigning a static pointer an address of
  a non - static member.



37. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  static int b;
}S;

char c = ‘l’;
int * sto::c = & c;
int main()
{
    cout << * (sto::c);
  }

(a) l(b) Prints nothing(c) Unpredictable(d) Error
Answer: (d) A static pointer member of a class can point only to some
member of a class.It cannot point to a non - member.



38. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
  static int b;
}S;

char c = ‘l’;
int * sto::c = & c;
int main()
{
    cout << * (sto::c);
  }

(a) Invalid initialisation of ‘sto::c’(b) Invalid use of qualified - name‘ sto::c’(c) Cannot convert‘ int ** ’to‘ int * ’ in initialization(d) None of the above
Answer: (c) Reference to character address is internally treated as‘ int ** ’.



39. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
}S;

class bro {
  public:
    char c;
}
D;
int * sto::c = & (D.c);
int main()
{
    D.c = ‘l’;
    cout << * (sto::c);
  }

(a) Cannot convert‘ char * ’to‘ int * ’ in initialization(b) Cannot convert‘ * bro’ to‘ * sto’ in initialization(c) Cannot convert‘ int ** ’to‘ int * ’ in initialization(d) No error
Answer: (a) Now as it is another class member it shows‘ char * ’.



40. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int * c;
}S;

class bro {
  public:
    int c;
}
D;
int * sto::c = & (D.c);
int main()
{
    D.c = ‘l’;
    cout << * (sto::c);
  }

(a) 108(b) 0(c) Prints nothing(d) Error
Answer: (a) This works as expected in the right format.So static pointers
can point to non - static members of other classes also.



41. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  static void fun() {
    cout << sto::c;
  }
}S;

int sto::c = 4;
int main()
{
    sto::fun();
  }

(a) 4(b) 0(c) Prints nothing(d) Error
Answer: (a)‘ static’ is the only storage class applicable
for functions.A
static
function is free of objects.It is called by using the class name.



42. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  static void fun() {
    cout << sto::c;
  }
}S;

int main()
{
    sto::fun();
  }

(a) 0(b) Prints nothing(c) Unpredictable(d) Error
Answer: (d) Static variable will be allocated memory only when it is
initiated as it is not associated with objects.So when the value is not
initialised, it gives error of missing variable.“undefined reference to‘ sto::c’” .



43. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  int b;
  static void fun() {
    cout << b;
  }
}S;

int main()
{
    sto::fun();
  }

(a) 0(b) Prints nothing(c) Unpredictable(d) Error
Answer: (d) Static functions cannot access non - static variables.



44. What will be the error thrown by the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  int b;
  static void fun() {
    cout << b;
  }
}S;

int main()
{
    sto::fun();
  }

(a)‘ sto::b’ inside‘ sto::fun’ is not static(b) Invalid use of member‘ sto::b’ in static member
function (c) Invalid use of non - static member‘ sto::b’ in static member
function‘ sto::fun’
  (d) None of the above
Answer: (b) Usage of any variable other than static members is not
permitted.



45. What is the output of the code?

#include<iostream>
using namespace std;
int b = 9;
class sto {
  public:
    static int c;
  static void fun() {
    cout << b;
  }
}S;

int main()
{
    sto::fun();
  }

(a) 9(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) static functions can access other global variables without any
issue.



46. What is the output of the code?

#include<iostream>
using namespace std;
class sup {
  public:
    static int b;
} int sup::b = 8;
class sto {
  public:
    static int c;
  static void fun() {
    cout << sup::b;
  }
}S;

int main()
{
    sto::fun();
  }

(a) 8(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) This also works right.



47. What is the output of the code?

#include<iostream>
using namespace std;
int b = 4;
class sto {
  public:
    static int c;
  int b;
  static void fun() {
    cout << b;
  }
}S;

int main()
{
    sto::fun();
  }

(a) 4(b) Prints nothing(c) Unpredictable(d) Error
Answer: (d) Class members have more precedence over global members
inside class functions.



48. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  int b;
  static void fun() {
    cout << “hai”;
  }
}S;

int main()
{
    sto::fun();
  }

(a) hai(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) Static functions need not necessarily use a static member
variable.



49. What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  int b;
  static void fun(sto f) {
    cout << f.b;
  }
}S;

int main()
{
    sto v;
    v.b = 4;
    sto::fun(v);
  }

(a) 4(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) A static
function can take arguments of any type .50.What is the output of the code?

#include<iostream>
using namespace std;
class sto {
  public:
    static int c;
  static int fun() {
    return c;
  }
}S;

int sto::c = 5;
int main()
{
    int v = sto::fun();
    cout << v;
  }

(a) 5(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) static
function can
return the static value.It is to be noted that
the value can be stored to a non - static variable.



51. What is the output of the code?

#include<iostream>
using namespace std;
int b = 8;
int main()
{
    extern int b;
    cout << b;
  }

(a) 8(b) 0(c) Unpredictable(d) Error
Answer: (a) Extern storage class means the variable refers to some already
defined variable in higher scope.It is mainly useful is accessing variablesfrom different files
while compiling together.



52. What is the output of the code?

#include<iostream>
using namespace std;
int b = 8;
int main()
{
    extern int b;
    b = 7;
    cout << b;
  }

(a) 7(b) 8(c) Unpredictable(d) Error
Answer: (a) The value can be changed normally.



53. What is the output of the code?

#include<iostream>
using namespace std;
int b = 8;
int main()
{
    extern int b = 7;
    cout << b;
  }

(a) 7(b) 8(c) Unpredictable(d) Error
Answer: (d) Extern variables cannot be initialized on the same declaration
statement.



54. What will be the error thrown by the code?

#include<iostream>
using namespace std;
int b = 8;
int main()
{
    extern int b = 7;
    cout << b;
  }

(a) Invalid use of ‘extern’ keyword(b) Expected‘;’
before‘ = ’operator(c)‘ extern’ type variable‘ b’ initialized on declaration(d) None of the above
Answer: (d) It throws“‘ b’ has both‘ extern’ and initializer’”.The compiler
doesn’ t accept both together.



55. What is the output of the code?

#include<iostream>
using namespace std;
int b = 8;
void fun() {
  cout << b;
}
int main()
{
    extern int b;
    b = 7;
    cout << b << “”;
    fun();
  }

(a) 7 7(b) 7 8(c) Unpredictable(d) Error
Answer: (a) Changing value of extern variable changes the original
variable also.



56. What is the output of the code?

#include<iostream>
using namespace std;
int b = 8;
void fun() {
  cout << b;
}
int main()
{
    b = 7;
    cout << b << “”;
    fun();
  }

(a) 7 7(b) 7 8(c) Unpredictable(d) Error
Answer: (a) Even when extern storage class is skipped the same output
comes.But this works only within the same file.So when multiple files and
variables are to be handled, ‘extern’ is the only go!



57. What is the output of the code?

#include<iostream>
using namespace std;
int b = 6;
class sto {
  public:
    extern int b;
  void fun() {
    cout << b;
  }
}S;

int main()
{
    S.fun();
  }

(a) 6(b) Prints nothing(c) Unpredictable(d) Error
Answer: (d) Class members cannot have storage class except‘ static’.



58. What is the output of the code?

#include<iostream>
using namespace std;
int b = 6;
class sto {
  public:
    void fun() {
      extern int b;
      cout << b;
    }
}S;

int main()
{
    S.fun();
  }

(a) 6(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a) This is possible, as the variable is a local variable and not a
class member.



59. What will be the error thrown by the code?

#include<iostream>
using namespace std;
int b = 6;
class sto {
  public:
    int b;
}S;

int main()
{
    S.b = extern int b;
    cout << S.b;
  }

(a) Expected‘;’
before‘ extern’
  (b) Expected primary - expression before‘ extern’(c) Both‘ a’ and‘ b’(d) No error
Answer: (c)‘ extern int b’ is declaration.It should be done separately and
then‘ S.b’ should be initiated.



60. What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    register int b = 9;
    cout << b;
  }

(a) 9(b) Prints nothing(c) Unpredictable(d) Error
Answer: (a)‘ register’ storage class means the value is requested to be
stored in register instead of RAM.It doesn’ t have any effect on the behavior of the variable.



61. What is the output of the following code snippet ?

#include<iostream>
using namespace std;
int main()
{
    auto int p;
    auto int q = 10;
    cout << ”
      default value“ << p << ”\n”;
    cout << ”
      default value“ << q << ”\n”;
    getchar();
    return 0;
  }

(a) Compiler dependent(b) Garbage and 10(c) 1 and 10(d) Compilation fault
Answer: (a) The behavior of the code will be different
for different
compilers.The modern - day compilers assign zero and the concept of
  garbage is avoided at most of the places.But, the traditional compilers and
compilers like Dev C++will initialize p with garbage and q with 10. And
hence, the answer is compiler dependent .62.What is the output of the code?

#include<iostream>
using namespace std;
int main()
{
    int p;
    auto int q;
    cout << ”
      default value“ << p << ”\n”;
    cout << ”
      default value“ << q << ”\n”;
    getchar();
    return 0;
  }

(a) Compiler dependent(b) Garbage and 0(c) 1 and 0 0(d) Compilation fault
Answer: (a) The behavior of the code will be different
for different
compilers.The modern - day compilers assign zero and the concept of
  garbage is ruled out.But, the traditional compilers and compilers like Dev
C++will initialize with garbage.Hence, the answer is compiler dependent.



63. What is the output of the below piece of code snippet, assuming the
compiler as Dev C++or traditional one ?

#include<iostream>
using namespace std;
int main()
{
  int p;
  auto int q;
  static int r;
  cout << ”
    default value“ << p << ”\n”;
  cout << ”
    default value“ << q << ”\n”;
  cout << ”
    default value“ << q << ”\n”;
  getchar();
  return 0;
}

(a) Garbage, Garbage, Garbage(b) 0, Garbage, Garbage(c) 0, 0, Garbage(d) None of the above
Answer: (a) Non - initialized integer(with / without) auto and static variables
will have garbage.This behavior might not be observed in the modern - day
compilers.



64. What is the output of the following code snippet ?

#include<iostream>
using namespace std;
int auto_verify() {
    int sum = 0;
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }

(a) 1, 1, 1, 1, 1(b) 0, 0, 0, 0, 0(c) 1, 2, 3, 4, 5(d) None of the aboveAnswer: (a) The output is through the behavior of the auto.The
default
storage qualifier is automatic and need not be mentioned explicitly.



65. What is the output of the following code snippet ?

#include<iostream>
using namespace std;
int auto_verify() {
    auto int sum = 0;
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }

(a) 1, 1, 1, 1, 1(b) 0, 0, 0, 0, 0(c) 1, 2, 3, 4, 5(d) None of the above
Answer: (a) The output is through the behavior of the auto.



66. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
static int variable;
int variable1;
int main()
{
    cout << ”\n” << “static“ << variable;
    cout << ”\n” << “global“ << variable1;
    getchar();
    return 0;
  }

(a) 0 and 0(b) 0 and Garbage(c) Compilation fault(d) None of the above
Answer: (a) Static is the
default storage class
for global variables.0 is
stored by
default
for static variables.The above code is written to prove
this.



67. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
static int variable;
auto int variable1;
int main()
{
    cout << ”\n” << “static“ << variable;
    cout << ”\n” << “global“ << variable1;
    getchar();
    return 0;
  }

(a) 0 and 0(b) Garbage and Garbage(c) Compilation error(d) None of the above
Answer: (c) Global variables cannot be auto and they are to be static.
Hence, it would be an error.



68. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
int auto_verify() {
    static int sum = 0;
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }

(a) 1, 1, 1, 1, 1(b) 0, 0, 0, 0, 0(c) 1, 2, 3, 4, 5(d) None of the above
Answer: (c) is the correct answer as static would remember the values and
would not re - initialize every time.



69. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
int sum = 0;
int auto_verify() {
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }

(a) 1, 1, 1, 1, 1(b) 0, 0, 0, 0, 0(c) 1, 2, 3, 4, 5(d) None of the above
Answer: (c) Global variables are by
default static and here the sum is static
by rule.Hence, the behavior is very similar to the previous code.



70. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
static int sum = 0;
int auto_verify() {
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }

(a) 1, 1, 1, 1, 1(b) 0, 0, 0, 0, 0(c) 1, 2, 3, 4, 5(d) None of the above
Answer: (c) If mentioned or not mentioned explicitly, global variables
remain static hence, the output will be c)



71. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
int i = 10;
int main()
{
    extern int i;
    cout << i << ”\n”;
    getchar();
    return 0;
  }

(a) 0(b) 10(c) Compilation error(d) Machine dependent
Answer: (b) Extern permits variables to be initialized outside the main and
to use them inside main
if needed.



72. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
int i = 10;
int main()
{
    extern int i;::i = 11;
    cout << i << ”\n”;
    getchar();
    return 0;
  }

(a) 11(b) 10(c) Compilation error(d) Machine dependent
Answer: (a) If the programmer has to re - initialize a value which was earlier
initialized through extern, it is always possible through scope resolution
operator.(::)



73. Can extern be used across files in the same directory– True or False.
Answer: True– Very much possible.Object files of the files would reside in the same directory and hence this would be a problem.



74. Can register be used as storage qualifier ? –True or False.
Answer: True– Yes.When needed, it can be used.In embedded systems,
  when faster access is required, register is used.But, otherwise, it would not
be used.



75. What is the output of the following code snippet ?

#include<iostream>
using namespace std;
int main()
{
    register int i = 10;
    cout << i << ”\n”;
    getchar();
    return 0;
  }

(a) 1(b) 10(c) Usage of register is wrong(d) None of the above
Answer: (b) It is very much legal to use the register as storage qualifier.
But, programmers prefer when faster access is required .



76. What is the output of the following code snippet ?

#include<iostream>
using namespace std;
int main()
{
    register int i;
    cout << i << ”\n”;
    getchar();
    return 0;
  }

(a) 1(b) Garbage(c) 0(d) None of the above
Answer: (b) It is very much legal to use the register as storage qualifier.
But, programmers prefer when faster access is required.



77. What is the output of the below code snippet ?

#include<iostream>
using namespace std;
int main()
{
    int i;
    static int i;
    i = 10;
    cout << i << ”\n”;
    getchar();
    return 0;
  }

(a) 1(b) Garbage(c) Compilation error(d) None of the above
Answer: (c) redeclaration of a variable is not permitted hence, it is an error .



78. Identify the error in the following code.(L4)

#include<iostream>
using namespace std;
global int sum = 0;
int auto_verify() {
    sum = sum + 1;
    cout << ”\n” << sum;
  }

int main()
{
    int i, ret;
    for (i = 1; i <= 5; i++) {
      ret = auto_verify();
    }
    getchar();
    return 0;
  }
Answer: There is no explicit keyword called global supported in C or CPP.
If declared above main, it naturally gets qualified as global storage qualifier.



79. What is the output of the below piece of code?

#include<iostream>
using namespace std;
int main()
{
    int i = 5; {
      int i = 10; {
        auto int i = 15;
        cout << “\n” << i;
      }
      cout << “\n” << i;
    }
    cout << “\n” << i;
    getchar();
    return 0;
  }

(a) Compilation Error(b) 5, 10, 15(c) 15, 10, 5(d) 5, 5, 5
Answer: (c) Scope of the auto storage qualifier is explained here through
this example.



80. What is the output of the below piece of code?

#include<iostream>
using namespace std;
int main()
{
    auto int a[5] = {
      1
    };
    cout << “\n” << a[1];
    getchar();
    return 0;
  }

(a) Garbage(b) 1(c) 0(d) None of the above
Answer: (c) If one of the components in an array is initialized, rest will be
automatically initialized to 0. This is referred to as automatic array.

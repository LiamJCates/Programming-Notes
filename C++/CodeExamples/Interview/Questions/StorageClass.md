If no storage-class specifier is provided, the default storage classes are:
    extern for all functions
    extern for objects at global (file) scope
    auto for objects at local (block) scope

NOTE
As of C++11 the auto keyword is no longer a C++ storage-class specifier
As of C++17 the register keyword is deprecated


1. What is the storage class of m?

  #include <iostream>
  using namespace std;

  void fun() {
    int m = 9;
    cout << m;
  }

int main() { fun(); }

Answer: automatic

As a local variable, the storage class of m is automatic by default.




2. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun() {
    auto int m = 9;
    cout << m;
  }

int main() { fun(); }

Answer: error
error: two or more data types in declaration of 'm'.
The auto keyword is no longer a C++ storage-class specifier.



3. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun() {
    static int count;
    cout << count;
  };

  int main() { fun(); }

Answer: 0

'static' storage class means that the variable is zero initialized at program start and it's value will be stored in memory even after the block completes its execution. The variable will be freed only after the execution of the whole program.



4. What is the output of the code?

  #include <iostream>
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

Answer: error

Even though 'count' is in memory as a static variable, it will be accessible only within its scope.



5. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun() {
    static int count;
    cout << count++ << " ";
  };

  int main()
  {
    fun();
    fun();
    fun();
  }

Answer: 0 1 2

'count' is static it will retain the old value.



6. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun() {
    static int count = 0;
    cout << count++ << " ";
  };
  int main()
  {
    fun();
    fun();
    fun();
  }

Answer: 0 1 2

Repeated declaration of 'static' variable is skipped, so the assignment is also skipped.



7. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun() {
    static int count;
    count = 0;
    cout << count++ << "";
  };

  int main()
  {
    fun();
    fun();
    fun();
  }

Answer: 000
Here the variable will be reinitialized on every call.



8. What is the output of the code?

  #include <iostream>
  using namespace std;

  int main()
  {
    int r = 9;
    while (r--> 5) {
      static int count;
      cout << count++;
    }
  }


Answer: 0123
Repeated declaration of 'static' variable is skipped, this works even in loops. It will be declared only on the first iteration.



9. What is the output of the code?

  #include <iostream>
  using namespace std;

  int main()
  {
    static int count;
    cout << count++ << " ";
    main();
  }

Answer: 0 1 2 3... till stack overflows

Repeat declaration of 'static' variable is skipped, this works even during recursion. It will be declared only on the first iteration.



10. What is the output of the code?

  #include <iostream>
  using namespace std;

  void fun(int c) {
    cout << c;
  }

  int main()
  {
    static int count = 9;
    fun(count);
  }


Answer: 9

A static value can be passed to a function. It takes the value without issues, however, we must be aware that the local variable is not static.




11. What is the output of the code?

  #include <iostream>
  using namespace std;

  int main()
  {
    static count = 9;
    cout << count;
  }

Answer: error

" 'count' does not name a type".
Storage classes do not associate any type with the variable.



12. What is the output of the code?

  #include <iostream>
  using namespace std;
  int main()
  {
    static int c = 9;
    cout << sizeof(c);
  }

Answer: 4

'static' storage class doesn't affect the size of the variable.



13. What is the output of the code?

  #include <iostream>
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


Answer: error

'static' member should be initiated only by using the class name with'::' operator.



14. What is the output of the code?

  #include <iostream>
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

Answer: error
throws "'c' in 'class sto' does not name a type".
While initializing a static member, a type is required.



15. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int c;
  }S;

  int sto::c = 8;

  int main()
  {
    cout << sto::c;
  }

Answer: 8

This is the way of initializing static variable.
Correction of previous question



16. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int c = 8;
  }S;

  int main()
  {
    cout << sto::c;
  }


Answer: error

Even though the static variable is common to the class, it cannot be initiated within the class unless it is const.




17. What is the output of the code?

  #include <iostream>
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

Answer: 6

Static variable can be read with an object instance.




18. What will be the error thrown by the code?

  #include <iostream>
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

Answer: No error

Here the static variable is of local scope in the function and is not a class member.



19. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int* c;
      static int b;
  }S;

  int sto::b = 6;
  int* sto::c = &(sto::b);

  int main()
  {
    cout << *(sto::c);
  }


Answer: 6



20. What will be the error thrown by the code?

  #include <iostream>
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

Answer: 8

It throws no error. It is actually the right way of using static pointers.



22. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
      int b;
  }S;

  S.b = 6;
  int sto::c = &(S.b);
  int main()
  {
    cout << sizeof(sto:: * c);
  }

Answer: error

Global object member cannot be defined globally. It can be
initialized only inside a particular scope.



23. What is the output of the code?

  #include <iostream>
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

Answer: 6

This works properly.



24. What will be the error thrown by the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
      static int b;
  }S;

  int main()
  {
    S.b = 9;
    int * sto::c = &(S.b);
    cout << * (sto::c);
  }


Answer: qualified-id in declaration before ‘=’ token

usage of class::member is not possible inside main.



25. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
      int b;
  }S;

  int * sto::c = &(S.b);
  int main()
  {
    S.b = 9;
    cout << * (sto::c);
  }

Answer: 9

This is the only way of assigning a static pointer an address of a non - static member.



26. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
  }S;

  char c = 'l';
  int * sto::c = & c;
  int main()
  {
    cout << *(sto::c);
  }

Answer: error
cannot convert ‘int\**’ to ‘int*’ in initialization
Reference to character address is internally treated as'int ** '.

A static pointer member of a class can point only to some member of a class. It cannot point to a non - member.



27. What will be the error thrown by the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
  }S;

  class bro {
    public:
      char c;
  }D;

  int* sto::c = &(D.c);

  int main()
  {
    D.c = 'l';
    cout << *(sto::c);
  }

Answer: Cannot convert'char * 'to'int * ' in initialization

Now as it is another class member it shows 'char *'



28. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int * c;
  }S;

  class bro {
    public:
      int c;
  }D;

  int * sto::c = & (D.c);
  int main()
  {
    D.c = 'l';
    cout << * (sto::c);
  }

Answer: 108

This works as expected in the right format. As static pointers can point to non - static members of other classes also.



29. What is the output of the code?

  #include <iostream>
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

Answer: 4

'static' is the only storage class applicable for functions.
A static function is free of objects. It is called by using the class name.



30. What is the output of the code?

  #include <iostream>
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

Answer: error

Static variable will be allocated memory only when it is initialized as it is not associated with objects. An uninitialized value gives error "undefined reference to 'sto::c'" .



31. What is the output of the code?

  #include <iostream>
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

Answer: error
invalid use of member ‘sto::b’ in static member function

Static functions cannot access non - static variables.




32. What is the output of the code?

  #include <iostream>
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

Answer: 9

static functions can access other global variables



33. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sup {
    public:
      static int b;
  }

  int sup::b = 8;

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


Answer: 8

This also works right.



34. What is the output of the code?

  #include <iostream>
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


Answer: error
invalid use of member ‘sto::b’ in static member function
The class member shadows the global members inside class functions.



35. What is the output of the code?

  #include <iostream>
  using namespace std;

  class sto {
    public:
      static int c;
      int b;
      static void fun() {
        cout << "fun";
      }
  }S;

  int main()
  {
    sto::fun();
  }


Answer: fun

Static functions need not necessarily use a static member variable.



36. What is the output of the code?

  #include <iostream>
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

Answer: 4

A static function can take arguments of any type.


37. What is the output of the code?

  #include <iostream>
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

Answer: 5

static function can return the static value. It is to be noted that the value can be stored to a non - static variable.



38. What is the output of the code?

  #include <iostream>
  using namespace std;
  int b = 8;

  int main()
  {
    extern int b;
    cout << b;
  }

Answer: 8

Extern storage class means the variable refers to some already defined variable in higher scope. It is mainly useful is accessing variables from different files while compiling together.



39. What is the output of the code?

  #include <iostream>
  using namespace std;

  int b = 8;

  int main()
  {
    extern int b;
    b = 7;
    cout << b;
  }

Answer: 7

The value can be changed normally.



40. What is the output of the code?

  #include <iostream>
  using namespace std;

  int b = 8;

  int main()
  {
    extern int b = 7;
    cout << b;
  }

Answer: error
‘b’ has both ‘extern’ and initializer
Extern variables cannot be initialized on the same declaration statement.




41. What is the output of the code?

  #include <iostream>
  using namespace std;

  int b = 8;

  void fun() {
    cout << b;
  }

  int main()
  {
    extern int b;
    b = 7;
    cout << b << " ";
    fun();
  }

Answer: 7 7

Changing value of extern variable changes the original variable also.



42. What is the output of the code?

  #include <iostream>
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

Answer: error

Class members cannot have storage class except 'static'.



43. What is the output of the code?

  #include <iostream>
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

Answer: 6

This is possible, as the variable is a local variable and not a class member.



44. What will be the error thrown by the code?

  #include <iostream>
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


Answer: error

Expected';' before'extern'
Expected primary - expression before'extern'

'extern int b' is a declaration. It should be done separately and then 'S.b' should be initiated.



45. What is the output of the code?

  #include <iostream>
  using namespace std;
  int main()
  {
    register int b = 9;
    cout << b;
  }


Answer: 9

'register' storage class means the value is requested to be stored in register instead of RAM. It doesn't have any effect on the behavior of the variable.





46. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;

  static int variable;

  int variable1;

  int main()
  {
    cout << "\n" << "static" << variable;
    cout << "\n" << "global" << variable1;
    getchar();
    return 0;
  }

(a) 0 and 0(b) 0 and Garbage(c) Compilation fault(d) None of the above

Answer: 0
0

Static is the default storage class for global variables.0 is stored by
default for static variables.




47. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;

  int auto_verify() {
      static int sum = 0;
      sum = sum + 1;
      cout << (sum == 1 ? "" : ", ") << sum ;
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


Answer: 1, 2, 3, 4, 5

static remembers the values and would not re - initialize every time.



48. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;
  int sum = 0;
  int auto_verify() {
      sum = sum + 1;
      cout << (sum == 1 ? "" : ", ") << sum ;
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


Answer: 1, 2, 3, 4, 5

Global variables are by default static and here the sum is static by rule.



49. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;
  static int sum = 0;
  int auto_verify() {
      sum = sum + 1;
      cout << (sum == 1 ? "" : ", ") << sum ;
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


Answer: 1, 2, 3, 4, 5

If mentioned or not mentioned explicitly, global variables remain static.



50. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;
  int i = 10;
  int main()
  {
    extern int i;
    cout << i << "\n";
    getchar();
    return 0;
  }

Answer: 10

Extern permits variables to be initialized outside the main and to use them inside main if needed.



51. What is the output of the below code snippet ?

  #include <iostream>
  using namespace std;
  int i = 10;
  int main()
  {
    extern int i;
    ::i = 11;
    cout << i << "\n";
    getchar();
    return 0;
  }

Answer: 11
If the programmer has to re - initialize a value which was earlier initialized through extern, it is always possible through scope resolution operator.(::)




52. What is the output of the below piece of code?

  #include <iostream>
  using namespace std;
  int main()
  {
    int i = 5; {
      int i = 10; {
        int i = 15;
        cout << i << ", ";
      }
      cout << i << ", ";
    }
    cout << i;
    getchar();
    return 0;
  }

Answer: 15, 10, 5
Scope of the automatic storage is explained here through this example.

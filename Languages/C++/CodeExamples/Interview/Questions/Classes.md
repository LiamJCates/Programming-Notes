1. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    public:
    int marks;
    void percent() { cout<< marks*10; }
  }S;

  int main()
  {
    S.marks=9;
    S.percent();
  }

Answer: 90 'S' is the object / instance of the class. It can access the 'public' members of the class. 'public' is the access specifier. Classes have two more specifiers 'private' and 'protected'. The variables are called 'data members' and the functions are called 'member functions'.



2. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    private:
    int marks;
    void percent() { cout<< marks*10; }
  }S;

  int main()
  {
    S.marks=9;
    S.percent();
  }

Answer: Error
error: ‘int student::marks’ is private within this context
error: ‘void student::percent()’ is private within this contex

Classes default to the 'private' access specifier, meaning that it's data is to be hidden from other unrelated info and user. Trying to access 'private' data and methods throws errors. It is accessible only by other members of the class and not even the objects.

3. What is the output of the code?

  #include <iostream>
  using namespace std;

  class student
  {
    protected:
    int marks;
    void percent(){ cout<< marks*10; }
  }S;

  int main()
  {
    S.marks=9;
    S.percent();
  }

Answer: Error
error: ‘int student::marks’ is protected within this context
error: ‘void student::percent()’ is protected within this context

'protected' access specifier means the data that is to be hidden from other unrelated info. Trying to access 'protected' data and methods throws errors. It is accessible only by the members of the class and inherited classes



4. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    public:
    int marks;
    void percent() { cout<< marks*10; }
  }S;

  int main()
  {
    cout<<sizeof(S);
  }

Answer: 4
Only member variables will be allocated memory and an int is allocated 4 bytes
Members need not be initialized, memory is allocated once the variable is created.



5. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    int marks;
    void percent() { cout<< marks*10; }
  }S;

  int main()
  {
    cout<<sizeof(S);
  }

Answer: 4
Even though the members are not accessible by the object, each object will have a specific value of the variable. So it will be allocated.



6. What is the output of the code?
  #include <iostream>
  using namespace std;
  class student
  {
    char section;
  public:
    int marks;
    void percent() { cout<< marks*10; }
  }S;

  int main()
  {
    cout<<sizeof(S);
  }

Answer: 5 This works normally.



7. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
  public:
    int marks;
    char section;
  }S;

  int main()
  {
    S.marks=8;
    S.section = 'a';
    cout<<S.marks<< " "<<S.section;
  }

Answer: 8 a



8. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
  public:
    int marks;
  private:
    char section;
  }S;

  int main()
  {
    S.marks=8;
    S.section = 'a';
    cout<<S.marks<< " "<<S.section;
  }

Answer: Error
section is private and thus throws an error on access by client code.



9. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    public:
      int marks;
    private:
      int m;
    public:
      char section;
  }S;

  int main()
  {
    S.marks=8;
    S.section = 'a';
    cout<<S.marks<< " "<<S.section;
  }


Answer: 8 a
Same access specifier can be given multiple times.



10. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    private:
      int marks;
    public:
      int m;
    private:
      char section;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: 8
Public members are accessible by client code.



11. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    private:
    public:
      int m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: 8
A specifier block can be empty.



12. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    private, public:
    int m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: Error
error: expected ‘:’ before ‘,’ token
error: expected unqualified-id before ‘,’ token
error: ‘class student’ has no member named ‘m’

This is not legal. But it is to be noted that still the specifiers exist as keywords.



13. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    private:public:
    int m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: 8
This works normally as specified above.


14. What is the output of the code?
  #include <iostream>
  using namespace std;
  int m;
  class student
  {
    public:
    ::m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: error
error: using-declaration for non-member at class scope
Global variables cannot be brought into class like this using scope resolution operator.

Here 'm' is not a member of a class. So it cannot be declared again inside the class using '::' operator.



15. What will be the error thrown the code?

  #include <iostream>
  using namespace std;
  int m;
  class student
  {
  public:
    int m;
  }S;

  int main()
  {  
    S.m = 8;
    m=0;
    cout<<S.m<< " "<<m;
  }

Answer: 8 0
It throws no error. It is allowed in classes.



16. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    public:
    int m;
  }m;

  int main()
  {
    m.m = 8;
    cout << m.m;
  }

Answer: 8
Class object can be same as a member variable.



17. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
    int m;
  public:
    int m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: Error
error: redeclaration of ‘int student::m’
error: ‘int student::m’ is private within this context

This is not allowed as the members will collide.
Before declaring 'm' as public it is declared as private.



18. What will be the error thrown by the code?
  #include <iostream>
  using namespace std;

  class student
  {
  public:
    int m;
    int m;
  }S;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: error
error: redeclaration of ‘int student::m’

Redeclaration of variable inside the class is not possible.



19. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
  public:
    int m;
    int ;
  }S;

  int main()
  {
    cout<<sizeof(S);
  }

Answer: error
error: declaration does not declare anything [-fpermissive]

Type cannot be given separately inside class for declaration.



20. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  { }S;
  int student::m;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }

Answer: error
error: ‘int student::m’ is not a static data member of ‘class student’
'class student' has no member named 'm'
This declaration of members is not possible.
This has a different meaning. It is related with 'static' members of class.



21. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student
  {
  public:
    int m;
  }S;
  S.m;

  int main()
  {
    S.m = 8;
    cout<<S.m;
  }


Answer: Error
error: ‘S’ does not name a type

Compiler treats "S.m;" as a new variable declaration, and throws errors.



22. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int m;

  int main()
  {
    m = 0;
    S.m = 8;
    cout << S.m << " " << m;
  }

Answer: 8 0
Declaring variables after the class with member names doesn't affect the declaration. Only variables that are defined outside and later declared inside class gives errors.



23. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m = 9;
  }S;

  int main()
  {
      cout << S.m;
  }

Answer: 9
May give warning:
"non-static data member initializers only available with -std = c++11 or -std = gnu++11[enabled by default]".

Such initializations can be done only to static members(that to outside the class usually). But this is available in the newer version compilers. So it is enabled by default.



24. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m = 9;
  }S;

  int main()
  {
      S.m = 8;
      cout << S.m;
  }

Answer:8
It works normally.



25. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S, S1;

  int main()
  {
      S.m = 8;
      cout << S.m << " " << S1.m;
  }

Answer: 8 0
We have created multiple objects, the first we assign a value to it's member m and the second is default initialized to 0.



26. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m = 9;
  }S, S1;

  int main()
  {
    S.m = 8;
    cout << S.m << " " << S1.m;
  }

Answer: 8 9
The class supplies a default initializer for member m, for S we reassign m's value.



27. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  };
  int main()
  {
    student S;
    S.m = 8;
    cout << S.m;
  }

Answer: 8
This is a legal declaration of student instance S inside main().




28. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student;
  class student {
    public:
      int m;
  };

  int main()
  {
    student S;
    S.m = 8;
    cout << S.m;
  }

Answer: 8
The statement 'class student;' is called forward declaration of the class. This is used to inform the compiler that such a class will be defined later. This is useful when declaring multiple classes and communicating amongst them. But it is mandatory that all the classes should be defined before 'main()'. Else it will throw errors of incomplete type.



29. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    student S;
    S.m = 8;
    cout << S.m;
  }

Answer: 8
The object 'S' inside main is local variable and the object after the class declaration is global.



30. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;
  student S;
  int main()
  {
      S.m = 8;
      cout << S.m;
  }

Answer: error
error: redefinition of ‘student S’

The scope clashes and throws error.



31. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    student S;
  }S;
  int main()
  {
    S.m = 8;
    cout << S.m;
  }

Answer:  error
error: field ‘S’ has incomplete type ‘student’
The object cannot be inside the class itself, as it is not completely defined.
The compiler knows 'student' is a class and is not complete at the point that S if declared.



32. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }
  S;

  int main()
  {
    S.m = 8;
    cout << S.m;
  }

Answer: 8
It works normally. Even though 'S;' is given in next line, the whitespace is disregarded and it will be considered as a continuation of the previous line.



33. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }student S;

  int main()
  {
      S.m = 8;
      cout << S.m;
  }


Answer: error
error: expected initializer before ‘S’
error: ‘S’ was not declared in this scope
This is not legal.



34. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    class subject {
      public:
        char grade;
    }sb;
  }S;

  int main()
  {
    S.m = 8;
    cout << S.m;
  }

Answer: 8
A class can be inside another class, called a nested class.


35. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    class subject {
      public:
        char grade;
    }sb;
  }S;

  int main()
  {
    sb.grade = 'A';
    cout << sb.grade;
  }

Answer: error
error: ‘sb’ was not declared in this scope

Here the object is inside the outer class, a nested class instance cannot be accessed without the outer object.



36. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    class subject {
      public:
        char grade;
    }sb;
  }S;

  int main()
  {
    S.sb.grade = 'A';
    cout << S.sb.grade;
  }

Answer: A
'sb' is treated as an object of 'class student'.



37. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    class subject {
      public:
        char grade;
    };
  }S;

  int main()
  {
    subject sb;
    sb.grade = 'A';
    cout << sb.grade;
  }

Answer: error
error: ‘subject’ was not declared in this scope
error: ‘sb’ was not declared in this scope

The class defined inside another class is not accessible by other classes.



38. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public: int m;
    class subject {
      public:
        char grade;
    };
  }S;
  int main()
  {
    S.subject sb;
    sb.grade = 'A';
    cout << sb.grade;
  }

Answer: error
error: invalid use of ‘class student::subject’
error: ‘sb’ was not declared in this scope

This is not a legal way of creating nested class instances



39. What will be the error thrown by the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    class student {
      public:
        char grade;
    }sb;
  }S;

  int main()
  {
    S.m = 9;
    cout << S.m;
  }


Answer: error
error: ‘student::student’ has the same name as the class in which it is declared

A nested class cannot have the same name as its outer class



40. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  class student {
    public:
      int m;
  }Sb;

  int main()
  {
      S.m = 9;
      cout << S.m;
  }


Answer: error
error: redefinition of ‘class student’
Multiple classes declared in the same scope cannot have same name.


41. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public: int m;
  }S;

  class subject {
    public:
      int g;
  }S;

  int main()
  {
      S.m = 9;
      cout << S.m;
  }

Answer: error
error: conflicting declaration ‘subject S’
Multiple classes declared in the same scope cannot have same object name.



42. What is the output of the code?
  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    class subject {
      public:
        int g;
    }sb;

    sb.g = 9;
    cout << sb.g;
  }

Answer: 9
This is a local class declaration. It is accessible only inside main.



43. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    class student {
      public:
        int g;
    }sb;

    sb.g = 9;
    cout << sb.g;
  }

Answer: 9
The local 'class' doesn't clash with the global class.



44. What is the output of the code?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    class student {
      public:
        int m;
    }S;

    S.m = 9;
    cout << S.m;
  }

Answer: 9
The scope plays the separating role and the local 'student' class doesn't clash with the global class.



45. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    class student {
      public:
        int m;
    }S;

    S.m = 9;
    cout << S.m << " " << ::S.m;
  }

Answer: 9 0
The scope plays the separating role and the local 'student' class doesn't clash with the global class.
The instance of student's member m in the local scope is assigned 9.
'::' is used to access the global scope instance of student, this instance's member m has been default initialized to 0.



46. What is the output of the code?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  int main()
  {
    class student {
      public:
        int m;
    }Sb;

    Sb.m = 9;
    cout << Sb.m << " " << ::S.m;
  }

Answer: 9
Even if the name is not clashing, '::' can be used to point to global scope variable.



47. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun(){ cout << m; }
  }S;

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: 9




48. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun();
  }S;

  void student::fun(){ cout << m; }

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: 9
This is the way of declaring functions inside the class and defining them outside using the scope resolution operator. Defining inside is called inline definition.



49. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    void fun();
    public:
      int m;
  }S;
  void student::fun(){ cout << m; }

  int main()
  {
    S.m = 9;
  }

Answer: prints nothing
private functions can be defined using the scope resolution operator.



50. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun();
  }S;

  student::fun(){ cout << m; }

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
When the return type of the definition is not specified, it will be treated as 'int'. As the definition and declaration is not the same, it throws errors.




51. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun();
  }S;

  student::void fun(){ cout << m; }

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: expected unqualified-id before ‘void’

void is treated as the function name.
This is not the legal way of defining functions via the scope resolution operator.



52. What is the output of the code ?

  #include <iostream>
  using namespace std;

  void student::fun(){ cout << m; }

  class student {
    public:
      int m;
    void fun();
  }S;

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: ‘student’ has not been declared
error: ‘m’ was not declared in this scope; did you mean ‘tm’?

As 'student' is not defined before the function definition, it gives errors.
'student' cannot be accessed before it is defined.



53. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun();
  }S;

  void fun(){ cout << m; }

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: ‘m’ was not declared in this scope; did you mean ‘tm’?
'm' member is not defined in the global scope

Global functions and member functions with same name doesn't map together. The class member 'fun' is not mapped to definition of global 'fun'. scope resolution is required.


54. What will be the error thrown by the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun();
  }S;

  void fun(){ cout << 9; }

  int main()
  {
    S.m = 9;
    S.fun();
  }


Answer:
undefined reference to 'student::fun()'

While we have eliminated the error related to a global declaration of fun() accessing the instance member m. Global functions and member functions with same name doesn't map together. The class member 'fun' is not mapped to definition of global 'fun'. scope resolution is required.



55. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun() {cout << "hai";}
  }S;

  void student::fun()  {cout << m;}

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: redefinition of ‘void student::fun()’

One member should be defined only once.



56. What will be the error thrown by the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun(){ cout << "hai"; }
  }S;

  void student::fun();
  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer:
error: declaration of ‘void student::fun()’ outside of class is not definition [-fpermissive]
Member function cannot be declared outside.



57. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  void student::fun()  {cout << m;}

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: no declaration matches ‘void student::fun()’
error: ‘class student’ has no member named ‘fun’



58. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  void student::fun();
  fun() {cout << m;}

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: no declaration matches ‘void student::fun()’
error: ‘class student’ has no member named ‘fun’
  All class members must be declared inside the class definition.

error: ISO C++ forbids declaration of ‘fun’ with no type [-fpermissive]
  Return type of a function is must in C++.



59. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
  }S;

  void student::fun();
  void student::fun(){ cout << m; }

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: no declaration matches ‘void student::fun()’
error: ‘class student’ has no member named ‘fun’
  All class members must be declared inside the class definition.



60. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun() { cout << m; }
  }S;

  int student::m;

  int main()
  {
    S.m = 9;
    S.fun();
  }

Answer: error
error: ‘int student::m’ is not a static data member of ‘class student’
Only static data members can be given like this.


61. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun() { cout << m; }
  }S;

  int main()
  {
    student s;
    S.m = 9;
    s.fun();
  }

Answer: Unpredictable
Data member's values are closed to the object. Undefined data members in a local scope are uninitialized and thus contain garbage values. Unlike 'C' here the undefined values are not initiated to 0.



62. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun() { cout << m; }
  }S;

  int main()
  {
    student s = S;
    S.m = 9;
    s.fun();
  }

Answer: 0
Object can be equated to other objects.
The default copy constructor is invoked to initialize 's'.
's' gets 0 as the global scoped 'S' is default initialized.
The global scoped 'S' gets the value 9 after equating to 's'.




63. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun() { cout << m; }
  }S;

  int main()
  {
    student s;
    S.m = 9;
    s = S;
    s.fun();
  }

Answer: 9
This works as expected.



64. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
    void fun() { cout << m; }
  }S;

  int main()
  {
    S.m = 9;
    student s(S);
    s.fun();
  }

Answer: 9
This is a way of creating object from another object.



65. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int m;
      void fun() { cout << m; }
  }S;

  int main()
  {
    S.m = 9;
    student s(S);
    s.m = 7;
    S.fun();
  }

Answer: 9
A change in new object doesn't reflect on the referenced object value.


66. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    protected:
      int m;
    public:
      void fun()
      {
        m = 9;
        cout << m;
      }
  }S;

  int main()
  {
    S.fun();
  }

Answer: 9
A class member can access 'protected' members.



67. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    private:
      int m;
    public:
      void fun()
      {
        m = 9;
        cout << m;
      }
  }S;

  int main()
  {
    S.fun();
  }

Answer: 9
A class member can access 'private' members.



68. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    void game(){ m = 8; }
    private:
      int m;
    public:
      void fun()
      {
        game();
        cout << m;
      }
  }S;

  int main()
  {
    S.fun();
  }

Answer: 8
A member function can call any member function. A function can access any data member. So it works as expected.



69. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    protected:
      int m;
    public:
      void fun()
      {
        game();
        cout << m;
      }
  }S;

  void game(){ cout << "game"; }

  int main()
  {
    S.m = 8;
    S.fun();
  }

Answer: Error
error: ‘game’ was not declared in this scope
  A member function cannot call a non - member function.
error: ‘int student::m’ is protected within this context


70. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      class nested {
        void fun() { cout << "nested-class"; }
      }D;
  }S;

  int main()
  {
    S.D.fun();
  }


Answer: error
error: ‘void student::nested::fun()’ is private within this context
Nested class functions are accessible from main. But here the inner class has the function 'fun()' in private scope.



71. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      class nested {
        public:
          void fun() {cout << "nested-class";}
      }D;
  }S;

  int main()
  {
    S.D.fun();
  }

Answer: nested-class
Now the function can be accessed.



72. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    class nested {
      public:
        void fun() { cout << "nested-class"; }
    };
    public:
      nested D;
  }S;
  int main()
  {
    S.D.fun();
  }

Answer: nested-class
This is also correct. Even though the class is defined in private scope, the object of the class is in public scope.



73. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    class nested {
      public:
        void fun();
    };
    public:
      void nested::fun() {cout << "nested-class"; }
    nested D;
  }S;

  int main()
  {
    S.D.fun();
  }

Answer: error
error: cannot define member function ‘student::nested::fun’ within ‘student’



74. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    class nested {
      public: void nested();
    };
    public:
      nested D;
  }S;

  void student::nested::fun(){ cout << "nested-class"; }
  int main()
  {
    S.D.fun();
  }

Answer: nested-class
This is a proper definition. As the class is confined to scope of inner class, while explicit definition of the function, it requires the whole hierarchy.



75. What will be the error thrown by the code ?

  #include <iostream>
  using namespace std;

  class student {
    class nested {
      public:
        void fun(){ cout << "nested-class"; }
    };
    public:
      nested D;
  }S;

  int main()
  {
    S.fun();
  }

Answer: error
error: ‘class student’ has no member named ‘fun’

The compiler doesn't care about the existence of the function.
It just checks if the function called is available in the current scope.



76. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    class nested {
      public:
        void fun();
    };
    public:
      nested D;
    void game { D.fun(); }
  }S;

  void student::nested::fun() { cout << "nested-class"; }

  int main()
  {
    S.game();
  }

Answer: nested-class
A function of the outer class can access the variable declared in the class. Here the object of the inner class is treated as any member of the class.



77. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      class nested {
      public:
        void fun() { cout << "nested-class"; }
      };
    void game()
    {
      nested d;
      d.fun();
    }
  }S;

  int main()
  {
    S.game();
  }

Answer: nested-class
Here, the object 'd' created inside 'student::fun' is temporary.
It will be deleted once the function has completed execution.



78. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      class nested {
        public:
          void fun() { cout << "nested-class"; }
      };
    void fun()
    {
      nested d;
      d.fun();
    }
  }S;

  int main()
  {
    S.fun();
  }

Answer: nested-class
This works normally.



79. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int c;
      int *f;
  }S;

  int main()
  {
    S.c = 3;
    S.f = &(S.c);
    cout << *(S.f);
  }

Answer: 3
class members can also be pointers.



80. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int c;
      int *f;
  }S;

  int main()
  {
    S.c = 3;
    S.f = &S.c;
    cout << *S.f;
  }

Answer: 3
'.' Operator has more precedence over '*' and '&' operators. So it still works right.



81. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int * f;
  }S;

  int main()
  {
    int c = 3;
    S.f = & c;
    cout << * (S.f);
  }

Answer: 3
Pointer members can also point to non - members.




82. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class student {
    public:
      int *f;
      int fun()
      {
        return 3;
      }
  }S;

  int main()
  {
    S.f = & (S.fun());
    cout << * (S.f);
  }

Answer: error
error: lvalue required as unary ‘&’ operand
This indirectly points a constant which is not possible.



83. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
      void fun(){cout << f;}
  }S;

  int main()
  {
    stud *C;
    C = &S;
    *C.f = 3;
    *C.fun();
  }

Answer: error
error: request for member ‘f’ in ‘C’, which is of pointer type ‘stud*’ (maybe you meant to use ‘->’ ?)

Objects can have pointers, but it should not be used like this for accessing.

"." is the syntax for pointer of object and has higher precedence than *,
for these statements to work \*C. would have to be replaced by (*C).




84. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
    void fun(){ cout << f; }
  }S;

  int main()
  {
    stud * C;
    C = &S;
    C -> f = 3;
    C -> fun();
  }

Answer: 3
The '->' is called arrow operator. This must be used for pointers of class objects.



85. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
      void fun() {cout << ((stud * ) this) -> f;}
  }S;

  int main()
  {
    S.f = 2;
    S.fun();
  }

Answer: 2
The usage of 'this pointer' points to the class specified in parenthesis. Instead of directly calling the member this is preferred to avoid confusion in advanced concepts like inheritance.




86. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
      void fun() { cout << this.f; }
  }S;

  int main()
  {
    S.f = 2;
    S.fun();
  }


Answer: error
error: request for member ‘f’ in ‘(stud\*)this’, which is of pointer type ‘stud*’ (maybe you meant to use ‘->’ ?)
This is not an appropriate usage of 'this' pointer.



87. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
    void fun()
  {
      cout << f;
    }
  }S;
  int main()
  {
    S.f = 2;
    ((stud * ) this) -> fun();
  }

Answer: error
'this' pointer can be used only inside a class.

error: invalid use of ‘this’ in non-member function



88. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
  public:
    int f;
  }S;

  class blo {
  public:
    void fun() { cout << ((stud * ) this) -> f;}
  }D;

  int main()
  {
    cout << "this in different class";
  }

Answer: this is different class
'this' pointer can also be used in a different and unrelated class.


89. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
  }S;

  class blo {
    public:
    void fun() { cout << ((stud * ) this) -> f; }
  } D;

  int main()
  {
    S.f = 2;
    D.fun();
  }

Answer: 0
It prints '0'. This is because, '2' is given to specific object 'S'.
But 'this' pointer calls the general function and not the specific to 'S'.



90. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      static int f;
  }S;

  int stud::f = 3;
  class blo {
    public:
      void fun(){cout << ((stud * ) this) -> f;}
  }D;

  int main()
  {
    D.fun();
  }

Answer: 3
'static' variable is common for the class so gives the value.



91. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
      void fun(){cout << f;}
  }S;

  class blo {
    public:
      void fun(){((stud * ) this) -> fun();}
  }D;

  int main()
  {
    D.fun();
  }

Answer: '0''garbage value'
When an object is specifically declared and generally called, the variable gets garbage value.



92. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
    void fun(){ cout << f; }
  }S;

  class blo {
    public:
      void fun(int a) {
        if (a % 2 == 0)
          ((stud * ) this) -> fun();
        else
          cout << ((stud * ) this) -> fun();
      }
  }D;

  int main()
  {
    D.fun(7);
  }

Answer: error
error: no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘void’)
It tries to get a value from a 'void' function and print it.




93. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      int f;
      int fun(){cout << f;}
  }S;

  class blo {
    public:
      void fun(int a) {
        if (a % 2 == 0)
          ((stud * ) this) -> fun();
        else
          cout << ((stud * ) this) -> fun();
      }
  }D;

  int main()
  {
    D.fun(7);
  }

Answer: '0''garbage value'
The same as in 'C', when an 'int' function doesn't explicitly return a value, the compiler automatically returns 0 on success.
Because the << operator is left associative the return value is printed before the garbage value.



94. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud {
    public:
      blo *s;
  }D;

  class blo {
    public:
      int b;
      void fun(int a) {cout << ((stud * ) this) -> s -> b;}
  }S;

  int main()
  {
    S.b = 2;
    S.fun();
  }

Answer: error
error: ‘blo’ does not name a type

'blo' is defined only after 'stud'. So the compiler doesn't know 'blo'.



95. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class blo {
    public:
      int b;
      void fun(int a) { cout << ((stud * ) this) -> s -> b;}
  }S;

  class stud {
    public:
      blo * s;
  }D;

  int main()
  {
    S.b = 2;
    S.fun();
  }

Answer: error
error: ‘stud’ was not declared in this scope;

Here usage of 'stud' causes the error as it is not yet defined.



96. What will be the error thrown by the code ?

  #include <iostream>
  using namespace std;

  class blo {
    public:
      int b;
      void fun(int a) { cout << ((stud * ) this) -> s -> b; }
  }B;

  class stud {
    public:
      blo * s;
  }D;

  int main()
  {
    S.b = 2;
    S.fun();
  }

Answer: errors
error: 'stud' was not declared in this scope
error: Expected primary - expression before ')' token in '((stud *)'
error: Expected ')'' before 'this' in '((stud *)this'

This is because the compiler treats 'stud' as an undefined variable and not a function.



97. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class stud;

  class blo {
    public:
      int b;
      void fun(int a) {
        cout << ((stud * ) this) -> s -> b;
      }
  }S;

  class stud {
    public: blo * s;
  }D;

  int main()
  {
    S.b = 2;
    S.fun();
  }

Answer: errors
error: invalid use of incomplete type ‘class stud’
note: Forward declaration of 'class stud'
error: no matching function for call to ‘blo::fun()’
Even though 'stud' has been declared earlier it is not yet defined.
'blo' cannot access a member of 'stud' even before it is defined.

While there is no error in the forward declaration, still as the error is in incomplete definition of the class declared the compiler notes the forward declaration.



98. What is the output of the code ?

  #include <iostream>
  using namespace std;

  class blo;

  class stud {
    public:
      blo * s;
  }D;

  class blo {
    public:
      int b;
      void fun(int a) { cout << ((stud * ) this) -> s -> b; }
  }S;

  int main()
  {
    S.b = 2;
    S.fun();
  }

Answer: error
error: no matching function for call to ‘blo::fun()’

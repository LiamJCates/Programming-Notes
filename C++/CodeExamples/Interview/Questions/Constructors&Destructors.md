1. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons() { m = 9;}
  }S;

  int main()
  {
    cout << S.m;
  }


Answer: 9
The function 'cons()'is a special function called' constructor'. A constructor has the same name as the class and should be in public scope. It doesn't have any return type. It will be called every time when an object of the class is created at any scope.



2. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    cons() { m = 9; }
  public:
    int m;
  }S;

  int main()
  {
    cout << S.m;
  }

Answer: error
error: 'cons::cons()' is private within this context
In order for a client to directly instantiate a class instance, constructors must be 'public'.



3. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    protected:
      cons() { m = 9; }
    public:
      int m;
  }S;

  int main()
  {
    cout << S.m;
  }

Answer: error
error: ‘cons::cons()’ is protected within this context
In order for a client to directly instantiate a class instance, constructors must be 'public'.



4. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    protected:
      cons() { m = 9; }
    public:
      cons() { m = 9; }
      int m;
  }S;

  int main()
  {
    cout << S.m;
  }

Answer: error
error: ‘cons::cons()’ cannot be overloaded with ‘cons::cons()’
To successfully overload a constructor we must specify a different parameter permutation meaning either a different number of parameters, different parameter types, or a different ordering of parameter types.



5. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      void cons() { m = 9; }
  }S;

  int main()
  {
    cout << S.m;
  }


Answer: error
error: return type specification for constructor invalid

Here the function 'cons'()' is treated as a normal member function as the function has a return type. The compiler finds that it is a constructor with return type and throws an error. Constructors are special functions that do not specify a return type.



6. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons() { m = 9; }
      cons() { m = 11; }
  }S;

  int main()
  {
    cout << S.m;
  }

Answer: error
error: ‘cons::cons()’ cannot be overloaded with ‘cons::cons()’.
This is due to two constructors having the same permutation of parameters.



7. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons();
  }S;

  cons::cons() { m = 11; }

  int main()
  {
    cout << S.m;
  }

Answer: 11
Such a constructor definition, using the scope resolution operator to define a declaration made within the class definition, is allowed.



8. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
  }S;

  cons::cons() { m = 11; }
  int main()
  {
    cout << S.m;
  }


Answer: error
error: definition of implicitly-declared ‘cons::cons()’
It means that the compiler treats 'cons()'as an implicit function, but its definition is specified outside.

In the previous question there was a declaration of the constructor. It just indicates the compiler that the constructor is going to be defined later or outside the class definition. So the definition outside maps to it appropriately. Here the declaration is removed. So definition of the constructor outside clashes with a predefined constructor, the default constructor.





10. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() { cout << "constructor";}
  };

  int main()
  {
    cons S;
    S.cons();
  }

Answer: error
error: invalid use of ‘cons::cons’
Constructors accessed by any object gives this error.
Constructors cannot be called explicitly by the object.



12. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      void cons() { cout << "constructor"; }
  };

  int main()
  {
    cons S;
    S.cons();
  }

Answer: error
error: return type specification for constructor invalid
Constructors cannot have return type, see question 5.



13. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      void init() { m = 80; }
      cons() { init(); }
  };

  int main()
  {
    cons S;
    cout << S.m;
  }

Answer: 80
Constructors can call other member functions of the class.



14. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() { init(); }
  };

  void init() { cout << "class initiated"; }

  int main() { cons S; }

Answer: error
error: ‘init’ was not declared in this scope;
Constructors have constraints over their scope of accessibility and cannot call non-member functions, unlike other class member functions.



16. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() {
      void init() {cout << "class initiated";}
      init();
    }
  };

  int main() { cons S; }

Answer: error
error: a function-definition is not allowed here before ‘{’ token
error: ‘init’ was not declared in this scope; did you mean ‘int’?

C++ does not allow function definition inside any function, including constructors.



17. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() {
      void init();
      init();
    }
  };

  void cons::init() { cout << "class initiated"; }

  int main() { cons S; }

Answer:
error: no declaration matches ‘void cons::init()’
C++ does not allow member functions declaration or definition inside any function, including constructors.



18. What will be the error thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    void init();
    cons() {
      void init();
      init();
    }
  };

  void cons::init() { cout << "class initiated"; }

  int main() { cons S; }

Answer:
In function 'cons::cons()': ...
...undefined reference to 'init()'

See following question



19. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      void init();
      cons() { init();}
  };

  void cons::init() { cout << "class initiated"; }

  int main() { cons S; }
Answer: class initiated
Constructors can call a member function.

If we remove the declaration of init() inside of cons() the code compiles correctly as compared to the code above.



20. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      class nested {
        public:
        void init() { cout << "class initiated"; }
      }d;
    int m;
    cons() { d.init(); }
  };

  int main() { cons S; }

Answer: class initiated
Constructors can call the member functions of nested classes.



21. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() {
      cout << "class initiated";
      cons();
    }
  };

  int main() { cons S; }


Answer: Prints 'class initiated' continuously till stack overflow causes a Segmentation fault
Constructors can be recursively called.



22. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons() { cout << "class initiated"; }
      void init() { cons(); }
  };

  int main()
  {
    cons S;
    S.init();
  }

Answer: class initiatedclass initiated

Constructors can be called from other member function of the same class.



23. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() {
      cout << "class initiated";
      main();
    }
  };

  int main() { cons S; }

Answer: error
error: ‘main’ was not declared in this scope
Constructor cannot call function that are out of scope. So it cannot call 'main'.



24. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() { int d = 8; }
  };

  int main()
  {
    cons S;
    cout << S.d;
  }

Answer: error
error: ‘class cons’ has no member named ‘d’
'd' is in scope within the constructor and is deleted after the execution of the constructor. So it is not accessible from the object .



25. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() { cout << "basic constructor"; }
    cons(int d) { cout << "constructor with parameters"; }
  };

  int main() { cons S(3); }

Answer: constructor with parameters
This is a form of overloaded constructor. It accepts objects with parameters.



26. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << "constructor with parameters"; }
  };

  int main() { cons S(3); }

Answer: constructor with parameters
As the object requires only a constructor with an argument, skipping basic constructor doesn't matter.



27. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << "constructor with parameters"; }
  };

  int main() { cons S; }


Answer: error
error: no matching function for call to ‘cons::cons()’

Here the default constructor is invoked to handle an instantiation with no parameters. The compiler will define a default constructor if no other constructor is implicitly defined. As a constructor taking an int value has been implicitly defined the call for a default constructor throws an error regarding missing constructors.



29. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
      cons(float d) { cout << d << ""; }
  };

  int main()
  {
    cons S(3.34);
    cons S(3);
  }


Answer: error
error: call of overloaded ‘cons(double)’ is ambiguous
  The literal value 3.34 defaults to a double and throws an error regarding mismatching constructor arguments.
error: redeclaration of ‘cons S’
  An object with the name S is declared twice.



31. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
      cons(double d) { cout << d << ""; }
  };

  int main() { cons S(3.34); }

Answer: 3.34
As 3.34 is a double the constructor argument matches to the appropriate definitions and gets called appropriately.



32. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
  };

  int main() { cons S(3.34); }

Answer: 3
While the argument 3.34 is a literal double value. As there is only one overloaded definition of the constructor, various data types gets mapped to it internally and type cast takes place.
Here, no ambiguity is present as only one definition is available.



33. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
      cons(int f) { cout << f << ""; }
  };

  int main() { cons S(3); }


Answer: error
error: ‘cons::cons(int)’ cannot be overloaded with ‘cons::cons(int)’

Changing the variable name of the parameter doesn't change the two definitions. Internally, both the definitions are considered same.



34. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
      cons(void f) { cout << "basic constructor"; }
  };

  int main() { cons S; }

Answer: error
error: invalid use of type ‘void’ in parameter declaration
  A variable cannot have' void' type, a set of errors are thrown in consequence of this.
error: no matching function for call to ‘cons::cons()’
  A default constructor is not defined and the implicit declarations prevent the compiler from doing so.



36. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << "int"; }
      cons(void) { cout << "basic constructor"; }
  };

  int main(){ cons S; }

Answer: basic constructor
When used for a function's parameter list, void specifies that the function takes no parameters.
So cons(void) acts as the default constructor.



37. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons(int d) {
      cout << d << "";
      cons();
    }
    cons() { cout << "basic constructor"; }
  };

  int main() { cons S(8); }

Answer: 8basic constructor
A constructor can be called from an overloaded constructor.



38. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) {
        cout << d << "";
        cons(6);
      }
      cons() { cout << "basic constructor"; }
  };

  int main() { cons S(8); }


Answer: Prints 86666…(till stack overflows)Segmentation Fault

The call is correct, but the infinite recursion causes this.



39. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d; }
      cons() {
        cout << "basic constructor";
        cons(4);
      }
  };

  int main() { cons S; }

Answer: basic constructor4
It works normally as expected.



40. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(int d) { cout << d << ""; }
      cons() {
        cout << "basic constructor";
        cons(4);
      }
  };

  int main() { cons S(); }

Answer: prints nothing
Here' S()' in 'main' is not considered an object even if the bracket is empty.



41. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(cons & d) {
        m = d.m;
        cout << d.m << "copy constructor";
      }
      cons() { m = 9; }
  };

  int main()
  {
    cons S;
    cons F(S);
  }

Answer: 9 copy constructor

A copy constructor of a given type creates an object with the reference of another object of the same type. It will be called when an object is created with sending another object as parameter.



42. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(cons d) {
        m = d.m;
        cout << d.m << "copy constructor";
      }
      cons() { m = 9; }
  };

  int main()
  {
    cons S;
    cons F(S);
  }

Answer: error
error: invalid constructor; you probably meant ‘cons (const cons&)’

While sending the object as reference, the values cannot be directly used. The '&' operator in definition plays the role of mapping the value.



44. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons(cons & d) { cout << d.m << "copy constructor"; }
    cons() { m = 9; }
  };

  int main()
  {
    cons S;
    cons F(S);
  }

Answer: 9copy constructor
Works as expected.



45. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons(cons & d) {
      cout << d.m << "copy constructor";
      cons(3);
    }
    cons(int w) { cout << w; }
    cons() { m = 9; }
  };

  int main()
  {
    cons S;
    cons F(S);
  }

Answer: 9copy constructor3
Any form of constructor can manually call any other constructor easily.



46. What is the output of the code?

  #include<iostream>
  using namespace std;
  class sup {
    public:
      int a;
      sup() { a = 8; }
  };

  class cons {
    public:
      int m;
      cons(sup & d) {
        m = d.a;
        cout << m;
      }
      cons() { m = 9; }
  };

  int main()
  {
    sup S;
    cons F(S);
  }


Answer: 8
Here the object is created in reference to object of another class.



47. What form of constructor is used last in the code?

  #include<iostream>
  using namespace std;
  class sup {
    public:
      int a;
  };

  class cons {
    public:
      int m;
      cons(sup &d) {
        m = d.a;
        cout << m;
      }
  };

  int main()
  {
    sup S;
    S.a = 6;
    cons F(S);
  }

Answer: parameterized constructor

Constructors are only of three types. The last constructor is used with an argument, meaning that it is not a default constructor. While the argument used is a reference type the constructor only resolves to a copy constructor if the argument is of the same type as the constructor's containing class.



48. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons(sup & d) {
        m = d.a;
        cout << m;
      }
      cons() { m = 9; }
  };

  class sup {
    public:
      int a;
      sup() { a = 8; }
  };

  int main()
  {
    sup S;
    cons F(S);
  }

Answer: error
error: expected ‘)’ before ‘&’ token
  As type 'sup' is unknown it is treated as a variable and ')' is expected after it.
error: no matching function for call to ‘cons::cons(sup&)’


Compiler organizes all the classes before executing main(). Here a reference to an instance of class 'sup' is used in the constructor of 'cons' before definition of 'sup', so the compiler does not yet know that it exists and throws cryptic errors as a consequence.

It is also to be noted that the same errors come even on passing object of 'sup' without reference.



50. Why are errors thrown by the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons(sup) {
      m = d.a;
      cout << m;
    }
    cons() { m = 9; }
  };

  class sup {
    public:
      int a;
    sup() { a = 8; }
  };

  int main()
  {
    sup S;
    cons F(S);
  }


Answer: The argument 'sup' is incomplete, so it gives the following errors.

error: field ‘sup’ has incomplete type ‘cons’
error: expected ‘;’ at end of member declaration
error: no matching function for call to ‘cons::cons(sup&)’



51. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      ~cons() { cout << "destructor"; }
  };

  int main(){ cons F; }

Answer: destructor

Destructor has the same name as the class with a prefix'~'. It is a special function that is called automatically when an object is deleted. In this case, when F goes out of scope at the completion of main, the destructor is called.



52. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      ~cons() { cout << "destructor";}
  };

  int main()
  {
    cons F;
    F.~cons();
  }

Answer: destructor destructor
A destructor can be called explicitly by the object from main. Even on calling it explicitly, it will be executed automatically once more while the object is being deleted.



53. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      void del() {cout << "destructor";}
      ~cons() { del(); }
  };

  int main(){ cons F; }


Answer: destructor

A destructor can call other member functions.



54. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    ~cons() { del();}
  };
  void del() {cout << "destructor";}

  int main(){ cons F; }


Answer: error
error: ‘del’ was not declared in this scope
A destructor cannot call functions defined outside its containing classes scope.



55. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    void del() { ~cons(); }
    ~cons() { cout << "destructor"; }
  };

  int main()
  {
    cons F;
    F.del();
  }

Answer: error
error: no match for ‘operator~’ (operand type is ‘cons’)
'~' is a special operator and cannot be used elsewhere in normal C++ program. The compiler throws a number of notes regarding the usage of the operator and halts the compilation.



56. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      ~cons() { cout << "destructor"; }
      ~cons(int d) { cout << "destructor"; }
  };

  int main(){ cons F; }

Answer: error
error: destructors may not have parameters
error: ‘cons::~cons()’ cannot be overloaded with ‘cons::~cons()’

Destructor is of only one type and may not have parameters, thus it cannot be overloaded. A function's type is determined by its name and its permutation of parameters.



58. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
    cons() { cout << "constructor"; }
    ~cons() {
      cout << "destructor";
      cons();
    }
  };

  int main(){ cons F; }

Answer: Prints "constructordestructorconstructordestructor…(till stack overflow)Segmentation fault

This is because, every time a constructor is called an object's memory is allocated. So a destructor must be executed for every constructor to free the allocated memory. Thus, the loop continues, stopping on overflow of stack.



59. What is the output of the code?

  #include<iostream>
  using namespace std;
  class cons {
    public:
      int m;
      cons() { cout << "constructor"; }
      ~cons()
      {
        cout << "destructor";
        S.~cons();
      }
  }S;

  int main(){ cons F; }

Answer: error
error: ‘S’ was not declared in this scope

Actually, the class doesn't know that 'S' exists as it is defined only after the class definition.



60. What is the output of the code?

  #include<iostream>
  using namespace std;
  class sup {
    public:
      ~sup() { cout << "sup destructor"; }
  }S;

  class cons {
    public:
      ~cons()
      {
        cout << "destructor";
        S.~sup();
      }
  };

  int main(){ cons F; }


Answer: destructorsup destructorsup destructor

Here 'S' is a global object defined before it is referenced. When F goes out of scope its destructor is called. That destructor calls the destructor for S explicitly. Even on calling a destructor explicitly, it will be executed automatically once more while the object is being deleted as S goes out of scope during the completion of main().

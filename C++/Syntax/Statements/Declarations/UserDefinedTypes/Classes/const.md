the const keyword can be used for a number of purposes throughout the declaration of a class.


### const Member Variables
You can mark member variables const by adding the keyword to the member’s type. The const member variables cannot be modified after their initialization.

struct Avout {
  const char* name = "Erasmas";
};

The name member is const, meaning the pointed-to value cannot be modified. On the other hand, apert is not const.

Sometimes you want the safety of marking a member variable const but would also like to initialize the member with arguments passed into a constructor. For this, you employ member initializer lists.

struct Avout {
  Avout(const char* name, long year_of_apert)
  : name{ name }, apert{ year_of_apert } {
  }  
  
  const char* name;
};





### Constant Objects

When an object of a class is qualified as a const object:

  const MyClass myobject;

The access to its data members from outside the class is restricted to read-only, as if all its data members were const for those accessing them from outside the class. Note though, that the constructor is still called and is allowed to initialize and modify these data members:

  // constructor on const object
  #include <iostream>
  using namespace std;

  class MyClass {
    public:
      int x;
      MyClass(int val) : x(val) {}
      int get() {return x;}
  };

  int main() {
    const MyClass foo(10);
  // foo.x = 20;            // not valid: x cannot be modified
    cout << foo.x << '\n';  // ok: data member x can be read
    return 0;
  }

The member functions of a const object can only be called if they are themselves specified as const members; in the example above, member get (which is not specified as const) cannot be called from foo. To specify that a member is a const member, the const keyword shall follow the function prototype, after the closing parenthesis for its parameters:

  int get() const {return x;}

Note that const can be used to qualify the type returned by a member function. This const is not the same as the one which specifies a member as const. Both are independent and are located at different places in the function prototype:

  int get() const {return x;}        // const member function
  const int& get() {return x;}       // member function returning a const&
  const int& get() const {return x;} // const member function returning a const&

Member functions specified to be const cannot modify non-static data members nor call other non-const member functions. In essence, const members shall not modify the state of an object.

const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access both const and non-const member functions alike.

You may think that anyway you are seldom going to declare const objects, and thus marking all members that don't modify the object as const is not worth the effort, but const objects are actually very common. Most functions taking classes as parameters actually take them by const reference, and thus, these functions can only access their const members:

  // const objects
  #include <iostream>
  using namespace std;

  class MyClass {
      int x;
    public:
      MyClass(int val) : x(val) {}
      const int& get() const {return x;}
  };

  void print (const MyClass& arg) {
    cout << arg.get() << '\n';
  }

  int main() {
    MyClass foo (10);
    print(foo);

    return 0;
  }


If in this example, get was not specified as a const member, the call to arg.get() in the print function would not be possible, because const objects only have access to const member functions.

Member functions can be overloaded on their constness: i.e., a class may have two member functions with identical signatures except that one is const and the other is not: in this case, the const version is called only when the object is itself const, and the non-const version is called when the object is itself non-const.

  // overloading members on constness
  #include <iostream>
  using namespace std;

  class MyClass {
      int x;
    public:
      MyClass(int val) : x(val) {}
      const int& get() const {return x;}
      int& get() {return x;}
  };

  int main() {
    MyClass foo (10);
    const MyClass bar (20);
    foo.get() = 15;         // ok: get() returns int&
  // bar.get() = 25;        // not valid: get() returns const int&
    cout << foo.get() << '\n';
    cout << bar.get() << '\n';

    return 0;
  }

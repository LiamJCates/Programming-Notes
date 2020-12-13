Singleton Class That Permits a Single Instance


You are asked to model the constitution of your country. Your constitution permits one president. Your class President risks the following:

President ourPresident;
DoSomething(ourPresident); // duplicate created in passing by value
President clone;
clone = ourPresident; // duplicate via assignment

Clearly, you need to avoid this situation. Beyond modeling a certain constitution, you might be programming an operating system and need to model one local area network, one processor, and so on. You need to ensure that certain resources cannot be copied or duplicated. If you don’t declare a copy constructor, the C++ compiler inserts a default public copy constructor for you. This ruins your design and threatens your implementation. Yet, the language gives you a solution to this design paradigm.

You would ensure that your class cannot be copied by declaring a private copy constructor. This ensures that the function call DoSomething(ourPresident) will cause a compile failure. To avoid assignment, you declare a private assignment operator:

class President
{
private:
  President(const President&); // private copy constructor
  President& operator= (const President&); // private copy assignment operator
  // … other attributes
};

There is no need for implementation of the private copy constructor or assignment operator. Just declaring them as private is adequate and sufficient toward fulfilling your goal of ensuring non-copyable objects of class President.


class President still has a shortcoming:

It cannot help creation of multiple presidents via instantiation of multiple objects:

President One, Two, Three;

Individually they are non-copyable thanks to the private copy constructors, but
what you ideally need is a class President that has one, and only one, real-world manifestation—that is, there is only one object and creation of additional ones is prohibited. Welcome to the concept of singleton that uses private constructors, a private assignment operator, and a static instance member to create this (controversially) powerful pattern.


 #include <iostream>
 #include <string>
 using namespace std;

class President
{
private:
  President() {}; // private default constructor
  President(const President&); // private copy constructor
  const President& operator=(const President&); // assignment operator

  string name;

public:
  static President& GetInstance() {
    // static objects are constructed only once
    static President onlyInstance;
    return onlyInstance;
  }

  string GetName() { return name; }

  void SetName(string InputName) { name = InputName; }
};

int main()
{
  President& onlyPresident = President::GetInstance();
  onlyPresident.SetName("Abraham Lincoln");

  // uncomment lines to see how compile failures prohibit duplicates
  // President second; // cannot access constructor
  // President* third= new President(); // cannot access constructor
  // President fourth = onlyPresident; // cannot access copy constructor
  // onlyPresident = President::GetInstance(); // cannot access operator=

  cout << "The name of the President is: ";
  cout << President::GetInstance().GetName() << endl;

  return 0;
}

Use the singleton pattern only where absolutely necessary, keeping future growth of the application and its features in perspective. Note that the very feature that it restricts creation of multiple instances can become an architectural bottleneck when a use case comes up that needs multiple instances of the class.

For example, if our project were to change from modeling a nation to modeling the United Nations, which is currently represented by 193 member nations, each with its own president, clearly we would have an architectural problem given a singleton class President that would permit the existence of only one instance.

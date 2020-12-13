Class That Prohibits Instantiation on the Stack
Space on the stack is often limited. If you are writing a database that may contain terabytes of data in its internal structures, you might want to ensure that a client of this class
cannot instantiate it on the stack; instead it is forced to create instances only on the free
store. The key to ensuring this is declaring the destructor private:
class MonsterDB
{
private:
~MonsterDB(); // private destructor
//... members that consume a huge amount of data
};Declaring a private destructor ensures that one is not allowed to create an instance like
this:
int main()
{
MonsterDB myDatabase; // compile error
// … more code
return 0;
}
This instance, if successfully constructed, would be on the stack. All objects on the stack
get popped when the stack is unwound and therefore the compiler would need to compile
and invoke the destructor ~MonsterDB() at the end of main(). However, this destructor
is private and therefore inaccessible, resulting in a compile failure.
A private destructor would not stop you from instantiating on the heap:
int main()
{
MonsterDB* myDatabase = new MonsterDB(); // no error
// … more code
return 0;
}
If you see a memory leak there, you are not mistaken. As the destructor is not accessible
from main, you cannot do a delete, either. What class MonsterDB needs to support is a
public static member function that would destroy the instance (a class member would
have access to the private destructor). See Listing 9.11.
LISTING 9.11 A Database class MonsterDB That Allows Object Creation Only on the
Free Store (Using new)
 #include <iostream>
 using namespace std;

 class MonsterDB
 {
 private:
 ~MonsterDB() {}; // private destructor prevents instances on stack

 public:
 static void DestroyInstance(MonsterDB* pInstance)
 {
 delete pInstance; // member can invoke private destructor
 }

 void DoSomething() {} // sample empty member method };

 int main()
 {
 MonsterDB* myDB = new MonsterDB(); // on heap
 myDB->DoSomething();

 // uncomment next line to see compile failure
 // delete myDB; // private destructor cannot be invoked

 // use static member to release memory
 MonsterDB::DestroyInstance(myDB);

 return 0;
 }

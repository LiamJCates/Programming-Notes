For information on the general definition of data abstraction see:
[System Design\ObjectOrientedDesign\Concepts\Abstraction\DataAbstraction.md]

Data Abstraction separates code into interface and implementation.

A stable public interface is independent of specific implementation details such that a change to the underlying implementation does not effect client code that utilizes the interface.

In C++, classes provide data abstraction through sufficient public methods to utilize functionality and manipulate object data without actually knowing how class has been implemented internally.


### Conceptual Example

For example, your program can make a call to the sort() function without knowing what algorithm the function actually uses to sort the given values. In fact, the underlying implementation of the sorting functionality could change between releases of the library, and as long as the interface stays the same, your function call will still work.

In this case whatever programs are using these interfaces, they would not be impacted and would just need a recompilation with the latest implementation.




### Implementation

Data abstraction in C++ is primarily achieved through
  encapsulation of state and behaviors into an abstraction unit, i.e. class
  separation of a public class interface and private implementation specifics through data hiding

  In C++, we use access labels to define the abstract interface to the class. A class may contain zero or more access labels −

    Members defined with a public label are accessible to all parts of the program. The data-abstraction view of a type is defined by its public members.

    Members defined with a private label are not accessible to code that uses the class. The private sections hide the implementation from code that uses the type.

  For information on the syntactic declaration of C++ access controls see:
  [C++\Syntax\Statements\Declarations\UserDefinedTypes\Classes\AccessControls.md]




### Benefits of Data Abstraction

Data abstraction provides two important advantages −
  Class internals are protected from inadvertent user-level errors, which might corrupt the state of the object.

  The class implementation may evolve over time in response to changing requirements or bug reports without requiring change in user-level code.

By defining data members only in the private section of the class, the class author is free to make changes in the data. If the implementation changes, only the class code needs to be examined to see what affect the change may have. If data is public, then any function that directly access the data members of the old representation might be broken.




### Example

Any C++ program where you implement a class with public and private members is an example of data abstraction.

#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }

      // interface to outside world
      void addNum(int number) {
         total += number;
      }

      // interface to outside world
      int getTotal() {
         return total;
      };

   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;

   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}

When the above code is compiled and executed, it produces the following result −

Total 60

Above class adds numbers together, and returns the sum. The public members - addNum and getTotal are the interfaces to the outside world and a user needs to know them to use the class. The private member total is something that the user doesn't need to know about, but is needed for the class to operate properly.

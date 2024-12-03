### Aggregate Initialization

The following initialization syntax is called aggregate initialization:

  Type objectName = {argument1, …, argumentN};

Alternatively, since C++11:

  Type objectName {argument1, …, argumentN};

Aggregate initialization can be applied to an aggregate, and therefore it is important to understand what data types fall under this category.

You already saw examples of aggregate initialization in the initialization of arrays

  int myNums[] = { 9, 5, -1 }; // myNums is int[3]
  char hello[6] = { 'h', 'e', 'l', 'l', 'o', ' \0' };

The term aggregate, however, is not limited to arrays of simple types like integers or characters, but extends also to classes (and therefore structs and unions) too.

There are restrictions imposed by the standard on the specification of a struct or a class that can be called an aggregate. These restrictions get nuanced depending on the version of C++ standard that you refer to. Yet, it can be safely said that classes/structs that comprise public and non-static data members, contain no private or protected data members, contain no virtual member functions, feature none or only public inheritance (that is, no
private, protected, or virtual inheritance), and no user-defined constructors are aggregates too and can be initialized as one.

Thus, the following struct fulfills the prerequisites of being an aggregate and their initializations follow their declarations:

  struct Aggregate1
  {
    int num;
    double pi;
  };

  Aggregate1 a1{ 2017, 3.14 };

Another example:

  struct Aggregate2
  {
    int num;
    char hello[6];
    int impYears[5];
  };

Aggregate2 a2 {42, {'h', 'e', 'l', 'l', 'o'}, {1998, 2003, 2011, 2014, 2017}};

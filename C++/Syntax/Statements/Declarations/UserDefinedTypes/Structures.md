Structure

struct: A collection of a fixed number of components in which the components are accessed by name.

structs have some useful low-level features: they’re C compatible, you can employ machine instructions that are highly efficient to copy or move them, and they can be efficiently represented in memory.

There are many instances in programming where we need more than one variable in order to represent an object. For example, to represent yourself, you might want to store your name, your birthday, your height, your weight, or any other number of characteristics about yourself. You could do so like this:

std::string myName;
int myBirthYear;
int myBirthMonth;
int myBirthDay;
int myHeightInches;
int myWeightPounds;

However, you now have 6 independent variables that are not grouped in any way. If you wanted to pass information about yourself to a function, you’d have to pass each variable individually. Furthermore, if you wanted to store information about someone else, you’d have to declare 6 more variables for each additional person! As you can see, this can quickly get out of control.

Fortunately, C++ allows us to create our own user-defined aggregate data types. An aggregate data type is a data type that groups multiple individual variables together.

One of the simplest aggregate data types is the struct. A struct (short for structure) allows us to group variables of mixed data types together into a single unit. These data elements, known as members or fields, can have different types and different lengths.



### Declaring and defining structs

Because structs are user-defined, we first have to tell the compiler what our struct looks like before we can begin using it. In C++, struct is a reserved word.

Data structures can be declared in C++ using the following syntax:

struct type_name {
  member definition;
  member definition;
  ...
  member definition;
} object_names;

Where type_name is a name for the structure type, object_names can be a set of zero or more valid identifiers for objects that have the type of this structure. Within braces {}, there is a list of one or more data members, each specified by a type and a valid identifier as its name.

Each element of a class is called a member. The members of a struct, even though enclosed in braces (that is, they form a block), are not considered to form a compound statement. Thus, a semicolon (after the right brace) is essential to end the struct statement:

  struct Product {
    int weight;
    double price;
  } ;

This declares a structure type, called Product, and defines it having two members: weight and price, each of a different fundamental type.

Keep in mind that Product is just a declaration -- even though we are telling the compiler that the struct will have member variables, no memory is allocated at this time. By convention, struct names start with a capital letter to distinguish them from variable names.

The above declaration creates a new type (Product), which can then be used to declare objects (variables) of this type:

  Product apple;
  Product banana, melon;

Note how once Product is declared, it is used just like any other type. As with normal variables, defining a struct variable allocates memory for that variable.

Right at the end of the struct definition, and before the ending semicolon (;), the optional field object_names can be used to directly declare objects of the structure type. For example, the structure objects apple, banana, and melon can be declared at the moment the data structure type is defined:

  struct Product {
    int weight;
    double price;
  } apple, banana, melon;

In this case, where object_names are specified, the type name (Product) becomes optional: struct requires either a type_name or at least one name in object_names, but not necessarily both.

It is important to clearly differentiate between what is the structure type name (Product), and what is an object of this type (apple, banana, and melon). Many objects (such as apple, banana, and melon) can be declared from a single structure type (Product).

Once the three objects of a determined structure type are declared (apple, banana, and melon) its members can be accessed directly. The syntax for that is simply to insert a dot (.) between the object name and the member name. For example, we could operate with any of these elements as if they were standard variables of their respective types:

  apple.weight = 1;
  apple.price = 0.69;
  banana.weight = 2;
  banana.price = 0.78;
  melon.weight = 5;
  melon.price = 2.95;

Each one of these has the data type corresponding to the member they refer to: apple.weight, banana.weight, and melon.weight are of type int, while apple.price, banana.price, and melon.price are of type double. As with normal variables, struct member variables are not initialized, and will typically contain junk. We must initialize them manually.

As seen above, a feature of data structures is the ability to refer to both their members individually or to the entire structure as a whole. In both cases using the same identifier: the name of the structure.



### Initializing structs

Initializing structs by assigning values member by member is a little cumbersome, so C++ supports a faster way to initialize structs using an initializer list. This allows you to initialize some or all the members of a struct at declaration time.

  struct Product {
    int weight;
    double price;
  } ;

  Product apple{1, 0.69};
  Product banana{2};

If the initializer list does not contain an initializer for some elements, those elements are initialized to a default value (that generally corresponds to the zero state for that type). In the above example, we see that banana.price gets default initialized to 0.0 because we did not specify an explicit initialization value for it.


### C++11/14: Non-static member initialization

Starting with C++11, it’s possible to give non-static (normal) struct members a default value:

  struct Rectangle
  {
      double length{ 1.0 };
      double width{ 1.0 };
  };

  int main()
  {
      Rectangle x; // length = 1.0, width = 1.0
      x.length = 2.0; // you can assign other values like normal   
  }

Unfortunately, in C++11, the non-static member initialization syntax is incompatible with the initializer list and uniform initialization syntax. For example, in C++11, the following program won’t compile:

  struct Rectangle
  {
  	double length{ 1.0 }; // non-static member initialization
  	double width{ 1.0 };
  };

  int main()
  {
  	Rectangle x{ 2.0, 2.0 }; // uniform initialization   
  }

Consequently, in C++11, you’ll have to decide whether you want to use non-static member initialization or uniform initialization. Uniform initialization is more flexible, so we recommend sticking with that one.

However, in C++14, this restriction was lifted and both can be used. If both are provided, the initializer list/uniform initialization syntax takes precedence. In the above example, Rectangle x would be initialized with length and width 2.0. In C++14, using both should be preferred, as it allows you to declare a struct with or without initialization parameters and ensure the members are initialized.



### Assigning to structs

Prior to C++11, if we wanted to assign values to the members of structs, we had to do so individually:

struct Employee
{
    short id;
    int age;
    double wage;
};

Employee joe;
joe.id = 1;
joe.age = 32;
joe.wage = 60000.0;

This is a pain, particularly for structs with many members. In C++11, you can now assign values to structs members using an initializer list:

  struct Employee
  {
      short id;
      int age;
      double wage;
  };

  Employee joe;
  joe = { 1, 32, 60000.0 }; // C++11 only



### Structs and functions

Typically, in a program, a struct is defined before the definitions of all the functions in the program, so that the struct can be used throughout the program. Therefore, if you define a struct and also simultaneously declare a struct variable, before the closing ;, that struct variable becomes a global variable and thus can be accessed anywhere in the program.

A big advantage of using structs over individual variables is that we can pass the entire struct to a function that needs to work with the members:

  void printInformation(Employee employee)
  {
      std::cout << "ID:   " << employee.id << '\n';
      std::cout << "Age:  " << employee.age << '\n';
      std::cout << "Wage: " << employee.wage << '\n';
  }

In the above example, we pass an entire Employee struct to printInformation() (by value, meaning the argument is copied into the parameter). This prevents us from having to pass each variable individually. Furthermore, if we ever decide to add new members to our Employee struct, we will not have to change the function declaration or function call!

A struct variable can be passed as a parameter either by value or by reference. Recall that when a variable is passed by value, the formal parameter copies the value of the actual parameter. Therefore, if the formal parameter modifies the data, the modification has no effect on the data of the actual parameter.

Suppose that a struct has several data members requiring a large amount of memory to store the data, and you need to pass a variable of that struct type by value.

The corresponding formal parameter then receives a copy of the data of the variable. The compiler must then allocate memory for the formal parameter in order to copy the value of the actual parameter. This operation might require, in addition to a large amount of storage space, a considerable amount of computer time to copy the value of the actual parameter into the formal parameter.

On the other hand, if a variable is passed by reference, the formal parameter receives only the address of the actual parameter. Therefore, an efficient way to pass a variable as a parameter is by reference. If a variable is passed by reference, then when the formal parameter changes, the actual parameter also changes. Sometimes, however, you do not want the function to be able to change the values of the actual parameter.

In C++, you can pass a variable by reference and still prevent the function from changing its value. This is done by using the keyword const in the formal parameter declaration


A function can also return a struct, which is one of the few ways to have a function return multiple variables.

  #include <iostream>

  struct Point3d
  {
      double x;
      double y;
      double z;
  };

  Point3d getZeroPoint()
  {
      // We can create a variable and return the variable.
      Point3d temp { 0.0, 0.0, 0.0 };
      return temp;
  }

  Point3d getZeroPoint2()
  {
      // We can return directly. We already specified the type
      // at the function declaration (Point3d), so we don't need
      // it again here.
      return { 0.0, 0.0, 0.0 };
  }

  Point3d getZeroPoint3()
  {
      // We can use empty curly braces to zero-initialize all
      // members of `Point3d`.
      return {};
  }

  int main()
  {
      Point3d zero{ getZeroPoint() };

      if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
          std::cout << "The point is zero\n";
      else
          std::cout << "The point is not zero\n";

      return 0;
  }



### Nesting structures
Structures can also be nested in such a way that an element of a structure is itself another structure:

  struct movies_t {
    string title;
    int year;
  };

  struct friends_t {
    string name;
    string email;
    movies_t favorite_movie;
  } charlie, maria;

  friends_t * pfriends = &charlie;

After the previous declarations, all of the following expressions would be valid:

  charlie.name
  maria.favorite_movie.title
  charlie.favorite_movie.year
  pfriends->favorite_movie.year

(where, by the way, the last two expressions refer to the same member).



You can use nested initializer lists for nested structs:

  struct Employee
  {
    short id;
    int age;
    double wage;
  };

  struct Company
  {
    Employee CEO; // an Employee struct within a Company struct
    int numberOfEmployees;
  };

  Company myCompany{{ 1, 42, 60000.0 }, 5 };


### Assignment
We can assign the value of one struct variable to another struct variable of the same type by using an assignment statement.

Product apple, banana;

  apple.weight = 1;
  apple.price = 0.69;

  banana.weight = 2;
  banana.price = 0.78;

  std::cout << banana.weight << " " << banana.price << std::endl;

  banana = apple;

  std::cout << banana.weight << " " << banana.price << std::endl;

Output:
2 0.78
1 0.69



### Comparison (Relational Operators)
To compare struct variables, you compare them member-wise, by accessing and comparing the values of similar members. No aggregate relational operations are performed on a struct.



### Pointers to Structures
You can define pointers to structures in very similar way as you define pointer to any other variable:

struct [struct type] *[struct pointer name];

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the & operator before the structure's name as follows −

[struct pointer name] = &[struct name];






### Accessing Members
We have seen how you can then access members of the variable using the dot operator (.), called the member access operator:

structVariableName.memberName

  #include <cstdio>
  struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
  };

  int main() {
    Book neuromancer;
    neuromancer.pages = 271;
    printf("Neuromancer has %d pages.", neuromancer.pages);
  }


If an object has been instantiated on the free store using new or if you have a pointer to an object, then you use the pointer operator (->) to access the members.

To access the members of a structure using a pointer to that structure, you may use the -> operator as follows:

[struct name]->[struct member];

What is a better way to access members: using the dot operator (.) or using the pointer operator (->)?

If you have a pointer to an object, the pointer operator would be best suited. If you have instantiated an object as a local variable on the stack, then the dot operator is best suited.

The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members. This operator serves to access the member of an object directly from its address. For example, in the example above:

  Book* bookPointer;
  bookPointer = \&neuromancer;

the member pages could then be accessed in this way:

  printf("Neuromancer has %d pages.", bookPointer->pages);


which is, for all purposes, equivalent to:

  printf("Neuromancer has %d pages.", (*bookPointer).pages);

Both expressions, are valid, and both access the member pages of the data structure pointed by bookPointer. It is definitely something different than:

  *bookPointer.pages

which is rather equivalent to:

  *(bookPointer.pages)

This would access the value pointed by a hypothetical pointer member called ages of the structure object bookPointer (which is not the case, since bookPointer is not an object and pages is not a pointer type).

The following panel summarizes possible combinations of the operators for pointers and for structure members:

| Expression | What is evaluated | Equivalent |
|------------|-------------------|------------|
| a.b | Member b of object a | |
| a->b | Member b of object pointed to by a | (*a).b |
| *a.b | Value pointed to by member b of object a | *(a.b) |






Struct size and data structure alignment

Typically, the size of a struct is the sum of the size of all its members, but not always!

Consider the Employee struct. On many platforms, a short is 2 bytes, an int is 4 bytes, and a double is 8 bytes, so we’d expect Employee to be 2 + 4 + 8 = 14 bytes. To find out the exact size of Employee, we can use the sizeof operator:

struct Employee
{
    short id;
    int age;
    double wage;
};

int main()
{
    std::cout << "The size of Employee is " << sizeof(Employee) << '\n';

    return 0;
}

On the author’s machine, this prints:

The size of Employee is 16

It turns out, we can only say that the size of a struct will be at least as large as the size of all the variables it contains. But it could be larger! For performance reasons, the compiler will sometimes add gaps into structures (this is called padding).

In the Employee struct above, the compiler is invisibly adding 2 bytes of padding after member id, making the size of the structure 16 bytes instead of 14. The reason it does this is beyond the scope of this tutorial, but readers who want to learn more can read about data structure alignment on Wikipedia. This is optional reading and not required to understand structures or C++!

C++ guarantees that members will be sequential in memory, although some implementations require members to be aligned along word boundaries, which depends on CPU register length. As a general rule, you should order members from largest to smallest within struct definitions.



### Accessing structs across multiple files

Because struct declarations do not take any memory, if you want to share a struct declaration across multiple files (so you can instantiate variables of that struct type in multiple files), put the struct declaration in a header file, and #include that header file anywhere you need it.

Struct variables are subject to the same rules as normal variables. Consequently, to make a struct variable accessible across multiple files, you can use the extern keyword in the declaration in the header and define the variable in a source file.



Structs are very important in C++, as understanding structs is the first major step towards object-oriented programming! The structs discussed above are sometimes called plain old data structs (or POD structs) since the members are all data (variable) members. Another aggregate data type called a class extends the concepts covered by structs. Understanding structs well will help make classes that much easier.

We can further augment structs with data member access controls and function declarations. Both of these functionalities are covered extensively in the section on classes:
[C++\Syntax\Statements\Declarations\UserDefinedTypes\Classes]

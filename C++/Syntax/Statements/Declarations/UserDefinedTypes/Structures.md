Structure

struct: A collection of a fixed number of components in which the components are accessed by name.

A data structure is a group of data elements grouped together under one name. These data elements, known as members, can have different types and different lengths.

In C++, struct is a reserved word.

Data structures can be declared in C++ using the following syntax:

struct type_name {
  member definition;
  member definition;
  ...
  member definition;
} object_names;

Where type_name is a name for the structure type, object_name can be a set of zero or more valid identifiers for objects that have the type of this structure. Within braces {}, there is a list with the data members, each one is specified with a type and a valid identifier as its name.

Each element of a class is called a member. The members of a struct, even though enclosed in braces (that is, they form a block), are not considered to form a compound statement. Thus, a semicolon (after the right brace) is essential to end the struct statement.

For example:

struct product {
  int weight;
  double price;
} ;

product apple;
product banana, melon;

This declares a structure type, called product, and defines it having two members: weight and price, each of a different fundamental type. This declaration creates a new type (product), which is then used to declare three objects (variables) of this type: apple, banana, and melon. Note how once product is declared, it is used just like any other type.

Right at the end of the struct definition, and before the ending semicolon (;), the optional field object_names can be used to directly declare objects of the structure type. For example, the structure objects apple, banana, and melon can be declared at the moment the data structure type is defined:

  struct product {
    int weight;
    double price;
  } apple, banana, melon;

In this case, where object_names are specified, the type name (product) becomes optional: struct requires either a type_name or at least one name in object_names, but not necessarily both.

It is important to clearly differentiate between what is the structure type name (product), and what is an object of this type (apple, banana, and melon). Many objects (such as apple, banana, and melon) can be declared from a single structure type (product).

Once the three objects of a determined structure type are declared (apple, banana, and melon) its members can be accessed directly. The syntax for that is simply to insert a dot (.) between the object name and the member name. For example, we could operate with any of these elements as if they were standard variables of their respective types:

  apple.weight
  apple.price
  banana.weight
  banana.price
  melon.weight
  melon.price

Each one of these has the data type corresponding to the member they refer to: apple.weight, banana.weight, and melon.weight are of type int, while apple.price, banana.price, and melon.price are of type double.

As seen above, a of the feature of data structures is the ability to refer to both their members individually or to the entire structure as a whole. In both cases using the same identifier: the name of the structure.



### Assignment
We can assign the value of one struct variable to another struct variable of the same type by using an assignment statement.

product apple, banana;

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








## Example

Consider the following Book class declaration with four members:

  struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
  };

Like any type definition, a struct is a definition, not a declaration. That is, it defines only a data type; no memory is allocated.

Once a data type is defined, you can declare variables of that type:

Book book1;

The memory allocated is large enough to store all of the structs members.

You can also declare struct variables when you define the struct by following the closing } with any number of identifiers.

Typically, in a program, a struct is defined before the definitions of all the functions in the program, so that the struct can be used throughout the program. Therefore, if you define a struct and also simultaneously declare a struct variable, before the closing ;, that struct variable becomes a global variable and thus can be accessed anywhere in the program.



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










structs have some useful low-level features: they’re C compatible, you can employ machine instructions that are highly efficient to copy or move them, and they can be efficiently represented in memory.

C++ guarantees that members will be sequential in memory, although some implementations require members to be aligned along word boundaries, which depend on CPU register length. As a general rule, you should order members from largest to smallest within struct definitions.



Nesting structures
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



### struct Variables and Functions
A struct variable can be passed as a parameter either by value or by
reference, and a function can return a value of type struct.

Recall that when a variable is passed by value, the formal parameter copies the value of the actual parameter. Therefore, if the formal parameter modifies the data, the modification has no effect on the data of the actual parameter.

Suppose that a struct has several data members requiring a large amount of memory to store the data, and you need to pass a variable of that struct type by value.

The corresponding formal parameter then receives a copy of the data of the variable. The compiler must then allocate memory for the formal parameter in order to copy the value of the actual parameter. This operation might require, in addition to a large amount of storage space, a considerable amount of computer time to copy the value of the actual parameter into the formal parameter.

On the other hand, if a variable is passed by reference, the formal parameter receives only the address of the actual parameter. Therefore, an efficient way to pass a variable as a parameter is by reference. If a variable is passed by reference, then when the formal parameter changes, the actual parameter also changes. Sometimes, however, you do not want the function to be able to change the values of the actual parameter.

In C++, you can pass a variable by reference and still prevent the function from changing its value. This is done by using the keyword const in the formal parameter declaration



## Access Controls
Access controls restrict member access.

Information can be classified into at least two categories: public data that we don’t mind the public knowing private data that we would like to make private.

C++ enables you to model class attributes and methods as public or private.

Keywords public and private

Public and private are the two major access controls. Anyone can access a public member, but only members can access private members. All struct members are public by default.



  #include <iostream>
  using namespace std;

  //structure definition with private and public members
  struct Student
  {
    private:
      int rNo;
      float perc;
    public:
      //function to read details
      void read(void)
      {
        cout<<"Enter roll number: ";
        cin>>rNo;
        cout<<"Enter percentage: ";
        cin>>perc;
      }
      //function to print details
      void print(void)
      {
        cout<<endl;
        cout<<"Roll number: "<<rNo<<endl;
        cout<<"Pecentage: "<<perc<<"%"<<endl;
      }
  };

  int main()
  {
    //declaring structure variable
    struct Student student;
    //reading and printing student details
    //by calling public member functions of the structure
    student.read();
    student.print();

    return 0;
  }

Output:
Enter roll number: 101
Enter percentage: 84.02

Roll number: 101
Pecentage: 84.02%

Public member functions read() and print() are accessing private data members rNo and perc. And the public member functions are calling within the main() function using the structure variable named student.

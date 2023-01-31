Type Aliasing
Typedefs allow the programmer to create an alias for a data type, and use the aliased name instead of the actual type name. Typedef literally stands for, “type definition”.


A type alias defines a name that refers to a previously defined name. You can use a type alias as a synonym for the existing type name. This can increase the portability (the ability of a program to be used across different types of machines; i.e., mini, mainframe, micro, etc; without much changes into the code) of a program as only the type alias statements would have to be changed.

There is no difference between a type and any type aliases referring to it. Also, type aliases cannot change the meaning of an existing type name.

There are two methods of type aliasing in C++:
  using
  typedef


### typedef

A syntax for creating such type aliases inherited from the C language, uses the typedef keyword:

typedef existing_type new_type_name ;

where existing_type is any type, either fundamental or compound, and new_type_name is an identifier with the new name given to the type:

  typedef char C;
  typedef unsigned int WORD;
  typedef char * pChar;
  typedef char field [50];

This defines four type aliases: C, WORD, pChar, and field as char, unsigned int, char* and char[50], respectively. Once these aliases are defined, they can be used in any declaration just like any other valid type:

  C mychar, anotherchar, *ptc1;
  WORD myword;
  pChar ptc2;
  field name;

By convention, typedef names are declared using a “_t” suffix. This helps indicate that the identifier represents a type, not a variable or function, and also helps prevent naming collisions with other identifiers.

### Using

A second syntax to define type aliases was introduced in the C++ language:

  using new_type_name = existing_type ;

where new_type_name is the type alias name and existing_type is the target type.

For example, the same type aliases as above could be defined as:

  using C = char;
  using WORD = unsigned int;
  using pChar = char *;
  using field = char [50];


Both aliases defined with typedef and aliases defined with using are semantically equivalent. The only difference being that typedef has certain limitations in the realm of templates that using has not. Therefore, using is more generic, although typedef has a longer history and is probably more common in existing code.

Note that neither typedef nor using create new distinct data types. They only create synonyms of existing types. That means that the type of myword above, declared with type WORD, can as well be considered of type unsigned int; it does not really matter, since both are actually referring to the same type.

Type aliases can be used to reduce the length of long or confusing type names, but they are most useful as tools to abstract programs from the underlying types they use. For example, by using an alias of int to refer to a particular kind of parameter instead of using int directly, it allows for the type to be easily replaced by long (or some other type) in a later version, without having to change every instance where it is used.







Type aliases can appear in any scope—block, class, or namespace.

You can introduce template parameters into type aliases. This enables
two important usages:

You can perform partial application on template parameters. Partial application is the process of fixing some number of arguments to a template, producing another template with fewer template parameters.

You can define a type alias for a template with a fully specified set of template parameters.

Template instantiations can be quite verbose, and type aliases help you
avoid carpal tunnel syndrome.








## typedef Structures

To define an "alias" for struct types:

typedef struct {
  member definition;
  member definition;
  ...
  member definition;
} [struct Type name];

Then use the alias directly to define variables without using the struct keyword:

[struct Type name] struct1, struct2;











Using type aliases for easier code maintenance

Type aliases also allow you to change the underlying type of an object without having to change lots of code. For example, if you were using a short to hold a student’s ID number, but then later decided you needed a long instead, you’d have to comb through lots of code and replace short with long. It would probably be difficult to figure out which shorts were being used to hold ID numbers and which were being used for other purposes.

However, with a type alias, all you have to do is change using studentID_t = short; to using studentID_t = long;. However, caution is still necessary when changing the type of a type alias to a type in a different type family (e.g. an integer to a floating point value, or vice versa)! The new type may have comparison or integer/floating point division issues, or other issues that the old type did not.

Using type aliases for platform independent coding

Another advantage of type aliases is that they can be used to hide platform specific details. On some platforms, an int is 2 bytes, and on others, it is 4 bytes. Thus, using int to store more than 2 bytes of information can be potentially dangerous when writing platform independent code.

Because char, short, int, and long give no indication of their size, it is fairly common for cross-platform programs to use type aliases to define aliases that include the type’s size in bits. For example, int8_t would be an 8-bit signed integer, int16_t a 16-bit signed integer, and int32_t a 32-bit signed integer. Using type aliases in this manner helps prevent mistakes and makes it more clear about what kind of assumptions have been made about the size of the variable.

In order to make sure each aliased type resolves to a type of the right size, type aliases of this kind are typically used in conjunction with preprocessor directives:

  #ifdef INT_2_BYTES
  using int8_t = char;
  using int16_t = int;
  using int32_t = long;
  #else
  using int8_t = char;
  using int16_t = short;
  using int32_t = int;
  #endif

On machines where integers are only 2 bytes, INT_2_BYTES can be #defined, and the program will be compiled with the top set of type aliases. On machines where integers are 4 bytes, leaving INT_2_BYTES undefined will cause the bottom set of type aliases to be used. In this way, int8_t will resolve to a 1 byte integer, int16_t will resolve to a 2 bytes integer, and int32_t will resolve to a 4 byte integer using the combination of char, short, int, and long that is appropriate for the machine the program is being compiled on.

This is exactly how the fixed width integers, like std::int8_t, are defined!

This is also where the issue with int8_t being treated as a char comes from -- std::int8_t is a type alias of char, and thus is just an alias for a char rather than being a unique type. As a result:

  #include <cstdint> // for fixed-width integers
  #include <iostream>

  int main()
  {
      std::int8_t i{ 97 }; // int8_t is actually a type alias for signed char
      std::cout << i;

      return 0;
  }

This program prints:

a

not 97, because std::cout prints char as an ASCII character, not a number.

Using type aliases to make complex types simple

Although we have only dealt with simple data types so far, in advanced C++, you could see a variable and function declared like this:

  std::vector<std::pair<std::string, int> > pairlist;

  bool hasDuplicates(std::vector<std::pair<std::string, int> > pairlist)
  {
      // some code here
  }

Typing std::vector<std::pair<std::string, int> > everywhere you need to use that type can get cumbersome. It’s much easier to use a type alias:

  using pairlist_t = std::vector<std::pair<std::string, int> >; // make pairlist_t an alias for this crazy type

  pairlist_t pairlist; // instantiate a pairlist_t variable

  bool hasDuplicates(pairlist_t pairlist) // use pairlist_t in a function parameter
  {
      // some code here
  }

Much better! Now we only have to type “pairlist_t” instead of std::vector<std::pair<std::string, int> >.

Don’t worry if you don’t know what std::vector, std::pair, or all these crazy angle brackets are yet. The only thing you really need to understand here is that type aliases allow you to take complex types and give them a simple name, which makes those types easier to work with and understand.

Best practice

Favor type aliases over typedefs, and use them liberally to document the meaning of your types.

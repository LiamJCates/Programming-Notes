Type Aliasing

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

Type Aliasing
A type alias defines a name that refers to a previously defined name. You can
use a type alias as a synonym for the existing type name.
There is no difference between a type and any type aliases referring to
it. Also, type aliases cannot change the meaning of an existing type name.
To declare a type alias, you use the following format, where type-alias is
the type alias name and type-id is the target type:
using type-alias = type-id;

Type aliases can appear in any scope—block, class, or namespace.
You can introduce template parameters into type aliases. This enables
two important usages:
•	 You can perform partial application on template parameters. Partial
application is the process of fixing some number of arguments to a
template, producing another template with fewer template parameters.
•	 You can define a type alias for a template with a fully specified set of
template parameters.
Template instantiations can be quite verbose, and type aliases help you
avoid carpal tunnel syndrome.

## typedef

C++ allows you to substitute variable types to something that you might find convenient.
You use the keyword typedef:

typedef type newname;

Here is an example where a programmer wants to call an unsigned int a descriptive STRICTLY_POSITIVE_INTEGER.

typedef unsigned int STRICTLY_POSITIVE_INTEGER;
STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532;

typedef or type substitution is particularly convenient when dealing with complex types that can have a cumbersome syntax, for example, types that use templates.


Note that the typedef statement does not create any new data type; it only creates an alias to an existing data type.







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

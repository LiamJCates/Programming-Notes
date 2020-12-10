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

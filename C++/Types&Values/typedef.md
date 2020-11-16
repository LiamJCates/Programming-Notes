## typedef

C++ allows you to substitute variable types to something that you might find convenient.
You use the keyword typedef:

typedef type newname;

Here is an example where a programmer wants to call an unsigned int a descriptive STRICTLY_POSITIVE_INTEGER.

typedef unsigned int STRICTLY_POSITIVE_INTEGER;
STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532;

typedef or type substitution is particularly convenient when dealing with complex types that can have a cumbersome syntax, for example, types that use templates.

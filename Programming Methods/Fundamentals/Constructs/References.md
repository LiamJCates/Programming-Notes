There are two ways that a variable can store its value in memory. We could think of these
ways as direct and indirect.

The variables that directly store their data are like boxes. When we create them, we can
think of them as a box that has the name of the variable stuck to it with a label. We can
store the value inside the box and look in the box later to see what value is in there.
Variables that store their values like this are called value variables

Variables that use indirect storage will act as an index card in a library. It will not store
the book but will have the location where it is stored, so it only contains the address
to where in memory the actual value is. Variables that store values like this are called
reference variables



When we declare a value variable of a type, several things will happen:

A chunk of memory that is large enough to host the given type is located,
and this location has an address.

A name is assigned to the memory location, the name we give the variable is just an alias for this address. It is much easier for us to remember that a variable called firstName stores a name instead of having to remember that the first name was at the 38892819283 address.

When our code is interpreted or compiled, the variable name is changed to the actual address, but that is luckily not anything that we will ever see. As this is a variable that stores its data by value, there is a direct relationship between where the data is and the variable name.




Reference variables
When it comes to reference variables, there is an extra step between the variable name and where the data is located.

the data will still need to be stored somewhere, so a memory location for it is found and as before, the address of where this is, is noted. However, the difference is that the variable name is not an alias for this address. Instead, the address for where the data is, is stored at another location in memory and the variable is an alias for that location.

This might seem pointless. Why can't we store the text string at the location pointed out by the weather variable? What is the point of this extra step? The answer is efficiency. In a program, we need to pass data around. The data that we have in a variable in one part of the program needs to be passed along to another part. Imagine that the data stored is much larger than the short text string in the preceding example; the actual passing of the data would mean that we need to make a copy of all the data. This takes some time, and we will now have two copies of the data, which will use twice as much memory. If a variable is of this reference type, we will not need to copy all the data, we would simply copy the reference value

How a language uses these two types will differ from language to language. When learning
a new language, it is vital to learn how it works with value and reference variables.

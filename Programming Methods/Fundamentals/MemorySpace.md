Each byte of computer memory has an address. A memory address works like a street address; it is used to help us navigate to the correct location:

To store 13 in the computer's memory, the programming language will need to reserve enough space — 4 bytes is typical.

4 bytes that are not occupied by something else need to be located. These
bytes need to be in continuous order.

The address of the first byte in this sequence is of interest to us. The programming language knows that we are storing an integer value at this location, and it knows how many bytes an integer occupies, so the first address is enough to locate this integer.

When writing a program, we don't want to remember numeric memory addresses, so we give this memory address a name by declaration of a variable. It is up to us, as programmers, to come up with this name, and we should pick a name that describes the data that we are storing.

Now that we have enough room for the reserved integer value and a name that can be used to refer to this memory address, the actual value can be stored at this memory location. This value will be stored in binary format.

If we want to save the value 13, binary 1101, all of the bits preceding this value are filled with zeros. As you can see in the following diagram, one byte would have been enough, but as many languages have a fixed size for its integer type, all the bytes will be reserved, regardless of whether we need them

Now, the value is stored in memory and we have a name that refers to this location. We can use this name to access this value. We call x in our example a variable. A variable consists of several things. It has a name, which is x in our sample. It also has a type. The type defines how much memory the data needs. We wanted to store an integer and we assumed that the language we are using has decided to use 4 bytes for integers. This is the size of this variable.

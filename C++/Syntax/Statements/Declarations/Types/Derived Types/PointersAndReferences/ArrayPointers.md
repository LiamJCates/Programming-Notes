### Array Pointer

Pointers share several characteristics with arrays. Pointers encode object location. Arrays encode the location and length of contiguous objects.

At the slightest provocation, an array will decay into a pointer. A decayed array loses length information and converts to a pointer to the array’s first element:

  int key_to_the_universe[]{ 3, 6, 9 };
  int* key_ptr = key_to_the_universe; // Points to 3

After initialization, key_ptr points to the first element of key_to_the_universe.

An array is a pointer to the first element. Should you need to access the second element via the expression myNumbers[1], you can also access the same using the pointer pointToNums with the syntax *(pointToNums + 1). The third element is accessed in the static array using myNumbers[2], whereas the third element is accessed in the dynamic array using the syntax *(pointToNums + 2).

In all but two cases (which we’ll cover below), when a fixed array is used in an expression, the fixed array will decay (be implicitly converted) into a pointer that points to the first element of the array. You can see this in the following program:

Differences between pointers and fixed arrays

There are a few cases where the difference in typing between fixed arrays and pointers makes a difference. These help illustrate that a fixed array and a pointer are not the same.

The primary difference occurs when using the sizeof() operator. When used on a fixed array, sizeof returns the size of the entire array (array length * element size). When used on a pointer, sizeof returns the size of a memory address (in bytes). A fixed array knows how long the array it is pointing to is. A pointer to the array does not.

The second difference occurs when using the address-of operator (&). Taking the address of a pointer yields the memory address of the pointer variable. Taking the address of the array returns a pointer to the entire array. This pointer also points to the first element of the array, but the type information is different. It’s unlikely you’ll ever need to use this.



#### Handling Decay

Often, you pass arrays as two arguments:
•	 A pointer to the first array element
•	 The array’s length
The mechanism that enables this pattern is the subscript operator ([]), which works with pointers just as with arrays.

  #include <cstdio>
  struct College {
    char name[256];
  };

  void print_names(College* colleges, size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++)
      printf("%s College\n", colleges[i].name);
  }

  int main() {
    College oxford[] = { "Magdalen", "Nuffield", "Kellogg" };
    print_names(oxford, sizeof(oxford) / sizeof(College));
  }

Output:
Magdalen College
Nuffield College
Kellogg College




## Array Pointer Arithmetic

To obtain the address of the nth element of an array, you have two options.
First, you can take the direct approach of obtaining the nth element with
the subscript operator ([]) and then use the address-of (&) operator:

  College* third_college_ptr = &oxford[2];

Pointer arithmetic, the set of rules for addition and subtraction on pointers, provides an alternate approach. When you add or subtract integers to pointers, the compiler figures out the correct byte offset using the size of the pointed-to type.

For example, adding 4 to a uint64_t pointer adds 32 bytes as a uint64_t takes up 8 bytes, so 4 of them take up 32 bytes.

The following is therefore equivalent to the previous option of obtaining the address of the nth element of an array:

  College* third_college_ptr = oxford + 2;




## string literal Pointers

string literals are arrays containing null-terminated character sequences. They can also be accessed directly. String literals are arrays of the proper array type to contain all its characters plus the terminating null-character, with each of the elements being of type const char (as literals, they can never be modified). For example:

const char * foo = "hello";

This declares an array with the literal representation for "hello", and then a pointer to its first element is assigned to foo. If we Suppose that "hello" is stored at the memory locations that start at address 1702, then foo is a pointer and contains the value 1702, and not 'h', nor "hello", although 1702 indeed is the address of both of these.

The pointer foo points to a sequence of characters. Because pointers and arrays behave essentially the same way in expressions, foo can be used to access the characters in the same way arrays of null-terminated character sequences are. For example:

  *(foo+4)
  foo[4]


Both expressions have a value of 'o' (the fifth element of the array).

When using a pointer to a string, to access the characters of the string through that pointer, you need to put parentheses around the asterisk and the pointer variable. Otherwise, the compiler first tries to access the index in brackets with the variable name and afterward applies the asterisk due to the precedence:

  (*ptrToString)[i]

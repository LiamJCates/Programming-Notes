### Void Pointer

The void type of pointer is a special type of pointer. In C++, void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).

The void type is used to specify a pointer to a block of memory (called a void pointer). The void pointer, also known as the generic pointer, can be pointed at objects of any data type.

A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type:

  void *ptr; // ptr is a void pointer

A void pointer can point to objects of any data type:

  int nValue;
  float fValue;

  struct Something
  {
    int n;
    float f;
  };

  Something sValue;

  void *ptr;
  ptr = &nValue; // valid
  ptr = &fValue; // valid
  ptr = &sValue; // valid


This gives void pointers a great flexibility. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

Because the void pointer does not know what type of object it is pointing to, direct indirection through it is not possible. A void pointer must first be explicitly cast to another pointer type before indirecting through the new pointer.

  #include <iostream>

  int main()
  {
    int value{ 5 };
    void *voidPtr{ &value };

     // illegal: Indirection through a void pointer
    // std::cout << *voidPtr << '\n';

    // however, if we cast our void pointer to an int pointer...
    int *intPtr{ static_cast<int*>(voidPtr) };

    // then we can use indirection through it like normal
    std::cout << *intPtr << '\n';
  }

Output:

  5

The next obvious question is: If a void pointer doesn’t know what it’s pointing to, how do we know what to cast it to? Ultimately, that is up to the developer to keep track of.

Here’s an example of a void pointer in use:

  #include <iostream>

  enum class Type
  {
      INT,
      FLOAT,
      CSTRING
  };

  void printValue(void *ptr, Type type)
  {
      switch (type)
      {
          case Type::INT:
              std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
              break;
          case Type::FLOAT:
              std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and perform indirection
              break;
          case Type::CSTRING:
              std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no indirection)
              // std::cout knows to treat char* as a C-style string
              // if we were to perform indirection through the result, then we'd just print the single char that ptr is pointing to
              break;
      }
  }

  int main()
  {
      int nValue{ 5 };
      float fValue{ 7.5f };
      char szValue[]{ "Mollie" };

      printValue(&nValue, Type::INT);
      printValue(&fValue, Type::FLOAT);
      printValue(szValue, Type::CSTRING);

      return 0;
  }

Output:

  5
  7.5
  Mollie



### Void pointer miscellany

Void pointers can be set to a null value:

  void *ptr{ nullptr };

Although some compilers allow deleting a void pointer that points to dynamically allocated memory, doing so should be avoided, as it can result in undefined behavior.

It is not possible to do pointer arithmetic on a void pointer. This is because pointer arithmetic requires the pointer to know what size object it is pointing to, so it can increment or decrement the pointer appropriately.

Note that there is no such thing as a void reference. This is because a void reference would be of type void &, and would not know what type of value it referenced.



Conclusion

In general, it is a good idea to avoid using void pointers unless absolutely necessary, as they effectively allow you to avoid type checking. This allows you to inadvertently do things that make no sense, and the compiler won’t complain about it. For example, the following would be valid:

  int nValue{ 5 };
  printValue(&nValue, Type::CSTRING);

But who knows what the result would actually be!

Although the above function seems like a neat way to make a single function handle multiple data types, C++ actually offers a much better way to do the same thing (via function overloading) that retains type checking to help prevent misuse. Many other places where void pointers would once be used to handle multiple data types are now better done using templates, which also offer strong type checking.

However, very occasionally, you may still find a reasonable use for the void pointer. Just make sure there isn’t a better (safer) way to do the same thing using other language mechanisms first!

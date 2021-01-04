## Pointers and Functions

Dereferencing Return Values
Like the address-of operator, system programmers use the dereference operator very often. Many operating system APIs will return pointers, and if you want to access the referred-to object, you’ll use the dereference operator.

Unfortunately, the dereference operator can cause a lot of notation based confusion for beginners because the dereference operator, the pointer declaration, and multiplication all use asterisks. Remember that you append an asterisk to the end of the pointed-to object’s type to declare a pointer; however, you prepend the dereference operator to the pointer:

  *gettysburg_address

After accessing an object by prepending the dereference operator to a pointer, you can treat the result like any other object of the pointed-to type.

For example, because gettysburg is an integer, you can write the value 17325
into gettysburg using gettysburg_address:

  *gettysburg_address = 17325;

As the pointer is dereferenced, *gettysburg_address appears on the left side of the equal sign, you’re writing to the address where gettysburg is stored.

If a dereferenced pointer appears anywhere except the left side of an
equal sign, you’re reading from the address. To retrieve the int pointed
to by gettysburg_address, you just tack on the dereference operator. For
instance, the following statement will print the value stored in gettysburg:

  printf("%d", *gettysburg_address);



It is often wise to check that a pointer argument actually points to something:

  // count the number of occurrences of x in p[]
  // p is assumed to point to a zero-terminated array of char (or to nothing)
  int count_x(const char∗ p, char x)
  {
    if (p==nullptr)
      return 0;

    int count = 0;

    for (; ∗p!=0; ++p)
      if (∗p==x)
        ++count;

    return count;
  }

Note how we can advance a pointer to point to the next element of an array using ++




Never return from a function the address of a local variable in the function.
The local variables live in the stack space allocated for the function, not in
the heap. When the function is finished, the computer frees the stack space
used for the function, making room for the next function call.



Returning a Pointer as a Nonpointer
You may find it annoying to dereference a pointer returned from a function
every time you want to use it. You can avoid this issue by dereferencing the pointer as soon as it returns

You preceded the call to the function with an asterisk, which dereferences the result immediately. You then place the result in a local nonpointer variable. After that, you have the value in the variable, and you don’t
need to dereference the pointer when you want to use the value.

Dereferencing Your Return Value Immediately So You Don’t Need to Use It as a Pointer

  #include <iostream>

  using namespace std;
  string *GetNotSoSecretCode()
  {
    string *code = new string("ABCDEF");
    return code;
  }

  int main()
  {
    string newcode;
    int index;

    for (index = 0; index < 10; index++)
    {
      newcode = *GetNotSoSecretCode();
      cout << newcode << endl;
    }
    return 0;
  }

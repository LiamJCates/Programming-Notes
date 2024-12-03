#### Unnamed (anonymous) namespaces

An unnamed namespace (also called an anonymous namespace) is a namespace that is defined without a name, like so:

  #include <iostream>

  namespace // unnamed namespace
  {
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
  }

  int main()
  {
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
  }

Output:

  v1

All content declared in an unnamed namespace is treated as if it is part of the parent namespace. So even though function doSomething is defined in the unnamed namespace, the function itself is accessible from the parent namespace (which in this case is the global namespace), which is why we can call doSomething from main without any qualifiers.

This might make unnamed namespaces seem useless. But the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated as if they had internal linkage, which means that the content of an unnamed namespace can’t be seen outside of the file in which the unnamed namespace is defined.

For functions, this is effectively the same as defining all functions in the unnamed namespace as static functions. The following program is effectively identical to the one above:

  #include <iostream>

  static void doSomething() // can only be accessed in this file
  {
    std::cout << "v1\n";
  }

  int main()
  {
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
  }

Unnamed namespaces are typically used when you have a lot of content that you want to ensure stays local to a given file, as it’s easier to cluster such content in an unnamed namespace than individually mark all declarations as static. Unnamed namespaces will also keep user-defined types (something we’ll discuss in a later lesson) local to the file, something for which there is no alternative equivalent mechanism to do.

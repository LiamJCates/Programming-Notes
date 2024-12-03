### Inline namespaces

Now consider the following program:

  #include <iostream>

  void doSomething()
  {
    std::cout << "v1\n";
  }

  int main()
  {
    doSomething();

    return 0;
  }

Output:

v1

Pretty straightforward, right?

But let’s say you’re not happy with doSomething, and you want to improve it in some way that changes how it behaves. But if you do this, you risk breaking existing programs using the older version. How do you handle this?

One way would be to create a new version of the function with a different name. But over the course of many changes, you could end up with a whole set of almost-identically named functions (doSomething, doSomething_v2, doSomething_v3, etc…).

An alternative is to use an inline namespace. An inline namespace is a namespace that is typically used to version content. Much like an unnamed namespace, anything declared inside an inline namespace is considered part of the parent namespace. However, inline namespaces don’t give everything internal linkage.

To define an inline namespace, we use the inline keyword:

  #include <iostream>

  inline namespace v1 // declare an inline namespace named v1
  {
    void doSomething()
    {
        std::cout << "v1\n";
    }
  }

  namespace v2 // declare a normal namespace named v2
  {
    void doSomething()
    {
        std::cout << "v2\n";
    }
  }

  int main()
  {
    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v1)

    return 0;
  }

Output:

v1
v2
v1

In the above example, callers to doSomething will get the v1 (the inline version) of doSomething. Callers who want to use the newer version can explicitly call v2::dosomething(). This preserves the function of existing programs while allowing newer programs to take advantage of newer/better variations.

Alternatively, if you want to push the newer version:

  #include <iostream>

  namespace v1 // declare a normal namespace named v1
  {
    void doSomething()
    {
        std::cout << "v1\n";
    }
  }

  inline namespace v2 // declare an inline namespace named v2
  {
    void doSomething()
    {
        std::cout << "v2\n";
    }
  }

  int main()
  {
    v1::doSomething(); // calls the v1 version of doSomething()
    v2::doSomething(); // calls the v2 version of doSomething()

    doSomething(); // calls the inline version of doSomething() (which is v2)

    return 0;
  }

Output:

v1
v2
v2

In this example, all callers to doSomething will get the v2 version by default (the newer and better version). Users who still want the older version of doSomething can explicitly call v1::doSomething() to access the old behavior. This means existing programs who want the v1 version will need to globally replace doSomething with v1::doSomething, but this typically won’t be problematic if the functions are well named.

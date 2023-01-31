### Argument Order
Take care not to make function calls where argument order matters.

The C++ specification does not define the order function calls evaluate arguments, whether arguments are matched with parameters in left to right order or right to left order.

When the arguments are function calls, then this can be problematic:

  someFunction(a(), b()); // a() or b() may be called first

If the architecture evaluates left to right, a() will be called before b(). If the architecture evaluates right to left, b() will be called before a(). This may or may not be of consequence, depending on what a() and b() do.

If it is important that one argument evaluate first, you should explicitly define the order of execution, like so:

  int avar{ a() }; // a() will always be called first
  int bvar{ b() }; // b() will always be called second

  someFunction(avar, bvar);

In the above call, it doesn't matter whether avar or bvar are copied first because they are just values

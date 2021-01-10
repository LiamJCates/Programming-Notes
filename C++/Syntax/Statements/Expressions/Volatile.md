Volatile Expressions

volatile is a type qualifier which prevents the compiler from optimizing away instructions that access a given variable.

The volatile keyword tells the compiler that every access made through this expression must be treated as a visible side effect. This means access cannot be optimized out or reordered with another visible side effect.

This keyword is crucial in some settings, like embedded programming, where reads and writes to some special portions of memory have effects on the underlying system. The volatile keyword keeps the compiler from optimizing such accesses away.

Illustrates why you might need the volatile keyword by containing instructions that the compiler would normally optimize away.

int foo(int& x) {
  x = 10;
  x = 20;
  auto y = x;
  y = x;
  return y;
}

Because x is assigned but never used before getting reassigned, it’s called a dead store and is a straightforward candidate for getting optimized away. There’s a similar story where x is used to set the value of y twice without any intervening instructions. This is called a redundant load and is also a candidate for optimization.

You might expect any decent compiler to optimize the preceding function into something resembling:

int foo(int& x) {
  x = 20;
  return x;
}

In some settings, the redundant reads and dead stores might have visible side effects on the system. By adding the volatile keyword to the argument of foo, you can avoid the optimizer getting rid of these important accesses.

int foo(volatile int& x) {
  x = 10;
  x = 20;
  auto y = x;
  y = x;
  return y;
}

Now the compiler will emit instructions to perform each of the reads
and writes you’ve programmed.

A common misconception is that volatile has to do with concurrent programming. It does not. Variables marked volatile are not generally thread safe.

int fibonacci(int n) {
  if (n <= 1)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

Analysis: Fibonacci number are calculated by adding sum of the previous two number.

This is an inefficient solution, a better solution follows.

Greatest common divisor (GCD)

int GCD(int m, int n)
{
  if (m < n)
    return (GCD(n, m));

  if (m % n == 0)
    return (n);

  return (GCD(n, m % n));
}

Analysis:
Euclid’s algorithm is used to find gcd.
GCD(n, m) == GCD(m, n mod m)

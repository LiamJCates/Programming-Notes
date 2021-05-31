unsigned int reverse_bits(unsigned int n)
{
  unsigned int ans = 0;
  for(; n > 1; ans <<= 1, n >>= 1) ans += (n&1);
  return (n == 1 ? ++ans : ans);
}

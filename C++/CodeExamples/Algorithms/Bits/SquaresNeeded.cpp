/*
There is an ancient legend of a young man that requests, as compensation for labor, a single grain of rice with the stipulation that his payment double each for each subsequent payment.  Recieveing 1 grain the first day, 2 grains for the second, 4 for the third, 8 for the fourth and so on, always doubling the previous.

Given an amount of grains, you need to return up to which day one should count in order to get at least as many.

As usual, a few examples might be way better than thousands of words from me:

squaresNeeded(0) == 0
squaresNeeded(1) == 1
squaresNeeded(2) == 2
squaresNeeded(3) == 2
squaresNeeded(4) == 3

Input is always going to be valid/reasonable: ie: a non negative number; extra cookie for not using a loop to compute square-by-square (at least not directly) and instead trying a smarter approach [hint: some peculiar operator]; a trick converting the number might also work: impress me!

*/

unsigned int squaresNeeded(long long n)
{
  unsigned int i, ans;
  for(i = 1, ans = 0; n >= i; i<<=1, ++ans);
  return ans;
}

#include <math.h>

unsigned int squaresNeeded(long long n)
{
  return log2(n) + 1;
}

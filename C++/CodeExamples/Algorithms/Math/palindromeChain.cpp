/*
Number is a palindrome if it is equal to the number with digits in reversed order.

For example, 5, 44, 171, 4884 are palindromes, and 43, 194, 4773 are not.

Task:
Write a function which takes a positive integer and returns the number of special steps needed to obtain a palindrome.

The special step is: "reverse the digits, and add to the original number".

If the resulting number is not a palindrome, repeat the procedure with the sum until the resulting number is a palindrome.

If the input number is already a palindrome, the number of steps is 0.

All inputs are guaranteed to have a final palindrome which does not overflow long.
Example

For example, start with 87:

  87 +   78 =  165     - step 1, not a palindrome
 165 +  561 =  726     - step 2, not a palindrome
 726 +  627 = 1353     - step 3, not a palindrome
1353 + 3531 = 4884     - step 4, palindrome!

4884 is a palindrome and we needed 4 steps to obtain it, so answer for 87 is 4.
Additional info

Some interesting information on the problem can be found in this Wikipedia article on Lychrel numbers.

*/

long reverse (long n)
{
  long r;
  for(r = 0; n > 0; r *= 10, r+= n%10, n/=10);
  return r;
}
int palindromeChainLength (long n) {
  int steps = 0;
  for(long r = reverse(n); r != n; steps++, n+=r, r = reverse(n));
  return steps;
}

int main() {
    assert(0 = palindromeChainLength(1));
    assert(0 = palindromeChainLength(88));
    assert(0 = palindromeChainLength(393));
    assert(1 = palindromeChainLength(10));
    assert(1 = palindromeChainLength(134));
    assert(4 = palindromeChainLength(87));
    assert(7 = palindromeChainLength(2897));
    assert(24 = palindromeChainLength(89));
}

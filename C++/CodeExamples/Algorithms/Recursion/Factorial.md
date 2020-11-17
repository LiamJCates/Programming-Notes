Factorial Calculation.
N! = N* (N-1)…. 2*1. Find the factorial of the given value.

int factorial(int i)
{
  // Termination Condition
  if (i <= 1)
    return 1;

  //Body, Recursive Expansion
  return i * factorial(i - 1);
}

Analysis: 
Each time method fn is calling fn-1. Time Complexity is O(N)

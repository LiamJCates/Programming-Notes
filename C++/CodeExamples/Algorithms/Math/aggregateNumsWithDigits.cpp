/*

You have to search all numbers from inclusive 1 to inclusive a given number x, that have the given digit d in it.
The value of d will always be 0 - 9.
The value of x will always be greater than 0.

You have to return as an array

    the count of these numbers,
    their sum
    and their product.

    For example:

x = 11
d = 1
->
Numbers: 1, 10, 11
Return: [3, 22, 110]


If there are no numbers, which include the digit, return [0,0,0].

*/

/*
Decompose numbers mathematically
*/

std::vector<long> numbersWithDigitInside(long x, long d)
{
  std::vector<long> result = { 0, 0, 1 };

  for(int i = 1; i <= x; i++)
  {
    for(long number = i; number; number /= 10)
    {
      if (number % 10 == d)
      {
				result[0]++;
	      result[1] += i;
	      result[2] *= i;
        break;
      }
    }
  }

  return {result[0], result[1], result[0] == 0 ? 0 : result[2]};
}



/*
Convert to string
*/

std::vector<long> numbersWithDigitInside(long x, long d) {
  std::vector<long> result = { 0, 0, 1 };

  for (long i = 1; i <= x; i++)
    if (std::to_string(i).find_first_of((char)(d + '0')) != std::string::npos) {
      result[0]++;
      result[1] += i;
      result[2] *= i;
    }

  return {result[0], result[1], result[0] == 0 ? 0 : result[2]};
}

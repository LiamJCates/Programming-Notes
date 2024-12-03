
/*
We can check the first digit of a number with the modulus operation with 10:

int check = 9;
int number = 199;

digit = number % 10 (9)

return digit == check;

To move to the next digit of a number we divide the number by 10

number /= 10; //19

We repeate the previous process to check the next digit until the number == 0

*/

bool containsDigit(int number, int digit)
{
  while (number != 0)
  {
    int curr_digit = number % 10;
    if (curr_digit == digit) return true;
    number /= 10;
  }

  return false;
}


bool containsDigit(int number, int digit)
{
  for (;number; number /= 10)
    if (number % 10 == digit) return true;

  return false;
}

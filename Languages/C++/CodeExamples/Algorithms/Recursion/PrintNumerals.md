## Print Base 10 Integer


### Iterative Implementation

#include <cmath>

void printIntIterative(int number){
  if(number < 0) {
    std::cout << "-";
    number *= -1;
  }
  for(int divisor = 0; number > 9; number %= divisor;) {
    divisor = pow(10, floor(log10(number)));
    std::cout << static_cast<char>(number / divisor + '0');
  }

  std::cout << static_cast<char>(number + '0') << endl;
}

Analysis:
Execution begins by printing a negative sign if number is less that 0 then converting number to a positive value

Iteration on the digits of number
for each iteration it determines if number has any lower order digits by comparing to greater than 9
  it determines the number of low order digits in number via the floor of a base 10 logarithm then it raises 10 to the power of the count of low order digits, this value is assigned to divisor
  The integer value of the highest order digit in number is found by division of number by divisor
  this is then added to the value of '0', cast to a char, and printed to cout
  the remaining low order digits are extracted via modulus

After iteration only a single high order digit remains it's value is added to the value of '0', cast to a char, and printed to cout


### Recursive Implementation

void printSignRecursive(int number){
  if(number < 0) {
    printIntRecursive(number * -1);
    std::cout << "-";
  }
  printIntRecursive(int number);
}

As printIntRecursive disregards the sign of the value it is passed, this helper function can be called first to handle potentially negative integer values.

It first determines the values sign
 If the number is negative it inverts it before passing to printIntRecursive, printing a "-" upon returning;
 Otherwise it passes an unchanged number to printIntRecursive

void printIntRecursive(int number)
{
  char digit = static_cast<char>(number % 10 + '0');
  number = number / 10;
  if (number != 0)
    printIntRecursive(number);

  std::cout << digit;
}

Analysis:
· Each time remainder is calculated and its char equivalent is stored in digit.
· If the number is greater than 10 then the number divided by 10 is passed to printIntRecursive() method.
· Due to the order of the recursive calls number's lowest order digit will first then each successive higher order digit is printed as the recursive function returns.

Time Complexity is O(N)



### Function choice
While the recursive function call stack might be harder to envision, the code is much easier to write








## Print Base 16 Integer s

void printIntRecursiveBase(int number, int const base) {
  std::string conversion = "0123456789ABCDEF";
  char digit = static_cast<char>(number % base);
  number = number / base;
  if (number != 0) {
    printInt2(number, base);
  }
  std::cout << " " << conversion[digit];
}

Analysis:· Base value is provided along with the number in the function parameter.
· Remainder of the number is calculated and stored in digit.
· If the number is greater than base then, number divided by base is passed
as an argument to the printInt() method recursively.
· Number will be printed with higher order first than the lower order digits.
Time Complexity is O(N)


While this version handles up to base 16 the conversion string array can be theoretically be altered handle any base or radix.

For Example a baase64 radix can be represented via:
std::string conversion = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

The Base64 index table:
Index 	Binary 	Char 		Index 	Binary 	Char 		Index 	Binary 	Char 		Index 	Binary 	Char
0 	000000 	A 	16 	010000 	Q 	32 	100000 	g 	48 	110000 	w
1 	000001 	B 	17 	010001 	R 	33 	100001 	h 	49 	110001 	x
2 	000010 	C 	18 	010010 	S 	34 	100010 	i 	50 	110010 	y
3 	000011 	D 	19 	010011 	T 	35 	100011 	j 	51 	110011 	z
4 	000100 	E 	20 	010100 	U 	36 	100100 	k 	52 	110100 	0
5 	000101 	F 	21 	010101 	V 	37 	100101 	l 	53 	110101 	1
6 	000110 	G 	22 	010110 	W 	38 	100110 	m 	54 	110110 	2
7 	000111 	H 	23 	010111 	X 	39 	100111 	n 	55 	110111 	3
8 	001000 	I 	24 	011000 	Y 	40 	101000 	o 	56 	111000 	4
9 	001001 	J 	25 	011001 	Z 	41 	101001 	p 	57 	111001 	5
10 	001010 	K 	26 	011010 	a 	42 	101010 	q 	58 	111010 	6
11 	001011 	L 	27 	011011 	b 	43 	101011 	r 	59 	111011 	7
12 	001100 	M 	28 	011100 	c 	44 	101100 	s 	60 	111100 	8
13 	001101 	N 	29 	011101 	d 	45 	101101 	t 	61 	111101 	9
14 	001110 	O 	30 	011110 	e 	46 	101110 	u 	62 	111110 	+
15 	001111 	P 	31 	011111 	f 	47 	101111 	v 	63 	111111 	/

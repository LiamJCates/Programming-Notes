A char is 1 byte i.e. 8 bits or CHAR_BIT bits. So its signed version i.e. 2’s complement where half the range is negative and half is positive will have value from -128 to 127. Well that is not exactly opposite because we have only one zero for positive and negative numbers. If it would have been 1’s complement then range would have been from -127 to 127 but since computers follow 2’s complement the specification clearly mentions that range should be from −27 to 27−1

. Note that chars are fundamentally integral types and ASCII symbols are first 128 numbers or in other words they are 7-bit numbers.

So a character ‘0’ is internally 48 in decimal which is its integral or internally it is handled as a sequence of binary numbers representing 0x30 in hexadecimal. These integral values for characters are known as ASCII value. A full table of ASCII values is given in the appendix A.

A simple program which takes input for few characters and then prints them on console along with their ascii values is given below:

#include <stdio.h>

int main()
{
  char c = 0;
  char c1 = 0, c2 = 0;

  printf("Enter a character on your keyboard and then press ENTER:\n");
  scanf("%c", &c);
  printf("The character entered is %c and its ASCII value is %d.\n", c, c);
  // Their remains '\n' in the stdin stream which needs to be cleared.
  getchar();
  printf("Enter a pair of characters on your keyboard and then press \
          ENTER:\n");
  scanf("%c%c", &c1, &c2);
  printf("The characters entered are %c and %c and their ASCII \
          values are %d and %d respectively.\n", c1, c2, c1, c2);

  short int si = 0;

  si = c1 + c2;

  printf("The sum of c1 and c2 as integers is %hd.\n", si);

  return 0;
}

A sample run may have following output:

Enter a character on your keyboard and then press ENTER:
1
The character entered is 1 and its ASCII value is 49.
Enter a pair of characters on your keyboard and then press ENTER:
12
The characters entered are 1 and 2 and their ASCII values are 49 and 50
respectively.
The sum of c1 and c2 as integers is 99.

As you can see from the program that characters are internally stored as integers and we can even perform integers which we normally perform on numbers like addition as shown. We can perform other operation as subtraction, multiplication and division, however, most of the time addition or subtraction only makes sense to advance the characters in their class. Multiplication and division of characters with other characters or integers does not make sense.

One problem of concern is the extra \n in the input stream. It does not cause trouble with integers but when you want to read characters then the Enter or Return keys which may be left over from the last input will cause trouble. \n is recognized as a character and will be assigned to next variable if it is in stdin. One of the ways to remove it is to make a call to getchar which reads one character from the stdin stream.

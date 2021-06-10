Enumeration Constant
There is one other kind of constant, the enumeration constant. An
enumeration is a list of constant integer values, as in

enum boolean { NO, YES };

The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified:

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

If not all values are specified, unspecified values continue
the progression from the last specified value

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB is 2, MAR is 3, etc. */


Names in different enumerations must be distinct.
Values need not be distinct in the same enumeration.
Enumerations provide a convenient way to associate constant values with names, an alternative to #define with the advantage that the values can be generated for you. Although variables of enum types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration. Nevertheless, enumeration variables offer the chance of checking and so are often better than #defines. In addition, a debugger may be able to print values of enumeration variables in their symbolic form



enum comprises a set of named integer constant values. Each distinct enumeration constitutes a different enumerated type. In C enums are very much equivalent to integers. You can do all operations of an enum on an enumeration member. An enumeration is is a set of values. It starts from zero by default and increments by one unless specifically specified. Consider the following example:

// Description: Demo of enum

#include <stdio.h>

int main()
{
  typedef enum {zero, one, two} enum1;
  typedef enum {alpha=-5, beta, gamma, theta=4, delta, omega} enum2;

  printf("zero = %d, one = %d, two=%d\n", zero, one, two);
  printf("alpha = %d, beta = %d, gamma=%d, theta=%d, delta=%d, omega=%d\n", \
          alpha, beta, gamma, theta, delta, omega);

  return 0;
}

and the output is:

zero = 0, one = 1, two=2
alpha = -5, beta = -4, gamma=-3, tehta=4, delta=5, omega=6

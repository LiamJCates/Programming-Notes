For complex types, there is a system header complex.h which internally includes various other headers. However I am giving you the summary here. There are following #define macros:

complex: Expands to _Complex

_Complex_I: Expands to a constant expression of type const float _Complex with the value of the imaginary.

imaginary: Expands to _Imaginary.

_Imaginary_I: Expands to a constant expression of type const float _Imaginary with the value of the imaginary value. I: Expands to either _Imaginary_I or _Complex_I. If _Imaginary_I is not defined, I expands to _Complex_I.

Complex types are declared as given below:

        float complex fCompZ;

        double complex dCompZ;

        long double ldCompZ;

Now I will present a summary of library functions provided by complex.h

//cabs, cabsf, cabsl - these compute and return absolute value
//of a complex number z

double cabs(double complex z);
float cabsf(float complex z);
long double cabsl(long double complex z);

//carg, cargf, cargl - these compute and return argument of a complex
//number z. The range of return value's range from one +ve pi radian
//to one -ve pi radian.

double carg(double complex z);
float cargf(float complex z);
long double cargl(long double complex z);

//cimag, cimagf, cimagl - these compute imaginary part of a complex
//number z and return that as a real number.

double cimag(double complex z);
float cimagf(float complex z);
long double cimagl(long double complex z);

//creal, crealf, creall - these compute real part of a complex
//number z and return the computed value.

double creal(double complex z);
float crealf(float complex z);
long double creall(long double complex z);

//conj, conjf, conjl - these functions compute the complex conjugate
//of z, by reversing the sign of its imaginary part and return the
//computed value.

double complex conj(double complex z);
float complex conjf(float complex z);
long double complex conjl(long double complex z);

//cproj, cprojf, cprojl - these functions compute a projection of z
// onto the Riemann sphere: z projects to z, except that all complex
//infinities (even those with one infinite part and one NaN (not a
//number) part) project to positive infinity on the real axis. If z
//has an infinite part, then cproj( z) shall be equivalent to:
//INFINITY + I * copysign(0.0, cimag(z))
//These functions return the computed value.

double complex cproj(double complex z);
float complex cprojf(float complex z);
long double complex cprojl(long double complex z);

//cexp, cexpf, cexpl - these functions shall compute the complex
//exponent of z, defined as e^z and return the computed value

double complex cexp(double complex z);
float complex cexpf(float complex z);
long double complex cexpl(long double complex z);

//clog, clogf, clogl - these functions compute the complex
//natural (base e) logarithm of z, with a branch cut along
//the negative real axis and return complex natural logarithm
//value, in a range of a strip mathematically unbounded along
//real axis and in the interval -ipi to +ipi along the
//imaginary axis.

double complex clog(double complex z);
float complex clogf(float complex z);
long double complex clogl(long double complex z);

//csqrt, csqrtf, csqrtl - these functions compute the complex
//square root of z, with a branch cut along the negative real
//axis and return the computed value in the range of the right
//half-plane (including the imaginary axis)

double complex csqrt(double complex z);
float complex csqrtf(float complex z);
long double complex csqrtl(long double complex z);

//cpow, cpowf, cpowl - these functions compute the complex
//power function x^y, with a branch cut for the first
//parameter along the negative real axis and return the
//computed value.

double complex cpow(double complex x, double complex y);
float complex cpowf(float complex x, float complex y);
long double complex cpowl(long double complex x,
long double complex y);

//csin, csinf, csinl - these functions compute the complex
//sine of z and return the computed value.

double complex csin(double complex z);
float complex csinf(float complex z);
long double complex csinl(long double complex z);

//ccos, ccosf, ccosl - these functions compute the complex
//cosine of z and return the computed value.

double complex ccos(double complex z);
float complex ccosf(float complex z);
long double complex ccosl(long double complex z);

//ctan, ctanf, ctanl - these functions compute the complex
//tangent of z and return the computed value.

double complex ctan(double complex z);
float complex ctanf(float complex z);
long double complex ctanl(long double complex z);

//casin, casinf, casinl - these functions compute the complex
//arc sine of z, with branch cuts outside the interval
//[-1, +1] along the real axis and return the computed value
//in the range of a strip mathematically unbounded along the
//imaginary axis and in the interval -0.5pi to +0.5pi radian
//inclusive along the real axis.

double complex casin(double complex z);
float complex casinf(float complex z);
long double complex casinl(long double complex z);

//cacos, cacosf, cacosl - these functions compute the complex
//arc cosine of z, with branch cuts outside the interval
//[-1, +1] along the real axis and return the computed value
//in the range of a strip mathematically unbounded along the
//imaginary axis and in the interval -0 to +pi radian
//inclusive along the real axis.

double complex cacos(double complex z);
float complex cacosf(float complex z);
long double complex cacosl(long double complex z);

//catan, catanf, catanl - these functions compute the complex
//arc tangent of z, with branch cuts outside the interval
//[-i, +i] along the real axis and return the computed value
//in the range of a strip mathematically unbounded along the
//imaginary axis and in the interval -0.5pi to +0.5pi radian
//inclusive along the real axis.

double complex catan(double complex z);
float complex catanf(float complex z);
long double complex catanl(long double complex z);

//csinh, csinhf, csinhl - these functions compute the complex
//hyperbolic sine of z and return the comupted value.

double complex csinh(double complex z);
float complex csinhf(float complex z);
long double complex csinhl(long double complex z);

//ccosh, ccoshf, ccoshl - these functions shall compute the
//complex hyperbolic cosine of z and return the computed
//value

double complex ccosh(double complex z);
float complex ccoshf(float complex z);
long double complex ccoshl(long double complex z);

//ctanh, ctanhf, ctanhl - these functions compute the
//complex hyperbolic tangent of z and return the computed
//value.

double complex ctanh(double complex z);
float complex ctanhf(float complex z);
long double complex ctanhl(long double complex z);

//casinh, casinhf, casinhl - these functions compute the
//complex arc hyperbolic sine of z, with branch cuts
//outside the interval [-i, +i] along the imaginary axis and
//return the complex arc hyperbolic sine value, in the range
//of a strip mathematically unbounded along the real axis
//and in the interval [-i0.5pi, +i0.5pi] along the imaginary
//axis.

double complex casinh(double complex z);
float complex casinhf(float complex z);
long double complex casinhl(long double complex z);
cacosh, cacoshf, cacoshl - theese functions compute the

//complex arc hyperbolic cosine of z, with a branch cut at
//values less than 1 along the real axis and return the complex
//arc hyperbolic cosine value, in the range of a half-strip
//of non-negative values along the real axis and in the
//interval [-ipi, +ipi] along the imaginary axis.

double complex cacosh(double complex z);
float complex cacoshf(float complex z);
long double complex cacoshl(long double complex z);

//catanh, catanhf, catanhl - these functions shall compute the
//complex arc hyperbolic tangent of z, with branch cuts outside
//the interval [-1, +1] along the real axis and return the
//complex arc hyperbolic tangent value, in the range of a strip
//mathematically unbounded along the real axis and in the
//interval [-i0.5pi, +i0.5pi] along the imaginary axis.

double complex catanh(double complex z);
float complex catanhf(float complex z);
long double complex catanhl(long double complex z);

Hers is a small demo program which explains two functions:

// Complex Number Program
// Description: Demo of complex data type

#include <stdio.h>
#include <complex.h>

int main()
{
  double complex z = 4.0 + 3.0i;

  printf("Absolute value of z is %lf\n", cabs(z));

  double complex zConj = conj(z);
  printf("Imaghinary part of conjugate is now %lf\n", cimag(zConj));

  return 0;
}

and the output is:

Absolute value of z is 5.000000
Imaghinary part of conjugate is now -3.000000

You must note that in Makefile you must compile it like $gcc complex.c -o complex -lm. Note the -lm part. It tells to look for definition of these functions in Math library of C. Without it the program won’t compile. At this point I encourage you to further explore different functions presented in the summary.

There are even more data types for integral type. I am sorry but I am unwrapping the layers one by one. These types are defined in inttypes.h and stdint.h. The types are int8_t, int16_t, int32_t, uint8_t, uint16_t and uint32_t. The numbers tell you how many bits each data type will occupy. The types without leading u are of signed type and the ones with it are of unsigned type. You can use the good old %d or %i for decimal integers and others for octals and hexes. Have a look at headers and try to decipher them.

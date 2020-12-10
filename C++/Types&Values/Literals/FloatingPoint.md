## Floating Point Literals
Floating-point numbers are recognized by:
decimal point (e.g., 3.14)
exponent (e.g., 3e−2).

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

Floating-point literals are double precision by default.

If you need single precision, use an f or F suffix; for extended precision, use l or L, as shown here:
float a = 0.1F;
double b = 0.2;
long double c = 0.3L;

You can also use scientific notation in literals:
double plancks_constant = 6.62607004ue-34v;

No spaces are permitted between the significand (the base u) and the
suffix (the exponential portion v).

While representing using decimal form, you must include the decimal point, the exponent, or both and while representing using exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       // Legal
314159E-5L    // Legal

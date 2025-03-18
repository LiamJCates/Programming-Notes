## Floating-point literals

A floating-point literal can have the following parts:

    An unsigned decimal integer,
    A decimal point (.),
    A fraction (another decimal number),
    An exponent.

The exponent part is an e or E followed by an integer, which can be signed (preceded by + or -). A floating-point literal must have at least one digit, and either a decimal point or e (or E).

More succinctly, the syntax is:

[digits].[digits][(E|e)[(+|-)]digits]

For example:


3.1415926
.123456789
3.1E+12
.1e-23
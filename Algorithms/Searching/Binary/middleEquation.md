Why use low + (high - low) / 2 instead of (low + high) / 2 ?

To prevent overflowing, an explanation follows.


Suppose the maximum integer value is 100, low = 50, and night = 80.
If you use the naive formula:

int mid = (low + high)/2;

the addition will result in 130, which overflows.

If you instead do:

int mid = low + (high - low)/2;

you can't overflow in (high - low) because you're subtracting a smaller number from a larger number. That always results in an even smaller number, so it can't possibly go over the maximum. E.g. 80 - 50 = 30.

And since the result is the average of low and high, it must be between them. Since these are both less than the maximum integer, anything between them is also less than the maximum, so there's no overflow.

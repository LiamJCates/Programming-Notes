

It's 3
because −11=7(−2)+3

.

Another way to see this is to take −11
and keep adding 7 to it until you get a positive number. This works because, if you're working modulo 7, then adding 7 is the same as not changing the number (modulo 7

). So:

−11+7≡−11(mod7)
, and −11+7=−4. Therefore −4≡−11(mod7)

. Well, we're still negative. Let's do it again:

−4+7≡−11(mod7)
, and −4+7=3. Therefore, 3≡−11(mod7)

.

Or, equivalently, −11≡3(mod7)

.

How do we know to use −2

? Let's recall how it works with positives first.

If you want to evaluate 31(mod7)
, you first recognize that 31=28+3=7⋅4+3. Therefore 31≡3(mod7). What did we do here? We found the largest multiple of 7 that's less than or equal to 31

.

Alternatively, with division, you can evaluate 31/7≈4.429
. The largest integer less than or equal to this is 4. Therefore 31=7⋅4+some number, where your goal is to determine what some number

is.

This same exact process applies for negative numbers.

If you want to evaluate −11(mod7)
, you need the largest multiple of 7 that's less than or equal to −11. This is −14. And −14+3=−11, therefore your answer is 3

.

Alternatively, with division, you can evaluate −11/7≈−1.571
. The largest integer less than or equal to this is −2. Therefore −11=7⋅(−2)+some number, where your goal is to determine what some number is.
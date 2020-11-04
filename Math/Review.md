Mathematics Review


Exponents
(x^a)*(x^b) = x^(a+b)
(x^a)/(x^b) =   x^(a-b)
 (x^a)^b = x^(ab)
(x^n)*(x^n) = 2x^n ≠ x^(2n)
2^n + 2^n = 2^(n+1)


Logarithms
"What power must we raise this base to, in order to get this answer?"

The main thing we use logarithms for is solving for x when x is in an exponent.

BX = Y         →         log B Y = X

So if we wanted to solve this:
10^x=100

We need to bring the x down from the exponent somehow, logarithms give us a trick for doing that.

We take the log⁡10​ of both sides:    log⁡1010x= log⁡10100

Now the left-hand side is asking, "what power must we raise 10 to in order to get 10^x?"

The answer, of course, is x. So we can simplify that whole left side to just "x":    x = log⁡10100


Now we just have to evaluate the right side.

What power do we have to raise 10 to in order to get 100?

x=2

That's how we use logarithms to pull a variable down from an exponent.


In computer science, all logarithms are to the base 2 unless specified otherwise.

X^A = B             if and only if logX B = A

logA B = logC B / logC A         for A, B, C > 0, A ≠ 1

log AB = log A + log B;         for A, B > 0

log A/B = log A − log B

log(A^B) = B * log A        log X < X for all X > 0




Where logs come up in algorithms and interviews

A question we often ask ourselves in computer science:
"How many times must we double 1 before we get to n"
"How many times must we divide n in half in order to get back down to 1?"

Binary Search
"how many times must we divide our original list size (n) in half until we get down to 1?"

log2 n

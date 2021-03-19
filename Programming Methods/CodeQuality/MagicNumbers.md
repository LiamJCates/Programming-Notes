### Magic Numbers

In computer programming, the term magic number has multiple meanings. It could refer to one or more of the following:

	 1. Unique values with unexplained meaning or multiple occurrences which could (preferably) be replaced with named constants
	 2. A constant numerical or text value used to identify a file format or protocol; for files, see List of file signatures
	 3. Distinctive unique values that are unlikely to be mistaken for other meanings (e.g., Globally Unique Identifiers)


For the first issue, Unique values with unexplained meaning or multiple occurrences which could (preferably) be replaced with named constants.

It’s very important for code maintenance to use value substitution with named constants instead of so-called “magic numbers.”

The use of unnamed magic numbers in code obscures the developers' intent in choosing that number. Magic numbers increase opportunities for subtle errors (e.g. is every digit correct in 3.14159265358979323846 and is this equal to 3.14159?) and makes it more difficult for the program to be adapted and extended in the future. Replacing all significant magic numbers with named constants makes programs easier to read, understand and maintain.

If you use magic numbers in your code, not only does the reader have no idea where the numbers come from or what they represent, but if you decide to change a value, you must perform hand editing, and you have no trail to follow to ensure you don’t miss one of your values (or accidentally change one you shouldn’t).

Names chosen to be meaningful in the context of the program can result in code that is more easily understood by a maintainer who is not the original author (or even by the original author after a period of time). An example of an uninformatively-named constant is int SIXTEEN = 16, while int NUMBER_OF_BITS = 16 is more descriptive.

The problems associated with magic 'numbers' described above are not limited to numerical types and the term is also applied to other data types where declaring a named constant would be more flexible and communicative. Thus, declaring const string testUserName = "John" is better than several occurrences of the 'magic value' "John" in a test suite.

For example, if it is required to randomly shuffle the values in an array representing a standard pack of playing cards, this pseudocode does the job using the Fisher–Yates shuffle algorithm:

   for i from 1 to 52
       j := i + randomInt(53 - i) - 1
       a.swapEntries(i, j)

where a is an array object, the function randomInt(x) chooses a random integer between 1 and x, inclusive, and swapEntries(i, j) swaps the ith and jth entries in the array. In the preceding example, 52 is a magic number. It is considered better programming style to write the following:

   constant int deckSize := 52
   for i from 1 to deckSize
       j := i + randomInt(deckSize + 1 - i) - 1
       a.swapEntries(i, j)

This is preferable for several reasons:

    It is easier to read and understand. A programmer reading the first example might wonder, What does the number 52 mean here? Why 52? The programmer might infer the meaning after reading the code carefully, but it is not obvious. Magic numbers become particularly confusing when the same number is used for different purposes in one section of code.
    It is easier to alter the value of the number, as it is not duplicated. Changing the value of a magic number is error-prone, because the same value is often used several times in different places within a program. Also, when two semantically distinct variables or numbers have the same value they may be accidentally both edited together. To modify the first example to shuffle a Tarot deck, which has 78 cards, a programmer might naively replace every instance of 52 in the program with 78. This would cause two problems. First, it would miss the value 53 on the second line of the example, which would cause the algorithm to fail in a subtle way. Second, it would likely replace the characters "52" everywhere, regardless of whether they refer to the deck size or to something else entirely, such as the number of weeks in a Gregorian calendar year, or more insidiously, are part of a number like "1523", all of which would introduce bugs. By contrast, changing the value of the deckSize variable in the second example would be a simple, one-line change.
    It encourages and facilitates documentation. The single place where the named variable is declared makes a good place to document what the value means and why it has the value it does. Having the same value in a plethora of places either leads to duplicate comments (and attendant problems when updating some but missing some) or leaves no one place where it's both natural for the author to explain the value and likely the reader shall look for an explanation.
    The declarations of "magic number" variables are placed together, usually at the top of a function or file, facilitating their review and change.
    It facilitates parameterization. For example, to generalize the above example into a procedure that shuffles a deck of any number of cards, it would be sufficient to turn deckSize into a parameter of that procedure, whereas the first example would require several changes.

   function shuffle (int deckSize)
      for i from 1 to deckSize
          j := i + randomInt(deckSize + 1 - i) - 1
          a.swapEntries(i, j)

    It helps detect typos. Using a variable (instead of a literal) takes advantage of a compiler's checking. Accidentally typing "62" instead of "52" would go undetected, whereas typing "dekSize" instead of "deckSize" would result in the compiler's warning that dekSize is undeclared.
    It can reduce typing in some IDEs. If an IDE supports code completion, it will fill in most of the variable's name from the first few letters.

### Disadvantages are:

    When the named constant is not defined near its use, it hurts the locality, and thus comprehensibility, of the code. Putting the 52 in a possibly distant place means that, to understand the workings of the for loop completely (for example to estimate the run-time of the loop), one must track down the definition and verify that it is the expected number. This is easy to avoid (by relocating the declaration) when the constant is only used in one portion of the code. When it's used in disparate portions, on the other hand, the remote location is a clue to the reader that the same value appears elsewhere, that may also be worth looking into.
    It may make the code more verbose. The declaration of the constant adds a line. When the constant's name is longer than the value's, particularly if several such constants appear in one line, it may make it necessary to split one logical statement of the code across several lines. An increase in verbosity may be justified when there is some likelihood of confusion about the constant, or when there is a likelihood the constant may need to be changed, such as reuse of a shuffling routine for other card games. It may equally be justified as an increase in expressiveness.
    It may be slower to process the expression deckSize + 1 at run-time than the value "53", although most modern compilers and interpreters will notice that deckSize has been declared as a constant and pre-calculate the value 53 in the compiled code. Even when that's not an option, loop optimization will move the addition so that it is performed before the loop. There is therefore usually no (or negligible) speed penalty compared to using magic numbers in code.
    It can make debugging more difficult on systems where the debugger doesn't display the values of constants (for example, because the compiler has optimized them out).


### Accepted uses

This section needs additional citations for verification. Please help improve this article by adding citations to reliable sources. Unsourced material may be challenged and removed. (March 2010) (Learn how and when to remove this template message)

In some contexts, the use of unnamed numerical constants is generally accepted (and arguably "not magic"). While such acceptance is subjective, and often depends on individual coding habits, the following are common examples:

    the use of 0 and 1 as initial or incremental values in a for loop, such as for (int i = 0; i < max; i += 1)
    the use of 2 to check whether a number is even or odd, as in isEven = (x % 2 == 0), where % is the modulo operator
    the use of simple arithmetic constants, e.g., in expressions such as circumference = 2 * Math.PI * radius,[1] or for calculating the discriminant of a quadratic equation as d = b^2 − 4*a*c
    the use of powers of 10 to convert metric values (e.g. between grams and kilograms) or to calculate percentage and per mille values
    exponents in expressions such as (f(x) ** 2 + f(y) ** 2) ** 0.5 for f ( x ) 2 + f ( y ) 2 {\displaystyle {\sqrt {f(x)^{2}+f(y)^{2}}}} {\displaystyle {\sqrt {f(x)^{2}+f(y)^{2}}}}

The constants 1 and 0 are sometimes used to represent the boolean values True and False in programming languages without a boolean type, such as older versions of C. Most modern programming languages provide a boolean or bool primitive type and so the use of 0 and 1 is ill-advised. This can be more confusing since 0 sometimes means programmatic success (when -1 means failure) and failure in other cases (when 1 means success).

In C and C++, 0 is sometimes used to represent the null pointer. As with boolean values, the C standard library includes a macro definition NULL whose use is encouraged. Other languages provide a specific null or nil value and when this is the case no alternative should be used. The typed pointer constant nullptr has been introduced with C++11.

Sequence

In this pseudo-code program, designed to find the average of two whole numbers, the instructions are in in the wrong sequence:

total ← 0
average ← number1/number2
OUTPUT “Enter the first number”
number1 ← USERINPUT
OUTPUT “Enter the second number”
number2 ← USERINPUT
OUTPUT "The average is " + average

Running this program would result in a logic error, because it tries to calculate the average before it knows the values of the numbers.

This version has the instructions in the correct sequence:

total ← 0
OUTPUT “Enter the first number”
number1 ← USERINPUT
OUTPUT “Enter the second number”
number2 ← USERINPUT
average ← number1/number2
OUTPUT "The average is " + average

Having statements in the wrong order is one of the simplest, yet most common, logical programming errors. The error occurs no matter which programming language is used.





Selection

Selection works by testing a condition. The test gives a Boolean result - TRUE or FALSE.

In programming, selection is implemented using IF THEN ELSE statements:

OUTPUT “How old are you?”
age ← USERINPUT
IF age > 16 THEN
     OUTPUT "You are old enough to drive a car"
ELSE
     OUTPUT "Come back when you are older!"
ENDIF

In the above pseudo-code program, the path the program takes depends on the condition. A variable, in this case age, is used to test the condition.

If the value of age is greater than 16, the result of the tested condition is TRUE and the program follows the first path, which follows the statement THEN. This path outputs to the user that they are old enough to drive.

If the value of age is less than 16, the result is FALSE and the program follows the second path, which follows the statement ELSE. This path outputs to the user that they are not yet old enough to drive.

The statement ENDIF ends the selection block.




Iteration

This program would print a message out six times:

OUTPUT “Coding is cool”
OUTPUT “Coding is cool”
OUTPUT “Coding is cool”
OUTPUT “Coding is cool”
OUTPUT “Coding is cool”
OUTPUT “Coding is cool”                   



Definite Iteration
Definite iteration uses the statements FOR and ENDFOR to determine what code is repeatedly executed and how many times. This program would also print out a message six times:

FOR count ← 1 TO 6
     OUTPUT “Coding is cool”
ENDFOR

The first line of the program determines how many times the code is to be iterated. It uses a variable, in this case count, known as the stepper variable, to keep track of how many times the code has been repeated so far. The variable is given a starting value.

Every time the code is iterated, the value of count increases by one. At the end of the iteration, the value of count is tested to see if it matches the end value. If the result is FALSE, the code loops back to the start of the iteration and runs again. If it is TRUE, the iteration ends and the program continues with the next line of code.

The stepper variable used to initialise a FOR loop can be used within the loop itself. This program uses a loop’s condition variable to print the ten times table:

FOR count ← 1 TO 10
     OUTPUT count * 10
ENDFOR

As can be seen above, by using iteration a program is simplified, less error prone and more flexible. This is because:

    there are fewer lines of code, meaning fewer opportunities for typing errors to creep in
    to increase or decrease the number of iterations, all the programmer has to do is change the loop's end value

FOR loops with STEP

It is also possible to add the keyword STEP to the first line of a FOR loop to determine how much the stepper variable increases or decreases by with each iteration.

The code below would output 1, 3, 5, 7, 9 as the value of count increases by two for each iteration:

FOR count ← 1 TO 10 STEP 2
     OUTPUT count
ENDFOR

The code below would display 5, 4, 3, 2, 1 as the value of count decreases by one for each iteration:

FOR count ← 5 TO 1 STEP -1
    OUTPUT count
ENDFOR



Indefinite Iteration
Indefinite iteration repeatedly executes a section of code until a condition is met - or no longer met. There are two types of indefinite iteration:

    WHILE loops - uses the statements WHILE and ENDWHILE
    REPEAT UNTIL loops - uses the statements REPEAT and UNTIL

WHILE loops

WHILE loops test the condition at the beginning of the loop. If the condition is met, the code within the loop is executed before the program loops back to test the condition again. This program would print out a message six times:

count ← 0
WHILE count < 6
     OUTPUT “Coding is cool”
     count ← count + 1
ENDWHILE

The WHILE statement defines the start of the loop. The ENDWHILE statement declares the end of the loop. By combining the start and the end, the scope of the statement is identified.

A variable, in this case count, is used for the condition. The WHILE statement also tests the condition - in this case to see if the value of count is less than six. If the result is TRUE, the code within the loop is executed, then the program loops back to the condition, which is tested again.

The iteration continues until the condition test result is FALSE, at which point the loop ends and the program executes the next line of code in sequence after the loop.

Because the condition is tested at the start of the loop, it is possible for the code within it to never actually be executed. Consider this program:

password ← USERINPUT
WHILE password <> “B1t3s1z£”
     OUTPUT “Password incorrect. Try again.”
     password ← USERINPUT
ENDWHILE

The first time the condition is tested, the result may be FALSE if the value of password matches. Because of this, none of the code within the loop will be executed and the program will move onto the next line of code in sequence after the loop.

WHILE loops are particularly useful for validation of user inputs as the code can insist that they retry entering data until it is correct.



REPEAT UNTIL loops

REPEAT UNTIL loops function in the same way as WHILE loops, with one major difference - the condition is tested at the end of the loop:

count ← 0
REPEAT
     OUTPUT “Coding is cool”
     count ← count + 1
UNTIL count = 10

The REPEAT statement defines the start of the loop. The UNTIL statement tests the condition and declares the end of the statement scope. Because the condition is tested at the end, the code within the loop is always executed at least once, even if the result of the test is FALSE.









Nested


Nested iteration

Iteration can also be nested. This program uses two definite FOR loops, one within another, to print out the times table for all numbers from one to ten:

FOR x ← 1 TO 10
     FOR y ← 1 TO 10
          result ← y * x
          OUTPUT y + " * " + x + " = " + result
     ENDFOR
ENDFOR              

For every iteration of x, y is iterated ten times.

Nested iteration isn't limited to FOR loops. A WHILE loop can be nested in a FOR loop and a FOR loop can be nested in a WHILE loop.



Nested selection

When using selection, the number of possible paths at a decision point can be increased by including one selection within another.

This program uses nested selection:

age ← int(input("How old are you? ")
if age > 16 then
     OUTPUT("You are old enough to drive a car and ride a moped!")
ELSE
     if age == 16 then
           OUTPUT("You are old enough to ride a moped!")
     ELSE
           OUTPUT("Come back when you are older!")
     ENDIF
ENDIF

Here, there are two conditions that may be tested, resulting in three possible paths to follow. The second condition is only tested if the result of the first test is FALSE.

Nested selection can be built up over and over to include many possibilities and paths for a program to follow. It allows for complex decisions to be made.

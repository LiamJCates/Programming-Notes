The pseudocode examples


Hello world in pseudocode
The first example will be a short program that just prints Hello, World! to the screen:
print "Hello, World!"


Variables declaration in pseudocode
In this example, we will create a couple of variables. The first one will store an integer.
The second one will store the value from the first one but converted into a string:

my_int_value = 10
my_string_value = string(my_int_value)

The for loop in pseudocode
In this example, we will have a for loop that iterates 10 times and prints the values 0 to 9:

for i = 0 to 10
  print i
end_for

Functions in pseudocode
In this example, we will create a small function that will accept three integers as arguments. The function should then return the largest of them. We will also call the function and display the result.

In the function, we first check whether the first argument is larger than the two others.
If it is, we have found the largest value, and we return it.
As we do a return as soon as we find the largest value, we will not need to use any else
statements in this program as a return will exit the function immediately.
We will, therefore, only need to compare the second argument with the third. If the
second is larger than the third, we return it; otherwise, we will return the third argument
as it must be the largest value. This is shown with the following code:

function max_of_three(first, second, third)
  if first > second and first > third then
    return first
  end_if
  if second > third then
    return second
  end_if
  return third
end_function

maximum = max_of_three(34, 56, 14)
print maximum

while loops, user input, if, and for loops in pseudocode
In this example, we will illustrate several concepts at the same time.
This program will ask the user to enter numbers, as many as they want. They can stop entering new values by entering a negative number. All values, except the final negative one, will be stored in a dynamic array.
Before the program exists, we will print all the values that we have stored with the following code block:

values = []
inputValue = 0

while inputValue >= 0
  print "Enter a number: "
  input inputValue
  if inputValue >= 0
    values.add(inputValue)
  end_if
end_while

From the preceding code, we see that:
1. First, we create a dynamic array. Remember that this is a list in which we can add and remove values during the program execution; that is, it is not a fixed-size array for which we will need to define how many items we want to store in it:

2. We will then enter a while loop, and inside it, ask the user for a number.

3. We will add the entered number to the dynamic array and will keep doing that until the user enters a negative number. This negative number should not be added to the array, but instead, it will act as an indication that the user is done entering numbers so we can exit the loop

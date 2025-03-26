
Function Structure

If you have a single function that is very long, break it apart into smaller sub-functions. The definition of "very long" is vague, but often a function longer than 20-30 lines is pushing it.

If you try to describe the function's purpose and find yourself using the word "and" a lot, that probably means the function does too many things and should be split into sub-functions.



### Boolean Zen

Don't ever test whether a boolean value is == or != to true or false.

Bad
if (x == true) {
  ...
} else if (x != true) {
  ...
}

Good
if (x) {
  ...
} else {
  ...
}


If you have an if/else statement that returns a boolean value based on a test, just directly return the test's result instead.

Bad
if (score1 == score2) {
  return true;
} else {
  return false;
}

Good
return score1 == score2;



### If/Else Usage


When using if/else statements, properly choose between various if and else patterns depending on whether the conditions relate to one another. Avoid redundant or unnecessary if tests.

Bad
if (grade >= 90) {
  alert("You got an A!");
}
if (grade >= 80 && grade < 90) {
  alert("You got a B!");
}
if (grade >= 70 && grade < 80) {
  alert("You got a C!");
}
...


Good
if (grade >= 90) {
  alert("You got an A!");
} else if (grade >= 80) {
  alert("You got a B!");
} else if (grade >= 70) {
  alert("You got a C!");
}
...


Move common code out of if/else statements so that it is not repeated (ie., minimize redundancy in your code).

Bad
if (x < y) {
  foo();
  x++;
  alert("hi");
} else {
  foo();
  y++;
  alert("hi");
}

Good
foo();
if (x < y) {
  x++;
} else {
  y++;
}
alert("hi");



Loop Usage

For Loops vs. While Loops

Use a for loop when the number of repetitions is known (definite); use a while loop when the number of repetitions is unknown (indefinite).

Bad
// repeat exactly size/2 times
for (let i = 0; i < size / 2; i++) {
  ...
}

Good
// repeat until the user clicks OK
while (!confirm("Are you sure?")) {
  ...
}
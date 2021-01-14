### Comparison
The relational operators can be applied to variables of type string.
str1 == str2; //< > !=

Variables of type string are compared character by character, starting with the first character and using the ASCII collating sequence. The character-by-character comparison continues until either a mismatch is found or the last characters have been compared and are equal.

Naturally, strings can be compared against each other, against C-style strings, and against string literals:

string incantation;

void respond(const string& answer)
{
  if (answer == incantation) {
    // perform magic
  }
  else if (answer == "yes") {
    // ...
  }
  // ...
}

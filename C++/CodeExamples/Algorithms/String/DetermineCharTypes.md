given a string, return a list of ints detailing the count of uppercase letters, lowercase, numbers and special characters, as follows.

Solve("*'&ABCDabcde12345") = [4,5,5,3].
--the order is: uppercase letters, lowercase, numbers and special characters.

#include <cctype>

std::vector<int> solve(std::string s){
    std::vector <int> v = {0,0,0,0};
    for(char ch : s) {
        if (isupper(ch)) v[0]++;
        else if (islower(ch)) v[1]++;
        else if (isdigit(ch)) v[2]++;
        else v[3]++;
    }
    return v;
}





cctype header declares a set of functions to classify and transform individual characters

bool function(char);
isalnum: Check if character is alphanumeric
isalpha: Check if character is alphabetic
isblank: Check if character is blank
iscntrl: Check if character is a control character
isdigit: Check if character is decimal digit
isgraph: Check if character has graphical representation
islower: Check if character is lowercase letter
isprint: Check if character is printable
ispunct: Check if character is a punctuation character
isspace: Check if character is a white-space
isupper: Check if character is uppercase letter
isxdigit: Check if character is hexadecimal digit


Character conversion functions
Two functions that convert between letter cases

char function(char);
tolower: Convert uppercase letter to lowercase
toupper: Convert lowercase letter to uppercase

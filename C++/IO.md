You use std::cout (pronounced “standard see-out”) to write simple text data to the
console and use std::cin (“standard see-in”) to read text and numbers (entered using the
keyboard) from the console.

std::cout << "Hello World" << std::endl;

insertion operator <<

std::cin >> Variable;

extraction operator >>

If the user input
needs to be stored in two variables, each containing data separated by a space, then you
can do so using one statement:
std::cin >> Variable1 >> Variable2;

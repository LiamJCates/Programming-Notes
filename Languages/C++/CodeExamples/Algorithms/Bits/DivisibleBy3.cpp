/*
To check for divisbility by three, you have to count the number of ones in even position and substract the number of ones in odd positions. If the difference is divisble by three, the original number is divisbilble by three (which, in turn, can be checked by reiterating the same rule).
*/

#include <regex>
#include <string>
#include <iostream>

int main()
{
    const std::string multiple_of_3_regex = "^(0*|0*(1(01*0)*10*)+)$";
    std::regex solution(multiple_of_3_regex);
    std::cout << std::regex_match(" 0", solution) << std::endl;
    std::cout << std::regex_match("abc", solution) << std::endl;
    std::cout << std::regex_match("000", solution) << std::endl;
    std::cout << std::regex_match("110", solution) << std::endl;
    std::cout << std::regex_match("111", solution) << std::endl;
    std::cout << std::regex_match("101111000110000101001110", solution) << std::endl;
    std::cout << std::regex_match("000000000101111000110000101001110", solution) << std::endl;
}

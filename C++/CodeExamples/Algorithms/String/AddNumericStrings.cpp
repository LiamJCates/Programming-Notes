#include <string>
#include <algorithm>
#include <iostream>

std::string add(const std::string &a, const std::string &b)
{

    std::string input1, input2;
    if (a.size() > b.size())
    {
        input1 = a;
        input2 = std::string(a.size() - b.size(), '0') + b;
    }
    else if (b.size() > a.size())
    {
        input1 = std::string(b.size() - a.size(), '0') + a;
        input2 = b;
    }
    else
    {
        input1 = a;
        input2 = b;
    }

    std::string result(input1.size() + 1, '0');

    char r, carry = 0;

    for (int i = input1.size(); i--;)
    {
        r = (input1[i] - '0') + (input2[i] - '0') + carry;
        carry = (r > 9)? 1 : 0;
        r %= 10;

        result[i + 1] = r + '0';
    }

    result[0] = carry + '0';

    if (result[0] == '0')
        result = result.substr(1);

    return result;
}

int main()
{
    std::cout << add("123", "456") << std::endl;
		std::cout << add("723", "456") << std::endl;
    std::cout << add("0", "0") << std::endl;
}

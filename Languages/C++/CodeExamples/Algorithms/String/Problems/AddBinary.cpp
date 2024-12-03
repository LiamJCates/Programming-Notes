#include <string>
#include <iostream>

using namespace std;

string addBinary(string a, string b)
{
    int carry = 0;
    string result;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j)
    {
        int ai = i >= 0 ? a[i] - '0' : 0;
        int bj = j >= 0 ? b[j] - '0' : 0;
        int val = (ai + bj + carry) % 2;
        carry = (ai + bj + carry) / 2;
        result.insert(result.begin(), val + '0');
    }
    if (carry == 1)
    {
        result.insert(result.begin(), '1');
    }
    return result;
}

int main()
{
    std::string b1 =  "11010001001";
    std::string b2 =  "11000100001";
    std::string b3 = "110010101010";

    cout << addBinary(b1, b2) << endl
        << b3 << endl;
}

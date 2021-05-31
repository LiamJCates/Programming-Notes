#include <map>

struct RomanNumerals {
    std::string to_roman(unsigned num);
    unsigned from_roman(std::string num);
} RomanNumerals;

std::string RomanNumerals::to_roman(unsigned num){
    std::string res;
    std::map<unsigned, std::string, std::greater<unsigned>> mp{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},{100, "C"}, {90, "XC"},
        {50, "L"},{40, "XL"},{10, "X"},{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    std::for_each(mp.begin(), mp.end(), [&](const auto& it){
                      for(unsigned i{0}; i < num/it.first; res += it.second, ++i);
                      num %= it.first;
                  });
    return res;
}

unsigned RomanNumerals::from_roman(std::string num){
    unsigned res{0};
    std::map<char, unsigned> mp{{'M', 1000}, {'D', 500},{'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    for(std::string::size_type i{0}; i < num.size() - 1; ++i)
        res += (mp[num[i]] >= mp[num[i+1]] ? mp[num[i]] : -mp[num[i]]);
    res += mp[num[num.size() - 1]];
    return res;
}

/*
Given a vector of factions that are themselves represented by two element vectors containing the numerator and denominator, produce a string with the factions with common denominator.
*/

typedef unsigned long long int ull;

std::string convertFrac(std::vector<std::vector<ull>> &lst)
{
  constexpr auto gcd = [](ull a, ull b, const auto& gcd) -> ull
  {return b == 0 ? a : gcd(b, a % b, gcd);};

  ull LCM = lst[0][1];
  for (int i = 1; i < lst.size(); i++)
    LCM = (lst[i][1] * LCM) / gcd(lst[i][1], LCM, gcd);

  std::string ans;
  for(auto &v : lst)
    ans += "(" + std::to_string((LCM / v[1]) * v[0]) + "," + std::to_string(LCM) + ")";

  return ans;
}

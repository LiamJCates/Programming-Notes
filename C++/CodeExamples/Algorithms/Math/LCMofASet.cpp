/*
	Given a vector of integer elements, determine the LCM of the set.
*/

typedef unsigned long long int ull;

std::string convertFrac(std::vector<std::vector<ull>> &lst)
{
  constexpr auto gcd = [](ull a, ull b, const auto& gcd) -> ull
  {return b == 0 ? a : gcd(b, a % b, gcd);};

  ull lcm = lst[0][1];
  for (int i = 1; i < lst.size(); i++)
    lcm = (lst[i][1] * lcm) / gcd(lst[i][1], lcm, gcd);

  return lcm;
}

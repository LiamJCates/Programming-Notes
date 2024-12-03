/*
Given a credit card number we can determine who the issuer/vendor is with a few basic knowns.

Complete the function getIssuer() that will use the values shown below to determine the card issuer for a given card number. If the number cannot be matched then the function should return the string Unknown.

| Card Type  | Begins With          | Number Length |
|------------|----------------------|---------------|
| AMEX       | 34 or 37             | 15            |
| Discover   | 6011                 | 16            |
| Mastercard | 51, 52, 53, 54 or 55 | 16            |
| VISA       | 4                    | 13 or 16      |

*/

#include <set>

std::string getIssuer(const std::string &number)
{
  int size = number.size();
  if(number.substr(0, 1) == "4" && (size == 13 || size == 16))
    return "VISA";

  if((number.substr(0, 2) == "34" || number.substr(0, 2) == "37") && size == 15)
    return "AMEX";

  std::set<std::string> s ({"51", "52", "53", "54", "55"});
  if(s.find(number.substr(0, 2)) != s.end() && size == 16)
    return "Mastercard";

  if(number.substr(0, 4) == "6011" && size == 16)
    return "Discover";

  return "Unknown";
}

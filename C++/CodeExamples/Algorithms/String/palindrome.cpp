#include <string>


// compare front half to back half
bool isPalindrom (const std::string& str) {

  for (int i = 0, j = str.size()-1, k = j/2; i < k; i++, j--)
		if( tolower( str[i] ) != tolower( str[j] ) )
			return false;

  return true;
}


// compare front half to back half using bitwise funcitons
// letters of differing case only differ in the 6th LSB
// by xoring then together then oring with 32, the only bit set should be 32
bool isPalindrom (const std::string& str) {

  for (int i = 0, j = str.length() - 1; i < j; ++i, --j)
    if ((str[i] ^ str[j] | 32) != 32)
      return false;

  return true;
}


//Make the string uppercase then compare it's reverse
bool isPalindrom (const std::string& str) {
  std::string lstr = str;
  for (char& c : lstr)
		c = tolower(c);

  return lstr == std::string(lstr.rbegin(), lstr.rend());
}


// encapsulate comparison, and only checks the necessary number of characters (half the length).

constexpr bool isPalindrom (const std::string& str)
{
  return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin(),
		[](const char &ch1, const char &ch2)
    {
      return tolower(ch1) == tolower(ch2);
    }
	);
}

#include <locale>

// Uses locale for internationalization

bool isPalindrom(const std::string& str) {
  const std::locale& loc = std::locale();
  const auto cmp =
		[&loc](char c1, char c2)
		{
			return std::tolower(c1, loc) == std::tolower(c2, loc);
		};

	return std::equal(str.begin(), str.begin() + str.length() / 2, str.rbegin(), cmp);
}













/** Listing 22-5. Testing for Palindromes using range and transform */
#include <algorithm>
#include <iostream>
#include <locale>
#include <ranges>
#include <string>
#include <string_view>

/** Test for letter.
 * @param ch the character to test
 * @return true if @p ch is a letter
 */
bool letter(char ch)
{
  return std::isalpha(ch, std::locale{});
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale{});
}

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string_view str)
{
  auto half{ str.size() / 2 };
  auto letters_only{ str | std::views::filter(letter) };
  auto reversed{ letters_only | std::views::reverse | std::views::take(half) };
  return std::ranges::equal(letters_only | std::views::take(half), reversed);
}

int main()
{
  std::locale::global(std::locale{""});
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});

  std::string line{};
  while (std::getline(std::cin, line))
    if (is_palindrome(line))
      std::cout << line << '\n';
}





/** Listing 23-5. Testing for Palindromes */
/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string_view str)
{
  if (str.empty())
    return true;
  for (auto left{str.begin()}, right{str.end() - 1}; left < right;) {
    if (not letter(*left))
      ++left;
    else if (not letter(*right))
      --right;
    else if (lowercase(*left) != lowercase(*right))
      return false;
    else {
      ++left;
      --right;
    }
  }
  return true;
}

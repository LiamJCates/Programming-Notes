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

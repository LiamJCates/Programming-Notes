/* Find number of unique words, the outputting words and counts, aligned neatly */
#include <format>
#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> counts{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  std::string word{};
  while (std::cin >> word)
    ++counts[word];

  // Determine the longest word.
  std::string::size_type longest{};
  for (auto element : counts)
    if (element.first.size() > longest)
      longest = element.first.size();

  // For each word/count pair...
  constexpr int count_size{10}; // Number of places for printing the count
  for (auto element : counts)
    // Print the word, count, newline. Keep the columns neatly aligned.
    std::cout << std::format("{1:{0}}{3:{2}}\n",
            longest, element.first, count_size, element.second);
}


/*
ssuming the basic characters are always available in a portable manner, we can modify the wordcounting program to treat only letters as characters that make up a word. The program would no longer
count right and right? as two distinct words. The string type offers several member functions that can
help us search in strings, extract substrings, and so on.
For example, you can build a string that contains only the letters and any other characters that you
want to consider to be part of a word (such as '-'). After reading each word from the input stream, make a
copy of the word but keep only the characters that are in the string of acceptable characters. Use the find
member function to try to find each character; find returns the zero-based index of the character, if found,
or std::string::npos, if not found.
*/

/** Listing 18-1. Counting Words: Restricting Words to Letters and Letter-Like Characters */
#include <format>
#include <iostream>
#include <map>
#include <string>

int main()
{
  using count_map = std::map<std::string, int>;
  using str_size  = std::string::size_type;

  count_map counts{};
  std::string word{};

  // Characters that are considered to be okay for use in words.
  // Split a long string into parts, and the compiler joins the parts.
  std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789-_"};

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only the characters that appear in okay.
    std::string copy{};
    for (char ch : word)
      if (okay.find(ch) != std::string::npos)
        copy.push_back(ch);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // Determine the longest word.
  str_size longest{0};
  for (auto pair : counts)
    if (pair.first.size() > longest)
      longest = pair.first.size();

  // For each word/count pair...
  constexpr int count_size{10}; // Number of places for printing the count
  for (auto pair : counts)
    // Print the word, count, newline. Keep the columns neatly aligned.
    std::cout << std::format("{1:{0}}{3:{2}}\n",
        longest, pair.first, count_size, pair.second);
}


/*
those living outside the United States—may have written a slightly different program.

Perhaps you included other characters in your string of acceptable characters.

For example, if you are French and using Microsoft Windows (and the Windows-1252 character set), you may have defined the okay object as follows:

std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÄÇÈÉÊËÎÏÔÙÛÜŒŸ"
"abcdefghijklmnopqrstuvwxyzàáäçèéêëîïöùûüœÿ"
"0123456789-_"};

But what if you then try to compile and run this program in a different environment, particularly one that uses the ISO 8859-1 character set (popular on UNIX systems)?

ISO 8859-1 and Windows-1252 share many character codes but differ in a few significant ways.

In particular, the characters 'Œ', 'œ', and 'Ÿ' are missing from ISO 8859-1.

As a result, the program may not compile successfully in an environment that uses ISO 8859-1 for the compile-time character set.

What if you want to share the program with a German user? Surely that user would want to include characters such as 'Ö', 'ö', and 'ß' as letters.

What about Greek, Russian, and Japanese users?

We need a better solution. Wouldn’t it be nice if C++ provided a simple function that would notify us if a character is a letter, without forcing us to hard-code exactly which characters are letters? Fortunately, it does.

An easier way to write the program is to call the isalnum function (declared in <locale>). This function indicates whether a character is alphanumeric in the runtime character set. The advantage of using isalnum is that you don’t have to enumerate all the possible alphanumeric characters; you don’t have to worry about differing character sets; and you don’t have to worry about accidentally omitting a character from the approved string.
*/


/** Listing 18-2. Testing a Character by Calling std::isalnum  */
#include <iostream>
#include <locale>
#include <map>
#include <string>

int main()
{
  using count_map = std::map<std::string, int>;
  count_map counts{};
  std::string word{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    std::string copy{};
    for (char ch : word)
      if (std::isalnum(ch, std::locale{""}))
        copy.push_back(ch);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (auto pair : counts)
    std::cout << pair.first << '\t' << pair.second << '\n';
}


/** Creating and Sharing a Single Locale Object */
#include <iostream>
#include <locale>
#include <map>
#include <string>

int main()
{
  using count_map = std::map<std::string, int>;

  std::locale native{""};         // Get the native locale.
  std::cin.imbue(native);         // Interpret the input and output according
  std::cout.imbue(native);        // to the native locale.

  count_map counts{};
  std::string word{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    std::string copy{};
    for (char ch : word)
      if (std::isalnum(ch, native))
        copy.push_back(ch);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (auto pair : counts)
    std::cout << pair.first << '\t' << pair.second << '\n';
}


/*
the next step to improving the word-counting program is to
update it, so that it ignores case differences when counting. For example, the program should count The
just as it does the. This is a classic problem in computer programming. C++ offers some rudimentary help
but lacks some important fundamental pieces.
*/

/** Listing 19-1. Folding Uppercase to Lowercase Prior to Counting Words */
#include <iostream>
#include <locale>
#include <map>
#include <string>

int main()
{
  using count_map = std::map<std::string, int>;

  std::locale native{""};     // get the native locale
  std::cin.imbue(native);     // interpret the input and output according to
  std::cout.imbue(native);    // the native locale

  count_map counts{};
  std::string word{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    std::string copy{};
    for (char ch : word)
      if (std::isalnum(ch, native))
        copy.push_back(tolower(ch, native));
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (auto pair : counts)
    std::cout << pair.first << '\t' << pair.second << '\n';
}


/*
This program still has an issue of interpreting words that are composed of the same letters but different cases.

The various complexities involved with addressing this issue detailed here:
[C++\Utilities\locale.md]

*/

/*

We can continue rewriting the word-counting program using range and transformation headers.

The sanitize function transforms a string by removing non-letters and converting all uppercase letters to lowercase.

A further complication, however, is that the filtering and transforming functions will rely on a locale.

Solve the problem for now by setting your chosen locale as the global locale. Do this by calling std::local::global and passing a locale object as the sole argument. An std::locale object created with the default constructor uses the global locale, so after your program sets your chosen locale as the global locale, you can easily imbue a stream or otherwise access the chosen locale by means of std::locale{}.

Any function can use the global locale without having to pass locale objects around.

We can also re-write the sanitize function to take advantage of the range and transform algorithms.

Use transform to convert characters to lowercase. Use filter to keep only alphabetic characters. A string_view is a range of characters so it can feed a range pipeline.

The range pipeline feeds one character at a time from str and filters them so that only characters that we want to keep continue through the pipeline. Those characters are then converted to lowercase. The pipeline is stored in data. Using a pipeline is a convenience, but in the end the sanitize() function needs to return a real string. So how do you get data from a range pipeline into a string? Fortunately, the range library also has begin() and end() functions that can be used to make a std::string object. Algorithms, even those in the std::ranges namespace, are declared in <algorithm>. Other std::ranges functions are in <ranges>.
*/

// Copied from list2202.cpp, but sanitize() replaced by #include.

#include <algorithm>
#include <format>
#include <iostream>
#include <locale>
#include <map>
#include <ranges>
#include <string>

using count_map  = std::map<std::string, int>;  ///< Map words to counts
using count_pair = count_map::value_type;       ///< pair of a word and a count
using str_size   = std::string::size_type;      ///< String size type

/** Initialize the I/O streams by imbuing them with
 * the global locale. Use this function to imbue the streams
 * with the native locale. C++ initially imbues streams with
 * the classic locale.
 */
void initialize_streams()
{
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});
}

/** Find the longest key in a map.
 * @param map the map to search
 * @returns the size of the longest key in @p map
 */
str_size get_longest_key(count_map const& map)
{
  str_size result{0};
  for (auto pair : map)
    if (pair.first.size() > result)
      result = pair.first.size();
  return result;
}

/** Print the word, count, newline. Keep the columns neatly aligned.
 * Rather than the tedious operation of measuring the magnitude of all
 * the counts and then determining the necessary number of columns, just
 * use a sufficiently large value for the counts column.
 * @param pair a word/count pair
 * @param longest the size of the longest key; pad all keys to this size
 */
void print_pair(count_pair const& pair, str_size longest)
{
  int constexpr count_size{10}; // Number of places for printing the count
  std::cout << std::format("{1:{0}}{3:{2}}\n",
          longest, pair.first, count_size, pair.second);
}

/** Print the results in neat columns.
 * @param counts the map of all the counts
 */
void print_counts(count_map const& counts)
{
  str_size longest{get_longest_key(counts)};

  // For each word/count pair...
  for (count_pair pair: counts)
    print_pair(pair, longest);
}

/** Test whether to keep a letter.
 * @param ch the character to test
 * @return true to keep @p ch because it may be a character that makes up a word
 */
bool keep(char ch)
{
  return std::isalnum(ch, std::locale{});
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale{});
}

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a sanitized copy of the string
 */
std::string sanitize(std::string_view str)
{
  auto data{ str
             | std::views::filter(keep)
             | std::views::transform(lowercase)  };
  return std::string{ std::ranges::begin(data), std::ranges::end(data) };
}

/** Main program to count unique words in the standard input. */
int main()
{
  // Set the global locale to the native locale.
  std::locale::global(std::locale{""});
  initialize_streams();

  count_map counts{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  std::string word{};
  while (std::cin >> word)
  {
    std::string copy{sanitize(word)};

    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  print_counts(counts);
}






/*
We can also rewrite the above version of the program to use iterators
*/


/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a sanitized copy of the string
 */
std::string sanitize(std::string_view str)
{
  std::string result{};
  std::copy_if(str.begin(), str.end(), std::back_inserter(result), keep);
  std::transform(result.begin(), result.end(), result.begin(), lowercase);
  return result;
}




/*
Rather than copying only the characters that match the predicate, we can remove the characters that match it. This will require us to replace keep.
*/

/** Test for non-letter.
 * @param ch the character to test
 * @return true if @p ch is not a character that makes up a word
 */
bool non_letter(char ch)
{
  return not std::isalnum(ch, std::locale());
}

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a sanitized copy of the string
 */
std::string sanitize(std::string str)
{
  // Remove all non-letters from the string, and then erase them.
  str.erase(std::remove_if(str.begin(), str.end(), non_letter), str.end());

  // Convert the remnants of the string to lowercase.
  std::transform(str.begin(), str.end(), str.begin(), lowercase);

  return str;
}

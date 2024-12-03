Perhaps the most notable difference in typical numeric computer output from country to country is the punctuator used to separate the integer and fractional parts of a real number. In the United States, a period denotes a decimal point, but in much of the world, a comma is expected instead. It would be quite inconvenient to do all your own formatting for locale-dependent displays. Once again, creating an abstraction that handles these differences solves the problem.

That abstraction is the locale. All streams have an associated locale object that they use for guidance on how to display certain quantities for different cultural environments.

In C++, a locale is a collection of information pertaining to a culture, region, and language.

The locale header includes information about
• Formatting numbers, currency, dates, and time
• Classifying characters (letter, digit, punctuation, etc.)
• Converting characters from uppercase to lowercase and vice versa
• Sorting text (e.g., is 'A' less than, equal to, or greater than 'Å'?)
• Message catalogs (for translations of strings that your program uses)


A locale manages the categories of culture-dependent display rules, which are defined as follows:

collate
Allows comparing strings according to different, supported collating sequences.

ctype
Abstracts the character classification and conversion facilities found in <cctype>.

monetary
Supports different displays of monetary quantities.

numeric
Supports different display formats of real numbers, including radix (decimal point) and grouping (thousands) separators.

time
Supports various international formats for display of date and time.

messages
Scaffolding to implement context-dependent message catalogs (such as for error messages in different languages).



Every C++ program begins with a minimal, standard locale, which is known as the classic or "C" locale. The std::locale::classic() function returns the classic locale. The unnamed locale, std::locale{""}, is the collection of the user’s preferences that C++ obtains from the host operating system. The locale with the empty string argument is often known as the native locale. The advantage of the classic locale is that its behavior is known and fixed. If your program must read data in a fixed format, you don’t want the user’s preferences getting in the way. By contrast, the advantage of the native format is that the user chose those preferences for a reason and wants to see program output follow that format. A user who always specifies a date as day/month/year doesn’t want a program printing month/day/year simply because that’s the convention in the programmer’s home country. Thus, the classic format is often used for reading and writing data files, and the native format is best used to interpret input from the user and to present output directly to the user. Every I/O stream has its own locale object. To affect the stream’s locale, call its imbue function, passing the locale object as the sole argument.

You read that correctly: imbue, not setlocale or setloc—given that the getloc function returns a stream’s current locale—or anything else that might be easy to remember. On the other hand, imbue is such an unusual name for a member function; you may remember it for that reason alone.


In other words, when C++ starts up, it initializes each stream with the classic locale, as follows:

std::cin.imbue(std::locale::classic());
std::cout.imbue(std::locale::classic());

Suppose you want to change the output stream to adopt the user’s native locale. Do this using the following statement at the start of your program:

std::cout.imbue(std::locale{""});

For example, suppose you have to write a program that reads a list of numbers from the standard input and computes the sum. The numbers are raw data from a scientific instrument, so they are written as digit strings. Therefore, you should continue to use the classic locale to read the input stream. The output is for the user’s benefit, so the output should use the native locale.

When you use the native locale, I recommend defining a variable of type std::locale in which to store it. You can pass this variable to isalnum, imbue, or other functions. By creating this variable and distributing copies of it, your program has to query the operating system for your preferences only once, not every time you need the locale.

```cpp
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
```



### ctype
The ctype standard facet classifies and transforms characters, adapting the functionality of the C library header <cctype> to C++ locales.

the cctype functionality can be found:
[C++\Utilities\cctype.md]


std::isalnum(ch, std::locale{""})

The first argument to std::isalnum is the character to test, and the second is std::locale{""}.

Now turn your attention to the std::locale{""} argument. The locale directs std::isalnum to the character set it should use to test the character. The character set determines the identity of a character, based on its numeric value. A user can change character sets while a program is running, so the program must keep track of the user’s actual character set and not depend on the character set that was active when you compiled the program.


### Capitlization

Western European languages have long made use of capital (or majuscule) letters and minuscule letters.

The more familiar terms—uppercase and lowercase—arise from the early days of typesetting, when the type slugs for majuscule letters were kept in the upper cases of large racks containing all the slugs used to make a printing plate. Beneath them were the cases, or boxes, that stored the minuscule letter slugs.

In the <locale> header, C++ declares the isupper and islower functions. They take a character as the first argument and a locale as the second argument. The return value is a bool: true if the character is uppercase (or lowercase, respectively) and false if the character is lowercase (or uppercase) or not a letter.

std::isupper('A', std::locale{"en_US.latin1"}) == true
std::islower('A', std::locale{"en_US.latin1"}) == false
std::isupper('Æ', std::locale{"en_US.latin1"}) == true
std::islower('Æ', std::locale{"en_US.latin1"}) == false
std::islower('½', std::locale{"en_US.latin1"}) == false
std::isupper('½', std::locale{"en_US.latin1"}) == false

The <locale> header also declares two functions to convert case: toupper converts lowercase to uppercase. If its character argument is not a lowercase letter, toupper returns the character as is. Similarly,
tolower converts to lowercase, if the character in question is an uppercase letter. Just like the category
testing functions, the second argument is a locale object.


Some readers, especially German readers, may see a problem.

Several languages have letter combinations that do not map easily between uppercase and lowercase, or one character maps to two characters.

The German Eszett, ß, is a lowercase letter; when you convert it to uppercase, you get two characters: SS. Thus, if your input file contains “ESSEN” and “eßen”, you want them to map to the same word,
so they’re counted together, but that just isn’t feasible with C++. The way the program currently works, it
maps “ESSEN” to “essen”, which it counts as a different word from “eßen”. A naïve solution would be to map
“essen” to “eßen”, but not all uses of ss are equivalent to ß.
Greek readers are familiar with another kind of problem. Greek has two forms of lowercase sigma: use ς
at the end of a word and σ elsewhere. Our simple program maps Σ (uppercase sigma) to σ, so some words in
all uppercase will not convert to a form that matches its lowercase version.
Sometimes, accents are lost during conversion. Mapping é to uppercase usually yields É but may also
yield E. Mapping uppercase to lowercase has fewer problems, in that É maps to é, but what if that E (which
maps to e) really means É, and you want it to map to é? The program has no way of knowing the writer’s
intentions, so all it can do is map the letters it receives.

Some character sets are more problematic than others. For example, ISO 8859-1 has a lowercase ÿ but
not an uppercase equivalent (Ϋ). Windows-1252, on the other hand, extends ISO 8859-1, and one of the new
code points is Ϋ.

NOTE
Code point is a fancy way of saying “numeric value that represents a character.” Although most
programmers don’t use code point in everyday speech, those programmers who work closely with characterset issues use it all the time, so you may as well get used to it. Mainstream programmers should become more
accustomed to using this phrase.


In other words, converting case is impossible to do correctly using only the standard C++ library.
If you know your alphabet is one that C++ handles correctly, then go ahead and use toupper and tolower.

For example, if you are writing a command-line interpreter, within which you have full control over the commands, and you decide that the user should be able to enter commands in any case, simply make sure the commands map correctly from one case to another.

This is easy to do, as all character sets can map the 26 letters of the Roman alphabet without any problems.

On the other hand, if your program accepts input from the user and you want to map that input to uppercase or lowercase, you cannot and must not use standard C++.

For example, if you are writing a word processor, and you decide you need to implement some case-folding functions, you must write or acquire
a library outside the standard to implement the case-folding logic correctly. Most likely, you would need
a library of character and string functions to implement your word processor. Case-folding would simply
be one small part of this hypothetical library.


What about our simple program? It isn’t always practical to handle the full, complete, correct handling of cases and characters when you just want to count a few words.

The case-handling code would dwarf the word-counting code.

In this case (pun intended), you must accept the fact that your program will sometimes produce incorrect results. Our poor little program will never recognize that “ESSEN” and “eßen” are the same word but in different cases.

You can work around some of the multiple mappings (such as with Greek sigma) by mapping to uppercase, then to lowercase. On the other hand, this can introduce problems with some accented characters. And I still have not touched upon the issue of whether “naïve” is the same word as “naive”. In some locales, the diacritics are significant, which would cause “naïve” and “naive” to be interpreted as two different words. In other locales, they are the same word and should be counted together. In some character sets, accented characters can be composed from separate non-accented characters followed by the desired accent. For example, maybe you can write “naı¨ve”, which is the same as “naïve”.

I hope by now you are completely scared away from manipulating cases and characters. Far too many naïve programmers become entangled in this web or, worse, simply write bad code. I was tempted to wait until much later in the book before throwing all this at you, but I know that many readers will want to improve the word-counting program by ignoring case, so I decided to tackle the problem early. Well, now you know better. That doesn’t mean you can’t keep working on the word-counting program.

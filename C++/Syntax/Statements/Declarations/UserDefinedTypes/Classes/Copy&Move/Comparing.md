Comparing

I defined copying and assignment in a way that requires meaningful comparison. If you can’t determine whether two objects are equal, you can’t verify whether you copied or assigned them correctly.

C++ has a few ways to check whether two objects are the same:

Standard algorithms such as find compare items to test for equality by one of two methods:

• Overload the == operator
	The first and most obvious way is to compare objects with the == operator. Value types should overload this operator. Make sure the operator is transitive — that is, if a == b and b == c, then a == c. Make sure the operator is commutative, that is, if a == b, then b == a. Finally, the operator should be reflexive: a == a.

• caller-supplied == predicate:
	Sometimes, you may want to compare objects with a custom predicate, for example, a person class might have operator== that compares every data member (name, address, etc.), but you want to search a container of person objects by checking only last names, which you do by writing your own comparison function. The custom predicate must obey the same transitive and reflexive restrictions as the == operator. If you are using the predicate with a specific algorithm, that algorithm calls the predicate in a particular way, so you know the order of the arguments. You don’t have to make your predicate commutative, and in some cases, you wouldn’t want to.

Standard algorithms and containers such as map compare items to store their elements in sorted order by one of two methods:

• Overload the < operator
	Containers such as map store their elements in sorted order. Some standard algorithms, such as binary_search, require their input range to be in sorted order. The ordered containers and algorithms use the same conventions. These containers and algorithms never use the == operator to determine whether two objects are the same. Instead, they check for equivalence — that is, if a < b is false and b < a is false, then a is equivalent to b. If your value type can be ordered, you should overload the < operator. Ensure that the operator is transitive (if a < b and b < c, then a < c). Also, the ordering must be strict, that is, a < a is always false.  

• Caller-supplied < predicate:
	By default, containers and algorithms that check for equivalence use the < operator. You can also supply your own comparison predicate instead of the < operator. The custom predicate must obey the same transitive and strictness restrictions as the < operator. If you are using the predicate with a specific algorithm, that algorithm calls the predicate in a particular way, so you know the order of the arguments.


Not all types are comparable with a less-than relationship. If your type cannot be ordered, do not 	implement the < operator, but you must also understand that you will not be able to store objects of that type 	in a map or use any of the binary search algorithms. Sometimes, you may want to impose an artificial order, 	just to permit these uses. For example, a color type may represent colors such as red, green, or yellow.

Although nothing about red or green inherently defines one as being “less than” another, you may want to 	define an arbitrary order, just so you can use these values as keys in a map. One immediate suggestion is to 	write a comparison function that compares colors as integers, using the < operator. 	On the other hand, if you have a value that should be compared (such as rational), you should 	implement operator== and operator<. You can then implement all other comparison operators in terms of these two.



Implement a color class that describes a color as three components: red, green, and blue, which are integers in the range 0 to 255. Define a comparison function, order_color, to permit storing colors as map keys. For extra credit, devise a suitable I/O format and overload the I/O operators too. We don’t worry about error-handling yet — for example, what if the user tries to set red to 1000, blue to 2000, and green to 3000.

```cpp
#include <iomanip>
#include <iostream>
#include <sstream>

class color
{
public:
  color() : color{0, 0, 0} {}
  color(color const&) = default;
  color(int r, int g, int b) : red_{r}, green_{g}, blue_{b} {}
  int red() const { return red_; }
  int green() const { return green_; }
  int blue() const { return blue_; }
  /// Because red(), green(), and blue() are supposed to be in the range [0,255],
  /// it should be possible to add them together in a single long integer.
  /// TODO: handle out of range
  long int combined() const { return ((red() * 256L + green()) * 256) + blue(); }
private:
  int red_, green_, blue_;
};

inline bool operator==(color const& a, color const& b)
{
  return a.combined() == b.combined();
}

inline bool operator!=(color const& a, color const& b)
{
  return not (a == b);
}

inline bool order_color(color const& a, color const& b)
{
  return a.combined() < b.combined();
}

/// Write a color in HTML format: #RRGGBB.
std::ostream& operator<<(std::ostream& out, color const& c)
{
  std::ostringstream tmp{};
  // The hex manipulator tells a stream to write or read in hexadecimal (base 16).
  // Use a temporary stream in case the out stream has its own formatting,
  // such as width, adjustment.
  tmp << '#' << std::hex << std::setw(6) << std::setfill('0') << c.combined();
  out << tmp.str();
  return out;
}

class ioflags
{
public:
  /// Save the formatting flags from @p stream.
  ioflags(std::basic_ios<char>& stream) : stream_{stream}, flags_{stream.flags()} {}
  ioflags(ioflags const&) = delete;
  /// Restore the formatting flags.
  ~ioflags() { stream_.flags(flags_); }
private:
  std::basic_ios<char>& stream_;
  std::ios_base::fmtflags flags_;
};

std::istream& operator>>(std::istream& in, color& c)
{
  ioflags flags{in};

  char hash{};
  if (not (in >> hash))
    return in;
  if (hash != '#')
  {
    // malformed color: no leading # character
    in.unget();                 // return the character to the input stream
    in.setstate(in.failbit);    // set the failure state
    return in;
  }
  // Read the color number, which is hexadecimal: RRGGBB.
  int combined{};
  in >> std::hex >> std::noskipws;
  if (not (in >> combined))
    return in;
  // Extract the R, G, and B bytes.
  int red, green, blue;
  blue = combined % 256;
  combined = combined / 256;
  green = combined % 256;
  combined = combined / 256;
  red = combined % 256;

  // Assign to c only after successfully reading all the color components.
  c = color{red, green, blue};

  return in;
}

int main()
{
  color c;
  while (std::cin >> c)
  {
    if (c == color{})
      std::cout << "black\n";
    else
      std::cout << c << '\n';
  }
}
```

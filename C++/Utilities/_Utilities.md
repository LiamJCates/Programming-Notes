The stdlib and Boost libraries provide a throng of types, classes, and functions that satisfy common programming needs. Together, this motley collection of tools is called utilities. Aside from their small, uncomplicated, and focused nature, utilities vary functionally.

The specification of the standard library is over two thirds of the ISO C++ standard. Explore it,
and prefer it to home-made alternatives. Much thought has gone into its design, more still into its
implementations, and much effort will go into its maintenance and extension

Data Structures
Between them, the stdlib and Boost libraries provide a venerable collection
of useful data structures. A data structure is a type that stores objects and
permits some set of operations over those stored objects.

Covered are
tribool
optional



key standard-library facilities.

Useful standard-library types:
string
ostream
variant
vector
map
path
unique_ptr
thread
regex
complex




In addition to the standard-library components, most implementations offer ‘‘graphical user
interface’’ systems (GUIs), Web interfaces, database interfaces, etc. Similarly, most applicationdevelopment environments provide ‘‘foundation libraries’’ for corporate or industrial ‘‘standard’’
development and/or execution environments.









Standard-Library Components
The facilities provided by the standard library can be classified like this:
• Run-time language support (e.g., for allocation and run-time type information).

• The C standard library (with very minor modifications to minimize violations of the type system).

• Strings (with support for international character sets, localization, and read-only views of substrings)

• Support for regular expression matching.

• I/O streams is an extensible framework for input and output to which users can add their own types, streams, buffering strategies, locales, and character sets. There is also a library for manipulating file systems in a portable manner (§10.10).

• The STL, a framework of containers (such as vector and map) and algorithms (such as find(), sort(), and merge())

• Support for numerical computation (such as standard mathematical functions, complex numbers, vectors with arithmetic operations, and random number generators);

• Support for concurrent programming, including threads and locks;

• Parallel versions of most STL algorithms and some numerical algorithms (e.g., sort() and reduce());

• Utilities to support template metaprogramming (e.g., type traits), STL-style generic programming (e.g., pair), general programming (e.g., variant and optional and clock.

• Support for efficient and safe management of general resources, plus an interface to optional garbage collectors.

• ‘‘Smart pointers’’ for resource management (e.g., unique_ptr and shared_ptr).

• Special-purpose containers, such as array, bitset, and tuple.

• Suffixes for popular units, such as ms for milliseconds and i for imaginary.

The main criteria for including a class in the library were that:
• it could be helpful to almost every C++ programmer (both novices and experts)
• it could be provided in a general form that did not add significant overhead compared to a simpler version of the same facility
• simple uses should be easy to learn (relative to the inherent complexity of their task).

Essentially, the C++ standard library provides the most common fundamental data structures together with the fundamental algorithms used on them.




Standard-Library Headers and Namespace
Every standard-library facility is provided through some standard header. For example:
The standard library is defined in a namespace (§3.4) called std. To use standard-library facilities, the std:: prefix can be used.


Selected Standard Library Headers
| header | contains |
|--------|----------|
| <algorithm> | copy(), find(), sort() |
| <array> | array |
| <chrono> | duration, time_point |
| <cmath> | sqrt(), pow() |
| <complex> | complex, sqrt(), pow() |
| <filesystem> | path |
| <forward_list> | forward_list |
| <fstream> | fstream, ifstream, ofstream |
| <future> | future, promise |
| <ios> | hex, dec, scientific, fixed, defaultfloat |
| <iostream> | istream, ostream, cin, cout |
| <map> | map, multimap |
| <memory> | unique_ptr, shared_ptr, allocator |
| <random> | default_random_engine, normal_distribution |
| <regex> | regex, smatch |
| <string> | string, basic_string |
| <set> | set, multiset |
| <sstream> | istringstream, ostringstream |
| <stdexcept> | length_error, out_of_range, runtime_error |
| <thread> | thread |
| <unordered_map> | unordered_map, unordered_multimap |
| <utility> | move(), swap(), pair |
| <variant> | variant |
| <vector> | vector |

This listing is far from complete.

Headers from the C standard library, such as <stdlib.h> are provided. For each such header there is also a version with its name prefixed by c and the .h removed. This version, such as <cstdlib> places its declarations in the std namespace.

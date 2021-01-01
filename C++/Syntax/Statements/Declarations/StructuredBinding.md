Structured Bindings

TODO:
https://en.cppreference.com/w/cpp/language/structured_binding


Structured bindings enable you to unpack objects into their constituent elements. Any type whose non-static data members are public can be
unpacked this way—for example, the POD (plain-old-data class) types.

Syntax:
auto [object-1, object-2, ...] = plain-old-data;

This line will initialize an arbitrary number of objects (object-1, object-2, and so on) by peeling them off a POD object one by one. The objects peel off the POD from top to bottom, and they fill in the structured binding from left to right.

Consider a read_text_file function that takes a string argument corresponding to the file path. Such a function might fail, for example, if a file is locked or doesn’t exist.

You have two options for handling errors:
•	 You can throw an exception within read_text_file.
•	 You can return a success status code from the function.

Let’s explore the second option.

struct TextFile {
  bool success;
  const char* contents;
  size_t n_bytes;
};

Listing 8-10: A TextFile type that will be returned by the read_text_file function

First, a flag communicates to the caller whether the function call was a success. Next is the contents of the file and its size n_bytes.

The prototype of read_text_file looks like this:
TextFile read_text_file(const char* path);

You can use a structured binding declaration to unpack a TextFile into
its parts within your program:

#include <cstdio>
struct TextFile {
  bool success;
  const char* data;
  size_t n_bytes;
};

TextFile read_text_file(const char* path) {
const static char contents[]{ "Sometimes the goat is you." };
return TextFile{
true,
contents,
sizeof(contents)
};
}
int main() {
const auto [success, contents, length] = read_text_file("REAMDE.txt");
if (success) {
printf("Read %zd bytes: %s\n", length, contents{);
} else {
printf("Failed to open REAMDE.txt.");
}
}
Read 27 bytes: Sometimes the goat is you.
Listing 8-11: A program simulating the reading of a text file that returns a POD that you
use in a structured binding
You’ve declared the TextFile and then provided a dummy definition
for read_text_file. (It doesn’t actually read a file; more on that in Part II.)
Within main, you invoke read_text_file and use a structured binding
declaration to unpack the results into three distinct variables: success,
contents, and length. After structured binding, you can use all these
variables as though you had declared them individually.
N O T E The types within a structured binding declaration don’t have to match.









## Structured Binding
A function can return only a single value, but that value can be a class object with many members.
This allows us to efficiently return many values. For example:
struct Entry {
string name;
int value;
};Section 3.6.3 Structured Binding 45
Entr y read_entry(istream& is) // naive read function (for a better version, see §10.5)
{
string s;
int i;
is >> s >> i;
return {s,i};
}
auto e = read_entry(cin);
cout << "{ " << e.name << " , " << e.value << " }\n";
Here, {s,i} is used to construct the Entr y return value. Similarly, we can ‘‘unpack’’ an
Entr y’s members into local variables:
auto [n,v] = read_entry(is);
cout << "{ " << n << " , " << v << " }\n";
The auto [n,v] declares two local variables n and v with their types deduced from
read_entr y()’s return type. This mechanism for giving local names to members of a class
object is called structured binding.
Consider another example:
map<string,int> m;
// ... fill m ...
for (const auto [key,value] : m)
cout << "{" << key "," << value << "}\n";
As usual, we can decorate auto with const and &. For example:
void incr(map<string,int>& m) // increment the value of each element of m
{
for (auto& [key,value] : m)
++value;
}
When structured binding is used for a class with no private data, it is easy to see how the binding is
done: there must be the same number of names defined for the binding as there are nonstatic data
members of the class, and each name introduced in the binding names the corresponding member.
There will not be any difference in the object code quality compared to explicitly using a composite
object; the use of structured binding is all about how best to express an idea.
It is also possible to handle classes where access is through member functions. For example:
complex<double> z = {1,2};
auto [re,im] = z+2; // re=3; im=2
A complex has two data members, but its interface consists of access functions, such as real() and
imag(). Mapping a complex<double> to two local variables, such as re and im is feasible and efficient, but the technique for doing so is beyond the scope of this book.

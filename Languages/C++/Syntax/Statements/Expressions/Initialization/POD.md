### Initializing PODs

The notation for initializing a POD mostly follows fundamental types.

#include <cstdint>
struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
};
int main() {
  PodStruct initialized_pod1{}; // All fields zeroed
  PodStruct initialized_pod2 = {}; // All fields zeroed
  PodStruct initialized_pod3{ 42, "Hello" }; // Fields a & b set; c = 0
  PodStruct initialized_pod4{ 42, "Hello", true }; // All fields set
}

Initializing a POD object to zero is similar to initializing objects of fundamental types to zero. The braces and equals-plus-braces approaches produce the same code: fields initialize to zero.

NOTE
You cannot use the equals-zero approach with PODs. The following will not compile because it’s expressly forbidden in the language rules:

PodStruct initialized_pod = 0;


### Initializing PODs to Arbitrary Values

You can initialize fields to arbitrary values using braced initializers. The arguments within braced initializers must match types with POD members. The order of arguments from left to right matches the order of members from top to bottom. Any omitted members are zeroed. Members a and b initialize to 42 and Hello after the initialization of initialized_pod3, and c is zeroed (set to false) because you omitted it from the braced initialization.
The initialization of initialized_pod4 includes an argument for c (true), so its value is set to true after initialization.

The equals-plus-braces initialization works identically:
PodStruct initialized_pod4 = { 42, "Hello", true };

You can only omit fields from right to left, so the following won’t compile:
PodStruct initialized_pod4 = { 42, true };

You cannot use parentheses to initialize PODs. The following will not compile:
PodStruct initialized_pod(42, "Hello", true);

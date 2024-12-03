## Attributes
Attributes apply implementation-defined features to an expression statement.
You introduce attributes using double brackets [[ ]] containing a list of one
or more comma-separated attribute elements.

| Attribute | Meaning |
|-----------|---------|
| [[noreturn]] | Indicates that a function doesn’t return. |
| [[deprecated("reason")]] | Indicates that this expression is deprecated; that is, its use is discouraged. The "reason" is optional and indicates the reason for deprecation. |
| [[fallthrough]] | Indicates that a switch case intends to fall through to the next switch case. This avoids compiler errors that will check for switch case fallthrough, because it’s uncommon. |
| [[nodiscard]] | Indicates that the following function or type declaration should be used. If code using this element discards the value, the compiler should emit a warning. |
| [[maybe_unused]] | Indicates that the following element might be unused and that the compiler shouldn’t warn about it. |
| [[carries_dependency]] | Used within the <atomic> header to help the compiler optimize certain memory operations. You’re unlikely to encounter this directly.|

demonstrates using the [[noreturn]] attribute by defining a function that never returns.

  #include <cstdio>
  #include <stdexcept>

  [[noreturn]] void pitcher() {
    throw std::runtime_error{ "Knuckleball." };
  }

  int main() {
    try {
      pitcher();
    } catch(const std::exception& e) {
      printf("exception: %s\n", e.what());
    }
  }

Output:

  Exception: Knuckleball.

First, you declare the pitcher function with the [[noreturn]] attribute. Within this function, you throw an exception. Because you always throw an exception, pitcher never returns (hence the [[noreturn]] attribute).

Within main, you invoke pitcher and handle the caught exception. Of course, this listing works without the [[noreturn]] attribute. But giving this information to the compiler allows it to reason more completely on your
code (and potentially to optimize your program).

The situations in which you’ll need to use an attribute are rare, but they
convey useful information to the compiler nonetheless.

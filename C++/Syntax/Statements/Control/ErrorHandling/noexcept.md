The noexcept Keyword
The keyword noexcept is another exception-related term you should know.
You can, and should, mark any function that cannot possibly throw an
exception noexcept, as in the following:
bool is_odd(int x) noexcept {
return 1 == (x % 2);
}
Functions marked noexcept make a rigid contract. When you’re using
a function marked noexcept, you can rest assured that the function cannot throw an exception. In exchange, you must be extremely careful when
you mark your own function noexcept, since the compiler won’t check for
you. If your code throws an exception inside a function marked noexcept,The Object Life Cycle 105
it’s bad juju. The C++ runtime will call the function std::terminate, a function that by default will exit the program via abort. Your program cannot
recover:
void hari_kari() noexcept {
throw std::runtime_error{ "Goodbye, cruel world." };
}
Marking a function noexcept enables some code optimizations that rely
on the function’s not being able to throw an exception.

Check out Item 16 of Effective Modern C++ by Scott Meyers for a thorough discussion of noexcept. The gist is that some move constructors and move assignment operators might throw an exception, for example, if they need to allocate memory and the
system is out. Unless a move constructor or move assignment operator specifies otherwise, the compiler must assume that a move could cause an exception. This disables
certain optimizations.

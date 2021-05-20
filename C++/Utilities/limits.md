


<limits>
int min{std::numeric_limits<int>::max()};
int max{std::numeric_limits<int>::min()};


 The name std::numeric_limits is part of the C++ standard library and lets you query the attributes
 of the built-in arithmetic types. You can determine the number of bits a type requires, the number of
 decimal digits, the minimum and maximum values, and more. Put the type that you are curious about in
 angle brackets. (You’ll see this approach to using types quite often in C++.) Thus, you could also query
 std::numeric_limits<bool>::min() and get false as the result.

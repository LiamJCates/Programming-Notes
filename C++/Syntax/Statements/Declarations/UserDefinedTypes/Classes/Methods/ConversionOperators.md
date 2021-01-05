Conversion Operators

Date holiday (12, 25, 2016); // instantiate
cout << holiday; // error in absence of conversion operator

The code would result in the following compile failure:

  error: binary '<<' : no operator found which takes a right-hand operand of type 'Date' (or there is no acceptable conversion).

This error essentially indicates that cout doesn’t know how to interpret an instance of Date as class Date does not support the operators that convert its contents into a type that cout would accept. We know that cout can work well with a const char*:

std::cout << "Hello world"; // const char* works!

So, getting cout to work with an instance of type Date might be as simple as adding an operator that returns a const char* version:

operator const char*()
{
  // operator implementation that returns a char*
}

Note that such assignments cause implicit conversions, that is, the compiler has used the available conversion operator (in this case const char*) thereby permitting unintended assignments that get compiled without error. To avoid implicit conversions, use keyword explicit at the beginning of an operator declaration, as follows:

  explicit operator const char*()
  {
  // conversion code here
  }

Using explicit would force the programmer to assert his intention to convert using a cast:

  string strHoliday(static_cast<const char*>(Holiday));
  strHoliday=static_cast<const char*>(Date(11,11,2016));

Program as many operators as you think your class would be used with. If your application needs an integer representation of a Date, then you may program it as follows:

  explicit operator int()
  {
  return day + month + year;
  }

This would allow an instance of Date to be used or transacted as an integer:

  FuncTakesInt(static_cast<int>(Date(12, 25, 2016)));

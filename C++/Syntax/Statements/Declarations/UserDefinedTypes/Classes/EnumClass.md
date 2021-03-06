Enumeration Classes

in C++, it is possible to create real enum types that are neither implicitly convertible to int and that neither have enumerator values of type int, but of the enum type itself, thus preserving type safety. They are declared with enum class (or enum struct) instead of just enum:

  enum class RainbowColors {
    Violet,
    Indigo,
    Blue,
    Green,
    Yellow,
    Orange,
    Red
  };

To initialize an enumeration variable to a value, use the name of the type followed by two colons :: and the desired value as each of the enumerator values of an enum class type needs to be scoped into its type (this is actually also possible with enum types, but it is only optional).

RainbowColors color = RainbowColors::Red;

Technically, an enum class is one of two kinds of enumerations: it’s called a scoped enum.

For compatibility with C, C++ supports an unscoped enum, which is declared with the enum keyword.

The major difference is that scoped enums require the enum’s type followed by :: to precede the values, whereas unscoped enums don’t.

Unscoped enum classes are less safe to use than scoped enums, so shy away from them unless absolutely necessary. They’re supported in C++ for mainly historical reasons, especially interoperation with C code.


Enumerated types declared with enum class also have more control over their underlying type; it may be any integral data type, such as char, short or unsigned int, which essentially serves to determine the size of the type. This is specified by a colon and the underlying type following the enumerated type. For example:

  enum class EyeColor : char {blue, green, brown};

Here, Eyecolor is a distinct type with the same size of a char (1 byte).



## Supercharging enums with Classes

When you work with classes, you can use a technique called wrapping, which helps you manage a resource.

An instance where this is useful is printing an enumeration. Attempting to do this you don’t see the word, such as red or blue; you see a number. The wrapping example below essentially helps you convert the number into a human readable form, which is a kind of resource management.

You can use this class with enum ColorEnum, as main() demonstrates. When you run this application, you see the single word red in the console.

  #include <iostream>
  using namespace std;

  class Colors
  {
    public:
      enum ColorEnum {blue, red, green, yellow, black};
      Colors(Colors::ColorEnum value);
      string AsString();

    protected:
      ColorEnum value;
  };

  Colors::Colors(Colors::ColorEnum initvalue)
  {
    value = initvalue;
  }

  string Colors::AsString()
  {
    switch (value)
    {
      case blue:    return "blue";
      case red:     return "red";
      case green:   return "green";
      case yellow:  return "yellow";
      case black:   return "black";
      default:      return "Not Found";
    }
  }

  int main()
  {
    Colors InkColor = Colors::red;
    cout << InkColor.AsString() << endl;
  }



In main(), we created the InkColor instance and set it not to a Color object but to an enum. We just violated An Important Rule about setting things equal to something of the same type. Why? C++ has a neat little trick: You can create a constructor that takes a certain type. In this case, we have a constructor that takes a ColorEnum. Then when you create a stack variable (not a pointer), you can just set it equal to a value of that type. The computer will implicitly call the constructor, passing it that value.

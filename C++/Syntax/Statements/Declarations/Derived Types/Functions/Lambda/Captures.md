### Lambda Captures

Lambda captures inject objects into the lambda.

Unlike nested blocks, where any identifier defined in an outer block is accessible in the scope of the nested block, lambdas can only access specific kinds of identifiers: global identifiers, entities that are known at compile time, and entities with static storage duration. This is where the capture clause becomes useful.

The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that it normally would not have access to. All we need to do is list the entities we want to access from within the lambda as part of the capture clause.

Declare a lambda’s capture by specifying a capture list within brackets []. The capture list goes before the parameter list, and it can contain any number of comma-separated arguments. You then use these arguments within the lambda’s body.

When the compiler encounters a lambda definition, it creates a custom object definition for the lambda. Each captured variable becomes a data member of the object.

When a lambda definition is executed, the lambda object is instantiated and for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda. These cloned variables are initialized from the outer scope variables of the same name at this point.

By default, lambdas capture by value.

A lambda’s capture list is analogous to a function type’s constructor.

int main(){

  int x = 2, y = 3;

  auto add = [x, y](){return x + y;};

  cout << add() << endl;
}

Much like functions can change the value of arguments passed by reference, we can also capture variables by reference to allow our lambda to affect the value of the argument. To capture an element by reference rather than by value, prefix the captured object’s name with an ampersand &.Unlike variables that are captured by value, variables that are captured by reference are non-const, unless the variable they’re capturing is const. Capture by reference should be preferred over capture by value whenever you would normally prefer passing an argument to a function by reference (e.g. for non-fundamental types).

int main(){

  int x = 2, y = 3;

  cout << x << " " << y << endl;

  auto swap = [&x, &y](){
    int temp = x;
    x = y;
    y = temp;
  };

  swap();

  cout << x << " " << y << endl;
}


### Capture By Reference Example

Now, let’s use a reference capture to count how many comparisons std::sort makes when it sorts an array.

  #include <algorithm>
  #include <array>
  #include <iostream>
  #include <string>

  struct Car
  {
    std::string make{};
    std::string model{};
  };

  int main()
  {
    std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
                               { "Toyota", "Corolla" },
                               { "Honda", "Civic" } } };

    int comparisons{ 0 };
    auto compare = [&comparisons](const auto& a, const auto& b)
    {
      // We captured comparisons by reference.
      ++comparisons;

      // Sort the cars by their make.
      return (a.make < b.make);
    };

    std::sort(cars.begin(), cars.end(), compare);

    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto& car : cars)
      std::cout << car.make << ' ' << car.model << '\n';

    return 0;
  }

Output:

  Comparisons: 2
  Honda Civic
  Toyota Corolla
  Volkswagen Golf



### Default Capture
So far, you’ve had to capture each element by name. Sometimes this style of capturing is called named capture.

Having to explicitly list the variables you want to capture can be burdensome. Fortunately, we can enlist the compiler’s help to auto-generate a list of variables we need to capture from the outer scope.

You can capture all automatic variables used within a lambda using default capture. A default capture (also called a capture-default) captures all lambda variables that share a name with a variable in the outer scope.

To specify a default capture by value within a capture list, use a lone equal sign =.

int main(){

  int x = 2, y = 3;

  auto add = [=](){return x + y;};

  cout << add() << endl;
}

To specify a default capture by reference, use a lone ampersand &.

int main(){

  int x = 2, y = 3;

  cout << x << " " << y << endl;

  auto swap = [&](){
    int temp = x;
    x = y;
    y = temp;
  };

  swap();

  cout << x << " " << y << endl;
}




### mutable
By default, variables are captured by const value. This means when the lambda is created, the lambda captures a constant copy of the outer scope variable, which means that the lambda is not allowed to modify them.

You’re not allowed to modify variables captured by value unless you add the mutable keyword to the lambda expression. The mutable keyword allows you to modify value-captured variables. This includes calling non-const methods on that object:

  #include <cstdio>
  #include <cstdint>

  int main()
  {
    char to_count{'s'};
    size_t tally{};
    auto s_counter = [=](const char *str) mutable {
      size_t index{}, result{};
      while (str[index])
      {
        if (str[index] == to_count)
          result++;
        index++;
      }
      tally += result;
      return result;
    };
    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Tally: %zd\n", tally);
    printf("Sally: %zd\n", sally);
    printf("Tally: %zd\n", tally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
    printf("Tally: %zd\n", tally);
  }

Output:

  Tally: 0
  Sally: 7
  Tally: 0
  Sailor: 3
  Tally: 0


You declare a default capture by value , and you make the lambda s_counter mutable. Each of the three times you print tally, you get a zero value. Why?

Because tally gets copied by value (via the default capture), the version in the lambda is, in essence, an entirely different variable that just happens to have the same name. Modifications to the lambda’s copy of tally don’t affect the automatic tally variable of main. The tally in main() is initialized to zero and never gets modified.



### Mixing Capture Methods

It’s also possible to mix a default capture with a named capture. You could, for example, default capture by reference and copy to_count by value using the following formulation:

auto s_counter = [&,to_count](const char* str) {
--snip--
};

This specifies a default capture by reference and to_count capture by value.

Although performing a default capture might seem like an easy shortcut, refrain from using it. It’s far better to declare captures explicitly. If you catch yourself saying “I’ll just use a default capture because there are too many variables to list out,” you probably need to refactor your code.



### Initializer Expressions in Capture Lists

Sometimes you want to initialize a whole new variable within a capture list. Maybe renaming a captured variable would make a lambda expression’s intent clearer. Or perhaps you want to move an object into a lambda and therefore need to initialize a variable.

To use an initializer expression, just declare the new variable’s name followed by an equal sign and the value you want to initialize your variable with:

auto s_counter = [&tally,my_char=to_count](const char* str) {
  size_t index{}, result{};
  while (str[index]) {
    if (str[index] == my_char) result++;
    --snip--
};

The capture list contains a simple named capture where you have tally by reference. The lambda also captures to_count by value, but you’ve elected to use the variable name my_char instead. Of course, you’ll need to use the name my_char instead of to_count inside the lambda.

N O T E
An initializer expression in a capture list is also called an init capture.



### Capturing this

Sometimes lambda expressions have an enclosing class. You can capture an enclosing object (pointed-to by this) by value or by reference using either [*this] or [this], respectively.

  #include <cstdio>
  #include <cstdint>

  struct LambdaFactory
  {
    LambdaFactory(char in) : to_count{in}, tally{} {}
    auto make_lambda()
    {
      return [this](const char *str) {
        size_t index{}, result{};
        while (str[index])
        {
          if (str[index] == to_count)
            result++;
          index++;
        }
        tally += result;
        return result;
      };
    }
    const char to_count;
    size_t tally;
  };

  int main()
  {
    LambdaFactory factory{'s'};
    auto lambda = factory.make_lambda();
    printf("Tally: %zd\n", factory.tally);
    printf("Sally: %zd\n", lambda("Sally sells seashells by the seashore."));
    printf("Tally: %zd\n", factory.tally);
    printf("Sailor: %zd\n", lambda("Sailor went to sea to see what he could see."));
    printf("Tally: %zd\n", factory.tally);
  }

Tally: 0
Sally: 7
Tally: 7
Sailor: 3
Tally: 10

The LambdaFactory constructor takes a single character and initializes the to_count field with it. The make_lambda method illustrates how you can capture this by reference and use the to_count and tally member variables within the lambda expression.

Within main, you initialize a factory and make a lambda using the make_lambda method. The output is identical to Listing 9-19, because you capture this by reference and state of tally persists across invocations of lambda.



### Clarifying Examples
There are a lot of possibilities with capture lists, but once you have a command of the basics there aren’t many surprises.

Clarifying Examples of Lambda Capture Lists

| Capture list | Meaning |
|--------------|---------|
| [&] | Default capture by reference |
| [&,i] | Default capture by reference; capture i by value |
| [=] | Default capture by value |
| [=,&i] | Default capture by value; capture i by reference |
| [i] | Capture i by value |
| [&i] | Capture i by reference |
| [i,&j] | Capture i by value; capture j by reference |
| [i=j,&k] | Capture j by value as i; capture k by reference |
| [this] | Capture enclosing object by reference |
| [*this] | Capture enclosing object by value |
| [=,*this,i,&j] | Default capture by value; capture this and i by value; capture j by reference |





### Defining Variables In Captures

Sometimes we want to capture a variable with a slight modification or declare a new variable that is only visible in the scope of the lambda. We can do so by defining a variable in the lambda-capture without specifying its type.

  #include <array>
  #include <iostream>

  int main()
  {
    std::array areas{ 100, 25, 121, 40, 56 };

    int width{};
    int height{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    // We store areas, but the user entered width and height.
    // We need to calculate the area before we can search for it.
    // Declare a new variable that's visible only to the lambda.
    // The type of userArea is automatically deduced to int.
    auto compareArea = [userArea{ width * height }](int knownArea)
    {
      return (userArea == knownArea);
    };

    auto found{ std::find_if(areas.begin(), areas.end(), comapreArea) };

      std::cout << (found == areas.end() ?  "Area unknown" : "Area found" )
                << '\n';

    return 0;
  }

userArea will only be calculated once when the lambda is defined. The calculated area is stored in the lambda object and is the same for every call. If a lambda is mutable and modifies a variable that was defined in the capture, the original value will be overridden.

Best practice

Only initialize variables in the capture if their value is short and their type is obvious. Otherwise it’s best to define the variable outside of the lambda and capture it.




### Dangling Captured Variables

Variables are captured at the point where the lambda is defined. If a variable captured by reference dies before the lambda, the lambda will be left holding a dangling reference.

For example:

  #include <iostream>
  #include <string>

  // returns a lambda
  auto makeWalrus(const std::string& name)
  {
    // Capture name by reference and return the lambda.
    return [&]() {
      std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
    };
  }

  int main()
  {
    // Create a new walrus whose name is Roofus.
    // sayName is the lambda returned by makeWalrus.
    auto sayName{ makeWalrus("Roofus") };

    // Call the lambda function that makeWalrus returned.
    sayName();

    return 0;
  }

The call to makeWalrus creates a temporary std::string from the string literal “Roofus”. The lambda in makeWalrus captures the temporary string by reference. The temporary string dies when makeWalrus returns, but the lambda still references it. Then when we call sayName, the dangling reference is accessed, causing undefined behavior.

Note that this also happens if name is passed to makeWalrus by value. The variable name still dies at the end of makeWalrus, and the lambda is left holding a dangling reference.

Warning

Be extra careful when you capture variables by reference, especially with a default reference capture. The captured variables must outlive the lambda.

If we want the captured name to be valid when the lambda is used, we need to capture it by value instead (either explicitly or using a default-capture by value).



### Unintended copies of mutable lambdas

Because lambdas are objects, they can be copied. In some cases, this can cause problems. Consider the following code:

  #include <iostream>

  int main()
  {
    int i{ 0 };

    // Create a new lambda named count
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };

    count(); // invoke count

    auto otherCount{ count }; // create a copy of count

    // invoke both count and the copy
    count();
    otherCount();

    return 0;
  }

Output

  1
  2
  2

Rather than printing 1, 2, 3, the code prints 2 twice. When we created otherCount as a copy of count, we created a copy of count in its current state. count‘s i was 1, so otherCount‘s i is 1 as well. Since otherCount is a copy of count, they each have their own i.

Now let’s take a look at a slightly less obvious example:

  #include <iostream>
  #include <functional>

  void invoke(const std::function<void(void)>& fn)
  {
      fn();
  }

  int main()
  {
      int i{ 0 };

      // Increments and prints its local copy of @i.
      auto count{ [i]() mutable {
        std::cout << ++i << '\n';
      } };

      invoke(count);
      invoke(count);
      invoke(count);

      return 0;
  }

Output:

  1
  1
  1

This exhibits the same problem as the prior example in a more obscure form. When std::function is created with a lambda, the std::function internally makes a copy of the lambda object. Thus, our call to fn() is actually being executed on the copy of our lambda, not the actual lambda.

If we need to pass a mutable lambda, and want to avoid the possibility of inadvertent copies being made, there are two options. One option is to use a non-capturing lambda instead -- in the above case, we could remove the capture and track our state using a static local variable instead. But static local variables can be difficult to keep track of and make our code less readable. A better option is to prevent copies of our lambda from being made in the first place. But since we can’t affect how std::function (or other standard library functions or objects) are implemented, how can we do this?

Fortunately, C++ provides a convenient type (as part of the <functional> header) called std::reference_wrapper that allows us to pass a normal type as if it were a reference. For even more convenience, a std::reference_wrapper can be created by using the std::ref() function. By wrapping our lambda in a std::reference_wrapper, whenever anybody tries to make a copy of our lambda, they’ll make a copy of the reference instead, which will copy the reference rather than the actual object.

Here’s our updated code using std::ref:

  #include <iostream>
  #include <functional>

  void invoke(const std::function<void(void)> &fn)
  {
      fn();
  }

  int main()
  {
      int i{ 0 };

      // Increments and prints its local copy of @i.
      auto count{ [i]() mutable {
        std::cout << ++i << '\n';
      } };

      // std::ref(count) ensures count is treated like a reference
      // thus, anything that tries to copy count will actually copy the reference
      // ensuring that only one count exists
      invoke(std::ref(count));
      invoke(std::ref(count));
      invoke(std::ref(count));

      return 0;
  }

Our output is now as expected:

  1
  2
  3

Note that the output doesn’t change even if invoke takes fn by value. std::function doesn’t create a copy of the lambda if we create it with std::ref.

Rule

Standard library functions may copy function objects (reminder: lambdas are function objects). If you want to provide lambdas with mutable captured variables, pass them by reference using std::ref.

Best practice

Try to avoid lambdas with states altogether. Stateless lambdas are easier to understand and don’t suffer from the above issues, as well as more dangerous issues that arise when you add parallel execution.

Structured Bindings

Structured binding is one of the newest features of C++17 that binds the specified names to subobjects or elements of initializer. In simple words, Structured Bindings give us the ability to declare multiple variables initialized from a tuple or struct. The main purpose of Structured Bindings in C++ 17 is to make the code clean and easy to understand. Like a reference, a structured binding is an alias to an existing object. Unlike a reference, the type of a structured binding does not have to be a reference type.

Syntax :
  auto ref-operator(optional)[identifier-list] = expression;
  auto ref-operator(optional)[identifier-list]{expression};
  auto ref-operator(optional)[identifier-list](expression);

Parameters :
  auto : auto
  ref operator : either & or &&
  identifier-list : List of comma separated variable names.
  expression : An expression that does not have the comma operator at the top level (i.e, an assignment-expression), either array or non-union class type.



Let E denote the type of the initializer expression. E shall be either a specialization of std::tuple, or a type whose non-static data members are all accessible and are declared in the same base class of E.

A structured binding declaration performs the binding in one of three possible ways, depending on E.
  Case 1 : if E is an array type, the names are bound to the array elements.

  Case 2 : if E is a non-union class type and tuple_size is a complete type, then the “tuple-like” binding protocol is used.

  Case 3 : if E is a non-union class type but tuple_size is not a complete type, then the names are bound to the public data members of E.






Structured bindings enable you to unpack objects into their constituent elements. Any type whose non-static data members are public can be
unpacked this way—for example, the POD (plain-old-data class) types.

Syntax:
auto [object-1, object-2, ...] = plain-old-data;

This line will initialize an arbitrary number of objects (object-1, object-2, and so on) by peeling them off a POD object one by one. The objects peel off the POD from top to bottom, and they fill in the structured binding from left to right.


A function can return only a single value, but that value can be a class object with many members. Structured binding allows a function to return many values. Below is an example of the usage of this.

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

This program simulates the reading of a text file that returns a POD that you
use in a structured binding

You’ve declared the TextFile and then provided a dummy definition for read_text_file. (It doesn’t actually read a file)

Within main, you invoke read_text_file and use a structured binding declaration to unpack the results into three distinct variables: success, contents, and length. After structured binding, you can use all these variables as though you had declared them individually.



Let us see the advantage of Structure bindings over tuples with the help of an example :

Example 1 : In C++98

  #include <bits/stdc++.h>
  using namespace std;

  // Creating a structure named Point
  struct Point {
    int x;
    int y;
  };

  // Driver code
  int main()
  {
    Point p = {1, 2};

    int x_coord = p.x;
    int y_coord = p.y;

    cout << "X Coordinate : " << x_coord << endl;
    cout << "Y Coordinate : " << y_coord << endl;

    return 0;
  }

Output :

X Coordinate : 1
Y Coordinate : 2



Example 2 : In C++11/C++14

  #include <bits/stdc++.h>
  #include <tuple>
  using namespace std;

  // Creating a structure named Point
  struct Point
  {
    int x, y;

    // Default Constructor
    Point() : x(0), y(0) { }

    // Parameterized Constructor for Init List
    Point(int x, int y) : x(x), y(y) { }

    auto operator()()
    {
      // returns a tuple to make it work with std::tie
      return make_tuple(x, y);  
    }
  };

  // Driver code
  int main()
  {
    Point p = {1, 2};
    int x_coord, y_coord;
    tie(x_coord, y_coord) = p();

    cout << "X Coordinate : " << x_coord << endl;
    cout << "Y Coordinate : " << y_coord << endl;

    return 0;
  }

Output :

X Coordinate : 1
Y Coordinate : 2

Example 3 : In C++17

  #include <bits/stdc++.h>
  using namespace std;

  struct Point
  {
    int x;
    int y;
  };

  // Driver code
  int main( )
  {
    Point p = { 1,2 };

    // Structure binding
    auto[ x_coord, y_coord ] = p;

    cout << "X Coordinate : " << x_coord << endl;
    cout << "Y Coordinate : " << y_coord << endl;
  }

Output :

X Coordinate : 1
Y Coordinate : 2

Applications : Structured Binding can be used with arrays to get the elements from the array. In this case, E is an array type, hence the names are bound to the array elements. Below is the implementation to show the same :

  #include <bits/stdc++.h>
  using namespace std;

  int main()
  {
    int arr[3] = { 1, 2, 3 };

    // Here, E is an array type, hence the  
    // names are bound to the array elements.
    auto[x, y, z] = arr;

    cout << x << " " << y << " " << z << endl;
  }

Output :

1 2 3

Note : The number of identifiers in the identifier list must be equal to the number of elements in the array. If the number of identifiers in the identifier list is less, then either a compile time error or design time error may occur. This means that we cannot take the specific set of elements from the array.

A more practical example for using the structured bindings is as follows :

  #include <bits/stdc++.h>
  #include <map>
  using namespace std;

  int main()
  {
    // Creating a map with key and value  
    // fields as String
    map<string, string> sites;

    sites.insert({ "GeeksforGeeks", "Coding Resources" });
    sites.insert({ "StackOverflow", "Q-A type" });
    sites.insert({ "Wikipedia", "Resources + References" });

    for (auto & [ key, value ] : sites)  
    {
       cout << key.c_str() << " " << value.c_str() << endl;
    }

    return 0;
  }

Output :

GeeksforGeeks Coding Resources
StackOverflow Q-A type
Wikipedia Resources + References

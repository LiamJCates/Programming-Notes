Namespace is a very small but powerful feature of C++. This chapter
throws light on the unknown powers of namespace and its usage.



1. True or False

Namespaces in C++ would help the programmer to reduce ambiguity while calling functions.

Answer: True.
Using proper namespace identifier one would be able to appropriately call the functions. Reader can refer the subsequent question to get an idea of what the namespaces are meant for.



2. Predict the output of the following code snippet.
```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    void f1() { cout << "First namespace function" << "\n"; }
}

namespace b_name_space
{
    void f1() {cout << "second namespace function" << "\n";}
}

int main()
{
    a_name_space ::f1();
    b_name_space ::f1();
    return 0;
}
```



Answer:
```
First namespace function
Second namespace function
```
Since the scope of the function f1 is mapped properly to both
the functions, when used with appropriate namespace name, it would call
relevant functions without ambiguity.



3. Predict the output of the following code snippet.

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a + b;
        cout << c << " ";
    }
}

namespace b_name_space
{
    int f1(int a, int b)
    {
        int c = a - b;
        cout << c << " ";
    }
}

int main()
{
    a_name_space ::f1(2, 2);
    b_name_space ::f1(1, 1);
    return 0;
}
```

Answer:
```
4 0
```
Like passing parameters to the normal functions, here we have passed arguments to the functions, identified through appropriate namespaces.



4. True or False
The using directive will inform the compiler that the names used in the code is from the specified namespace.

Answer: True.
Using is a directive and it makes sure that compiler calls the correct code from appropriate namespace.



5. What is the output of the below code snippet?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a + b;
        cout << c << "\n";
    }
}

namespace b_name_space
{
    int f1(int a, int b)
    {
        int c = a - b;
        cout << c << "\n";
    }
}

int main()
{
    a_name_space::f1(2, 2);
}
```

Answer:
```
4
```
No harm in having a namespace without using the name. It may be used at a later point of time.



6. Identify the error in the following code snippet?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a + b;
        cout << c << " ";
    }
}

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a - b;
        cout << c << " ";
    }
}

int main()
{
    a_name_space ::f1(2, 2);
}
```

Answer:
```
Compilation error
```
Redefinition of ‘int a_name_space::f1(int, int)’ is illegal and not permitted.



7. What is the output of the following code snippet?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a + b;
        cout << c << " ";
    }
}

namespace b_name_space
{
    int f1(int a, int b)
    {
        int c = a - b;
        cout << c << " ";
    }
    int f1(float a, float b, float d)
    {
        float c = a + b + d;
        cout << c << "\n";
    }
}
int main()
{
    a_name_space ::f1(2, 2);
    b_name_space ::f1(5, 2);
    return 0;
}
```

Answer:
```
4 3
```
It is very much legal and the code has both namespace and function overloading concept used.



8. What is the output of the following code snippet?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int f1(int a, int b)
    {
        int c = a + b;
        cout << c << " ";
    }
}

namespace b_name_space
{
    int f1(int a, int b)
    {
        int c = a - b;
        cout << c << " ";
    }
    int f1(int a, int b, int d)
    {
        float c = a + b + d;
        cout << c << " ";
    }
}

int main()
{
    a_name_space ::f1(2, 2);
    b_name_space ::f1(5, 2);

    return 0;
}
```

Answer:
```
4 3
```
It is very much legal and the code has both namespace and function overloading concept used.



9. What is the output of the following piece of code?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int x = 4;
    int y = 5;
}

namespace b_name_space
{
    float x = 4.2222;
    float y = 5.2222;
}

int main()
{
    using a_name_space::x;
    using b_name_space::y;
    cout << x << ", " << y;
}
```

Answer:
```
4, 5.2222
```
The Using directive allows us to specify and access variables from which namespace one wishes to access.
 is used for this purpose.



10. Predict the output of the following code snippet.

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int x = 4;
    int y = 5;
}

namespace b_name_space
{
    float x = 4.2222;
    float y = 5.2222;
}

int main()
{
    a_name_space::x = 10;
    using a_name_space::x;
    cout << x << "\n";

    return 0;
}
```


Answer:
```
10
```
Using scope resolution operator, the variable x of namespace a_name_space is altered, hence the code will work fine.



11. What is the output of the following code?

```c++
#include <iostream>
using namespace std;

namespace a_name_space
{
    int x = 4;
    int y = 5;
}

namespace b_name_space
{
    float x = 4.2222;
    float y = 5.2222;
}

int main()
{
    a_name_space::x = 10;
    using a_name_space::x;
    cout << x << " ";
    b_name_space::y = 11.2222;
    using b_name_space::y;
    cout << y << " ";

    return 0;
}
```

Answer:
```
10 11.2222
```
Usage of namespace and scope resolution operators are proper in this code hence, it would work fine

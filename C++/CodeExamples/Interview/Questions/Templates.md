1. Templates were brought to implement which of the following concept?

(a) Overloading
(b) Polymorphism
(c) Inheritance
(d) Generic programming.

Answer: (d)



2. Which among the following data types are supported in the given template  

template <typename T>
void add(T a, T b){ }

(a) Int
(b) String
(c) Float
(d) All the above



Answer: (d)



3. Can a function template be overloaded?
(a) Yes
(b) No
(c) Possible by template argument list
(d) None of the above
Answer: (c)


4. Can operator be overloaded in Class template?
(a) Yes
(b) No
Answer: (a)
5. Is it possible to write a template in a separate cpp file?
(a) Yes
(b) No
Answer: (b)
6. Class Template names area and -> rectangle and square are classes
created using the template. Can object be created for rectangle?
(a) Yes
(b) No
(c) Possible because it’s a class not a template
Answer: (c)
7. Class Template names area and -> rectangle and square are classes
created using the template. Can object be created for area?
(a) Yes
(b) No
(c) Not possible because it’s not a class it is a template
Answer: (c)
8. Predict the output of the following code snippet.
# include <iostream>
# include <vector>
using namespace std;
int main ()
{
vector<int> a;
int i;
a.push_back(5);a.push_back(3);
a.push_back(1);
for (i=0;i<3;i++)
cout << a[i] << “ ”;
return 0;
}
(a) Compilation fault
(b) 5 3 1
(c) 1 3 5
(d) No output
Answer: (b) vector <> a; is the syntax through which templates can be
handled. <> is the symbol to be used with template code.
9. Predict the output of the following piece of code.
# include <iostream>
# include <vector>
using namespace std;
int main ()
{
int i;
vector<int> f (3,2);
vector<int> d (2,3);
f.swap(d);
for (i=0;i<f.size();i++)
cout << f[i] << “\t”;
cout <<”\n”;
for (i=0;i<d.size();i++)
cout << d[i] << “\t”;
cout <<”\n”;
return 0;
}
(a) 3 3
(b) 2 2
2 2 2 3 3 3(c) Compilation fault
(d) None of the above
Answer: (a) Using swap and templates, the contents of the two vectors are
swapped hence, the result would be ‘a’.
10. What is the output of the following code snippet?
# include <iostream>
# include <vector>
using namespace std;
int main ()
{
int i;
vector<int> f (3,’b’);
vector<int> d (2,’a’);
f.swap(d);
for (i=0;i<f.size();i++)
cout << f[i] << “\t”;
cout <<”\n”;
for (i=0;i<d.size();i++)
cout << d[i] << “\t”;
cout <<”\n”;
return 0;
}(a
) a a
(b) b b
b b b a a a
(c) 97 97
(d) Compilation error
98 98 98
Answer: (c) Since the vector<int> is the way the code has been written, it
would print the ascii value of a and b.
11. What is the output of the below code snippet?
# include <iostream># include <vector>
using namespace std;
int main ()
{
int i;
vector<char> f (3,’b’);
vector<char> d (2,’a’);
f.swap(d);
for (i=0;i<f.size();i++)
cout << f[i] << “\t”;
cout <<”\n”;
for (i=0;i<d.size();i++)
cout << d[i] << “\t”;
cout <<”\n”;
return 0;
}
(a) a a
(b) b b
b b b a a a
(c) 97 97
(d) Compilation error
98 98 98
Answer: (a) is the correct answer. Since the data type is correctly
associated with the vector, we have correct answer at this attempt.
12. Predict the output of the following code snippet?
# include <iostream>
# include <queue>
using namespace std;
int main()
{
queue <int> q;
int i;
for (i=1; i<=5; i++)q.push(i);
while (!q.empty())
{c
out <<q.front() <<” “;
q.pop();
}c
out <<”\n”;
return 0;
}
(a) Compilation error
(b) 1 2 3 4 5
(c) 5 4 3 2 1
(d) None of the above
Answer: (b) This code depicts the simplest way of constructing queues.
13. Predict the output of the following code snippet?
# include <iostream>
using namespace std;
int main()
{
queue <int> q;
int i;
for (i=1; i<=5; i++)
q.push(i);
while (!q.empty())
{c
out <<q.front() <<” “;
q.pop();
}
cout <<”\n”;
return 0;
}
(a) Compilation error
(b) 1 2 3 4 5(c) 5 4 3 2 1
(d) None of the above
Answer: (a) Without having the appropriate header file include <queue>
the code will not be recognized properly by the compiler

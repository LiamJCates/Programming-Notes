## Function Template Definition
C++ has the ability to define functions with generic types, known as function templates. Defining a function template follows the same syntax as a regular function, except that it is preceded by the template keyword and a series of template parameters enclosed in angle-brackets <>:

template <class T>
ret-type func-name(parameter list) {
   //function body
}

Here, T is a placeholder name for a data type used by the function. This name can be used within the function definition to specify the type of parameters to the function and the return type of the function and to declare variables within the function.

You can define more than one generic data type by using a comma-separated list:

template<typename X, typename Y, typename Z>
X my_template_function(Y& arg1, const Z* arg2) {
  --snip--
}

Within the body of my_template_function, you can use arg1 and arg2 however you’d like, as long as you return an object of type X.



There are three ways of expressing an operation parameterized by types or values:
• A function template
• A function object: an object that can carry data and be called like a function
• A lambda expression: a shorthand notation for a function object



Template functions do have a few drawbacks, and we would be remiss not to mention them. First, some older compilers do not have very good template support. However, this downside is no longer as much of a problem as it used to be. Second, template functions often produce crazy-looking error messages that are much harder to decipher than those of regular functions (we’ll see an example of this in the next lesson). Third, template functions can increase your compile time and code size, as a single template might be “realized” and recompiled in many files (there are ways to work around this one).

However, these drawbacks are fairly minor compared with the power and flexibility templates bring to your programming toolkit!


## Examples


### Function Templates


template <class T>
T max(T const& t1, T const& t2)
{
  return t1 < t2? t2: t1;
}

You can see the first line says template, angle brackets, class T, close angle brackets. And that is the indicator that this is a templated function. Then the T that you see everywhere else in the function signature is that placeholder type. It's just a convention to use a capital letter T, but it's a very popular one.

So what this code declares is that the function is called max and it returns some type T, whatever this is the templated of, it takes a T by constant reference called t1 and another T by constant reference called t2.

Because you might be using this template to compare two integers, you might think, oh, I'll just take them by value, but you could also be using this template to compare two purchase orders that might be large and expensive to copy, so it makes sense to take them by reference. Since it doesn't change the parameters that it's passed, it's a good idea to take by const reference. And if you don't take by const reference, you wouldn't be able to pass a literal, like 0, as one of the parameters. So, T const ref is the right signature here.

The body is using the immediate if operator, the ternary operator. It checks to see if t1 is less than t2. If it is, and t2 is the larger one, and we'll return t2, and then after the colon comes what we return if the condition was false, we'll return t1. The way this one's coded, if you pass two things the same, it will always return the first one as the answer.

In C++, it's very common for templates to rely on operator overloads. When you use operator overloads, you can implement operator<(const T &t1, const T &t2) and all the other operators for your classes, then the template can use the operator overload, and it'll work for fundamentals types, as well as for the classes that you write. 

For more information on overloading operators, see:
[C++\Syntax\Overloading\Operators]




We can write a function that calculates the sum of the element values of any sequence that a range for can traverse (e.g., a container) like this:

template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{
  for (auto x : s)
    v+=x;
  return v;
}

The Value template argument and the function argument v are there to allow the caller to specify the type and initial value of the accumulator (the variable in which to accumulate the sum):

void user(Vector<int>& vi, list<double>& ld, vector<complex<double>>& vc)
{
  int x = sum(vi,0); // the sum of a vector of ints (add ints)
  double d = sum(vi,0.0); // the sum of a vector of ints (add doubles)
  double dd = sum(ld,0.0); // the sum of a list of doubles
  auto z = sum(vc,complex{0.0,0.0}); // the sum of a vector of complex<double>
}

The point of adding ints in a double would be to gracefully handle a number larger than the largest int. Note how the types of the template arguments for sum<Sequence ,Value> are deduced from the function arguments. Fortunately, we do not need to explicitly specify those types.

This sum() is a simplified version of the standard-library accumulate(). A function template can be a member function, but not a virtual member. The compiler would not know all instantiations of such a template in a program, so it could not generate a vtbl.



### Function Objects
One particularly useful kind of template is the function object (sometimes called a functor), which is used to define objects that can be called like functions:

template<typename T>
class Less_than {
  const T val; // value to compare against
  public:
  Less_than(const T& v) :val{v} { }
  bool operator()(const T& x) const { return x<val; } // call operator
};

The function called operator() implements the ‘‘function call,’’ ‘‘call,’’ or ‘‘application’’ operator ().

We can define named variables of type Less_than for some argument type:

Less_than lti {42};
// lti(i) will compare i to 42 using < (i<42)

Less_than lts {"Backus"s};
// lts(s) will compare s to "Backus" using < (s<"Backus")

Less_than<string> lts2 {"Naur"};
// "Naur" is a C-style string, so we need <string> to get the right <

We can call such an object, just as we call a function:

void fct(int n, const string& s)
{
  bool b1 = lti(n); // tr ue if n<42
  bool b2 = lts(s); // tr ue if s<"Backus"
  // ...
}

Such function objects are widely used as arguments to algorithms. For example, we can count the occurrences of values for which a predicate returns true:

template<typename C, typename P>
// requires Sequence<C> && Callable<P,Value_type<P>>
int count(const C& c, P pred)
{
  int cnt = 0;
  for (const auto& x : c)
    if (pred(x))
      ++cnt;
  return cnt;
}

A predicate is something that we can invoke to return true or false. For example:

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
  cout << "number of values less than " << x << ": " << count(vec,Less_than{x}) << '\n';
  cout << "number of values less than " << s << ": " << count(lst,Less_than{s}) << '\n';
}

Here, Less_than{x} constructs an object of type Less_than<int>, for which the call operator compares to the int called x; Less_than{s} constructs an object that compares to the string called s. The beauty of these function objects is that they carry the value to be compared against with them. We don’t have to write a separate function for each value (and each type), and we don’t have to introduce nasty global variables to hold values. Also, for a simple function object like Less_than, inlining is simple, so a call of Less_than is far more efficient than an indirect function call. The ability to carry data plus their efficiency makes function objects particularly useful as arguments to algorithms.

Function objects used to specify the meaning of key operations of a general algorithm (such as Less_than for count()) are often referred to as policy objects.







## Lambda Expressions
There is a notation for implicitly generating function objects:

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
  cout << "number of values less than " << x
  << ": " << count(vec,[&](int a){ return a<x; })
  << '\n';Section 6.3.3 Lambda Expressions 87
  cout << "number of values less than " << s
  << ": " << count(lst,[&](const string& a){ return a<s; })
  << '\n';
}

The notation [&](int a){ return a<x; } is called a lambda expression.

It generates a function object exactly like Less_than<int>{x}. The [&] is a capture list specifying that all local names used in the lambda body (such as x) will be accessed through references. Had we wanted to ‘‘capture’’ only x, we could have said so: [&x]. Had we wanted to give the generated object a copy of x, we could have said so: [=x]. Capture nothing is [ ], capture all local names used by reference is [&], and capture all local names used by value is [=].

Using lambdas can be convenient and terse, but also obscure. For nontrivial actions (say, more than a simple expression), I prefer to name the operation so as to more clearly state its purpose and to make it available for use in several places in a program.

In §4.5.3, we noted the annoyance of having to write many functions to perform operations on elements of vectors of pointers and unique_ptrs, such as draw_all() and rotate_all(). Function objects (in particular, lambdas) can help by allowing us to separate the traversal of the container from the specification of what is to be done with each element.

First, we need a function that applies an operation to each object pointed to by the elements of a container of pointers:

template<typename C, typename Oper>
void for_all(C& c, Oper op) // assume that C is a container of pointers
// requires Sequence<C> && Callable<Oper,Value_type<C>>
{
  for (auto& x : c)
  op(x); // pass op() a reference to each element pointed to
}

Now, we can write a version of user() from §4.5 without writing a set of _all functions:

void user2()
{
  vector<unique_ptr<Shape>> v;
  while (cin)
  v.push_back(read_shape(cin));
  for_all(v,[](unique_ptr<Shape>& ps){ ps−>draw(); }); // draw_all()
  for_all(v,[](unique_ptr<Shape>& ps){ ps−>rotate(45); }); // rotate_all(45)
}

I pass a unique_ptr<Shape>& to a lambda so that for_all() doesn’t have to care exactly how the objects are stored. In particular, those for_all() calls do not affect the lifetime of the Shapes passed and the bodies of the lambdas use the argument just as if they had been a plain-old pointers.
Like a function, a lambda can be generic. For example:

template<class S>
void rotate_and_draw(vector<S>& v, int r)
{
  for_all(v,[](auto& s){ s−>rotate(r); s−>draw(); });
}

Here, like in variable declarations, auto means that any type is accepted as an initializer (an argument is considered to initialize the formal parameter in a call). This makes a lambda with an auto parameter a template, a generic lambda. For reasons lost in standards committee politics, this use of auto is not currently allowed for function arguments.

We can call this generic rotate_and_draw() with any container of objects that you can draw() and rotate():

void user4()
{
  vector<unique_ptr<Shape>> v1;
  vector<Shape∗> v2;
  // ...
  rotate_and_draw(v1,45);
  rotate_and_draw(v2,90);
}

Using a lambda, we can turn any statement into an expression. This is mostly used to provide an operation to compute a value as an argument value, but the ability is general. Consider a complicated initialization:

enum class Init_mode { zero, seq, cpy, patrn }; // initializer alternatives

// messy code:
// int n, Init_mode m, vector<int>& arg, and iterators p and q are defined somewhere

vector<int> v;
switch (m) {
  case zero:
    v = vector<int>(n); // n elements initialized to 0
    break;
  case cpy:
    v = arg;
    break;
};

// ...
if (m == seq)
  v.assign(p,q); // copy from sequence [p:q)
// ...

This is a stylized example, but unfortunately not atypical. We need to select among a set of alternatives for initializing a data structure (here v) and we need to do different computations for different
alternatives. Such code is often messy, deemed essential ‘‘for efficiency,’’ and a source of bugs:
• The variable could be used before it gets its intended value.
• The ‘‘initialization code’’ could be mixed with other code, making it hard to comprehend.Section 6.3.3 Lambda Expressions 89
• When ‘‘initialization code’’ is mixed with other code it is easier to forget a case.
• This isn’t initialization, it’s assignment.
Instead, we could convert it to a lambda used as an initializer:
// int n, Init_mode m, vector<int>& arg, and iterators p and q are defined somewhere
vector<int> v = [&] {
  switch (m) {
    case zero:
      return vector<int>(n); // n elements initialized to 0
    case seq:
      return vector<int>{p,q}; // copy from sequence [p:q)
    case cpy:
      return arg;
}
}();
// ...
I still ‘‘forgot’’ a case, but now that’s easily spotted.

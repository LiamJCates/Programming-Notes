Move Construction
Move constructors look like copy constructors except they take rvalue references instead of lvalue references.

Consider the SimpleString move constructor in Listing 4-35.
SimpleString(SimpleString&& other) noexcept
: max_size{ other.max_size },
  buffer(other.buffer),
  length(other.length) {
  other.length = 0;
  other.buffer = nullptr;
  other.max_size = 0;
}
Listing 4-35: A move constructor for SimpleString

Because other is an rvalue reference, you’re allowed to cannibalize
it. In the case of SimpleString, this is easy: just copy all fields of other into this and then zero out the fields of other. The latter step is important:
it puts other in a moved-from state. (Consider what would happen upon the
destruction of other had you not cleared its members.)
Executing this move constructor is a lot less expensive than executing
the copy constructor.
The move constructor is designed to not throw an exception, so you
mark it noexcept. Your preference should be to use noexcept move constructors; often, the compiler cannot use exception-throwing move constructors
and will use copy constructors instead. Compilers prefer slow, correct code
instead of fast, incorrect code.



Move Constructors Help Improve Performance
There are cases where objects are subjected to copy steps automatically, due to the nature
of the language and its needs. Consider the following:
class MyString
{
// pick implementation from Listing 9.9
};
MyString Copy(MyString& source) // function
{
MyString copyForReturn(source.GetString()); // create copy
return copyForReturn; // return by value invokes copy constructor
}int main()
{
MyString sayHello ("Hello World of C++");
MyString sayHelloAgain(Copy(sayHello)); // invokes 2x copy constructor
return 0;
}
As the comment indicates, in the instantiation of sayHelloAgain, the copy constructor
was invoked twice, thus a deep copy was performed twice because of our call to function
Copy(sayHello) that returns a MyString by value. However, this value returned is very
temporary and is not available outside this expression. So, the copy constructor invoked
in good faith by the C++ compiler is a burden on performance. This impact becomes significant if our class were to contain objects of great size.
To avoid this performance bottleneck, versions of C++ starting with C++11 feature a
move constructor in addition to a copy constructor. The syntax of a move constructor is
// move constructor
MyString(MyString&& moveSource)
{
if(moveSource.buffer != NULL)
{
buffer = moveSource.buffer; // take ownership i.e. 'move'
moveSource.buffer = NULL; // set the move source to NULL
}
}
When a move constructor is programmed, the compiler automatically opts for the same
for “moving” the temporary resource and hence avoiding a deep-copy step. With the
move constructor implemented, the comment should be appropriately changed to the following:
MyString sayHelloAgain(Copy(sayHello)); // invokes 1x copy, 1x move constructors

You would ensure that your class cannot be copied by declaring a private copy constructor. This ensures that the function call DoSomething(ourPresident) will cause a
compile failure.

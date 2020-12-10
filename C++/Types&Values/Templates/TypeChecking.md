## Type Checking
Templates are type safe. During template instantiation, the compiler pastes
in the template parameters. If the resulting code is incorrect, the compiler
will not generate the instantiation.

Consider this template function which squares an element and returns the result.
template<typename T>
T square(T value)
{
  return value * value;
}

The T has a silent requirement: it must support multiplication.
If you try to use square with, say, a char*, the compilation will fail:

template<typename T>
T square(T value)
{
  return value * value;
}
int main()
{
  char my_char{ 'Q' };
  auto result = square(&my_char); //Bang!
}
Pointers don’t support multiplication, so template initialization fails

Error messages emitted by template initialization failures are notoriously cryptic.

Although template instantiation ensures type safety, the checking happens very late in the compilation process. When the compiler instantiates a template, it pastes the template parameter types into the template. After type insertion, the compiler attempts to compile the result. If instantiation fails, the compiler emits the dying words inside the template instantiation.

C++ template programming shares similarities with duck-typed languages.

Duck-typed languages (like Python) defer type checking until runtime.

The underlying philosophy is that if an object looks like a duck and quacks like a duck, then it must be type duck. Unfortunately, this means you can’t generally know whether an object supports a particular operation until you execute the program.

With templates, you cannot know whether an instantiation will succeed until you try to compile it. Although duck-typed languages might blow up at runtime, templates might blow up at compile time.

This situation is widely regarded as unacceptable by right-thinking people
in the C++ community, the solution called is concepts.

/*
A General-Purpose and Fast Data Storage Container Builder

In this exercise, we will write a function that takes any number of elements of any type, which can, in turn, be converted into a common type. The function should also return a container having all the elements converted into that common type, and it should also be fast to traverse:
*/
// 1. Let's begin by including the required libraries:
#include <iostream>
#include <array>
#include <type_traits>

/*
2. First, we'll try to build the signature of the function. Since the return type is a container that is fast to traverse, we'll go ahead with std::array. To allow any number of parameters, we'll use variadic templates:
*/
template<typename ... Args>
std::array<?,?> build_array(Args&&... args)

/*
Considering the requirement that the container should be fast to traverse for the return type, we can choose an array or a vector. Since the number of elements is known at the compile time based on the number of parameters to the function, we can go ahead with std::array.
*/

/*
3. Now, we must provide the type of the elements and the number of elements for std::array. We can use the std::common_type template to find out what the type
of elements inside std::array will be. Since this is dependent on arguments, we'll provide the return type of the function as a trailing type:
*/
template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_
type<Args...>::type, ?>
{
  using commonType = typename std::common_type<Args...>::type;
  // Create array
}
/*
4. As shown in the preceding code, we now need to figure out two things – the
number of elements, and how to create the array with commonType:
*/
template< typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_
type<Args...>::type, sizeof...(args)>
{
  using commonType = typename std::common_type<Args...>::type;
  return {std::forward<commonType>(args)...};
}
//5. Now, let's write the main function to see how our function works:
int main()
{
  auto data = build_array(1, 0u, 'a', 3.2f, false);
  for(auto i: data)
  std::cout << i << " ";
  std::cout << std::endl;
}
/*
6. Running the code should give the following output:
1 0 97 3.2 0

As we can see, all final output is in the form of float, since everything can be
converted to float.

*/
/*
7. To test this further, we can add the following inside the main function and test the output:

auto data2 = build_array(1, "Packt", 2.0);

With this modification, we should get an error saying that all the types can't
be converted to a common type. The exact error message should mention that
template deduction has failed. This is because there is no single type in which we can convert both the string and number.
Builder functions, such as the one we have created in this exercise, can be used when you are not sure about the type of data, yet you need to optimize efficiency.

There are a lot of useful features and utility functions that std::array doesn't provide. One major reason for this is to maintain similar or better performance and memory requirements compared to C-style arrays
*/

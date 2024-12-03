/*
Implementing a Dynamic Sized Array

Write an array-like container to manage the data, which can also support dynamic sizing. We'll also implement some utility functions to merge different classes.

Most of the functions mentioned here have a similar implementation to that of
std::array

Perform the following steps to complete the exercise:
*/

//1. First, include the required headers:
#include <iostream>
#include <sstream>
#include <algorithm>

//2. A basic templated structure called dynamic_array and primary data members:

template <typename T>
class dynamic_array
{
  T* data;
  size_t n;

  //3. A constructor that takes the size of the array and copies it:
public:
  dynamic_array(int n)
  {
    this->n = n;
    data = new T[n];
  }
  dynamic_array(const dynamic_array<T>& other)
  {
    n = other.n;
    data = new T[n];
    for(int i = 0; i < n; i++)
    data[i] = other[i];
  }
  //4. operator[] and function() in the public accessor to support the access of data directly, similar to std::array:
  T& operator[](int index)
  {
    return data[index];
  }
  const T& operator[](int index) const
  {
    return data[index];
  }
  T& at(int index)
  {
    if(index < n)
    return data[index];
    throw "Index out of range";
  }

  //5. A function size() to return the size of the array
  size_t size() const
  {
    return n;
  }

  //6. A destructor to avoid memory leaks:
  ~dynamic_array()
  {
    delete[] data;
  }

  //7. iterator functions to support range-based loops to iterate over dynamic_array:
  T* begin()
  {
    return data;
  }
  const T* begin() const
  {
    return data;
  }
  T* end()
  {
    return data + n;
  }
  const T* end() const
  {
    return data + n;
  }

  //8. A function to append one array to another using + operator a friend function for better usability:
  friend dynamic_array<T>
  operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
  {
    dynamic_array<T> result(arr1.size() + arr2.size());
    std::copy(arr1.begin(), arr1.end(), result.begin());
    std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
    return result;
  }
  //9. A to_string function that takes a separator parameter with default ",":
  std::string to_string(const std::string& sep = ", ")
  {
    if(n == 0)
    return "";
    std::ostringstream os;
    os << data[0];
    for(int i = 1; i < n; i++)
    os << sep << data[i];
    return os.str();
  }
}

//Test Code
//10. A struct for students name and grade for simplicity
struct student
{
  std::string name;
  int standard;
};
//operator<< to print it properly:
std::ostream& operator<<(std::ostream& os, const student& s)
{
  return (os << "[Name: " << s.name << ", Grade: " << s.grade << "]");
}


//11. main function
int main()
{
  int nStudents;
  std::cout << "Enter number of students in class 1: ";
  std::cin >> nStudents;
  dynamic_array<student> class1(nStudents);
  for(int i = 0; i < nStudents; i++)
  {
    std::cout << "Enter name and class of student " << i + 1 << ": ";
    std::string name;
    int standard;
    std::cin >> name >> standard;
    class1[i] = student{name, standard};
  }
  std::cout << std::endl;

  // Now, let's try to access the student out of range in the array
  try
  {
    class1[nStudents] = student{"Xun", 8}; // No exception, undefined behavior
    std::cout << "class1 student set out of range without exception" <<
    std::endl;
    class1.at(nStudents) = student{"Xun", 8}; // Will throw exception
  }
  catch(...)
  {
    std::cout << "Exception caught" << std::endl;
  }
  std::cout << std::endl;

  // Deep copy
  auto class2 = class1;
  std::cout << "Second class after initialized using first array: " <<
  class2.to_string() << std::endl;
  std::cout << std::endl;

  // Combines both classes and creates a bigger one
  auto class3 = class1 + class2;
  std::cout << "Combined class: ";
  std::cout << class3.to_string() << std::endl;
  return 0;
}

/*12. Execute the preceding code with three students – Raj(8), Rahul(10), and Paul(6) as input. The output looks like the following in the console:

Enter number of students in class 1 : 3
Enter name and class of student 1: Raj 8
Enter name and class of student 2: Rahul 10
Enter name and class of student 3: Paul 6

class1 student set out of range without exception
Exception caught

Second class after initialized using first array : [Name: Raj, Grade:
8], [Name: Rahul, Grade: 10], [Name: Paul, Grade: 6]

Combined class : [Name: Raj, Grade: 8], [Name: Rahul, Grade: 10],
[Name: Paul, Grade: 6], [Name: Raj, Grade: 8], [Name: Rahul,
Grade: 10], [Name: Paul, Grade: 6]
*/

## Parameter passing, Call by value

Arguments can be passed from one method to other using parameters. By default all, the variables, which are passed as parameters, are passed-by-value. That means a separate copy is created inside the called method and no changes done inside called method will reflect in calling method.

void incrementPassByValue(int var)
{
var++;
}
int main()
{
int i = 10;
std::cout << "Value of i before increment is : " << i << std::endl;
incrementPassByValue(i);
std::cout << "Value of i after increment is : " << i << std::endl;
}

Output:
Value of i before increment is : 10
Value of i after increment is : 10

Analysis:
· Variable ”i” is declared and the value 10 is initialized to it.
· Value of ”i” is printed.
· Increment method is called. When a method is called the value of the
parameter is copied into another variable of the called method. Flow of
control goes to increase() function.
· Value of var is incremented by 1. However, remember, it is just a copy
inside the increment method.
· When the method exits, the value of ”i” is still 10.
Points to remember:
1. Pass by value just creates a copy of variable.
2. Pass by value, value before and after the method call remain same.





## Parameter passing, Call by Reference
If you need to change the value of the parameter inside the method, then you should use call by reference. C++ language by default passes by value.
Therefore, to make it happen, you need to pass by reference by using “&” operator. The variable inside the called function also refer to the same variable inside the calling function. When the value of reference variable is changed then the original variable value also change.

void incrementPassByReference(int& var)
{
var++;
}

int main()
{
  int i = 10;
  std::cout << "Value of i before increment is : " << i << std::endl;
  incrementPassByReference(i);
  std::cout << "Value of i after increment is : " << i << std::endl;
}

Output:
Value of i before increment is : 10
Value of i after increment is : 11

Analysis: Variable “i” is passed as pass by reference, so variable “i” inside calling function and variable “var” inside called function are the same. So value of var changed inside called function will also be reflected into the variable “i” inside calling function.





## Parameter passing, Call by Pointer
When we pass address of variable inside calling function to the called function then the changes done inside called function is also reflected inside calling function.

void incrementPassByPointer(int* ptr)
{
(*ptr)++;
}

int main()
{
  int i = 10;
  std::cout << "Value of i before increment is : " << i << std::endl;
  incrementPassByPointer(&i);
  std::cout << "Value of i after increment is : " << i << std::endl;
}
Output:
Value of i before increment is : 10
Value of i after increment is : 11

Analysis:
We are passing address of a variable inside calling function to the called function. Moreover, modifying the value at that address so the change done is reflected to the calling function variable too.

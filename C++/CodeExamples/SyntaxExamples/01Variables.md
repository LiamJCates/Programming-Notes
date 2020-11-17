"Variables" are simply storage locations for data. For every variable, some memory is allocated. The size of this memory depends on the type of the variable.

int main() {
  int var1, var2, var3;
  var1 = 100;
  var2 = 200;
  var3 = var1 + var2;
  std::cout << "Adding " << var1 << " and " << var2 << " will give " << var3 << std::endl;
}

Analysis:
· Memory is allocated for variables var1, var2 and var3. Whenever we
declare a variable, then memory is allocated for storing the value in the variable. In our example, 4 bytes are allocated for each int.

· Value 100 is stored in variable var1 and value 200 is stored in variable var2.

· Value of var1 and var2 is added and stored in var3.

· Finally, the value of var1, var2 and var3 is printed to screen using
std::cout.

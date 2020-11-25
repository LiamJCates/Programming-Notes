System stack and Method Calls
When the method is called, the current execution is stopped and the control goes to the called method.

After the called method exits / returns, the execution resumes from the point at which the execution was stopped.

To get the exact point at which execution should be resumed, the address of the next instruction is stored in the stack.

When the method call completes, the address at the top of the stack is taken out.

void function2() {
  print("function2 line 1");
}

void function1() {
  print("function1 line 1");
  function2();
  print("function1 line 2");
}

void main() {
  print("main line 1");
  function1();
  print("main line 2");
}

Output:
main line 1
function1 line 1
function2 line 1
function1 line 2
main line 2

Analysis:
· Every program starts with main() method.
· The first statement of main() will be executed. And we will print “main line 1” as output.
· function1() is called. Before control goes to function1() then next instruction that is address of next line is stored in the system stack.
· Control goes to function1() method.
· The first statement inside function1() is executed, this will print “function1 line 1” to output.
· function2() is called from function1(). Before control goes to function2() address of the next instruction that is address of next line is added to the system stack.
· Control goes to function2() method.
· “function2 line 1” is printed to screen.
· When function2() exits, control come back to function1(). And the program reads the next instruction from the stack, and the next line is executed. And print “function1 line 2” to screen.
· When function1 exits, control comes back to the main method. And program
reads the next instruction from the stack and executed it and finally “main line 2” is printed to screen.

Points to remember:
1. Methods are implemented using a stack.
2. When a method is called the address of the next instruction is pushed into the stack.
3. When a method is finished the address of the execution is taken out of the stack.

Debugging
One of the most important skills for a software engineer is efficient, effective debugging.



## Visual Studio
Visual Studio has an excellent, built-in debugger. I suggest that you debug
programs in its Debug configuration. This causes the tool chain to build a
target that enhances the debugging experience.

To insert a breakpoint click the margin just to the left of the corresponding line number. A red circle appears where you clicked

Select Debug > Start Debugging. The program will run up to the line
where you’ve inserted a breakpoint. The debugger will halt program
execution, and a yellow arrow will appear to indicate the next instruction to be run

Select Debug > Step Over. The step over operation executes the
instruction without “stepping into” any function calls. By default,
the keyboard shortcut for step over is F10.

Debug > Step Into calls a function and breaks on the first line. You can continue debugging this function by stepping into/over its instructions. By default, the keyboard shortcut for step into is F11.

To allow execution to return to a caller, select Debug > Step Out. By default, the keyboard shortcut for this operation is shift-F11.

Inspect the Autos window by selecting Debug > Windows > Auto. You
can see the current value of some of the important variables.

The Visual Studio debugger supports many more features. For more
information, check out the Visual Studio documentation link available at
https://ccc.codes/.



## GCC and Clang Debugging with GDB and LLDB

Clang also has an excellent debugger called the Low Level Debugger
(LLDB), which you can download at https://lldb.llvm.org/. It was designed to
work with the GDB commands in this section, so for brevity I won’t cover
LLDB explicitly. You can debug programs compiled with GCC debug support using LLDB, and you can debug programs compiled with Clang debug
support using GDB.

To debug the program in Listing 1-8 (on page 20) using GDB, follow
these steps:
1. In a command line, navigate to the folder where you’ve stored your
header and source files.

2. Compile your program with debug support:
$ g++-8 main.cpp -o stepfun -g

3. Debug your program using gdb; you should see the following interactive
console session:
$ gdb stepfun
GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.
html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law. Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from stepfun...done.
(gdb)

4. To insert a breakpoint, use the command break, which takes a single
argument corresponding to the name of the source file and the line
where you want to break, separated by a colon (:). For example, suppose you want to break on the first line of main.cpp. In Listing 1-8, that
is on line 5 (although you might need to adjust placement depending
on how you’ve written the source). You can create a breakpoint using
the following command at the (gdb) prompt:
(gdb) break main.cpp:5

5. You can also tell gdb to break at a particular function by name:
(gdb) break main

6. Either way, you can now execute your program:
(gdb) run
Starting program: /home/josh/stepfun
Breakpoint 1, main () at main.cpp:5
5 int num1 = 42;
(gdb)Up and Running 27

7. To single step into an instruction, you use the step command to follow
each line of the program, including steps into functions:
(gdb) step
6 int result1 = step_function(num1);

8. To continue stepping, press enter to repeat the last command:
(gdb)
step_function (x=42) at step_function.cpp:4

9. To step back out of a function invocation, you use the finish command:
(gdb) finish
Run till exit from #0 step_function (x=42) at step_function.cpp:7
0x0000000000400546 in main () at main.cpp:6
6 int result1 = step_function(num1);
Value returned is $1 = 1

10. To execute an instruction without stepping into a function call, you use
the next command:
(gdb) next
8 int num2 = 0;

11. To inspect the current value of variables, you use the info locals
command:
(gdb) info locals
num2 = -648029488
result2 = 32767
num1 = 42
result1 = 1
num3 = 0
result3 = 0
Notice that any variables that have not yet been initialized will not
have sensible values.

12. To continue execution until the next breakpoint (or until the program
completes), use the continue command:
(gdb) continue
Continuing.
Num1: 42, Step: 1
Num2: 0, Step: 0
Num3: -32768, Step: -1
[Inferior 1 (process 1322) exited normally]

13. Use the quit command to exit gdb at any time.28 Chapter 1
GDB supports many more features. For more information, check out
the documentation at https://sourceware.org/gdb/current/onlinedocs/gdb/.

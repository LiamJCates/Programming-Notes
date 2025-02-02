In computer programming and software development, debugging is the process of finding and resolving bugs (defects or problems that prevent correct operation) within computer programs, software, or systems.

Debugging tactics can involve interactive debugging, control flow analysis, unit testing, integration testing, log file analysis, monitoring at the application or system level, memory dumps, and profiling. Many programming languages and software development tools also offer programs to aid in debugging, known as debuggers.




Debugger

A debugger is a tool that can help us see what happens when a program is running. As we have already mentioned, some bugs can be hard to find and understand just by running the program. Often, we will discover a strange behavior in the program, but it might not be obvious what the reason behind this behavior is.

A debugger is a computer program used to test and debug other programs (the "target" program). The main use of a debugger is to run the target program under controlled conditions that permit the programmer to track its operations in progress and monitor changes in computer resources (most often memory areas used by the target program or the computer's operating system) that may indicate malfunctioning code. Typical debugging facilities include the ability to run or halt the target program at specific points, display the contents of memory, CPU registers or storage devices (such as disk drives), and modify memory or register contents in order to enter selected test data that might be a cause of faulty program execution.

The code to be examined might alternatively be running on an instruction set simulator (ISS), a technique that allows great power in its ability to halt when specific conditions are encountered, but which will typically be somewhat slower than executing the code directly on the appropriate (or the same) processor. Some debuggers offer two modes of operation, full or partial simulation, to limit this impact.

A "trap" occurs when the program cannot normally continue because of a programming bug or invalid data. For example, the program might have tried to use an instruction not available on the current version of the CPU or attempted to access unavailable or protected memory. When the program "traps" or reaches a preset condition, the debugger typically shows the location in the original code if it is a source-level debugger or symbolic debugger, commonly now seen in integrated development environments. If it is a low-level debugger or a machine-language debugger it shows the line in the disassembly (unless it also has online access to the original source code and can display the appropriate section of code from the assembly or compilation).


A debugger is an application that is tailored for a particular programming language and can be used to pause the application at a specified code line. At this point, we can inspect what values all the variables have. We can also resume the execution of the program or execute it one line at a time to see what happens.


Breakpoints
A breakpoint is a way for us to say, run the program to this point, then pause it and show
me the status of the program.




Debugging ranges in complexity from fixing simple errors to performing lengthy and tiresome tasks of data collection, analysis, and scheduling updates. The debugging skill of the programmer can be a major factor in the ability to debug a problem, but the difficulty of software debugging varies greatly with the complexity of the system, and also depends, to some extent, on the programming language(s) used and the available tools, such as debuggers. Debuggers are software tools which enable the programmer to monitor the execution of a program, stop it, restart it, set breakpoints, and change values in memory. The term debugger can also refer to the person who is doing the debugging.

Generally, high-level programming languages, such as Java, make debugging easier, because they have features such as exception handling and type checking that make real sources of erratic behavior easier to spot. In programming languages such as C or assembly, bugs may cause silent problems such as memory corruption, and it is often difficult to see where the initial problem happened. In those cases, memory debugger tools may be needed.

In certain situations, general purpose software tools that are language specific in nature can be very useful. These take the form of static code analysis tools. These tools look for a very specific set of known problems, some common and some rare, within the source code, concentrating more on the semantics (e.g. data flow) rather than the syntax, as compilers and interpreters do.

Both commercial and free tools exist for various languages; some claim to be able to detect hundreds of different problems. These tools can be extremely useful when checking very large source trees, where it is impractical to do code walk-throughs. A typical example of a problem detected would be a variable dereference that occurs before the variable is assigned a value. As another example, some such tools perform strong type checking when the language does not require it. Thus, they are better at locating likely errors in code that is syntactically correct. But these tools have a reputation of false positives, where correct code is flagged as dubious. The old Unix lint program is an early example.

For debugging electronic hardware (e.g., computer hardware) as well as low-level software (e.g., BIOSes, device drivers) and firmware, instruments such as oscilloscopes, logic analyzers, or in-circuit emulators (ICEs) are often used, alone or in combination. An ICE may perform many of the typical software debugger's tasks on low-level software and firmware.














Debugging process

Normally the first step in debugging is to attempt to reproduce the problem. This can be a non-trivial task, for example as with parallel processes and some Heisenbugs. Also, specific user environment and usage history can make it difficult to reproduce the problem.

After the bug is reproduced, the input of the program may need to be simplified to make it easier to debug. For example, a bug in a compiler can make it crash when parsing some large source file. However, after simplification of the test case, only few lines from the original source file can be sufficient to reproduce the same crash. Such simplification can be made manually, using a divide-and-conquer approach. The programmer will try to remove some parts of original test case and check if the problem still exists. When debugging the problem in a GUI, the programmer can try to skip some user interaction from the original problem description and check if remaining actions are sufficient for bugs to appear.

After the test case is sufficiently simplified, a programmer can use a debugger tool to examine program states (values of variables, plus the call stack) and track down the origin of the problem(s). Alternatively, tracing can be used. In simple cases, tracing is just a few print statements, which output the values of variables at certain points of program execution.









Techniques
Interactive debugging

Print debugging (or tracing) is the act of watching (live or recorded) trace statements, or print statements, that indicate the flow of execution of a process. This is sometimes called printf debugging, due to the use of the printf function in C.

Remote debugging is the process of debugging a program running on a system different from the debugger. To start remote debugging, a debugger connects to a remote system over a communications link such as a local area network. The debugger can then control the execution of the program on the remote system and retrieve information about its state.

Post-mortem debugging is debugging of the program after it has already crashed. Related techniques often include various tracing techniques like examining log files, outputting a call stack on crash, and analysis of memory dump (or core dump) of the crashed process. The dump of the process could be obtained automatically by the system (for example, when the process has terminated due to an unhandled exception), or by a programmer-inserted instruction, or manually by the interactive user.

"Wolf fence" algorithm: Edward Gauss described this simple but very useful and now famous algorithm in a 1982 article for Communications of the ACM as follows: "There's one wolf in Alaska; how do you find it? First build a fence down the middle of the state, wait for the wolf to howl, determine which side of the fence it is on. Repeat process on that side only, until you get to the point where you can see the wolf." This is implemented e.g. in the Git version control system as the command git bisect, which uses the above algorithm to determine which commit introduced a particular bug.

Record and replay debugging is the technique of creating a program execution recording (e.g. using Mozilla's free rr debugging tool; enabling reversible debugging/execution), which can be replayed and interactively debugged. Useful for remote debugging and debugging intermittent, non-determinstic, and other hard-to-reproduce defects.

Delta Debugging – a technique of automating test case simplification.[11]:p.123

Saff Squeeze – a technique of isolating failure within the test using progressive inlining of parts of the failing test.

Causality tracking: There are techniques to track the cause effect chains in the computation.[13] Those techniques can be tailored for specific bugs, such as null pointer dereferences.[

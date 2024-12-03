We will look into the details about how we can execute C++ programs.

C++ programs can be executed on a variety of operating systems like Windows, Linux, Mac OS, etc. Each operating system has its own features & behavior and based on that the approach of setting up a C++ environment will differ accordingly.

### Local Environment

In order to learn C++ effectively, we need to practice programs before we begin with C++ programming. For this, we need to have a proper environment on our local machine from where we can write C++ programs, compile them and later execute them.

As a part of the local environment setup, we need two most important software on our machine as mentioned below:

#### Text Editor

Firstly, we need to write programs. In order to write these programs, we need a text editor on our machine. Any text editor that allows us to input text should work. It can be as simple as a notepad or an advanced editor like Notepad++. We need this editor to write programs.

Once we finish writing a program, we save this file with an extension ‘.cpp’ and then pass it on to compiler for compiling.



#### Compiler

Once we have the C++ program ready, we need to compile the program and execute it. We use a software program called a “compiler” to compile the program.

In simple terms, compilation can be defined as the conversion of source code into the object code.

For more information about compilers, see:
[C++\Compiler.md]


### Setting C/C++ Compiler



#### Linux Operating System

We need to type the following command in order to ensure that our Linux Operating System has the correct version of C++ compiler.

g++ -v

If the compiler is installed on this Linux system, then the above command will launch the C++ compiler and print its version.

If the terminal shows the following
```
g++ hello.cpp -o hello
The program 'g++' can be found in the following packages:
 * g++
 * pentium-builder
Try: sudo apt-get install <selected package>
```

run
```
sudo apt-get install g++
```

If an error occurs, then it is required that we read the error and check the documentation again and correct the setup accordingly.

Note: The above command to execute a.out may differ depending on the version of Linux.

For a simple example that walks through creating and compiling source code, see:
[C++\GettingStarted.md]



#### Windows Operating System

C++ is very vast and so are the compilers available for C++. We have a lot of compilers that are available in the Windows out of which some are freely available while some are paid.

Some of the compilers that are freely available are listed below:

    Cygwin (GNU C++)
    MINGW (Minimalist GNU for Windows) – GCC version for Windows.
    Intel C++ for non-commercial development.
    Microsoft Visual C++ Express edition.
    Oracle C++

Among all the above compilers, Microsoft Visual C++ compiler is the most popular one. We can either download the free express edition or community edition for this compiler. This is a complete solution IDE and will let us develop everything right from simple programs to big projects.

As this is a readymade IDE, we need not specifically give any command or remember a sequence to compile and execute the C++ programs. We just need to download the appropriate version of MS Visual Studio and install it. Once done, we are ready to use it.



#### Online C++ IDEs

Online IDES are the best option for people who want to gain experience with C++ by practicing it and forego the complications of a local setup.

Popular among these are:

##### Cpp.sh

This is an interactive online compiler that allows you to write C++ program online and execute it.


##### codechef ide

Codechef ide is a multi-language compiler. It allows us to select the appropriate language for which you want to execute programs and then you can execute the programs in the required language.

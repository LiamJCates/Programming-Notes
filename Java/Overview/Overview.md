Java technology is both a programming language and a platform



Originally developed by James Gosling at Sun Microsystems, since acquired by Oracle Corporation

Java is currently one of the most popular programming languages in use. According to Oracle, 3 billion devices run Java. Furthermore, Android apps are also developed using Java. With the growing demand for mobile apps, it is safe to say that Java is an essential language to learn if you are interested in becoming a programmer.

Java Programming Language
The Java programming language is a high-level language that can be characterized as:
Object oriented
Distributed
Multithreaded
Dynamic
Platform Independent

Architecture neutral
Portable
High performance
Robust
Secure

Java originally seduced programmers with friendly syntax, object-oriented features, memory management, and best of all — portability.






Java Platform

A platform is the hardware or software environment in which a program runs.
Most platforms can be described as a combination of  OS and underlying hardware.
The Java platform differs from most other platforms in that it's a software-only platform that runs on top of other hardware-based platforms.

The Java platform has two components:
The Java Virtual Machine
The Java Application Programming Interface (API)


 technical terms are defined in The Java Language Specification, Third Edition [JLS]




### The Java Application Programming Interface (API)
The term API is short for  application programming interface
The Java API and API's in general can be considered as collections of ready-made software components that provide useful capabilities.
A programmer who writes a program that uses an API is referred to as a  user of the API.
A class whose implementation uses an API is a client of the API.


The Java API is sectioned into libraries or related classes and interfaces called packages
A java package is a group of similar types of classes, interfaces and sub-packages.
Java packages can be categorized into built-in packages and user-defined packages.



The term exported API, or simply API, refers to the
classes, interfaces, constructors, members, and serialized forms by which a programmer accesses a class, interface, or package.

API is used in preference to the otherwise preferable term interface to avoid
confusion with the language construct of that name.


Classes, interfaces, constructors, members, and serialized forms are collectively known as
API elements.

An exported API consists of the API elements that are accessible outside of the package that defines the API.

Loosely speaking, the exported API of a package consists of  the public/protected members and constructors of every public class or interface in the package.

 Code should be reused rather than copied



### The Java Class Libraries
The Java environment relies on several built-in class libraries that contain many built-in methods that provide support for such things as I/O, string handling, networking, and graphics.

The Java libraries contain thousands of classes and interfaces and tens of thousands of functions. Luckily, you do not need to know every one of them, but you do need to know surprisingly many to use Java for anything realistic.



### How Java compiles and interprets code
Once the source code has been written, you use the Java compiler to compile the source code into a format known as Java bytecodes

the bytecodes can be run on any platform that has a Java runtime environment (IRE) installed on it. A JRE includes all of the software needed to run bytecodes. Among other things, this includes an implementation of a Java virtual machine (JVM). This JVM includes a Java interpreter to translate the Java bytecodes into native code that can be understood by the underlying operating system. Most modern implementations of the JVM have replaced the Java interpreter with a just-in-time compiler (JIT compiler). A JIT compiler is similar to an interpreter in some ways, but it actually compiles the most used parts of the Java bytecodes into native code and stores this code in a cache. This improves performance significantly. Since JREs are available for all major operating systems, you can run Java on most platforms. This is what gives Java applications their platform independence.

When you develop a Java application, you typically use a code editor to work with
the source code for the application. Files that contain source code have the .java
extension.
• The Java compiler translates Java source code into a platform-independent
format known as Java bytecodes. Files that contain Java bytecodes have the .class
extension.
• A Java virtual machine (JVM) includes a Java interpreter that executes Java
bytecodes. Most modern implementations of the JVM have replaced the Java
interpreter with a just-in-time compiler (JIT compiler). A JIT compiler is similar to
an interpreter in some ways, but it improves performance significantly.
• A Java runtime environment (IRE) has all of the components necessary to run
bytecodes including a JVM. Since JREs are available for most operating systems,
Java bytecodes can be run on most operating systems.



### The Java Virtual Machine

Like all modern, high level programming languages, Java code resembles the English language which computers are unable to understand.

Every computer platform has its own machine code instruction set.
Code has to be converted into machine code through a process known as compilation.
Hence, machine code that is compiled for one platform will not work on another platform.  

Programming languages like C and C++ compile written code into machine code directly.  As a result, this machine code can only be run on the specific platform that the code is compiled for.

Java does it a little differently. Instead of compiling into machine code directly, Java compiles all written
code into bytecode first.

Java Bytecode is platform independent. That is, there is no difference between the bytecode for Windows, Mac or Linux. When a user wants to run a Java program, a program inside the user’s
computer (known as the Java Virtual Machine or JVM) converts this bytecode into machine code for the specific platform that the user uses.

The advantage of using this two-step compilation process is that it allows Java code to be run on all platforms as long as the computer running the Java program has JVM installed.

Compilation
The Java virtual machine is implemented in software.
The Java virtual machine reads and executes java bytecode.
To produce java bytecode we first begin with properly formatted java source code
Java source code is a source code document following an established protocol (the Java language).
All Java source code is first written in plain text files ending with the .java extension.
The .java extension signals a document is java source code.
The javac compiler checks source code documents for errors
The javac compiler only compile valid java source documents which follow the Java language protocol
valid source files are then compiled into .class files by the javac compiler.
The compiler creates this new document by translating the .java file into Java bytecode.
java bytecode is the machine language of the Java Virtual Machine
The java launcher tool can then be used to run applications with an instance of the Java Virtual Machine.

General Compilation Steps
Produce source code                 "filename.java"
compile using javac compiler command         %javac file.java
compiler outputs class file            "filename.class"
run compiled bytecode on a JVM             %java filename

The Java slogan is "Write once run anywhere"

What does WORA mean?
Ideally, Java can be developed on any device, compiled into a standard bytecode and be expected to run on any device equipped with a Java virtual machine (JVM).

Compiled Java bytecode is thus platform independent as any device capable of running Java will be able to interpret/translate Java bytecode

As a platform-independent environment, the Java platform can be slower than native code.





### Bytecode
The key that allowed Java to the problems of security and the portability is that the output of a Java compiler is not executable code. Rather, it is bytecode.

Bytecode is a highly optimized set of instructions designed to be executed by what is called the Java Virtual Machine (JVM), which is part of the Java Runtime Environment (JRE). In essence, the original JVM was designed as an interpreter for bytecode. This may come as a bit of a surprise because many modern languages are designed to be compiled into CPU-specific, executable code due to performance concerns. However, the fact that a Java program is executed by the JVM helps solve the major problems associated with web-based programs. Here is why. Translating a Java program into bytecode makes it much easier to run a program in a wide variety of environments because only the JRE (which includes the JVM) needs to be implemented for each platform. Once a JRE exists for a given system, any Java program can run on it. Remember, although the details of the JRE will differ from platform to platform, all JREs understand the same Java bytecode.

If a Java program were compiled to native code, then different versions of the same program would have to exist for each type of CPU connected to the Internet. This is, of course, not a feasible solution. Thus, the execution of bytecode by the JVM is the easiest way to create truly portable programs.

The fact that a Java program is executed by the JVM also helps to make it secure. Because the JVM is in control, it manages program execution. Thus, it is possible for the JVM to create a restricted execution environment, called the sandbox, that contains the program, preventing unrestricted access to the machine. Safety is also enhanced by certain restrictions that exist in the Java language.

When a program is interpreted, it generally runs slower than the same program would run if compiled to executable code. However, with Java, the differential between the two is not so great. Because bytecode has been highly optimized, the use of bytecode enables the JVM to execute programs much faster than you might expect. Although Java was designed as an interpreted language, there is nothing about Java that prevents on-the-fly compilation of bytecode into native code in order to boost performance. For this reason, the HotSpot JVM was introduced not long after Java’s initial release. HotSpot includes a just-in-time (JIT) compiler for bytecode. When a JIT compiler is part of the JVM, selected portions of bytecode are compiled into executable code in real time on a piece-by-piece demand basis. That is, a JIT compiler compiles code as it is needed during execution. Furthermore, not all sequences of bytecode are compiled—only those that will benefit from compilation. The remaining code is simply interpreted. However, the just-in-time approach still yields a significant performance boost. Even when dynamic compilation is applied to bytecode, the portability and safety features still apply because the JVM is still in charge of the execution environment.

One other point: Beginning with JDK 9, some Java environments will also support an ahead-of-time compiler that can be used to compile bytecode into native code prior to execution by the JVM, rather than on the-fly. Ahead-of-time compilation is a specialized feature and it does not replace Java’s traditional approach just described.

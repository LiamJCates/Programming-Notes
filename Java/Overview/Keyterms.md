# The Java “White Paper” Buzzwords
The authors of Java wrote an influential white paper that explains their design goals and accomplishments. They also published a shorter overview that is organized along the following 11 buzzwords:
1. Simple
2. Object-Oriented
3. Distributed
4. Robust
5. Secure
6. Architecture-Neutral
7. Portable
8. Interpreted
9. High-Performance
10. Multithreaded
11. Dynamic

### Simple
The syntax for Java is a cleaned-up version of C++ syntax.

Java was designed to be easier than C++ primarily in the following ways:
Java automatically takes care of memory allocation and deallocation, an error-prone and tedious task.
Java doesn’t include pointers, a powerful feature for experienced programmers that can be easily misused and can open up major security vulnerabilities.
Java includes only single inheritance of classes in object-oriented programming.
Java doesn’t have to be compiled on each different platform, executing the same bytecode everywhere.


### Object-oriented
Object-oriented programming (OOP): an approach to programming that breaks a programming problem into objects that interact with each other. Objects are created from templates called classes that define class data fields and the code required to use that data
Encapsulation: Java supports access modifiers to protect data from
unintended access and modification. Most people consider
encapsulation to be an aspect of object-oriented languages.

### Distributed
Java has an extensive library of routines for coping with TCP/IP protocols like HTTP and FTP. Java applications can open and access objects across the Net via URLs with the same ease as when accessing a local file system.



### Robust
Java is intended for writing programs that must be reliable in a variety of ways. Java puts a lot of emphasis on early checking for possible problems, later dynamic (runtime) checking, and eliminating situations that are error prone. . . . The single biggest difference between Java and C/C++ is that Java has a pointer model that eliminates the possibility of overwriting memory and corrupting data. The Java compiler detects many problems that in other languages would show up only at runtime. As for the second point, anyone who has spent hours chasing memory corruption caused by a pointer bug will be very happy with this aspect of Java.

One of the major advantages of Java over C++ is that it
prevents memory leaks. Java manages memory on its own and does
garbage collection automatically. Bad memory management in C++ is
a big source of errors in prog


### Secure
Java is intended to be used in networked/distributed environments. Toward that end, a lot of emphasis has been placed on security. From the beginning, Java was designed to make certain kinds of attacks impossible:
Overrunning the runtime stack—a common attack of worms and viruses
Corrupting memory outside its own process space such as reading or writing files without permission

The lack of pointers and the presence of automatic memory management are two key elements of Java security. In order for Java to enable programs to be safely downloaded and executed on the client computer, it was necessary to prevent them from launching such an attack. Java achieved this protection by enabling you to confine an application to the Java execution environment and prevent it from accessing other parts of the computer.

Originally, the Java attitude towards downloaded code was “Bring it on!” Untrusted code was executed in a sandbox environment where it could not impact the host system. The ability to download an application with a high level of confidence that no harm will be done contributed significantly to Java’s early success.

Unfortunately, over time, hackers got quite good at spotting subtle flaws in the implementation of the security architecture. Sun, and then Oracle, had a tough time keeping up with bug fixes. After a number of high-profile attacks, browser vendors and Oracle became increasingly cautious. Java browser plug-ins no longer trust remote code unless it is digitally signed and users have agreed to its execution.

Java code runs inside the JVM. This creates a sandbox that
makes it hard for Java code to do malicious things

### Architecture Neutral / Platform Independent
Java is an interpreted language that gets
compiled to bytecode. A key benefit is that Java code gets compiled
once rather than needing to be recompiled for different operating
systems. This is known as “write once, run everywhere.” The
portability allows you to easily share pre-compiled pieces of software.

The compiler generates an architecture-neutral object file format. The compiled code is executable on any processor, given the presence of the Java runtime system. The Java compiler does this by generating bytecode instructions which have nothing to do with a particular computer architecture. Rather, they are designed to be both easy to interpret on any machine and easy to translate into native machine code on the fly.




### Portable
Unlike languages like C and C++, there are no “implementation-dependent” aspects of the specification. The sizes of the primitive data types are specified, as is the behavior of arithmetic on them. As well, for everything that isn’t related to user interfaces, the Java libraries do a great job of letting you work in a platform-independent manner. You can work with files, regular expressions, XML, dates and times, databases, network connections, threads, and so on, without worrying about the underlying operating system. Not only are your programs portable, but the Java APIs are often of higher quality than the native ones.



### Interpreted
The Java interpreter can execute Java bytecodes directly on any machine to which the interpreter has been ported. Since linking is a more incremental and lightweight process, the development process can be much more rapid and exploratory.

Some believe Java is interpreted, so it is too slow for serious applications.

In the early days of Java, the language was interpreted. Nowadays, the Java virtual machine uses a just-in-time compiler. The “hot spots” of your code will run just as fast in Java as they would in C++, and in some cases even faster.



### High-Performance

While the performance of interpreted bytecodes is usually more than adequate, there are situations where higher performance is required. The bytecodes can be translated on the fly (at runtime) into machine code for the particular CPU the application is running on.

In the early years of Java, many users disagreed with the statement that the performance was “more than adequate.” Today, however, the just-in-time compilers have become so good that they are competitive with traditional compilers and, in some cases, even outperform them because they have more information available. For example, a just-in-time compiler can monitor which code is executed frequently and optimize just that code for speed. A more code is executed frequently and optimize just that code for speed. A more sophisticated optimization is the elimination (or “inlining”) of function calls. The just-in-time compiler knows which classes have been loaded. It can use inlining when, based upon the currently loaded collection of classes, a particular function is never overridden, and it can undo that optimization later if necessary.



### Multithreaded
Java is designed to allow multiple pieces of code to
run at the same time.
[The] benefits of multithreading are better interactive responsiveness and real-time behavior. Nowadays, we care about concurrency because Moore’s law has come to an end. Instead of faster processors, we just get more of them, and we have to keep them busy. Yet when you look at most programming languages, they show a shocking disregard for this problem. Java was well ahead of its time. It was the first mainstream language to support concurrent programming. As you can see from the white paper, its motivation was a little different. At the time, multicore processors were exotic, but web programming had just started, and processors spent a lot of time waiting for a response from the server. Concurrent programming was needed to make sure the user interface didn’t freeze. Concurrent programming is never easy, but Java has done a very good job making it manageable.



### Dynamic
In a number of ways, Java is a more dynamic language than C or C++. It was designed to adapt to an evolving environment. Libraries can freely add new methods and instance variables without any effect on their clients. In Java, finding out runtime type information is straightforward. This is an important feature in situations where code needs to be added to a running program. A prime example is code that is downloaded from the Internet to run in a browser. In C or C++, this is indeed a major challenge, but the Java designers were well aware of dynamic languages that made it easy to evolve a running program. Their achievement was to bring this feature to a mainstream programming language.



### Backward Compatibility
The Java language architects pay careful
attention to making sure old programs will work with later versions of
Java. While this doesn’t always occur, changes that will break
backward compatibility occur slowly and with notice. Deprecation is a
technique to accomplish this where code is flagged to indicate it
shouldn’t be used. This lets developers know a different approach is
preferred so they can start changing the code.

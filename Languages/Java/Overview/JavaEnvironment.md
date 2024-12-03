Java Development Kit (JDK) contains the minimum software you
need to do Java development. Key pieces include the compiler (javac),
which converts .java files to .class files, and the launcher java, which
creates the virtual machine and executes the program.

The JDK also contains other tools including the archiver (jar)
command, which can package files together, and the API
documentation (javadoc) command for generating documentation.

The javac program generates instructions in a special format that the
java command can run called bytecode. Then java launches the Java
Virtual Machine (JVM) before running the code. The JVM knows how
to run bytecode on the actual machine it is on. You can think of the
JVM as a special magic box on your machine that knows how to run
your .class file.

Where Did the JRE Go?
In previous versions of Java, you could download a Java Runtime
Environment (JRE) instead of the full JDK. The JRE was a subset
of the JDK that was used for running a program but could not
compile one. It was literally a subset. In fact, if you looked inside
the directory structure of a JDK in older versions of Java, you
would see a folder named jre.
In Java 11, the JRE is no longer available as a stand-alone
download or a subdirectory of the JDK. People can use the full JDK
when running a Java program. Alternatively, developers can
supply an executable that contains the required pieces that would have been in the JRE. The jlink command creates this executable.
While the JRE is not in scope for the exam, knowing what changed
may help you eliminate wrong answers.

Java comes with a large suite of application
programming interfaces (APIs) that you can use. For example, there
is a StringBuilder class to create a large String and a method in
Collections to sort a list. When writing a program, it is helpful to look
what pieces of your assignment can be accomplished by existing APIs.

Every six months, the version number of Java gets incremented. Java
11 came out in September 2018.

Every three years, Oracle has a long-term support (LTS) release.
Unlike non-LTS versions that are supported for only six months, LTS
releases have patches and upgrades available for at least three years.

It is recommended to use the Oracle distribution of Java 11 to study. Note that Oracle’s JDK is free for personal use as well as other scenarios. Alternatively, you can use OpenJDK, which is based
on the same source code.

main()
When you run your program, you’re really running a class. Programs are launched through the Java interpreter with a class name and execution begins with the main method.

Running a java program means telling the Java Virtual Machine (JVM) to “Load the named class, then start executing its main() method. Keep running ‘til all the code in main is finished.”

When the JVM starts running, it looks for the class you give it at the command line.
Then it starts looking for a specially-written method that looks exactly like:

public static void main (String[] args) {
// your code goes here
}

Next, the JVM runs everything between the curly braces { } of your main method.

Whenever a Java application is started, the main() method is the first method to be called.
main must always be static as static methods do not require an instance of their respective class to be instantiated.

When the application is launched, there aren't any objects yet.
It is the job of the main method to construct the objects that are needed to start the program.

String[] args
The words String[] args inside the parentheses of our main() method means the main() method can take in an array of strings as input.
The String args[] parameter of the main method holds the command-line arguments
A commandline argument is the information that directly follows the program’s name on the command line when it is executed.

In the main method of a Java program, the name of the program is not stored in the args array. For example, when you start up a program as

java Message -h world

from the command line, then args[0] will be "-h" and not "Message" or "java".

Class Use

When you create a class, you may also want to create a separate test class which you’ll use to create objects of your new class type.

The tester class is where you put the main method, and in that main() method you create and access objects of your new class type.

The tester class has only one job: to try out the methods and variables of your new object class type.

Such a program that uses the class is often referred to as a client of the class.

As long as you’re in main(), you’re not really in Objectville. It’s fine for a test program to run within the main method, but in a true OO application, you need objects talking to other objects, as opposed to a static main() method creating and testing objects. The two uses of main:
■ to test your real class
■ to launch/start your Java application

A real Java application is nothing but objects talking to other objects. In this case, talking means objects calling methods on one another.



Class File Location
For a class to communicate it must be public:
public class ClassName { //class members }

A public class must be written in a source file that has the same name as the class, with the .java extension. A public class named Greeter, for example, must be placed in a file named Greeter.java. As a result, you can’t place two public classes in the same file. You can put the two classes into one file, but only one class in the file can be a public class.

When you compile code with more than one class in a single source file, Java still creates a separate class file for each class. Removing the public keyword from a class is acceptable for relatively small programs, but its limitation is that the class is available only to the classes defined within the same .java file. If you want a class to be more widely available, opt for the second solution: Place it, with the public keyword, in a separate file with its name. 

If you’re going to create an application that has several public classes, create a separate folder for the application. Then save all the class files for the application to this folder. If you keep your class files together in the same folder, the Java compiler can find them. If you place them in separate folders, you may need to adjust your ClassPath environment variable to help the compiler find the classes.










Module
Each module is a class. We use the term module to refer to all the code that we keep in a single file. By convention, each module is a Java class that is kept in a file with the same name of the class but has a .java extension.

Modular programming
•Organize programs as independent modules that do a job together.
•Why? Easier to share and reuse code to build bigger programs.

Libraries.
We refer to a module whose methods are primarily intended for use by many other programs as a library.

Clients.
We use the term client to refer to a program that calls a given library method.

APIs.
Programmers normally think in terms of a contract between the client and the implementation that is a clear specification of what the method is to do.

Implementations.
We use the term implementation to describe the Java code that implements the methods in an API.

Packages
Java classes can be grouped into packages. Packages allow you to group related classes and interfaces.

A package serves three purposes. First, it provides a mechanism by which related pieces of a program can be organized as a unit. Classes defined within a package must be accessed through their package name. Thus, a package provides a way to name a collection of classes. Second, they eliminate potential naming conflicts among classes. Finally, a package participates in Java’s access control mechanism. Classes defined within a package can be made private to that package and not accessible by code outside the package. Thus, the package provides a means by which classes can be encapsulated.

In general, when you name a class, you are allocating a name from the namespace. A namespace defines a declarative region. In Java, no two classes can use the same name from the same namespace. Thus, within a given namespace, each class name must be unique.

Package names are dot-separated sequences of identifiers

Classes in Java can be referred to by a short name such as Object or a full name that includes the package name, such as java.lang.Object. Your Java classes can refer to any class in the java.lang package using only its short name. The java.lang package provides basic language features such as string handling and mathematical operations. To use classes from any other package, you must refer to them either by explicitly using their full package name or using an import command for a particular package. Using import tells the Java compiler to look in that package when turning a short name of a class into the full name.

package pkgName;
This statement tells the compiler that the Java file we wrote belongs to the pkgName package.

When we write package pkgName; at the top of our file, we are asking the compiler to include this file in the helloworld package. The compiler will then create a folder named “pkgName” and save the file into that folder. Files that belong to the same package are stored in the same folder.

You can create a hierarchy of packages. To do so, simply separate each package name from the one above it by use of a period. The general form of a multileveled package statement is shown here:

package pack1.pack2.pack3...packN;

It is a convention for us to name our packages in lowercase, note that Java is case-sensitive

Any class without a package statement is in the "default package" with no package name.
The fuIl name of a class consists of the package name followed by the class name.


Importing Packages
When you use a class from another package, you can fully qualify the name of the class with the name of its package, as the preceding examples have done. However, such an approach could easily become tiresome and awkward, especially if the classes you are qualifying are deeply nested in a package hierarchy.

The import directive allows programmers to omit package names when referring to classes.

 If you simultaneously use two classes with the same short name (such as java.util.Date and java.sql.Date), then you are stuck-you must use the full name for one of them.

You can import all classes from a package using a wildcard: import java.util.* ;

You never have to explicitly import two packages:

» java.lang: This package contains classes that are so commonly used that the Java compiler makes them available to every program. Examples of the classes in this package are String, Exception, and the various wrapper classes, such as Integer and Boolean. (For complete documentation on this package and all of the other Java packages described in this book, refer to http://download.java.net/jdk8/docs/api.)

» The default package: This package contains classes that aren’t specifically put in some other package.

The wildcard import imports all the classes in a package by using the asterisk as the wildcard.

For example, the following statement imports all the classes from the package java.util.
import java.util.*;

The information for the classes in an imported package is not read in at compile time or runtime unless the class is used in the program. The import statement simply tells the compiler where to locate the classes. There is no performance difference between a specific import and a wildcard import declaration.
Static Import
Java supports an expanded use of the import keyword. By following import with the keyword static, an import statement can be used to import the static members of a class or interface. This is called static import. When using static import, it is possible to refer to static members directly by their names, without having to qualify them with the name of their class. This simplifies and shortens the syntax required to use a static member.


There are two general forms of the import static statement. The first, which is used by the preceding example, brings into view a single name:
import static package.type-name.static-member-name;

Here, type-name is the name of a class or interface that contains the desired static member. Its full package name is specified by pkg. The name of the member is specified by static-member-name.

The second form of static import imports all static members:
import static package.type-name.*;

If you will be using many static methods or fields defined by a class, then this form lets you bring them into view without having to specify each individually.

For example, this brings the static field System.out into view:
import static java.lang.System.out

After this statement, you can output to the console without having to qualify out with System:

out.println("statically imported name use")

Warning
As convenient as static import can be, it is important not to abuse it. Remember, one reason that Java organizes its libraries into packages is to avoid namespace collisions. When you import static members, you are bringing those members into the current namespace. Thus, you are increasing the potential for namespace conflicts and inadvertent name hiding. If you are using a static member once or twice in the program, it’s best not to import it. Also, some static names, such as System.out, are so recognizable that you might not want to import them. Static import is designed for those situations in which you are using a static member repeatedly, such as when performing a series of mathematical computations. In essence, you should use, but not abuse, this feature.

Q: Using static import, can I import the static members of classes that I create? A: Yes, you can use static import to import the static members of classes and interfaces you create. Doing so is especially convenient when you define several static members that are used frequently throughout a large program. For example, if a class defines a number of static final constants that define various limits, then using static import to bring them into view will save you a lot of tedious typing.

Creating your own packages

1. Pick a name for your package.
You can use any name you wish, but I recommend you follow the established convention of using your Internet domain name (if you have one), only backwards. I own a domain called LoweWriter.com, so I use the name com.lowewriter for all my packages.
(Using your domain name backwards ensures that your package names are unique.)

Notice that package names are in all-lowercase letters. That’s not an absolute requirement, but it’s a Java convention that you ought to stick to. If you start using capital letters in your package names, you’ll be branded a rebel for sure. And since Java is case-sensitive, a package named com.lowewriter is a different package from one named com.LoweWriter.

You can add additional levels beyond the domain name if you want. For example, I put my utility classes in a package named com.lowewriter.util.

If you don’t have a domain all to yourself, try using your e-mail address backwards. For example, if your e-mail address is SomeBody@SomeCompany.com, use com.somecompany.somebody for your package names. That way they are still unique. (If you ever want to distribute your Java packages, you should register a domain name. Nothing says “Amateur” like a package name that starts with com.gmail. And, although a package name created from a backwards e-mail address is almost sure to be unique, there is a small chance that it won’t be.)

2. Choose a directory on your hard drive to be the root of your class library.
You need a place on your hard drive to store your classes. I suggest you create a directory such as c:\javaclasses.
This folder becomes the root directory for your Java packages.

3. Create subdirectories within the root directory for your package name.
For example, for the package named com.lowewriter.util, create a directory named com in the c:\javaclasses directory (assuming that’s the name of your root). Then, in the com directory, create a directory named lowewriter. Then, in lowewriter, create a directory named util. Thus, the
complete path to the directory that contains the classes for the com.lowewriter.util package is c:\javaclasses\com\lowewriter\util.

4. Add the root directory for your package to the ClassPath environment variable.

The exact procedure for doing this depends on your operating system. You can set the ClassPath by double-clicking System from the Control Panel. Click the Advanced tab, and then click Environment Variables. Be careful not to disturb any directories already listed in the ClassPath. Toadd your root directory to the ClassPath, add a semicolon followed by the path to your root directory to the end of the ClassPath value. For example, suppose your ClassPath is already set to this:
.;c:\util\classes
Then you modify it to look like this:
.;c:\util\classes;c:\javaclasses
Here I added ;c:\javaclasses to the end of the ClassPath value.

5. Save the files for any classes you want to be in a particular package in the directory for that package.
For example, save the files for a class that belongs to the com.lowewriter.
util package in c:\javaclasses\com\lowewriter\util.

6. Add a package statement to the beginning of each source file that belongs in a package.

The package statement simply provides the name for the package that any class in the file is placed in. For example:
package com.lowewriter.util;
The package statement must be the first non-comment statement in the file.
Putting Your Classes in a JAR File

A JAR file is a single file that can contain more than one class in a compressed format that the Java Runtime Environment can access quickly. (JAR stands for Java archive.)

JAR files are created by the jar utility, which you find in the Java bin directory along with the other Java command-line tools, such as java and javac. JAR files are similar in format to Zip files, a compressed format made popular by the PKZIP program. The main difference is that JAR files contain a special file, called the manifest file, that contains information about the files in the archive. This manifest is automatically created by the jar utility, but you can supply a manifest of your own to provide additional information about the archived files.

JAR files are the normal way to distribute finished Java applications. After finishing your application, you run the jar command from a command prompt to prepare the JAR file. Then, another user can copy the JAR file to his or her computer. The user can then run the application directly from the JAR file. JAR files are also used to distribute class libraries. You can add a JAR file to the ClassPath environment variable. Then the classes in the JAR file are automatically available to any Java program that imports the package that contains the classes.


jar command-line options

The basic format of the jar command is this:
jar options jar-file [manifest-file] class-files...


Options for the jar Command
Option Description
c     Creates a new jar file.
u     Updates an existing jar file.
x     Extracts files from an existing jar file.
t     Lists the contents of a jar file.
f     Indicates that the jar file is specified as an argument. You almost always want to use this option.
v     Verbose output. This option tells the jar command to display extra information while it works.
0     Doesn’t compress files when it adds them to the archive. This option isn’t used much.
m     Specifies that a manifest file is provided. It’s listed as the next argument following the jar file.
M     Specifies that a manifest file should not be added to the archive. This option is rarely used.

Note that you must specify at least the c, u, x, or t option to tell jar what action you want to perform.
Archiving a package
The most common use for the jar utility is to create an archive of an entire package. The procedure for doing that varies slightly depending on what operating system you’re using. However, the jar command itself is the same regardless of your operating system. Here’s the procedure for archiving a package on a PC running any version of Windows:

1. Open a command window.
The easiest way to do that is to choose Start ➪ Run, type cmd in the Open text box, and click OK. On Windows 8, right-click the Start button, and then choose Command Prompt on the menu that appears.
If you have trouble running the jar command in Step 3, you may need to open the command prompt in Administrator mode. To do so, click the Start menu, type cmd, right-click cmd.exe at the top of the Start menu, and choose Run as Administrator.

2. Use a cd command to navigate to your package root.
For example, if your packages are stored in c:\javaclasses, use this command:
cd \javaclasses

3. Use a jar command that specifies the options cf, the name of the jar file, and the path to the class files you want to archive. For example, to create an archive named utils.jar that contains all the class files in the com.lowewriter.util package, use this command:
jar cf utils.jar com\lowewriter\util\*.class

4. To verify that the jar file was created correctly, use the jar command that specifies the options tf and the name of the jar file. For example, if the jar file is named utils.jar, use this command:
jar tf utils.jar

This lists the contents of the jar file so you can see what classes were added.

Here’s some typical output from this command:
META-INF/
META-INF/MANIFEST.MF
com/lowewriter/util/Console.class
As you can see, the utils.jar file contains the Console class, which is in my com.lowewriter.util package.

5. That’s all!
You’re done. You can leave the jar file where it is, or you can give it to your friends so they can use the classes it contains.
Adding a jar to your classpath

To use the classes in an archive, you must add the jar file to your ClassPath environment variable. I describe the procedure for modifying the ClassPath variable in Windows XP earlier in this chapter, in the section “Creating your own packages.” So I won’t repeat the details here.

To add an archive to the ClassPath variable, just add the complete path to the archive, making sure to separate it from any other paths already in the ClassPath with a semicolon. Here’s an example:
.;c:\javaclasses\utils.jar;c:\javaclasses

Here I added the path c:\javaclasses\utils.jar to my ClassPath variable.

Starting with Java 1.6, you can add all the jar files from a particular directory to the ClassPath in one fell swoop. For example, imagine that your c:\javaclasses directory contains two jar files — utils.jar and extras.jar. To add both jar files to the ClassPath, use a forward slash (/) followed by an asterisk:
.;c:\javaclasses/*
The forward slash looks strange, especially when combined with the back slash in c:\javaclasses. But that’s the way you use a ClassPath wildcard.

The first path in a ClassPath variable is always a single dot (.), which allows Java to find classes in the current directory. Also, be aware that Java searches the various paths and archive files in the Class Path variable in the order in which you list them. Thus, with the ClassPath.;c:\javaclasses\utils.jar;c:\javaclasses, Java searches for classes first in the current directory, then in the utils archive, and finally in the c:\javaclasses directory.


Running a program directly from an archive
With just a little work, you can set up an archive so that a Java program can be run directly from it. All you have to do is create a manifest file before you create the archive. Then, when you run the jar utility to create the archive, you include the manifest file on the jar command line.

A manifest file is a simple text file that contains information about the files in the archive. Although it can contain many lines of information, it needs just one line to make an executable jar file:
Main-Class: ClassName

The class name is the fully qualified name of the class that contains the main method that is executed to start the application. It isn’t required, but it’s typical to use the extension .mf for manifest files. For example, suppose you have an application whose main class is GuessingGame, and all the class files for the application are in the package com.lowewriter.game. First, create a manifest file named game.mf in the com\lowewriter\game directory. This file contains the following line:
Main-Class: com.lowewriter.game.GuessingGame

Then run the jar command with the options cfm, the name of the archive to create, the name of the manifest file, and the path for the class files. Here’s an example:
jar cfm game.jar com\lowewriter\game\game.mf com\lowewriter\game\*.class

Now you can run the application directly from a command prompt by using the java command with the -jar switch and the name of the archive file. Here’s an example:
java -jar game.jar

This command starts the JRE and executes the main method of the class specified by the manifest file in the game.jar archive file. If your operating system is configured properly, you can also run the application by double-clicking an icon for the jar file.
Finding Packages and CLASSPATH

How does the Java run-time system know where to look for packages that you create?

First, by default, the Java run-time system uses the current working directory as its starting point. Thus, if your package is in a subdirectory of the current directory, it will be found. Second, you can specify a directory path or paths by setting the CLASSPATH environmental variable. Third, you can use the -classpath option with java band javac to specify the path to your classes. It is useful to point out that, beginning with JDK 9, a package can be part of a module, and thus found on the module path. However, a discussion of modules and module paths is deferred

In order for a program to find mypack, the program can be executed from a directory immediately above mypack, or CLASSPATH must be set to include the path to mypack, or the -classpath option must specify the path to mypack when the program is run via java. The easiest way to try the examples shown in this chapter is to simply create the package directories below your current development directory, put the .class files into the appropriate directories, and then execute the programs from the development directory. This is the approach used by the following examples. One last point: To avoid problems, it is best to keep all .java and .class files associated with a package in that package’s directory. Also, compile each file from the directory above the package directory.

The base directory is the directory that contains all package directories as well as any classes that are contained in the default package (that is, the package without a name).

Always compile from the base directory so the class file is placed in the correct location.

To run a program, you must start the Java virtual machine in the base directory and specify the full class name of the class that contains the main method.





Modules
Packages were state-of-the-art when Java was first released, but they’ve been showing their age now for several years. For example, developers often have problems managing packages for large applications that use a large numbers of packages, especially when those packages require different versions of Java.

Another problem with packages is that they don’t provide an easy way to create a lightweight application whose runtime contains only those portions of Java that are actually needed. This can limit Java’s ability to run on devices with limited resources, such as embedded controllers or smartphones.

Beginning with JDK 9, an important feature called modules was added to Java. Modules give you a way to describe the relationships and dependencies of the code that comprises an application. Modules also let you control which parts of a module are accessible to other modules and which are not. Through the use of modules you can create more reliable, scalable programs.

Understanding modules
Generally the term module refers to any reusable software component, from an individual method to a complex system consisting of multiple packages.

In its most fundamental sense, a Java module is a grouping of packages and resources that can be collectively referred to by the module’s name.

A module is a new way of grouping classes in a way that explicitly lists which other modules the module depends on and what specific public types (that is, classes and interfaces) within the classes contained in the module are to be made available for other modules to use. To be more specific:

» A module must explicitly list its dependencies — that is, what other modules are required for the module to compile and run. For example, if one or more of the classes in the module require database access, the module must explicitly indicate that it requires the Java database module (known as java.sql).

» A module must also explicitly list the visibility of any packages contained within the module. As you already know, you can create public types within a traditional package, and those public classes are available throughout the package and also externally to the package. With modules, public types in a package are visible outside of the module only if the package is explicitly listed as an exported type.

Like traditional packages, modules are stored in JAR files. A JAR file that contains a module is called a modular JAR file. The only difference between a modular JAR file and a regular JAR file is that a modular JAR file contains a special class called module-info.class. The module-info.class class file identifies the module’s dependencies (that is, what other modules are required) and the packages that are visible to other modules. All this is done by means of a source file called module-info.java.

The module-info.java file
The module-info.java file is a Java source file that defines a module. The module
is defined by using a combination of several new Java language elements that are
introduced by Java 9.
A module declaration specifies the name of a module and defines the relationship a module and its packages have to other modules. Module declarations are program statements in a Java source file and are supported by several module-related keywords added to Java by JDK 9.

exports
module
open
opens
provides
requires
to
transitive
uses
with

It is important to understand that these keywords are recognized as keywords only in the context of a module declaration. Otherwise, they are interpreted as identifiers in other situations. Thus, the keyword module could, for example, also be used as a parameter name, but such a use is certainly not recommended.

A module declaration is contained in a file called module-info.java. Thus, a module is defined in a Java source file. This file is then compiled by javac into a class file and is known as a module descriptor. The module-info.java file must contain only a module definition. It is not a general-purpose file.

A module declaration begins with the keyword module. Here is its general form:
module moduleName {
    //module definition
}

The name of the module is specified by moduleName, which must be a valid Java identifier or a sequence of identifiers separated by periods. The module definition is specified within the braces. Although a module definition may be empty (which results in a declaration that simply names the module), typically it specifies one or more clauses that define the characteristics of the module.

Here is a simple module-info.java file that does creates a module but does not define any dependencies or exported packages:
module com.lowewriter.payroll {}

In this example, the name of the module is com.lowewriter.payroll. Note that modules are named just like packages, typically using the reverse-domain notation. In other words, for this example, I used my own personal domain (lowewriter.com) in reverse, followed by the name of the module.

To specify that the module is dependent on another module, you add a requires statement that specifies the name of the module. For example, if the module will require database access, it will need the standard java.SQL module:

module com.lowewriter.payroll
{
 requires java.SQL;
}
If the module also depends on another module you’ve created named com.lowewriter.util, you would add a requires statement for that module as well:

module com.lowewriter.payroll
{
 requires java.SQL;
 requires com.lowewriter.util;
}

You can also add exports statements to export packages that are contained in the module. When you export a package, any public classes or interfaces within the package are visible to other modules. For example:

module com.lowewriter.payroll
{
 requires java.SQL;
 requires com.lowewriter.util;
 exports com.lowewriter.payrolldb;
}

In this example, any public classes or interfaces defined by the package com.lowewriter.payrolldb are visible to other modules.

Q: Why are the module-related keywords, such as module and requires, recognized as keywords only in the context of a module declaration? A: Restricting their use as keywords to a module declaration prevents problems with preexisting code that uses one or more of them as identifiers. For example, consider a situation in which a pre-JDK 9 program uses requires as the name of a variable. When that program is ported to a modern version of Java if requires were recognized as a keyword outside a module declaration, then any other place in which it is used would result in a compilation error. By recognizing requires as a keyword only within a module declaration, any other uses of requires in the program are unaffected and remain valid. Of course, the same goes for the other module-related keywords. Because they are context-sensitive, the module-related keywords are formally called restricted keywords.


Setting up folders for a module

Getting the source folders set up for a module is similar to setting up the folders
for a package, but with the added requirement that the module-info.java file
must be in the root folder for the module. Typically, the root folder for the module
is named the same as the module, using the dots. For example, the root folder for
the com.lowewriter.payroll module is com.lowewriter.payroll.
The module-info.java file lives within the root folder. In addition, the path to
packages that are a part of the module typically follow the same convention as
for normal packages. Thus, within the module root folder is a folder named com,
within the com folder is a folder named lowewriter, and within the lowewriter
folder is a folder named payroll. The java files for the payroll package are within
the payroll folder.
Assuming that there are two source files for the payroll package (named Address.
java and Employee.java), the complete folder structure including the source files
for the payroll example looks like this:
com.lowewriter.payroll
 module-info.java
 com
 lowewriter
 payroll
 Address.java
 Employee.java
Maybe now the exports command in the module-info.java file makes more
sense:
exports com.lowewriter.payroll;
Notice that the path from the module root to the source files for the package correspond to the package name.

Compiling a module
To compile a module, you can use the javac command from a command prompt,
specifying the name of all the source files you want to compile. First, navigate to
the root folder for the module (in this case, C:\java9\com.lowewriter.payroll).
Then use a javac command like this one:
javac module-info.java com\lowewriter\payroll\*.java

This command will create a module-info.class file in the module’s root folder as
well as .class files for all Java source files in com\lowewriter\payroll. For this
example, two class files will be created in the com\lowewriter\payroll folder:
Address.class and Employee.class.
Creating a modular JAR file
The final step for creating a Java module is to assemble the compiled class files
(including module-info.class) into a module JAR file. You can do that by using
the jar command, like this:
jar cf com.lowewriter.payroll.jar *.class com\lowewriter\payroll\*.class
In this example, cf means to create a Jar file. The cf is followed by the class
files to include. To keep the command simple, I used wildcards to include all the
class files in the module root folder and all the class files in the com\lowewriter\
payroll folder.
You can verify that the Jar file contains the correct contents by running the jar
command with the tf option followed by the name of the Jar file. For example:
C:\Java9\com.lowewriter.payroll>jar tf com.lowewriter.payroll.jar
META-INF/
META-INF/MANIFEST.MF
module-info.class
com/lowewriter/payroll/Address.class
com/lowewriter/payroll/Employee.class
As you can see, the jar tf command indicates that the Jar file contains three
classes as expected: module-info.class and the two com.lowewriter.payroll
classes.
There is a lot more to learn about the Java Module System that’s beyond the scope
of this book, but this should be enough to get you started with it. For more information, search the web for Java Module System. You’ll find plenty of good information from Oracle and other sources about the advanced details of working with
modules for larger applications.


The dependencies between modules should be kept to a minimum.

To guarantee the uniqueness of package names, the inventors of Java recommend that you start a package name with a domain name in reverse (such as com.sun or edu.sjsu.cs), because domain names are guaranteed to be unique. Then use some other mechanism within your organization to ensure that the remainder of the package name is unique as well.









Q: What is a Java program? What do you actually deliver?
A: A Java program is a pile of classes (or at least one class). In a Java application, one of the classes must have a main method, used to start-up the program. So as a programmer, you write one or more classes. And those classes are what you deliver. If the end-user doesn’t have a JVM, then you’ll also need to include that with your application’s classes, so that they can run your program. There are a number of installer programs that let you bundle your classes with a variety of JVM’s (say, for different platforms), and put it all on a CD-ROM. Then the end-user can install the correct version of the JVM (assuming they don’t already have it on their machine.)

Q: What if I have a hundred classes? Or a thousand? Isn’t that a big pain to deliver all those individual files? Can I bundle them into one Application Thing?
A: Yes, it would be a big pain to deliver a huge bunch of individual files to your end-users, but you won’t have to. You can put all of your application files into a Java Archive – a .jar file – that’s based on the pkzip format. In the jar file, you can include a simple text file formatted as something called a manifest, that defines which class in that jar holds the main() method that should run.

Q When a Java class imports an entire package, does it increase the compiled size of that class?
A No. The use of the term import in Java is misleading. The import keyword does not add the code of one class or package to the class you are creating. Instead, it makes it easier to refer to classes within another class. The sole purpose of importing is to shorten the class names when they’re used in Java statements.

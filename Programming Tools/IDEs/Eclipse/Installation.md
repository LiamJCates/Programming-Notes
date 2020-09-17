# Installation

## Setting up a Java SE Development Environment with Eclipse

Eclipse by default doesn't include a toolchain. That may strike you as odd until you remember how many different languages Eclipse can support, and if you only ever want to work in Java, you wouldn't want it installing the C++ toolchains for you.

For Java, this means downloading the JDK for your platform. I'm going to assume you have either already downloaded the Java JDK or you know how to do that.<br/>
Download JDK    https://www.oracle.com/java/technologies
<br/><br/>

Let's quickly take a look at some important areas of the Eclipse site.<br/>
https://www.eclipse.org/getting_started/
<br/>
You can see there are easy navigation aids to get you more plug-ins, documentation for both the IDE User Guide and specific documentation on Java Development, and additional options for getting help.
<br/>
IDE Documentation:    https://help.eclipse.org/2020-03/index.jsp?nav=%2F0
<br/>
Java Documentation:    https://help.eclipse.org/2020-03/index.jsp?nav=%2F1
<br/>
Download Eclipse: https://www.eclipse.org/downloads/packages/
<br/>
Download and install the Eclipse IDE for Java Developers option

## Demo: First Launching of Eclipse

It is very easy to install Eclipse. In fact, you do not need to install it in a Windows way.
All you need to do is to open the zip archive you've downloaded from the Eclipse website and copy the content in any directory you want.

The first thing Eclipse asks us is to choose a directory in which it is going to create the workspace.
The workspace is the directory in which Eclipse is going to create our project.

## Demo: Setting the Right Version of Java to Launch Eclipse

Java virtual machine version 1.8 or greater is required.
If you are on a machine on which you cannot change that version, then you need to do something else. Navigate to your Eclipse installation's top directory and find the eclipe.ini configuration file.

Open it and just before the -vmargs option, type
-VM
and the path to the desired javaw.exe executable file
![javaw file path](https://raw.githubusercontent.com/LiamJCates/Programming-Notes/master/Programming%20Tools/IDEs/Eclipse/Images/configuration.png)

Here we are declaring the jdk1.8 144 subversion. Let us save this file, close this. Relaunch Eclipse Neon, and now we are good to go. Eclipse Neon is launching properly.

## Demo: Updating the Version of a Workspace

If we launch a later version of Eclipse, using the same workspace as an earlier version
We see an older version of Eclipse warning.
inside that workspace in configuration files, the version of Eclipse used to create it has been recorded.
Eclipse can upgrade the workspace for us.
But there is a warning because going back to the old version might lead to loss of information.

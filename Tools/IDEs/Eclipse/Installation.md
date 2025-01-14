# Installation

## Setting up a Java SE Development Environment with Eclipse

Eclipse by default doesn't include a toolchain. That may strike you as odd until you remember how many different languages Eclipse can support, and if you only ever want to work in Java, you wouldn't want it installing the C++ toolchains for you.

For Java, this means downloading the JDK for your platform.
<br/>
Download JDK    https://www.oracle.com/java/technologies
<br/><br/>
I'm going to assume you have either already downloaded the Java JDK or you know how to do that.<br/>
<br/><br/>

Let's quickly take a look at some important areas of the Eclipse site.<br/>
You can find these neatly organized by a helpful getting started page:<br/>
https://www.eclipse.org/getting_started/
<br/><br/>
You will find navigation aids to help you locate
* Plug-Ins: https://marketplace.eclipse.org/
* A User Guide:    https://help.eclipse.org/2020-03/index.jsp?nav=%2F0
* Java Setup:    https://help.eclipse.org/2020-03/index.jsp?nav=%2F1

As well as additional options for getting help.
<br/><br/>

Now, instead of following the download and install option on the getting started page, we want to navigate to a specific package.<br/>
Download Eclipse: https://www.eclipse.org/downloads/packages/
<br/>
Eclipse IDE for Java Developers

## Demo: First Launching of Eclipse

It is very easy to install Eclipse. In fact, you do not need to install it in a Windows way. All you need to do is to open the zip archive you've downloaded from the Eclipse website and copy the content in any directory you want.

The first thing Eclipse asks us is to choose a directory in which it is going to create the workspace. The workspace is the directory in which Eclipse is going to create our project.

## Demo: Setting the Right Version of Java to Launch Eclipse

Java virtual machine version 1.8 or greater is required by Eclipse. If you are on a machine on which you cannot change that version, then you need to do something else. Navigate to your Eclipse installation's top directory and find the eclipe.ini configuration file.
<br/><br/>
Open it and just before the -vmargs option, type:<br/>
-VM and the path to the desired javaw.exe executable file<br/>
![javaw file path](https://raw.githubusercontent.com/LiamJCates/Programming-Notes/master/Programming%20Tools/IDEs/Eclipse/Images/configuration.png)
<br/>
Here we are declaring the jdk1.8 144 subversion. Save and close this file.
<br/><br/>

## Demo: Updating the Version of a Workspace

If we launch a later version of Eclipse, using the same workspace as an earlier version we see an older version of Eclipse warning.
Inside that workspace are configuration files that specify the version of Eclipse used to create it.
Eclipse can upgrade the workspace for us but will throw a warning because going back to the old version might lead to loss of information.

To demonstrate how minimal a Qt project can be and to give us a programming sandpit to
play around in, we’ll create a simple scratchpad project. For this project, we won’t even use
the IDE to do it for us, so you can really see how projects are built up.
First, we need to create a root folder to store all of our Qt projects. On Windows, I use
c:\projects\qt, while I use ~/projects/qt on Linux and Mac OS. Create this folder
wherever works for you.


In our Qt projects folder, create a new folder scratchpad and navigate into it. Create a new plain text file called scratchpad.pro

Next, simply double-click on the file and it will open in Qt Creator:

Here, Qt Creator is asking us how we want our project to be configured, namely, which kits we want to use when building and running our code. Pick one or more available kits and click on Configure Project. You can easily add and remove kits later, so don’t worry about which ones you select.

If you switch back to the filesystem, you will see that Qt Creator has created a new file for us called scratchpad.pro.user. This is just an XML file containing configuration information. If you delete this file and open the .pro file again, you will be prompted to configure the project again. As its name suggests, the configuration settings are relevant to the local user, so often if you load a project created by someone else, you will need to go through the configure project step then too.

With the project successfully configured, you will see the project has been opened, even with a completely empty .pro file. That's about as minimal as a project can get!

Back in the filesystem, create the following plain text files:
main.cpp
main.qml
qml.qrc

I will go through each of these files, explain their purpose, and add their content soon. In a real-world project, we would of course use the IDE to create the files for us.


However, the purpose of
doing it this way is to show you that when you boil it down, a project is just a bunch of text
files. Never be afraid to create and edit files manually. A lot of modern IDEs can confuse
and overcomplicate with menu after menu and never-ending option windows. Qt Creator
may miss some of the advanced bells and whistles of other IDEs but is refreshingly lean and
straightforward.
With those files created, double-click on the scratchpad.pro file in the Projects pane and
we’ll start editing our new project.

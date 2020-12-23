Working with software projects
The term project can be used in two different ways when talking about software development:
  • A collaborative enterprise used to develop the actual program – in other words, as a group of people working together. For that, we need a project plan, a project leader, and so on.

  • A container for all the files that make up the program we develop. It is the latter meaning – a container for all the files that make up a program – that we will discuss here as the former is about project management and not software development.

When our code is broken up into well-defined modules – most likely in the form of several files – we need a way to let the compiler or interpreter find all the files so that they can be assembled into the executable machine code. Creating the correct structure for the project is usually done by tools that programmers use to develop software. These tools come in many categories, but the most advanced form is called an Integrated Development Environment (IDE). The central part of an IDE is the editor that's used to write the code. It will also assist us with creating software projects. A programming language defines how a project shall be organized. This can, for example, be in a form where the different files shall be in relation to each other. Some languages will do this with the help of things called packages.


Working with packages to share code
In software developer culture, sharing code for free is very natural. This makes the industry unique as programmers share and use each other's code all the time. Using someone else's solutions to a problem is as natural as sharing my good ideas and code. It is usually wise to reuse the work of others as the code is often well developed, well tested, and well maintained. In software development, the term open source is well known. It means that someone has an idea for an application, writes the code for it, and then shares it online. Others are then encouraged to help with the development of this project. Several programmers will join in, and together they keep the project going. Everyone interested can then use this code free of charge. 

The code that's developed in such a project is often in the form of one or several modules. If you want to use such a module, you must find it, and then you need to download it. The question is, how we can find it, download it, and make sure it is put in a location so that our application can find it?

Luckily, there is a solution to this: package managers.


Package managers
A package manager is a piece of software that will help us find, download, and install code bundled in packages. It works by storing the code modules, now referred to as packages, in a central location. This central storage is called a repository, or just repo. This means that when you write a program, you can specify the packages necessary for its successful execution. Such a specification directs the package manager to visit the package manager's online repository to retrieve the necessary packages.


Now that we can download the package, we will soon be dealing with another problem. We must make sure that, when naming things in our code, all the names are unique. If not, the program will not run. This can be tricky, especially when using packages that others have written. How do we know that the names we're using are not already being used? The solution is in namespaces

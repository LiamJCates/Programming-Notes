Applications Types

Standalone applications
A standalone application is a program that can work offline, that is, it does not necessarily require a network connection. Therefore, when writing such an application, we will need to provide all the resources the program will require.

These resources can be images, such as icons used in the application, files to store program configuration, and so on. It is usually a rather straightforward affair to create these applications as we will not need to interact with other programs. When learning to write applications, most of your programs will likely fall into this category.  



Client-server applications
Client-server is a model we can use to create distributed applications, which are applications that run on more than one machine. The idea behind the client-server model is that we have at least two computers involved. One acts as the server, and all the others have the role of the client. Clients and servers need to communicate with each other. It is always the client who initiates the communication. Sometimes the server communicates with several clients at once; other times, the server only communicates with a single client at a time. This means that we can use different computers to take care of different parts of an application's responsibility. We can let one computer deal with one aspect of a problem and another computer work on a different aspect of the same problem. These two computers then need to communicate their results, usually to a single computer, which can then assemble the different results into one solution. We can also use this model when we have different roles for different parts of an application. For example, we have one role that is to display data to and get input from a user (user interaction) and another role that is to process and store this data. We can divide these roles so the processing and storing role is done by one computer and the user interaction role by another computer.

Web applications
A web application is a special form of client-server application where we have a client that interacts with a user in the form of a web page. The server is responsible for producing the results the user will see and to accept and process the input from the user.

Mobile applications
When we talk about a mobile application, we usually mean a program that is designed to run on a mobile device, such as a smartphone. These devices have some special characteristics that we need to consider when writing an application. First, their screen is smaller than a computer monitor. The screen can also be rotated in landscape or portrait orientation. We will also use the touchscreen of the device for input. The mobile application might also use other features of the device, such as the GPS, sending text messages, or sensing the movement of the device using its accelerometer. These are things we usually can't do if an application runs on a normal computer. A mobile application can be connected, but it does not have to be. Being connected means that it can communicate with another computer, maybe using the client-server techniques we discussed earlier.



Distributed applications
A distributed application is an application that does not run on one single machine, but instead lets different parts of the program run on multiple computers that communicate with each other over a network. This might sound like the client-server solutions we talked about earlier, but here we don't have the distinct roles of a client and a server. There could be several reasons to use this solution. One may be that what we are doing requires so much computing power that a single computer will not be enough. The idea is to use the computing power of many computers and distribute the calculations to all of them, letting each computer work on a small section of the problem and communicate the results to the other machines in the network. This will give us something of a supercomputer that will act as a very powerful single machine running a single application, when it is actually thousands of computers running small individual parts of the application.

Peer-to-peer networks
A peer-to-peer network, also known as P2P, is a network of computers that are equal participants in the network. Each computer in the network is called a node, or a peer, and they make portions of their resources, such as processing power or disk storage, directly available to other participants in the network. This technique was popularized by filesharing systems such as Napster in the late '90s. A peer in the network is both a supplier and a consumer of resources. This is what makes this solution different from a traditional client-server model in which the supply and consumption of resources are divided between the server and the client


Cloud-based applications
The idea behind cloud-based computing is to move away from the need to host your servers and other resources needed to run your project, and instead buy time from large data centers to use their computing power. There are many advantages to this. You don't have to make sure that your computers are up and running, that operating systems are updated, that you have implemented back-up solutions for your data, and so on. You can set up your server to be online, and then you can deploy your software on this server and run it from there. The companies providing these services soon began to add other features that we can use as well. These are ready-made parts that we can use in our applications. What this means is that there will be parts of our application that we won't need to write ourselves. Instead, we can buy these ready-made parts from the provider and integrate them into our application that will run on a server, also provided by them. There are many variations of this: we can buy a server, we might only buy storage, or we might buy one or more services that we will use, and these can then be combined in any way we want.



Systems software
The software in this category helps the user, applications, and computer hardware to interact and function together. These applications create an environment that other programs can work in. When a computer is powered on, the first thing that is loaded into the computer's memory is system software applications. They will mostly run in the background, even if some of them can have a visual user interface. Because these programs work directly with the computer's hardware, they are often referred to as low-level software.



Programming software
In this category, we find the tools and applications used by programmers when they write and test software. First, we need the programs that are the actual language the programmers use. To be able to write a program in C++, Java, Python, or any other language, we must first install the software that will take care of the translation of the source code into machine code. A programmer often uses specialized text editors that will assist them when writing code. Some programs are even more advanced and will provide not only an editor for writing the code but a range of other built-in tools that are useful to have access to when writing programs. These are called Integrated Development Environments (IDEs). An example of a built-in tool is a debugger, which is a program that will help the programmer to find errors in the code.



Serverless applications
A serverless application is a specialized variant of cloud-based applications. It can come in several different forms. Common to all these variants is that the cloud provider runs the servers needed, and dynamically manages all the resources the application needs. What this means is that we, for example, will not need to buy storage of a fixed size. The provider will add more storage as we need it, and we will pay for the storage we use. We can compare this to a scenario where if our hard disk is full, it just keeps increasing its storage capacity to meet our needs for more space. This kind of software is interesting if you want to automate the maintenance of servers, storage, and other aspects of your infrastructure. These solutions are intelligent, so they can adapt to changes, for example, by giving us more storage when we need and reducing it again when the need drops.

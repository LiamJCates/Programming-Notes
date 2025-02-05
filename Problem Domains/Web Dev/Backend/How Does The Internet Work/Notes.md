The Internet is a global network of computers which communicate through a standardized set of protocols.

Began in the 1960s as a US-army-funded research project by the United States Department of Defense as a means of creating a decentralized communication network that could withstand a nuclear attack. 

The Internet transitioned into a public infrastructure in the 1980s with the support of many public universities and private companies.

Over the years, it has evolved into a complex and sophisticated network that spans the globe.
Though the various technologies that support the Internet have evolved over time, the way it works hasn't changed much: Internet is a way to connect computers and ensure that, whatever happens, they find a way to stay connected.



### Intro to the Internet

The Internet is the backbone of the World Wide Web, the technical infrastructure that makes accessing the Web possible. 

At its most basic, the Internet is the largest network of computers ever made.

A computer network is a system that links two or more computing devices, enabling information transfer or communication through the transmission of data.

When two computers communicate, at minimum, they must be linked via some types of transmission media.

[Website Development\WebBasics\internet-schema-1.png]

Such a basic network is not limited to two computers. You can connect as many computers as you wish. However things get complicated quickly. To connect ten computers, you need 45 cables, with nine plugs per computer!

[Website Development\WebBasics\internet-schema-2.png]

To solve this problem, each computer on a network is connected to a computer called a router. This router has only one job: like a signaler at a railway station, it makes sure that a message sent from a given computer arrives at the right destination computer. To send a message to computer B, computer A must send the message to the router, which in turn forwards the message to computer B and makes sure the message is not delivered to computer C.

Once we add a router to the system, our network of 10 computers only requires 10 cables: a single plug for each computer and a router with 10 plugs.

[Website Development\WebBasics\internet-schema-3.png]

A single router cannot scale to connect billions of computers.
But a router is a computer like any other, so we can connect routers together.
By connecting computers to routers, then routers to routers, we are able to scale.

Anywhere two or more parts of the internet intersect there's a router.
Every time you visit a website upwards of ten to fifteen routers may help data find its way to and from your computer

[Website Development\WebBasics\internet-schema-4.png]

Such a network comes very close to what we call the Internet, but we're missing something. We built that network for our own purposes. There are other networks out there: your friends, your neighbors, anyone can have their own network of computers. But it's not really possible to set cables up between your house and the rest of the world, so how can you handle this? Well, there are already cables linked to your house, for example, electric power and telephone. The telephone infrastructure already connects your house with anyone in the world so it is the perfect wire we need. To connect our network to the telephone infrastructure, we need a special piece of equipment called a modem. This modem turns the information from our network into information manageable by the telephone infrastructure and vice versa.

[Website Development\WebBasics\internet-schema-5.png]

So we are connected to the telephone infrastructure. The next step is to send the messages from our network to the network we want to reach. To do that, we will connect our network to an Internet Service Provider (ISP). An ISP is a company that manages some special routers that are all linked together and can also access other ISPs' routers. So the message from our network is carried through the network of ISP networks to the destination network. The Internet consists of this whole infrastructure of networks

[Website Development\WebBasics\internet-schema-6.png]

The internet is a network of networks, made up of an incredibly large number of independently operated segments. 

It links billions of devices together all around the globe. So maybe you’re connected with a laptop or a phone through wifi, but then that wifi connection connects to an ISP connects you to billions and billions of devices around the world through hundreds of thousands of networks that are all interconnected.

The system is fully distributed. There’s no central control that’s deciding how data is routed or where pieces of network are built, 
or even who interconnects with whom. These are all business decisions that are made independently by the operators. They are all motivated to assure that there is end-to-end connectivity of every part of the network, because the utility of the net is that any device can communicate with any other device, just like you want to be able to make phone calls to any other telephone in the world. 








One thing that most people do not appreciate is that the internet is really a design philosophy and an architecture expressed in a set of protocols. A protocol is a well-known set of rules and standards that, if all parties agree to use it, will allow them to communicate without trouble. 

One of the key benefits of using standardized protocols is that they allow devices and systems from different manufacturers and vendors to communicate with each other seamlessly. For example, a web browser developed by one company can communicate with a web server developed by another company, as long as they both adhere to the HTTP protocol.

How the internet actually physically works is less important than the fact that this design philosophy has allowed the internet to adapt and absorb new communication technologies. This is because in order for a new technology to use the internet in some fashion, it just 
needs to know which protocols to work with. 

Internet protocols define how information is exchanged between devices and ensure that data is transmitted reliably and securely.

To ensure that data packets are sent and received correctly, the internet uses a variety of protocols, including the Internet Protocol (IP) and the Transmission Control Protocol (TCP). IP is responsible for routing packets to their correct destination, while TCP ensures that packets are transmitted reliably and in the correct order.

In addition to the core IP/TCP protocols, there are a wide range of other technologies and protocols that are used to enable communication and data exchange over the internet, including the Domain Name System (DNS), the Hypertext Transfer Protocol (HTTP), and the Secure Sockets Layer/Transport Layer Security (SSL/TLS) protocol. 


Keyterms

  Packet: A small unit of data that is transmitted over the internet.
  Router: A device that directs packets of data between different networks.
  IP Address: A unique identifier assigned to each device on a network, used to route data to the correct destination.
  Domain Name: A human-readable name that is used to identify a website, such as google.com.
  DNS: The Domain Name System is responsible for translating domain names into IP addresses.
  HTTP: The Hypertext Transfer Protocol is used to transfer data between a client (such as a web browser) and a server (such as a website).
  HTTPS: An encrypted version of HTTP that is used to provide secure communication between a client and server.
  SSL/TLS: The Secure Sockets Layer and Transport Layer Security protocols are used to provide secure communication over the internet.




Packets

The core of the internet is a global network of interconnected routers, which are responsible for directing traffic between different devices and systems. 

Whenever data travels across the internet, computers break the information into smaller, ordered pieces called packets.

When information reaches its destination the packets are reassembled in their original order to make a picture, email, web page, etc...

Packets are sent from devices to a router. The router examines the packet and forwards it to the next router in the path towards its destination. This process continues until the packet reaches its final destination.

Information transfer on the Internet from one computer to another does not need to follow a fixed path; in fact, it may change paths during the transfer.




Network Hosts

A computing device connected to, or "on", a network is known as a host.

A host sending data over, or distributing data onto a network is known as a transmitter or source.
A host obtaining data from, or accepting communication over a network is known as the receiver or destination.

Network hosts can be further divided into specialized categories based on their role on the network

A server is a computer connected directly to the Internet

Servers provide data, services, or applications to other hosts on the network. 
For example, web pages are files on server hard drives.


A client is a host indirectly connected to the internet via an ISP, they're not connected directly to the Internet.

A client is responsible for interacting with users. Clients send requests to a server, which processes these requests, performs necessary tasks to generate a response, and returns the response to the client. The client receives the server's response, displays the results to the user, and awaits the users next request.


IP

To communicate to a network host, we specify which one. 

Every network host has a unique address that identifies it, called an "IP address" (where IP stands for Internet Protocol).
similar to a unique postal address

IP v4: 32 bit 4 byte
[0-255].[0-255].[0-255].[0-255]

IP v6: 128 bit 8 byte
[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF]


These numbers are arranged in a hierarchy 

The earlier numbers usually identify the country and regional network of the device. 
Then come the subnetwork, and finally the address of the specific device.

IPv4 was designed in 1973 and widely adopted in the early 80s 
and provides for more than 4 billion unique addresses for devices connecting to the internet. 


A longer IP address format called IPv6 which uses 128 bits per address and provides over 340 undecillion unique addresses. 
That’s more than enough for every grain of sand on Earth to have its own IP address. 


To traverse the internet each packet is wrapped in several layers
the first layer is your computer's IP address
your computer sends the packet to the first router which adds its own IP address then sends it to the next router
each time the packet reaches a new router another layer is added until it reaches the destination, like a web server

when the server sends back information it creates packets with an identical wrapping
as the packet makes its way over the internet back to your computer, each router unwraps a layer to discover where to send the response next until it reaches your computer



DNS 

To make things easier, we can alias an IP address with a human readable name called a domain name.
Since 72.14.205.100 doesn't roll off the tongue we also give them Domain Names like google.com or facebook.com

As you might notice, when we browse the Web with a Web browser, we usually use a name to reach a website. 


A system called the “domain name system” (or DNS) associates names like www.example.com with the corresponding addresses.  uses the DNS to look up domain names and get the associated IP address, which is used to connect your computer to the destination on the internet.

One DNS server can't handle requests from all devices. 
DNS servers are connected in a distributed hierarchy and are divided into zones, 
splitting up responsibility for the major domains such as .org, .com, .net, etc.

(That goes a little somethin’ like this!) 
Client: Hey, hi there, I want to go to www.code.org. 

DNS Server 1: Mm… yeah I don’t know the, uh— the IP address for that domain; let me ask around. 
Hey, do you know how to get to, uh, code.org? 

DNS Server 2: Yeah, I got it right here; 
it’s a 174.129.14.120. 

DNS Server 1: Oh, okay, great. 
Thanks. Yeah I’m gonna— I’m gonna write that down and save it for later in case I need it. Hey, 
here’s that address you wanted.

Client: Awesome! Thank you. 


DNS was originally created to be an open and public communication protocol for government and educational institutions.



TCP/IP (Transmission Control Protocol/Internet Protocol) is the underlying communication protocol used by most internet-based applications and services. It provides a reliable, ordered, and error-checked delivery of data between applications running on different devices.

When building applications with TCP/IP, there are a few key concepts to understand:

    Ports: Ports are used to identify the application or service running on a device. Each application or service is assigned a unique port number, allowing data to be sent to the correct destination.
    Sockets: A socket is a combination of an IP address and a port number, representing a specific endpoint for communication. Sockets are used to establish connections between devices and transfer data between applications.
    Connections: A connection is established between two sockets when two devices want to communicate with each other. During the connection establishment process, the devices negotiate various parameters such as the maximum segment size and window size, which determine how data will be transmitted over the connection.
    Data transfer: Once a connection is established, data can be transferred between the applications running on each device. Data is typically transmitted in segments, with each segment containing a sequence number and other metadata to ensure reliable delivery.

When building applications with TCP/IP, you’ll need to ensure that your application is designed to work with the appropriate ports, sockets, and connections. You’ll also need to be familiar with the various protocols and standards that are commonly used with TCP/IP, such as HTTP, FTP (File Transfer Protocol), and SMTP (Simple Mail Transfer Protocol). Understanding these concepts and protocols is essential for building effective, scalable, and secure internet-based applications and services.



HTTP

HTTP (Hypertext Transfer Protocol) and HTTPS (HTTP Secure) are two of the most commonly used protocols in internet-based applications and services.

HTTP is the protocol used to transfer data between a client (such as a web browser) and a server (such as a website). When you visit a website, your web browser sends an HTTP request to the server, asking for the webpage or other resource you’ve requested. The server then sends an HTTP response back to the client, containing the requested data.

HTTPS is a more secure version of HTTP, which encrypts the data being transmitted between the client and server using SSL/TLS (Secure Sockets Layer/Transport Layer Security) encryption. This provides an additional layer of security, helping to protect sensitive information such as login credentials, payment information, and other personal data.

When you visit a website that uses HTTPS, your web browser will display a padlock icon in the address bar, indicating that the connection is secure. You may also see the letters “https” at the beginning of the website address, rather than “http”.



SSL/TLS

SSL/TLS is a protocol used to encrypt data being transmitted over the internet. It is commonly used to provide secure connections for applications such as web browsers, email clients, and file transfer programs.

When using SSL/TLS to secure internet communication, there are a few key concepts to understand:

    Certificates: SSL/TLS certificates are used to establish trust between the client and server. They contain information about the identity of the server and are signed by a trusted third party (a Certificate Authority) to verify their authenticity.

    Handshake: During the SSL/TLS handshake process, the client and server exchange information to negotiate the encryption algorithm and other parameters for the secure connection.

    Encryption: Once the secure connection is established, data is encrypted using the agreed-upon algorithm and can be transmitted securely between the client and server.

When building internet-based applications and services, it’s important to understand how SSL/TLS works and to ensure that your application is designed to use SSL/TLS when transmitting sensitive data such as login credentials, payment information, and other personal data. You’ll also need to ensure that you obtain and maintain valid SSL/TLS certificates for your servers, and that you follow best practices for configuring and securing your SSL/TLS connections. By doing so, you can help protect your users’ data and ensure the integrity and confidentiality of your application’s communication over the internet.










As described above, the Internet is a technical infrastructure which allows billions of computers to be connected. Among those computers, some computers (called Web servers) can send messages intelligible to web browsers. The Internet is an infrastructure, whereas the Web is a service built on top of the infrastructure.


Servers can be web servers, cloud servers, virtual hosts, providing services to computers over the internet or part of a mainframe computer environment, providing services to attached workstations.

A web service is a software application that allows different computer systems to communicate with each other over the internet using standardized protocols, enabling them to exchange data and perform functions regardless of the programming language or platform they are built on

web server
A computer that hosts a website on the Internet. 

web page
A document which can be displayed in a web browser such as Firefox, Google Chrome, Opera, Microsoft Internet Explorer or Edge, or Apple's Safari. These are also often called just "pages."

website
A collection of web pages which are grouped together and usually connected together in various ways. Often called a "web site" or simply a "site."



search engine
A web service that helps you find other web pages, such as Google, Bing, Yahoo, or DuckDuckGo. Search engines are normally accessed through a web browser (e.g. you can perform search engine searches directly in the address bar of Firefox, Chrome, etc.) or through a web page.

https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_web_server






The web works by displaying HTML, styling it with CSS, and adding interaction with JavaScript.


World Wide Web: an open information system populated with resources reached through URLs.

Unique Resource Locators: (URLs) provide unique addresses to those resources so that your browser can access them

Packet switching: the technique for dividing information into message blocks that each get routed separately, and assembled on the other side. The distributed nature and error correction allowed by packet switching make communication across the internet possible.


The HTTP protocol takes care of the information communication between the web browser and the web server to deliver documents so that the web browser can render it on the screen.



Big Idea:
The World Wide Web is an information space where documents and other web resources are identified by Unique Resource Locators, or URLs, interlinked by hypertext links and can be accessed by the internet.

web basic ingredients:
 resources, like HTML documents, images, or other files. This is the content that we want to use, websites that we want to browse, images to look at, files that we want to share.
 URLs uniquely identify the resources so that your web browser can ultimately show them to you or download them. Every resource on the web has a unique URL.
 Hypertext Transfer Protocol, or HTTP. This is the communication protocol that defines how documents are transferred between networked devices.

How it works:
 Documents, like HTML documents and other resources like images, are hosted by web servers.
 Web servers are computers that run special software to serve up documents and other resources.
 The web server will have a unique address on the internet, a URL.
 Example: server.com
 All resources hosted by a given server will have unique names related to that server
 Example: server.com/document1.html.
 You can use these resources from a client computer that has a web browser installed on it, like Internet Explorer or Google Chrome.
 Nowadays, there are many types of client PCs that have web browsers, desktop computers, mobile phones or even virtual reality headsets.


Web browsers use the HTTP GET operation to ask the internet to serve up a specific document that lives at the address of a given URL.
Whilst rendering an HTML document on the screen, a web browser uses CSS and JavaScript to style the document and give it functionality.
A web browser doesn't only get documents from a server, sometimes it sends documents back to the server for processing using an HTTP POST operation.

Now this is a very simplified view of how the web works. There is much more going on, like domain name server calls and TCP/IP protocol handshakes, but that is beyond the scope of this document











According to the OSI model, the layers of the internet are: 
Physical Layer
Data Link Layer (Link Layer)
Network Layer
Transport Layer
Session Layer
Presentation Layer
Application Layer

The Application Layer being the topmost layer closest to the user and the Physical Layer being the lowest level responsible for physical transmission of data


A brief description of each layer of the OSI Model:

1. **Physical Layer**: This is the lowest layer of the OSI model and is responsible for the physical connection between devices. It deals with the transmission and reception of raw bit streams over a physical medium (e.g., cables, switches).

2. **Data Link Layer**: This layer is responsible for node-to-node data transfer and error detection and correction. It ensures that data transferred is free of errors. It includes protocols like Ethernet and PPP.

3. **Network Layer**: This layer is responsible for determining the best physical path for data to reach its destination. It handles packet forwarding, including routing through different routers. Protocols like IP (Internet Protocol) operate at this layer.

4. **Transport Layer**: This layer ensures complete data transfer. It provides error recovery and flow control. Protocols like TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) operate at this layer.

5. **Session Layer**: This layer manages sessions between applications. It establishes, manages, and terminates connections between local and remote applications.

6. **Presentation Layer**: This layer translates data between the application layer and the network format. It is responsible for data encryption, compression, and translation.

7. **Application Layer**: This is the topmost layer and is closest to the end user. It provides network services directly to applications. Protocols like HTTP, FTP, SMTP, and DNS operate at this layer.





Protocols

TCP/IP



When you request a webpage, your device sends a data packet through your internet service provider (ISP) to a Domain Name System (DNS) server, which translates the website’s domain name into an IP address. The packet is then routed across various networks (using routers and switches) to the destination server, which processes the request and sends back the response. This back-and-forth exchange enables the transfer of data like web pages, emails, and files, making the internet a dynamic, decentralized system for global communication.
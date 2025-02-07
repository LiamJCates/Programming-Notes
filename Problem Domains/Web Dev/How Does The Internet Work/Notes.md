# Intro to the Internet

The Internet is a global network of computers which communicate through a standardized set of protocols.

Though the various technologies that support the Internet have evolved over time, the way it works hasn't changed much: Internet is a way to connect computers and ensure that, whatever happens, they find a way to stay connected.

## Intro to Internet Infrastructure

### Keyterms

    Internet: the technical infrastructure composing the largest computer network in the world
    Network: a group of devices that are connected and share data
    Transmission media: a communication channel, wired or wireless, that carries data across a network
    Switch: A device that directs data between physically connected devices on the same network
    Access Point: A device that directs data between wirelessly connected devices on the same network
    Router: A device that directs data between different networks.
    Modem: connects local networks to the internet by translating digital signals into analog signals to be transmitted to an ISP
    ISP: a company that provides internet access to consumers and businesses
    Host: A computing device connected to, or "on", a network.
    Topology: physical and logical arrangement of network connections on a network
    Server: A Host that provides information or services on a network
    Client: A Host that requests information or services on a network
    Client–Server model: distributed application structure that partitions tasks or workloads between service providers and requesters.
    Distributed System: a collection of independent computers that work together across a network to achieve a common goal
    Decentralized Network: a network where control and data are spread out across many points, rather than managed by a single authority
    Internet Engineering Task Force: organization that manages open standards that assist in ensuring the internet remains efficient

### How Computers are Linked

At its most basic, the Internet is the largest computer network ever.

A computer network is a system that links two or more computing devices.
Networks enable information transfer or communication through the transmission of data between devices.

#### Transmission Media

Transmission media refer to the pathways through which data is shared from one device to another, within a network. 
Transmission media are either physical or wireless.
All transmission media harnesses some form of signal propagation.
Physical transmission media generally propagate signal energy over some type of cable.
Wireless transmission media generally consists of a transmitter sending and receiver responding to an electromagnetic wave.

### How The Internet Is Organized

When two computers communicate, at minimum, they must be linked via some transmission media.

[Website Development\WebBasics\internet-schema-1.png]

Such a basic network is not limited to two computers. 
You can connect as many computers as you wish, however things get complicated quickly.
To connect ten computers, you need 45 cables, with nine plugs per computer!

[Website Development\WebBasics\internet-schema-2.png]

To solve this problem, each computer on a network is connected to a computer called a router. This router has only one job: like a signaler at a railway station, it makes sure that a message sent from a given computer arrives at the right destination computer. To send a message to computer B, computer A must send the message to the router, which in turn forwards the message to computer B and makes sure the message is not delivered to computer C.

Once we add a router to the system, our network of 10 computers only requires 10 cables: a single plug for each computer and a router with 10 plugs.

[Website Development\WebBasics\internet-schema-3.png]

A single router cannot scale to connect billions of computers.
But a router is a computer like any other, so we can connect routers together.
By connecting computers to routers, then routers to routers, we are able to scale.

Borrowing hardware from the telephone industry, connections within the same geographical location are often managed by switches.
Person computers may be connected directly to a router or may be connected to a network switch that is then connected to a router.
A network switch connects devices within a local area and forwards data to and from those devices and the router.

As technology has evolved and wireless connection became possible, another piece of hardware, the access point was developed.
Computers are connected physically to a switch via copper cables.
Computers are connected wirelessly to an access point via radio waves.

However, anywhere two or more networks intersect there's a router.
Every time you visit a website upwards of ten to fifteen routers may help data find its way to and from your computer.

[Website Development\WebBasics\internet-schema-4.png]

Such a network comes very close to what we call the Internet, but we're missing something. It's not really possible to set cables up between your house and the rest of the world, so how can you handle this? Hardware is again borrowed from the telephone industry, telecom infrastructure already connects your house with anyone in the world. To connect our network to the telephone infrastructure, we need a special piece of equipment called a modem. This modem turns the information from our network into information manageable by the telephone infrastructure and vice versa.

![](Website Development\WebBasics\internet-schema-5.png)

So we are connected to the telephone infrastructure. The next step is to send the messages from our network to the network we want to reach. To do that, we will connect our network to an Internet Service Provider (ISP). An ISP is a company that manages some special routers that are all linked together and can also access other ISPs' routers. So the message from our network is carried through the network of ISP networks to the destination network. The Internet consists of this whole infrastructure of networks.

[Website Development\WebBasics\internet-schema-6.png]

The Internet is a vast, sprawling network of networks, an incredibly large number of independently operated segments. 
In fact, the word "Internet" could be said to come from this concept: interconnected networks.


### Hosts

A network host, or simply a host, is a device connected to a computer network, assigned at least one network address.
A computer participating in networks that use the Internet Protocol suite may be referred to as an IP host. 
Specifically, computers participating in the Internet are called Internet hosts.

Network hosts can be further divided into specialized categories based on their role on the network

#### Server 

A server is a computer connected directly to the Internet
Servers provide data, services, or applications to other hosts on the network. 
For example, web pages are files on server hard drives.
This data can be sent out to whichever hosts the server happens to be serving.

#### Client

A client is a host indirectly connected to the internet via an ISP.
A client is responsible for interacting with end users. 

Once a connection is established, data can be transferred between the applications running on each device.
Clients send requests to a server, which processes these requests, performs necessary tasks to generate a response, and returns the response to the client. The client receives the server's response, displays the results to the user, and awaits the users next request.


### Where is the internet?

The internet has three basic parts:

#### The last mile
the part of the internet that connects homes and small businesses to the internet. Currently, about 60 percent of residential internet connections in the United States are provided by cable TV companies such as Comcast and Time Warner. Of the remaining 40 percent, a growing fraction use new fiber optic cables, most of which are part of Verizon's FiOS program or AT&T's U-Verse. Finally, a significant but shrinking number use outdated DSL service provided over telephone cables.
The last mile also includes the towers that allow people to access the internet with their cell phones. Wireless internet service accounts for a large and growing share of all internet usage.

#### Data centers
rooms full of servers that store user data and host online apps and content. Some are owned by large companies such as Google and Facebook. Others are commercial facilities that provide service to many smaller websites. Data centers have very fast internet connections, allowing them to serve many users simultaneously. Data centers can be located anywhere in the world, but they are often located in remote areas where land and electricity are cheap. For example, Google, Facebook, and Microsoft have all constructed vast data centers in Iowa.

#### The backbone 
consists of long-distance networks — mostly on fiber optic cables — that carry data between data centers and consumers. The backbone market is highly competitive. Backbone providers frequently connect their networks together at Internet Exchange Points, usually located in major cities. Establishing a presence at IEPs makes it much easier for backbone providers to improve their connections to others.


### Who runs the internet?

No one runs the internet. It's organized as a decentralized network of networks. Thousands of companies, universities, governments, and other entities operate their own networks and exchange traffic with each other based on voluntary interconnection agreements.

Began in the 1960s as a US-army-funded research project by the United States Department of Defense as a means of creating a decentralized communication network that could withstand a nuclear attack. 

In the 1980s the Internet transitioned into a public infrastructure with the support of many public universities and private companies.

Today, the system is fully distributed. There's no central control that's deciding how data is routed or where pieces of network are built, 
or even who interconnects with whom. These are all business decisions that are made independently by the operators. They are all motivated to assure that there is end-to-end connectivity of every part of the network, because the utility of the net is that any device can communicate with any other device, just like you want to be able to make phone calls to any other telephone in the world. 

The Internet's distributed nature makes it resilient. Any computer or hardware that can send and receive data in the correct fashion (e.g. using the correct networking protocols) can be part of the Internet. Pieces of networking hardware connect and disconnect from the Internet all the time without impacting how the Internet functions — unlike a computer, which may not function at all if it is missing a component. This applies even at a large scale: if a server, an entire data center, or an entire region of data centers goes down, the rest of the Internet can still function (if more slowly).

The shared technical standards that make the internet work are managed by an organization called the Internet Engineering Task Force. The IETF is an open organization; anyone is free to attend meetings, propose new standards, and recommend changes to existing standards. No one is required to adopt standards endorsed by the IETF, but the IETF's consensus-based decision-making process helps to ensure that its recommendations are generally adopted by the internet community.





## Intro to Network Protocols

### Keyterms

  Protocol: a set of rules that govern the format and methods by which data is transmitted.
  Packet: A most basic unit of data transmitted over a network
  Internet Protocol (IP): An addressing protocol that routes data packets through networks, from source to destination
  IP Address: A unique identifier assigned to each device on a network.
  DHCP: Network management protocol used to automate the process of configuring devices on IP networks.
  MAC address: permanent, unique identifier assigned to a network interface card (NIC) or network adapter a device uses to connect to a LAN.
  LAN: A local network segment where connected devices communicate with each other without needing to pass through a router.
  ARP: Network communication protocol that matches IP addresses to MAC addresses.
  Domain Name: A human-readable name that is used to identify a website, such as google.com.
  DNS: The Domain Name System is responsible for translating domain names into IP addresses.


### What are Protocols

Connecting two computers, both of which may use different hardware and run different software, is one of the main challenges that the creators of the Internet had to solve. It requires the use of communications techniques that are understandable by all connected computers, just as two people, who may have little in common otherwise, can speak a common language to understand each other.

This problem is solved with protocols. 

In networking, a protocol is a standardized way of formatting and transmitting data so that any connected devices are able to communicate with and understand each other.

One of the key benefits of using standardized protocols is that they allow devices and systems from different manufacturers and vendors to communicate with each other seamlessly.

To ensure that data is sent and received correctly, the internet uses a variety of protocols.
Because all Internet-connected computers and other devices can interpret and understand these protocols, the Internet works no matter who or what connects to it.

The internet is really a design philosophy and an architecture expressed in a set of protocols. 

How an individual segment of the internet is physically structured is less important than the fact that this design philosophy has allowed the internet to adapt and absorb new communication technologies. This is because in order for a new technology to use the internet in some fashion, it just needs to know a specified set of protocols. 



###  Internet Protocol (IP)

To communicate between devices on a network, we specify what to transfer between them and which computers to transfer between.

#### Packets

A network packet is the unit of data carried by a packet-switched network.

Instead of transferring files as single, uninterrupted data blocks, sending it in smaller packets enables computers to share connections.

Each packet is treated as an independent entity, unaffected by the other packets it is transmitted alongside.

Packets from simultaneous connections are interspersed, to support concurrent connections.

If there is a problem with the transmission of one or more packets, only those packets are retransmitted, rather than the entirety of a larger file.

#### Packet Structure

A packet has two parts, header and payload.
The packet header contains information, known as metadata, that helps the packet get to its destination.
The payload is the actual data being transmitted. 
The payload is encapsulated within the packet and follows the header.
This can be any type of data, such as part of an email, a web page, a video stream, or any other type of digital information. 

#### IP Address

Every network host has a unique address that identifies it, called an "IP address".
similar to a unique postal address used by the postal service.

IP addresses have a uniform format.

These numbers are arranged in a hierarchy 
The earlier numbers usually identify the country and regional network of the device. 
Then come the subnetwork, and finally the address of the specific device.

The source IP address determines where data originates from.
The destination IP address determines where the data is intended to travel.
Each packet keeps track of it's source IP and destination IP in their header.


### Dynamic Host Configuration Protocol (DHCP)

If connected to the Internet, a host has a unique IP address.

If you connect to the Internet through an Internet Service Provider (ISP), you are usually assigned a temporary IP address for the duration of your session. 

Dynamic IPs are obtained from a DHCP (Dynamic Host Configuration Protocol) server.

DHCP is a network management protocol used to automate the process of configuring devices on IP networks. 


### Address Resolution Protocol (ARP)

Address Resolution Protocol (ARP) is a network communication protocol that matches IP addresses to MAC addresses.

A MAC (Media Access Control) address is a unique identifier assigned to a network interface card (NIC) or network adapter. 
MAC addresses identify devices within a local network segment.

A local network segment is a portion of a local area network (LAN) where devices are directly connected and can communicate with each other without needing to pass through a router.

ARP allows devices on a local network segment to communicate with each other. 

ARP translates the IP address into a MAC Address
This translation is necessary because IP addresses change frequently, while MAC addresses are permanent.

ARP helps ensure that data is routed to the correct device on a network. 

Without ARP, devices on the same network would not be able to communicate with each other.


### DNS 

To reach a website, we usually remember its name. 

While each server has a unique IP address, since 72.14.205.100 doesn't roll off the tongue, we give them Domain Names like google.com.
That is, we alias an IP address with a human readable domain name.

A domain or domain name is a unique, symbolic name or term for a specific area or sever on the internet. 
This name is entered by the end-user to access a specific website.

The Domain Name System (DNS) associates domain name with the corresponding IP addresses
like a phonebook associates names to phone numbers.














 

### TCP

#### Keyterms

 Ports: Ports are used to identify the application or service running on a device. 
 Sockets: A socket is a combination of an IP address and a port number, representing a specific endpoint for communication. Sockets are used to establish connections between devices and transfer data between applications.
 Connections: A connection is established between two sockets when two devices want to communicate with each other. 


#### What is TCP 

TCP/IP (Transmission Control Protocol/Internet Protocol) is the underlying communication protocol used by most internet-based applications and services. TCP provides a reliable, ordered, and error-checked delivery of data between applications running on different devices.

IP is the primary way in which network connections are made, and it establishes the basis of the Internet. IP does not handle packet ordering or error checking. Such functionality requires another protocol, often the Transmission Control Protocol (TCP).

IP is a connectionless protocol, which means that each unit of data is individually addressed and routed from the source device to the target device, and the target does not send an acknowledgement back to the source. 

That's where the TCP protocol comes in. 
TCP is used in conjunction with IP in order to maintain a connection between the sender and the target and to ensure packet order and integrity.

TCP is a connection-oriented protocol that establishes a connection between two hosts before transmitting any data. All data sent over a TCP connection is checked for accuracy and retransmitted until the data is received correctly. This reliability makes TCP well-suited for applications that require a high degree of error-checking and for large data transfers. 

TCP can be thought of as the puzzle assembler on the other side who puts the pieces together in the right order, asks for missing pieces to be resent, and lets the sender know the puzzle has been received. TCP maintains the connection with the sender from before the first puzzle piece is sent to after the final piece is sent.

Think of it like a guaranteed mail service. 
When you request data on your device, servers send many packets. 
When your packets arrive, TCP does a full inventory and sends back acknowledgments of each packet received. 
If all packets are there, TCP signs for your delivery and you're done.
If TCP finds some packets are missing, it requests each missing or incomplete packet again. 
This continues until TCP verifies the delivery of all packets.

The email message is broken into packets before each packet is sent out into the Internet. 
Upon arriving at the target device, the group of packets are reassembled by TCP into the original contents of the email.

#### ports, sockets, and connections:

##### Ports
- **Description**: Ports are numerical identifiers used to distinguish different services or applications running on a device. They range from 0 to 65535.
- **Function**: Ports help direct incoming data to the correct application. For example:
  - **HTTP**: Typically uses port 80.
  - **HTTPS**: Typically uses port 443.
  - **FTP**: Typically uses ports 20 and 21.
- **Types**:
  - **Well-Known Ports**: Range from 0 to 1023 and are assigned to common protocols and services (e.g., HTTP, FTP).
  - **Registered Ports**: Range from 1024 to 49151 and are assigned to user processes or applications.
  - **Dynamic/Private Ports**: Range from 49152 to 65535 and are used for temporary or private purposes.

##### Sockets
- **Description**: A socket is a combination of an IP address and a port number, representing a specific endpoint for communication.
- **Function**: Sockets are used to establish connections between devices and transfer data between applications. They uniquely identify a connection endpoint.
- **Example**: `192.168.1.1:80` (IP address `192.168.1.1` and port `80`).

##### Connections
- **Description**: A connection is established between two sockets when two devices want to communicate with each other.
- **Function**: During the connection establishment process, the devices negotiate various parameters such as the maximum segment size and window size, which determine how data will be transmitted over the connection. This ensures reliable and ordered data transfer.
- **Process**:
  - **Three-Way Handshake**: 
    1. **SYN**: The client sends a SYN (synchronize) packet to the server to initiate a connection.
    2. **SYN-ACK**: The server responds with a SYN-ACK (synchronize-acknowledge) packet to acknowledge the request.
    3. **ACK**: The client sends an ACK (acknowledge) packet to confirm the connection is established.
  - **Data Transfer**: Once the connection is established, data can be transferred between the client and server. TCP ensures that data is delivered accurately and in the correct order.
  - **Connection Termination**: When the data transfer is complete, the connection is terminated using a four-step process (FIN, FIN-ACK, ACK, and FIN-ACK).

##### Example
- **Port**: `192.168.1.1:80` (IP address `192.168.1.1` and port `80`).
- **Socket**: `192.168.1.1:80` (local socket) communicating with `203.0.113.5:12345` (remote socket).
- **Connection**: The established link between `192.168.1.1:80` and `203.0.113.5:12345` allowing data exchange.

##### Additional Details
- **Reliability**: TCP ensures reliable data transfer by using acknowledgments and retransmissions. If a packet is lost or corrupted, TCP will retransmit it.
- **Flow Control**: TCP uses flow control mechanisms to prevent overwhelming the receiver with too much data at once.
- **Congestion Control**: TCP adjusts the rate of data transmission based on network congestion to avoid packet loss and ensure efficient use of network resources.









There are four main protocols used in TCP/IP: the Transmission Control Protocol (TCP), the User Datagram Protocol (UDP), the Internet Protocol (IP), and the Internet Control Message Protocol (ICMP).

    TCP ensures that data is delivered reliably and in order. 
    UDP is used for applications where data doesn't need to be delivered reliably or needs to be delivered quickly without the overhead of TCP.
    IP is the protocol that routes data from one computer to another. 
    ICMP is used for error-checking and for managing traffic congestion.



Transmission Control Protocol (TCP) and User Datagram Protocol (UDP) are both ways to send data over the internet.
TCP is more reliable, while UDP is faster and more efficient

### User Datagram Protocol (UDP)



#### Overview
- **Description**: UDP is a connectionless, lightweight transport layer protocol in the TCP/IP suite. It is used for applications that require fast, efficient transmission of data without the need for guaranteed delivery, order, or error-checking.
- **Function**: UDP allows applications to send messages, called datagrams, to other hosts on an IP network without establishing a connection.

#### Characteristics
- **Connectionless**: Unlike TCP, UDP does not establish a connection before sending data. Each datagram is sent independently.
- **Unreliable**: UDP does not guarantee delivery, order, or error-checking of datagrams. If a datagram is lost or arrives out of order, it is not retransmitted.
- **Low Overhead**: UDP has minimal protocol overhead, making it faster and more efficient for applications that can tolerate some data loss.

#### Structure
- **Header**: The UDP header is simple and consists of four fields (8 bytes total):
  - **Source Port** (2 bytes): The port number of the sending application.
  - **Destination Port** (2 bytes): The port number of the receiving application.
  - **Length** (2 bytes): The length of the UDP header and data.
  - **Checksum** (2 bytes): Used for error-checking of the header and data (optional).

#### Use Cases
- **Real-Time Applications**: UDP is ideal for real-time applications where speed is critical and some data loss is acceptable, such as:
  - **Streaming Media**: Audio and video streaming (e.g., live broadcasts, VoIP).
  - **Online Gaming**: Fast-paced games where low latency is more important than reliability.
  - **DNS Queries**: Domain Name System (DNS) queries, where quick responses are needed.
  - **Broadcast and Multicast**: Sending data to multiple recipients simultaneously.

#### Example
- **DNS Query**: When a client needs to resolve a domain name to an IP address, it sends a UDP datagram to a DNS server. The server responds with a UDP datagram containing the IP address.

### Comparison with TCP
- **Reliability**: TCP provides reliable, ordered delivery of data, while UDP does not.
- **Connection**: TCP establishes a connection before data transfer, while UDP is connectionless.
- **Overhead**: TCP has higher overhead due to connection management and error-checking, while UDP has minimal overhead.
- **Speed**: UDP is faster and more efficient for applications that can tolerate some data loss.

### Summary
UDP is a simple, fast, and efficient protocol suitable for applications that prioritize speed and can tolerate some data loss. It is widely used in real-time applications, streaming, online gaming, and other scenarios where low latency is crucial.

There are some other protocols also notable, and there are,

    Address Resolution Protocol (ARP)
    File Transfer Protocol (FTP)
    Hypertext Transfer Protocol (HTTP)
    Simple Mail Transfer Protocol (SMTP)



### Internet Control Message Protocol (ICMP)

#### Overview
- **Description**: ICMP is a network layer protocol used for error reporting and diagnostic functions in IP networks. It is an integral part of the Internet Protocol suite and is primarily used by network devices, like routers, to send error messages and operational information.
- **Function**: ICMP helps manage and control the flow of data in a network by providing feedback about issues in the communication environment. It is used for network diagnostics and troubleshooting.

#### Key Components of ICMP

1. **ICMP Messages**
   - **Description**: ICMP messages are encapsulated within IP packets and consist of various types and codes that indicate the nature of the message.
   - **Types and Codes**: Each ICMP message has a type and code that specify the purpose of the message. Some common types and codes include:
     - **Type 0**: Echo Reply (used in ping responses)
     - **Type 3**: Destination Unreachable (various codes indicate specific reasons, such as network unreachable, host unreachable, etc.)
     - **Type 4**: Source Quench (request to reduce sending rate)
     - **Type 5**: Redirect (used to inform a host of a better route)
     - **Type 8**: Echo Request (used in ping requests)
     - **Type 11**: Time Exceeded (indicates that the TTL of a packet has expired)

2. **ICMP Header**
   - **Description**: The ICMP header contains information about the ICMP message, including the type, code, checksum, and other fields specific to the message type.
   - **Fields**:
     - **Type**: Indicates the type of ICMP message.
     - **Code**: Provides additional information about the type.
     - **Checksum**: Used for error-checking the ICMP header and data.
     - **Rest of Header**: Varies based on the type and code of the message. It may include fields like identifier, sequence number, and data.

3. **Common ICMP Messages**
   - **Echo Request and Echo Reply**:
     - **Description**: Used by the `ping` utility to test connectivity between devices.
     - **Function**: The Echo Request message is sent to a target device, which responds with an Echo Reply message if it is reachable.
   - **Destination Unreachable**:
     - **Description**: Indicates that a packet could not reach its destination.
     - **Function**: Various codes specify the reason, such as network unreachable, host unreachable, protocol unreachable, or port unreachable.
   - **Time Exceeded**:
     - **Description**: Indicates that the Time to Live (TTL) of a packet has expired.
     - **Function**: Commonly used by the `traceroute` utility to identify the path packets take to reach a destination.
   - **Redirect**:
     - **Description**: Informs a host of a better route to a destination.
     - **Function**: Helps optimize routing by directing traffic through a more efficient path.

#### Use Cases
- **Network Diagnostics**: ICMP is widely used for network diagnostics and troubleshooting tools like `ping` and `traceroute`.
- **Error Reporting**: ICMP messages provide feedback about issues in the network, such as unreachable destinations or expired TTLs.
- **Routing Optimization**: ICMP Redirect messages help optimize routing by informing hosts of better routes.

#### Security Considerations
- **ICMP Flooding**: Attackers can use ICMP to flood a target with Echo Request messages, overwhelming the target and causing a denial of service (DoS).
- **ICMP Redirect Attacks**: Malicious actors can use ICMP Redirect messages to alter routing tables and redirect traffic through a compromised device.
- **Mitigation**: Network administrators can implement rate limiting, filtering, and monitoring to mitigate ICMP-based attacks.

### Summary
ICMP is a crucial protocol for managing and diagnosing network issues. It provides feedback about the status of the network and helps ensure efficient data flow. Understanding ICMP and its various message types is essential for network administrators and engineers to maintain and troubleshoot IP networks effectively.







HTTP


 HTTP: The Hypertext Transfer Protocol is used to transfer data between a client (such as a web browser) and a server (such as a website).
 HTTPS: An encrypted version of HTTP that is used to provide secure communication between a client and server.
 SSL/TLS: The Secure Sockets Layer and Transport Layer Security protocols are used to provide secure communication over the internet.



HTTP (Hypertext Transfer Protocol) and HTTPS (HTTP Secure) are two of the most commonly used protocols in internet-based applications and services.

HTTP is the protocol used to transfer data between a client (such as a web browser) and a server (such as a website).

Clients and servers communicate by exchanging individual messages (as opposed to a stream of data). The messages sent by the client are called requests and the messages sent by the server as an answer are called responses.

When you visit a website, your web browser sends an HTTP request to the server, asking for the webpage or other resource you've requested. The server then sends an HTTP response back to the client, containing the requested data.

HTTP is a protocol for fetching resources such as HTML documents. It is the foundation of any data exchange on the Web and it is a client-server protocol, which means requests are initiated by the recipient, usually the Web browser. A complete document is typically constructed from resources such as text content, layout instructions, images, videos, scripts, and more.

A single Web document composed from multiple resources from different servers.



HTTPS

HTTPS is a more secure version of HTTP, which encrypts the data being transmitted between the client and server using SSL/TLS (Secure Sockets Layer/Transport Layer Security) encryption. This provides an additional layer of security, helping to protect sensitive information such as login credentials, payment information, and other personal data.

When you visit a website that uses HTTPS, your web browser will display a padlock icon in the address bar, indicating that the connection is secure. You may also see the letters “https” at the beginning of the website address, rather than “http”.



### SSL/TLS

SSL/TLS is a protocol used to encrypt data being transmitted over the internet. It is commonly used to provide secure connections for applications such as web browsers, email clients, and file transfer programs.

When using SSL/TLS to secure internet communication, there are a few key concepts to understand:

 Certificates: SSL/TLS certificates are used to establish trust between the client and server. They contain information about the identity of the server and are signed by a trusted third party (a Certificate Authority) to verify their authenticity.

 Handshake: During the SSL/TLS handshake process, the client and server exchange information to negotiate the encryption algorithm and other parameters for the secure connection.

 Encryption: Once the secure connection is established, data is encrypted using the agreed-upon algorithm and can be transmitted securely between the client and server.

When building internet-based applications and services, it's important to understand how SSL/TLS works and to ensure that your application is designed to use SSL/TLS when transmitting sensitive data such as login credentials, payment information, and other personal data. You'll also need to ensure that you obtain and maintain valid SSL/TLS certificates for your servers, and that you follow best practices for configuring and securing your SSL/TLS connections. By doing so, you can help protect your users' data and ensure the integrity and confidentiality of your application's communication over the internet.











Consider this article. In order for you to see it, it was sent over the Internet piece by piece in the form of several thousand data packets.

The specific steps involved in this process are:

    DNS query: When your browser started to load this webpage, it likely first made a DNS query to find out the Cloudflare website's IP address.
    TCP handshake: Your browser opened a connection with that IP address.
    TLS handshake: Your browser also set up encryption between a Cloudflare web server and your device so that attackers cannot read the data packets that travel between those two endpoints.
    HTTP request: Your browser requested the content that appears on this webpage.
    HTTP response: Cloudflare's server transmitted the content in the form of HTML, CSS, and JavaScript code, broken up into a series of data packets. Once your device received the packets and verified it had received all of them, your browser interpreted the HTML, CSS, and JavaScript code contained in the packets to render this article about how the Internet works. The whole process took only a second or two.





Hosts use various protocols to communicate, including TCP and User Datagram Protocol (UDP).



File Transfer Protocol (FTP): A reliable protocol for sending and receiving files 
User Datagram Protocol (UDP): A connectionless protocol that prioritizes speed over reliability, making it ideal for real-time applications like video streaming 
Simple Network Management Protocol (SNMP): A protocol that allows network administrators to monitor and manage network devices 
Simple Mail Transfer Protocol (SMTP): A protocol for sending emails between computers 
Internet Control Message Protocol (ICMP): A protocol that diagnoses communication issues between devices 
Dynamic Host Configuration Protocol (DHCP): A protocol that assigns IP addresses to devices on a network 
Application layer protocols: Protocols that allow programs to send information to each other, often used for web communication 





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













## Introduction to Network Layers

While a network user may only perceive that he
or she is using one computer program (like a Web browser) and one piece of hardware (like
a PC), these are only parts of a much larger puzzle. In order for even the simplest task to be
accomplished on a network, dozens of different components must cooperate, passing
control information and data to accomplish the overall goal of network communication.

The best way to understand any complex system is to break it down into pieces and then
analyze what they do and how they interact. The most logical approach for this is to divide
the overall set of functions into modular components, each of which is responsible for a
particular function. At the same time, we also need to define interfaces between these
components, which describe how they fit together. This enables us to simplify the
complexity of networking by approaching it in digestible chunks.


Networking technologies are most often compartmentalized in this manner by dividing their
functions into layers, each of which contains hardware and/or software elements. Each
layer is responsible for performing a particular type of task, as well as interacting with the
layers above it and below it. Layers are conceptually arranged into a vertical stack. Lower
layers are charged with more concrete tasks such as hardware signaling and low-level
communication; they provide services to the higher layers. The higher layers in turn use
these services to implement more abstract functions such as implementing user
applications.




### OSI Model

The OSI model is a seven-layer model that divides the complexity of network communications into seven smaller, more manageable parts, each responsible for a different aspect of the communication process.


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





TCP Layers

The TCP/IP model is divided into four different layers:

    Application layer
    Transport layer
    Internet layer
    Network Access layer

Data moves from one layer to another.
Each layer performs a specific task on the data that is being transmitted over the network channel 
Each layer makes use of the services provided by the underlying lower layers, and provides services to the layer above it.

The above layers represents different layer of abstraction in a process.
In the case of data being sent, the process movies from top to bottom. 
In the case of data being received, the layers of the model work in reverse order.




Application Layer
    This layer provides network services directly to applications. 
    It is the closest layer to the end user and facilitates communication between software applications and lower layers.
    It handles high-level protocols, data representation, encoding, and dialog control.
    The application layer is the scope within which applications, or processes, create user data and communicate this data to other applications on another or the same host.
    Processes are addressed via ports which essentially represent services.
    
    It corresponds to the OSI model's Session, Presentation, and Application layers.
    Protocols include HTTP (Hypertext Transfer Protocol), FTP (File Transfer Protocol), SMTP (Simple Mail Transfer Protocol), DNS (Domain Name System), Telnet, SSH (Secure Shell).

Transport Layer
    This layer provides end-to-end communication services for applications by managing host-to-host communications on either the local network or remote networks separated by routers.
    It ensures complete data transfer and error recovery.
    It handles data segmentation, flow control, error detection and correction, and retransmission of lost data. 
    
    It corresponds to the OSI model's Transport layer.
    Protocols include TCP (Transmission Control Protocol), UDP (User Datagram Protocol).

Internet Layer
    This layer is responsible for logical addressing and routing of data packets across the network. It ensures that data packets are sent from the source to the destination across multiple networks.
    It handles packet forwarding, addressing, and routing. It corresponds to the OSI model's Network layer.
    Protocols include IP (Internet Protocol), ICMP (Internet Control Message Protocol), IGMP (Internet Group Management Protocol).

Network Interface Layer (Link Layer)
   Responsible for the physical transmission of data over a network. It includes the hardware and software technologies that connect devices to the network.
   Handles the physical addressing, data framing, and error detection. It corresponds to the OSI model's Physical and Data Link layers.
   Protocols include Ethernet, Wi-Fi, ARP (Address Resolution Protocol).


The TCP/IP model is a more simplified and practical framework compared to the OSI model, and it is the foundation of the modern Internet.


### Internet Protocol Suite

The Internet Protocol Suite, commonly known as TCP/IP, is a set of communication protocols used for the Internet and similar networks. It is organized into four abstraction layers, each with specific functions and protocols. Here is a detailed explanation of all parts of the Internet Protocol Suite:

#### 1. Application Layer
- **Description**: This layer provides network services directly to applications. It is the closest layer to the end user and facilitates communication between software applications and lower layers.
- **Function**: It handles high-level protocols, data representation, encoding, and dialog control.
- **Protocols**:
  - **HTTP (Hypertext Transfer Protocol)**: Used for transferring web pages.
  - **HTTPS (HTTP Secure)**: An encrypted version of HTTP for secure communication.
  - **FTP (File Transfer Protocol)**: Used for transferring files.
  - **SMTP (Simple Mail Transfer Protocol)**: Used for sending emails.
  - **DNS (Domain Name System)**: Translates domain names into IP addresses.
  - **Telnet**: Provides remote login capabilities.
  - **SSH (Secure Shell)**: Provides secure remote login and other secure network services.

#### 2. Transport Layer
- **Description**: This layer provides end-to-end communication services for applications. It ensures complete data transfer and error recovery.
- **Function**: It handles data segmentation, flow control, error detection and correction, and retransmission of lost data.
- **Protocols**:
  - **TCP (Transmission Control Protocol)**: Provides reliable, ordered, and error-checked delivery of data.
  - **UDP (User Datagram Protocol)**: Provides a connectionless, lightweight protocol for fast, efficient transmission of data without guaranteed delivery.

#### 3. Internet Layer
- **Description**: This layer is responsible for logical addressing and routing of data packets across the network. It ensures that data packets are sent from the source to the destination across multiple networks.
- **Function**: It handles packet forwarding, addressing, and routing.
- **Protocols**:
  - **IP (Internet Protocol)**: Provides logical addressing and routing of packets.
  - **ICMP (Internet Control Message Protocol)**: Used for error reporting and diagnostic functions.
  - **IGMP (Internet Group Management Protocol)**: Manages multicast group memberships.

#### 4. Network Interface Layer (Link Layer)
- **Description**: This layer is responsible for the physical transmission of data over a network. It includes the hardware and software technologies that connect devices to the network.
- **Function**: It handles physical addressing, data framing, and error detection.
- **Protocols**:
  - **Ethernet**: A widely used LAN technology.
  - **Wi-Fi**: A wireless LAN technology.
  - **ARP (Address Resolution Protocol)**: Maps IP addresses to MAC addresses.

### Summary
The Internet Protocol Suite, or TCP/IP, is a comprehensive set of protocols that enable communication over the Internet and similar networks. It is organized into four layers, each with specific functions and protocols that work together to ensure reliable and efficient data transmission. Understanding these layers and their associated protocols is essential for network administrators, engineers, and anyone involved in network communication.











Types of Enterprise Computer Networks

    Open system: A system that is connected to the network and is ready for communication. 

    Closed system: A system that is not connected to the network and can’t be communicated with.

    LAN: A Local Area Network (LAN) is a network that covers a small area, such as an office or a home. LANs are typically used to connect computers and other devices within a building or a campus.

    WAN: A Wide Area Network (WAN) is a network that covers a large geographic area, such as a city, country, or even the entire world. WANs are used to connect LANs together and are typically used for long-distance communication.

    Cloud Networks: Cloud Networks can be visualized with a Wide Area Network (WAN) as they can be hosted on public or private cloud service providers and cloud networks are available if there is a demand. Cloud Networks consist of Virtual Routers, Firewalls, etc.

These are just a few basic concepts of computer networking. Networking is a vast and complex field, and there are many more concepts and technologies involved in building and maintaining networks. Now we are going to discuss some more concepts on Computer Networking.

    

Types of Computer Network Architecture

Computer Network falls under these broad Categories:

    Client-Server Architecture: Client-Server Architecture is a type of Computer Network Architecture in which Nodes can be Servers or Clients. Here, the server node can manage the Client Node Behaviour.

    Peer-to-Peer Architecture: In P2P (Peer-to-Peer) Architecture, there is not any concept of a Central Server. Each device is free for working as either client or server.








Node Vs Host

A node is a broader term that includes anything connected to a network, while a host requires an IP address. In other words, all hosts are nodes, but network nodes are not hosts unless they require an IP address to function. 



Network Topology

The Network Topology is the layout arrangement of the different devices in a network. 

Some types of network topologies are:

    Bus Topology: In bus topology all devices are connected to a single central cable called a bus. Data is sent along this cable and all devices share the same connection. Simple and cheap to set up but if the main cable fails the whole network goes down.

    Star Topology: In star topology all devices are connected to a central node called hub or switch. The hub controls the flow of data between devices. If one device fails the rest of the network is unaffected. But, if the central hub fails the whole network stops working.

    Ring Topology: In ring topology devices are connected in a circular loop with each device connected to two others. Data travels in one direction (or sometimes both) passing through each device until it reaches its destination. A failure in one device can affect the whole network.

    Mesh Topology: In mesh topology every device is connected to every other device in the network. It provides multiple paths for data so if one path fails another can take over.

    Tree Topology: Tree topology is the combination of star and bus topology. Tree topology is good for organizing large networks and allows for easy expansion.

    Hybrid Topology: Hybrid topology is the combination of two or more different topologies (like star and mesh). It is flexible and can be customized based on the network’s specific needs.





A lot of different kinds of hardware and infrastructure go into making the Internet work for everyone. Some of the most important types include the following:

    Routers forward packets to different computer networks based on their destination. Routers are like the traffic cops of the Internet, making sure that Internet traffic goes to the right networks.
    Switches connect devices that share a single network. They use packet switching to forward packets to the correct devices. They also receive outbound packets from those devices and pass them along to the right destination.
    Web servers are specialized high-powered computers that store and serve content (webpages, images, videos) to users, in addition to hosting applications and databases. Servers also respond to DNS queries and perform other important tasks to keep the Internet up and running. Most servers are kept in large data centers, which are located throughout the world.





### Subnet

#### Overview
- **Description**: A subnet, or subnetwork, is a logically segmented portion of a larger network. It divides a large network into smaller, more manageable sections, improving performance and security.
- **Function**: Subnets help organize and manage IP addresses within a network, allowing for efficient routing and reducing broadcast traffic.

#### How Subnets Work
- **IP Addressing**: Each device in a subnet is assigned a unique IP address. The IP address consists of two parts: the network portion and the host portion.
- **Subnet Mask**: A subnet mask is used to determine which part of an IP address is the network portion and which part is the host portion. It is a 32-bit number that masks an IP address and divides it into network and host addresses.
  - Example: For an IP address `192.168.1.10` with a subnet mask `255.255.255.0`, the network portion is `192.168.1` and the host portion is `10`.

#### Benefits of Subnetting
- **Improved Performance**: By reducing the size of broadcast domains, subnetting minimizes network congestion and improves overall performance.
- **Enhanced Security**: Subnets can isolate different segments of a network, providing an additional layer of security by controlling access between subnets.
- **Efficient IP Address Management**: Subnetting allows for better utilization of IP addresses, preventing wastage and ensuring that IP address space is used efficiently.


### Difference Between Network and Host Portions of a Subnet Mask

#### Network Portion
- **Description**: The network portion of an IP address identifies the specific network to which the device belongs. It is used by routers to determine the best path to route packets to their destination network.
- **Function**: It helps in identifying and routing data to the correct network. All devices within the same network share the same network portion in their IP addresses.
- **Determination**: The subnet mask determines how many bits of the IP address are used for the network portion. For example, in a subnet mask of `255.255.255.0` (or `/24`), the first 24 bits are the network portion.

#### Host Portion
- **Description**: The host portion of an IP address identifies the specific device within the network. It is unique to each device within the same network.
- **Function**: It allows for the identification and communication with individual devices within the network. Each device has a unique host portion in its IP address.
- **Determination**: The remaining bits of the IP address, after the network portion, are used for the host portion. For example, in a subnet mask of `255.255.255.0` (or `/24`), the last 8 bits are the host portion.

### Example
- **IP Address**: `192.168.1.10`
- **Subnet Mask**: `255.255.255.0` (or `/24`)
  - **Network Portion**: `192.168.1` (first 24 bits)
  - **Host Portion**: `10` (last 8 bits)

### Summary
- **Network Portion**: Identifies the network, shared by all devices within the same network, used for routing.
- **Host Portion**: Identifies the specific device within the network, unique to each device within the same network.

The subnet mask is crucial in dividing the IP address into these two portions, enabling efficient routing and communication within and between networks.


#### Subnetting Example
- **Class C Network**: Consider a Class C network with the IP address range `192.168.1.0/24`. This network can be divided into smaller subnets.
  - **Subnet 1**: `192.168.1.0/26` (subnet mask `255.255.255.192`)
    - Network Address: `192.168.1.0`
    - Broadcast Address: `192.168.1.63`
    - Usable IP Range: `192.168.1.1` to `192.168.1.62`
  - **Subnet 2**: `192.168.1.64/26` (subnet mask `255.255.255.192`)
    - Network Address: `192.168.1.64`
    - Broadcast Address: `192.168.1.127`
    - Usable IP Range: `192.168.1.65` to `192.168.1.126`

#### Summary
A subnet is a smaller, logical subdivision of a larger network, created to improve network performance, enhance security, and manage IP addresses efficiently. Subnetting involves dividing a network into smaller segments, each with its own unique IP address range and subnet mask.

A network switch is a hardware device that connects multiple devices within a network, allowing them to communicate with each other by intelligently directing data packets to their intended destination, essentially acting as a traffic controller for network traffic between connected devices like computers, printers, and servers; it operates at the data link layer (Layer 2) of the OSI model, using MAC addresses to identify devices and efficiently forward data packets only to the appropriate recipient. 

 Unlike a router, a switch only sends data to the single device it is intended for (which may be another switch, a router, or a user's computer), not to networks of multiple devices.

Routers select paths for data packets to cross networks and reach their destinations. Routers do this by connecting with different networks and forwarding data from network to network

 routers are necessary for an Internet connection, while switches are only used for interconnecting devices. Homes and small offices need routers for Internet access, but most do not need a network switch, unless they require a large amount of Ethernet* ports. However, large offices, networks, and data centers with dozens or hundreds of computers usually do require switches.

 Network switches can operate at either OSI layer 2 (the data link layer) or layer 3 (the network layer). Layer 2 switches forward data based on the destination MAC address (see below for definition), while layer 3 switches forward data based on the destination IP address. Some switches can do both.

Most switches, however, are layer 2 switches. Layer 2 switches most often connect to the devices in their networks using Ethernet cables. Ethernet cables are physical cables that plug into devices via Ethernet ports.


An unmanaged switch simply creates more Ethernet ports on a LAN, so that more local devices can access the Internet. Unmanaged switches pass data back and forth based on device MAC addresses.

A managed switch fulfills the same function for much larger networks, and offers network administrators much more control over how traffic is prioritized. They also enable administrators to set up Virtual LANs (VLANs) to further subdivide a local network into smaller chunks.

Network switches refer to MAC addresses in order to send Internet traffic to the right devices, not IP addresses.

IP addresses are used at layer 3, which means computers and devices all over the Internet use IP addresses for sending and receiving data, no matter which network they are connected to. All IP packets include their source and destination IP addresses in their headers, just as a piece of mail has a destination address and a return address.

In contrast, a MAC address is a permanent identifier for each piece of hardware, somewhat like a serial number. Unlike IP addresses, MAC addresses do not change. MAC addresses are used at layer 2, not layer 3 — which means they are not included in IP packet headers. In other words, MAC addresses are not part of Internet traffic. They are only used inside a given LAN.

Layer 2 network switches maintain a table in memory that matches MAC addresses to the switch's Ethernet ports. This table is called a Content Addressable Memory (CAM) table.

Suppose Computer A is connected to an Ethernet cable that plugs into the switch's Port 1, Computer B is connected to Port 2, and Computer C to Port 3. When data arrives for Computer A, the switch consults its CAM table, sees where Computer A is connected, and knows to forward Computer A-bound traffic at Port 1, not Ports 2 or 3.

The switch's CAM table would look something like this:
MAC address 	 Port 
Computer A's MAC address 	1
Computer B's MAC address 	2
Computer C's MAC address 	3

The switch's CAM table is stored in memory. If the switch is turned off, the table will disappear and the switch has to relearn the table when it is rebooted.

Now, suppose the switch was just turned on and has not yet created its CAM table. It does not know which ports Computers A, B, and C are connected to. It also does not know their MAC addresses.
 MAC address  	 Port 
? 	?
? 	?
? 	?

Suppose Computer A sends a message to Computer B. The switch takes the following steps to get the message to Computer B and start filling out its CAM table:

    It records Computer A's MAC address and the port its message came in on
    It forwards Computer A's message to all other computers on the network (except Computer A); this is known as "flooding"
    When Computer B replies, it records Computer B's MAC address and port as well

MAC address 	 Port 
Computer A's MAC address 	1
Computer B's MAC address 	2
? 	?

Now, the switch's CAM table knows where Computer A and Computer B are. It also knows their MAC addresses.









### Network Security

Ensuring the security of a network is crucial to protect data and resources from unauthorized access and attacks. Key aspects of network security include:

    Firewalls: Devices or software that monitor and control incoming and outgoing network traffic based on security rules.
    Encryption: The process of encoding data to prevent unauthorized access. Commonly used in VPNs, HTTPS, and secure email.
    Intrusion Detection Systems (IDS): Tools that monitor network traffic for suspicious activity and potential threats.
    Access Control: Mechanisms that restrict access to network resources based on user identity and role.
    Regular Updates and Patching: Keeping software and hardware up to date to protect against vulnerabilities.


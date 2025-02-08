# Transmission Control Protocol (TCP) / Internet Protocol (IP)

The Internet Protocol Suite known as TCP/IP (Transmission Control Protocol/Internet Protocol) is the underlying communication protocol used by most internet-based applications and services.

There are four main protocols used in TCP/IP:

  Internet Protocol (IP) is the protocol that routes data from one computer to another. 
  Transmission Control Protocol (TCP) ensures that data is delivered reliably and in order. 
  Internet Control Message Protocol (ICMP) is used for error-checking and for managing traffic congestion.
  User Datagram Protocol (UDP) is used for data delivery that is quick but less reliable, without the overhead or assurance of TCP.
  


###  Internet Protocol (IP)

To communicate between devices on a network, we specify which devices and what to transfer between them.

IP defines the structure of packets, known as IP datagrams, and provides the addressing system that identifies devices on a network that utilizes routers.

#### Packets

Computers break larger data files to be transferred into smaller, ordered pieces individually called a network packet.

A packet, in networking terms, is the smallest functioning unit of data.
Packets are the basic building block of all network communication.


#### Why Packets are Small

Packets are used for efficient and reliable transmission of data.

Without packets, the process of sending a large video file would require an uninterrupted data stream.
This data stream would clog the network as other transmissions would have to wait.

If data was sent between computers all at once, a connection between two computers could occupy multiple cables, routers, and switches. Essentially, only two people would be able to use a segment of the Internet at a time — instead of an almost unlimited number of people, as is the case in reality.

Instead of transferring files as single, uninterrupted data blocks, sending it in smaller packets enables computers to share connections.

#### Packet Switching 

Packets are sent across the Internet using a technique called packet switching. 

A very large image file might be made up of tens of millions of bits, ones and zeros, binary data.
The computer sending the image can break it into hundreds or even thousands of packets. 

Intermediary routers and switches are able to process such packets independently from each other.
Multiple, simultaneous transmissions may be managed by packet switching.
Packets from concurrent connections are rapidly interspersed, and sent to the next router in their intended path.
In this way, data exchanges consisting of smaller amounts of data may be completed at the same time larger file transfers are ongoing.
This is by design, so that no single connection dominates the network. 

Each packet is treated as an independent entity, using the header metadata to ensure it reaches the intended destination.

If there is a problem with the transmission of one or more packets, only those packets are requested to be retransmitted, rather than the entirety of a larger file.


#### How Packets Travel

Packets are initiated from source devices to the first router on their path. 
The router examines the packet and forwards it to the next router, towards its target.
This process continues until the packet reaches its destination device.

The data path, the order of routers used to transfer data across a network, may change in the midst of a computer-to-computer conversation. 

A packet travels from one place to another on the internet a lot like how you might get from one place to another in a car. 
Depending on traffic congestion or road conditions you might choose or be forced to take a different route to get to a desired location.

If one route is congested, individual packets may travel different routes through the internet to arrive at their destination.

Additionally, if internet routers experience congestion or other technical problems, they are allowed to deal with it by simply discarding packets. 
The receiving computers is responsible for sending confirmation of each packet received. 
The sending computer is responsible for confirming receipt and send a copies of packets that didn't make it. 
This approach might seem counterintuitive, but it simplifies the internet's core infrastructure, leading to higher performance at lower cost.

Having options for paths makes the network fault tolerant.
Router systems are scalable. 
They can work with eight devices, eight billion devices or more. 
In fact, because of these principles of fault tolerance and redundancy, the more routers we add, the more reliable the internet becomes. 
Through packet switching, we can grow and scale the internet without interrupting service for anybody using it.
This is the basis for a key principle of the internet: reliability. 


### Internet Protocol (IP)

An internet packet, also known as a network packet, is the fundamental unit of data transmitted over a packet-switched network like the Internet. Each packet contains two main parts: the header and the payload (data).

#### 1. Header
The header contains metadata about the packet, which is used for routing and managing the packet as it travels through the network. The header includes several fields.

   - **Version**: Indicates the IP version (IPv4 or IPv6).
   - **Header Length**: Specifies the length of the header.
   - **Type of Service**: Indicates the quality of service desired.
   - **Total Length**: The entire packet size, including header and data.
   - **Identification**: A unique identifier for the packet, used to reassemble fragmented packets.
   - **Flags**: Control flags for fragmentation and other functions.
   - **Fragment Offset**: Indicates the position of a fragment in the original data stream if the packet has been fragmented.
   - **Time to Live (TTL)**: A counter that decrements by one each time the packet passes through a router. When the TTL reaches zero, the packet is discarded to prevent it from circulating indefinitely.
   - **Protocol**: Indicates the protocol used in the data portion (e.g., TCP, UDP, ICMP).
   - **Header Checksum**: A value used for error-checking the header to ensure data integrity.
   - **Source IP Address**: The IP address of the sender.
   - **Destination IP Address**: The IP address of the receiver.
   - **Options**: Optional fields that can be used for various purposes, such as security or routing.

#### 2. Payload (Data)
The payload is the actual data being transmitted, it is encapsulated within the packet and follows the header.

- **Data**: The actual content being transmitted. This could be a fragment of a larger file or message.
- **Padding**: Optional padding to ensure the packet meets a minimum length requirement.

### Example of an IP Packet Structure
Here is a simplified example of an IPv4 packet structure:

```
| Header                          | Payload (Data)          |
|---------------------------------|-------------------------|
| Version                         | Actual data being sent  |
| Header Length                   | Optional Padding        |
| Type of Service                 |                         |
| Total Length                    |                         |
| Identification                  |                         |
| Flags                           |                         |
| Fragment Offset                 |                         |
| Time to Live (TTL)              |                         |
| Protocol                        |                         |
| Header Checksum                 |                         |
| Source IP Address               |                         |
| Destination IP Address          |                         |
| Options                         |                         |
```





#### What Are IP Addresses

Every network host has a unique address that identifies it, called an "IP address".
similar to a unique postal address used by the postal service.

IP addresses have a uniform format.

These numbers are arranged in a hierarchy 
The earlier numbers usually identify the country and regional network of the device. 
Then come the subnetwork, and finally the address of the specific device.

#### IPv4

IP v4: 32 bit, 4 byte
[0-255].[0-255].[0-255].[0-255]

IPv4 was designed in 1973 and widely adopted in the early 80s
In 1974, the Institute of Electrical and Electronics Engineers (IEEE) published a paper entitled "A Protocol for Packet Network Intercommunication".
Authors Vint Cerf and Bob Kahn describe an internetworking protocol for sharing resources using packet switching.
IPv4's 32 bits per address provides 2^32, over 4 billion, unique addresses for devices connecting to the internet. 

A regional Internet registry (RIR) is an organization that manages the allocation and registration of Internet number resources within a particular region of the world.
Internet number resources include IP addresses.

IPv4 address exhaustion is the depletion of the pool of unallocated IPv4 addresses, and began to be an issue for various RIRs in the 2010s


#### IPv6

IP v6: 128 bit, 16 byte
[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF]

A longer IP address format called IPv6 was developed by the Internet Engineering Task Force (IETF) 
IETF began developing IPv6 in 1994, and the core specification was published in 1995.
IPv6 was ratified as the Internet Standard in 2017. 
IPv6's 128 bits per address and provides 2^128, over 340 undecillion, unique addresses.
That's more than enough for every grain of sand on Earth to have its own IP address.

IPv6 provides some other updates to IPv4, including security and privacy improvements. Despite their differences, both IPv4 and IPv6 have been used concurrently on the web for over a decade. The two versions can run in parallel, but special measures had to be implemented to facilitate communications between IPv4 and IPv6 devices. This compromise had to be made because so much of the web is still running on IPv4 addresses.

*What happened to IPv5? IPv5 was an experimental streaming data protocol that was never implemented. It used the same 32-bit formatting as IPv4, so it did not adequately solve the problem of not having enough unique IP addresses. For this reason, IPv6 became the successor to IPv4.

#### IPs Usage

The source IP address determines where data originates from.
The destination IP address determines where the data is intended to travel.
Each packet keeps track of it's source IP and destination IP in their header.

To traverse the internet each packet is wrapped in several layers
The first layer is your computer's, the source, IP address
your computer sends the packet to the first router which adds its own IP address then sends it to the next router
each time the packet reaches a new router another layer is added until it reaches the destination.

When the server sends back information it creates response packets with a wrapping identical to the ones received.
The packets make their way over the internet back to your computer.
Each router unwraps a layer to discover where to send the response next until it reaches your computer.

As part of the Internet Protocol, every router keeps track of multiple paths for sending packets.
Routers chooses the cheapest available path for each piece of data based on destination IP address for the packet. 
Cheapest in this case doesn't mean cost but time and nontechnical factors such as politics and relationships between companies.
Often the best route for data to travel isn't necessarily the most direct.











#### What is TCP 


IP is the primary way in which network connections are made, and it establishes the basis of the Internet. IP does not handle packet ordering or error checking. Such functionality requires another protocol, often the Transmission Control Protocol (TCP).

IP is a connectionless protocol, which means that each unit of data is individually addressed and routed from the source device to the target device, and the target does not send an acknowledgement back to the source. 

That's where the TCP protocol comes in.
TCP is used in conjunction with IP in order to maintain a connection between the sender and the target and to ensure packet order and integrity.
TCP provides a reliable, ordered, and error-checked delivery of data between applications running on different devices.

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

Ports are numerical identifiers used to distinguish different services or applications running on a device. They range from 0 to 65535. Ports help direct incoming data to the correct application. For example:
  - **HTTP**: Typically uses port 80.
  - **HTTPS**: Typically uses port 443.
  - **FTP**: Typically uses ports 20 and 21.
- **Types**:
  - **Well-Known Ports**: Range from 0 to 1023 and are assigned to common protocols and services (e.g., HTTP, FTP).
  - **Registered Ports**: Range from 1024 to 49151 and are assigned to user processes or applications.
  - **Dynamic/Private Ports**: Range from 49152 to 65535 and are used for temporary or private purposes.

##### Sockets
A socket is a combination of an IP address and a port number, representing a specific endpoint for communication. Sockets are used to establish connections between devices and transfer data between applications. They uniquely identify a connection endpoint.

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

###  Internet Protocol (IP)

To communicate between devices on a network, we specify which devices and what to transfer between them.

IP defines the structure of packets, known as IP datagrams, and provides the addressing system that identifies devices on a network.


#### Packets

Computers break larger data files to be transferred into smaller, ordered pieces individually called a network packet.

A packet, in networking terms, is the smallest functioning unit of data.
Packets are the basic building block of all network communication.

#### Why Packets are Small

Packets are used for efficient and reliable transmission of data.

Without packets, the process of sending a large video file would require an uninterrupted data stream.
This data stream would clog the network as other transmissions would have to wait.

If data was sent between computers all at once with no packet switching, a connection between two computers could occupy multiple cables, routers, and switches. Essentially, only two people would be able to use a segment of the Internet at a time — instead of an almost unlimited number of people, as is the case in reality.

Instead of transferring files as single, uninterrupted data blocks, sending it in smaller packets enables computers to share connections.

#### Packet Switching 

Packets are sent across the Internet using a technique called packet switching. 

A very large image file might be made up of tens of millions of bits, ones and zeros called binary data.
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


### Summary
The Internet Protocol (IP) defines the structure and handling of network packets. IP packets consist of a header containing metadata and a payload containing the actual data being transmitted. This structure allows packets to be efficiently routed through the network and reassembled at the destination, ensuring reliable and organized data transmission.


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










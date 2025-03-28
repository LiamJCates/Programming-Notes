### DHCP

If you are connected to the Internet, your computer has a unique IP address.

If you connect to the Internet through an Internet Service Provider (ISP), you are usually assigned a temporary IP address for the duration of your session. 

ISPs assign these temporary IP addresses, known as a dynamic IP addresses, from a pool of shared IP addresses.
The limited supply of IPv4 addresses led to the introduction of dynamically assigning IP addresses, which is still a very common practice. Most devices connected to the Internet are assigned temporary IP addresses.
This is more cost-effective for the ISP than assigning each user a permanent, or static, IP address.

Some ISP customers, such as large enterprises, will pay to maintain a static IP address (for example, Cloudflare’s 1.1.1.1). However, for most users, having a dynamic IP address is sufficient. When hosting a web server, such as a self-hosted website, API, or gaming server, a dynamic IP address can create problems. A change in IP address can cause their DNS queries to fail, effectively taking the resource offline.

dynamic IPs are obtained from a DHCP (Dynamic Host Configuration Protocol) server.

#### IP Assignment
By using DHCP, both your computer and router can automatically obtain the necessary IP addresses and network configuration parameters, ensuring seamless connectivity within the local network and to the Internet.

- **Computer**: Receives a private IP address from the local DHCP server (usually the router) for communication within the local network.
- **Router**: Receives a public IP address from the ISP's DHCP server for communication with the Internet.

DHCP is a network management protocol used to automate the process of configuring devices on IP networks. 

1. **DHCP Discover**:
   - When a device (client) connects to a network, it sends out a DHCP Discover message to identify available DHCP servers. This message is broadcasted to all devices on the network.

2. **DHCP Offer**:
   - A DHCP server receives the Discover message and responds with a DHCP Offer message. This message contains an available IP address, subnet mask, default gateway, and other network configuration details.

3. **DHCP Request**:
   - The client receives the Offer message and responds with a DHCP Request message, indicating that it accepts the offered IP address and configuration.

4. **DHCP Acknowledgment**:
   - The DHCP server receives the Request message and sends a DHCP Acknowledgment (ACK) message to the client. This message confirms that the IP address has been leased to the client for a specified period.

5. **IP Address Lease**:
   - The client can now use the assigned IP address to communicate on the network. The lease duration is specified by the DHCP server, and the client must renew the lease before it expires.

6. **DHCP Renewal**:
   - Before the lease expires, the client sends a DHCP Request message to the server to renew the lease. The server responds with a DHCP ACK message to extend the lease duration.

7. **DHCP Release**:
   - When the client no longer needs the IP address (e.g., when it disconnects from the network), it sends a DHCP Release message to the server, releasing the IP address back to the pool of available addresses.

This process ensures that devices on a network can automatically obtain IP addresses and other network configuration details without manual intervention.
### Ping

There is a handy program to see if a computer is connected to the Internet. 
The name comes from active sonar terminology that sends a pulse of sound and listens for the echo to detect objects under water

usage
$ ping www.yahoo.com

The ping utility sends a 'ping' (actually an ICMP (Internet Control Message Protocol) echo request message) to the named computer. 
The pinged computer will respond with a reply.
The ping program will count the time expired until the reply comes back (if it does). 
Also, if you enter a domain name (i.e. www.yahoo.com) instead of an IP address, ping will resolve the domain name and display the computer's IP address.

### Traceroute

The traceroute utility shows the path your packets are taking to a given Internet destination. Like ping, you must use traceroute from a command prompt. In Windows, use tracert www.yahoo.com. From a Unix prompt,

usage
traceroute www.yahoo.com. 

Like ping, you may also enter IP addresses instead of domain names. Traceroute will print out a list of all the routers, computers, and any other Internet entities that your packets must travel through to get to their destination. 


you'll notice that your packets must travel through many things to get to their destination. Most have long names such as sjc2-core1-h2-0-0.atlas.digex.net and fddi0-0.br4.SJC.globalcenter.net. These are Internet routers that decide where to send your packets. 
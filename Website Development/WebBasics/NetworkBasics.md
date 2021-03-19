How does the Internet work?

The internet consists of connection media, the fiber optics, copper, or wireless networks, that form connections between 

A computer connected to, or "on", a network is called a host
two computers connected directly to the internet's media can communicate
every host has a unique Internet Protocol address or IP address
just like a postal address
IP addresses help computers find each other but since 72.14.205.100 doesn't exactly roll off the tongue we also give them Domain Names like google.com or facebook.com



a server is a special computer connected directly to the Internet
web pages are files on server hard drives

Home computers are not servers because they're not connected directly to the Internet
Home computers are called clients because they're connected indirectly to the Internet through an Internet Service Provider


Whenever data travels across the internet computers break the information
into smaller pieces called packets
when information reaches its destination the packets are reassembled in their
original order to make a picture, email, web page, etc...

IP addresses and routers
everything connected directly or indirectly to the Internet has an IP address
this includes computers, servers, cell phones, and all of the equipment in between

anywhere two or more parts of the internet intersect there's a piece of equipment called a router routers direct packets around the internet helping each packet get one step closer
to its destination

every time you visit a website upwards of ten to fifteen routers may help your packets find their
way to and from your computer

imagine each packet as a piece of candy wrapped in several layers
the first layer is your computer's IP address
your computer sends the packet to the first router which adds its own IP address each time
the packet reaches a new router another layer is added until it reaches the server
then when the server sends back information it creates packets with an identical
wrapping as the packet makes its way
over the internet back to your computer
each router unwraps a layer to discover
where to send the packet next until it
reaches your computer

When two computers need to communicate, you have to link them, either physically (usually with an Ethernet cable) or wirelessly (for example with WiFi or Bluetooth systems). All modern computers can sustain any of those connections.

[Website Development\WebBasics\internet-schema-1.png]

Such a network is not limited to two computers. You can connect as many computers as you wish. But it gets complicated quickly. If you're trying to connect, say, ten computers, you need 45 cables, with nine plugs per computer!

[Website Development\WebBasics\internet-schema-2.png]

To solve this problem, each computer on a network is connected to a computer called a router. This router has only one job: like a signaler at a railway station, it makes sure that a message sent from a given computer arrives at the right destination computer. To send a message to computer B, computer A must send the message to the router, which in turn forwards the message to computer B and makes sure the message is not delivered to computer C.

Once we add a router to the system, our network of 10 computers only requires 10 cables: a single plug for each computer and a router with 10 plugs.

[Website Development\WebBasics\internet-schema-3.png]

A single router cannot scale to connect thousands, millions or billions of computers?
But a router is a computer like any other, so we can connect routers together.
By connecting computers to routers, then routers to routers, we are able to scale infinitely.

[Website Development\WebBasics\internet-schema-4.png]

Such a network comes very close to what we call the Internet, but we're missing something. We built that network for our own purposes. There are other networks out there: your friends, your neighbors, anyone can have their own network of computers. But it's not really possible to set cables up between your house and the rest of the world, so how can you handle this? Well, there are already cables linked to your house, for example, electric power and telephone. The telephone infrastructure already connects your house with anyone in the world so it is the perfect wire we need. To connect our network to the telephone infrastructure, we need a special piece of equipment called a modem. This modem turns the information from our network into information manageable by the telephone infrastructure and vice versa.

[Website Development\WebBasics\internet-schema-5.png]

So we are connected to the telephone infrastructure. The next step is to send the messages from our network to the network we want to reach. To do that, we will connect our network to an Internet Service Provider (ISP). An ISP is a company that manages some special routers that are all linked together and can also access other ISPs' routers. So the message from our network is carried through the network of ISP networks to the destination network. The Internet consists of this whole infrastructure of networks


If you want to send a message to a computer, you have to specify which one. Thus any computer linked to a network has a unique address that identifies it, called an "IP address" (where IP stands for Internet Protocol).
IP v4: 32 bit
[0-255].[0-255].[0-255].[0-255]
IP v6: 128 bit    [0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF].[0-FFFF]


To make things easier, we can alias an IP address with a human readable name called a domain name.

As you might notice, when we browse the Web with a Web browser, we usually use the domain name to reach a website. Does that mean the Internet and the Web are the same thing? It's not that simple. As we saw, the Internet is a technical infrastructure which allows billions of computers to be connected all together. Among those computers, some computers (called Web servers) can send messages intelligible to web browsers. The Internet is an infrastructure, whereas the Web is a service built on top of the infrastructure.

[Website Development\WebBasics\internet-schema-6.png]









Terms

web page
A document which can be displayed in a web browser such as Firefox, Google Chrome, Opera, Microsoft Internet Explorer or Edge, or Apple's Safari. These are also often called just "pages."

website
A collection of web pages which are grouped together and usually connected together in various ways. Often called a "web site" or simply a "site."

web server
A computer that hosts a website on the Internet.

search engine
A web service that helps you find other web pages, such as Google, Bing, Yahoo, or DuckDuckGo. Search engines are normally accessed through a web browser (e.g. you can perform search engine searches directly in the address bar of Firefox, Chrome, etc.) or through a web page (e.g. bing.com or duckduckgo.com).

https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_web_server

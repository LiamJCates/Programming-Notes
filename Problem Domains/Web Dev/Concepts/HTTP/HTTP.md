What is HTTP?

The Hypertext Transfer Protocol (HTTP) is the foundation of the World Wide Web, and is used to load webpages using hypertext links. 

It defines how content is requested and transmitted across the internet.

A typical flow over HTTP involves a client machine making a request to a server, which then sends a response message.



An HTTP request is the way Internet communications platforms such as web browsers ask for the information they need to load a website.

Each HTTP request made across the Internet carries with it a series of encoded data that carries different types of information. A typical HTTP request contains:

    HTTP version type
    a URL
    an HTTP method
    HTTP request headers
    Optional HTTP body.



### Protocol Layers

HTTP is an application layer protocol designed to transfer information between networked devices and runs on top of other layers of the network protocol stack. 
HTTP is a TCP/IP-based application layer communication protocol that standardizes how clients and servers communicate with each other. By application layer protocol, I mean that it’s simply an abstraction layer that standardizes how hosts (clients and servers) communicate. HTTP itself depends on TCP/IP to get requests and responses between the client and server. By default, TCP port 80 is used, but other ports can also be used. HTTPS, however, uses port 443.




### HTTP - Methods

An HTTP method, sometimes referred to as an HTTP verb, indicates the action that the HTTP request expects from the queried server. For example, two of the most common HTTP methods are ‘GET’ and ‘POST’; a ‘GET’ request expects information back in return (usually in the form of a website), while a ‘POST’ request typically indicates that the client is submitting information to the web server (such as form information, e.g. a submitted username and password).


The set of common methods for HTTP/1.1 is defined below and this set can be expanded based on requirements. 

These method names are case sensitive and they must be used in uppercase.


GET
The GET method is used to retrieve information from the given server using a given URI. Requests using GET should only retrieve data and should have no other effect on the data.

HEAD
Same as GET, but transfers the status line and header section only.

POST
A POST request is used to send data to the server, for example, customer information, file upload, etc. using HTML forms.

PUT
Replaces all current representations of the target resource with the uploaded content.

DELETE
Removes all current representations of the target resource given by a URI.

CONNECT
Establishes a tunnel to the server identified by a given URI.

OPTIONS    
Describes the communication options for the target resource.

TRACE
Performs a message loop-back test along the path to the target resource.












## HTTP/2


https://http2.github.io/




### Key Design Goals and Improvements Over HTTP/1.1

HTTP/2 was designed for low latency transport of content. The key features or differences from the old version of HTTP/1.1 include

    Binary instead of Textual
    Multiplexing - Multiple asynchronous HTTP requests over a single connection
    Header compression using HPACK
    Server Push - Multiple responses for single request
    Request Prioritization
    Security

- **Performance Optimization:**  
  HTTP/2 minimizes the overhead in web communications by reducing redundant headers and multiplexing multiple requests/responses concurrently on a single connection. This removes the need for multiple TCP connections, reducing latency and network congestion.

- **Binary Protocol:**  
  Unlike the text-based HTTP/1.1, HTTP/2 uses a binary framing layer. Binary protocols are easier to parse and optimize for performance, and they reduce errors related to text encoding.

- **Multiplexing Streams:**  
  With multiplexing, multiple messages can be interleaved over a single connection. This resolves the “head-of-line blocking” issue that affected pipelined HTTP/1.1 connections.

- **Header Compression (HPACK):**  
  HTTP/2 introduces HPACK, a compression format for headers that minimizes the redundancy across similar HTTP requests and responses, which is crucial for modern web applications that rely on many small transactions.

- **Stream Prioritization:**  
  Requests can be prioritized so that more important content (like visible images or critical scripts) is delivered first. This improves overall page load times when multiple resources are requested concurrently.

- **Server Push:**  
  HTTP/2 allows the server to “push” responses for requests that the client has not yet made, anticipating future needs. For example, along with an HTML document, a server can push associated CSS or JavaScript files to streamline the loading process.




### Binary Protocol

HTTP/2 tends to address the issue of increased latency that existed in HTTP/1.x by making it a binary protocol. Being a binary protocol, it easier to parse but unlike HTTP/1.x it is no longer readable by the human eye. The major building blocks of HTTP/2 are Frames and Streams
Frames and Streams

HTTP messages are now composed of one or more frames. There is a HEADERS frame for the meta data and DATA frame for the payload and there exist several other types of frames (HEADERS, DATA, RST_STREAM, SETTINGS, PRIORITY etc) that you can check through the HTTP/2 specs.

Every HTTP/2 request and response is given a unique stream ID and it is divided into frames. Frames are nothing but binary pieces of data. A collection of frames is called a Stream. Each frame has a stream id that identifies the stream to which it belongs and each frame has a common header. Also, apart from stream ID being unique, it is worth mentioning that, any request initiated by client uses odd numbers and the response from server has even numbers stream IDs.

Apart from the HEADERS and DATA, another frame type that I think worth mentioning here is RST_STREAM which is a special frame type that is used to abort some stream i.e. client may send this frame to let the server know that I don’t need this stream anymore. In HTTP/1.1 the only way to make the server stop sending the response to client was closing the connection which resulted in increased latency because a new connection had to be opened for any consecutive requests. While in HTTP/2, client can use RST_STREAM and stop receiving a specific stream while the connection will still be open and the other streams will still be in play.


### Multiplexing

Since HTTP/2 is now a binary protocol and as I said above that it uses frames and streams for requests and responses, once a TCP connection is opened, all the streams are sent asynchronously through the same connection without opening any additional connections. And in turn, the server responds in the same asynchronous way i.e. the response has no order and the client uses the assigned stream id to identify the stream to which a specific packet belongs. This also solves the head-of-line blocking issue that existed in HTTP/1.x i.e. the client will not have to wait for the request that is taking time and other requests will still be getting processed.

- **Concurrent Exchanges:**  
  Multiplexing enables multiple requests and responses to be in transit simultaneously over a single TCP connection. This means that small requests do not block larger ones from being delivered and vice versa.

- **Head-of-Line Blocking:**  
  While HTTP/2 manages many small streams concurrently, TCP’s inherent head-of-line blocking at the transport level can still introduce delays if packet loss occurs. However, the protocol design at the application layer minimizes this impact as much as possible.




### Header Compression

It was part of a separate RFC which was specifically aimed at optimizing the sent headers. The essence of it is that when we are constantly accessing the server from a same client there is alot of redundant data that we are sending in the headers over and over, and sometimes there might be cookies increasing the headers size which results in bandwidth usage and increased latency. To overcome this, HTTP/2 introduced header compression.

Unlike request and response, headers are not compressed in gzip or compress etc formats but there is a different mechanism in place for header compression which is literal values are encoded using Huffman code and a headers table is maintained by the client and server and both the client and server omit any repetitive headers (e.g. user agent etc) in the subsequent requests and reference them using the headers table maintained by both.

While we are talking headers, let me add here that the headers are still the same as in HTTP/1.1, except for the addition of some pseudo headers i.e. :method, :scheme, :host and :path

### Server Push

Server push is another tremendous feature of HTTP/2 where the server, knowing that the client is going to ask for a certain resource, can push it to the client without even client asking for it. For example, let’s say a browser loads a web page, it parses the whole page to find out the remote content that it has to load from the server and then sends consequent requests to the server to get that content.

Server push allows the server to decrease the roundtrips by pushing the data that it knows that client is going to demand. How it is done is, server sends a special frame called PUSH_PROMISE notifying the client that, “Hey, I am about to send this resource to you! Do not ask me for it.” The PUSH_PROMISE frame is associated with the stream that caused the push to happen and it contains the promised stream ID i.e. the stream on which the server will send the resource to be pushed.

### Request Prioritization

A client can assign a priority to a stream by including the prioritization information in the HEADERS frame by which a stream is opened. At any other time, client can send a PRIORITY frame to change the priority of a stream.

Without any priority information, server processes the requests asynchronously i.e. without any order. If there is priority assigned to a stream, then based on this prioritization information, server decides how much of the resources need to be given to process which request.

### Security

There was extensive discussion on whether security (through TLS) should be made mandatory for HTTP/2 or not. In the end, it was decided not to make it mandatory. However, most vendors stated that they will only support HTTP/2 when it is used over TLS. So, although HTTP/2 doesn’t require encryption by specs but it has kind of become mandatory by default anyway. With that out of the way, HTTP/2 when implemented over TLS does impose some requirementsi.e. TLS version 1.2 or higher must be used, there must be a certain level of minimum keysizes, ephemeral keys are required etc.




## Detailed Protocol Structure

### A. Binary Framing Layer

- **Frames and Streams:**  
  - **Frames:** The smallest unit in HTTP/2 is the frame. Each frame encapsulates a specific type of data (such as header or data frames). Frames are identified by their type (e.g., HEADERS, DATA, PRIORITY, RST_STREAM) and are the basic elements that the protocol uses to define the exchange between client and server.
  - **Streams:** Each HTTP/2 connection can handle multiple concurrent streams. A stream is an independent, bidirectional channel within the connection. Every stream is identified by a unique identifier, and frames belonging to different streams are interleaved.

- **Advantages:**  
  The binary framing layer allows for more efficient parsing and better error handling. It is less susceptible to ambiguity than a text-based protocol, reducing the likelihood of misinterpretation by either client or server.


### C. Header Compression: HPACK

- **Static and Dynamic Tables:**  
  HPACK uses a combination of static and dynamic tables to store header fields. The static table contains a pre-defined set of header fields while the dynamic table is built up as header information is exchanged.
  
- **Compression Techniques:**  
  By only sending header indices (rather than the full header field data) when the same header is repeatedly used, HPACK significantly reduces the amount of redundant data transmitted.

### D. Stream Prioritization

- **Priority Weighting:**  
  Each stream can be given a weight relative to other streams. This system enables the client and server to coordinate which streams should be processed and delivered first.

- **Dependency Trees:**  
  Streams can also be dependent on one another. A dependent stream will only be fully processed when its parent stream has been adequately handled, ensuring that critical tasks are not delayed by less important ones.

### E. Flow Control

- **Window Management:**  
  HTTP/2 includes mechanisms to avoid overwhelming the client or the server. Flow control is applied at both the connection level and the individual stream level, allowing for finely tuned regulation of data transmission.
  
- **Dynamic Adjustment:**  
  The window sizes can be negotiated between endpoints, enabling adaptive control based on the current network conditions and resource availability.

### F. Server Push

- **Use Cases:**  
  Server push is particularly useful for web pages that request multiple resources. When the server anticipates that a client will need certain resources (e.g., CSS or JavaScript files), it can send them immediately without waiting for separate client requests.
  
- **Control Mechanism:**  
  The client retains control over which pushed resources it accepts. In many implementations, a client can “reject” or reset pushed streams that it doesn’t require.

### G. Security Considerations

- **Encryption:**  
  Although HTTP/2 does not mandate encryption, most implementations use TLS for added security and performance benefits with modern cryptographic protocols. In many cases, browsers only support HTTP/2 over TLS.
  
- **Improved Privacy:**  
  The compression and multiplexing mechanisms in HTTP/2 are designed not only to boost performance but also to secure the transmission of data, ensuring that sensitive header information is adequately protected.

---

## 4. Implementing and Testing HTTP/2

- **Server Implementations:**  
  Many major web servers (such as Apache, NGINX, and IIS) now support HTTP/2 either natively or through modules. When configuring these servers, understanding their specific implementation of features (like server push or prioritization) is key to optimizing performance.

- **Client Support:**  
  Modern web browsers, including Chrome, Firefox, and Edge, fully support HTTP/2. Testing tools such as curl (with the `--http2` flag) or various online HTTP/2 test suites are useful for verifying correct behavior.

- **Debugging:**  
  Tools like Wireshark can decode and analyze HTTP/2 frames, allowing developers to see how multiplexing and header compression are functioning. Browser developer tools also offer a view into HTTP/2 communications by displaying frame-level details of requests and responses.

---

## 5. Performance Optimization Strategies

- **Resource Prioritization:**  
  Leverage stream prioritization to ensure that critical resources load faster by assigning them a higher priority.

- **Minimizing Round Trips:**  
  Use server push wisely to reduce the number of round trips required for loading resources, while also being cautious not to push unneeded data.
  
- **Optimizing Flow Control:**  
  Fine-tuning the flow control window sizes can help mitigate the adverse effects of network latency or packet loss.

- **Monitoring and Analytics:**  
  Continuously monitor server performance metrics and network traffic. Analyze logs to understand and subsequently mitigate potential bottlenecks.

---

## 6. Further Reading and Resources

- **Official HTTP/2 Specification:**  
  Review the HTTP/2 standard provided by the IETF for precise protocol definitions and implementation guidelines.

- **Developer Documentation:**  
  - Mozilla Developer Network (MDN) provides detailed articles on HTTP/2 concepts, practical implementation, and performance tips.  
  - Explore the official HTTP/2 website and its resources, which include conceptual overviews and detailed technical specifications.

- **Case Studies and Performance Benchmarks:**  
  Look for benchmark studies comparing HTTP/1.1 and HTTP/2 performance in various scenarios. These case studies provide insights into how adopting HTTP/2 has improved speed and efficiency for high-traffic websites.





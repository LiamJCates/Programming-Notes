### DNS 

We usually use a name to reach a website. 

While each server has a unique IP address, since 72.14.205.100 doesn't roll off the tongue, we give them Domain Names like google.com.
That is, we alias an IP address with a human readable domain name.

A domain or domain name is a unique, symbolic name or term for a specific area or sever on the internet. 
This name is entered by the end-user to access a specific website.

The Domain Name System (DNS) associates domain name with the corresponding IP addresses
like a phonebook associates names to phone numbers.



https://support.hostpoint.ch/en/products/domain/frequently-asked-questions/what-is-a-domain

#### Who manages domains?

DNS was originally created to be an open and public communication protocol for government and educational institutions.

One DNS server can't handle requests from all devices. 
DNS servers are connected in a distributed hierarchy and are divided into zones, 
splitting up responsibility for the major domains such as .org, .com, .net, etc.

Domains are not assigned and managed by a centralized body, but are the result of an interplay between several people and organizations:

##### Registrant

The registrant is a person or organization that registers a domain name as an end customer. The registrant is therefore the owner of the domain name.

##### Registrar

The registrar is a company that registers the domain name with the relevant registry on behalf of the registrant and charges the registrant (end customer) the cost of doing so. The registrar shall ensure that the domain name complies with the specifications of the relevant registry.

##### Registry

The registry is a central registration body that manages one or more top-level domains. 

gTLD registries
As the name suggests, these organizations maintain generic extensions. Some of them like VeriSign (.com, .net) and Afilias (.info) have been around for a while. Others are either newly established companies or subsidiaries of existing ones. They manage the so-called new gTLDs. Branded TLDs like .google are an example of new extensions managed by a subsidiary of a larger existing company. Generic TLDs like .xyz or .tech are examples of extensions that are governed by newly created organizations.

##### National registries
These organizations are de jure independent, but they are usually government-led organizations that maintain the original country-code extensions like .de, .uk or .mx and new ones like .london. Country-code registries abide by the rules set by ICANN regarding the administration of top-level domains, but they also adopt country-specific policies that may be unique for a particular extension. If you want to register a .com.au domain name for example, you will need a valid Australian business number.

##### ICANN

ICANN (Internet Corporation for Assigned Names and Numbers) is a global non-profit organization and the world’s highest body for assigning and regulating domains. ICANN ensures that each domain exists only once, is unique and accessible, and regulates management and coordination of the Domain Name System (DNS).

ICANN is also responsible for the accreditation of registrars who wish to register domain names with generic top-level domains. To be accredited by ICANN, a registrar must undergo a process and meet certain security and stability requirements.


https://www.icdsoft.com/blog/who-is-who-in-the-domain-name-industry/


#### DNS Resolution

When a user wants to load a webpage, a translation must occur between domain name and IP address.
This process is called DNS resolution

DNS resolution converts a human-friendly hostname (such as www.example.com) into a computer-friendly IP address (such as 192.168.1.1). 


In order to understand the process behind the DNS resolution, it's important to learn about the different hardware components a DNS query must pass between. For the web browser, the DNS lookup occurs "behind the scenes" and requires no interaction from the user's computer apart from the initial request.

There are 4 DNS servers involved in loading a webpage:

    DNS recursor - The recursor can be thought of as a librarian who is asked to go find a particular book somewhere in a library. The DNS recursor is a server designed to receive queries from client machines through applications such as web browsers. Typically the recursor is then responsible for making additional requests in order to satisfy the client's DNS query.

    Root nameserver - The root server is the first step in translating (resolving) human readable host names into IP addresses. It can be thought of like an index in a library that points to different racks of books - typically it serves as a reference to other more specific locations.

    TLD nameserver - The top level domain server (TLD) can be thought of as a specific rack of books in a library. This nameserver is the next step in the search for a specific IP address, and it hosts the last portion of a hostname (In example.com, the TLD server is “com”).

    Authoritative nameserver - This final nameserver can be thought of as a dictionary on a rack of books, in which a specific name can be translated into its definition. The authoritative nameserver is the last stop in the nameserver query. If the authoritative name server has access to the requested record, it will return the IP address for the requested hostname back to the DNS Recursor (the librarian) that made the initial request.


When you enter a domain, a request will be sent to the corresponding name server. The name server searches its database for the correct IP address of this domain and responds. The browser can then display the desired website. This usually happens within milliseconds.



![DNS Resolution](DNS Resolution.png)









 SQL (relational) vs. NoSQL (nonrelational) databases



Though there are many types of NoSQL databases with varying features, the following table shows some of the differences between SQL and NoSQL databases.

NoSQL databases

Optimal workloads

	Relational databases are designed for transactional and strongly consistent online transaction processing (OLTP) applications and are good for online analytical processing (OLAP). 	

	NoSQL databases are designed for a number of data access patterns that include low-latency applications. NoSQL search databases are designed for analytics over semi-structured data.

Data model 	

The relational model normalizes data into tables that are composed of rows and columns. A schema strictly defines the tables, rows, columns, indexes, relationships between tables, and other database elements. The database enforces the referential integrity in relationships between tables.

NoSQL databases provide a variety of data models such as key-value, document, and graph, which are optimized for performance and scale.


CAP Theorem
[Problem Domains\Distributed\CAP.md]

CAP stands for

    Consistency: All reads receive the most recent write or an error.
			Optimally, all the nodes see the same data at the same time.

    Availability: All reads contain data, but it might not be the most recent.
			gives us a guarantee that there will be a response for every request made to the system about whether it was successful or not

	Partition tolerance: The system continues to operate despite network failures (ie; dropped partitions, slow network connections, or unavailable network connections between nodes.)
			NoSQL database management system will work even if a part of the system has failed or is not working

Of these three things, any given distributed database can really only excel at two of them.

distributed relational databases tend to excel at consistency and partition tolerance
distributed NoSQL databases tend to excel at availability and partition tolerance.

In the theorem, partition tolerance is a must.
The assumption is that the system operates on a distributed data store so the system, by nature, operates with network partitions. Network failures will happen, so to offer any kind of reliable service, partition tolerance is necessary.

That leaves a decision between the other two, C and A. When a network failure happens, one can choose to guarantee consistency or availability:

    High consistency comes at the cost of lower availability.
    High availability comes at the cost of lower consistency.


Consistent databases should be used when the value of the information returned needs to be accurate.
Financial databases should be consistent

Availability databases should be used when the service is more important than the information.
E-commerce and Content Distribution databases should be available

NOTE:
Consistency in CAP is different than that of ACID. Consistency in CAP means having the most up-to-date information. (ACID refers to a different database event. In ACID, consistency means any new transaction to the database won’t corrupt the database.)





ACID properties 	




NoSQL databases often make tradeoffs by relaxing some of the ACID properties of relational databases for a more flexible data model that can scale horizontally. This makes NoSQL databases an excellent choice for high throughput, low-latency use cases that need to scale horizontally beyond the limitations of a single instance.


Performance 	

Relational database performance is generally dependent on the disk subsystem. The optimization of queries, indexes, and table structure is often required to achieve peak performance. 	

NoSQL database performance is generally a function of the underlying hardware cluster size, network latency, and the calling application.



Scale

Relational databases typically scale up by increasing the compute capabilities of the hardware or scale-out by adding replicas for read-only workloads. 	

NoSQL databases typically are partitionable because access patterns are able to scale out by using distributed architecture to increase throughput that provides consistent performance at near boundless scale.


APIs

Requests to store and retrieve data are communicated using queries that conform to a structured query language (SQL). These queries are parsed and executed by the relational database. 	

NoSQL databases implement an Object-based APIs which allow app developers to easily store and retrieve data structures. Partition keys let apps look up key-value pairs, column sets, or semi-structured documents that contain serialized app objects and attributes.






Types of NoSQL Databases

	Key-value: Key-value databases are highly partitionable and allow horizontal scaling at scales that other types of databases cannot achieve. Use cases such as gaming, ad tech, and IoT lend themselves particularly well to the key-value data model. Amazon DynamoDB is designed to provide consistent single-digit millisecond latency for any scale of workloads. This consistent performance is a big part of why the Snapchat Stories feature, which includes Snapchat's largest storage write workload, moved to DynamoDB.

	Document: In application code, data is represented often as an object or JSON-like document because it is an efficient and intuitive data model for developers. Document databases make it easier for developers to store and query data in a database by using the same document model format that they use in their application code. The flexible, semistructured, and hierarchical nature of documents and document databases allows them to evolve with applications’ needs. The document model works well with catalogs, user profiles, and content management systems where each document is unique and evolves over time. Amazon DocumentDB (with MongoDB compatibility) and MongoDB are popular document databases that provide powerful and intuitive APIs for flexible and iterative development.

	Graph: A graph database’s purpose is to make it easy to build and run applications that work with highly connected datasets. Typical use cases for a graph database include social networking, recommendation engines, fraud detection, and knowledge graphs. Amazon Neptune is a fully-managed graph database service. Neptune supports both the Property Graph model and the Resource Description Framework (RDF), providing the choice of two graph APIs: TinkerPop and RDF/SPARQL. Popular graph databases include Neo4j and Giraph.

	In-memory: Gaming and ad-tech applications have use cases such as leaderboards, session stores, and real-time analytics that require microsecond response times and can have large spikes in traffic coming at any time. Amazon ElastiCache offers Memcached and Redis, to serve low-latency, high-throughput workloads, such as McDonald’s, that cannot be served with disk-based data stores. Amazon DynamoDB Accelerator (DAX) is another example of a purpose-built data store. DAX makes DynamoDB reads an order of magnitude faster.

	Search: Many applications output logs to help developers troubleshoot issues. Amazon Elasticsearch Service (Amazon ES) is purpose built for providing near-real-time visualizations and analytics of machine-generated data by indexing, aggregating, and searching semistructured logs and metrics. Amazon ES also is a powerful, high-performance search engine for full-text search use cases. Expedia is using more than 150 Amazon ES domains, 30 TB of data, and 30 billion documents for a variety of mission-critical use cases, ranging from operational monitoring and troubleshooting to distributed application stack tracing and pricing optimization.





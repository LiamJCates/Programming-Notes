NoSQL is a term used to describe nonrelational database systems


NoSQL databases are widely recognized for their ease of development, functionality, and performance at scale.

Instead of the relational model, NoSQL databases (like DynamoDB) use alternate models for data management, such as key-value pairs or document storage.

NoSQL databases are purpose built for specific data models and have flexible schemas for building modern applications.


NoSQL databases use a variety of data models for accessing and managing data. These types of databases are optimized specifically for applications that require

large data volume,
low latency
flexible data models,

which are achieved by relaxing some of the data consistency restrictions of other databases.





Consider the example of modeling the schema for a simple book database:

In a relational database, a book record is often dissembled (or “normalized”) and stored in separate tables, and relationships are defined by primary and foreign key constraints.

		In this example,
		the Books table has columns for ISBN, Book Title, and Edition Number,
		the Authors table has columns for AuthorID and Author Name
		the Author-ISBN table has columns for AuthorID and ISBN.

		The relational model is designed to enable the database to enforce referential integrity between tables in the database, normalized to reduce the redundancy, and generally optimized for storage.

In a NoSQL database, a book record is usually stored as a JSON document.

	For each book, the item, ISBN, Book Title, Edition Number, Author Name, and AuthorID are stored as attributes in a single document.

In this model, data is optimized for intuitive development and horizontal scalability.






Why should you use a NoSQL database?

NoSQL databases are a great fit for many modern applications such as mobile, web, and gaming that require flexible, scalable, high-performance, and highly functional databases to provide great user experiences.

   Flexibility: NoSQL databases generally provide flexible schemas that enable faster and more iterative development. The flexible data model makes NoSQL databases ideal for semi-structured and unstructured data.

	 Scalability: NoSQL databases are generally designed to scale out by using distributed clusters of hardware instead of scaling up by adding expensive and robust servers. Some cloud providers handle these operations behind-the-scenes as a fully managed service.

	 High-performance: NoSQL database are optimized for specific data models and access patterns that enable higher performance than trying to accomplish similar functionality with relational databases.

	 Highly functional: NoSQL databases provide highly functional APIs and data types that are purpose built for each of their respective data models.






 SQL (relational) vs. NoSQL (nonrelational) databases

For decades, the predominant data model that was used for application development was the relational data model used by relational databases such as Oracle, DB2, SQL Server, MySQL, and PostgreSQL. It wasn’t until the mid to late 2000s that other data models began to gain significant adoption and usage. To differentiate and categorize these new classes of databases and data models, the term “NoSQL” was coined. Often the term “NoSQL” is used interchangeably with “nonrelational.”

Though there are many types of NoSQL databases with varying features, the following table shows some of the differences between SQL and NoSQL databases.
Getting Started with NoSQL
NoSQL databases

Optimal workloads

	Relational databases are designed for transactional and strongly consistent online transaction processing (OLTP) applications and are good for online analytical processing (OLAP). 	

	NoSQL databases are designed for a number of data access patterns that include low-latency applications. NoSQL search databases are designed for analytics over semi-structured data.

Data model 	

The relational model normalizes data into tables that are composed of rows and columns. A schema strictly defines the tables, rows, columns, indexes, relationships between tables, and other database elements. The database enforces the referential integrity in relationships between tables.

NoSQL databases provide a variety of data models such as key-value, document, and graph, which are optimized for performance and scale.


CAP Theorem
CAP stands for

    Consistency: All reads receive the most recent write or an error.
			Optimally, all the nodes see the same data at the same time.

    Availability: All reads contain data, but it might not be the most recent.
			gives us a guarantee that there will be a response for every request made to the system about whether it was successful or not

		Partition tolerance: The system continues to operate despite network failures (ie; dropped partitions, slow network connections, or unavailable network connections between nodes.)
			 NoSQL database management system will work even if a part of the system has failed or is not working

Of these three things, any given database can really only excel at two of them.

relational databases tend to excel at consistency and partition tolerance
NoSQL databases tend to excel at availability and partition tolerance.

In the theorem, partition tolerance is a must.
The assumption is that the system operates on a distributed data store so the system, by nature, operates with network partitions. Network failures will happen, so to offer any kind of reliable service, partition tolerance is necessary—the P of CAP.

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

Relational databases provide atomicity, consistency, isolation, and durability (ACID) properties:
    Atomicity requires a transaction to execute completely or not at all.

		Consistency requires that when a transaction has been committed, the data must conform to the database schema.

		Isolation requires that concurrent transactions execute separately from each other.

		Durability requires the ability to recover from an unexpected system failure or power outage to the last known state.


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



SQL vs. NoSQL Terminology

The following table compares terminology used by select NoSQL databases with terminology used by SQL databases.


| SQL | MongoDB | DynamoDB | Cassandra  | Couchbase |
|-----|---------|----------|------------|-----------|
| Table | Collection | Table | Table | Data bucket |
| Row | Document | Item | Row | Document |
| Column | Field | Attribute | Column | Field |
| Primary key | ObjectId | Primary key | Primary key | Document ID |
| Index | Index | Secondary index | Index | Index |
| View | View | Global secondary index | Materialized view | View |
| Nested table or object | Embedded document | Map | Map | Map |
| Array | Array | List | List | List |



Types of NoSQL Databases

	Key-value: Key-value databases are highly partitionable and allow horizontal scaling at scales that other types of databases cannot achieve. Use cases such as gaming, ad tech, and IoT lend themselves particularly well to the key-value data model. Amazon DynamoDB is designed to provide consistent single-digit millisecond latency for any scale of workloads. This consistent performance is a big part of why the Snapchat Stories feature, which includes Snapchat's largest storage write workload, moved to DynamoDB.

	Document: In application code, data is represented often as an object or JSON-like document because it is an efficient and intuitive data model for developers. Document databases make it easier for developers to store and query data in a database by using the same document model format that they use in their application code. The flexible, semistructured, and hierarchical nature of documents and document databases allows them to evolve with applications’ needs. The document model works well with catalogs, user profiles, and content management systems where each document is unique and evolves over time. Amazon DocumentDB (with MongoDB compatibility) and MongoDB are popular document databases that provide powerful and intuitive APIs for flexible and iterative development.

	Graph: A graph database’s purpose is to make it easy to build and run applications that work with highly connected datasets. Typical use cases for a graph database include social networking, recommendation engines, fraud detection, and knowledge graphs. Amazon Neptune is a fully-managed graph database service. Neptune supports both the Property Graph model and the Resource Description Framework (RDF), providing the choice of two graph APIs: TinkerPop and RDF/SPARQL. Popular graph databases include Neo4j and Giraph.

	In-memory: Gaming and ad-tech applications have use cases such as leaderboards, session stores, and real-time analytics that require microsecond response times and can have large spikes in traffic coming at any time. Amazon ElastiCache offers Memcached and Redis, to serve low-latency, high-throughput workloads, such as McDonald’s, that cannot be served with disk-based data stores. Amazon DynamoDB Accelerator (DAX) is another example of a purpose-built data store. DAX makes DynamoDB reads an order of magnitude faster.

	Search: Many applications output logs to help developers troubleshoot issues. Amazon Elasticsearch Service (Amazon ES) is purpose built for providing near-real-time visualizations and analytics of machine-generated data by indexing, aggregating, and searching semistructured logs and metrics. Amazon ES also is a powerful, high-performance search engine for full-text search use cases. Expedia is using more than 150 Amazon ES domains, 30 TB of data, and 30 billion documents for a variety of mission-critical use cases, ranging from operational monitoring and troubleshooting to distributed application stack tracing and pricing optimization.

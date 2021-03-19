What is NoSQL?

NoSQL stands for ‘Not Only SQL’, but it is also evolved due to some restrictions & challenges with the traditional databases. NoSQL databases are designed to work with large distributed data sets. NoSQL databases are highly and flexible; they allow us to store and process unstructured and semi-structured data that cannot be easily handled by using a relational database system (RDBMS). These databases are basically used for processing big data in real-time web applications.

NoSQL encompasses a wide variety of different database technologies that were developed in response to a rise in the volume of data stored about users, objects and products. The frequency in which this data is accessed, and performance and processing needs. Relational databases, on the other hand, were not designed to cope with the scale and agility challenges that face modern applications, nor were they built to take advantage of the cheap storage and processing power available today.



What are the features of NoSQL?

When compared to relational databases, NoSQL databases are more scalable and provide superior performance, and their data model addresses several issues that the relational model is not designed to address:

    Large volumes of structured, semi-structured, and unstructured data
    Agile sprints, quick iteration, and frequent code pushes
    Object-oriented programming that is easy to use and flexible
    Efficient, scale-out architecture instead of expensive, monolithic architecture


		features of NoSQL:

		    Flexibility: NoSQL offers flexibility to store structured, semi-structured or unstructured data, unlike a relational database which allows only structured data.
		    Dynamic Schemas: In NoSQL, schema definition is not required; this solves the problem to modify the schema where a table is already present with huge datasets, and new columns need to be added to the same table.
		    Sharding: Sharding means partitioning data into smaller databases to have faster access to data. This feature is present in NoSQL databases, allowing us to fetch data from a server in the fastest time.
		    Generic: the user can customize the NoSQL database as per the need.
		    Scaling: NoSQL databases scale-out horizontally; thus, they are cheaper to manage.


Some of the key features or highlights of NoSQL database are as follows:

  It is Schema Agnostic through which any data can be stored without the need for upfront schema design
  It supports auto-sharding and it is highly elastic as it allows the users to automatically share the workload to any number of servers
  It is highly distributable and so it makes use of a cluster of servers to store a single huge database
  It is highly scalable which ensures NoSQL database to support any volume of data and highly complex cloud applications
  It supports integrated caching through which the data that are cached will be transparent and all the application developers and operation team can view it at ease





major challenges with RDBMS systems:

    Not optimized to scale out: RDBMS systems are not optimized for horizontal scaling out.
    Not able to handle unstructured data: RDBMS systems are not able to handle schema-less data (semi-structured or unstructured)
    Costly: There is a high licensing cost for data analysis with RDBMS systems.
    Not able to handle the high velocity of data ingestion: RDBMS systems are designed for steady data retention.



How Does NoSQL relate to big data?

NoSQL databases are designed with “Big Data” needs in mind. Since a fixed schema model does not bind them, this makes them suitable for today’s business needs where there is a large volume of non-uniform data (Big Data).



What is BASE?
The CAP theorem states that distributed systems cannot achieve all three properties simultaneously: consistency, availability, and partition tolerance. The BASE system gives up on consistency while maintaining the other two. The BASE system works well despite physical network partitions and always allow a client with reading and write availability.

    The BASE stands for:
    Basically Available
    Soft state
    Eventual consistency


What do you mean by eventual consistency in NoSQL stores?

Eventual consistency in NoSQL means that when all the service logics have been executed, the system is left in a consistent state. For achieving high availability, this concept is used in the distributed systems. It gives a guarantee that, if new updates are not made to a given data item, then eventually all accesses to that item will return the last updated value. In NoSQL, it is provided in terms of BASE and RDMS also known as ACID properties. Present NoSQL databases provide client applications with guarantee of eventual consistency. Some NoSQL databases like- MongoDB and Cassandra are eventually consistent in some of the configurations




List the different kinds of NoSQL data stores?

The variety of NoSQL data stores available which are widely distributed are categorized into four categories. They are:

Key value store- it is a simple data storage key system which uses keys to access different values.

Document stores- it is used for storing hierarchical data structures directly in the database.

Column family store- it is a sparse matrix system. It uses columns and rows as keys.

Graph store- it is used in case of relationships-intensive problems.



What are advantages and disadvantages of NoSQL?

Advantages of NoSQL

    Using the new node concepts, the database of NoSQL can be expanded to the set limit. Low commodity hardware takes this point as an added advantage.
    NoSQL databases are used to store a massive volume of information. Big data and recently posted user reviews utilize the concept of NoSQL.
    There is no expensive administration required to monitor the database of NoSQL.
    NoSQL can be installed with cheap economy instead of spending money on complicated systems.

Disadvantages of NoSQL

    Since NoSQL is a new technology of database storage, there are many other systems in the market which are already leading in the market.
    The previously built systems have the support available round the clock, but the NoSQL support system is less comparatively.
    Since NoSQL is a new technology, it is not supporting the old commands that are used in the system.






Can you differentiate both SQL database and NoSQL database?

SQL Database
	It performs well with the relational database system
	It is vertically scalable
	The systems that come under SQL database is fixed and does not support
	flexibility
	It does not support hierarchical data storage
	Queries of any complexity can be handled

NoSQL Database
	It performs well with the distributed database system
	It is horizontally scalable
	In NoSQL database, all the systems are dynamic and it is completely flexible
	It supports hierarchical data storage
	It cannot handle highly complex queries



How is NoSQL database and Relational Database Management System or RDBMS different from each other?

NoSQL Database
	NoSQL does not follow any data pattern or data format
	NoSQL database is highly scalable
	It is limited and ensures several restrictions in terms of query
	NoSQL database uses key value pair, documents and column for storage

Relational Database Management System or RDBMS
	RDBMS it highly organized and structured
	RDBMS is less scalable
	As it is a structured query language it supports any form of queries
	RDBMS makes use of table to store values and relationships


Following is a list of the differences between NoSQL and RDBMS:

Data format,
	NoSQL does not follow any order for its data format.
	RDBMS is more organized and structured when it comes to the format of its data.

Scalability
	NoSQL is more scalable.
	Whereas, RDBMS is average and less scalable than NoSQL.

For querying of data,
	NoSQL is limited in terms of querying because there is no join clause present in NoSQL.
	Whereas, querying can be used in RDBMS as it uses the structured query language.

The difference in the storage mechanism
	NoSQL uses key value pair, documents, column storage, etc. for storage.
	Whereas, RDBMS uses various tables for storing data and relationships.

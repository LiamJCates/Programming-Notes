# NoSQL Overview

**NoSQL** is a term used to describe non-relational database systems.

NoSQL stands for **“Not Only SQL”**. It evolved due to some restrictions and challenges with traditional relational databases — where SQL is synonymous with the relational model. While relational databases work exceptionally well for structured data and complex transactions, scaling them (especially horizontally across distributed systems) proved challenging. As applications and data volumes grew (particularly with the advent of the internet), the need for more flexible, scalable solutions became apparent. 

NoSQL databases support a flexible data model by storing unstructured or semi-structured data more easily.

Instead of the relational model, NoSQL databases implement alternate models for data management, such as key-value pairs, document storage, and more.

NoSQL databases are widely recognized for their ease of development, functionality, and performance at scale. Developers can work faster and more productively with data structures that match the application's read/write needs. Businesses often use a mix of NoSQL databases to meet their requirements.

Some NoSQL databases also provide native, built-in horizontal and vertical scaling capabilities. They work in distributed environments and provide high availability and fault tolerance. In addition, these databases are purpose-built for specific data models and offer flexible schemas for building modern applications.

> **Optimized for:**  
> - large data volume  
> - low latency  
> - flexible data models  

*(These are often achieved by relaxing some of the data consistency restrictions of relational models.)*

It is generally agreed that NoSQL databases fall into four categories:
- **Key-Value**
- **Document**
- **Column-based**
- **Graph**

There is some overlap among these types, so the definitions aren’t always clear.


---

## Use Cases: Social Media Platforms

Businesses often use a mix of NoSQL databases for their needs.

Social media NoSQL databases:
- **Document databases** to manage user profiles.
- **Column databases** to store user activity feed information.
- **Key-Value databases** to manage user sessions and speed access to frequently used data.
- **Graph databases** to maintain connections by storing information about friends and relationships.

---

## Example: Modeling a Book Database Schema

### Relational Database Approach

In a relational database, a book record is often **normalized** and stored across separate tables with relationships defined by primary and foreign key constraints. For example:

- **Books Table:** Columns for ISBN, Book Title, and Edition Number.
- **Authors Table:** Columns for AuthorID and Author Name.
- **Author-ISBN Table:** Columns for AuthorID and ISBN.

This relational model enforces referential integrity between tables, reduces redundancy, and is optimized for storage.

### NoSQL Database Approach

In a NoSQL database, a book record is typically stored as a **JSON document**. For each book, attributes like ISBN, Book Title, Edition Number, Author Name, and AuthorID are stored together in a single document. This approach is optimized for intuitive development and horizontal scalability.

---

## Why Use a NoSQL Database?

NoSQL databases are well-suited for modern applications that demand flexible, scalable, high-performance, and highly functional data storage.

- **Flexibility:**  
  NoSQL databases provide flexible schemas, enabling faster and more iterative development. This flexibility is ideal for semi-structured and unstructured data.

- **Scalability:**  
  They are generally designed to scale out using distributed clusters of hardware instead of relying solely on scaling up with expensive servers. Many cloud providers now offer fully managed NoSQL services, where horizontal scaling operations are handled behind-the-scenes.

- **High Performance:**  
  Optimized for specific data models and access patterns, NoSQL databases can achieve higher performance than traditional relational databases for certain workloads.

- **Highly Functional:**  
  They offer specialized APIs and data types that are purpose-built for their respective data models.

---

## SQL (Relational) vs. NoSQL (Nonrelational) Databases

For decades, the relational data model (used by databases such as Oracle, DB2, SQL Server, MySQL, and PostgreSQL) was predominant. It wasn’t until the mid-to-late 2000s that alternative data models began to gain adoption. To categorize these new databases, the term **NoSQL** was coined—often used interchangeably with “non-relational.”

### Comparison Table

| Feature            | Relational Databases | NoSQL Databases                                                 |
|--------------------|----------------------|-----------------------------------------------------------------|
| **Optimal Workloads** | Transactional, strongly consistent OLTP; good for OLAP. | Designed for low-latency applications and analytics on semi-structured data. |
| **Data Model**     | Normalizes data into tables with a strict schema and enforced referential integrity. | Offers various models (key-value, document, graph) optimized for performance and scale. |
| **CAP Theorem**    | Typically excel in consistency and partition tolerance. | Tend to excel in availability and partition tolerance.          |
| **ACID Properties**| Enforces atomicity, consistency, isolation, and durability (ACID). | Often relaxes some ACID properties for greater flexibility and scalability. |
| **Performance**    | Depends on disk subsystem; query, index, and schema optimizations are common. | Performance relies on cluster size, network latency, and specific access patterns. |
| **Scale**          | Scales vertically (more powerful hardware) or with read replicas for horizontal scaling. | Designed to scale out horizontally using distributed architectures. |
| **APIs**           | Uses SQL queries for data manipulation. | Implements object-based APIs suited to various data models.      |

---

## CAP Theorem

[Refer to `Problem Domains/Distributed/CAP.md`](Problem%20Domains/Distributed/CAP.md)

**CAP stands for:**

- **Consistency:** All reads receive either the most recent write or an error, ideally ensuring that all nodes see the same data simultaneously.
- **Availability:** Every request receives a response—even if it may not be the most recent data.
- **Partition Tolerance:** The system continues to operate despite network failures (e.g., dropped partitions or slow/unavailable connections).

A distributed database can generally excel at only two of these three properties:
- **Distributed relational databases:** Tend to excel at consistency and partition tolerance.
- **Distributed NoSQL databases:** Tend to excel at availability and partition tolerance.

When a network failure occurs, you must choose between consistency and availability:
- **High consistency** comes at the cost of lower availability.
- **High availability** comes at the cost of lower consistency.

> **Use Case Guidance:**  
> - Use **consistent databases** (e.g., for financial applications) when the accuracy of the returned information is paramount.  
> - Use **availability-focused databases** (e.g., for e-commerce) when ensuring a continuous service is more critical.

> **Note:** Consistency in the context of CAP means having the most up-to-date information, which is different from ACID consistency (i.e., ensuring that a transaction does not corrupt the database).

---

## ACID Properties

Relational databases adhere to ACID properties:

- **Atomicity:** A transaction must be executed completely or not at all.
- **Consistency:** Data must conform to the defined schema after a transaction.
- **Isolation:** Concurrent transactions should operate independently.
- **Durability:** The system must recover to the last known state after a failure.

NoSQL databases often trade off some of these properties to allow for more flexible data models and horizontal scalability, making them an excellent choice for high-throughput, low-latency scenarios.

---

## Additional Considerations

### Performance

- **Relational Databases:**  
  Performance is often dependent on the disk subsystem. Optimizing queries, indexes, and table structures is key to peak performance.

- **NoSQL Databases:**  
  Performance is generally a function of the underlying hardware cluster size, network latency, and application-specific access patterns.

### Scale

- **Relational Databases:**  
  Typically scale up by increasing hardware capabilities or scale out by adding replicas for read-only workloads.

- **NoSQL Databases:**  
  Are inherently partitionable and designed to scale out using distributed architectures, which can provide consistent performance at near boundless scale.

### APIs

- **Relational Databases:**  
  Use structured query language (SQL) for data manipulation.

- **NoSQL Databases:**  
  Often implement object-based APIs that simplify the storage and retrieval of complex data structures.

---

## SQL vs. NoSQL Terminology

The following table compares terminology used by select NoSQL databases with that used in SQL databases:

| SQL                        | MongoDB        | DynamoDB    | Cassandra   | Couchbase    |
|----------------------------|----------------|-------------|-------------|--------------|
| **Table**                  | Collection     | Table       | Table       | Data bucket  |
| **Row**                    | Document       | Item        | Row         | Document     |
| **Column**                 | Field          | Attribute   | Column      | Field        |
| **Primary key**            | ObjectId       | Primary key | Primary key | Document ID  |
| **Index**                  | Index          | Secondary index | Index   | Index        |
| **View**                   | View           | Global secondary index | Materialized view | View |
| **Nested table/object**    | Embedded document | Map     | Map         | Map          |
| **Array**                  | Array          | List        | List        | List         |

---

## Types of NoSQL Databases

- **Key-Value:**  
  Highly partitionable and scalable. Commonly used in gaming, ad tech, and IoT.  
  *Example:* Amazon DynamoDB provides consistent single-digit millisecond latency.

- **Document:**  
  Data is stored as JSON-like documents, making it intuitive for developers.  
  *Examples:* Amazon DocumentDB (with MongoDB compatibility), MongoDB.

- **Graph:**  
  Optimized for applications that work with highly connected datasets (e.g., social networking, recommendation engines, fraud detection).  
  *Examples:* Amazon Neptune, Neo4j, Giraph.

- **In-Memory:**  
  Designed for real-time analytics, session stores, and leaderboards with microsecond response times.  
  *Examples:* Amazon ElastiCache (Memcached, Redis), Amazon DynamoDB Accelerator (DAX).

- **Search:**  
  Optimized for indexing, aggregating, and searching large volumes of machine-generated data.  
  *Example:* Amazon Elasticsearch Service (Amazon ES), used in scenarios like distributed application monitoring and full-text search.
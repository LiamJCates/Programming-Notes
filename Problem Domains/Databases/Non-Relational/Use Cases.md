Non-relational databases (often called NoSQL) are best used when your application demands one or more of the following characteristics:

1. **Flexible Schema for Unstructured or Semi-Structured Data:**  
   - If your data does not fit neatly into rows and columns or is expected to evolve frequently (e.g., JSON documents, sensor logs, social media posts), a NoSQL database allows you to store data without the need for a rigid schema.  
   - This flexibility speeds up development by removing the need for costly schema migrations.

2. **Horizontal Scalability:**  
   - When your application must handle massive volumes of data or high read/write traffic, NoSQL systems are designed to scale out by distributing data across multiple servers.  
   - This scale-out approach is typically more cost-effective and easier to manage than vertical scaling, especially in cloud environments.

3. **High Throughput and Low Latency:**  
   - For real-time applications—such as chat systems, online gaming, or fraud detection—where fast read/write speeds are critical, NoSQL databases often outperform traditional SQL databases by minimizing overhead (sometimes at the cost of immediate consistency).

4. **Handling Big Data and Analytics:**  
   - If your workload involves processing and analyzing large amounts of unstructured data (like logs, clickstreams, or IoT data), many NoSQL databases are optimized for these use cases and can efficiently support distributed processing.

5. **Specific Data Models:**  
   - Some applications benefit from specialized data models such as:  
     - **Document databases** (e.g., MongoDB) for hierarchical data and object-like structures.  
     - **Key-value stores** (e.g., Redis) for simple, fast access patterns.  
     - **Graph databases** (e.g., Neo4j) for applications that need to manage complex relationships, like social networks or recommendation engines.  
     - **Wide-column stores** (e.g., Cassandra) for handling massive, distributed datasets with high write loads.

6. **Agile Development Environments:**  
   - In scenarios where the requirements are changing rapidly, a NoSQL database’s schema-on-read model (or schema-less design) allows developers to iterate and deploy changes without lengthy downtime for schema alterations.

In summary, choose a non-relational database when your data is highly variable, the scale and performance requirements exceed what a single server (or vertical scaling) can offer, or when your application naturally fits one of the specialized NoSQL models. Conversely, if you need strict consistency (ACID properties) and your data is highly structured with complex relationships, a relational database may be more appropriate.
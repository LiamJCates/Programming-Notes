What is MongoDB?

MongoDB is a leading document-oriented NoSQL database that offers flexibility and scalability for modern applications. Instead of using rows and columns like in relational databases, MongoDB stores data in documents. These documents are stored in collections, which can be thought of as analogous to tables in SQL databases.

However, unlike traditional relational databases, MongoDB doesn’t enforce a predefined schema, allowing each document to have its unique structure.

MongoDB stores data in BSON (Binary JSON) format, which is similar to JSON but optimized for storage and performance. This enables MongoDB to store a wide range of data types, including arrays and nested objects, making it particularly suitable for handling complex, hierarchical data structures.
Document-Oriented Databases

A document-oriented database stores data in the form of documents, which are typically in JSON or BSON format. Each document can store structured, semi-structured, or even unstructured data, offering a high level of flexibility. In MongoDB, documents can vary in structure, meaning one document might have five fields while another in the same collection might have ten, with completely different data types.

Benefit of this approach is that relationships between data can be embedded within documents, reducing the need for joins and improving performance for certain types of queries. For example, customer details and their order history can be stored in the same document, making retrieval much faster and more efficient for operations where this combined data is required.
MongoDB Data Format (JSON-like)

MongoDB stores data in BSON, which allows for the flexibility of JSON but adds support for more data types, such as dates and binary data. Here’s an example of a MongoDB document:

{
    "_id": ObjectId("507f191e810c19729de860ea"),
    "name": "John Doe",
    "email": "john.doe@example.com",
    "age": 30,
    "address": {
        "street": "123 Main St",
        "city": "New York",
        "zip": "10001"
    },
    "hobbies": ["reading", "gaming", "hiking"]
}

This document represents a user with fields such as name, email, age, and address. The _id field is unique to each document and is automatically generated if not specified.
CRUD Operations in MongoDB

CRUD stands for Create, Read, Update, and Delete — the four basic operations to manage data in MongoDB.
1. Create: Adding new documents to a collection

MongoDB provides insertOne() and insertMany() methods to insert documents.

db.users.insertOne({
    "name": "John Doe",
    "email": "john.doe@example.com",
    "age": 30
})

2. Read: Retrieving documents from the database

The find() and findOne() methods allow you to retrieve documents. For example, to find all users older than 25:

db.users.find({ "age": { $gt: 25 } })

3. Update: Modifying existing documents

MongoDB provides updateOne() and updateMany() methods for updating data. For instance, to update a user's email:

db.users.updateOne(
    { "name": "John Doe" },
    { $set: { "email": "new.email@example.com" } }
)

4. Delete: Removing documents

To delete a document, MongoDB offers deleteOne() and deleteMany() methods.

db.users.deleteOne({ "name": "John Doe" })

Conclusion

MongoDB, as a document-oriented NoSQL database, offers tremendous flexibility, scalability, and ease of use, particularly for modern applications dealing with large amounts of unstructured or semi-structured data. Its JSON-like format, dynamic schema, and efficient handling of complex data structures make it a powerful tool for developers. Whether you’re building a real-time application, an e-commerce platform, or a social media app, MongoDB provides a versatile solution for your data management needs.
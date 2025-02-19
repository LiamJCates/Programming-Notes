Amazon Athena is an interactive query service that makes it easy to analyze data directly in Amazon Simple Storage Service (Amazon S3) using standard SQL.

Athena helps you analyze unstructured, semi-structured, and structured data stored in Amazon S3.

With a few actions in the AWS Management Console, you can point Athena at your data stored in Amazon S3 and begin using standard SQL to run ad-hoc queries.


Ad Hoc SQL is very flexible and often more familiar to developers than writing stored procedures because it allows developers to simply construct a string (usually via concatenation) and submit it to the database.

Ad hoc is latin for "for this purpose".
You might call it an "on the fly" query, or a "just so" query.
It's the kind of SQL query you just loosely type out where you need it

var newSqlQuery = "SELECT * FROM table WHERE id = " + myId;

...which is an entirely different query each time that line of code is executed, depending on the value of myId.

The opposite of an ad hoc query is a predefined query such as a Stored Procedure, where you have created a single query for the entire generalized purpose of selecting from that table (say), and pass the ID as a variable.


Athena is serverless, so there is no infrastructure to set up or manage, and you pay only for the queries you run. Athena scales automatically—running queries in parallel—so results are fast, even with large datasets and complex queries.

Items, or objects, are placed into named buckets stored with names which are usually called keys. The main content is the value.

Objects are created, deleted, or updated. Large objects can be streamed, but you cannot modify parts of a value; you need to update the whole object. Partial data access can work via S3 Select.

Every object also has metadata, which includes arbitrary key-value pairs, and is used in a way similar to HTTP headers. Some metadata is system-defined, some are significant when serving HTTP content from buckets or CloudFront, and you can also define arbitrary metadata for your own use.

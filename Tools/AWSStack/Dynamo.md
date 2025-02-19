DynamoDB is a NoSQL database with focuses on speed, flexibility, and scalability.
DynamoDB is priced on a combination of throughput and storage.

Unlike the technologies behind many other Amazon products, DynamoDB is a proprietary AWS product with no interface-compatible alternative available as an open source project. If you tightly couple your application to its API and featureset, it will take significant effort to replace.
The most commonly used alternative to DynamoDB is Cassandra.









Tables, Items, and Attributes
The following are the basic DynamoDB components:
• Tables
Similar to other database systems, DynamoDB stores data in tables. A table is a collection of data. For example, see the example table called People that you could use to store personal contact information about friends, family, or anyone else of interest. You could also have a Cars table to store information about vehicles that people drive.

•Items
Each table contains zero or more items. An item is a group of attributes that is uniquely identifiable among all of the other items.
Items in DynamoDB are similar in many ways to rows, records, or tuples in other database systems. In DynamoDB, there is no limit to the number of items you can store in a table.
Each item in the table has a unique identifier, or primary key, that distinguishes the item from all of the others in the table.

• Attributes –
Each item is composed of one or more attributes. An attribute is a fundamental data element, something that does not need to be broken down any further. For example, an item in a People table contains attributes called PersonID, LastName, FirstName, and so on. For a Departmenttable, an item might have attributes such as DepartmentID, Name, Manager, and so on. Attributes in DynamoDB are similar in many ways to fields or columns in other database systems.
Some of the items have a nested attribute (Address). DynamoDB supports nested attributes up to 32 levels deep.


Table	People


{
	"PersonID": 101,
	"LastName": "Smith",
	"FirstName": "John",
	"Phone": "555-5555"
}

{
	"PersonID": 101,
	"LastName": "Smith",
	"FirstName": "John",
	"Address": {
		"Street": "123 Main",
		"City": "Anytown",
		"State": "NA",
		"ZIPCode": 12345
	}
}

Note the following about the People table:

 In the People table, the primary key consists of one attribute (PersonID).

• Other than the primary key, the People table is schemaless, which means that neither the attributesnor their data types need to be defined beforehand. Each item can have its own distinct attributes.

• Most of the attributes are scalar, which means that they can have only one value. Strings and numbers are common examples of scalars.

•

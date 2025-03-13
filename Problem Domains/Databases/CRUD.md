## **1. CRUD Operations**

create, read, update, and delete (CRUD) are the four basic functions of persistent storage.
The acronym CRUD refers to all of the major functions that are implemented in database applications.

### **1.1 Create (Insert)**
- **Operation**: Adding new records or data items.
- **Example**: Inserting a new row into a table.
- **Purpose**: To grow the database with new information.

### **1.2 Read (Query/Select)**
- **Operation**: Retrieving data from the database.
- **Example**: Running a SELECT query to fetch user details.
- **Purpose**: To allow users or applications to access stored information.

### **1.3 Update (Modify)**
- **Operation**: Changing or modifying existing data.
- **Example**: Updating a user’s email address.
- **Purpose**: To keep data current and correct any errors.

### **1.4 Delete (Remove)**
- **Operation**: Removing existing data.
- **Example**: Deleting a record from a table.
- **Purpose**: To remove obsolete or unwanted information.



Each letter in the acronym can map to a standard Structured Query Language (SQL) statement, Hypertext Transfer Protocol (HTTP) method (this is typically used to build RESTful APIs) or Data Distribution Service (DDS) operation:


| Operation | SQL | HTTP | RESTful WS | DDS | MongoDB |
|-----------|-----|------|------------|-----|---------|
| Create | INSERT | PUT / POST | POST | write | Insert |
| Read (Retrieve) | SELECT | GET | GET | read / take | Find |
| Update (Modify) | UPDATE | PUT / POST / PATCH | PUT | write | Update |
| Delete (Destroy) | DELETE | DELETE | DELETE | dispose | Remove |
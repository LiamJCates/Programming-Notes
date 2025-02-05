CRUD

create, read, update, and delete (CRUD) are the four basic functions of persistent storage.

The acronym CRUD refers to all of the major functions that are implemented in relational database applications.

Each letter in the acronym can map to a standard Structured Query Language (SQL) statement, Hypertext Transfer Protocol (HTTP) method (this is typically used to build RESTful APIs) or Data Distribution Service (DDS) operation:


| Operation | SQL | HTTP | RESTful WS | DDS | MongoDB |
|-----------|-----|------|------------|-----|---------|
| Create | INSERT | PUT / POST | POST | write | Insert |
| Read (Retrieve) | SELECT | GET | GET | read / take | Find |
| Update (Modify) | UPDATE | PUT / POST / PATCH | PUT | write | Update |
| Delete (Destroy) | DELETE | DELETE | DELETE | dispose | Remove |

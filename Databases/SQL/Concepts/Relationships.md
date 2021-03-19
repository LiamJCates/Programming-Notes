Relationships
If rows in a given table can be associated in some way with rows in
another table, the tables are said to have a relationship between them.
The manner in which the relationship is established depends on the type
of relationship. Three types of relationships can exist between a pair of
tables: one-to-one, one-to-many, and many-to-many. Understanding relationships is crucial to understanding how views work and, by definition,
how multi-table SQL queries are designed and used.


One-to-One
A pair of tables has a one-to-one relationship when a single row in the
first table is related to only one row in the second table, and a single row
in the second table is related to only one row in the first table. In this
type of relationship, one table is referred to as the primary table, and the
other is referred to as the secondary table. You establish this relationship by taking the primary key of the primary table and inserting it into
the secondary table, where it becomes a foreign key. This is a special
type of relationship because in nearly all cases the foreign key also acts
as the primary key of the secondary table.

The selection of the table that will play the primary role in this type of
relationship depends on whether rows can exist in one table with no
matching row in the other table. You cannot add rows to the secondary table in a one-to-one relationship unless a matching row already
exists in the primary table.


One-to-Many
When a pair of tables has a one-to-many relationship, a single row in the
first table can be related to many rows in the second table, but a single
row in the second table can be related to only one row in the first table.
This relationship is established by taking the primary key of the table on
the “one” side and inserting it into the table on the “many” side, where it
becomes a foreign key.


Many-to-Many
A pair of tables is in a many-to-many relationship when a single row in
the first table can be related to many rows in the second table, and a
single row in the second table can be related to many rows in the first
table. To establish this relationship properly, you must create what is
known as a linking table. This table provides an easy way to associate
rows from one table with those of the other and will help to ensure that
you have no problems adding, deleting, or modifying any related data.
You define a linking table by taking a copy of the primary key of each
table in the relationship and using them to form the structure of the
new table. These columns actually serve two distinct roles: Together
they form the composite primary key of the linking table, and separately
they each serve as a foreign key.
A many-to-many relationship that has not been properly established is
said to be unresolved. Figure 1-7 shows a clear example of an unresolved
many-to-many relationship. In this case, a single row in the Customers
table can be related to many rows in the Entertainers table, and a single
row in the Entertainers table can be related to many rows in the Customers table.

This relationship is unresolved because of the inherent problem with a
many-to-many relationship. The issue is this: How do you easily associate rows from the first table with rows in the second table? To reframe
the question regarding the tables shown in Figure 1-7, how do you associate a single customer with several entertainers or a specific entertainer
with several customers? (If you are running an entertainment booking agency, you certainly hope that any one customer will book multiple
entertainers over time and that any one entertainer has more than one
customer!) Do you insert a few columns from the Customers table into
the Entertainers table? Or do you add several columns from the Entertainers table to the Customers table? Either of these approaches is going
to create some problems when you try to work with related data, not
least of which regards data integrity. The solution to this dilemma is to
create a linking table in the manner previously stated. By creating and
using the linking table, you can properly resolve the many-to-many relationship.


The linking table in Figure 1-8 was created by taking the CustomerID
from the Customers table and the EntertainerID from the Entertainers
table and using them as the basis for a new table. As with any other table
in the database, the new linking table has its own name—Engagements.
In fact, the Engagements table is a good example of a table that stores the
information about an event. Entertainer 1003 (JV & the Deep Six) played
an engagement for customer 10001 (Doris Hartwig) on February 23. And
a linking table lets you store additional information about the link—like 
the date and perhaps the cost of the engagement. The real advantage of
a linking table is that it allows you to associate any number of rows from
both tables in the relationship. As the example shows, you can now easily
associate a given customer with any number of entertainers or a specific
entertainer with any number of customers.

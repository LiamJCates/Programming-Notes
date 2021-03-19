Basic Relational Database Concepts

Database
a name for an abstract container to help organize data for efficient storage, manipulation, and retrieval
A collection of data stored in some organized fashion.

Database Management System (or DBMS)
A database is created and manipulated via Database software called the Database Management System (or DBMS).


Schema
Information that describes the database table layout, data properties, and the relationships between data entities.

A Schema contains information that describes a given database including
what data may be stored,
how it is broken up,
specific tables within a database,
the relationship between tables
how individual pieces of information are named,
and much more.



Relational database management system (RDBMS)
Any database management system (DBMS) that is based on the relational model as introduced by E. F. Codd.
A relational database management system (RDBMS) is a software application program you use to create, maintain, modify, and manipulate a
relational database.


Relational Database Model
This model organizes data into one or more tables (or "relations") of columns and rows
an application of tuple relational calculus

SQL is an implementation of the relational data model which has a mathematical definition and notation independent of SQL.

Relational Algebra
Mathematical description of tables and SQL operations



Table
Tables are subcontainers within a database.
Table are database objects that store the actual data.
Each RDBMS consists of one or more tables.
Each table is a collection, in the form of a structured list, of specific, related data.
Generally, the data represented by a given table is of one specific subject or related "entity type"
The information of each instance of the table's entity type is held in a table format within a database partitioned into rows that have attributes described by columns.
The logical order of rows and columns within a table is of absolutely no importance.
Table data is stored and organized into indivisible unit values known as cells.



Row
Each row represents a unique instance of the tables entity type, abstractly called a data record.

The number of rows in the table is the number of records in it.
Each row is composed of the entire set of columns in a table, regardless of whether or not the columns contain any values.


The terms Tuples/Records/Rows are used interchangeably, but row is technically the correct term.






Columns
Tables are composed of one or more columns
Columns are also called attributes or fields
Each column represents a characteristic of the subject of the table to which it belongs.
Columns hold similar data for each column cell.
The number of columns determines the number of cells in each row
Each column has an associated data type that constrains the range of data that can be contained by its fields
The columns representing values attributed to a given instance of the table entity
When you break up data into columns the level of granularity is up to you and your specific requirements, think ahead to which data might be used to sort , filter or as a search index
each value being the mathematical equivalent of what a programmer would term an elemental type.
Every column in a properly designed database contains one and only
one value, and its name identifies the type of value it holds. This makes
entering data into a column very intuitive.


Datatypes
A database is an organized collection of data used to model some type of organization or organizational process.
Datatypes help sort data correctly and plays an important role in optimizing disk usage.
It really doesn’t matter whether you’re using paper or an application program to collect and store the data. You have a database as long as
you’re collecting and storing data in some organized manner for a specific
purpose.
Datatypes and their names are one of the primary sources of SQL incompatibility.
While most basic datatypes are supported consistently, many more advanced datatypes are not.


Table Metadata
Besides the actual data rows, tables generally have associated with them some metadata, such as constraints on the table or on the values within particular columns.

Each table has a unique name
Each table row is identified by a unique key
Each table column has a unique name
A database column imposes restriction on the data it can hold
    size, type, format, null or not






Relation
"Table" is another term for "relation";
A relation (table) is abstractly described as a set of tuples (rows).
Although there is the difference in that a table is usually a multiset (bag) of rows where a relation is a set and does not allow duplicates.
As a set, the relation doesn't care about tuple order
Two relations (tables) with the same set of tuples (row content), containing the same attributes are viewed as the same regardless of any order.


A widely held misconception is that the relational model derives its name from the fact that tables within a relational database can be related to one another. However, the term relation in the model is used to describe what most relational database systems call a table.

data in a relational database is stored in relations, which are perceived by the user as tables. Each relation is composed of tuples (records or rows) and attributes (fields or columns).


Relations As Subsets of Cartesian Products
The Cartesian product of two or more sets is the set of all tuples that can be formed by taking one element from each of the sets. sets A, B, and C, would be written AxBxC.

How many elements are in the Cartesian product A x B x C of sets A, B, C, if each set has 10 elements? 103

We can view any relation on attributes A, B, C as a subset of the cartesian product A x B x C.




Index
A special lookup table that the database search engine uses to speed up data retrieval.






Keys
Relational Database tables use specialized columns called keys to form relationships between tables.

Keys are special columns that play very specific roles within a table. The
type of key determines its purpose within the table. Although a table
might contain several types of keys, I will limit my discussion to the two
most important ones: the primary key and the foreign key.




















Primary key
A column (or set of columns) whose values uniquely identify every row in a table.

A primary key that consists of a set of columns is called a compound key

Though they are not required, database designers ensure that every table they create has a primary key so that future data manipulation is possible and manageable.

Without a primary key, updating or deleting specific rows in a table becomes difficult as there is no guaranteed safe way to refer to just the rows to be affected.

Always define Primary Keys that meet the following conditions:
• No two rows can have the same primary key value.
• Every row must have a primary key value. (No NULL)
• Primary key values should never be reused or reassigned or modified


When multiple columns are used as a primary key, rules listed above must apply to all columns, and the values of all columns together must be unique

Individual columns of a multicolumn primary key are not required to have unique values, but they must be unique as a collection

A primary key consists of one or more columns that uniquely identify
each row within a table. (When a primary key is composed of two or
more columns, it is known as a composite primary key.) The primary key
is the most important for two reasons: Its value identifies a specific row
throughout the entire database, and its column identifies a given table
throughout the entire database. Primary keys also enforce table-level
integrity and help establish relationships with other tables. Every table
in your database should have a primary key.



Foreign Key
When you determine that a pair of tables has a relationship to each
other, you typically establish the relationship by taking a copy of the
primary key from the first table and inserting it into the second table,
where it becomes a foreign key. (The term foreign key is derived from
the fact that the second table already has a primary key of its own, and
the primary key you are introducing from the first table is foreign to the
second table.)

Foreign keys are important not only for the obvious reason that they
help establish relationships between pairs of tables but also because
they help ensure relationship-level integrity. This means that the rows
in both tables will always be properly related because the values of a
foreign key must be drawn from the values of the primary key to which
it refers. Foreign keys also help you avoid the dreaded “orphaned rows,”
a classic example of which is an order row without an associated customer. If you don’t know who placed the order, you can’t process it, and
you obviously can’t invoice it. That’ll throw off your quarterly sales!


Views
A view is a virtual table composed of columns from one or more tables
in the database. The tables that comprise the view are known as base
tables. The relational model refers to a view as virtual because it draws
data from base tables rather than storing any data on its own. In fact,
the only information about a view that is stored in the database is its
structure.
Views enable you to see the information in your database from many
different perspectives, thus providing great flexibility for working with
data. You can create views in a variety of ways—they are especially useful when based on multiple related tables.

In many RDBMS programs, a view is commonly implemented and referred
to as a saved query or, more simply, a query. In most cases, a query has all
the characteristics of a view, so the only difference is that it is referred to
by a different name.



### Theory vs Design
Now that you know the importance of learning about relational databases, you must understand that there is a difference between database
theory and database design. Database theory involves the principles
and rules that formulate the basis of the relational database model. It
is what is learned in the hallowed halls of academia and then quickly
dismissed in the dark dens of the real world. But theory is important, nonetheless, because it guarantees that the relational database is
structurally sound and that all actions taken on the data in the database have predictable results. On the other hand, database design
involves the structured, organized set of processes used to design a
relational database. A good database design methodology will help you
ensure the integrity, consistency, and accuracy of the data in the database and guarantee that any information you retrieve will be as accurate and up to date as possible.
If you want to design and create enterprise-wide databases, or develop
web-based Internet commerce databases, or begin to delve into data
warehousing, you should seriously think about studying database theory. This applies even if you’re not going to explore any of these areas but
are considering becoming a high-end database consultant. For the rest
of you who are going to design and create relational databases on a variety of platforms (which, I believe, is the vast majority of the people reading this book), learning a good, solid database design methodology will
serve you well. Always remember that designing a database is relatively
easy, but implementing a database within a specific RDBMS program onSummary 31
a particular platform is another issue altogether.







Database Normalization
the process of structuring a database relationships in accordance with a series of so-called normal forms in order to reduce data redundancy and improve data integrity

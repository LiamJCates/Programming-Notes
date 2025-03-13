SQL Constraints

SQL constraints are used to specify rules for the data in a table.

Constraints are used to limit the type of data that can go into a table. This ensures the accuracy and reliability of the data in the table. If there is any violation between the constraint and the data action, the action is aborted.

Constraints can be column level or table level. Column level constraints apply to a column, and table level constraints apply to the whole table.

The following constraints are commonly used in SQL:

NOT NULL - Ensures that a column cannot have a NULL value
UNIQUE - Ensures that all values in a column are different
PRIMARY KEY - combination of NOT NULL and UNIQUE. Uniquely identifies records, usable once
FOREIGN KEY - Uniquely identifies a row/record in another table
CHECK - Ensures that all values in a column satisfies a specific condition
DEFAULT - Sets a default value for a column when no value is specified
INDEX - Used to create and retrieve data from the database very quickly

Constraints can be specified when the table is created with the CREATE TABLE statement, or after the table is created with the ALTER TABLE statement.

Syntax
CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    column3 datatype constraint,
    ....
);

The CONSTRAINT keyword can also be used to group CREATE TABLE constraints

Each constraint is preceded by a constraint name
    convention dictates prefixing constraint names with an identifier: id_constraint_name
    where id is uc for UNIQUE,
CREATE TABLE table_name (
    …
    columnN datatype,
    …
    CONSTRAINT
    PK_columnN PRIMARY KEY (columnN)
);


NOT NULL Constraint

By default, a column can hold NULL values.
The NOT NULL constraint enforces a column to NOT accept NULL values.

Syntax
CREATE TABLE table_name (
…
columnN datatype NOT NULL,
    …
);


ALTER TABLE to add a NOT NULL constraint

ALTER TABLE table_name MODIFY column_name datatype NOT NULL;

ALTER TABLE to remove a NOT NULL constraint

ALTER TABLE tableName MODIFY columnName columnType NULL;

UNIQUE Constraint

The UNIQUE constraint ensures that all values in a column are different.
Both UNIQUE and PRIMARY KEY constraints provide a guarantee for uniqueness for a column set
However, you can have many UNIQUE constraints per table, but only one PRIMARY KEY constraint per table.

Syntax
CREATE TABLE table_name (
…
column_name datatype UNIQUE,
    …
);

To define a UNIQUE  constraint for two or more columns, you use the following syntax:

CREATE TABLE table_name (
…
column_name datatype,
    …
    UNIQUE (column_list)
);

If you define a UNIQUE constraint without specifying a name, MySQL automatically generates a name.
To define a name use this syntax

CREATE TABLE table_name (
…
column_name datatype,
    …
    CONSTRAINT uc_constraint_name UNIQUE (column_list)
);


Add a UNIQUE constraint

ALTER TABLE table_name ADD UNIQUE (columnN);
ALTER TABLE table_name ADD CONSTRAINT uc_constraint_name UNIQUE (column_list);

When you define a unique constraint, MySQL creates a corresponding UNIQUE index to enforce it


To drop a UNIQUE constraint, you use can use DROP INDEX or ALTER TABLE statement:

DROP INDEX index_name ON table_name;
or
ALTER TABLE table_name DROP INDEX index_name;
PRIMARY KEY Constraint

The PRIMARY KEY constraint uniquely identifies each record in a table.
Primary keys must contain unique values, and cannot contain NULL values.
A table can have only ONE primary key; and in the table, this primary key can consist of single or multiple columns (fields).

Syntax
CREATE TABLE table_name (
…
column_name datatype PRIMARY KEY,
    …
);

To define PRIMARY KEY constraint for two or more columns, you use the following syntax:

CREATE TABLE table_name (
…
column_name datatype,
    …
    PRIMARY KEY (column_list)
);

If you define a UNIQUE constraint without specifying a name, MySQL automatically generates a name.
To define a name use this syntax

CREATE TABLE table_name (
…
column_name datatype,
    …
    CONSTRAINT pk_constraint_name PRIMARY KEY (column_list)
);


Add a PRIMARY KEY constraint

ALTER TABLE table_name ADD PRIMARY KEY (column_list);
ALTER TABLE table_name ADD CONSTRAINT pk_constraint_name PRIMARY KEY (column_list);

Drop a PRIMARY KEY constraint

ALTER TABLE table_name DROP PRIMARY KEY (column_list);


FOREIGN KEY Constraint
A FOREIGN KEY is a key used to link two tables together.
A FOREIGN KEY is a field (or collection of fields) in one table that refers to the PRIMARY KEY in another table.
The table containing the foreign key is called the child table, and the table containing the candidate key is called the referenced or parent table.

Syntax
CREATE TABLE table_name (
…
column_name datatype FOREIGN KEY,
    …
);

To define a FOREIGN KEY constraint for two or more columns, you use the following syntax:

CREATE TABLE table_name (
…
column_name datatype,
    …
    FOREIGN KEY (column_list) REFERENCES table_name(column_list)
);

If you define a constraint without specifying a name, MySQL automatically generates a name.
To define a name use this syntax

CREATE TABLE table_name (
…
column_name datatype,
    …
    CONSTRAINT fk_constraint_name FOREIGN KEY (column_list)
REFERENCES table_name(column_list)
);


Add a FOREIGN KEY constraint

ALTER TABLE table_name ADD FOREIGN KEY (column_list);
ALTER TABLE table_name ADD CONSTRAINT fk_constraint_name FOREIGN KEY (column_list);

Drop a FOREIGN KEY constraint

ALTER TABLE table_name DROP FOREIGN KEY (column_list);



CHECK Constraint

The CHECK constraint is used to limit the value range that can be placed in a column.
If you define a CHECK constraint on a single column it allows only certain values for this column.
If you define a CHECK constraint on a table it can limit the values in certain columns based on values in other columns in the row.


CREATE TABLE table_name (
…
column_name datatype,
    …
    CHECK (column_name predicate)
);

If you define a constraint without specifying a name, MySQL automatically generates a name.
To define a name use this syntax

CREATE TABLE table_name (
…
column_name datatype,
    …
    CONSTRAINT chk_constraint_name CHECK (predicate)
);


Add a CHECK constraint

ALTER TABLE table_name ADD CHECK (predicte);
ALTER TABLE table_name ADD CONSTRAINT chk_constraint_name CHECK (predicate)

Drop a CHECK constraint
ALTER TABLE table_name DROP CHECK chk_constraint_name

DEFAULT Constraint

The DEFAULT constraint is used to provide a default value for a column.

The default value will be added to all new records IF no other value is specified.

Syntax
CREATE TABLE table_name (
…
column_name datatype DEFAULT value,
    …
);

Add a DEFAULT constraint

ALTER TABLE table_name ALTER column_name DEFAULT value

Drop a DEFAULT constraint

ALTER TABLE table_name ALTER column_name DROP DEFAULT
INDEX Statement

The CREATE INDEX statement is used to create indexes in tables.

Indexes are used to retrieve data from the database more quickly than otherwise. The users cannot see the indexes, they are just used to speed up searches/queries.

Syntax
CREATE TABLE table_name (
…
column_name datatype,
    …
    INDEX idx_name (column_list)
);


Add an INDEX

CREATE INDEX idk_index_name ON table_name (column_list)

Drop an INDEX

DROP INDEX index_name ON table_name

ALTER TABLE table_name DROP INDEX index_name;

AUTO_INCREMENT

The AUTO_INCREMENT attribute causes MySQL to set a unique value for the idcolumn in every row. Since no value was specified for the AUTO_INCREMENTcolumn, MySQL will assign sequence numbers automatically.
Typically coupled with a PRIMARY KEY constraint, used to generate a unique primary key for each record
AUTO_INCREMENT attribute forced the id column to start with 1, andto increment by 1 for each new record.

Syntax
CREATE TABLE table_name (
…
column_name datatype AUTO_INCREMENT,
    …
);

Column Design

A column represents a characteristic of the subject of the table to which it belongs. If you give the
column an appropriate name, you should be able to identify the characteristic it’s supposed to represent. A name that is ambiguous, vague,
or unclear is a sure sign of trouble and suggests that the purpose of the
column has not been carefully thought out. Use the following checklist
to test each of your column names:
• Is the name descriptive and meaningful to your entire organization?
If users in several departments are going to work with this database, make certain you choose a name that is meaningful to everyone who accesses this column. Semantics is a funny thing, and if
you use a word that has a different meaning to different groups of
people, you’re just inviting trouble.
• Is the column name clear and unambiguous? PhoneNumber is a
column name that can be very misleading. What kind of phone
number is this column supposed to represent? A home phone?
A work phone? A cellular phone? Learn to be specific. If you need
to record each of these types of phone numbers, then create
HomePhone, WorkPhone, and CellPhone columns.36 Chapter 2 Ensuring Your Database Structure Is Sound
❖ Note An argument could be made that HomePhone, WorkPhone,
and CellPhone are actually a repeating group that should be moved
to a separate table that could hold multiple phone numbers for the
related customer or employee. Such a table would also have a column
to indicate the type of phone, and it would be possible for each related
person or company to have an unlimited list of phone numbers.
You’ll see more about this when I discuss table structures in the next
section.
In addition to making your column names clear and unambiguous,
be sure that you don’t use the same column name in several
tables. Let’s say you have three tables called Customers, Vendors,
and Employees. No doubt you will have City and State columns in
each of these tables, and the columns will have the same names in
all three tables. There isn’t a problem with this until you have to
refer to one particular column. How do you distinguish between,
say, the City column in the Vendors table, the City column in the
Customers table, and the City column in the Employees table? The
answer is simple: Add a short prefix to each of the column names.
For example, use the name VendCity in the Vendors table, CustCity
in the Customers table, and EmpCity in the Employees table. Now
you can easily make a clear reference to any of these columns. (You
can use this technique on any generic column such as FirstName,
LastName, and Address.)
Here’s the main thing to remember: Make sure that each column
in your database has a unique name and that it appears only once
in the entire database structure. The only exception to this rule is
when a column is being used to establish a relationship between
two tables.
❖ Note The degree to which you use prefixes within a table is a
matter of style. When a table contains generic column names, some
database designers will choose to prefix the generic names only,
while others elect to prefix all of the column names within the table.
Regardless of the prefix method you use, it is very important that you
use it consistently throughout the database structure.
Fine-Tuning Columns 37
• Did you use an acronym or abbreviation as a column name? If you
did, change it! Acronyms can be hard to decipher and are easily
misunderstood. Imagine seeing a column named CAD_SW. How
would you know what the column represents? Use abbreviations
sparingly, and handle them with care. Use an abbreviation only
if it supplements or positively enhances the column name. It
shouldn’t detract from the meaning of the column name.
• Did you use a name that implicitly or explicitly identifies more than
one characteristic? These types of names are easy to spot because
they typically use the words and or or. Column names that contain a back slash (\), a hyphen (-), or an ampersand (&) are dead
giveaways as well. If you have columns with names such as Phone\
Fax or Area or Location, review the data that they store and determine whether you need to deconstruct them into smaller, distinct
columns.
❖ Note The SQL Standard defines a regular identifier as a name that
must begin with a letter and can contain only letters, numbers, and
the underscore character. Spaces are not allowed. It also defines a
delimited identifier as a name—surrounded by double quotes—that
must start with a letter and can contain letters, numbers, the underscore character, spaces, and a very specific set of special characters.
I recommend that you use the regular identifier naming convention
exclusively for your column names because many SQL implementations support only the regular identifier naming convention.
After using this checklist to revise your column names, you have one
task left: Make certain you use the singular form of the column name.
A column with a plural name such as Categories implies that it might
contain two or more values for any given row, which is not a good idea.
A column name is singular because it represents a single characteristic
of the subject of the table to which it belongs. A table name, on the other
hand, is plural because it represents a collection of similar objects or
events. You can distinguish table names from column names quite easily
when you use this naming convention.


Now that you’ve straightened out the column names, let’s focus on the
structure of the column itself. You might be fairly sure that your columns are sound, but you can still do a few things to make certain
they’re built as efficiently as possible. Test your columns against the following checklist to determine whether or not your columns need a little
more work:
• Make sure the column represents a specific characteristic of the
subject of the table. The idea here is to determine whether the
column truly belongs in the table. If it isn’t germane to the
table, remove it, or perhaps move it to another table. The only
exceptions to this rule occur when the column is being used to
establish a relationship between this table and other tables in
the database or when it has been added to the table in support
of some task required by a database application. For example, in
the Classes table in Figure 2-1, the StaffLastName and StaffFirstName columns are unnecessary because of the presence of
the StaffID column. StaffID is being used to establish a relationship between the Classes table and the Staff table, and you
can view data from both tables simultaneously by using a view
or an SQL SELECT query. If you have unnecessary columns in
your tables, you can either remove them completely or use them
as the basis of a new table if they don’t appear anywhere else
in the database structure.

Make certain that the column contains only a single value. A column that can potentially store several instances of the same
type of value is known as a multivalued column. (A column that
contains multiple phone numbers is an example of a multivalued
column.) Likewise, a column that can potentially store two or
more distinct values is known as a multipart column. (A column
that contains both an item number and an item description is
an example of a multipart column.) Multivalued and multipart
columns can wreak havoc in your database, especially when you
try to edit, delete, or sort the data. When you ensure that each
column stores only a single value, you go a long way toward guaranteeing data integrity and accurate information. But for the time
being, just try to identify any multivalued or multipart columns
and make a note of them. You’ll learn how to resolve them in the
next section.

Make sure the column does not store the result of a calculation or
concatenation. Calculated columns are not allowed in a properly
designed table. The issue here is the value of the calculated column itself. A column, unlike a cell in a spreadsheet, does not store
an actual calculation. When the value of any part of the calculation changes, the result value stored in the column is not updated.
The only ways to update the value are to do so manually or to write
some procedural code that will do it automatically. Either way, it
is incumbent on the user or you, the developer, to make certain
the value is updated. The preferred way to work with a calculation,
however, is to incorporate it into a SELECT statement.

Make certain the column appears only once in the entire database.
If you’ve made the common mistake of inserting the same column
(for example, CompanyName) into several tables within the database, you’re going to have a problem with inconsistent data. This
occurs when you change the value of the column in one table and
then you forget to make the same modification wherever else the
same column appears. Avoid this problem entirely by ensuring
that a column appears only once in the entire database structure.
(The only exception to this rule is when you’re using a column to
establish a relationship between two tables.)

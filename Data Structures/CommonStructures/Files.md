A file in computer terminology is defined as a block of useful data in a persistent storage medium; that is, the file is available for future use. The data is organized in a hierarchical order. The hierarchical order includes items such as records, fields, and so forth, which all are defined as follows.

Terminologies
•	 Data Field – A data field is a unit which stores a unary fact. It is
usually characterized by its type and size. For example, “employee’s
name” is a data field that stores the names of employees.
•	 Record – The collection of related data fields is called a record. For
example, an employee’s record may contain various data fields such as
name, id, address, contact number, and so on.
•	 File – The collection of related records is called a file. An example is a
file of the employees working in an organization.
•	 Directory – The collection of related files is called a directory. Every
file in a computer system is stored in a directory.
•	 File Name – The name of a file is a string of characters.
•	 Read-only – A file named read-only cannot be modified or deleted. If
we try to delete the file, then a particular message is displayed.
•	 Hidden – A file marked as hidden is not displayed in the directory.

File Operations
There are various operations which can be performed on the files.
1. File Creation – It is the first operation to be performed on the files if the
file has not been created. A file is created by specifying its name and mode.
The records are inserted into the file by opening the file in writing mode.
Once all the records are inserted into the file, the file can be used for future read and write operations.

2. Updating a File – It means changing the contents of a file. It is usually
done in the following ways:
a. Inserting into a File – The new record is inserted into the file. For
example, if a new employee joins an organization, his/her record is
inserted in the EMPLOYEE file.
b. Modifying a File – The existing records are modified in the file.
For example, if the address of an employee is changed, then the new
address must be modified in the EMPLOYEE file.
c. Deleting from a File – The existing record is deleted from the
file. For example, if an employee quits a job, then his/her record is
deleted from the EMPLOYEE file.
3. Retrieving from a File – It refers to the process of extracting
some useful data from a file. It is usually done in the following ways:
a. Enquiring – It retrieves a low amount of data from the file.
b. Generating a Report – It retrieves a huge amount of data from
the file.


A file is classified into two types, which are:
1. Text Files – A text file, often called a flat file, is a file that stores all
the numeric or non-numeric data using its corresponding ASCII values.
The data can be a string of letters, numbers, or special symbols. Therefore, it is also known as an ASCII file. Usually, a text file has a special
marker known as the end of file marker which denotes the end of the file.
2. Binary Files – A binary file is a file that contains all the data in the binary form of 1s and 0s. It stores the data in the same form as that of primary
memory. Thus, a binary file is not readable by human beings. Binary files
are read by computer programs, and they decode the binary files into
something meaningful. Data is efficiently stored in binary files.




File Organization
File organization refers to the way in which records are physically
arranged on a storage device. Further, there may be a single key or multiple
keys associated with it. Therefore, based on its physical storage and the keys
used to access the records, files are classified as sequential files, relative
files, indexed sequential files, and inverted files. There are various factors
which should be taken into consideration while choosing a particular type
of file organization which are:
1. Ease of retrieval of the records.
2. Economy of storage.
3. Reliability, that is, whether a file organization is reliable or not.
4. Security, that is, whether a file organization is secured or not.
Now, we will discuss some of the techniques which are commonly used
for file organization.

Sequence File Organization
Sequence file organization is the most basic way to organize a collection of records in a file. Sequence file organization is when the file is created when the records are written, one after the other in order, and can be
accessed only in that order in which they are written when the file is used
for input. All the records are numbered from zero onward. Thus, if there
are N records in a file, then the first record is numbered as 0, and the last
record will be numbered as N-1. In some cases, records of sequential files
are sorted by the value of some field in each record. The field whose value
is used to sort the records is known as a sort key. If a file is sorted by the
value of a field named “key field,” then the record i proceeds record j if
and only if the value of “key field” in record i is less than or equal to the
value of “key field” in record j. Also, a file can be sorted in either ascending or descending order by a sort key comprising one or more fields. As
the records in a sequential file can only be accessed sequentially, these
files are used more commonly in batch processing than in interactive processing. For example, the records of a sequential file are used to generate the white pages of a telephone directory that will be sorted by the
subscriber’s last name.


Advantages of a Sequence File Organization
1. It is easy to handle.
2. It does not involve extra overheads/problems.
3. Records can be of varying lengths in this organization.
4. It can be stored on magnetic disks as well as tapes.
Disadvantages of Sequence File Organization
1. Records can be accessed only in sequence.
2. It does not support the update operation in between the files.
3. It does not support interactive applications.


Indexed Sequence File Organization
An indexed sequential file organization is an efficient way of organizing
the records when there is a need to access both sequentially by some key
values and also to access the records individually by the same key value. It
provides the combination of access types that are supported by a sequential
file or a relative file. The index has been structured as a binary search tree.
This index is used to serve as a request for access to a particular record, and
the sequential data file alone is used to support sequential access to the entire
collection of records. Because of its capability to support both sequential and
direct access, indexed sequence file organization is used to support applications that require both batch and interactive processing.
Advantages of Indexed Sequence File Organization
1. Records can be accessed sequentially and randomly.
2. It supports batch as well as interactive oriented applications.
3. It supports the update operation in between records in the file.
Disadvantages of Indexed Sequence File Organization
1. In this organization, files can only be stored on magnetic disks.
2. It involves extra overhead in the form of maintenance.
3. Records can only be of a fixed length, as we maintain the structure of
each node like a linked list.



Relative File Organization
Relative file organization provides an effective way of accessing individual records directly. In relative file organization, there is a predictable
relationship between the key and the record’s location in the file. The
records do not necessarily appear physically in sorted order by their keys.
Then how is a given record found? The relationship that will be used to
translate between key value and the physical address is designated, for
example, R(Key value → address). When a record is to be written into
a relative file, the mapping function R is used to translate the record’s
key to an address, which indicates where the record is to be stored.
The fundamental techniques that are used for mapping function R are
directory lookup and address calculation (hashing).
•	 Directory Lookup Technique – It is the simplest technique
for implementing a mapping function R. The basic idea of this
technique is to keep a directory of key values: address pairs. To find
a record in a relative file, one locates its key value in the directory,
and then the indicated address is used to find the record on the
storage device. The directory can be organized as a binary search
tree.
•	 Address Calculation Technique – Another common technique
for implementing a mapping function R is to perform a calculation
on the key value (hashing) such that the result is a relative
address.
Advantages of Relative File Organization
1. Records can be accessed out of sequence.
2. It is well suited for interactive applications.
3. It supports an update operation in between the files.
Disadvantages of Relative File Organization
1. It can be stored only on magnetic disks.
2. It also involves extra overhead in the form of maintenance
of indexes.


Inverted File Organization
One fundamental approach for providing a linkage between an index and a
file is called inversion. A key’s inversion index contains all the values that the key
presently has in records of the file. Each key-value entry in the inversion index
points to all the data records that have the corresponding value. Then, the file is
said to be inverted on that key. The inversion approach for providing multi-key
access has been used as the basis for a physical data structure in commercially
available relational DBMS such as Oracle, DB2, and so on. These systems were
designed to provide rapid access to the records via as many inversion keys as
the designer cares to identify. They have user-friendly, natural-language-like
query languages to assist the user in formulating inquiries. A complete inverted
file has an inversion index for every data field. If a file is not completely inverted
but has at least one inversion index, then it is said to be a partially inverted file.

Advantages of Inverted File Organization
1. The Boolean query requires only one access per record satisfying the
query along with some access to process the indexes.
2. Records can be stored in any way, for example, sequentially ordered by
primary key, randomly linked ordered by primary key, and so forth.
3. It also results in space saving as compared with the other file structures.
Disadvantages of Inverted File Organization
Since the index entries are of variable lengths, index maintenance
becomes more complex

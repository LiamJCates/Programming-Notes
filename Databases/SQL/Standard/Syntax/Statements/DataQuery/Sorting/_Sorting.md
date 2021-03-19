### Sorting Retrieved Data

If query results are not explicitly sorted, data will be returned in no order of any significance

Relational database design theory states
you cannot rely on the sort order if you do not explicitly control it, the sequence of retrieved data cannot be assumed to have significance if ordering was not explicitly specified.


If unsorted, data will typically be displayed in the order in which it appears in the underlying tables.
Unsorted data could be the order in which the data was added to the tables initially, however, if the data was subsequently updated or deleted, the order will be affected by how the DBMS reuses reclaimed storage space.

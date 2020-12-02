External Sorting
External Sorting is a sorting technique which is used when the amount
of data is massive. When a large amount of data has to be sorted, it is not
possible to bring it into main memory (RAM). Therefore, in that situation a secondary memory needs to be used. Also, at the same time, some portion of data is brought into the main memory from the secondary
memory for sorting based on the availability of storage space of the main
memory. After the data is sorted, it is sent back to the secondary memory.
Now, the next portion of the data is brought into the main memory, and
after sorting it is sent back to the secondary memory. This procedure is repeated until all the data is sorted. Here, each portion is called a segment.
The time required for sorting is greater because time will be spent transferring the data from secondary memory to main memory. The merge
sort algorithm is widely and commonly used in external sorting, which has
already been discussed.
External sorting is used in database applications for performing different kinds of operations like join, union, projection, and many more. It is also
used to update a master file from a transaction file. For example, if we are
updating the company file based on the new employees, existing employees, locations, and so on. Duplicate records or data can also be removed
from external sorting.

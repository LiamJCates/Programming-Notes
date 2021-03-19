SQL SELECT statements typically return raw or unformatted data.

Data formatting is a presentation issue, not a retrieval issue.
Data presentation or formatting is typically specified by the application which displays the data.


Data stored within a database’s tables is often not available in the exact format needed by your applications. Rather than retrieve the data as it is and then reformat it within your client application or report, what you really want is to retrieve converted, calculated, or reformatted data directly from the database.

In general, it is far quicker and network efficient to perform data conversions and reformatting on the database server than it is to perform them within the client

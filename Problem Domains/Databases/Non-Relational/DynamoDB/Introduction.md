Introduction to Amazon DynamoDB


We'll be introducing the Amazon DynamoDB service by reviewing
its features
use cases for NoSQL data stores.
how to create an Amazon DynamoDB table and new items
how to retrieve the data using query and scan operations.


Amazon DynamoDB is a fully managed NoSQL database service.

Amazon manages all of the underlying data infrastructure for this service and redundantly stores data across multiple facilities within an AWS region, as part of the fault tolerant architecture of the service.

With DynamoDB, you can create tables and items.
You can add items to a table.

The service automatically partitions your data and adds table storage to meet the workload requirements.
There is no practical limit on the number of items you can store in a table. For instance, some customers have production tables that contain billions of items.

One of the benefits of a NoSQL database is that items in the same table may have different attributes. This gives you the flexibility to add attributes as your application evolves. You can have newer format items stored side‑by‑side with older format items in the same table without needing to perform schema migrations.

As your application becomes more popular and as users continue to interact with it, your storage can grow with your application's needs.

All of the data in DynamoDB is stored on solid state drives
Its simple query language allows for consistent, low‑latency query performance.

In addition to scaling storage, DynamoDB also allows you to provision the amount of read or write throughput you need for your table. As the number of application users grow, DynamoDB tables can be scaled to handle the increased numbers of read and write requests with manual provisioning.

Alternatively, you can enable autoscaling, so DynamoDB monitors the load on the table and automatically increases or decreases the provisioned throughput. The ability to scale your tables in terms of both storage and provisioned throughput makes Amazon DynamoDB a good fit for structured data from the web, mobile, and Internet of Things applications.


For instance, you may have a large number of clients continuously generating data and making large numbers of requests per second. In this case, the throughput scaling of DynamoDB allows consistent performance for your clients.


DynamoDB is also used in latency sensitive applications.
The predictable query performance, even in large tables, makes it useful for cases where variable latency could cause significant impact to user experience or to business goals, such as ad tech or gaming.

Table data is partitioned and indexed by primary key. There are two different ways of retrieving data from a DynamoDB table.

In the first method, query operation takes advantage of the partitioning to effectively locate items by using the primary key.
The second method is via a scan, which will allow you to locate items in the table by matching conditions on non‑key attributes. The second method gives you flexibility to locate items by other attributes. However, the operation is less efficient as DynamoDB will scan through all the items in the table to find the ones that matched your criteria. 

To take full advantage of query operations in DynamoDB, it's important to think about the key you used to uniquely identify items in the DynamoDB table.

You can set up a simple primary key based on single attribute of the data values with the uniform distributions, such as a GUID or other random identifiers. For example, if you were to model a table with products, you could use some attributes such as the product ID.

Alternatively, you can specify a compound key, which will be composed of a partition key and a secondary key.

In this example, if I was to have a table with books, I might use the combination of author and title to uniquely identify table items. This could be useful if you expect to frequently look at books by author, since then, you could use query.


Let's switch to a demo where I'll create a new DynamoDB table and an item and then use query and scan operations to retrieve the data. So here I am, in the Amazon DynamoDB section of the AWS Management console. I can see in the upper corner the Oregon region is selected. This means that any tables that I create will be deployed to the Oregon region. I'm going to go ahead and create a new DynamoDB table. The first parameter that I'm asked for is the table name. This table will hold information about books, so we'll call it the books table. The next thing I have to specify is a partition key. As I mentioned earlier, DynamoDB is going to partition and index the data by partition key. I could use something like a book ID here, but in this case, I know that I'm going to be frequently looking up the books by author. Therefore, I would like to set this to be author in order to ensure that my primary field is indexed for fast retrieval. However, an individual author can, in fact, author more than one book in my table, so author won't uniquely identify the items that I need to store. I'm going to use a compound key instead by adding a sort key. Now this combination of author and title can uniquely identify each book in my table. The next set of decisions that I need to make is around whether I want to use autoscaling or manually provisioned throughput, and if I want to define any secondary indices on the table. For this demo, I'm going to use the default settings. This will allow DynamoDB to automatically monitor the table and set the read and write throughput accordingly. And there's the new table. The table is called books, and the primary key is author, and the search key is title. Let me now go ahead and take a quick look at the top bar here. I can see the items in the table, and I also have the ability to check my metrics, create indices, and perform other operations on the table. I'm going to go ahead and check the items in the table. Because this is a brand new table, I don't have any data. So I'll add a data item. When I click create item, I see that DynamoDB has automatically filled out a template for what this item should have based on the primary key that I determined earlier. In this demonstration, I have author and title available. Now I'll go ahead and add a book by H.G. Wells called "The Time Machine". The next thing that I can do is add additional attributes to this item. The flexibility to have items in the table with different attributes is really useful, and the flexible schema allows developers to evolve the table utilization as the application requirements change. Now I'm going to go ahead and add a set of strings for edition so that I can keep track of different editions of this book, such as Audible or Kindle versions. The last piece of this to change is the representation in this wizard from a tree over to text. I see a JSON style declaration of the items in the table. I can add as many attributes to this JSON definition or to the tree, as long as the overall size fits within the maximum size of a DynamoDB item of 400 kilobytes. When I hit Save, it commits the items to the data store, and I see that I have a new item. The author H.G. Wells. The title is "The Time Machine", and I also have the different editions for this item. I'm going to take a quick moment to pause and load a little bit more data into the table. Okay, I'm going to go ahead and refresh the table, and now I should see more items. So here I have author, title, rating, and editions. Note that not every item has the same set of attributes. That's really taking advantage of DynamoDB's flexibility, which allows you to have different attributes and different items. Although, remember every single one of these items has to have both an author and a title, as those form the compound key I discussed earlier. All right, to quickly locate books in this table, I can use the query operation. When I use query operation, I must specify the value for the partition key. In this case, I'm going to go ahead and look for the books by H.G. Wells. I can optionally set filter criteria on the key and I can choose whether I want the data to come back in ascending or descending order, based on the value of the sort key. When a hit start search, I see several results that come back for H.G. Wells. There are four different books here. This query operation has taken advantage of the fact that I know the partition key of the data to retrieve and it matches the data very quickly. On the other hand, what if I don't know the author of the book that I want to look up? What if I want to find all of the different Audible books in my table or filter on any other non‑key attribute? In that case, I can use the scan operation. For example, I can go ahead and check for the editions of the books where the edition attribute contains Audible. I should find all of the Audible books in my dataset. After pressing start search, I see several books have been returned. I can optionally add additional filters to only show items where rating is greater than three. With that, I see that four books were returned that have a rating higher than three and contain Audible editions. So now I've covered the basic operations of creating a table, loading data, and using both the query operation and scan operation to retrieve our data. In summary, Amazon DynamoDB is a managed NoSQL database service, which can be used as a data store for applications which need to scale to store large amounts of data, support high request volume, and require low‑latency query performance. For AWS Solutions Architecture and AWS Training and Certification, I'm Rudy Valdez. Thanks for watching.

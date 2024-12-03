### Buffers, Flushing, and Synchronization

When we operate with file streams, these are associated to an internal buffer object of type streambuf. This buffer object may represent a memory block that acts as an intermediary between the stream and the physical file.

For example, with an ofstream, each time the member function put (which writes a single character) is called, the character may be inserted in this intermediate buffer instead of being written directly to the physical file with which the stream is associated.

The operating system may also define other layers of buffering for reading and writing to files.

When the buffer is flushed, all the data contained in it is written to the physical medium (if it is an output stream). This process is called synchronization and takes place under any of the following circumstances:

##### When the file is closed:
before closing a file, all buffers that have not yet been flushed are synchronized and all pending data is written or read to the physical medium.

##### When the buffer is full:
Buffers have a certain size. When the buffer is full it is automatically synchronized.

##### Explicitly, with manipulators:
When certain manipulators are used on streams, an explicit synchronization takes place. These manipulators are: flush and endl.

##### Explicitly, with member function sync():
Calling the stream's member function sync() causes an immediate synchronization. This function returns an int value equal to -1 if the stream has no associated buffer or in case of failure. Otherwise (if the stream buffer was successfully synchronized) it returns 0.

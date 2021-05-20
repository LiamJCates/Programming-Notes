Just because a program is structured to have multiple threads or processes does not mean they'll necessarily execute in parallel. A concept that's closely related to parallel execution but often gets confused with it is concurrency.

Concurrency refers to the ability of an algorithm or program to be broken into different parts that can be executed out of order or partially out of order without affecting the end result.

Concurrency is about how a program is structured and the composition of order independent processes.

We can decompose a procedure into a collection of concurrent tasks when the relative order in which we do them doesn't matter.

In one scenario, concurrently running two independent processes may overlap in time. However, with only a single processor, only one is actually executing at any instant in time. If we swap processes frequently, it might create the illusion that they're executing simultaneously on our single processor but this is not true parallel execution.

To actually execute in parallel, we need parallel hardware, at least a second processor.

In regards to computers, parallel hardware can come in a variety of forms.

Most modern processors used in things like desktop computers and cellphones have multiple processing cores.

Graphics processing units or GPUs contains hundreds or even thousands of specialized cores working in parallel to make amazing graphics that you see on the screen.

Computer clusters distribute their processing across multiple systems.

Concurrency is about the structure of a program being able to deal with multiple things at once whereas parallelism is about simultaneous execution, actually doing multiple things at once.

Concurrency enables a program to execute in parallel, given the necessary hardware, but a concurrent program is not inherently parallel.


Programs may not always benefit from parallel execution. For example, the software drivers that handle I/O devices like a mouse, keyboard, and hard drive need to execute concurrently. They're managed by the operating system as independent things that get executed as needed. In a multi-core system, the execution of those drivers might get split amongst the available processors. However, since I/O operations occur rather infrequently relative to the speed at which computer operates, we don't really gain anything from parallel execution. Those sparse independent tasks could run just fine on a single processor and we wouldn't feel a difference.

Concurrent programming is useful for I/O-dependent tasks like graphical user interfaces. When the user clicks a button to execute an operation that might take a while, to avoid locking up the user interface until it's completed we can run the operation in a separate concurrent thread. This leaves the thread that's running the UI free to accept new inputs. That sort of IO-dependent task is a good use case for concurrency.

Parallel processing really becomes useful for computationally-intensive tasks such as calculating the result of multiplying two matrices together. When large math operations can be divided into independent sub-parts, executing those parts in parallel on separate processors can really speed things up. 

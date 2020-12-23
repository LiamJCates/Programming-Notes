Software development process methodologies

Since the 1960s, different methodologies have been developed to help system developers be more productive, on target, and create higher quality code. Here, we will look at some of the more essential methodologies – some that are in use today and some that have been superseded by newer and more flexible ones.


Waterfall development
The waterfall development model is one that almost everyone loves to hate. We will look at it anyway, as many newer methodologies have been developed as a reaction to it. The reason it is hated, is that it will not take changing requirements into account.

In the waterfall model, several defined steps are completed, one preceding the next.

This is how the model works:
1. First, we gather all the requirements needed for this application.
2. After that, we make a system design, where we describe how different responsibilities will be divided between different parts of the application.
3. Then, we write the code.
4. During the verification phase, the code is tested.
5. Finally, when the software is released, it goes into the maintenance phase, where it is maintained.

The main criticism of this model is that it will not capture new requirements that might (and often will) arise during the development phase. The process of going from an initial idea to a finalized product can be rather long, and during this time, a lot of things will happen that will have an impact on this application. New laws can come into place, competing applications might be released, new versions of operating systems and other software that this application relies on might be released, and so on. If we have a development model that cannot capture these changes, we will most likely have developed a product that is outdated before it has even been released.



Spiral model
In 1986, the American software engineer Barry Boehm described and depicted a model that, instead of going from one phase to the next, was shaped as a spiral. This idea has since been developed and modified into several new methodologies. Still, the basic idea of driving the development process by a spiral has been prevalent since then. One key concept in the spiral model is that risk is taken into consideration as a critical concept when developing software.

Here, we have four distinct phases. Instead of going through them once in order, we will iterate through them over and over as many times as necessary until the application is developed:

1. In the first phase, we look at the objectives, as we see them at this point in the development process.

2. We then look at the risks. What can hinder us from succeeding in implementing the objectives we just determined? By identifying the risks, we have a higher chance of avoiding them or at least minimizing the impact they will have on our software.

3. When that is done, we will go ahead and develop and test the software.

4. The last phase is a review phase. Here, we look back at what we have done in the other three phases during this iteration, including what went well and what problems we had. We can learn from this so that the next iteration is better.

We will then start over with the objectives for the next iteration by determining the risks and developing and reviewing them repeatedly.

The growing spiral illustrates that, for each iteration, more of the software has been created. Even if the spiral model was created as a reaction to the shortcomings of the waterfall model, this claim shows that the problem is not the Waterfall model in itself, but that the development process becomes very prolonged and therefore can't react to rapid changes in requirements.

The spiral model gave inspiration to several new methodologies, where the development process is divided into smaller iterations, the most popular being Agile Development.


Agile development
Agile software development refers to a group of software methodologies, all based on iterative development.

The term agile comes from a group of 17 software developers who met at a resort in Snowbird, Utah, in 2001. After the meeting, they published Manifesto for Agile Software Development.

The manifesto is a short description of what should be prioritized during the software development process.

It can be found at https://agilemanifesto.org/.

This manifesto is then outlined in more detail by twelve principles, called Principles behind the Agile Manifesto, and they can be found here at https://agilemanifesto.org/principles.html.

These ideas had a significant impact on the software industry, and several new software development methodologies were developed in response to the manifesto.
Let's look at some of the more popular of these.

Agile Scrum methodology
This methodology, better known as Scrum, is a lightweight project management framework that uses an iterative and incremental approach.

In Scrum, the product owner – a person with the power to decide what items will go into the application – plays a central role. This person needs to play an active role throughout the development process.

The product owner works closely with the development team to create a prioritized list of system functionality, called the product backlog. The product backlog consists of whatever needs to be done to deliver a working software system successfully. The items in the backlog can be things such as the features of the application, bugs that need to be fixed, and non-functional requirements such as certification, accessibility, and data integrity. When the properties in the backlog have been prioritized, a team of developers (and potentially other roles, if needed) will start to develop in what can be called potentially shippable increments. This means that the team will take some of the highest prioritized items from the backlog and start to implement them during a short time frame, known as a sprint. A sprint will typically last for somewhere between 14 and 30 days. The outcome of the sprint is preferably fully functional so that it can immediately be put into production, and users can start using this functionality. The team will then start over with a new sprint. This will be repeated as many times as necessary.

Lean software development
This Agile methodology is iterative, just like Scrum, and focuses on delivering fully functional batches. The methodology is highly flexible and does not have any rigid rules or guidelines.

Its main idea is to eliminate what is called waste. This is done by letting users of the system select only the precious features for the system. These features are then prioritized and delivered in small batches.

It relies on rapid and reliable feedback from the users of the software. In Lean
development, the work is pulled by customer requests.

Extreme Programming (XP)
This methodology was first described by Kent Beck, an American software engineer who took software best practices to an extreme level. One example of this is code review.
Standard practice is that another developer should review all the code before it can be merged with the code that goes into a release. In XP, this is done by using the concept of pair programming.

Pair programming is when two developers are using one computer to develop code. One is called the driver and is the one that will write the code. The other
developer is called the observer or the navigator and will observe and review what the driver is doing. The two will frequently switch roles.

Compared to the traditional code review process, this will speed things up as the review is done during the development phase. Other benefits of pair programming include the fact that the driver will consistently get input from the observer regarding how to solve the current task.

The goal of XP is to reduce the cost of changes in the requirements. To do this, XP uses short development cycles.

In XP, changes in requirements are a natural, inescapable, and desirable aspect of software development.

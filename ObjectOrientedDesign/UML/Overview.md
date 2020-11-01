UML is a general purpose method that uses a pictorial language to visualize, specify, model, and document systems.

Although UML is generally used to model software systems, it may be used on non-software systems as well. For example, the process flow in a manufacturing unit.

The Object Management Group (OMG) created and manages the
UML specification to consolidate best practices established in the use of modeling languages.

While UML is not a programming language, tools can be used to generate code in various languages using UML diagrams.

UML is used to both design software and provide a visual record for the system, to be included as part of formal software documentation.


UML has a direct relation with object oriented analysis and design.

UML communicates and documents class structures, objects, and interactions of object-oriented applications and systems.

This process creates a share vocabulary between developers, customers, and managers without unnecessary detail.

The result of modeling with UML is a graphical model that offers different views of a system in the form of various diagrams.











Why

Communication
One of the biggest problems we have in business today, and in software development in particular, are communication problems.

Imagine that you want to develop a software system. One of the first challenges you are confronted with is clarifying what the customer actually wants and whether you have understood the customer’s exact requirements for the prospective system.

Natural language is often imprecise and ambiguous. Misunderstandings can easily arise and there is a very great risk that people with different backgrounds (e.g., a computer scientist and a business manager) will talk at cross-purposes, which can have serious consequences.

UML helps clearly define a common vocabulary between the many roles that compose real world development teams

Software Roles
Product Owner        Define the product, ultimate beneficiaries of the software
Business Analyst    Communicate between product owners, business, and IT, gather requirements
Architect        Design systems and identify how they should be built
Operations        deploy, monitor and maintain software after development
Quality Assurance    Ensure requirements are satisfied
Developer        Develops software from business requirements and architect designs

we're making sure with UML that when we create these designs, we do so in a common way that everybody understands.

Thus there is a need for there to be a standard that we can take with us as we move from project to project or job to job and we're able to take the standard language we have, UML, and continue to communicate well with new team members.
















Methods Models and Tools

There are many Development Methods
Though they follow one of two standard patterns

Waterfall method
a planned set of sequential steps.
Planning/design > build > test > deploy


Iterative development
The same steps: Planning/design > build > test > deploy
but in a very quick cyclical and iterative fashion.
Oftentimes these iterations are as short as 1-2 weeks and seldom do they get longer than maybe 6 or 8 weeks.

Methods are often checklists of things that we need to do to develop our software. Sometimes these are really long checklists, different methods have very prescriptive tasks and things that we need to do. We're not going to concern ourselves with methods and UML doesn't really care what method you use.










Models
What we're going to focus on is the modeling.
UML provides a framework to translate designs that we create into models that can be shared with members of the team.

To create UML models there are a lot of formal tools available to us.
Case-type tools, tools like VISIO, Visual Studio, Software Architect, there's a lot of tools out there, and they vary in how rigorously they conform to the UML standards and also the features they give us.

Tool Ability
Forward Engineering: Uses UML models to generate software.
Reverse Engineering: Take software we have already created and derive models. "as-built" models






What is a model?

Models allow us to describe systems efficiently and elegantly. A system is an integrated whole made up of components that are related to one another and influence each other in such a way that they can be perceived as a single, task-based or purpose-based unit.

Examples of systems are material things, such as cars or airplanes, ecological environments, such as lakes and forests, but also organizational units such as a university or a company.

UML highlights the important aspects of the software in a clear form of notation that is as simple as possible but abstracts from irrelevant details, just like models in architecture, e.g., construction plans.

A construction plan for a building contains information such as the floor plan.
Construction materials to be used are not specified at this point in time; they are irrelevant and would make the plan more complicated than necessary. The plan also does not contain any information about how the electrical cables are to be laid. A separate plan is created for this aspect to avoid presenting too much information at once. Just like in architecture, it is important in information technology that people with different backgrounds can read, interpret, and implement the model.

Modeling languages were developed precisely for such scenarios and demonstrate clearly defined rules for a structured description of a system. These languages can be textual (e.g., a programming language such as Java) or visual (e.g., a language that provides symbols for transistors, diodes, etc. that can be combined with one another).
Modeling languages can be designed for a specific domain, for example, for describing web applications. On the one hand, these domain-specific modeling languages provide tools and guidelines for solving problems in a specific field efficiently; on the other hand, they can also be restrictive.
Alternatively, modeling languages can be designed for general purpose use.







Models must be created with great care and due consideration. According to Bran Selic [47], five characteristics determine the quality of
a model:
• Abstraction: a model is always a reduced representation of the system that it represents. Because the details that are irrelevant in a
specific context are hidden or removed, it is easier for the user to
understand the essence of the whole.
• Understandability: simply omitting irrelevant details is not enough
to make a model understandable. It is important to present the remaining elements as intuitively as possible—for example, in a graphical notation. The understandability results directly from the expressiveness of the modeling language. Expressiveness can be defined as
the ability to present complex content with as few concepts as possible. In this way, a good model reduces the intellectual effort required
to understand the content depicted. For example, typical programming languages are not particularly expressive for a human reader as
a lot of effort is required to understand the content of the program.
• Accuracy: a model must highlight the relevant properties of the real
system, reflecting reality as closely as possible.
• Predictiveness: a model must enable prediction of interesting but not
obvious properties of the system being modeled. This can be done
via simulation or analysis of formal properties.
• Cost-effectiveness: in the long-run, it must be cheaper to create the
model than to create the system being modeled.








UML for Software

In information technology, we are interested in particular in software systems and thus in models that describe software systems.

Software systems themselves are based on abstractions that represent machine-processable facts of reality. In this context, abstraction means generalization—setting aside specific and individual features. Abstract is the opposite of concrete. Abstracting therefore means moving away from specifics, distinguishing the substance from the incidental, recognizing common characteristics

Choosing the correct means of abstraction makes programming easier. The individual parts then have simple and small interfaces. New functionality can be introduced without the need for extensive reorganization. Choosing the wrong means of abstraction might result in a number of nasty surprises during implementation: the interfaces will be complicated and it will be difficult to implement changes. You can only manage the ever-increasing complexity of modern software systems with suitable means of abstraction

The language UML is a general purpose modeling language. We will use UML to get to know the most important concepts of object-oriented modeling.

Object-oriented modeling is a form of modeling that obeys the object-oriented paradigm.
































Usage of UML


Diagrams




Two types of modeling- structural modeling and behavioral modeling.
Thus two classes of UML diagrams—behavioral and structural.

Structural Modeling
Asks what kind of elements do we need to put together to build the software, to solve the problems we're looking at, and how do they related to each other, how can we combine them to be most functional?

Static Parts of the system
the parts that's kind of to build a framework. Oftentimes they're the nouns, the things that we deal with.

Structural modeling diagrams include
Class diagrams        identify the vocabulary, the things that we are building.

Component diagrams     help us structure these things together physically, package them up, and work with them as parts, and then have those parts plugged together.

Package diagrams    logically helps us combine things, nothing physical with Package diagrams, but logically put things together and help us, especially when we're doing modeling of large systems.

Deployment diagrams    map the pieces that we've built will be defined as components often and how they map to the physical deployment, the servers that they run on the hardware that we need.



Behavioral Modeling
Behavioral diagrams illustrate how system components interact to form a system.

defines the functionality of the system, the processes that occur, the interactions that happen between the structural pieces defined.

dynamic parts of the system that implement the functionality that our users are looking for. the verbs or actions system components can take.

Behavioral Modeling Diagrams
Use Case diagrams    lay out the functionality that we're after, what features, what work needs to happen, and who is interested in those.

Sequence diagrams     lay out how things process, how the different pieces that we've defined interact, and especially the main focus is on a time sequencing structure. What object calls what other object, what orders are those done in?

State diagrams        take a particular object, look at the different states that that object can be in, and define the transitions that occur. Whether those transitions come from outside stimulus requesting the state change or whether they come from just events that may occur and cause a state to change.

Activity diagrams    like flow charts, if you've ever seen those, but they have some enhanced functionality that we'll be looking at.

































Activity diagrams
Activity diagrams represent workflows in a graphical way. They can be used to describe the business workflow or the operational workflow of any component in a system.

Interaction diagrams
Interaction diagrams visually document how system components interact with each other.
    Sequence diagram
    Sequence diagrams are used to show a specific use case scenario, representative of a typical behavior based on the given use case.
Communication diagram
Timing diagram

State machine diagrams

Use case diagrams


Structural diagrams illustrate components of a system.

Class diagrams

Component diagrams
A component diagram displays the structural relationship of components of a software system.
Composite structure diagrams

Deployment diagrams
A deployment diagram shows the hardware of your system and the software in that hardware.

Object diagrams

Package diagrams





Sequence diagrams
Sequence diagrams are used to show a specific use case scenario. So, these diagrams are
representative of a typical behavior based on the given use case.



Communication diagram
Communication diagrams are a special type of interaction diagrams. They focus on how system participants are linked to one another.


Timing diagrams
Timing UML diagrams provide a visual representation of a system's time constraints.

The following example shows two time constraints in a bank's vault security system. There
are two objects:
Bio Security System
Vault

Each starts in the Off state. The first time constraint indicates that the vault must be opened
within 15 seconds of the Bio Security System being activated. The second time constraint is
that the vault can only be open for 20 minutes or less:



State machine diagrams

State machine diagrams are used to visually describe a system's behavior. The key
components of these diagrams include states and transitions. The sample state machine
provided in the following diagram is for a bank vault. The solid circle is the initial pseudo
state and indicates entry into the system. There are four states—Wait, Unlock, Enable, and
Vault.
In our bank vault example, the vault is enabled when two bank managers place their thumb
on a thumbprint scanner. The vault is unlocked, contingent on a successful thumbprint
scan, by entering the correct combination. When these conditions are met, the Vault state is
reached and the managers can enter it:



Use case diagrams
Use case diagrams document the interactions between your users and your system. This is typically done with text, but UML does support use cases.


example of a grade book for an online education institution.
The student logs on to the system and selects their class. The student then selects the assignment and uploads their document. Next, the student enters text and selects the submit button. The instructor logs on to the system and selects their class. The instructor then selects the assignment, and the student. They grade the assignment, enter a grade, and select the submit button.


There are several visual components to the UML use case diagram:

Actor: The stick figure is referred to as an actor. In our example, student and instructor were both actors. These are the users that use your system. Often, there are multiple user roles in a system.

Relationship: The solid lines indicate which actors interact with which use case items.

System: The overall system is represented by a rectangle. Actors are placed outside of the system and use case items are placed within the system.

Use Case Item: Use case items are represented in ovals, as seen in our preceding Online Grade Book example. These are the components of your use case.

structural UML diagrams

Structural diagrams illustrate components of a system. The six diagrams listed here are
structural, and are briefly described in the subsections that follow:
Class diagrams
class diagram illustrates class templates and objects
It shows the classes in a system, attributes, and operations of each class and the relationship between each class.

Component diagrams
Component diagrams provide a visual representation of a system's physical components.


Composite structure diagrams

Deployment diagrams
Object diagrams
Package diagrams
Package diagrams are used to provide a high-level visual depiction of large systems. These diagrams are simplistic and simply show how a system's components are grouped.







Composite structure diagrams
The Composite structure UML diagram shows the runtime structure of a system. This
diagram can be used to show the internal components of a class.


The following example shows a microwave with four structures:


We can also represent a composite structure with a rectangular box, as illustrated in the following diagram:

Object diagrams

Object diagrams have an unfortunate name, as it does not aptly describe this UML
diagram's purpose. The object diagram visually communicates a set of class instances. In
fact, the instances have mostly optional components and are often only partially depicted.
Therefore, a more apt name for this diagram might be a loosely defined instance UML diagram.
The following example depicts four objects and their hierarchy. Because each object is an
instance of a class, it is underlined and followed by a colon and the class name:
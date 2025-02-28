https://en.wikipedia.org/wiki/Waterfall_model


The waterfall development model is notorious, many newer methodologies have been developed as a reaction to it's lack of success.

According to the 2014 Chaos report 31% of waterfall projects were cancelled after significant spend and a further 52.7% of projects needed to nearly double their budget. 


In the waterfall model, several defined steps are completed, one preceding the next:

1. Gather Requirements
2. System Design
3. Development
4. Integration
5. Testing
6. Deployment
7. Maintenance

The main criticism of this model is that it will not capture new requirements that might (and often will) arise during the development phase. The process of going from an initial idea to a finalized product can be rather long, and during this time, a lot of things will happen that will have an impact on this application. New laws can come into place, competing applications might be released, new versions of operating systems and other software that this application relies on might be released, and so on. 


If we have a development model that cannot capture these changes, we will most likely have developed a product that is outdated before it has even been released.







The waterfall model arranges all the phases sequentially so that each new phase depends on the outcome of the previous phase. Conceptually, the design flows from one phase down to the next, like that of a waterfall.

Bell and Thayer, in 1976, coined the term Waterfall. 

In 1985, the US Department of Defense standardized the Waterfall methodology and this approach was defined as the standard approach for Software Development. 

The Waterfall model comprises of 6 stages: Preliminary design, Detailed Design, Development, Unit testing, Integration, and Testing.

A product started with an idea for the finished project, the team went to work on everything that this application needed to do and, several years later, finally publish the finished software. 

The reason we don't want to do this is that during any lengthy development period, the market landscape is constantly changing. 

    The requirements for the application might change, 
    new laws can require process alterations, 
    competing software solutions might be released, 
    etc...




Waterfall Software Development Methodology

The Waterfall model is one of the earliest and most well-known software development methodologies. It is a sequential (non-iterative) approach to software development where progress is seen as flowing steadily downwards through distinct phases. The model was first introduced in the 1970s and is often compared to the process of water cascading down, as it follows a strict step-by-step approach. Each phase must be completed before moving on to the next, making it highly structured.

Waterfall is a traditional methodology that follows a linear approach, making it easier to manage for projects with well-defined requirements that are unlikely to change throughout the project lifecycle. It’s particularly suited for projects where the scope is clearly understood upfront and the development process doesn’t require frequent revisions or updates based on feedback.
Phases of the Waterfall Model

The Waterfall model is divided into several phases, with each phase acting as a foundation for the next. The typical phases of the Waterfall software development methodology include:
1. Requirements Gathering and Analysis

    Objective: To define what the system will do and gather detailed requirements from stakeholders. These requirements are typically collected from the customer or end-users, specifying exactly what the software needs to accomplish.
    Activities:
        Conduct meetings with stakeholders (clients, users, business analysts) to gather and document all necessary system requirements.
        Analyze the requirements to identify gaps, inconsistencies, or ambiguities.
        The output of this phase is a requirements specification document that outlines what the system must do in detail.

Key Characteristics:

    Requirements are gathered before any design or development begins.
    The focus is on a comprehensive understanding of the problem.

2. System Design

    Objective: To plan the architecture and structure of the system based on the requirements collected in the previous phase.
    Activities:
        The system is broken down into modules, and the architecture is defined.
        Detailed design specifications are created for both high-level (system) and low-level (component) designs.
        Decisions are made about the technologies, tools, and programming languages to be used.
        The system design typically includes data models, interface designs, system architecture diagrams, and workflows.

Key Characteristics:

    Focus on defining the overall system architecture.
    Design documents serve as the blueprint for coding.
    Little to no coding occurs in this phase.

3. Implementation (Coding)

    Objective: To transform the design specifications into executable code.
    Activities:
        Developers begin writing code based on the design documents created in the previous phase.
        Each module or component is implemented separately, according to the system design specifications.
        The development team follows coding standards to ensure uniformity and consistency across the software.

Key Characteristics:

    Code is written in this phase following a detailed blueprint.
    Testing may be minimal or focused on individual modules (unit testing) during coding.

4. Integration and Testing (Verification)

    Objective: To ensure that the software works as intended and meets the requirements defined at the beginning of the project.
    Activities:
        The system components/modules are integrated and tested as a whole.
        Testing includes various levels such as unit testing, integration testing, system testing, and acceptance testing.
        The goal is to verify that the software functions correctly, is free of defects, and satisfies the requirements specified in the first phase.
        Any defects or bugs identified during testing are fixed, and the system is re-tested as needed.

Key Characteristics:

    Testing is performed after the entire system has been developed.
    Testing can be time-consuming, as the software is tested in a fully integrated state.

5. Deployment (Installation)

    Objective: To deploy the system into a production environment where it will be used by end-users.
    Activities:
        The system is installed on the client’s hardware, configured, and made operational.
        Documentation, training, and support are provided to end-users.
        The system may be rolled out to production in a phased approach or as a full deployment.

Key Characteristics:

    The system is delivered to the end-users.
    Any issues found post-deployment are logged for future updates or fixes.

6. Maintenance

    Objective: To monitor the system in the live environment and provide ongoing support.
    Activities:
        Maintain and update the system to fix bugs, add new features, or adapt to changing requirements.
        Perform necessary updates and upgrades over time.
        Track performance and usability issues that arise after deployment, making any required patches or improvements.

Key Characteristics:

    Ongoing support and maintenance of the system after deployment.
    Typically involves bug fixing, performance tuning, and sometimes small updates or enhancements.

Key Characteristics of the Waterfall Model

    Sequential and Linear: Each phase is distinct and must be completed before moving on to the next phase. It’s a linear progression, meaning there is no overlap or iteration between the phases.

    Rigid Structure: The Waterfall model is known for its rigid structure. Once a phase is completed, it’s difficult to go back and make changes without starting over or causing delays.

    Documentation-Heavy: Waterfall places significant emphasis on documentation at each stage. Documentation provides clarity about the system’s requirements, design, and functionality.

    Clear Deliverables: At each phase, the team produces a well-defined deliverable, such as the requirements specification document, design documentation, source code, or test reports.

    Late Testing: Testing is typically done only after the entire system has been developed, which can lead to the discovery of issues late in the process. This can be problematic if requirements or design flaws are only detected at this point.

Advantages of the Waterfall Model

    Easy to Understand and Use: Due to its linear nature, the Waterfall model is easy to understand and follow, especially for smaller projects where requirements are clear from the outset.

    Clear Structure: Each phase has specific deliverables and milestones, making the development process easy to manage and track.

    Well-Suited for Predictable Projects: Waterfall works well for projects with well-defined requirements that are unlikely to change during development. This includes projects with fixed goals and a clear understanding of what needs to be built.

    Easy to Manage: The process is straightforward and requires minimal project management complexity, as each phase has a clear end date and deliverable.

    Good Documentation: The extensive documentation produced in each phase provides clarity, and makes it easier to maintain and enhance the system in the future.

Disadvantages of the Waterfall Model

    Inflexibility: One of the biggest drawbacks of the Waterfall model is its lack of flexibility. Once a phase is completed, going back to make changes is difficult and costly. This makes the model ill-suited for projects with evolving or unclear requirements.

    Late Discovery of Issues: Because testing happens late in the process, it can be difficult to identify defects in the system early. If bugs or design issues are found late in the game, they can lead to delays and require costly rework.

    Assumes Requirements are Well-Understood Upfront: The Waterfall model assumes that all requirements are known upfront, which isn’t always the case in modern software development where user needs may evolve over time.

    Customer Feedback is Delayed: Because the customer isn’t involved in the development process until the software is delivered, there’s little opportunity for continuous feedback. This can result in the delivered system not meeting the customer’s evolving needs.

    Not Ideal for Complex or Large Projects: As projects grow in complexity, the rigidity of Waterfall becomes a significant disadvantage. Large or complex projects often require frequent changes or adjustments, making the Waterfall approach less practical.

When to Use the Waterfall Model

The Waterfall model is well-suited for projects with well-defined, unchanging requirements. Examples include:

    Regulated Industries: For projects in industries with strict regulatory or compliance requirements, Waterfall’s extensive documentation and step-by-step process make it easier to meet compliance standards.

    Small Projects: For small-scale projects where the requirements are clear and unlikely to change during the course of development, the Waterfall model can be effective.

    Maintenance Projects: For systems that require minimal updates or have stable, long-term functionality, the Waterfall approach works well because there’s less need for iteration.

    Projects with Clear Deliverables: If the end product is well understood from the start (e.g., a product with a specific set of features), Waterfall can be an efficient choice.

Conclusion

The Waterfall model is a traditional and structured approach to software development that provides clear phases and deliverables. It is best suited for projects with well-defined requirements and a low likelihood of changes throughout the project lifecycle. While it offers clarity and ease of management, its lack of flexibility and the tendency to delay feedback and testing until late in the process make it less suitable for modern, dynamic projects where requirements evolve over time. As a result, while Waterfall is still used today in certain contexts, more agile and flexible methodologies like Agile, Scrum, or Kanban have become more popular for many modern software projects.
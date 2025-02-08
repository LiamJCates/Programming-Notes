A version control system (VCS) is used to manage changes in files, documents, programs, or other data collections over time.

In industry a VCS is used by programmers to manage different revisions of their code. 

Benefits
Possible to restore earlier reversions if needed, making change safer. 
Allow developers to work together on the same project and, in a safe manner, work in the same source code files. 
Track who changed what in a document, and when the change was made. 

It records changes to files, such as code, documents, or configuration files, and stores them in a repository. With version control, developers can revert to previous versions, compare differences between versions, and understand the evolution of a project. It supports features like branching, where different lines of development can occur independently, and merging, which combines changes from different branches. Overall, version control ensures that changes are organized, recoverable, and easily managed, making it a critical tool in software development and collaborative projects.

Files that are version controlled are stored in what is called a repository. When changes are made to a file, the user of the VCS can commit these changes to the repository, and by extension of that, create a reversion point. It is at these points where the version control system takes a snapshot of all the changes made.

Using version control is essential for managing changes in software development, as it enables tracking of modifications, collaboration, and maintaining a history of your project. It allows multiple developers to work on the same codebase simultaneously without overwriting each other’s work, providing a clear record of who made changes and why. Version control systems facilitate rollback to previous versions if issues arise, and they support branching and merging, which are crucial for experimenting with new features and managing different stages of development. Overall, version control ensures code quality, accountability, and efficient collaboration in projects.

To illustrate how this works, we can use one of the most popular version control systems available: Git. Git was created by Linus Torvalds, the creator of Linux, in 2005. It was initially created to be used by the programmers who were working on the Linux kernel code, but soon gained popularity outside the Linux project. Today, it is by far the most popular version control system.


### Git vs Other VCS

Git has become the de facto standard for source control in software development, but it’s not the only version control system (VCS) available. Here are some key differences between Git and other popular VCS:

    Mercurial: Mercurial is a distributed VCS that uses a similar architecture to Git. However, it has a more centralized approach and doesn’t use hashes for tracking changes.
    Subversion: Subversion is a centralized VCS that’s often compared to Git. While both systems support branching and merging, Subversion requires a central server to manage the repository.
    Perforce: Perforce is a commercial VCS that’s designed for large-scale development projects. It uses a centralized approach and has features like build automation and issue tracking.
    CVS: CVS is an older version control system that’s still in use today. However, it lacks many modern features and is often considered outdated.

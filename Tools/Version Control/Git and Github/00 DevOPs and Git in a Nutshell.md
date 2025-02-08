DevOps and Git in a Nutshell

DevOps basically means modern software development practices

version control is a core component of DevOps, continuous delivery pipelines.
version control manages team files for large and small projects.
This allows the team to continuously improve its product.

Git is an open source version control system originally created by Linus Torvalds.
Git is used by most major technology companies, and is assumed knowledge for many modern programming and IT jobs.




DevOps Fundamental Principles
Continuous improvement releases consistent small improvements to your product
This is contrasted with what might be called the waterfall approach, in which many features are planned, developed and released as one batch.

Continuous small changes to a product, also known as small batch sizes leads to continuous improvement.

Even removing a single bug, though the change is small these are different versions of the product.


Small batch size also applies to features.

The version of the product on the left contains only blue icons.
The product on the right adds a single feature, the ability to have multicolor icons.

The integration of many small changes to the project leads to a continuously improving project.


Git helps manage continuous improvement
modern products have many versions
Let's say that our product is an application that currently contains 50 files of code.

Git manages versions of products forming a project history.
Each version of a project is called a commit.

In this example the first version of the project is represented by commit A and contains a bug.
The second version of the project is represented by commit B which differs from commit A only in that the bug has been fixed.
Assuming the bug fix involves a change to only one of the 50 files,
Commits A and B only differ by that single file.
.
Git is really good at managing small changes like this.

Is Git efficient?
We know that each commit is a snapshot of the entire project at a given point in time.
With many small changes to the project, you might think that Git stores many copies of the same file.
This is not how Git works however.
Behind the scenes, Git is very efficient at storing commits.
Each unique file is stored only once.
For example, after commit A, Git has stored 50 files.
Commit B only adds one file for Git to store, the file that contains the bug fix, a total of 51 files stored.


The collection of commits contain the history of the project.
At any time you can review the projects history and undo changes by going back to the previous version of the project.

Let's say that customers don't like a feature for some reason, or worse, adding that feature introduced some problems that you didn't foresee.
You can easily go back to a version of the product without the feature.
Either by going back to commit A, or by adding a new commit that undoes the work of commit B.












Git Branches
Now that we've seen how commits helped managed the many versions of a continuously improving project. We will look at an important feature of Git called branches.

All commits belong to a branch.
A branch can be thought of as an independent line of development of the project.
By default, there is a single branch and it's called master.
In this example, commits A, B, and C all belong to the master branch.


How do you maintain a stable project at the same time that you are working on it?
You can create a separate branch and work on it independently of the master branch.

Here a featureX branch was created, and commit C includes content that is unique to the featureX branch. In this case, the master branch does not know that the featureX branch exists. The master branch thinks that the latest commit is B, even though separate work has been done on commit C.

We've seen that branches can be used to independently work on the project without disrupting the rest of the project.

Here the master branch sees the project as 50 stable files. This commit has usually been tested, approved and maybe the version of the product that is currently in production.

The featureX branch sees the same 50 files plus maybe one file that was added for the new feature.
The independence of branches allow teams to scale their work.
In this example, the project can be in production at commit B and separate development can be done on featureX, bugY, and featureZ.

Commit B on the master branch is not aware of or impacted by the other branches.
So far we've discussed the importance of many small changes to continuous improvement.

Git can manage the many versions of projects with commits and that the project can be worked on independently using branches.


Merging independent branches using pull requests.

When a branch is ready to become part of the master branch, it can be merged into the master branch.
A merge combines the work of separate branches.


In this example, before the merge, featureX is implemented on its own branch which is also called featureX.
Before the merge, the master branch has no knowledge of the featureX branch.
After the merge, there's a single master branch with the latest commit, including the code that implements featureX.

Before you merge content into the master branch, how do you know that your changes are good?

A pull request is a request to merge your branch into another branch.
This request is usually made by the developer of the branch when the feature, bug fix or other change is complete.

In this example, the pull request is a request to merge the commit that includes featureX into the master branch.

During a pull request team members can discuss, review, and approve your changes.
You can also require that automated test pass before the merge is allowed to happen.
This helps ensure that the changes introduced by the merge don't cause problems for the customer.

If the pull request is accepted, your version of the project is merged and becomes the latest commit on the master branch.
You can feel good about the quality because the changes were reviewed and automated tests have passed.


We have seen some of the ways that Git is fundamental to DevOps and modern software development.
Git manages many small improvements to the project using commits, it also allows simultaneous stability and development through branches.
And improves product quality using pull requests which can include review and testing.

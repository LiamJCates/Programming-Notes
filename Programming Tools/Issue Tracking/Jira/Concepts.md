# JIRA Concepts

## Issues
JIRA is a project management tool revolving around a central concept known as "issues". Every unit of work or task either technical, non-technical, support, etc... is logged as an issue.

Since JIRA tracks all the tasks, the sub-tasks or even a work as an Issue, there are several Issue Types used to identify and categorize them.

By default, an Issue may be classified as follows:
* Task − A task that needs to be done to achieve team’s goal.
* Sub-Task − This is the sub-task of an issue. In a logged issue, there can be several steps to resolve it, called sub-tasks.
* Bug − A problem that impairs or prevents the functions of the product.
* Epic − A big user story that needs to be broken down.
* Improvement − An improvement or enhancement to an existing feature or task.
* New Feature − A new feature of the product, which is yet to be developed.
* Story − A user story.

## Project
A Project contains issues; a JIRA project can be called a collection of issues. A JIRA Project can be of several types. For example −

    Software Development Project
    Marketing Project
    Migration to other platform project
    Help Desk Tracking Project
    Leave Request Management System
    Employee Performance System
    Website Enhancement


## Workflow
In JIRA, workflow is used to track the lifecycle of an Issue. Workflow is a record of statuses and transitions of an issue during its lifecycle. A status represents the stage of an issue at a particular point. An issue can be in only one status at a given point of time like Opened, To Do, Done, Closed, Assigned, etc.

A transition is a link between two statuses when an issue moves from one status to another. For an issue to move between two statuses, a transition must exist. In a simple way, a transition is some kind of work done on the issue, while status is the impact of work on that issue.


Example
As of now, an issue is created and opened. When the assignee starts working on the issue, the issue moves to the In Progress status. Here, the transition is starting the work, while the status of the issue is now progressive.

JIRA workflow has the following stages to track as soon as an issue is created −

    Open Issue − After creation, the issue is open and can be assigned to the assignee to start working on it.

    In Progress Issue − The assignee has actively started to work on the issue.

    Resolved Issue − All sub-tasks and works of that Issue are completed. Now, the issue is waiting to be verified by the reporter. If verification is successful, it will be closed or re-opened, if any further changes are required.

    Reopened Issue − This issue was resolved previously, but the resolution was either incorrect or missed a few things or some modifications are required. From Reopened stage, issues are marked either as assigned or resolved.

    Close Issue − The issue is considered as finished, resolution is correct as of now. Closed issues can be re-opened later based on the requirement.

JIRA Workflow can be referred as a Defect Lifecycle. It follows the same concepts; the only difference is that it is generic for all issues rather than limited to Defects only.

The following diagram shows a standard workflow −
![Standard Workflow](https://raw.githubusercontent.com/LiamJCates/Programming-Notes/master/Programming%20Tools/Issue%20Tracking/Jira/Images/standard_workflow.jpg)



## Boards
Boards are a showcase of process that is followed by a Project.

# Project Management

## Creating a Project
To create a project, the user should login as a JIRA Service Desk Admin
In the top navbar Click Project → Create Project.

Choose the type of Project that suits your requirement and the process it should follow.
Once the type of project is selected, click on Next.
The user will see the flow of the project based on the selection.
The following screen displays the available issue types and the workflow for the chosen project in the step mentioned above.

Click on the Select button.
On the following screen enter the name of the project and confirm the Key that the user wants to display as a reference in all the issues.
Once this is done, click on the Submit button.



## Issue Type Schemes

An issue type scheme determines which issue types will be available to a project or set of projects. It also manages specifying the order in which the issue types will present in the user interface of JIRA, while creating an Issue. An issue type scheme generates as soon as the project is added in the JIRA.

If a user logs in as Admin and navigates to Settings → JIRA Administrator → Issues, all the listed issue types will display.

The Default Issue Type Scheme is the list of global issue types. All newly created issue types will automatically be added to this scheme.

By clicking on the Add Issue Type Scheme button at the top right hand corner, the user can add a user defined scheme.

Custom schemes require:
Name
Description
Selection of allowed Issue Types from the Available issue type list.

Click on Save. The new schema will appear in the list.

By clicking on Edit, the user can edit the details.
By clicking on Associate, the user can associate this scheme to a project. Copy and Delete is used for copying and deletion of the same scheme.

## Screen
Screens represent the arrangement of fields to display in UI whenever a new issue is created or existing issues are modified and issue transitioned through one status to another. If a user logs in as Admin and navigates to Settings → Issues → Screens, they will be able to see all the available screens.

By clicking on configure, the user will be able to see all the available fields with a given screen organized in the order displayed by the UI.


## Screen Schemes
Screen schemes provides an option to choose fields, which should display when a particular issue type is selected. A screen scheme is mapped with issue type using the Issue Type Screen Scheme. It can be associated with one or more project. A screen scheme can be deleted only when it is not used by any Issue Type screen scheme. The user can add a new screen scheme by clicking on the Add Screen Scheme button.

Provide all details and the click on the ADD button.


## Create Issue
To create an issue in JIRA, the user should have Create Issue permission in the project. Admin can add/remove the permission.

Click on the Create button in the navigation bar to open the create issue dialogue box.

To complete the process of creating an issue, we should follow the pointers given below.

    Select the Project where the issue is.

    Select the type of issue, whether it is a bug/new feature/story, etc.

    Write a one-line summary to provide the overall idea about the issue.

    Write the details of the issue in the Description field. Explain the issue, so that stockholders can understand every detail of the issue.

    To create a similar type of issue in the same project and issue type, check the checkbox of “Create another” otherwise keep it as unchecked.

    After entering all the details, click on the Create button.

The following screenshot shows how to create an issue by providing the required and optional details.
Creation Another

If the “Create another” checkbox is not checked, after clicking on the Create button, the user will have to navigate to the Dashboard and a pop-up will display on the right side with an issue id and summary.

The following screenshot shows how to know whether the issue is successfully created or not.
Issue Id Summary

If the “Create another” checkbox is checked while clicking on the Create button, the user will get a new create issue page along with the issue id.

The following screenshot shows the page, if the user has checked the “Create another” box.
Check Box
Configure Fields

To add other fields in the Create Issue form, click on “Configure fields” at the top right hand side of the page. The following screenshot shows how to configure the fields in the Create Issue page.
Configure Fields

After clicking on the Configure fields button, a drop down box will be displayed, click on Custom. The following screenshot shows the available fields under the Custom tab.
Custom

By checking and unchecking the checkboxes to show and hide, fields will be added or cleared from the form. The following screenshot shows the available fields under the All tab.
All Tab

Now navigate to Create Issue, all fields based on choices will be displayed in the form that shows up. The following screenshot shows the configured fields in the Create Issue page.
Create Issue Page

The fields in the Create Issue form are explained below.

    Priority − Issue creator can set the priority to resolve the issue as High, Medium, Low, and Lowest.

    Labels − It is similar to Tag; it helps in filtering out specific types of issues.

    Linked Issue − It links other issues that are either dependent on this issue or this issue is dependent on them. Options in dropdowns are – block, is blocked by, duplicate, clone, etc.

    Issue − User can link the issue by the Typing ID or summary of those that are related to the linked issue field.

    Assignee − The person who is responsible to fix this issue. Assignee name can be entered by the issue creator.

    Epic Link − An Issue creator can provide an epic link, if the issue belongs to any of those.

    Sprint − The user can define in which sprint, this issue belongs to, when this issue should be addressed.



### Clone an Issue
Cloning means to copy. To clone an issue means to create a duplicate issue within the same project. A cloned issue can be treated as a new issue and edited like other issues.

We should consider the following points while cloning an issue.

    A cloned issue is completely a separate issue from the original issue.

    Any action or operation taken on the original issue does not have any impact on the clone issue and vice-versa.

    The only connection between the original and clone is the link that is created.

    Information that is carried from the original issue to clone issue is as follows −

        Summary
        Description
        Assignee
        Environment
        Priority
        Issue Type
        Security
        Component
        Reporter
        Affects Version
        Fix Version
        Attachment
        Projects
        Content of custom fields are also cloned

    Information that is not cloned −
        Time Tracking
        Comments
        Issue History
        Links to confluence pages

Steps to Follow for Cloning

Open a JIRA issue that is supposed to be cloned. Select More → Clone when the screen appears.

In the clone screen, there are a few options given to the users, which are as follows −

    A user can change the summary while cloning it.

    If the issue contains links to other issues, a user can check the checkbox to contain the clone issue or uncheck if the user does not want to be a part of the clone issue.

    If the issue has sub-tasks, the user can select/deselect the checkbox to contain the sub-tasks in clone or not.

    The same is applicable for attachment as well.

    It also gives an option, whether to carry or not – the sprint value to the new clone issue.


The next step is to click on Create. It will display the clone issue details. If the user does not change the clone words while creating, it can be visible in the summary, links and sub-tasks.

### Create a Subtask
An issue can be completed by performing many tasks with different persons like Dev, QA, UAT, Business, Support, etc. To track the progress in each department, sub-tasks are created in an issue and assigned to the concern person. Once all the sub-tasks are resolved, the issue can be marked as completed.
Points to Note for Creating a Subtask

The following points are to be considered when creating a subtask.

    All subtasks are an essential part of their parent issue.

    All subtasks are visible on the main screen of the parent issue.

    Subtasks always belong to the same project as their parent issue.

    Subtask has all fields that are present in the standard issue.

    Subtasks cannot have a subtask of their own.

Steps to Follow for Creating a Subtask

We should consider the following steps when creating a subtask.

    Open an issue where subtasks should be created.

    Select More → Create Subtask. Create subtask page will display.

The following screenshot shows how to access the Create Subtask functionality.
Create Subtask functionality

Enter the details in all the required fields and then click on Create. The following screenshot shows the Create Subtask Form with the required and optional fields.
Create Subtask Form

Once a subtask is created, it will be available on the Main Issue page → Subtask section.


## Convert Issue To Subtask

To begin with, navigate and click to the issue, which needs to be converted into a subtask. Select More → Convert to subtask. The following screenshot shows how to navigate to convert to sub-task.
Convert to subtask

Choose the parent issue in which this subtask will be tagged. The following screenshot shows how to convert the issue into a sub-task.
Convert the issue into a sub-task

Click on Next. If the status of the issue is not an allowed status for the new issue type. Select – New Status will be displayed. Select a new status and click on the Next button.

Update Fields screen will be prompted to enter any additional fields, if they are required. Otherwise, a message will be prompted as – 'All fields will be updated automatically'. Click on Next.

The following screenshot shows how to convert the issue in sub-tasks.
Convert the issue in sub-tasks

The Confirmation screen is displayed. It will display the original values and the new values. Click on Finish.

The following screenshot shows how to convert the issue in sub-tasks.
How to convert the issue in sub-tasks

The original issue will be displayed. Now it is a sub-task. The parent's issue number is now displayed at the top of the screen. The following screenshot shows how the sub-task displays after successful conversion from an issue.
Successful Conversion
Convert an Issue to a Subtask

We should consider the following points while converting an issue to a subtask.

    An issue cannot be converted into a subtask if it has its own subtask.

    To convert such an issue into a subtask, we should first convert all the subtasks of issues into a standard issue and after that convert the issue into a subtask.

    Subtasks cannot be moved from one issue to another directly.

    To move a subtask from one issue to another, first convert all sub-tasks into issues and then again, convert issues to subtasks by giving the parent issue name while converting.


## Convert Subtask to Issue
To convert a subtask to an issue, we should first navigate to the subtask that needs to be converted into an issue. Then, Select More → Convert to issue.

To begin with, click on the drop down box of the Select Issue Type option, choose the type of the issue (i.e., a standard issue type) and click on the Next button.

The following screenshot shows how to convert a sub-task to an issue.
Convert subtask to an issue

If the status of the subtask is not an allowed status for the new issue type, then the Select New Status screen is displayed. Select a new status and click on the Next button.

In the next step, the Update Fields screen will be prompted to enter any additional fields if they are required. Otherwise, a message will display stating – 'All fields will be updated automatically'. Click on Next.

The following screenshot shows how to convert a subtask in to an issue.
Update Fields

The Confirmation screen is displayed. It will display the original values and the new values. Click on Finish.

The issue will be displayed. It is no longer a subtask. There is no longer a parent issue number displayed at the top of the screen.

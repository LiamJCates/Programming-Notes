# IDE Basics

## Folder Structure

Eclipse is a software written in Java, so look and feel vary by platform but UI organization is the same.

Eclipse knows at least one Java installation from your machine, this is the Java it will use by default to handle your projects.
Of course it can be [overridden](https://github.com/LiamJCates/Programming-Notes/blob/master/Programming%20Tools/IDEs/Eclipse/Installation.md#demo-setting-the-right-version-of-java-to-launch-eclipse)

### Workspace
A workspace is a collection of projects that you want to work with when you launch Eclipse.

In a nutshell, a workspace is a directory on your disk.
There can be as many workspaces as you want.
At a given time, only one instance of Eclipse works in a workspace, and one instance of Eclipse can only work in a single workspace.
A workspace can contain and can handle several projects, and those projects are going to share common properties defined at the workspace level.

### Understanding the Workspace Folder Organization
So one workspace is one folder, and one project is one subfolder in a workspace.

Inside each workspace, there is
* a hidden subdirectory called. metadata, which contains
* a version.ini configuration file
* a .log file, with Eclipse error messages
* a .lock file
* other subdirectories created by Eclipse itself or plugins.
subdirectories for the projects, Project 1, Project 2, etc…



### Project
A project can take any number of forms from a desktop executable, a library, a set of web pages, and more.

Not all projects in a workspace have to be related.
You can take any approach you like to creating a workspace.
You can create a single workspace, and create every programming project under that workspace.
Eclipse is actually geared toward this approach.
It has some additional tools like working sets, which we will talk about in more depth later, but working sets allow for convenient grouping to make it easy to work with a subset of your projects.

You can also create any number of workspaces.
If you want, you can have one for every project or group of related projects.
You can do something in between.

One thing that you don't want to do is create your workspace inside any directory that might get updated by a vendor when they upgrade their toolset.

### Understanding the Project Folder Organization
Inside each Project subdirectory, there is
a hidden subdirectory called the .settings subdirectory
and two files, .classpath and .project.

Those elements contain project-level configuration. We are not going to open them. Usually you do not need to change or edit those files or subdirectories by hand.

## Exploring the Eclipse Workbench

The Workbench is what loads when you run the Eclipse  application.
The Workbench provides the user interface structure for Eclipse.

Two of the basic building blocks of Eclipse are views and perspectives.

#### View
A view is the Eclipse name for a unique content area that accomplishes a given task.
Package Explorer, Outline, and the Console are examples of three views.

#### Perspective
A perspective is just the layout of a particular collection of views.


Depending on which IDEs you've used, this layout might look familiar to you.

As soon as we open Eclipse, we are in a particular perspective. There are some useful built-in perspectives including a default, one for browsing code, one for debugging, and one for source code management with Git. There are other preexisting perspectives, and you can create more and customize the existing ones.


### Java Default Perspective
If Eclipse for Java Developers was downloaded, the default perspective will have:
* Explorer section on the left,
* Task List for Mylyn and an Outline section for whatever code we're looking at on the right
* axillary windows on the bottom
* A central editor tabs

We see an empty workspace with the default Java perspective.

### Opening Perspectives
The icon in the upper-right indicates your current perspective.

You can open other perspectives using
* the icon with the plus in the top right
* Window > Perspective

Open the Java Browse perspective, so we can see this in action.

Now you can see there's a new icon, and the addition of the magnifying glass indicates it's the browse perspective.
Click between the icons to switch perspectives.

When you no longer need a perspective, just right-click and select Close.

### Opening Views
Add another view to the perspective: Window > Show View
select the Project Explorer view
this view can look quite similar to the Package Explorer view.

I will point out that I find the Project Explorer view a little more capable when you start working with additional tools like Spring or Web Development. It's good to know it's there, although right now we're just going to use it to have an additional tab.

### Managing Views
Each view has a minimize / maximize icon

use the Restore icon in the view's top bar to reanchor the view to its previous location.
or the icon below restore to bring back any given tab temporarily, until it is clicked off again.
If more than one view is minimized the view's order from top to bottom in the order you minimize them.
You can take a tab and put it where ever you like. When you click and start to drag, Eclipse will give you some highlighting lines to indicate where it's going to put the tab.
Notice when I get a single vertical bar next to the tabs in a view, eclipse will make the selected view one of the tabs in that view.

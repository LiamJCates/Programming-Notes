# Eclipse Guided Tour for Java






## Presenting the Eclipse Key Concepts

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

### Opening views
Add another view to the perspective: Window > Show View
select the Project Explorer view
this view can look quite similar to the Package Explorer view.

I will point out that I find the Project Explorer view a little more capable when you start working with additional tools like Spring or Web Development. It's good to know it's there, although right now we're just going to use it to have an additional tab.

Each view has a minimize / maximize icon

use the Restore icon in the view's top bar to reanchor the view to its previous location.
or the icon below restore to bring back any given tab temporarily, until it is clicked off again.
If more than one view is minimized the view's order from top to bottom in the order you minimize them.
You can take a tab and put it where ever you like. When you click and start to drag, Eclipse will give you some highlighting lines to indicate where it's going to put the tab.
Notice when I get a single vertical bar next to the tabs in a view, eclipse will make the selected view one of the tabs in that view.


### Saving Perspectives
We can save a new arrangement as its own perspective.
use the Window > Perspective > Save Perspective As...

You can hover over the icon, and you'll get the name of the perspective after a short delay.
To delete a perspective go to Preferences at the bottom of the Window menu, open up the general area, and scan down for perspectives, then we can select the perspective we want to delete, click Delete, and finally Apply and Close.

When you double-click a tab, it maximizes to take up the whole screen. Double-click it again, and it goes back to where it was.

For fine-grained control over your perspective there are even more options if you go into the Window menu and select Customized Perspective. We're not going to get into that much detail right now, but you can change what toolbars are showing, the menu visibility, and more, and all of that will save with your perspective as well.


Eclipse has templates that can save you some typing. The system out print line method is available by just typing syso, and hitting Ctrl+Space. We can then select the match from the list, and then just hit Save.

By default, Eclipse is set up to build when you hit Save.

We can also prettify our code. Under the Source menu is the Format command

In Preferences under General, we can go down to Workspace, and you can see Build automatically is checked, and that's what's complying in our code for us as we save. And I don't know why, but by default, Save automatically before build is unchecked, I actually prefer to have that checked.







## Demo: Creating a First Java SE Project

We have several methods for creating a project:
* right click the Project Explorer and then New > Project
* the New Project button on the toolbar
* the New panel in the File Menu

Choose a method and select the Java project.
Give a name to our project.
Choose a JDK to run our project. By default, Eclipse will use the JDK it is using itself
Choose a project layout.
Finish.

Eclipse is asking us if we want to switch to the Java perspective, which is a little simpler than the Java EE perspective, so let us do that. And you see that we have a simpler toolbar and an arrangement of views, which is slightly different. And on the top-right of this UI, we can choose to go back to the Java EE perspective or to stay on the Java SE perspective.

Demo: Creating a First Class

To create a class, we can right-click src folder, New, and Class from the pop-up menu.
Put our class in a package because using the default package or the empty package is not recommended in Java.

Demo: Setting the Characters Encoding for Java Source Files

Before we go any further
right-click select this class and open the properties at the bottom.
or can use the shortcut, Alt+Enter, to open the property panel for this class.

By default, the text file encoding for Java source code in Eclipse is, in fact, wrong.
It is inherited from the OS you are using. On my Windows machine, this is Cp1252
it should be UTF-8.
To do this for all Java source code, go to the Window menu > Preferences.
filter for encoding.
General > Content Types
select the Text option in the Content types region
then, at the bottom, enter into the "Default encoding" textbox  "UTF-8"
It will be inherited by all the text generated by Eclipse
select Update, then Apply and Close.
. java files are UTF-8 is in the specification of the language.

Demo: Customizing the Format of the Java Source Files

To customize the way Eclipse formats your Java code. Window > Preferences
filter by "format"  to find  Java > Code Style > Formatter.

Edit the Eclipse built-in format.
Rename it
there are many options, one edit we can make is the selection of the Spaces only Tab policy
4 is a nice default
Apply and click OK. Apply and Close.







### About Eclipse
On Windows and Linux, Help Menu > About Eclipse
Under the About, you'll see the installation details section.
So normally you just get information in an About, right? In an Eclipse, you can actually get quite a bit of information by clicking on things, but this is also where you uninstall things from. If you click on an item, you'll notice the Uninstall button enables. When you uninstall a feature, Eclipse will prompt you to restart, and it's a good idea to do so. We're going to look at some other ways to uninstall, but remember this is here, as it's one of the finest grained ways to uninstall items that Eclipse offers. You can also see your Installation History, Features that have installed, Plug-ins, and Configuration information.

Help menu
This is where you check for updates and install new software.
Let's start with the older method, and use the Install New Software item.
You'll see "Work with" a site pop-up, and there are quite a few that are from eclipse. org.
A lot of those things that we saw when we were on the website, you can download here now, and you can also get additional tooling. I'll select the All Available Sites option, which is the slowest choice. This presents a long list of packages I can update. The package filter is right below

The more modern way to install features to Eclipse is through the Marketplace item on the Help menu.
You'll see by default, there are three Marketplaces available, and after a few seconds, the featured items will populate. Again we have a convenient search area.
There are other tabs you can explore in the Marketplace, but let's look at the Installed tab.
This is the other way of finding out what's installed. It turns out only two items were actually installed using the Marketplace mechanism. What's nice is if you did use the Marketplace to install something, you can both update and uninstall it from this tab. I like Git, so I'm going to leave it here.





Quick Access

You'll notice up in the toolbar, there's a text-entry box that says Quick Access in light gray.
It was a little bit controversial, because one thing Quick Access can allow is a reduce dependence on your mouse, but they wanted to increase the affordability of the feature, so they gave it prime real estate on the toolbar.

There is a hide feature. Just right-click on the border and select Hide from the context menu if you don't want to lose the screen real estate.

The historical way to get to Quick Access is to use the keyboard shortcut is Ctrl+3
On Windows, it's obvious that this window resizes as when you hover over the border, the cursor will change into a two-headed arrow.

Once you select an option, Eclipse moves it up to the Previous Choices section, so that your most recently used items are close at hand. The more you use Quick Access, the more useful it becomes.
So if you know a little bit about Eclipse, you can do some easy fuzzy searching.

This isn't 100% accurate, some text on checkboxes or radio buttons sometimes is not part of the search. So if you're pretty sure there's a feature, and you don't see it doing this, don't give up. You can still look and go find it, but most of the time this is going to get you what you want with a quick search.

I use the Quick Access feature quite frequently, and I use it so much that I actually like to assign that keyboard shortcut from Command+3 to something more convenient.
Let's use Quick Access, and type pref key, and we can jump to the Preferences. We're in General under Keys, and you can see right here is another is another search box. This is going to let us search for all the commands that we can reassign the shortcuts for. Let's just look for Quick Access, and there it is. And as expected, it's Command+3. We can come down here and set the Binding. Now I'm just going to hit 0 on my numeric keypad. You can see it puts in Numpad_0. You can set When this is used, so any time you're in a window is a good choice. And I just find this really convenient, I just reach over with my right hand, hit 0, and I'm automatically in the Quick Access box, and I'm ready to do a search. That's it for the Quick Access feature, use it while you're learning Eclipse, and it'll help increase your productivity. Keep your hands on the keyboard and off of the mouse.


Digging Deep into the Project/Package Explorer


The Link with Editor item.
Now when I click on a file, notice that the Explorer panel scrolled up and highlighted that file.

The collapse all button.
When you've got a bunch of things open, you can click, and you're right back down to your project level. It doesn't remember what you had though, so you'll have to go do everything by hand again.

The View menu.
Right now we are in the flat view, and you can see that JUnit is repeated for each package, and no nesting of packages is shown. If I change the Hierarchical, we nest deeper and don't repeat the project name everywhere. I'll set it back to Flat.

Let's take a look at the context menus. Each level of the Project Explorer has its own context-sensitive menu. They look very similar.
I most often use this on the project level itself, because project properties is really the project preferences, as opposed to when you went to Windows Preferences, you made changes to Eclipse for either all projects or the entire workspace.
There are some settings on the other levels as well. These are much more reduced and typically a subset of the features, but you get finer-grain control if you want to go all the way down to a file.

Go Into
At the project JUnit, we can right-click, and select Go Into, and it'll slightly reduce our complexity, and take us just to this single project. Same thing if we go down to a particular package, and we right-click, and select Go Into. It's reduced our whole view to just that package. If you're working on a single package, it's nice to reduce the complexity.

The back button works just like a browser, only it's faster and reverses your steps. The forward button takes you back in. If you hover over the buttons, they tell you where the navigation will end up. The up arrow just jumps you up the hierarchy, so depending on how you navigated down to a certain level, this can be a faster way to go back.

Open Type Hierarchy
When you want to see some information about the hierarchy of your classes, you can use the Open Type hierarchy. So let's go down to a package level just to make it of a medium complexity, and select Open Type Hierarchy, and you can see the shortcut is F4, and it opens up two panes over here. Clicking on an item up above updates the more detailed information down below. These panes can be individually resized. When the cursor changes to the double-headed arrow, you can click and drag. The buttons at the top provide a lot of control over what you hide and what you show in these views. Type Hierarchy works at multiple levels. We can go all the way down to a file.

Local History

Let's take a look at a feature that I think a lot of developers overlook at first, Local History.
If you use this feature just one time to recover you from broken code, you're going to love it forever.
Local History is a baked-in limited form of source code management. It's not a replacement for a full source code management tool, but it can come in handy, especially between commits.
It can automatically keep snapshots of your editing history, it's available from varying levels, but I typically find it the most useful at the file level.
right click a file in the project explorer and select

down at the bottom, it opened up a History tab.

We can see the original version and the version we just modified.
That opens up the Compare Editor.
It highlights the differences, showing the comments that were added.

Let's also take a quick look at the Chrome.

The second icon lets you copy all non-conflicting changes that are in the right panel, which in this case is the older code, into the left panel, which contains the newer code.
The next icon does the same, but just for the current change.
The next four icons just let you navigate up and down among the changes. The first icon lets you swap the left and right panels, that lets the two buttons to copy changes work from older to newer code, or newer to older code.

The dropdown off the left lets us change from a Java syntax aware view to a standard text view.

If you know you want a previous version of a file, you can right click, and you can say Replace With.

This gives you two options, Local History will let you choose which version, and Pervious From Local History will just choose the previous version.
We can now do the Replace again, this time selecting the Local History option, now we see our various versions. Double-clicking a version lets us see the version down below in the right panel, and quickly compare it to the current version in the workspace in the left panel. We can make sure we have the right version, and then we can click Replace to make that our current version.

Local History settings are under Preferences in the General workspace, Local History Area.
Local History by default is limiting the history size to 7 days. And then the Maximum entries per an individual file will be 50. The max size of the entire Local History file is set to just 1 MB, so you may want to increase this. If you're committing to Git or another repo fairly frequently like you should, you likely won't need very much space, but I usually set to this to be more like 10 MB. You can use whatever settings make sense for you. Some people have run into problems when they unclick this Limit history size. The history files can get really large, and then backing things up, and copying your entire workspace, or the entire project around can get quite big. I think it's a good idea to limit it.

Discovering the Navigator View

The Navigator view can show you some files you otherwise can't see.
The long way to get to it is to use the Window menu, Show View, and there's a Navigator view
It is similar to the Project Explorer, but you can see the files under .[folder] types.
Your source folder is still there, and it also lets you have a quick look and see at the. class path and the. project data files, which you can even double-click and edit here, although I don't recommend it unless you really know what you're doing, but sometimes it can be useful.

The Convenience of Working Sets

Working sets are a convenient grouping mechanism inside Eclipse.
You can groups parts of a project, you can group multiple projects.
You can group unrelated things if you want, it's very flexible.

There are multiple features in Eclipse that will take advantage of existing working sets.
One of the most important is building.
You can group multiple projects together, and then with a single command, you can build them all.

One of the most convenient uses of working sets is searching. If you want to limit your searches to just a few projects or even to just some packages, you can do that as well. And as we progress further into this course, you'll see where working sets show up in many dialogs.

Let's get started with a demo of how to create, delete, and use some working sets.

Drill down to source, and select a handful of packages here.
We'll right-click, we'll come down to Assign Working Sets, we'll click on New, we'll tell it we want a Java working set, click Next, and we need to give it a name then click Finish.
Now we've got a working set. If we created new packages that aren't children of a member of a working set, they won't belong. If they are children, they would be automatically added.

Let's do something with our working set. One of the convenient things to do and demonstrate is searching. We can come up to Search in the menu bar, and do a file search. We'll search for the word test. Now I want to limit this to the newly created working set. You can see it's currently searching the entire workspace. I just click on the working set radio button, use Choose, and select my working set. And once you do this once, it will remember your last chosen working set for your session.

Another way to get to the working set functionality is through the View menu. And from here I just use Select working Set.

Editing Code

Editor Tabs

It used to be that double-clicking tabs in separate panes still supported maximizing the tab. Double-clicking works when you haven't split the editor panel, but once it's split, it no longer works.

Now I can take a tab and drag it outside of the Eclipse window, and the gray bars indicate that this is a valid drop area. When I do let go, I get an external window for editing.

It's now quite easy and intuitive to get multiple views on a single tab. Use the Window menu, select Editor, and the first three options allow just that. Let's start with Toggle Split Editor Horizontal. And you'll notice that the two tabs can look at different areas of the same file. If I select the same option, it restores my un-split view. I can then split vertical. If I hadn't restored my view, this still would've worked. It wouldn't have split my view into four. It would've just changed from a horizontal split to a vertical split.

Let me toggle this split back, and let's try the clone option. Now I have two tabs showing the same view. If I wanted to see different areas of this file, I can of course just drag this tab into its own area. Cloning, by the way, does work along with a split view. So if you have a view split and then clone it, you can have three views on the same file. You can also clone more than once.


Code Folding

The Marker bar is this area all the way over to the left.
Just to the right of that is the Code Folding region.

Let's start with Code Folding.
A negative icon indicates an area that can be collapsed, and a plus icon indicates an area that can be expanded. You can fold at the import level, and the default setting is to collapse the import area. T

When you hover over a collapsed area, a pop-up window will open to show you the contents of the collapsed area. Clicking the icon permanently opens the area. When you hover over the Code Folding icon for an expanded area, you get a little vertical line that shows you what's going to collapse. The entire method will collapse. Again, hovering shows us the entire method with formatting. By the way, you can pin some pop-up windows in Eclipse, just click inside the pop-up, and it pins in a temporary way. The window will stay open when your mouse moves outside of the pop-up. You can even copy contents if you want. Just click again outside the window, and the pop-up disappears. You can collapse at the comment level if you have multiline comments outside of a method.

IN preferences Folding can be enabled and disabled, and you can also initially tell Eclipse which areas you want folded, and you can see which areas are capable of being folded.

Tasks, Bookmarks, and Breakpoints

Adding tasks.
If you add a task, and you're on a line of code, it'll automatically put in the code that was on that line, or you can just enter something manually if it is a blank line. You can click OK. You'll notice it put the task icon in the Marker Bar. It also added the task to the task view.

In previous versions of Eclipse, the task window would open automatically, but now we need to ask for it. Using Quick Access, type svt, arrow down, and the task view opens down below. I can come down to the task view, and I can double-click that line, and that will jump me right back into the code. So when you have a lot of tasks, this is very convenient.

If you want to remove a task, you can do it down here by right-clicking and selecting Delete, and you can also do it right in the code by clicking the Marker Bar again, and selecting Remove Task.

The TODO keyword is recognized by the Java environment. Once we save and then build, it does show up, and it's a full-fledged task. Though  you can't right-click and remove the task, because the comment is still here, it would just come back. So you can either remove the whole comment, or you can just get rid of the keyword that it's triggering on. Then save and build again, and you'll see it goes away everywhere.

Bookmarks are very similar to tasks. You can right-click in the Marker Bar, and you can just select Add Bookmark. And again, if you're on a line of code, it gives you the code in the dialog for the name, or you can type your own text.

The bookmark view also isn't showing by default. We could use Quick Access, and that would work, but since this view is a little buried, I want to drill down and show it to you. It's still under the Window menu, Show View, this time come down to Other, and at the top of the General folder is Bookmarks.

I find one of the most convenient things about the Marker Bar is that you can set breakpoints for the debugger right here. In the Marker Bar, you can use the context-sensitive menu to toggle a breakpoint, but even more convenient is to use double-clicking. To set a breakpoint, all you have to do is double-click, and a breakpoint shows up. Double-click again, and it goes away. I'll recreate it with the menu. If I right-click on the breakpoint, notice that the bottom, the breakpoint properties option. Also notice it has a shortcut of Command+double-clicking. In this dialog, you get some nice options for controlling your breakpoints.

Show Source of Selected Element

Eclipse has the ability to eliminate distractions and show you the source for the selected element only. Eclipse's definition of the source of the selected element is what the blue highlighting is showing you. In this release of Eclipse, the icon for this feature is off by default, so let's go turn it on. It is in the Window menu, Perspective, Customize Perspective area. Then we just need the Editor Presentation option, and there is Show Source of Selected Element Only. I'll enable that. Since the highlighting is on the create method, when I click the button, I bring my focus to bear on just that method. When I need the rest of the class, another click, and it all comes back. That concludes our tour of the Marker Bar area.

Content Assist

Content Assist requires a trigger.
hold down the Ctrl key and hit Space, and I get a list of everything Eclipse thinks I might be looking for.

If I type in enough characters that it's unique when I hit Ctrl+Space, it'll give me the match. If I don't type enough characters, it'll give me everything it can find that starts with that, and then I can continue to type to narrow the list down then I can just hit Return to complete the list.

The period always acts like a trigger key, and all the methods show up on the right with all their parameters. And I can look at those. Let's single-click a method. The documentation pane updates, and the pinning feature works here too. I can click in the documentation pane and temporarily pin it. I'll double-click my method.

Content Assist also works with code templates. So if we just type syso, and hit Ctrl+Space, we can see the template match at the top. Also note that you can continue to press Ctrl+Space and toggle through various panes of Content Assist. Each time the status bar will show you what the next press of Ctrl+Space will display.

Advanced Content Assist

In a Java doc a @ tag has Content Assist suggestions
Create a sample method. I'll type a parameter type of int, and Content Assist offers a default parameter name it offers me for an int is i. Not the most descriptive name, but let's just accept that.

We can create another Java doc, and you can see it automatically sticks in param i for us as well.
If we modify our method and we add a parameter and type @par, and accept that, and now hit Ctrl+Space, it automatically suggests the new parameter we would then want to define in our document.

Let me demonstrate both local variable naming and auto-importing.
If we Content Assist on a new type it automatically did an import for me.
Again  hit Ctrl+Space again, and it auto-suggests multiple names for the new local variable name

If we create a method that returns a string, and takes a parameter of type object, and then we're going to test this object to see if it's an instance of an exception. We want to return obj., and you can see it's already giving us the context-sensitive help for an exception. I'll type get, and select getMessage. And notice that it inserted the cast to Exception type automatically.

Preferences for Content Assist in the Java, Editor, Content Assist section.
Auto Activation is the delay after you type the auto-activation trigger. So after hitting the dot operator, once the specified number of milliseconds has elapsed, if you do nothing, then Content Assist will appear.

In the Advanced settings, there are two panels for configuration. In the top pane, you can specify what shows up when Content Assist first shows you options. By default, it has Java Proposals, SWT Template Proposals, and the standard template proposals. In the bottom pane, you can configure what shows up each time you hit Ctrl+Space to move to an additional panel. You can see the same three options appear, although in a different order, but that there are three additional types of proposals also shown.

There's a Favorites section.  You can see there are a number of entries here, I can explain what this is doing with a simple example. Let's say we want to work with the array, sort, static method. If we type sort, you can see we don't get the method we want. We can use Quick Access, go to Content Assist, back to the Favorites tab. Now just select New Type, then we just need to give it a fully-qualified name, so in this case java. util. Arrays, don't add the dot star at the end, just click OK, and Eclipse puts the proper syntax in. Click Apply and Close. And now when we go to use sort, you can see the options I was after show up at the top of our list.

One final thing, when you delete over typed characters with Content Assist open, it keeps trying to match, even when you have nothing left to match. If you want to get rid of the dialog, just hit the Esc key.


Code Analysis

It's time to talk about one of the other great contributions to programmer productivity, the tool that takes all the fun and mystery of compiling our code, code analysis. The JDT supports both code analysis and quick-fix capabilities. Eclipse uses the term code analysis instead of static analysis, and I prefer to stick with code analysis as well. Plus I'm old school when I think of static analysis as a separate analysis step, and code analysis in Eclipse happens as you type, and that can really increase your productivity.

The intermediate language design of Java allows code analysis to be baked in, the editor is using the actual Java compiler itself to validate the code as you type it.
You can customize the behavior of what happens while you type by customizing the error and warning settings for the compiler itself. In the demo, we'll take a look at those settings. Although the settings can allow you to flag legal, but suspect code, the building options only go so far. Some people, and I count myself among them, prefer to have the compiler or IDE in this case do as much as the heavy lifting as possible. While I won't be exploring them in this course, there are many plug-ins for Eclipse that extend its code analysis capabilities. You can do a search on code analysis in the Eclipse Marketplace to start exploring. You'll find several interesting tools, including the curiously-named PMD, which has been quite popular for a number of years. I suggest you start with the building code analysis. You'll probably know when you're ready to explore these plug-ins.

Code analysis has to be the most discoverable of any feature in the IDE. You just start typing, and if you pause, it immediately takes effect, and you can see it doesn't like whatever I've typed, because it's only a partial statement. So often you just ignore it at first until you finish what you're doing, and then you wait a second, and then errors go away, and you know you have valid code.
If you make a mistake, and you don't know what you've done wrong, then you can hover over the Marker Bar, and get more information about the error.

In addition to hovering over the error, and seeing what it doesn't like, and fixing it by hand, we can also use Quick Fix. There are a couple of ways to do this. My favorite is to position near the end, and hit Command+1.
If your hand is on the mouse, you can just hover on the error, and the Quick Fix menu appears.
This option is also available under the Edit menu, Quick Fix, and you can see the shortcut that should work on your system. But you do have to be near the error, which I wasn't, so let's get at least on the same line of code.

set up to generate an error in our settings.
So that's our excuse to go the tool that I'm apparently obsessed with, Quick Access. And remember that Java doesn't have a separate tool for code analysis, it uses the compiler, so we'll type error, and we'll get to the error warnings for the Java compiler, we'll select that.
make your settings as aggressive as possible. I prefer to have false positives rather than false negatives. It's pretty easy to come back here and ignore something, but if it's automatically ignored, there's no way for you to know that. If you come in and at least make everything a warning, then you'll know which ones you don't like.

Once you're done, we can click Apply, and it's offering to rebuild. Let's allow it. Huh, I would've expected to see an error now. Let me verify my change saved. It looks good, but I'll hit both Apply buttons. Let's just do the build manually. Well there we go. So the setting and feature are working, good to know the first time you change the settings, you may need to manually trigger the build.


Other Editor Features

I want to talk about just a few more additional editor features. Two of them relate to hiding and showing information, whitespace characters and line numbers. There are a lot of tricks for doing things efficiently in the editor, but I wanted to touch on one that I really like, the block editing mode. It can be very useful in certain circumstances, especially when you have a lot of similar code on multiple lines.

In the toolbar, you can see that there's an icon right here for show whitespace characters.

In the Marker Bar, you can right-click, and you can turn on and off Show Line Numbers

In the Text Editors preferences, and here's another way to both toggle off and on line numbers, but there's also an option for showing whitespace with additional options. We can click on configure visibility, and you have multiple options on how you want to see whitespace. I find this very nice and not an option found in a lot of IDEs or editors. You can even set the transparency of the whitespace characters. You can see by default they are at 80% transparency.


block selection mode.
This icon toggles block selection mode, or use Alt+Shift+A.
The cursor changes to this crosshair icon, so you know you're in block mode.
Now you can select the rectangular area on the screen and as I start typing, it will replace everything on every line in the block. I don't actually have to select anything, I'll insert some space between both equal signs and the number on these two lines. I'll drag down. It's a little precise to drag exactly down, but if you get a rectangle, you can just adjust your aim until you have only a vertical bar and not the rectangle like this. Let go and type. I'll do it again to fix the alignment, and one final time to change the comments.


Customizing Eclipse

Perspectives

When you customize Eclipse, you're really customizing a perspective.
You can start out by modifying the current perspective, or you can create a new one.
It isn't dangerous to modify the current one, because you can always get back to the original.
use the Window menu, Perspective, then select the Reset Perspective item.

It's nice not to lose all your customizations by having to reset a perspective. So I recommend creating a new perspective
using the Window menu > Perspective > Save Perspective As.
In the preferences section is Perspectives-General we can
set the default that Eclipse will open to
delete unneeded perspectives


Toolbars and Menus

create a new perspective for experimenting.
reset perspective doesn't do a complete job


We modify the toolbar in Window > Customize Perspective.

If you go to a separator bar and you hover, you'll get a crosshairs icon. And then you can click and drag to move the toolbar that was just to the right of that separator bar.
If you don't want to have toolbar sections moved around, you can lock it down. Using Quick Access, just type lock, and then select the Toggle Lock Toolbars option.
Now the little separator bars are gone. Also since the toolbar uses the mouse anyway, you can just right-click on the toolbar and select the option to lock or unlock the toolbar depending on its current state.

Finally if you don't want the toolbar at all, you can use the Windows menu, Appearance submenu, and select Hide Toolbar. Sometimes this also disables Quick Access on me, but I've discovered that sometimes it works, and changing other visual elements like opening up a file via the Package Explorer will wake it back up sometimes.

Shortcuts (Key Bindings)

keyboard shortcuts are customized from the preferences window > General > Keys
Starting at the top, we have Schemes that we can pick. We have just choices for Default and Emacs,

Good Bindings to set include
Open Declaration which jumps right to the declaration of the class or methods.
The References command shows me everywhere a method or class is referenced.

If you ever want to get a single command's original binding back, you can just use the Restore Command button
If you want to wipe out all your hard one customizations in a single click, the Restore Defaults button will do that.
You can export bindings as a CVS file

You can have more than one binding for a command, but you can't just enter a second one in the binding box. What you do is select the command, and click the Copy button. It gives you a copy without a shortcut, and we can assign a second shortcut to this command now.

Eclipse supports key sequences for shortcuts.

To back up bingings, use the File menu, select Export, open the General section, select Preferences. By default, it's going to save all preferences, and that isn't a bad idea, but you can also save just the keys preferences, click Browse. You'll navigate to a folder of your choosing, provide a name for the key prefs export, click Save, and Finish, and you're done. Well, almost. You do want to be able to import them, but it's almost the same process. File, Import this time, General, and Preferences, click Next, navigate to your saved prefs, click the file, click Open. If you saved multiple prefs, you can elect to Import them all, or import a single section. Click Finish, and you'll have them back.


Additional Views

Let's start with a look at Eclipse's Template view, that's down here. Templates is the term Eclipse uses for code shortcuts. Sometimes you'll also hear terms like code snippets.
If you're just learning Eclipse, and you're just learning the templates, I would suggest you position this in some free space on your monitor or on your second monitor, and it'll serve as a good reminder of the various templates that are available.

No demo is complete without a trip to the Preferences pane, and there is a useful technique I would like to show you. Depending on what you're doing, you can end up with a lot of different console views, and it's easy to lose track of your run/debug console. Let's type console, click on the Run/Debug choice that shows up, select the Background color swatch, and let's set the background to a muted yellow. Let me run, and now it's pretty obvious when our run/debug console window comes to the front.

The final thing to look at is the New Console View. I can select that, and now I get two console tabs. They both contain the same content; however, we can use the display selected console icon, and select the Java Trace in one console, and the run/debug console view in the other. And now it's a little more convenient to switch between the two views.


Navigating Code

Navigate Menu

The Package Explorer is active, and I'm going to start with the Navigate menu, and the Go To item. And you can see the Resource option is enabled. Now this might not always be enabled, but because I started with the focus on the Package Explorer, it is an option available to me. Selecting this gives you a dialog, type to find what you're looking for.
You'll notice Eclipse is doing a begins with search.
If you want to do a contains search, then just start with a wild card character.

You'll also notice that we're looking at all resources, so the search will find more than just Java source files. If you want to limit it to just Java files, you can add the file type(*.type)

I'll double-click this, and you'll notice this will just show you where it is in your Package Explorer. It opens up the right package, and then highlights the file, and shows it to me.

What I find more useful is the Navigate, Open Resource feature. It looks just the same, and you'll notice it even shows the matches from the Go To dialog. The Matching items list will grow the more you use the dialog. And Eclipse takes advantage of this history. We only have one match, but I think you'll get the idea. Let me start the same search, and the dialog shows a section at the top for previous matching items that still qualify, as well as the matches in the workspace.

This time it actually opens the resource in the editor, and another notable difference between the Go To and the Open Resource is now that I'm in the Editor view, when I go to Navigate, Go To, you'll notice that resource is dimmed, but Open Resource is not. So from the editor or from the Package Explorer, I can use Open Resource to get to items.


Hovering

When you hover or a method, if there are Java docs for that method, you can see them.

Chrome
The first icon will show this information in a Java doc view.
If you happen to have the source code, you can open the declaration, and you can also open the Java doc in a browser. So let me just show you the Javadoc view. Now the same documentation is down here.

you can call up an alternate hover function by using modifier keys.
In this case, I want to see the actual source code for the constructor, so I can hold down the Shift key, and then hover over Logo itself. For source code, there are no icons in the window, although I could click on it and lock it in place.

However, I actually find I spend more time looking at code in my current project than I do in the library. So I actually prefer to reverse this functionality. You probably guessed the way I'm going to do that is with Quick Access. Type hover, and then select the Hovers option for the Java/Editor. There are four functions enabled in the left-most column, and in the right-most column, you can see the Modifier Key Press or combination needed for three of them. The Text Hover Name column gives you a pretty good idea of what the function is, except for maybe Combined Hover, which looks through the existing ones that are checked and picks the one it likes the best. You can click on a row and get more detail in the Description box below. Use the Pressed key modifier while hovering box down here. I can delete the Shift modifier, and now select Combined Hover, and then just hit the Shift key. Now Apply and Close. Now when I hover over Logo with no modifier keys, I get the source code. If I go back to ActionListener and hover, I get the source code. But if I move off and I hold down the Shift key and hover again, I have the Java docs. So that's it for hovering. It does inspire you to write more Java docs though, doesn't it?

Outline and Quick Outline


You can see the Outline view over to the right. You'll notice at the top we have a number of icon buttons up there. And the first button can be used to collapse the outline.

The  button is for sorting,
by default, all these methods are showing up in the Outline view in the same order they exist in the file By clicking  we can sort this alphabetically, and it does have some limitations on that reordering.
The static fields and constructors stay at the top, static methods stay at the top,
the fields are followed by all the methods sorted into alphabetical order.
This does toggle, so clicking it again restores the order of the file.


The next four buttons allow us to hide or show various things. The first one lets us hide all the fields. Those are all gone now. The next one lets us hide the static fields and methods. You might think the third one is going to hide publics, but it does just the opposite. It hides the nonpublic, so that only the ones with the green dots are going to remain. Instead of hiding, it makes sense to think of this button as only showing the publics, and your visual cue of that is the fact that there's no slash through this icon. Let me reset a bit. The next one is going to hide local types, so it's really going to take the triangle next to test, and make it unavailable, and close it, so that we can't drill down and see the listener that we've added.

In addition to being able to navigate your code by clicking and jumping to a certain place, and seeing a nice bird's eye view of your code, you can actually reorganize your code here as well. Let's say we wanted our final method to be nearer to the top of our code. We could grab it and just drag it, and you see the bar shows you where it's going to go, so I'm going to put it right under main, and you can undo this if you don't like where you put it, or if you did it by accident.

Finally in Chrome, there's a view menu up here to the right, which has a number of features. One is Link with Editor, which is similar to what the Package Explorer does, but really what it does is toggle how clicking on a method syncs with the editor from single-clicking to double-clicking. It was on by default, so I was just single-clicking. If it had been off, I would have had to double-click, and single-click wouldn't have done anything. I prefer the default.

The View menu also has the ability to filter your Outline view. I'm not crazy about this feature, because it's a little too permanent, and it's a little duplicative of what's in the Quick Outline view, which we're about to discover, but we'll just take a quick look at it. What you can do is come in here, enable it, and then you can specify a filter, and so I'm going to type om and the wild card, so anything that starts with om is going to be filtered. And when I click OK, you'll see that omega over here in the list is going to go away, and that's sort of why I don't like it. I don't want this list to be hiding parts of my class from me other than what's done with these quick buttons up here, they at least give me some clue that something's hidden. I'm going to take that back off.

One other thing that's in the view is Visible Categories. This is related to categories you add with Java docs, so let's take a look at that. As a matter of fact, if we look at it right now, there's nothing we can do, because there are no Java doc categories in this HelloWorld file. I'm just going to add a Java doc to the test here, add a category, and call it testSample. Now you'll notice when I come back over here, the View menu has changed. If I click off testSample, you'll see down below the test has disappeared, and then I can either click on testSample and just toggle it, or I can go into the Visible Categories dialog, and enable it.

However, typically when I want to filter my outline view, it's because I'm looking for a specific method, and that's pretty much what Quick Outline view was built for. So when you're in the editor, you can just hold down the Command key and hit O, and you get Quick Outline view. Very much like your regular outline view, it's just that this isn't a pop-up, and the top allows you to search. So if I wanted just omega, I could type om, and I've winnowed down the list to what I'm looking for. It returned, and it jumps directly to that method just like clicking in the Outline view. The search supports wild cards as well, so you could do contain searches if you needed to. The Quick Outline view also has its own view menu, and you can use these the same way you could use them for Outline view. Finally notice the hint at the bottom. If you want to show all the inherited members, you can hit Command+O a second time. You get a nice long list. This function toggles, so hit Command+0 again, and you'll hide the inherited members.

Editor History and Annotations

The editor history buttons work a lot like the back and forward buttons in a browser. If I click on the dropdown arrow, it shows me all the files I've visited. It will also show how many locations you've been to in each file, and we'll prove that in a minute. For now, let me just click on the back button, you'll notice if the file is no longer open, Eclipse simply opens it for you. I can do it a couple of times. You'll notice it's only taking me to the top of the files, but that's because I never navigated around in these files, I only opened them. We can use the forward button and reverse our course, but the files don't automatically close. Let's bring back Outline view, and we'll go to main, alpha, and MethodWayDownHere. And I want to click on the dropdown. Now you'll notice that the dropdown doesn't have an additional three entries, instead it just shows HelloWorld once, but indicates that it has three locations. I can't jump to those from here, but you can see I'm currently on MethodWayDownHere, and if I click from the dropdown, I'm taken back to alpha, and if I click the back button, I'm taken to main. Clicking again takes me to the next file. Next up is the very useful

last edit location.
When you click this, the last place you actually made an edit gets opened, and it takes you back there directly. That can save you a lot of time if you've been moving around and just viewing code, and you need to get back to the last place you changed. As long as you don't edit, you can keep using the editor history buttons, and the last edit location button continues to work.

navigation buttons.
I'll use the previous annotation button dropdown, and you can see it allows you to specify which types of annotation you want to navigate through. Right now, it is only using errors, infos, and warnings, but there are almost a dozen navigation choices here. The next annotation has the same choices, but any changes you make in one location luckily are synced in the other button.

Breadcrumb.
I can right-click on the editor and select Show in Breadcrumb. But there's also a toolbar icon for this. Once I click it, you can see the breadcrumb that opened up at the top of the window, and unlike breadcrumbs you may have used in browsers where you can just navigate back along the path you came, you can actually use this breadcrumb to get to anywhere in your project. If you click at the lowest level, it lets you navigate anywhere within this class, not just to the locations we visited. If you go up a level, it lets you navigate within this package to other classes. We only have two files, but if we had a dozen, they would all be here. We can also navigate to other packages if we had any, and the same thing applies to the source folder, and then all the way up at the workspace level.


Searching and Navigating with More Power

Call Hierarchy
The call hierarchy works with methods, classes, fields, or initializer.
Lets give it a try with a class file open in the editor
right-click on the class name and in the dropdown list we can select Open Call Hierarchy.
Down below, in a Call Hierarchy tab, we get a list of all the places that call the class constructor in our workspace.

click on a method in that view, and in the right pane, we see the line number and line of code
it also jumped to that line in the current file.

We can also see a little lower in the list that some of these members have multiple matches,
double-click on one of those to jump to the match.

On each Call Hierarchy list item there is a disclosing triangle on the item's left,
opening it displays all callers of that item
These items can, in turn, have their own disclosing triangle


Control Key Links
hold down the Control key and hover over methods, classes, fields, or initializer to open either the declaration or the implementation.
For those that have them, the Super Implementation or the Return Type are also listed.

fields don't get a menu, but the field shows a hyperlink, and clicking it jumps to the declaration of that field.

We can control the hyperlinking behavior.
use Quick Access and type hyper, and go down right here to Hyperlinking - General/Editors/Text Editors. You can see you can
enable or disable the entire feature
change the modifier key
enable and disable the various kinds of links that you want to use.



File Level Bookmarks/Tasks
If you want to set a bookmark or task at the file level, you can highlight the file in the explorer
Edit Menu > Add Bookmark or Add Task

We give it a brief description.
use Quick Access to open the Bookmark or Task windows, and you'll see that these show up
Clicking it will jump you to the top of the file.

These commands are not available from the Context menu, so you need to use the Edit toolbar


Clipboard Navigate
We can also find items based on what's in our clipboard.

We select a methods, classes, fields, or initializer
right click and select copy to put that in our clipboard
go to the Navigate menu, and select Open from Clipboard.
A menu shows all instances in our project


To identify the code file currently on screen
Either Go to the Navigate Menu, or Right Click to access the context menu of the file
select Show In, Package Explorer
or whatever window you're using for navigating around

The code I'm currently looking at automatically opens up the correct package
showing us where the file is, and what part of the file the cursor is on.



Navigate by Searching

There are quite a number of ways to navigate via searching in Eclipse.
The normal find and replace search, tied to the Control+F shortcut, works only on the current file.

There are the facilities for searching across multiple files, and you can quickly configure those searches to the current selection of files, files in the project, workspace, or working set.


Single File-Based Searching,
open a file
Edit menu, you'll see this section of Find features,
Find/Replace, Find Next, Find Previous, Incremental Find Next, and Incremental Find Previous


a normal Command+F, Find and Replace.
highlight some text and hit Command+F
it'll put that highlighted text in the dialog box, a pretty standard Find/Replace box
there are sections for Direction, Scope, a selection of checkboxes for your options, and then the buttons at the bottom.

when I type in the Find box, nothing very dynamic happens.
If I hit Find, it would find any matches

with Incremental selected, this results in a dynamic search
As I delete, it moves back up the previous searches.
Use the Find button to just go to the next instance that it finds
when it gets to the bottom, it will ding and then wrap around to the top.


Incremental Find
Command+J is the incremental find.
Notice at the bottom, in the Status Bar, it says Incremental Find.
All keystrokes are directed to that little area at the bottom.
It's important that you know this feature is here, and you take a glance down there, and see if your keystrokes are getting redirected.
This will dynamically find matches
If there are no matches, so I get a beep and a red warning.
If I hit Command+J again, it will jump to the next occurrence.
If I hit Command+J and we are on the last occurance, it beeps, and I get the not found message
hitting Command+J again wraps to the file beginning.

To get out of this mode.
hit the Esc key, hit an arrow key, or you can just take your mouse and click off.

search across multiple files
,When you would like to search across multiple files use the Search menu
There's Search, and Search File, and then all other options are Java-specific searches.
All three of these bring up the same dialog, although they can activate a different tab on the dialog.

We will start with File search.
This will do a contained search.
You may specify whether it's Case sensitive, a Regular expression, or Whole words.
You can limit it to a certain file name pattern and where the search considers derived resources, the files that the build process creates for you.
The Scope section gives you a lot of flexibility about which files you're going to search
At times, certain scopes aren't enabled.

If you don't happen to be in a file in a project, and you bring up this dialog, Enclosing projects will be dimmed. You need to remember to have at least a single file in your project open if you want to be able to search across all the files in the projects. You can click Enclosing projects.

click Search, and in new search window, results display in a hierarchical tree mode
we can instead come over to the View menu, and we can ask to show it as a list.

Once you've got a search result, I just want to point out that there are a couple of context-sensitive menus here.
If you're not on anything, and you click in whitespace, you get one menu that lets you get to the next match or the previous match.
If you're on a particular match, and you highlight it and click, you'll see that you get many of the same choices, but some of these operate on the item selected.

You can do Replace Selected or you can do a Replace All.

You can also Command or Shift+click to get a selection of files

Use the Preview button to see exactly what's going to happen.
You get the Original Source on the left and the Refactored Source on the right. You can open up any file and select any one or all of the 134 items, and see what is going to happen.

Since I find the File search command to be the most convenient way to do both searching and replacing,

In the Keyboard Shortcuts, type file search, move to the Binding, and hit Command+F, and Apply.
Remove the conflicting command for Find and Replace, and unbind that.

language search.
Search Menu > Java
You have to specify a category in the "Search For" area
If you don't want a second limitation, in the "Limit To" region click "All occurrences"
"Search in" is used here in place of the file type.
The Scope section is the same as it was in the File Search dialog

Overview Ruler and Mark Occurrences

Overview Ruler
The Marker Bar is on the left side of our editor pane, and it is a reflection of the annotations that are present in the current screen for the editor.
The Overview Ruler, on the other hand, sits on the right side of the editor, and it's a reflection of all the annotations that are in the entire file.
In fact, you'll notice that all the warnings are shown here in a light yellow, and we can get a good idea of how many warnings we have in the file with just a glance.

Mark Occurrences
Mark Occurrences is a feature where you click on a variable, or a type, or a method, it highlights every usage of that identifier in the Overview Ruler
Click on any annotation in the Overview Ruler and it will jump to that usage

By default, the Mark Occurrences does not show up in the Marker bar, but you can make it do so in General, Editors, Text Editors, Annotations. And down here in the list is Occurrences. And if you want it to show up in the Marker bar, you can enable the checkbox for Vertical ruler, which is the synonym for the Marker bar.

You can select where they're going to show, and what color they have, what they look like, and if they are included in the previous and next navigation shortcuts, which we haven't talked about, but there's a keyboard shortcut that defaults to Command+. and Shift+Command+.

Before we leave Preferences, let's jump the settings for Mark Occurrences.
This pane allows you to select the elements that are affected by Mark Occurrences

When you have an occurrence and a warning, the warning wins in both the Marker bar and the Overview bar.

 Quite a few things show up in the Overview Ruler, and you can configure even more.
Jumping to Warnings and Errors

The JDT will parse the output from the build process, and put errors and warnings down in the Problems tab.
To open a Warning or error double-click, and the relevant source file opens up in an Editor tab with the problem line highlighted.

My recommendation is to turn on Link With Editor, and then as you open each problem, even if it's a different error in a different file, it will automatically open up that section in the Package Explorer.

If we want to navigate through the various warnings and errors in this file, all we have to do is just click on the links in the Overview Ruler here, and it'll take us to all of those.



Making the IDE Work Harder for You

Shortcuts

The pop-up windows often have shortcut hints.
Hovering often reveals shortcuts as well.

Let's start with a shortcut we've already visited, Command+O, Quick Outline.
Notice there's a related shortcut, in this case it's telling us Command+O will now invoke a function to show inherited members.

Previous Annotation.
A lot of people like to change these so that only errors and warnings show up on the annotations, use Ctrl+. and Ctrl+,. So using a combination of these two, you can navigate through your errors, then use Command+1 to pull up Quick Fixes and modify your code, never pulling your hands off the keyboard.

Ctrl+E, automatically makes the Show List menu appear.
Shift+Ctrl+L is a shortcuts list, this is not a comprehensive list
    Shift+Ctrl+L a second time opens the Preferences pane.

 Command+/ The shortcut to toggle commenting

Shift+Ctrl+P on either side of the bracket will jump you to the matching bracket.

Shift+Ctrl+O organizes imports using the wild card syntax, you can just position on that line, hit Shift+Command+O, and the IDE does all the heavy lifting for you.

Alt+Shift+up arrow and down arrow will progressively select the enclosing element.

Ctrl+Alt+up arrow will duplicate lines.
A line will be duplicated and moved up, and my cursor will be moved to the new line.
Ctrl+Alt+down arrow is called copy lines
It takes the current line and copies it down, and moves your cursor down one line.

We can navigate quickly through a class with Ctrl+Shift+up and down.
From the start of the class, each subsequent use takes me through the fields, then the class methods

Ctrl+D delete a line

If you want to get to the Java docs on a class  hit Shift+F2.
It opens a browser inside an Editor pane, and jumps you right to the help for that item

Tips and Tricks

Content Assist supports camel case matches when entering code, which displays Content Assist options based on an element's initials.

Automatically insert braces and semicolons
Preferences > filter brace > Java\Editor\Typing > "Automatically insert at correct position" > Apply


Alt+Shift+Q
Pulls up a complete list of all the Alt+Shift+Q shortcuts.
With this window, I could either keep typing, or I can just arrow down through the list, and then hit Return to get the one I want.

Sort Members.
Source > Sort Members
Preferences/Java/Appearance/Members Sort Order




Help!

http://help.eclipse.org


local help reflects the actual Eclipse components that you downloaded and installed.

When you're searching for help on a particular section of Eclipse, you can use the scope feature to limit your search to just the areas of interest. You can easily remove the scope filtering by using the search all topics feature.

The query syntax is pretty straightforward, but it pays to know a little bit about it.
When you type multiple words, you are doing an and search, so each word you add will reduce your matches.
If instead you want to broaden your search, type or.
If you want to eliminate some matches, proceed a word that you're not interested in with not.
The Help System also supports some wild cards. Counter intuitively sometimes using wild cards can actually show you fewer options, because without wild cards, Eclipse searching employs word stemming. So you can just type the root of a word, and your query gets conflated to include words derived from the root. So for example, if you type the word compile, Eclipse will also find complier, complying, compiled, compilation, and other related terms.
You can defeat word stemming by using wild cards or quoting a single word, and you can also use quotes for phrases. Wild cards, as you might expect, won't work inside a quoted string. Finally all searches are case insensitive.

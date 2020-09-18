# Eclipse for Java Developers















Demo: Exploring the Java Build Path and the Installed JDK

Right Click project node in Project Explorer > Preferences ( Alt + Enter ) > Java Build Path
Here we  can see that version of Java our project is running
From the Libraries tab we can select other options
By default, Eclipse has chosen the JDK it is using to run itself as a Java application.
Click the declaration of the JDK then "Edit"
we are presented with another panel that will show us all the JDK that are known to Eclipse here.
If we click the Environments button here, Eclipse will show us all the versions of the JDK it knows and the associated installed JDKs.

Demo: Adding a JDK in the Java Build Path

To change that, we go up one level in Preferences to Installed JREs
To add a JDK. select "Add" > Next >  Directory (Top right)
navigate to where the jdk is installed and select it
Here Eclipse is happy because it found all the necessary files for the JDK.
Click Finish
Click Apply
go back to the Execution Environments.
Select the desired environment and Apply and Close

To complete the change we visit the Java Compiler option

select the proper JDK up top
click Apply and Close.
Eclipse asks for a full rebuild since we changed the version of the compiler, which is normal.

Demo: Creating a Second Project with a Dependency to It

To tell Eclipse that one project is depending on another in the same workspace.
Enter properties (alt + enter) > Java build path
In the projects tab select add, select the project dependency
Apply and Close
Now first-project knows the other.

ask Eclipse to fix the imports of this class by using Ctrl+Shift+O as a shortcut, it imports the dependency package

This is how you can declare dependencies between your Java projects. Go to the properties of the project. On the build path here Projects tab, you just add the project you need as dependencies to this project.

Demo: Adding Source Folders to a Project

(Alt + Enter) Properties > Java Build Path > Source Tab > "Add Folder..."
Source Folder Selection panel > "Create New Folder..."
New Source Folder panel > name the new folder > Finish
check it's box in the Source Folder Selection panel > OK
Now it appears in the source folder tab of the java Build Path option in the project preferences panel
Apply and Close
This new source folder is now shown in the Package Explorer.


Demo: JUnit Added as an External Library

To import the JUnit Library
( Alt + Enter ) Properties > Java Build Path > Libraries Tab > "Add Library..."
the JUnit package is easily found since JUnit is already known by Eclipse.

Demo: Adding AssertJ as an External Dependency

A very good assertion framework in the Java space is called AssertJ.
how can I use AssertJ instead of JUnit?

(Alt + Enter) Properties > Java Build Path > Libraries Tab
AssertJ is not known as a default library within Eclipse.
We create a library
Libraries Tab > "Add Library..." > Add Library Panel > User Library > Next
User Library Panel > "User Libraries..." > User Libraries Panel > "New…" > New User Library panel
name it "AssertJ" > OK.
User Libraries Panel > "Add External JARs..." > select the AssertJ file from file system
Apply and Close
User Libraries Panel > "Finish"
Java Build Path > Apply and Close


Demo: Packaging a Set of Project in an Executable JAR File

Project Explorer > Project > Context Menu (Right Click) > "Export..." > Export Panel > "Java" > "JAR file"
"Next" > JAR File Specification panel

From this panel, we can select the resources we want to export:
classes from the project package, the src files.
any dependency package src files.
We do not want to export the .settings which contains  the .classpath and the .project.

In "Select the export destination:" text box choose the relative file path and name of the .jar file
Example:     first-project\jar\first-project. jar.
In "Options:"     Compress the contents of the JAR file.

Click Next.
In the JAR Packaging Options panel, all the default "options for handling problems" are correct.
We should not launch the construction of the jar file if we have compile errors anyway

Check the "Save the description of this JAR in the workplace" box
save the description of the JAR in the top of the project hierarchy and name it the same as the project.
Eclipse adds the jardesc extension to this file automatically.

Click Next.
check "Generate the manifest file"
The manifest is the file inside the JAR file that is going to describe the content of the JAR file.

Click "Browse..."  and select a main class to make this jar runnable. > click Finish.
Eclipse is going to create this location for us automatically.


Setting up a Java Maven Development Environment with Eclipse

Introducing How Eclipse and Maven Work Together

Eclipse supports Maven using a plugin.
If you have downloaded Eclipse for Java EE developers, you already have this plugin installed.
Eclipse also comes with an embedded version of Maven. So if you have downloaded this version of Eclipse, you also have downloaded a version of Maven. This is very useful if you want to fiddle around to play with Eclipse and Maven and see how things work.

A development production environment, will have their own version of Maven configured.



Demo: Introducing, Updating, and Configuring Maven

check the Maven configuration of Eclipse.
Window menu > Preferences > filter for Maven

in "Installations" we see that this version of Eclipse comes with an embedded version of Maven
in "User Settings" we see the default local repository for artifact dependencies and plugins is C:\Users\[user]\.m2\repository

This configuration works perfectly well though you can change it.

"Installations" > "Add… " > New Maven Runtime panel > "Directory… "  > locate the Maven installation Click OK > Finish > and in Installations select this version > Apply

"User Settings" panel > right of User Settings textbox "Browse..." > navigate to prefered settings.xml
click Update Settings > Apply and Close



Demo: Creating a First Maven Project

Package Explorer view >  Context menu > New > Project > Filter "Maven" > Maven project > "Next"
confirm defaults "Next"

A Maven project is known by three elements, a Group Id, an Artifact Id, and a Version.
Group Id is the package
Artifact Id is the project namethe
version number, 0.0.1-SNAPSHOT
"Finish"


A typical Maven project has four folders,
two for source and test code and two for the source and test resources.


Demo: Configuring a Maven Project, Updating the Java Version

The pom.xml file is the main configuration file of any Maven project.

We can see that our POM just took the groupId, artifactId, and version that we created the project with

The first thing we need to do is to fix the Java 5 version.

We are going to use the <properties> element, and create three properties.
<maven.compiler.target>1.8</maven.compiler.target>
<maven.compiler.source>1.8</maven.compiler.source>

It means that we are going to type in Java 8 source code, and we expect this source code to be compiled using Java 8.

<project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>

Indicates source encoding is UTF-8.

Those are the three standard properties every Maven project should provide.

Once this is done, we can tell Eclipse we changed the version of Java for this project. Now you can update automatically this Eclipse project taking into account this change.

Package Explorer view >  Context menu >  Maven > Update Project > OK

The Java 5 default configuration has been changed to Java 8 to follow the configuration of the pom. xml.


Adding Dependencies

For a new dependency Search for artifactId here: https://mvnrepository.com/
copy and paste <dependency> info

For a previously used dependency, one that is now in the .m2/repository

pom.xml context menu > Maven > Add Dependency… > search for artifactId

Testing dependencies

        <!-- https://mvnrepository.com/artifact/org.assertj/assertj-core -->
        <dependency>
            <groupId>org.assertj</groupId>
            <artifactId>assertj-core</artifactId>
            <version>3.15.0</version>
            <scope>test</scope>
        </dependency>

        <!-- https://mvnrepository.com/artifact/junit/junit -->
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.13</version>
            <scope>test</scope>
        </dependency>

Surefire supports three different generations of JUnit: JUnit 3.8.x, JUnit 4.x (serial provider) and JUnit 4.7



Demo: Running Maven Tests, Running the Package Maven Goal

We can execute Maven goals from the Package Explorer
Package Explorer > pom.xml context menu > Run As > select a goal

But suppose that we want to do something that is not readily available in this menu, like Maven package or Maven deploy on a special repository.

Package Explorer > pom.xml context menu > Run As > "Run Configuration… "

In the Run Configurations panel
Name: Maven Package
Base Directory: "Workspace..." > HelloWorld
Goal: package

Apply

Run this code.
In the console, we can see that all the lifecycle of the Maven build has been executed, resources, compile, test resources, test compile, test, which is a success, and then package by calling the maven-jar-plugin. We have created a hello-service-0. 1. jar in the target directory of our project.



Using Git for a Java Project in Eclipse

Introducing How Eclipse and Git Work Together

Eclipse supports Git through the user plugin installed in the default installation of Eclipse itself.
So if you have downloaded the Eclipse for Java EE Developers, you do not need to download anything more.

Eclipse also comes with an embedded version of Git, so you do not need to have any separate installation of Git.


Demo: Configuring Git and Creating a Project Repository

The first thing we might want to do is go to the preferences of Git, so

Window > Preferences > filter "Git" > Git/Configuration options > Configuration panel

"Add Entry… " > Add a configuration entry panel
Key textbox: user.name
Value: [your name]

"Add Entry… " > Add a configuration entry panel
Key textbox: user.email
Value: [your email]

those two values are going to be used by Git automatically to fill in the author and the email address added to each commit.

Apply and Close.

Now is the second step. Let us create a Git repository with this project.
Package Explorer context menu >  Team > Share Project > Configure Git Repository panel

checkbox " Use or create repository in the parent folder of the project"
 Select the project > "Create Repository" > Finish

visually speaking, the appearance of the project in the Package Explorer has changed a little.
The golden cylinder on this project icon shows that this project is handled by Git.

Demo: Configuring the .gitignore Git File

create and configure the so gitignore file to filter out all the elements from that project that we do not want to put in the Git repository.

Project Explorer >  > uncheckbox ".* resources"

This the technical files created by Eclipse and the hidden files that we do not usually see.
there are two files and one folder that we want to filter, enter into .gitignore:
.classpath
.project
.settings/

.classpath and .project, which are Eclipse technical files.
. settings folder that is also created by Eclipse to store some information on our project.

you can see that the aspect of some file icons have changed.
Now the. classpath and the. project, file icons are not marked with the question mark sign

Demo: Creating a First Commit with the .gitgnore File

Project Explorer context menu > Team > Commit >  Git Staging view

We have four main areas on this view.
The Unstaged Changes area.
The Staged Changes area.
The Commit Message area.
The author, the committer, and the two buttons, Commit and Push and Commit.

Drag files to the "Staged Changes" area to commit them
the file icon aspect of that file will change, a little plus sign is added to it.
This can also be done using Project Explorer context menu > Team > Add to Index
Select the .gitignore file
add a commit message, "Created gitignore", and press the "Commit" button.

The file has been committed to the Git repository.

Demo: Browsing the History View of a Git Repository

To have a look at the state of a given repository in Eclipse, we need to open a special view.
Window > Show View > Other > filter History > Team/History > Open
This view is blank when first opened, highlight your project in the project explorer
In the History view find  just under the view tab
It will synchronize with the Package Explorer view to show you the commits pertaining to the element you have selected in the Package Explorer view.

Demo: Checking out and Watching All the Commits of a Repository

By default, this History view only shows the current commit, and the previous commits of the resource we have selected.
Use  To see all the commits and all the branches, Show All Branches and Tags.

Demo: Creating and Checking out a Branch

History view > highlight the commit to branch > right click context menu >  "Create Branch… "

Demo: Merging Two Branches with a Conflict

Once we have done some development on a branch that we want to merge with our master branch

History view > highlight the master branch > right click context menu >  "Check Out"
History view > highlight the branch to merge > right click context menu >  "Merge"

When conflicts occur

Those branches with different versions of the same file will have a conflict occur upon merging
highlight the affected class in the Project Explorer > Team > Merge Tool

This Merge Tool view is divided into three parts.
The first part is the Structure Compare and the Java Structure Compare.
The second part is the current commit we are watching
The third part is the commit that we are trying to merge.

Merge conflicts between the second and third parts are identified and resolved using the middle bar.
Closing the view prompts a file save, accept this

commit this merged file, Team, Commit, stage the changes.
The conflict has been solved.

Demo: Preparing a GitHub Repository to Push a Local Repository

A GitHub repository is a cloud repository.
Access a GitHub account,
create a new repository.
do not initialize it with a README because I am going to push some content to it, and creating a README would create a first commit in this repository, which will create problems with this push operation.

copy the HTTPS URL.

Demo: Configuring a Push Operation and Pushing to GitHub

Window > Show View > "Other… " > filter Git > > Git/ Git Repositories


It will display our current project
highlight Remote > right click context menu > "Create Remote… " > New Remote panel

The default name "origin" is fine, the configure push option is selected. > OK

provide the URI for this remote repository. > "Change… " > Select a URI panel
URI: paste the Github URI
Host and Repository path are filled
Protocol is https
provide your user name and my password and click Finish.

now we provide Ref mappings.
In a nutshell, these tell Git what branches and what labels to push to the remote repositories and the matching between the local branches and the remote branches.

Here we can click the Advanced button.
My local Git is fetching information from GitHub. And since the GitHub repository is completely empty, it does not give me, of course, any branch or label that would already exist in the remote repository.

Select "Add All Branches Spec" and "Add All Tags Spec" > Finish.

Either "Save" or "Save and Push"
or in Remotes highlight the Push directory and right click for the context menu > Push

Upon pushing you will be asked for your credentials again.

Demo: Using an SSH Key Pair to Push Commits to GitHub

having to enter a password every time we want to push stuff to our Git repository is quite annoying.

And for some security reasons, we do not want to record our username and password inside the Eclipse configuration file. There is another solution to provide credentials to GitHub and other Git remote repositories, which is to come with a key and use SSH.

Configure an SSH key on your github page
Personal Settings > SSH and GPG keys > follow the instructions there


tell Eclipse where to find our private key.

Preferences > filter SSH > General/Network Connections/SSH2 > "Add Private Key… "
Browse to ssh keys
ex: C:\Users\L\.ssh\(id_dsa id_rsa)

Now we need to Configure Push once again.
Select the remote repository in the History view and right click > Configure Push…

The SSH stuff appears here automatically.
Here you need to select the SSH protocol if it is not correctly configured by default.
Click Finish

Advanced, and we are presented with the same Configure Push window that we already saw.
Select "Add All Branches Spec" and "Add All Tags Spec" > Finish.
Save and Push


Demo: Configuring and Using the Fetch Operation

Let us now make a modification to the remote Git repository by adding a README file to it. And this README file is just fine. Let us commit it. We have now a nice README file in our repository. And in the process, we created a new commit, the SHA1 is 7b1. And if we go back to Eclipse, we can see in our History that the last commit we have is 4c4, which is not the last commit in our GitHub repository. So the best thing to do for the moment is to fetch those modifications, get this last commit present on the GitHub repository, and not present on our local repository. So for that, we need to configure the fetch operation, which is the second operation that we haven't touched yet in this origin node. So let us do that. Configure Fetch. Let us check this. The URI is correct. The SSH protocol has been selected. Let us click Finish, Advanced. We want to fetch all the branches and all the tags. Let us click Finish and Save. And you see that the credentials we created for the push operation have also been used for the fetch operation, so no password has been asked. Now we can just fetch the modification locally. Here is the report. Let us click OK. Let us go in the History. Select the project here. And we can see that the origin/devel branch is on the same commit as our devel branch, but the origin/master branch is one commit ahead. So what we just need to do is to merge this commit in our master branch. It is, of course, just a fast- forward merge, and the README. mardown file has been created locally. Let us add some content to this README, Welcome to sample-git-for-Pluralsight. This is a sample repository for my Pluralsight course Eclipse for Java Developers, used to push and fetch elements. By the way, we have a nice preview in the Eclipse interface. Let us commit this code, Added some comments in the Readme. We can directly Commit and Push. Let us do that. This is the report for the push operation. Let us Close and check the History. The last commit we did was the b4ec. Let us check here. Refresh this view, and indeed the b4ec commit has been properly pushed to GitHub.
Demo: Creating a Local Project by Fetching a GitHub Repository

We still have two elements to cover, which are the same, but in two different contexts, which consists in fetching repository locally when we have no code locally. So here I just closed the sample-git-project. I will still be using this sample-git-project from GitHub. And what I want to do is to import it locally. So with that, I can go into the Package Explorer, pop-up menu, select the Import option here. Let us open this a little. I have this Git node there, so I can import a project from a Git repository. I am going to use a Clone URI. Here I am presented with the same kind of window as the fetch window we already saw. The URI is the Git URI using SSH. Let us select the SSH protocol here. Click Next. Since we have already configured Eclipse to connect to Git, Eclipse is able to query this Git repository to get everything. Let us click Next. We are going to create this project locally in sample-git-for-Pluralsight, and automatically Git will register this remote repository as the origin repository, keeping this configuration. Let us click Next, and we are going to import this project as a general project. The name of this project will be the same as the repository. Let us click Finish, and now we have this project created here for us. The problem is that this project as such is not seen as a Java project. Why? Because we decided not to push the. project and the. classpath Eclipse configuration files to GitHub, so Eclipse could not recognize this project as a Java project. Once we've done that, we need to tell Eclipse that this project is a Java project. So select the project, pop-up menu, Properties. Here we are going to select the Project Facets from this Properties window. Convert to faceted form. Just select Java here. Select a runtime here, which is Java 8. Apply and Close, and we are done. We now have a proper Java project. So those steps are the steps you want to follow when you want to import an existing Java project from a remote repository locally. By the way, if we check the Git Repositories view, we can see that in the Remotes node, the GitHub repository has been automatically configured with proper push and fetch operations.
Demo: Fetching and Importing a Git Maven Java Project

The other context you may find yourself into is when you want to import an existing Java project, but that happens to be a Maven project. Here I created another GitHub repository called sample-maven-git-for-Pluralsight. And you can see that there is a pom. xml file in this repository, making this project a Maven project. The previous project we imported was not a Maven project. It was just a plain Java SE project, and now we have a Maven project. So we are going to clone it using SSH. Let us copy this to the clipboard. And there is a special plugin to import this project directly, making the creation of the Maven project simpler than the Java SE stuff. Basically, we will not have to deal with the facet property of this project as we had to do in a previous case. Let us see how it works. We can either import it directly, select the Maven stuff here, and check out Maven project from source control management or create a new project. And in the Maven node here, we have also the same option, Check out Maven Projects from SCM. Let us click Next. Now the problem is that the default Eclipse installation comes with no support of no source control management system. For that we need to install a special plugin that is not present by default in the Eclipse installation. We can click on this link, find more source control management connectors on the marketplace. So let us go to this marketplace. And what you want to do is look for m2e-egit. Select this m2e-egit plugin here. Click Finish. Next, Next. Accept the license. Finish. Install anyway. Restart your Eclipse. And when this is done, you are good to go. So let us Import, Maven, Check out Maven Projects from source control management. Next. And now you can see that you have the Git option, which is available. Let us paste the URI of our repository. Check out Head Revision, which is fine. Click Next. Everything is fine here. Click OK, and this time the project is directly imported from GitHub to our repository and properly configured as a Maven Java project.
Demo: Fixing an Imported Maven Project

Once you've done that, you may need to fix the configuration of this Java Maven Eclipse project. There is no error shown in this Package Explorer view. But if we check the properties of this project, you may see that some elements are missing, so let us fix that. So to do that, you need to select the project, pop-up menu, and go to the Properties option, Java Build Path. And in the Source option here, add the different folders. You see that Maven is complaining, for instance, because the src/test/Java is missing. So let us add this folder. Create New Folder, src/test/java, Next, Finish. Now it has been created. We can also create src/main/resources, Finish, and src/test/resources. Those are the four standard folders that Maven is using to work properly. Let us click OK, Apply, Apply and Close, and now Maven should not complain anymore. The error message that was present on src/test/Java is not here anymore. So you see that importing a Maven Java project from a remote repository is a lot simpler than importing a plain Java SE project. The odds are that most of the time, the projects you will need to import are, indeed, Maven projects. The only caveat is that you need to install the right plugin before doing that because it is not present in the Eclipse installation by default.
Module Wrap Up

And with this, I think we are ready to wrap up this module. What did you learn in this module? Well, you learned everything you need to know to properly work with Git within Eclipse without using the command line. Now there are still things that are not implemented in the Eclipse interface, so being able to use Git through the command line is still very useful. You saw how to conduct the main Git operations using the Eclipse interface. You saw how to create and configure a Git repository, how to commit, how to create a branch, and how to use the Merge Tool in a conflict situation. You also saw how to configure a remote Git repository from within the interface and configure push and pull operations between your local repository and this remote repository. You also saw how to deal with credentials, the classical HTTPS, username, password, credentials, and also the SSH protocol based on the use of private and public keys. And you also saw at least how to import a Java project from a remote Git repository locally in two cases, a plain Java SE project or the most useful one, which is a Maven Java project. By the way, all the repositories we saw in the example are still in GitHub. I do not plan to delete them, so feel free to use them if you want to practice. And with this, I think we are done. Thank you for watching this module. I hope you found it interesting. And I hope we will meet again in the next module of this course about connecting Eclipse to databases, which is a first step to what you will see in the last module of this course about Java EE applications.
Connecting Eclipse to a Database Server with MySQL
Module Introduction and Agenda

Hello, my name is Jose. I am very glad to welcome you back to this Eclipse for Java Developers course. This module covers the connection of Eclipse to database servers with the example of the MySQL database server. What are you going to learn in this module? Well basically how to work with database servers from within Eclipse, which might look very handy. Eclipse comes with a SQL plugin, at least the Java EE version of Eclipse, which is the one we are talking about in this course. First, you will configure Eclipse to connect to database servers, and the example will be the MySQL database server. And in the second step, you will see how to create and configure a connection to a particular database instance. And then when this is done, you will be able to create tables, add and query for data, import and export data from and to your database server.
Introducing How Eclipse and Databases Work Together

So Eclipse and databases, how does it work? Let us first see the big picture of the organization. You know that Eclipse is a Java software. And as such, connecting to a database for Java software is built on JDBC. JDBC stands for Java Database Connection. It is a standard API available in the JDK from the very early versions of the JDK. So as a Java application, Eclipse needs a JDBC driver to connect to the corresponding database server. JDBC is an API mostly made of interfaces. There is no implementation in it. So you need an implementation particular to each database server to implement this JDBC API. So the first step is to install this JDBC driver in Eclipse so that it can connect to the database server you need. Then when this is done, a connection can be created and used, and a connection is made of basically three parts. First, a URL, and second and third, a username and a password to connect to the database. Just as a side note, if you are not familiar with JDBC or database programmation in Java, you can check several JDBC courses available here, on Pluralsight. Let us first see more precisely how things are organized. You probably remember from an earlier module that all the projects you can create within Eclipse are stored in subfolders of a workspace root folder. In this workspace, there is a subfolder hidden called. metadata in which Eclipse stores various technical information. This is where the JDBC driver of the database you want to use is going to be stored. Of course, several JDBC drivers can be installed within Eclipse, for instance, MySQL, Postgres, SQL Server, Oracle DB server, and the like. So these JDBC driver installation is made at the workspace level and thus made available in all the projects from this workspace. Once you have a project that you want to connect to a database, a particular connection to a particular database server instance will be stored at the project level. So if you have several projects connecting to this same database instance, you want to create one connection per project. This is how things are organized at the workspace level.
Demo: Introducing the Test Project to Create Data and Queries

Now that we have the big picture in mind, let us jump in the live demo of this module. Let us connect Eclipse to an existing MySQL database instance. First, we install the JDBC driver. Then, we create a connection. And then, we play with it, passing SQL queries back and forth to the MySQL database instance. So first, we are going to begin with an existing Java Maven project that I just created in Eclipse, Java 8 Maven project called user-db. It has a dependency to the mysql-connector-java JDBC driver provided by MySQL. Every database vendor provides a JDBC driver, so the first step, of course, is to find this driver, which is, most of the time, very easy. Then we have a user class, which is just a plain JavaBean with two properties, name and age, respectively a String and an int. And then a CreateUser that is going to create a set of user in an existing database. The database URL is localhost/Pluralsight, and the dbUser and its password are both Pluralsight. Of course, never use this kind of thing in a real production environment. Then we are just using plain JDBC code with a PreparedStatement and a batch to create four users in the database. And then we have a ReadUser class, which is just reading back the users from the database. This database exists. I have MySQL server up and running on this local machine. And if you want to run this code yourself, you should have search a server available on your machine. Installing and configuring MySQL is beyond the scope of this module, but I guess that you're able to do that yourself.
Demo: Creating and Configuring a Connnection to a MySQL Server

For the moment, this database instance is empty. There is no table in it. So what I want to do first is to connect to this database and create the right table. For that, we are going to use a special view available in Eclipse, Window, Show View, Other, which is the Data Source Explorer. Let us open this view. This view could appear anywhere on the perspective. So if you want to drag and drop it from one place to another, you can just do it like that as usual. And by the way, if you are using the Java EE perspective of Eclipse, the Data Source Explorer is already opened in this perspective. Let us switch back to the Java SE perspective. For the moment, this Data Source Explorer is empty. What we're going to do is create a database connection from this node here. Pop-up menu, View. What we want to create is a connection to MySQL server. And we are going to call this MySQL connection profile MySQL Pluralsight. Click Next. There is no driver available. Here this drop-down list is empty. So let us click on this button to create a new driver definition. What we want to create is a JDBC driver to the 5. 1 version of MySQL. So let us create this one. Switch to the JAR list. Here there is just a placeholder telling us the name of the file we are looking for. So at this point, you need to know where, for instance, in your Maven repository your MySQL JDBC driver is located. It is located here, so I can just open it. I can get rid of this one. Switch to the Properties of this driver. The Connection URL will be to localhost/Pluralsight. The Database Name is Pluralsight. The User ID is also Pluralsight. And by the way, the password is also Pluralsight. Let us click OK. We are going to save the password in the Eclipse configuration file, which is not necessarily very safe. And we can test the connection here. The connection is okay, meaning that Eclipse has found the right driver, that the database is up and running, the URL is correct, database name is correct, and the user and password are also correct. Let us click Next. We can review here the different properties we set up. They are all correct, so let us click Finish here. Now we have a database connection available here. And if we open the Pluralsight node, we see the Schemas the Pluralsight user has access to and see that there is no table in this database.
Demo: Creating SQL Queries and Editing Data

Now that we have set up a connection to our database, let us see how we can launch SQL queries to it. For that I am going to create a file in this file folder, and I'm going to call it create. sql. The SQL file is a known file by Eclipse, and you see that we have a special editor for those SQL files. Here we can select a connection on this file. Let us select MySQL 5. 1, the name MySQL Pluralsight, and the connection to the Database, Pluralsight. Eclipse tells us that we are connected and in Auto Commit mode. So from now on, we can type in SQL code, so let us create a table called user with a primary key called id. It's going to be an int primary key and auto_increment. Then the name is going to be varchar of 80, for instance, and an age, which is going to be an int. We can execute this statement directly from within this file, pop-up menu. We have three options, Execute All, Execute Selected Text, or Execute Selected Text As One Statement. Let us choose this one. And executing this SQL query automatically opens another view called SQL Results view with the status of our query. Our create tables user query has been successfully executed on the database. If we check back in the Data Source Explorer, refresh this Tables node now, we indeed have the user table that appears here with the different columns we have created. Let us save this file. Now that we've done that, we can use our CreateUser class to create a set of users in our database. Let us run this class. Pop-up menu, Run As, Java application, check the console. This message at the end of the execution is just the execution of the batch. We have one line created per batch line, which is expected. And now if we check in the data source explorer, we can select the table, pop-up menu, Data, and click Edit to see the content of the user table with the four users that we have created in our code. By the way, we can also use this Table view to interact with the table and to create data in it. If I click on new row here, add a user, Jennifer 39 and Michael 21, all I need to do is save the result. the message in the SQL Results view tells me that the two insertions have been made. And if I refresh this view, the two generated primary keys are appearing in the id column of this table.
Demo: Using the SQL Scrapbook to Test SQL Queries

By the way from the Data Source Explorer view, I can also click on this button to open a SQL scrapbook. What is a scrapbook? It is just an empty SQL statement file that is automatically connected to the Connection profile file I have selected in the Data Source Explorer. So if, for instance, I type in another query, select count from user, select this code and run it using the Alt+C shortcut, I will have MySQL result in the SQL Results view here. And if I want to see the results, I need to click on this button here to see that I have six users in my table, which is of course the expected result. Now if I run the ReadUser code here, let us move this view, that is going to read the content of the table, make it a list of User object, and print out each user. Let us run this code as a Java application, watch the result in the console, and indeed I have all the content of my table that is displayed by this code. I can, of course, save this scrapbook, or instance in the files folder, scrapbook. sql. OK. This scrapbook has been saved. So this scrapbook stuff is a very convenient way to launch various queries on a database, to save them, manipulate them, modify them, etc.
Demo: Exporting and Importing Data

I can also directly export the data of a table in a text file using this option, the pop-up menu of a table node, Extract. I can choose the Column delimiter, Command, Semicolon, etc., the Character string delimiter. Let us click Finish. So the creation of the user file is mentioned in the SQL results view. And the user file itself is correctly created in the files folder. Here is the content of the five in plain text. We can check the contrary. Let us delete the data from the user table. Alt+C to run this. If I render select count once again, I'll see the count is now 0. So I have deleted the content of the table. Let us go back to the Data Source view. Select the user, pop-up menu, Data, Load. Navigate to the user. txt file. Import this data in the table. The SQL Results view tells us that six rows have been created, and indeed if I run the select count once again, Alt+C, I have now the six users that are back in my database. So this import/export functionality is also very handy, especially if you already have data in a text file that you want to import directly within MySQL.
Module Wrap Up

And with this, I think we're okay with this module. So what did you see in this module? Well you saw how to connect Eclipse, which is a Java application, to any JDBC database as long as you have the JDBC driver. Everything we have done with MySQL can be done with any database server. We saw how to use the different views, the SQL view, the Database Explorer view, and the like. We saw how to write and launch SQL queries and to get results in the SQL Results view. And at last, we saw how to import and export data in raw text to the JDBC database. So thank you for watching this module. I hope you found it interesting. And I hope we will meet again in the next and last module of this Eclipse for Java Developers course. You are going to see how to handle full Java EE applications and launch them in a Tomcat application server.
Setting up a Java EE Project in Eclipse with Tomcat
Module Introduction and Agenda

Hello, my name is Jose. I am very happy to welcome you back to this Eclipse for Java Developers course and to the last module of this course that will cover Java EE projects in Eclipse connected with the Tomcat application server. What are you going to learn in this module? Well, you will begin by a quick overview of the structure of a Java EE application. This module is not a module about Java EE, but about creating and deploying Java EE applications using Eclipse. You will see how to connect Eclipse to a Tomcat instance and by doing so, you will also learn how to connect Eclipse to any Java EE application server and how to create a Java EE project within Eclipse using Maven and the standard Eclipse plugins for Java EE. You will then see how to run this project within Tomcat and how to debug it and how to use Maven to package the web application and distribute it to any Java EE application server.
Introducing How Eclipse and Java EE Applications Work Together

Let us take a quick overview of what a Java EE application is and what is it made of. So what is a Java EE application? Typically, a Java EE application can be seen as a web application, more or less sophisticated. It has a set of Java classes, servlets, web services, REST services, some static resources. Think about HTML pages, CSS files, JPEG images, audio files, video files. It has some dynamic pages. Think about JavaServer pages or JSF pages. It has some JavaScript files and some metadata in XML descriptors and sometimes even more elements like these ones that are not cited here. So a Java EE application is quite a complex object made of many things, many elements. We will see a very simple Java EE application in this module. By the way, if you are not familiar with what a Java EE application is, you may check the Java EE keyword here on Pluralsight, and it will give you several courses returned by many people on many aspects of Java EE. The good news is that Eclipse fully supports all that, including servlets, web services, REST services, etc. It can create special Java EE projects connected to application servers and can support those Java EE projects through the use of Maven, and this is what we are going to see.
Understanding How to Run a Java EE Application

Remember that Java EE applications are not standalone. What does it mean? When we saw Java SE examples, we wrote a main method and asked Eclipse to execute this main method. A Java EE application is not run like that. It runs in an application server. So it means that in a Java EE application, I do not have a main method. The main method is, in fact, in the application server. I do not see it as a developer. There are lots of application servers around. Think about Tomcat by the Apache Foundation, Glassfish developed by Oracle, JBoss developed by Red Hat, WebLogic, also developed by Oracle, WebScarab by IBM, and many others. So to be able to run the application we are working on, Eclipse needs to connect to one of these servers and use it as a runner.
Connecting an Eclipse Workspace to a Java EE Application Server

So the first step is to connect Eclipse to an application server. And the application server we are going to use as an example is the Tomcat application server. Eclipse needs a plugin for each application server around and sometimes a different plugin for each version of such an application server. Now the good news is that Eclipse for Java EE developments comes with already installed plugins, so we will not have to download those. If this is the case, if you are using a special application server not supported by default by Eclipse, then you need to go to the Marketplace and download the right plugin. Once this is done, a connection to an existing server instance to an existing server installation must be established. Let us see the big picture of the Eclipse and the application server organization. As you remember, Eclipse works with a special folder called a workspace in which all our project folders are going to be stored. In that folder, there is a special. metadata hidden folder in which the different connections to the well-known application servers is stored. And once this is done, each project can be connected to a given instance of an application server. So the organization is exactly the same as the JDBC organization we saw in the previous module.
Demo: Connecting Eclipse to an Existing Tomcat Installation

So let us see all that in action. Let us create, deploy, and run a web application. We are going to use the Tomcat application server. Of course, other application servers might differ, but not too much. Most of the time, the configuration in Eclipse will work the same as Tomcat. So we are back in our Eclipse workspace, and note that we are now in the Java EE perspective, not in the Java SE perspective anymore as we can see on the top right of this window. The first thing we want to make sure is that we have the right plugin to connect to the Tomcat application server. It takes place in the Window menu, Preferences. And let us filter this with the Server keyword. Here we have the Server node with three suboptions. And what we want to check is the Runtime Environments. Here we do not have any runtime environment configured. Let us add one. And from this panel, we can see all the default application servers readily available in this distribution of Eclipse. So we have a nice set of Tomcat versions, Geronimo, Basic, Java EE runtime servers, those are very old, Cloud Foundry, IBM with Bluemix and WebSphere Application Server, ObjectWeb with the JOnAS application server, which is not supported anymore, Oracle with GlassFish Tools, Oracle Cloud Tools, and WebLogic Server Tools, JBoss and WildFly from Red Hat, Resin, and SAP. We are going to use Tomcat 9, so we select this one. Click Next. And here Eclipse is asking us to point to a Tomcat installation directory. So I have prepared here a Tomcat directory with the default installation of Tomcat. Let us copy/paste this path directly to here. Select and Install the JRE. We already have a default Java 8 JDK installed, so let us click Apply and Close. Select JDK 8 here, and we are done. We can now click Finish. In the Server Runtime Environments, we have now reference to the Apache Tomcat version 9 application server. By the way, if you need to install a Tomcat version, you can just download it from the tomcat. apache. org URL. Here you just have to click on the Tomcat 9 download and download, for instance, the tar. gz distribution just here. This is the distribution I am using in this module. Once you have downloaded this archive, all you want to do is unzip it in any directory and declare that directory within Eclipse.
Demo: Creating and Configuring a First Web Application

Let us now create a first Java EE project. For that we are going to use the pop-up menu of this Project Explorer view of the Java EE Eclipse perspective. New, Project. Let us open up this one. We have one node that looks interesting, which is the Java EE node here. But in fact, we're not going to use the project in it. We are merely going to use the Web node there and the Dynamic Web Project. If you want to create a web app, this is the type of project you want to select. Let us click Next. The name of the project will be first-webapp. We'll keep the Target runtime as Apache Tomcat version 9. This is fine. If you have other runtime declared at the Eclipse level, then they will be made available here from this drop-down menu. The Dynamic web module version is 3. 1, which is fine. If you want to downgrade this version, you can do so with this drop-down menu. And the default configuration is also fine. We can now click Finish, and the first webapp project is being created. Let us open it. You can see that this project is a little more complicated than a plain Java SE project. We have a several nodes. The first one is the configuration of the web application with all the elements you can create in it. The second one is for the web services and the REST services deployed with the service endpoint interfaces and the web services themselves. We have then the Java Resources with the src folder in which the Java code we are going to write will be stored and the Libraries node with the JDK and the Apache Tomcat v9 library. Then if you have JavaScript Resources, they will be declared here. The build node is to store the compiled files of this web application, and the WebContent will hold the HTML pages, JSP, JSF files, images, audio, etc. This is the first way of creating a web application. And what we can do is check the Properties here of this project, select Project Facets here, and check the facets that have been selected for this project. We can see the Dynamic Web Module 3. 1, Java 1. 8, and JavaScript 1. 0. On this button here, we can see that the runtime selected is the Apache Tomcat v9.
Demo: Creating and Configuring a Web Application Using Maven

Let us now create a second project using the Maven plugin for Eclipse. Once again, let us open the pop-up menu of this Project Explorer view. New, Project. Select Maven. This is a Maven project. Next. We are going to skip the archetype selection. Click Next. Let us take org. paumard as the Group Id, maven-webapp as the Artifact Id, 0. 1 for the Version. And for the Packaging, we are not going to select jar this time, but war, which stands for web archive and which is the standard Maven packaging for web applications. Let us click Finish. The project is being created, and we can see that there is an error in it. When we open it, there is an error in the POM file. Let us open this POM file. Let us do some cleanup in it. Let us copy/paste the default properties that we saw in the Maven module of this course. And let us update this Maven project, maven-webapp, to make sure that the libraries are the Java 8 libraries and not the Java 5 libraries. Now this error is still there. Let us check the error message. Maven is, in fact, complaining because it needs a failOnMissingWebXml property that has to be set to true. So let us do that, failOnMissingWebXml. Let us put false for this property, and now Maven should be happy. Why do we have to put this? Because in previous versions of Java EE, this web XML metadata file was mandatory, and it has been made optional in an old version. But Maven still supports this old format, so we need to tell Maven that if this web XML is not there, it's still okay. Now let us check the properties of this project and the project facets of this project especially. And let us go directly to the runtime environment, and you can see that creating a Java EE project using the Maven plugin does not configure the runtime automatically. You have to do that by hand. So let us click here, Apache Tomcat v9. Java is set to 8, which is fine. The Dynamic Web Module is set to 2. 5, and we want 3. 1. Apply, Apply and Close. And now we have a proper Java EE web application project created with Maven.
Demo: Launching and Browsing a First Simple Web Application

Since this is a web application, let us create a first very simple HTML page. We can do that with the pop-up menu of the project, New, HTML file. This HTML file has to be stored in a very special directory of this project, and the Maven plugin knows that it is going to put it in the src/main/webapp folder, which is exactly what we need. Let us call this file index. html. Next. Let us make it an HTML 5 file. This is fine. We have this file created here. It is in the src/main/webapp folder. This is our Welcome Page. Let us put some message, Welcome to our new webapp. Now we have some basic content in our webapp, and what we would like to do is run it. In fact, it's quite simple to do that. All we need to do is select the project, pop-up menu on the project level, Run As, and select Run on Server. Do not select Java Application because we do not have any main method in this project, so the plugin will be confused. It is going to ask us which server do you want to run this application on? Of course, it is the Apache Tomcat Server that we just installed. We can select the Server runtime environment here. If we add others, they would appear here in this drop-down menu. And if we click Next, we are presented with the configuration of the instance of Tomcat that is going to run. Here all we want to do is run the maven-webapp application. Let us click Finish. It quickly opens the Servers view at the bottom of the screen with a node representing the Tomcat Server that is running. If we open this node, we see that our maven-webapp project has been deployed in this Tomcat Server and a welcome page that is displayed in the internal browser of Eclipse. We can copy/paste this URL and open it in a Chrome browser, for instance, for the exact same result.
Demo: Configuring the Manual Deployment of a Web Application

So in fact, behind the curtain many things happened here. An instance of Tomcat has been configured and launched and added to the Servers view. Our web application has been deployed in this Tomcat web server, and a browser has been launched in Eclipse. Let us make a modification to our page, This is our welcome page. You can see that quickly our web application transited from the state synchronized, republish, and synchronized again. If we refresh this page, the new message is appearing. So automatically when a modification is made in the web application, this web application will be reloaded in Tomcat. Here we have a very simple web application with just a single HTML page, so reloading it in Tomcat is very fast. If we have a bigger web application with many classes, many services, this reloading might take a few seconds. Reloading automatically on a modification may not be what you want. To configure that, all you have to do is double-click on this Tomcat web server here. It opens the overview configuration of the web server. And here in Publishing, you just need to click this button, Never publish automatically. You can save this configuration by pressing Ctrl+S. And now let us modify this message, nice welcome page. You see that the server and the web application stays in the Republish state. And to trigger the publication, you need to click this button here, Publish to the server. Let us do that. The server is now synchronized with our web application. Reloading the page here will show the new state of our HTML page.
Demo: Creating and Deploying a First Java Server Page

Let us add some dynamic content to our web application. New, JSP File for instance. Let us call it index. jsp. Next, HTML markup. This is fine. Finish. This is Dynamic page, h1 Welcome to our first JSP! And as a text, we're going to put some real dynamic content. It is and here a nice scriptlet Date. And if I Ctrl+Space this Date object, I have the automatic autocompletion. And by selecting java. util. Date, it will add the import of java. util. Date automatically for me in this Java server page. Let us close our paragraph. Our web application is in Republish state, which is expected. Let us publish it to the server. Go back to the welcome page. Browse the index. jsp page that we just created. And we can see that we are Wednesday, February 21, and this is 15:45. And if I refresh this page, I can see that the seconds, that the date is changing, which is expected. This is a dynamic resource that is recalculated on its request.
Demo: Creating a Servlet That Passes Content to a JSP

Let us now go one step further and create a servlet connected to a JavaServer page. I just created a User class in this project. We can have a quick look at it. It is just a plain JavaBean with two properties, name and age, respectively, String and integer. Let us create a servlet in this project. We can do that with the pop- up menu of the project or with this icon on the task bar. We are going to put it in the org. paumard. webapp package and call it UserListServlet. Next. We are going to bind it to the URL user-list. OK. All the rest is fine. Let us click Finish. Let us simplify a little of this. Eclipse is able to create the skeleton of a servlet. This doPost method is fine, and we're going to change the doGet method. Suppose this servlet is making a query on a database. We are not going to connect it to a real database, but we are just going to create a list of users, let me copy/paste it real quick, and put those users in the list, Arrays. asList (mary, james, patricia, and john). Let us put that in the list called users. We are going to bound this list to the request, request. setAttribute userList, users, and forward the request on a JSP. That's what we're going to create, request. getRequestDispatcher to the users-list. jsp and call the forward method with the request and the response. So basically, this servlet is faking a request on a database, creates a list of users, and passes this list of users using the request to a JSP.
Demo: Creating and Testing a JSP Using JSTL

In order for this to work, we need to add two dependencies to the pom. xml of our Maven descriptor. The first one is a Java EE dependency from the javax package. Here it is. And the one we need is the javaee-web-API since we are only using the web profile of Java EE. And the second dependency we want to add is the jstl, Java Server Tag Library, which is either this one 1. 2 or even the javax. servlet one. Do not choose the jstl-api because this is not the one we want to use. OK. Once we've done that, we can create our JSP file, users-list. jsp. Let us click Finish. Let us check that this users-list. jsp is indeed the file to which we are forwarding the request, which is the case. We are going to add first a taglib here, taglib. The prefix is the standard one, c, and the URI is http://java. sun. com/jsp/jstl/core. If you make a mistake in typing this URI, for instance if you forget the e, you will have an error message from the JSP plugin of Eclipse, telling you that this URI is not recognized. So this is our Users list, h2 Users lists is the following. We are going to use the forEach tag from the standard tag libraries. Let us take a user as a var, and items will be requestScope. userList. And for each user, we are going just to display the user. name : user. age. Our JSP is now correct. If we want to run our project, we can also drag and drop it on the Tomcat node from the Servers view. Launch Tomcat by clicking on this button. The console should tell us that everything is fine. Then go back to our Chrome application, make your request on user-list, and here we have the list of the users that has been sent by the servlet. We can just check that this is correct. Let us go back to the servlet. Modify the ages for instance, 22 here. When you modify a servlet, Tomcat has to be restarted. Republishing the webapp is not enough, so let us do that. Restart the server by clicking this button. This is done. Go back to Chrome, Refresh, and indeed the ages have been updated.
Demo: Running a Web Application in Debug Mode

Suppose now that we have some debug to do in the code of this servlet or in any other Java code of our application. Using this interface, we can also start Tomcat in Debug mode. Let us do that. Let us stop the running Tomcat. Go back to the Servers view and launch it, but this time in Debug mode instead of Run mode. Let us click here. Now Tomcat is running. And instead of running in a normal mode, it is running in Debug mode as is stated here. We can put a breakpoint in a servlet, launch this request once again. Eclipse is asking if we want to switch to the Debug perspective. Let us click Yes. And from now on, we are debugging inside the code of our servlet. Let us click F6 to step one line here by hovering the variable, we have the content of the variable. We can check the list of users. Let us enlarge this window a little. Check the different users one by one if you wish and then run the code again by clicking the Resume button here. By the way, all the buttons for the Debug mode to control the way the application is running are here on the taskbar. So this little trick enables you to debug your application using Eclipse.
Demo: Packaging a Web Application Using Maven

Now that our web application is running and free tested, what we can do is package it as a WAR file using Maven. We already saw how to package an application in a Maven module of this course, so let us do it for this webapp application. Let us create a Maven run configuration by clicking this button here, selecting a Maven Build here. Let us create a new launch configuration. This configuration will be called Webapp package, for instance. The root directory is our maven-webapp. The goal is war:war, and that's it. Let us run this goal. You see on the console that the WAR plugin has been invoked automatically, and maven-webapp-0. 1. war file has been created in the target directory of our Eclipse project. Let us reduce this console. Check the target directory here. Open this WAR file with the system editor, which is, in this case, WinRAR, and we can see that the content of this WAR file is indeed the content of a webapp. We have our HTML and JSP file. And in the WEB-INF directory, our classes of org. paumard, model with the User. class, our servlet UserListServlet. class. Let us go back. And in the lib directory, the javaee-web-api-7. 0. jar and the jstl-1. 2. jar. By the way, this javaee-web-api should not be here, so we are going to tell Maven to remove it. Here we need to add the scope provided. We forgot that. Let us run this packaging application once again, Webapp package. Check this WAR file once again. And now in the lib directory, the javaee file is not present anymore.
Demo: Launching Tomcat as a Remote Application Server

So we just saw how to develop and deploy a web application with Eclipse in a local Tomcat installation, and most of the time this is how you are going to work in a real production environment. But there are still situations where you need to debug a web application from a remote Tomcat installation, not necessarily a production environment. It can also be some kind of testing environment. And for that, you need to declare this remote installation of Tomcat in Eclipse. So this is what we are going to see now, how to connect to this remote Tomcat instance and debug our web application in this remote installation. For that, we are going to launch an instance of Tomcat independently of Eclipse. We have a Tomcat installed in this directory. It is a local Tomcat, but we are going to connect to it just in the same way as you would do it for a remote Tomcat. There are several ways to launch Tomcat. You have scripts in the bin directory. And one of the scripts is the catalina script, and you need to pass start as an option to it. It will open another window and launch Tomcat here in almost half a second. Now we have a running Tomcat instance on this local machine, and we can connect to it using any browser. For instance, I have here a Chrome browser, and connecting to localhost:8080 will show this welcome page with different links to various pages of documentation. We are interested in the Manager App of this page. Click the button here. And by default, it will ask for a password because this application is password protected. If we try to connect with a default installation, it will not work. And if we click Cancel, it will show this page, telling you that you need to add the two following lines to a special file, tomcat-users. xml installed in the conf directory of the Tomcat installation. So let us do that. Let us copy those two lines. Navigate to the root directory of our Tomcat installation. Go to the conf subdirectory and edit this file in Notepad++. Navigate a little and just copy/paste those two lines here. Save this file. Now we need to restart Tomcat, so let us do that. Catalina stop and then catalina start once again. Go back to our browser. Refresh this page. Type in tomcat and the password, secret with a 3 instead of the first e. Connect. And now we are connected to the Application Manager of Tomcat. With the default applications already deployed, docs, examples, host-manager, and manager. Now probably if you have a real production Tomcat, you will not see those applications because most of the time people do not let those applications in a Tomcat installation.
Demo: Deploying a Web Application in a Remote Tomcat Instance

Now what we need to do is to package our web application and use this interface, this web interface, to deploy it by hand. So let us go back to Eclipse. Check our Run Configuration called Webapp package. Maybe what we can do is add the package goal between the clean and the war to make sure that everything is compiled properly to package our WAR file. Apply, Run. As usual, the Maven goal has been run, and the maven- webapp-0. 1. war has been created and added to the target subdirectory. So let us just copy all this. Reduce this console. Go back in our web application and deploy this WAR file by clicking this button here. Our WAR file is just this one. Let us open it, Deploy. After a few seconds, we have successfully deployed our web application in Tomcat. Let us Ctrl+click this in a new tab. This is the welcome page of our web application. And if I type in user-list, you will see our list of users. This is great, so we have deployed our web application manually in a Tomcat remote server. Now what we need to do is to connect Eclipse in Debug mode to this server.
Demo: Connecting Eclipse to a Remote Tomcat in Debug Mode

Tomcat is a Java application, and in fact there is a special mechanism at the Java virtual machine level that allows to open a port, a special debug port, that Eclipse is able to connect to. So let us do that. Let us go back to our command line tool. Let us stop our Tomcat, catalina stop. And let us run it again with the option jpda start. This option means Java platform debugger architecture. In fact, it triggers special options at the JVM level that are fully documented on this page with the following link. So if you want to have more information, you should refer to this page, which contains the full documentation of this technique. Now this Tomcat is launched in Debug mode, so Eclipse is going to be able to connect to this instance of Tomcat to get some debug information. To do that, we need to create a debug configuration from here, so Debug Configuration, that is made precisely for debugging. You want to select Remote Java Application here. Create a new launch configuration. Let us call it Webapp Tomcat Debug. Select the project, which is our maven-webapp. And in fact, all the other options selected by default on this pane are correct. They are the one we are going to use. And let us add this debug configuration to the Favorites menu of the Debug menu. So let us Apply, Close. Switch to the Debug perspective of Eclipse. Click on this Debug button from the toolbar and select Webapp Tomcat Debug and see what is happening now. The Debug view is connections to the instance of Tomcat we just launched, and we have now the list of the threads that Tomcat has been launching on our machine. So we are now ready to connect to our web application in Debug mode.
Demo: Debugging a Web Application Deployed in a Remote Tomcat

Let us open the source code of our user-list servlet. Add a breakpoint on the first line here. There are several ways to do that. We can use the pop-up menu in this blue margin here, and then we have Toggle Breakpoint there. Or easier, we can just use the shortcut Ctrl+Shift+B like that. This little blue bullet here shows us that we have a breakpoint on this line. And now what we can do is run our web application. There is no main method in a web application, so you cannot run it like that. Of course you need a browser to launch a request that will execute the code of this servlet. So let us switch to our browser, and let us refresh this Users list page by pressing F5. And you can see in Eclipse this green bar showing that our application is blocked on this line, precisely where we put our breakpoint. If we switch back to our browser, we will see that Chrome is waiting for information from the server, and this is expected because our Tomcat Server is currently blocked by the debugger, so it is not able to send any HTML information to this browser. Let us switch back to Eclipse. F6 to advanced one line up to here. We can have information on the mary variable, for instance. This is a user, age 32. We can do the same on James and Patricia. If we do the same on John, it does not work. Why? Just because this line has not been executed yet, and this variable has not been created yet. Let us continue to run this web application by pressing F8. Now we are not in Debug mode anymore. No Tomcat thread is blocked. So let us switch back to our server, and now we can see that the page is properly displayed in this browser. So this is basically how you can connect to a remote Tomcat. It is built on a special Java protocol build on TCP/IP. So you need to provide an IP address and a port to connect to it, and you need to launch this Tomcat using the special option, JPDA. By the way, if you want finer control on this Tomcat mode, you can also check the documentation from within the catalina. bat batch file. Let us scroll a little, and you will see that here you have several options, JPDA_TRANSPORT, ADDRESS, SUSPEND, and OPTS to finely tune the way you want to debug your Tomcat. So this is how you can debug an application from Eclipse in a remote Tomcat installation.
Module Wrap Up

And with this, I think we are done with this module. Let us quickly wrap it up. What did you learn in this last module? Well, you learned how to configure Eclipse to work with Tomcat and to interact with Tomcat. We created a basic Java EE project and a Maven Java EE project, which is most of the time what you will be doing if you're working in a real production environment. And we configured Eclipse to launch this project using Tomcat, to start and stop Tomcat, and to launch it in Debug mode. We saw how to use the Eclipse graphical user interface to create some of the elements of a web application. We saw the servlet, the HTML file, and the JavaServer Page file. It's basically the same for web services and REST services. You saw how to launch Tomcat and how to debug it, and you saw that in two configurations, a development configuration with a local Tomcat installed and the possibility to debug your web application in a remote Tomcat using the debug features of the JVM. And at last, we saw how to package the WAR file to deploy a web application, using the WAR plugin of Maven. And since this is the last module of this course, it is also time to wrap this course up. What did you learn in it? Well, we covered quite a lot of ground in fact. This course was all about Eclipse for Java developers. You saw the most useful tasks you have to master as a Java developer using Eclipse. Configure a Java project, choose the right JDK and change it if you need it, create a project with Maven. Maven is really a de facto standard nowadays in the Java space, so learning how to use Maven through your IDE is really a must. Use Git for source control management. Git is also a de facto standard in the Java space, so we saw that, how to use Git through the Eclipse graphical interface, including interacting with GitHub, interacting with databases without having to launch external tools to do that. Very useful. And at last, create, debug, and package web applications using both the Java EE plugin of Eclipse and the Java EE Maven plugin that we have in Eclipse. That's it for this course. I hope you found it interesting. You can follow me on Twitter for up- to-date technical information on the Java space. And you can also check my open source projects on my GitHub account, including many Java things. Thank you for watching this course. I really hope you enjoyed it, and I hope we will meet again on another course here, on Pluralsight.
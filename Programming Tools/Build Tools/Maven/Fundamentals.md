# Introduction to Maven

## High Level Overview

Maven is a build tool.
Maven always produces one output that is called an artifact, a component  JAR, ZIP file, etc...

Maven helps up manage our dependencies.
Dependency management is probably the number one reason that people get into using Maven

At a macro level, Maven can be used as a project management tool

It will also help us describe things like what our source control module is or where our documentation is stored, who the developers are. It has some meta information also tied to what your project is.

The other nice benefit of using Maven for builds is that, as mentioned earlier, it can produce extra information. You can produce the Javadocs, the source code, and JAR file with all of the extra information your IDE will use.

Maven is managed by the Apache Software Foundation as an Open Source Project.
<br/><br/><br/>

## Why do we want to use Maven?

### Repeatable Builds
It's the ability for us to be able to recreate our build for any environment, as well as to not have to change our settings for each environment. So, Maven lets us externalize a lot of our settings to where we can now develop on Windows, test on a Linux box, and deploy to a different flavor of Linux or UNIX in production. We can also utilize tools like Docker to help us do this inside of our application. We have all of our properties externalized to where our code isn't dependent on the environment that it's being built in.

### Transitive Dependencies
Downloading a dependency will also pull other items it needs in. With Maven, you can tell it that you want to use a tool and it will download that tool and all of the transitive dependencies as well.  This is the number one reason without a doubt that people start using Maven.

contains everything you need for your environment. So whether I'm building in my IDE, building from the command line, it contains all the information I need to build our code and reproduce our code.

### A Local Repo
Historically, downloaded JARs or other resources are inside each project
With multiple projects, we could possibly have the same JAR downloaded for each one. A Maven local repo, is a local structure that enables us to download resources once and then have projects reference needed resources from that singular location.

### IDE Compatibility
Maven works very well with your IDE. It doesn't matter if your IDE is NetBeans, IntelliJ, or Eclipse, and you can also use it standalone.
The same functions that we can call from the command line can also be called by an IDE. It doesn't have a different path for the different environment. You've set up your Java environment variables, and it's all derived from your Maven files.

### Build Tool Integration
Maven is the preferred choice for working with build tools like Jenkins or CruiseControl, Hudson, Bamboo, any of the various automated build tools that are out there for doing continuous integration. Maven is without a doubt the first-class resident that they want you to use for that type of stuff. It works with all of those tools. And there is also a lot of additional plugins that you can use that are also integrated with those continuous integration tools.


## Installation Best Practices

https://maven.apache.org/download.cgi
Download the .ZIP file
open up File Explorer
A personal preference is to create a folder structure of C:\\dev\\tools, expanding the JDK, IDE, Maven, any other tools there.

extract the ZIP file so that when you click on the apache-maven-X.X folder, it holds the bin, boot, conf, and lib directories.

The  is where we're going to now point our environment variables
To edit our system environment variables.
Windows key Search "Advanced System Settings"
Advanced Tab > "Environment Variables"

Environment Variables panel
System Variables region > "New…"  > name JAVA_HOME > Browse Directory > select the JDK
System Variables region > "New…" > name MAVEN_HOME > Browse Directory > find apache-maven-X.X.X instance
System Variables region > "Path" > "Edit..."
"New" > %JAVA_HOME%\\bin > New > %MAVEN_HOME%\\bin
"Move Up" to the first and second locations in path



## Demo: Hello World

Eclipse > File > New > Project > General > Project > name "HelloWorld" > Finish
right-click on our project file tree > New > File > name "pom.xml" > Finish

In the empty pom.xml file, start adding five elements

<project>
  <groupId>org.example</groupId>        //For organization example
  <artifactId>HelloWorld</artifactId>   //Project name
  <version>1.0-SNAPSHOT</version>
  <modelVersion>4.0.0</modelVersion>    //This has always been 4.0.0
  <packaging>jar</packaging>
</project>


Create 3 folders with hierarchy src/main/java
The directory structure that Maven is looking for in regards to our class files.
right-click src/main/java        New > File > named "HelloWorld.java"


ignore the working set error/warning and create and save a simple Hello World
public class HelloWorld{

    public static void main(String args[]) {
        System.out.println("Hello World");
    }
}

command line cd to eclipse-workspace/HelloWorld > run mvn clean
The first time you run this, it's going to go out and download a bunch of plugins and dependencies from the Maven repo.
clean initializes your directory structure and deletes any previously generated files.

mvn compile
compiles our source code for us also downloading more dependencies and other plugins

We ran our build, but you'll notice we got an error

as of Java 10+, Java 5 was no longer supported, and the default compile version before was Java 5, so now it's forcing you to use 7 or later because there's no longer support for 5.
To use Java 10 or later in your IDE, or just for general development, we have to add a POM build section and a plugin.

Inside of our POM after <packaging>, but before the closing </project> tag, and this section:

<build>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <version>3.8.0</version>
                <configuration>
                    <release>11</release>
                </configuration>
            </plugin>
        </plugins>
    </build>

Java 11 is the most recent LTS long term support release
The biggest thing I see people make a mistake doing here is they add the plugins section, but don't add the plugin element after that.

mvn compile > cd target/classes
we'll have our HelloWorld.class here and we can run it to print out HelloWorld to the command line
java HelloWorld

We can also do the same thing and run package at that project level as well, and it will now generate our artifact for us too.
mvn package > cd target > dir > see the HelloWorld.JAR file already produced for us.
remember this was the packaging type inside of our POM, JAR, it will go ahead and create that for us. So we can go into cd target and do a dir here, and you'll see there is our artifactId of HelloWorld, our version of 1.0 -SNAPSHOT, our packaging type of .jar, all specified in our file.

## Structure

### Folder Structure

By default, Maven looks for [project_name]/src/main/java directory.
It compiles all of our code to a [project_name]/target directory
it does this by referencing our defaults and whatever things we've overwritten in our pom.xml file.

#### src/main/java

Our src/main/java directory is where we store all of our Java code

In our previous example we were just using the default package, so it stores it right underneath src/main/java, but a package would build folder structure underneath this directory.

For testing use a src/test/java directory  for two reasons.
You can keep test code separate from production code, but we can have them reference the same package structure.

put all of your test code under src/test/java and all of your source code under src/main/java.
One thing that's worth mentioning is that src/test/java directory is specifically for unit tests.

#### target

The target directory is where everything gets compiled to and where all of your tests get ran from.
when you run a goal like package, mvn package, target's contents get packaged into a JAR and WAR.

classes directory, contains classes from src/main/java
maven-archiver directory, holds what we're referring to for our packages,
test-classes directory, and that's how our code gets unit tested.
the artifact HelloWorld-1.0-SNAPSHOT.jar is here



Basic POM
The basic POM file uses convention over configuration.
it doesn't say anything about package or directory structure because we are assuming defaults

### Project Information
Four basic project information sections:
* groupId is often the same as our package. Packages like com.acme or com.Pluralsight, such as our example here, are commonly what you would use for your groupId. They designate your business name or your application name as you would reference it as a web address.
* artifactId is the name of our application, and what our artifact will be named.
* version is very simply what we want to call it, so 1.0, 2.0, 3.0, or if it's a maintenance release, something like 1.0 .1. etc...
* packaging is how we want to distribute our application. Is it a JAR, is it a WAR, a RAR or an EAR file. These are just some of the common file types associated with Java applications. We could use the default packaging, which is a JAR, and not specify it inside of our application

### POM Dependencies
Dependencies are imported by their naming convention. This is often considered the most confusing part of Maven because you have to know what their artifactId is, what their groupId is, and what version you want to use.

Let's look at what this code looks like for us to achieve this.
Within <dependencies></dependencies> tags list individual <dependency></dependency> elements which each contain <groupId> <artifactId> <version> elements

Example

## Goals

The goals that we can run off of our basic application are pretty straightforward.
Since we're using a lot of the defaults, they're already defined for us.

#### mvn clean
The clean goal deletes the target directory and any of its generated sources.

#### mvn compile
compile all of the source code, generate any files if we're using a library such as web services or something like that that would generate stubs and skeletons or other source code, and it will place that into our classes directory. If you have a .properties file or things like that, they're going to get copied over into our classes directory underneath our target as well.

#### mvn package
The package command will run compile first so we don't have to tell it to run compile, but we can daisy chain goals. It will run any unit tests that we have and package that up based off the type that we have defined inside of our POM.

#### mvn install
The install goal is a little bit different than what some people think. Install will run the package command and then it will install it in your local repository. It will copy your JAR or WAR file, or however it's packaged, and place it inside of your repository. The default of that is your home directory, .m2.

#### mvn deploy
Deploy does not mean deploy it to an app server. Deploy runs the install command and then deploys it to a corporate or remote repository. If you're using a corporate internal repository, deploy is going to copy it up to that internal repository.
install and deploy often get confused and backwards. As far as you're concerned, install will install it locally, deploy will install it remotely.


## Demo: Goals
right-click project in Project Explorer > Configure > Maven project.
It will download a few things for a second and set up the structure of our project

open pom.xml, notice we don't have a dependencies section.
between the packaging and build sections add
   <dependencies>
        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-lang3</artifactId>
            <version>3.8.1</version>
        </dependency>
    </dependencies>

Save and you're going to see a couple of things maybe flash on the screen. What happens is it will go through and it's building my workspace and downloading some dependencies.
we now have a Maven Dependencies source folder with commons-lang3 added to our class path.
cd to project root
mvn clean > mvn compile > mvn install.
this will download all the dependencies that it needs, package up the application, and then install it in our local repository. Example: C:\\Users\\Name\\.m2\\repository\\com\\example\\HelloWorld\\1.0-SNAPSHOT\\HelloWorld-1.0-SNAPSHOT.jar

this is everything that we had specified for our project structure.
* groupId of com.example
* artifact of HelloWorld
* version of 1.0.SNAPSHOT
and that's exactly where it installed it to our local repository
So we have all of our application ran through that configuration and installed based off those POM properties.

## Defaults

The build section is where we override things of a specific nature.

## Local Repo Structure

Once we've ran the compile command or any command that is preceded by the compile command, it will download all of your dependencies to your local storage.
Our local storage is by default in our home directory under the hidden directory of m2.
Maven stores artifacts based off groupId/artifactId/version.
This structure helps us avoid duplication.
We don't need to copy these JARs into every application we have. They can all be referenced from this location.
We also don't bloat our Git or Bitbucket, or whatever SCM we're using to store our application. There's no reason to keep storing these JAR files repetitively in there for each application. We can access them from one central repository.

## Demo: The Build Section

To override the default naming convention of our application
Open pom.xml >  in the <build> section > add <finalName>example</finalName> as the first element

cd to project root > mvn package
it will build our application and the final artifact will be named foo.jar

If we erase <finalName> and run mvn package to build with our default jar name we must run
mvn clean > mvn package


## Dependencies

### Dependency Overview

Dependencies are simply other resources that we want to use inside of our application.
Maven will pull in transitive dependencies based off the dependencies we list.
To use a dependency, we create
a <dependency> element
input the associated <groupId> <artifactId> and <version>

then list them in our POM and Maven will automatically download it for us and pull in the transitive dependencies.

Versions
Versions are the release number of the artifact that we want to use.

SNAPSHOT
SNAPSHOT has to be labeled specifically that in all capital letters.

All of your internal development should start off as a snapshot.
SNAPSHOT allows us to push new code to a repository or a development team every time we compile

You should also be aware of using snapshots from other third-party libraries if you want the latest code. pull it down as a snapshot and every time we go to compile, it will look to see if there's new code that it should pull down and use.

Besides SNAPSHOT releases, everything else of a naming convention is left up to the end user.



### Dependency Scopes

Dependency scopes can help to limit transitivity of the dependencies and they modify classpath for different built tasks. Maven has 6 default dependency scopes used as such:
<dependency>
    <groupId>commons-lang</groupId>
    <artifactId>commons-lang</artifactId>
    <version>2.6</version>
    <scope>compile</scope>
</dependency>

#### Compile    <scope>compile</scope>
This is the default scope when no other scope is provided.
Dependencies with this scope are available on the classpath of the project in all build tasks and they're propagated to the dependent projects.

#### Provided    <scope>provided</scope>
This scope is used to mark dependencies that should be provided at runtime by JDK or a container.
The provided dependencies are available only at compile-time and in the test classpath of the project; what's more, they aren't transitive. A good use case for this scope would be a web application deployed in some container, where the container already provides some libraries itself.

#### Runtime    <scope>runtime</scope>
The dependencies with this scope are required at runtime, but they're not needed for compilation of the project code. Because of that, dependencies marked with the runtime scope will be present in runtime and test classpath, but they will be missing from compile classpath.

#### Test        <scope>test</scope>
This scope is used to indicate that dependency isn't required at standard runtime of the application, but is used only for test purposes. Test dependencies aren't transitive and are only present for test and execution classpaths. The standard use case for this scope is adding test library like JUnit to our application.

#### System        <scope>system</scope>
System scope is much similar to the provided scope. The main difference between those two scopes is that system requires us to directly point to specific jar on the system. These dependencies may fail on different machines if dependencies aren't present or are located in a different place than the systemPath element points to, included under the <scope> element:
    <systemPath>${project.basedir}/libs/custom-dependency-1.3.2.jar</systemPath>


#### Import        <scope>import</scope>
This scope was added in Maven 2.0.9 and it's only available for the dependency type pom. Import indicates that this dependency should be replaced with all effective dependencies declared in it's POM.
This is an advanced topic. It deals with dependency management, which is something we're not going to cover in this course. Dependency management deals with sharing resources across multiple POMs, and it's kind of an advanced topic that we're just not going to cover here.

Schema Warning

While developing there was a warning "No schema defined for this pom.xml
We can copy Maven's project schema namespace

<project xmlns="http://maven.apache.org/POM/4.0.0"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://maven.apache.org/POM/4.0.0
                                      http://maven.apache.org/xsd/maven-4.0.0.xsd">

It runs fine without it, but you should have this so that the IDE context-sensitive help works well

### Demo: Review of Concepts

Let's go ahead and dive into how we add some dependencies inside of our application

Notice the Dependencies tab at the bottom of the Eclipse code editor view
it'll show you what you have for dependencies inside of your application.
add a dependency to the pom.xml and the Dependencies tab automatically gets updated.
Any required Transitive Dependencies are also listed under the dependency that required them

This dependency hierarchy viewer really is pretty handy for you trying to troubleshoot which JAR is pulling which library in.


## Repositories

### What Is a Repository?

Maven looks in your local repo first.
It looks locally to find dependencies, if it doesn't, it will go out and download that from a remote repository.
When it downloads it, it will install it in your home directory /.m2/repository/<groupId>/<artifactId>


### Repositories

Repositories are very simply just an HTTP accessible location that we can download files from.

Our default location is defined in the Super pom.xml.
The Super POM is located inside of our Maven installation.

Generally, you don't need to go into it, the Super POM

The default location that it's pointing to is repo.maven.apache.org.

This has 95% of what you'll ever want to download


### Dependency Repository

A dependency repository is where we download all of our dependencies from.
It can contain releases or snapshots, or both for that matter, but it's not uncommon to have them in separate repositories. It's very easy for us to define our dependency repository. It's just a snippet of XML in the <repositories> section of our POM.



### Demo: Adding a Repository



HTTP sites for repositories are just that, they're very simple websites that a dependency with a snapshot will not build because most people don't upload their snapshots to the central Maven repo. And to add a repository, we can go ahead and just add a repositories element below our closing dependencies tag, but before our build tag, and add a single repository for snapshots and restrict it to just a snapshot release and no other final releases from that repository. Really simple to do, but a good way for you to go download code that's possibly under development by a library that you're using.


### Plugin Repository

Plugin repositories are almost identical to a dependency repository, they just deal with plugins.
Releases and Snapshots

Releases and snapshots can come from the same repository, as we had previously mentioned. Why would we not want projects to just upload everything to the central repo? Well, there's a release process not unlike deploying a mobile app to an app store, or something similar to that. It's a little bit difficult. We also want to make sure that we have everything final before we pushed it up there. Things like snapshots, milestones, release candidates, all of these are best not to deploy to the central repository just because it's a little bit more work and a little bit of a headache to do so. We'll often define a repository to handle just snapshots and host it off of our own corporate website. This was the case with the dependency repo that we looked at earlier from Spring. They don't want to put all of their snapshots up in repo.maven .apache .org. And here's that repository again where we just get snapshots from the corporate repository of Spring. Snapshots are enabled, but releases are disabled.


## Plugins

### Goals

Goals are actually just plugins configured in the Maven install.
things like clean, compile, test, package, the various install and deploy commands. Those are all basic goals that are defined inside the Super POM. The Super POM has these goals defined in it which are then added to your effective POM.

goals are always tied to a phase

### Phases

validate phase
validates the project structure and necessary information.
It has all the plugins that it needs, it has all the artifacts downloaded, all of our structure is in place. It has permissions to create these directories or do things like that.

compile phase.
where we compile our source code out. It should be of note though that this is not where testing code gets compiled

test phase
Testing tests the compiled source code and actually compiles our test source code and makes sure all of the resources are in line with our test package, so our src/test/java directory.

package phase.
The package phase packages all of our code in its defined <packaging>
It doesn't do anything with it once it is packaged, but it allows us to test to make sure that everything's in its proper order that it should be. A lot of people will tie generating resources or Javadocs or stuff like that to this phase, which we're going to talk about here in just a second.

integration-test phase.
This will allow us to deploy and run integration tests. A lot of people don't use this yet because it's still a newer phase to the Maven lifecycle.

verify phase.
This runs checks against our project to verify that it's good and meets all the requirements that it should before we install it in our local repository or we deploy it to a remote repository.


install phase
package it and put it in our local repo

deploy phase
will copy up to a remote repository.

The Compiler Plugin



The Compiler Plugin is exactly what it sounds like, it's the plugin that we use to compile both our source code and our test code, although it does run in different phases for each.

The Compiler Plugin
invokes javac
builds our classpath based off of our dependencies and their classification of scope.

it defaults to an older version of Java, Java 1.7, regardless of what JDK you have installed.

For this reason alone, the Compiler Plugin is the most overwritten plugin
We can customize this plugin by defining the <configuration> section.
In the configuration section we can specify a handful of things.
We can tell it that we want it to fork, which means to spin off on its own thread. We can set the min and max memory. So if you've ever run into compilation problems where you haven't had enough memory on the heap or whatever, you can specify those memory settings here inside your configuration. We also have our source and target directories, which is mainly the two features that people overwrite the most to tell it to use a different target than what we're compiling to.

Demo: Compiler Plugin

Inside of our <build> element, again, we have a <plugins> element, that houses <plugin> elements
<plugin> elements require <groupId> <artifactId> <version> and <configuration> elements

inside <configuration> we specify the <release>

Now I want to show you one small change for the sake of an example.
If we wanted to compile this down to Java 9, we make the <release> 9 </release> and save
The IDE will build our project, but it'll give us a warning or an error stating that the project space isn't up to date with the configuration.
We resolve that by right-click in Project Explorer > Maven > Update Project
It should go through, rebuild our application, and you'll notice that it has now configured our project to be a JavaSE-9 application.


The Jar Plugin

The JAR Plugin is used to package our code into a JAR file
usually tied to the package phase of our build lifecycle.
Now the configuration section will
allow us to change the includes and excludes.
build our manifest for us.

Demo: Jar Plugin

The JAR plugin is already configured by default as part of the packaging phase
to configure it we add that plugin to our POM <plugins> inside the <build> section
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-jar-plugin</artifactId>
    <version>3.1.2</version>
    <configuration>
        <include>**/*.xml14</include>
    </configuration>
 </plugin>

we're not overriding the <phase>, so we're going to leave that configuration out.
In <configuration> we forcefully include all XML files in all subdirectories.
The double asterisk says go through all the directories and look for anything named .xml on the end of that extension.

So, this is a basic configuration for the JAR Plugin, and you can run that inside of your application or we can go ahead and go to our command line and do mvn package


The Source Plugin

The Source Plugin can often be confusing to people because they think it's doing more than what it actually does for our application. All it does is package up our source code for us so that we can distribute it for context-sensitive help inside our IDE or to make some more code intensive Javadocs. It's by default also tied to the package phase, just like we saw with the JAR Plugin, and it's frequently even overridden to a later phase than that. If you're running package a lot and you don't want to sit there and wait for it, people will just tie it to the install phase or even the deploy phase just because it's slowing their build down.

Demo: Source Plugin

To configure the Source Plugin, we add that plugin to our POM <plugins> inside the <build> section
<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-source-plugin</artifactId>
    <version>3.1.0</version>
    <executions>
        <execution>
            <goals>
                <goal>jar<goal>
            </goals>
            <phase>install</phase>
    </executions>
 </plugin>

The executions section is where it gets interesting.
To tie this to a later phase we added a specific execution that's tied to the goal jar and the phase install.



The Javadoc Plugin

The Javadoc Plugin is almost identical to the Source Plugin in the sense that we're going to take our Javadocs and package them into a JAR file when we upload them to our repository.
you can browse the Javadoc Plugin's website to see any other additional information or goals that are available there.

We typically tie it to our package phase, but if we're running package a lot we can hinder performance, and so we'll tie it to a later phase, like the verify phase or how we did with the source plugin, the install.

Usually we just use the defaults, but if you have customized Javadocs for your company, maybe throw in your company logo or change colors or whatever, you can customize all this inside the Javadoc Plugin configuration.

Demo: Javadoc Plugin

<plugin>
    <groupId>org.apache.maven.plugins</groupId>
    <artifactId>maven-javadoc-plugin</artifactId>
    <version>3.1.0</version>
    <executions>
        <execution>
            <goals>
                <goal>jar<goal>
            </goals>
            <phase>install</phase>
    </executions>
 </plugin>

The Javadoc Plugin is typically tied to actually a Maven site goal, and just to show you an example of overriding it, we're going to tie it to the same configuration we had for the Source Plugin.

command line and run mvn install again. And it will go through, and this will take a little bit longer. It'll go through and check all of the source structure and then generate all those HTML files for us.
navigate down into the target directory to see the folder apidoc that wasn't there before.


IDE Integration

Installation

Java and Maven are installed the same way regardless of using the IDE.
So I have to have Java installed, my Java home variable set, and I have to have Maven installed.

I personally prefer to install Maven outside of the IDE because it's where it finds settings and that type of stuff from. I don't want to have to configure it in multiple places. It can often be confusing and lead to errors down the road.

Demo: Importing Projects

File > Import > Maven > Existing Maven Projects
Select a Maven project and the IDE will identify our POM.
Click Finish

You'll see that the lower right-hand section, it's building our project this first time, so it will show you the success as it goes through and adds those dependencies, configures our classpath, etc…

Converting Existing Projects

right-click on a project containing a POM file > Configure > Convert to Maven Project
Once your project has been converted, the classpath will automatically be set and will build the project and let you know of any of errors that it may encounter or whether it builds successfully or not.



Dependencies Viewer

Dependencies are much more easily added in the IDE.
The Dependencies tab will show us which dependencies we have installed and allow us to manipulate those dependencies as well.
The Add screen has searching capability,
Add searches your local repo, so it may not be available to you if you have not used a dependancy at some other time
Entering the groupId artifactId and version and clicking OK will add it to both our POM and project.

It won't build that hierarchy until we save it. hit Ctrl+S or the Save icon.

And once I do that, you'll notice it blows up my Dependency Hierarchy screen here and you'll see that we have a bunch of different things that it's overridden or omitted.

Another useful feature though is if you've got a JAR inside of your application and you're wondering where it came from,, you can click on that and it'll tell you exactly where it came through your hierarchy

Effective Pom

The effective POM can be a very wordy document. It is actually what our POM is underneath the hood of everything. It's our complete POM with everything that's inherited from our project POM if we're using a parent POM and the default Super POM. So it's three, possibly even four, POM files combined into one. It's more of a debugging tool to see what the POM is doing and what versions of things we're using. Not a lot of people spend much time in here, but it is important to know about because you can find specific things inside your application in the effective POM.

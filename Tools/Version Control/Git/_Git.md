Let's start by writing some code. Let's say we have this code in a file called calc.code:

function add(a, b)
  return a + b

Save this file in an empty folder. We can now use the GIT software to create a repository. This means that we can start to version control the files within this folder. From the command line, we can do this by writing the following code:

  git init

At this point, nothing is version controlled yet. We will need to tell GIT what files we want to add to version control. We can do that with the following command:

  git add calc.code

Our file is now staged. This means that its changes will be tracked, but we will need to do one more thing to record the changes that have been made to our file. What we'll do is called a commit. A commit will record our changes and store them in our repository. Let's do that with the following command:

  git commit -m "Initial Commit"

-m tells git that we will provide a commit message, and the message is what comes within the quotes. The messages will help us see what is changed in a commit, so we should take some time to come up with descriptive messages.
The changes we have made are now stored on what is called the master branch.

We would now like to continue to work on our program and add more code to this file. To make life a little bit safer, we can create a new branch and make our changes in this branch. We will soon see why this might be a good idea. To create a new branch called subtract, we can use the following command:

  git branch subtract

Creating a new branch will give us an exact copy of the branch we created it from, which in this case is the master branch.

We are still on the master branch, so any changes we make will be on this branch. So, before we do anything else, we should switch branches. We can do that with the checkout command:

  git checkout subtract

We are now on the subtract branch. Now, we can update our source code file, so let's add another function, making the file look like this:

  function add(a, b)
  return a + b
  function subtract(a, b)
  return a - b

If we save these changes, we can add the file to the staging area and commit the changes with the following commands:

  git add calc.code

git commit -m "Added the subtract function."

Now that we have committed our changes to GIT, we can switch branches. Let's do that with the following command:

  git checkout master

If we open our file now, we will see the following content:

function add(a, b)
  return a + b

The changes we made are not here. This is because these changes are not in the master branch. Keeping the file open in our editor, we can now switch back to the subtract branch by using the following command:

  git checkout subtract

Like magic, the changes we made to the file are back, and the subtract function is as we left it:

```
function add(a, b)
return a + b
function subtract(a, b)
return a - b
```

This illustrates that if we, for some reason, decide that the changes we made were no good, we can always go back to our master branch, and everything will be like it was before we started. However, if we, on the other hand, are happy with the changes, we can now bring the two branches together. In GIT, this is called a merge. The first thing we should do before merging the two branches is make sure that the branch we want to merge is active.

In this case, it is the master branch, so we write the following:

  git checkout master

Now, we are ready to merge the changes we made back into the master branch. We can do this with the following command:

  git merge subtract

This means we take the changes made in the branch called subtract and merge it with the content of the current branch, master.

This is how we can use version control with GIT on our local machine. Now, let's see how we can use it to collaborate with other programmers who work on the same project as us.

For that, we will need not only our local repository but also a central repository that we can use to update the other on the changes we make.

Let's assume that Alice and Bob are both working on the same project and want to use GIT to update each other on the changes they make to any files in the project. They will not only have their local GIT repositories, as we saw in the preceding example, but they will also connect to a centralized repository. Any changes they make can now be pushed to this repository, and they can also pull down any changes the other person made from that repository.

We can now assume that they will both work on the same file we saw previously, calc.code, and that it has the same content as we left it with, like this:

function add(a, b)
return a + b
function subtract(a, b)
return a - b

The central repository is often referred to as the origin. Let's say that Alice now wants to create a multiply function:

1. The first thing she should do is pull down the latest version from the central repository (origin) with the following command:

  git pull origin master

Here, origin points out the central repository, and master is the branch she wants to pull down.

2. She now has the latest version, and she can begin implementing her function. She decides to do this in a new branch, so she executes the following command:

  git branch multiply

3. She will then switch to this branch with the following command:

  git checkout multiply

4. Now, she can make the necessary changes, so she adds the following code to the file:

```
function add(a, b)
return a + b
function subtract(a, b)
return a – b
function multiply(a, b)
return a * b
```
Let's leave Alice here and check what Bob is doing.

While Alice has started her work, Bob decides he wants to create a divide function:

1. Just like Alice, he will pull down the latest version of the master branch and create a new branch called divide, switch to it, and then change the calc.code file, so that it looks as follows:
```
function add(a, b)
return a + b
function subtract(a, b)
return a – b
function divide(a, b)
return a / b
```

At this point, Alice is happy with her changes, so she commits them to her branch and merges her branch with the master.

2. Now, she wants to push these changes to the central repository. Before she does that, though, she wants to make sure that changes have been made to the central repository. So, first, she tries to pull down any changes to her repository with the same command she ran previously:

  git pull origin master

3. Since nothing has happened to the central repository since her last pull, nothing will happen. She can now push her changes with the following command:

  git push origin master

Now, her changes are stored in the central repository. At this point, her local version of the master branch and the version stored in the central repository are identical.

Let's go back to Bob, who has finished his function. He commits his changes to his local repository in his branch and merges it into the master branch. Now, he is ready to commit his changes to the central repository:

1. Just like Alice, first, he wants to make sure that he has the latest changes from the central repository, so he issues a pull command:

  git pull origin master

2. This time, things will not go so well. He gets a message that there has been a merge conflict. What's that? He opens the code file, and he now sees this:

```
function add(a, b)
return a + b
function subtract(a, b)
return a - b
<<<<<<< HEAD
function multiply(a, b)
return a * b
=======
function divide(a, b)
return a / b
>>>>>>> div
```

What happened was that he and Alice made changes to the same file on the same line, which is at the end of the file in this case.

GIT became confused due to this and needs help to decide what will be in the file.

Bob looks at this and understands that Alice has added a function to the same location in the file that he did, and he understands that both functions should be there.

The <<<<<<< HEAD marker indicates the beginning of the conflict. What is
between that line and the ======= line is the changes he pulled down. The code between ======= and >>>>>>> div are his changes.

3. Since he decides that both functions should be in this file, he removes the three marker lines from the file, so it now looks like this:

```
function add(a, b)
return a + b
function subtract(a, b)
return a - b
function multiply(a, b)
return a * b
function divide(a, b)
return a / b
```

He can now commit his changes to his local repository and then push the changes so that Alice can get the changes later.


This illustrates how a version control system can be used to share work between multiple programmers in a project. There are, of course, many other aspects of version control systems that we did not cover here, but now, you at least have an idea about what a version control system can do for you and how it can be used to share work with others.

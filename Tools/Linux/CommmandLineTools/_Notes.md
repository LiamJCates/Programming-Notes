A Unix-like operating system such as Linux organizes its files in what is called a hierarchical directory structure. This means they are organized in a tree-like pattern of directories (sometimes called folders in other systems), which may contain files and other directories. 

The first directory in the file system is called the root directory, named "/".

Note that unlike Windows, which has a separate file system tree for each storage device, Unix-like systems such as Linux always have a single file system tree, regardless of how many drives or storage devices are attached to the computer. Storage devices are attached (or more correctly, mounted) at various points on the tree according to the whims of the system administrator, the person (or people) responsible for the maintenance of the system.

At any given time, we are inside a single directory, and we can see the files contained in the directory and the pathway to the directory above us (called the parent directory) and any subdirectories (called the child directory) below us. The directory we are standing in is called the current working directory. 


The primary way to interact with the linux file system is the command line interface

### What is a Command Line
The first instance of CLI built for “interfacing with computers over teletype machines in the 1950s.” It allows a user to interact with the system, taking character-based command inputs.

The CLI is just an interface, the main task is done by a program called command language interpreter. The "shell" is the command language interpreter that shall execute commands read from a command line string, the standard input, or a specified file.

Therefore, when we speak of the command line, we are really referring to the shell. A shell application ensures that the commands to be executed are expressed in the language described in Shell Command Language. The shell takes such commands and passes them to the operating system to carry out.

For most Linux distros, Bash (bourne again shell) is the default command-line interface or shell used to execute commands. The name is an acronym for bourne-again shell, a reference to the fact that bash is an enhanced replacement for sh, the original Unix shell program written by Steve Bourne.


### Accessing The Shell
The shell is accessed using the Terminal – a hardware device used to input and display data. However, the terminal application you see on your Linux systems is an emulator that replicates the jobs of a real-world terminal.

When using a graphical user interface (GUI), we need another program called a terminal emulator to interact with the shell. If we look through our desktop menus, we will probably find one. KDE uses konsole, and GNOME4 uses gnome-terminal, though it’s likely called simply Terminal on your menu.

A number of other terminal emulators are available for Linux, but they all basically do the same thing: give us access to the shell. You will probably develop a preference for one or another terminal emulator based on the number of bells and whistles it has.


### Commands
Linux distributions can leverage an extensive range of commands to accomplish various tasks.


The first piece of text you see when you land on the shell is called the prompt. A shell prompt will appear whenever the shell is ready to accept input.

While it might vary in appearance somewhat depending on the distribution, the typically include

username @ machinename directory $

If the last character of the prompt is a hash mark (#) rather than a dollar sign, the terminal session has superuser privileges.

This means either we are logged in as the root user or we selected a terminal emulator that provides superuser (administrative) privileges.

The Linux CLI is case-sensitive



Running some commands may require you to install additional packages, and some commands may only be intended to work on certain systems.


### pwd

To display the current working directory, we use the pwd (print working directory) command.

```console
$ pwd
/Users/<username>
```


The descriptions of these Linux commands are based on their manual pages.

Command syntax to access a man page:

man command_name

For eg: man cat


We can access the command history by using the up arrow, the command history is a list that lets of view previous commands entered into the terminal, in the order they were entered. Most Linux distributions remember the last 1,000 commands by default. Once we have accessed the command history, we can use the down arrow to move forward in the command history.

Using the left and right arrows, we can position the cursor anywhere on
the command line. This makes editing commands easy.

While the shell is all about the keyboard, you can also use a mouse with your
terminal emulator. A mechanism built into the X Window System (the underlying engine that makes the GUI go) supports a quick copy-and-paste technique.
If you highlight some text by holding down the left mouse button and dragging
the mouse over it (or double-clicking a word), it is copied into a buffer maintained by X. Pressing the middle mouse button will cause the text to be pasted
at the cursor location.

Don’t be tempted to use ctrl-C and ctrl-V to perform copy and paste
inside a terminal window. They don’t work. These control codes have different
meanings to the shell and were assigned many years before the release of
Microsoft Windows.



### Command Options and Arguments

Commands are often followed by one or more options that modify their
behavior and, further, by one or more arguments, the items upon which the
command acts. So, most commands look kind of like this:

command -options arguments

Most commands use options, which consist of a single character preceded by a dash, for example, -l. Many commands, however, including
those from the GNU Project, also support long options, consisting of a word
preceded by two dashes. Also, many commands allow multiple short options
to be strung together.



We can end the terminal session by using the exit command or pressin ctrl-D







All shell commands are executed from a given directory called the working directory.


A pathname is the route we take along the branches of the tree to get to the directory we want. We can specify pathnames in one of two different ways: 
absolute pathnames
relative pathnames.

An absolute pathname begins with the root directory and follows the tree branch by branch until the path to the desired directory or file is completed.

A relative pathname starts from the working directory. 

To do this, it uses a couple of special notations to represent relative positions in
the file system tree. These special notations are . (dot) and .. (dot dot).
The . notation refers to the working directory, and the .. notation refers
to the working directory’s parent directory.





### Home

When we first log in to our system (or start a terminal emulator session), our current working directory is set to our home directory. 

The location of your home directory varies depending on which operating system you’re on.

Each user account is given its own home directory, and it is the only place a regular user is allowed to write files.

Your home directory will be where your settings files get stored and where your desktop is kept. The home directory (or subdirectories under your home directory) is also where you will save documents and files that are yours and not to be shared with others.

By default, your home directory will be unreadable and inaccessible to all other users apart from yourself (and root).

The root user has a unique home directory location /root 

### ls

To list the files and directories in the current working directory, we use the ls command.

To change directories . cd followed by the pathname of the desired working directory.




On Linux systems, files are named in a manner similar to that of other systems
such as Windows, but there are some important differences.

Filenames that begin with a period character are hidden. This only means that ls will not list them unless you say ls -a. When your account was created, several hidden files were placed in your home directory to configure things for your account. In addition, some applications place their configuration and settings files in your home directory as hidden files.

Filenames and commands in Linux, like Unix, are case sensitive. The filenames File1 and file1 refer to different files.

Though Linux supports long filenames that may contain embedded spaces
and punctuation characters, limit the punctuation characters in the names
of files you create to period, dash, and underscore. Most important, do not
embed spaces in filenames. If you want to represent spaces between words
in a filename, use underscore characters. You will thank yourself later.

Linux has no concept of a “file extension” like some other operating systems. You may name files any way you like. The contents or purpose of a file is determined by other means. Although Unix-like operating systems
don’t use file extensions to determine the contents/purpose of files, many
application programs do.



### cd

Changes the working directory to your home directory.

cd -
Changes the working directory to the previous working directory.

cd ~ 

It is quite common to see a tilde (~) in place of the full path for a home directory. The ~ will expand to be the path of your home directory

cd ~<username>

Changes the working directory to the home directory of the user with <username>. For example, typing cd ~bob will change the directory to the home directory of user “bob.”

ls
List directory contents

file
Determine file type

less
View file contents

ls
Can be used without a directory to list the contents of the current working directory. ls can be followed by an absolute or relative pathname to list the contents of the specified directory. Ls can be followed by multiple directories to list their contents in a single output, grouped by directory.


Common ls Options

| Option | Long option | Description |
+--------+-------------+-------------+
| -a | --all | List all files, even those with names that begin with a period, which are normally not listed (that is, hidden). |
| -A | --almost-all | Like the -a option except it does not list . (current directory) and .. (parent directory). |
| -d | --directory | Ordinarily, if a directory is specified, ls will list the contents of the directory, not the directory itself. Use this option in conjunction with the -l option to see details about the directory rather than its contents. |
| -F | --classify | This option will append an indicator character to the end of each listed name. For example, it will append a forward slash (/) if the name is a directory. |
| -h | --human-readable | In long format listings, display file sizes in humanreadable format rather than in bytes. |
| -l | Display results in long format. |
| -r | --reverse | Display the results in reverse order. Normally, ls displays its results in ascending alphabetical order. |
| -S | | Sort results by file size. |
| -t | | Sort by modification time. |


Here is an example of a file from the output of ls -l

-rw-r--r-- 1 root root 32059 2017-04-03 11:05 oo-cd-cover.odf

-rw-r--r--
Access rights to the file. The first character indicates the type of file. Among the different types, a leading dash means a regular file, while a d indicates a directory.
The next three characters are the access rights for the file’s owner, the next three are for members of the file’s group, and the final three are for everyone else.

1
File’s number of hard links. See "Symbolic Links" and "Hard Links".

root
The username of the file’s owner.

root
The name of the group that owns the file.

32059
Size of the file in bytes.

2017-04-03 11:05
Date and time of the file’s last modification.

oo-cd-cover.odf
Name of the file.
